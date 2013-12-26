// Radon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include "windows.h"

#define MSIZE 512

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j;
	float k;

	double d,count;
	float *data_in=(float*)malloc(sizeof(float)*MSIZE*MSIZE);
	float *x=(float*)malloc(sizeof(float)*MSIZE*MSIZE);
	float *y=(float*)malloc(sizeof(float)*MSIZE*MSIZE);
	float *x_r=(float*)malloc(sizeof(float)*MSIZE*MSIZE);
	float *y_r=(float*)malloc(sizeof(float)*MSIZE*MSIZE);
	float *p_data_in,*p_x,*p_y,*p_x_r,*p_y_r;

	count=0;
	int t1=GetTickCount();
	p_data_in=data_in;
	p_x=x;
	p_y=y;
	for (i=0;i<MSIZE;i++)
	{
		for (j=0;j<MSIZE;j++)
		{
			*p_data_in=rand();
			*p_x=i;
			*p_y=j;
			p_data_in++;
			p_x++;
			p_y++;
		}
	}
	
	for(k=0;k<180;k+=0.1)
	{
		float sink,cosk;
		sink=sin(k*3.1415926/180);
		cosk=cos(k*3.1415926/180);
		p_data_in=data_in;
		p_x=x;
		p_y=y;
		p_x_r=x_r;
		p_y_r=y_r;

		for (i=0;i<MSIZE;i++)
		{
			for (j=0;j<MSIZE;j++)
			{
				*p_x_r=*p_x*sink+*p_y*cosk;
				*p_y_r=*p_x*sink-*p_y*cosk;
				p_x_r++;
				p_y_r++;
				p_x++;
				p_y++;
			}
		}
	}
	int t2=GetTickCount();
	printf("time difference: %d %f\n",t2-t1,count);
	return 0;
}

