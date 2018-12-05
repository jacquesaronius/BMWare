#include <kernel/gpu.h>

#ifndef LOGO_PRINT_H
#define LOGO_PRINT_H

static const pixel_t RED = {0xaa, 0x00, 0x00};
static const pixel_t ORANGE = {0xff, 0x66, 0x00};
static const pixel_t REDORANGE = {0xc9, 0x50, 0x00};
static const pixel_t BROWN = {0x71, 0x2e, 0x00};
static const pixel_t LIGHTBROWN = {0xaf, 0x00, 0x00};

void makeLogo();

void makedownTriangle(int length, int x1, int y1, pixel_t * color);
void makeupTriangle(int length, int x1, int y1, pixel_t * color);
void makeleftTriangle(int length, int x1, int y1, pixel_t * color);
void makerightTriangle(int length, int x1, int y1, pixel_t * color);


#endif