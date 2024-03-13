#ifndef OLIVE_H_
#define OLIVE_H_
#include<stdint.h>
#include<stdlib.h>
void draw_line(uint32_t *image,uint32_t color,int x0,int y0,int xe,int ye,size_t sw,size_t sh);
void fill_circle(uint32_t *image,uint32_t color,int x,int y,int r,size_t sw,size_t sh);
void fill_rect(uint32_t *image,uint32_t color,int x,int y,size_t w,size_t h,size_t sw,size_t sh);
void fill_bg(uint32_t *image,uint32_t color,size_t width,size_t height);
int write(uint32_t *image,size_t width,size_t height,char *file_path);



#endif
