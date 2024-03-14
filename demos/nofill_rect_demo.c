#include "pixpen.h" 
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define WIDTH 500
#define HEIGHT 500


static uint32_t image[WIDTH*HEIGHT];
int main(){
	//change file name here
	char * file_path="rect_no_fill.ppm";
	fill_bg(image,0xFF202020,WIDTH,HEIGHT);
	

	//rectangle outline
	draw_rect(image,0xFF00FF00,50,50,100,70,WIDTH,HEIGHT);
	draw_rect(image,0xFFFF00FF,80,80,100,200,WIDTH,HEIGHT);
	draw_rect(image,0xFFFFFF00,300,200,100,100,WIDTH,HEIGHT);

	draw_rect(image,0xFF00FF00,70,40,300,170,WIDTH,HEIGHT);
	draw_rect(image,0xFFFF00FF,10,320,130,300,WIDTH,HEIGHT);
	draw_rect(image,0xFFFFFF00,123,220,150,450,WIDTH,HEIGHT);



    int status=write(image,WIDTH,HEIGHT,file_path);
	if(!status){
		printf("%s SAVED ",file_path);
	}
	else{
		printf("error occured while saving");
 
	}

	return 0;

}
