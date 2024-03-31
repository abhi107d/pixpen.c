#ifndef OLIVE_H_
#define OLIVE_H_
#include<stdint.h>
#include<stdlib.h>

//structs
struct vec3d{
	int x;
	int y;
	int z;
}typedef vec3d;
struct vec2d{
	int x;
	int y;
}typedef vec2d;


void fill_triangle(uint32_t *image,uint32_t color,size_t sw,size_t sh,
	int x1,int y1,
	int x2,int y2,
	int x3,int y3);
void draw_line(uint32_t *image,uint32_t color,int x0,int y0,int xe,int ye,size_t sw,size_t sh);
void fill_circle(uint32_t *image,uint32_t color,int x,int y,int r,size_t sw,size_t sh);
void draw_circle(uint32_t *image,uint32_t color,int x,int y,int r,size_t sw,size_t sh);
void fill_rect(uint32_t *image,uint32_t color,int x,int y,size_t w,size_t h,size_t sw,size_t sh);
void draw_rect(uint32_t *image,uint32_t color,int x,int y,size_t w,size_t h,size_t sw,size_t sh);


void vec32d(vec2d* p1,vec3d p2,size_t sw,size_t sh,size_t theta);


void fill_bg(uint32_t *image,uint32_t color,size_t width,size_t height);
int write(uint32_t *image,size_t width,size_t height,char *file_path);



#endif
