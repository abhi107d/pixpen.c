#include "pixpen.h" 
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define WIDTH 500
#define HEIGHT 500


static uint32_t image[WIDTH*HEIGHT];
int main(){
	//change file name here
	char * file_path="draw_rect.ppm";
	fill_bg(image,0xFF202020,WIDTH,HEIGHT);
	

	//rectangle example
	

	/* int k=0; */	
	/* size_t size=WIDTH/10; */
	/* for(int i=0;i<10;i++){ */
	/* 	for(int j=0;j<10;j++){ */
	/* 		uint32_t color=0xFF00FF00; */
	/* 		if(k%2==0){ */
	/* 			color=0xFF0000FF; */
	/* 		} */
	/* 		k++; */
	/* 		fill_rect(image,color,i*size,j*size,size,size,WIDTH,HEIGHT); */

	/* 	} */
	/* 	k++; */
	/* } */
	
	//rectangle outline
	draw_rect(image,0xFF00FF00,50,50,100,70,WIDTH,HEIGHT);
	draw_rect(image,0xFFFF00FF,80,80,100,200,WIDTH,HEIGHT);
	draw_rect(image,0xFFFFFF00,300,200,100,100,WIDTH,HEIGHT);

	draw_rect(image,0xFF00FF00,70,40,300,170,WIDTH,HEIGHT);
	draw_rect(image,0xFFFF00FF,10,320,130,300,WIDTH,HEIGHT);
	draw_rect(image,0xFFFFFF00,123,220,150,450,WIDTH,HEIGHT);



	//circle example
	
	/* int k=0; */	
	/* size_t size=WIDTH/10; */
	/* for(int i=0;i<10;i++){ */
	/* 	for(int j=0;j<10;j++){ */
	/* 		uint32_t color=0xFF00FFFF; */
	/* 		if(k%2==0){ */
	/* 			color=0xFFFF00FF; */
	/* 		} */
	/* 		k++; */
	/* 		fill_circle(image,color,i*size+size/2,j*size+size/2,size/2,WIDTH,HEIGHT); */

	/* 	} */
	/* 	k++; */
	/* } */
		


	//print grid
	/* for(int i=0;i<HEIGHT/50;i++)draw_line(image,0xFF00FF00,0,i*50,WIDTH,i*50,WIDTH,HEIGHT); */
	/* for(int i=0;i<WIDTH/50;i++)draw_line(image,0xFFFF00FF,i*50,0,i*50,HEIGHT,WIDTH,HEIGHT); */





    int status=write(image,WIDTH,HEIGHT,file_path);
	if(!status){
		printf("%s SAVED ",file_path);
	}
	else{
		printf("error occured while saving");
 
	}

	return 0;

}
