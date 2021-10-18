#include <stdio.h>
#include<math.h>
void zaokruzi1(float *broj,int vel)
{ int i;
	for(i=0;i<vel;i++)
	{
		*(broj+i)=(round((*(broj+i))*10))/10;
	}
}
void preslozi(float *broj,int vel,int k)
{   zaokruzi1(broj,vel);
	float *p=broj;
 int clan=0;
int s=0,cifra,j,i;
float temp;
	for(i=0;i<vel;i++)
	{   s=0;
		clan=*(broj+i)*10;
		
	do {
			cifra=clan%10;
			clan=clan/10;
			s+=fabs(cifra);
		} while(clan%10!=0 || clan/10!=0);
	if(s==k || s>k)
	{
    if(i==0){ p++;} else{
	temp=*(broj+i);
	for(j=i;(broj+j)>p;j--)
	{
		*(broj+j)=*(broj+j-1);
		
	}
	*p=temp;
	p++;
	}
	}
	}
}

int main() {
float broj[]={ -25.99999, 0.1, 0.19999, 123.456, -123.456 };
zaokruzi1(broj,5);
preslozi(broj,5,26);
printf("%f",*(broj+3));
return 0;
}
