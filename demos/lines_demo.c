#include "pixpen.h" 
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define WIDTH 500
#define HEIGHT 500


static uint32_t image[WIDTH*HEIGHT];
int main(){
	//change file name here
	char * file_path="grid_demo.ppm";
	fill_bg(image,0xFF202020,WIDTH,HEIGHT);

	//print grid
	for(int i=0;i<HEIGHT/50;i++)draw_line(image,0xFF00FF00,0,i*50,WIDTH,i*50,WIDTH,HEIGHT);
	for(int i=0;i<WIDTH/50;i++)draw_line(image,0xFFFF00FF,i*50,0,i*50,HEIGHT,WIDTH,HEIGHT);

    int status=write(image,WIDTH,HEIGHT,file_path);
	if(!status){
		printf("%s SAVED ",file_path);
	}
	else{
		printf("error occured while saving");
 
	}

	return 0;

}
