#include "pixpen.h"
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

//functions
#define swap(T,x,y)do{T t=x;x=y;y=t;}while(0) 



//fill_triangle


//sort points
void sort_points(int* x1,int* y1,int *x2,int * y2,int* x3,int* y3){
	if(*y1>*y2){
		swap(int,*x1,*x2);
		swap(int,*y1,*y2);
	}
	if(*y2>*y3){
		swap(int,*x3,*x2);
		swap(int,*y3,*y2);
	}
	
	if(*y1>*y2){
		swap(int,*x1,*x2);
		swap(int,*y1,*y2);
	}
}



//line eqn
void line(int x1,int y1,int x2,int y2,float *k,float *b){
	int dx=x2-x1;
	int dy=y2-y1;

	if(dy==0){
		*k=0;
		*b=(float)x2;
	}
	
	*k=(float)dx/(float)dy;
	*b=(float)x1-(float)y1*(*k);


}

//fill triangle function
void fill_triangle(uint32_t *image,uint32_t color,size_t sw,size_t sh,
	int x1,int y1,
	int x2,int y2,
	int x3,int y3){
	
	sort_points(&x1,&y1,&x2,&y2,&x3,&y3);


	float m23,b23;
	float m12,b12;
	float m13,b13;
	line(x1,y1,x2,y2,&m12,&b12);
	line(x1,y1,x3,y3,&m13,&b13);
	line(x2,y2,x3,y3,&m23,&b23);

	for(int i=y1;i<=y3;i++){
		float sp=m13*(float)i+b13;
		float ep;
		if(i<=y2)ep=m12*(float)i+b12;
		else ep=m23*i+b23;

		if(sp>ep)swap(float,sp,ep);
		for(int j=(int)sp;j<=(int)ep;j++){
			int indx=i*(int)sw+j;
			if(indx>=0 && indx<(int)sw*(int)sh)image[indx]=color;
		}
	}

	


}












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


