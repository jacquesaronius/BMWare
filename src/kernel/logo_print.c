#include <kernel/logo_print.h>
#include <math.h>

void makeLogo(){
    /*------------B-------------------*/
    makeleftTriangle(40, 50, 50, &BROWN);
    makerightTriangle(40, 30, 71, &RED);
    makeleftTriangle(40, 50, 92, &ORANGE);
    makerightTriangle(40, 30, 113, &RED);
    makeleftTriangle(40, 50, 134, &ORANGE);
    makerightTriangle(40, 30, 155, &RED);
    makeleftTriangle(40, 50, 176, &ORANGE);
    makerightTriangle(40, 52, 50, &LIGHTBROWN);
    makerightTriangle(40, 52, 176, &RED);
    makeleftTriangle(40, 72, 71, &REDORANGE);
    makerightTriangle(40, 74, 71, &RED);
    makeleftTriangle(40, 94, 92, &ORANGE);
    makerightTriangle(40, 74, 113, &RED);
    makeleftTriangle(40, 72, 113, &ORANGE);
    makeleftTriangle(40, 94, 134, &ORANGE);
    makerightTriangle(40, 74, 155, &RED);
    makeleftTriangle(40, 72, 155, &ORANGE);

    /*---------------M-----------------*/
    makedownTriangle(40, 105, 154, &ORANGE);
    makeupTriangle(40, 105, 152, &RED);
    makeupTriangle(40, 146, 152, &RED);
    makeupTriangle(40, 187, 152, &RED);
    makeupTriangle(40, 228, 152, &RED);
    makeupTriangle(40, 167, 174, &RED);
    makedownTriangle(40, 146, 154, &ORANGE);
    makedownTriangle(40, 187, 154, &ORANGE);
    makedownTriangle(40, 228, 154, &ORANGE);
    makedownTriangle(40, 125, 132, &ORANGE);
    makedownTriangle(40, 207, 132, &ORANGE);
    makeupTriangle(40, 125, 130, &RED);
    makeupTriangle(40, 207, 130, &RED);

    
    /*---------------W-----------------*/
    makedownTriangle(40, 276, 154, &RED);
    makedownTriangle(40, 358, 154, &RED);
    makeupTriangle(40, 276, 152, &ORANGE);
    makeupTriangle(40, 358, 152, &ORANGE);
    makedownTriangle(40, 255, 132, &RED);
    makedownTriangle(40, 337, 132, &RED);
    makedownTriangle(40, 296, 132, &RED);
    makedownTriangle(40, 378, 132, &RED);
    makeupTriangle(40, 255, 130, &ORANGE);
    makeupTriangle(40, 296, 130, &ORANGE);
    makeupTriangle(40, 337, 130, &ORANGE);
    makeupTriangle(40, 378, 130, &ORANGE);
    makedownTriangle(40, 317, 110, &RED);

    /*--------------A-------------------*/
    makeupTriangle(40, 410, 152, &RED);
    makeupTriangle(40, 451, 152, &RED);
    makedownTriangle(40, 410, 154, &ORANGE);
    makedownTriangle(40, 451, 154, &ORANGE);
    makeupTriangle(40, 389, 174, &RED);
    makeupTriangle(40, 473, 174, &RED);
    makeupTriangle(40, 431, 131, &RED);

    /*--------------R-------------------*/
   makerightTriangle(28, 520, 167, &RED);
   makeleftTriangle(28, 534, 152, &ORANGE);
   makerightTriangle(28, 520, 138, &RED);
   makeleftTriangle(28, 534, 123, &ORANGE);
   makerightTriangle(28, 520, 108, &RED);
   makeleftTriangle(28, 534, 93, &ORANGE);
   makerightTriangle(28, 536, 93, &RED);
   makeleftTriangle(28, 550, 108, &ORANGE);
   makerightTriangle(28, 552, 108, &RED);
   makeleftTriangle(28, 550, 137, &ORANGE);
   makerightTriangle(28, 552, 137, &RED);
   makeleftTriangle(28, 566, 152, &ORANGE);
   makerightTriangle(28, 552, 167, &RED);

   /*----------------E-------------------*/
   makerightTriangle(20, 580, 157, &RED);
   makeleftTriangle(20, 590, 124, &ORANGE);
   makeleftTriangle(20, 590, 146, &ORANGE);
   makeleftTriangle(20, 590, 168, &ORANGE);
   makerightTriangle(20, 592, 168, &RED);
   makeleftTriangle(20, 602, 179, &ORANGE);
   makerightTriangle(20, 604, 179, &RED);
   makeleftTriangle(20, 614, 168, &ORANGE);
   makerightTriangle(20, 616, 168, &RED);
   makerightTriangle(20, 592, 124, &RED);
   makerightTriangle(20, 592, 146, &RED);
   makeleftTriangle(20, 602, 135, &ORANGE);
   makerightTriangle(20, 580, 113, &RED);
   makeleftTriangle(20, 590, 102, &ORANGE);
   makerightTriangle(20, 592, 102, &RED);
   makeleftTriangle(20, 602, 91, &ORANGE);
   makerightTriangle(20, 604, 91, &RED);
   makeleftTriangle(20, 614, 102, &ORANGE);
   makerightTriangle(20, 616, 102, &RED);

}

void makedownTriangle(int length, int x1, int y1, pixel_t * color){
 //Downward facing triangle 
 int height = length;
 
 for(int i = 0; i < height; i++){
   for(int j = 0; j < length; j++){
      write_pixel(x1 + j, y1, color);    
   }

   x1 += 1;
   y1 += 1;
   if(length % 2 == 0){
    length -= 2;  
   }
 }

}

void makeupTriangle(int length, int x1, int y1, pixel_t * color){
 //Upward Facing triangle 
 int height = length;
 
 for(int i = 0; i < height; i++){
   for(int j = 0; j < length; j++){
      write_pixel(x1 + j, y1, color);    
   }

   x1 += 1;
   y1 -= 1;
   if(length % 2 == 0){
    length -= 2;  
   }
 }

}

void makeleftTriangle(int length, int x1, int y1, pixel_t * color){
 //Left Facing triangle 
 int height = length;
 
 for(int i = 0; i < height; i++){
   for(int j = 0; j < length; j++){
      write_pixel(x1, y1 + j, color);    
   }

   x1 -= 1;
   y1 += 1;
   if(length % 2 == 0){
    length -= 2;  
   }
 }

}

void makerightTriangle(int length, int x1, int y1, pixel_t * color){
 //Rightward facing triangle 
 int height = length;
 
 for(int i = 0; i < height; i++){
   for(int j = 0; j < length; j++){
      write_pixel(x1, y1 + j, color);    
   }

   x1 += 1;
   y1 += 1;
   if(length % 2 == 0){
    length -= 2;  
   }
 }

}