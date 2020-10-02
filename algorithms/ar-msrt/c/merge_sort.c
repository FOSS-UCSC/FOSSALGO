#include<stdio.h>

int main()
{
	int a[5]={17,26,54,77,93};
	int b[5]={20,25,31,44,55};
	int c[10];
	int i,j,k,x=0,y=0,m;
	i=sizeof(a)/sizeof(a[0]);
	j=sizeof(b)/sizeof(b[0]);
	for(k=0;k<i+j;k++)
	{
		if(x<i && y<j)
		{
			if(a[x]< b[y])
		    {
			    c[k]=a[x];
			    x++;
		    }
		    else
		    {
			    c[k]=b[y];
			    y++;
		    } 
		}
		
		 else if(x==i)
		 {
		 	for(;k<i+j;){
		 		c[k]=b[y];
		 		y++;
		 		k++;
			 }
		 }
		 else
		 {
		 	for(;k<i+j;)
		 	{
		 		c[k]=a[x];
		 		x++;
		 		k++;
			 }
		 }
	}
	for(m=0;m<i+j;m++)
	{
		printf("%d\t",c[m]);
		
	}
	return 0;
}
