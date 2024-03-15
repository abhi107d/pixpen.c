#include "pixpen.h"
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>



//line bresenhams
void draw_line(uint32_t *image,uint32_t color,int x0,int y0,int xe,int ye,size_t sw,size_t sh){
	int X=x0;
	int Y=y0;

	int Xe=xe;
	int Ye=ye;
 
	image[(y0*sw)+x0]=color;

	int flag=0;
	int dx=abs(xe-x0);
	int dy=abs(ye-y0);
	if(dx<dy){
		flag=1;
		int temp=dx;
		dx=dy;
		dy=temp;

		temp=X;
		X=Y;
		Y=temp;

		temp=Xe;
		Xe=Ye;
		Ye=temp;


	}
	if(X>Xe){
		int temp=X;
		X=Xe;
		Xe=X;
		temp=Y;
		Y=Ye;
		Ye=temp;
	}

	
	int step=dx;
	int incry=1;
	if((Ye-Y)<0)incry=-1;

	int p=2*dy-dx;
	
	for(int i=0;i<step;i++){
		X=X+1;
		if(p<0)p=p+2*dy;
		else{
			p=p+2*dy-2*dx;
			Y=Y+incry;
		}
		if(flag){  
			image[X*sw+Y]=color;
		}
		else image[Y*sw+X]=color;
	}
}




//draw circle
//bresenhams circle 
void draw_circle(uint32_t *image,uint32_t color,int x,int y,int r,size_t sw,size_t sh){
	int p=3-2*r;
	int x0=0;
	int y0=r;
	while(y0>x0){
		if(p>0){
			p=p+4*(x0-y0)+10;
			y0=y0-1;
		}
		else{
			p=p+4*x0+6;
		}
		x0=x0+1;

		int	arr[8][2]={
			{x0+x,y0+y},
			{y0+x,x0+y},
			{-x0+x,y0+y},
			{y0+x,-x0+y},
			{-y0+x,x0+y},
			{x0+x,-y0+y},
			{-x0+x,-y0+y},
			{-y0+x,-x0+y}
		};
		
	
		for(int i=0;i<8;i++){
				if(arr[i][0]>=0 && arr[i][1]>=0 && arr[i][0]<(int)sw && arr[i][1]<(int)sh){
						image[(arr[i][1]*(int)sw+arr[i][0])]=color;
				}
		}
	}
}
		


//fill circle
void fill_circle(uint32_t *image,uint32_t color,int x,int y,int r,size_t sw,size_t sh){
	//define boundaries
	int X=x-r;
	int Y=y-r;
	int Xe=x+r;
	int Ye=y+r;
	for(int i=Y;i<Ye;i++){
		if(i>=0 && i<=(int)sh){			
			for(int j=X;j<Xe;j++){
				if(j>=0 && j<=(int)sw){
					int range=(y-i)*(y-i)+(x-j)*(x-j);
					if(r*r>=range)image[i*(int)sw+j]=color;
				}
			}
		}
	}
}



//draw rect
//
//draw a rectangle
void draw_rect(uint32_t *image,uint32_t color,int x,int y,size_t w,size_t h,size_t sw,size_t sh){
	int SIZE=sw*sh;
	for(size_t i=0;i<h;i++){
		int y0=y+i;
		int idx1=y0*(int)sw+x;
		int idx2=y0*(int)sw+x+w;
		
		if(idx1<SIZE && idx1>=0)image[idx1]=color;
		if(idx2<SIZE && idx2>=0)image[idx2]=color;
		
	}
	for(size_t i=0;i<w;i++){
		int x0=x+i;
		int idx1=y*(int)sw+x0;
		int idx2=(y+h)*(int)sw+x0;
		
		if(idx1<SIZE && idx1>=0)image[idx1]=color;
		if(idx2<SIZE && idx2>=0)image[idx2]=color;

	}
}

		
//fill a rectangle
void fill_rect(uint32_t *image,uint32_t color,int x,int y,size_t w,size_t h,size_t sw,size_t sh){
	for(size_t i=0;i<h;i++){
		int y0=y+i;
		if(y0>=0 && y0< (int)sh){
			for(size_t j=0;j<w;j++){
				int x0=x+j; 
				if(x0>=0 && x0<(int)sw)image[((y0)*sw)+(x0)]=color;
			}
		}
	}
}
//**

//fill the background
void fill_bg(uint32_t *image,uint32_t color,size_t width,size_t height){
	for(size_t i=0;i<width*height;i++){
		image[i]=color;

	}
}




//write the buffer
int write(uint32_t *image,size_t width,size_t height,char *file_path){
	int res=0;
	FILE *f=fopen(file_path,"wb");
	if(f==NULL){
		res=1;
		goto exit;
	}
	
	fprintf(f,"P6\n%zu %zu\n255\n",width,height);
	if(ferror(f)){
		res=1;
		goto exit;
	}
	for(size_t i=0;i<width*height;i++){
		uint32_t pixel=image[i];
		uint8_t byte[3]={
			(pixel>>0*8),
			(pixel>>8),
			(pixel>>2*8)};
		fwrite(byte,sizeof(byte),1,f);
		if(ferror(f)){
			res=1;
			goto exit;
		}
	}
	goto exit;



exit:
	if(f)fclose(f);
	return res;

}


