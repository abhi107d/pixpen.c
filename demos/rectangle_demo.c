#include "pixpen.h" 
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define WIDTH 500
#define HEIGHT 500


static uint32_t image[WIDTH*HEIGHT];
int main(){
	//change file name here
	char * file_path="rectangle.ppm";
	fill_bg(image,0xFF202020,WIDTH,HEIGHT);
	

	//rectangle example
	

	int k=0;	
	size_t size=WIDTH/10;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			uint32_t color=0xFF00FF00;
			if(k%2==0){
				color=0xFF0000FF;
			}
			k++;
			fill_rect(image,color,i*size,j*size,size,size,WIDTH,HEIGHT);

		}
		k++;
	}
	




    int status=write(image,WIDTH,HEIGHT,file_path);
	if(!status){
		printf("%s SAVED ",file_path);
	}
	else{
		printf("error occured while saving");
 
	}

	return 0;

}
