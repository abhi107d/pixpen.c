#include "pixpen.h" 
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define WIDTH 500
#define HEIGHT 500


static uint32_t image[WIDTH*HEIGHT];
int main(){
	//change file name here
	char * file_path="test.ppm";
	//ffill background colr 
	fill_bg(image,0xFF202020,WIDTH,HEIGHT);
	

	//examples
	//*
	//*
	//draw line 
	/* draw_line(image,0xFFFF00FF,50,0,150,70,WIDTH,HEIGHT); */
	//*
	//rectangle example
	/* fill_rect(image,0xFFAAEE00,120,220,100,132,WIDTH,HEIGHT); */
	//*
	//*
	//rectangle outline
	/* draw_rect(image,0xFF00FF00,70,40,300,170,WIDTH,HEIGHT); */
	//*
	//*
	//fill circle
	/* fill_circle(image,0xFFC0CB,300,240,70,WIDTH,HEIGHT); */ 
	//*
	//*
	//draw circle
	/* draw_circle(image, 0xFFFF00FF, 250, 250, 100, WIDTH, HEIGHT); */
	//*
	//*
	fill_triangle(image,0xFFFF0000,WIDTH,HEIGHT,310,116,162,87,228,268);
	fill_triangle(image,0xFF00FF00,WIDTH,HEIGHT,117,17,59,167,26,77);
	fill_triangle(image,0xFFFFFF00,WIDTH,HEIGHT,392,192,315,346,196,318);
	fill_triangle(image,0xFF00FFFF,WIDTH,HEIGHT,172,196,184,312,39,302);
	fill_triangle(image,0xFFFF00FF,WIDTH,HEIGHT,255,40,128,37,227,124);
	/* fill_triangle(image,0xFFFF0000,WIDTH,HEIGHT,301,12,69,-156,183,92); */



    int status=write(image,WIDTH,HEIGHT,file_path);
	if(!status){
		printf("%s SAVED ",file_path);
	}
	else{
		printf("error occured while saving");
 
	}

	return 0;

}
