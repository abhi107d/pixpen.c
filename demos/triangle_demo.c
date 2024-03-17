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
	
//*
	fill_triangle(image,0xFFFF0000,WIDTH,HEIGHT,310,116,162,87,228,268);
	fill_triangle(image,0xFF00FF00,WIDTH,HEIGHT,117,17,59,167,26,77);
	fill_triangle(image,0xFFFFFF00,WIDTH,HEIGHT,392,192,315,346,196,318);
	fill_triangle(image,0xFF00FFFF,WIDTH,HEIGHT,172,196,184,312,39,302);
	fill_triangle(image,0xFFFF00FF,WIDTH,HEIGHT,255,40,128,37,227,124);
	fill_triangle(image,0xFFFF00FF,WIDTH,HEIGHT,50,50,80,0,100,50);

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
