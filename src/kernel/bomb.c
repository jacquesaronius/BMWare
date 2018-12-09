#include <kernel/bomb.h>
#include <kernel/mem.h>
#include <kernel/interrupts.h>
#include <common/stdlib.h>
#include <kernel/stdio.h>
#include <kernel/gpu.h>
static uint32_t next_proc_num = 1;
#define NEW_PID next_proc_num++;

extern uint8_t __end;
extern void switch_to_thread(process_control_block_t * old, process_control_block_t * new);

IMPLEMENT_LIST(pcb);

pcb_list_t run_queue;
pcb_list_t all_proc_list;
void process_init(void)
{
    process_control_block_t * main_pcb;
    INITIALIZE_LIST(run_queue);
    INITIALIZE_LIST(all_proc_list);
     
    main_pcb = kmalloc(sizeof(process_control_block_t));
    main_pcb->stack_page = (void *)&__end;
    main_pcb->pid = NEW_PID;
    memcpy(main_pcb->proc_name, "Init", 5);

    
    append_pcb_list(&all_proc_list, main_pcb);

    current_process = main_pcb;

    
    timer_set(10000);
}

void schedule(void) {
    DISABLE_INTERRUPTS();
    process_control_block_t * new_thread, * old_thread;

    
    if (size_pcb_list(&run_queue) == 0) {
        ENABLE_INTERRUPTS();
        return;
    }

    
    new_thread = pop_pcb_list(&run_queue);
    old_thread = current_process;
    current_process = new_thread;

    
    append_pcb_list(&run_queue, old_thread);

    
    switch_to_thread(old_thread, new_thread);
    ENABLE_INTERRUPTS();
}

void create_kernel_thread(kthread_function_f thread_func, char * name, int name_len) {
    process_control_block_t * pcb;
    proc_saved_state_t * new_proc_state;


    pcb = kmalloc(sizeof(process_control_block_t));
    pcb->stack_page = alloc_page();
    pcb->pid = NEW_PID;
    memcpy(pcb->proc_name, name, MIN(name_len,19));
    pcb->proc_name[MIN(name_len,19)+1] = 0;

    
    new_proc_state = pcb->stack_page + PAGE_SIZE - sizeof(proc_saved_state_t);
    pcb->saved_state = new_proc_state;

    
    bzero(new_proc_state, sizeof(proc_saved_state_t));
    new_proc_state->lr = (uint32_t)thread_func;     
    new_proc_state->sp = (uint32_t)reap;            
    new_proc_state->cpsr = 0x13 | (8 << 1);         

    
    append_pcb_list(&all_proc_list, pcb);
    append_pcb_list(&run_queue, pcb);
}

static void reap(void) {
    DISABLE_INTERRUPTS();
    process_control_block_t * new_thread, * old_thread;

    
    while (size_pcb_list(&run_queue) == 0);

    
    new_thread = pop_pcb_list(&run_queue);
    old_thread = current_process;
    current_process = new_thread;

    
    
    free_page(old_thread->stack_page);
    kfree(old_thread);

    
    switch_to_thread(old_thread, new_thread);
}

void print_bomb(int distance)
{
    int i;
    gpu_clear();
    for (i = 0; i < distance; i++);
        puts("\n");
    puts("             . . .\n");
    puts("              \\|/\n");
    puts("            `--+--'\n");
    puts("              /|\\\n");
    puts("             ' | '\n");
    puts("               |\n");
    puts("               |\n");
    puts("           ,--'#`--.\n");
    puts("           |#######|\n");
    puts("        _.-'#######`-._\n");
    puts("     ,-'###############`-.\n");
    puts("   ,'#####################`,\n");
    puts("  /#########################\\\n");
    puts(" |###########################|\n");
    puts("|#############################|\n");
    puts("|#############################|\n");
    puts("|#############################|\n");
    puts("|#############################|\n");
    puts(" |###########################|\n");
    puts("  \\#########################/\n");
    puts("   `.#####################,'\n");
    puts("     `._###############_,'\n");
    puts("        `--..#####..--'\n");
}

void drop_bombs(void)
{
    int i;
    for (i = 0; i < 60; i++)
    {
        uart_puts(itoa(i, 10));
        print_bomb(i);
        udelay(10000000000);
    }
}