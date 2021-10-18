#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926


int main() 
{
int stepen=0,minuta=0,sekunde=0;
int i,j,n=0;
double radijan,a=0,sekunda1=0, sekunda2=0, c=0;

radijan=(float)180/PI;
double niz[500];

do
{
printf("Unesite broj uglova: ");
scanf("%d" , &n);
} while(n<1 || n>500);


for(i=0 ; i<n ; i++)
{
scanf("%lf" , &niz[i]); 
niz[i]=niz[i]*radijan;
}

printf("Uglovi su: \n");

for(i=0 ; i<n ; i++)
{
	
if(niz[i]>=0)
	{
a=niz[i];
stepen=(int)a;
c=(a-stepen)*60;
minuta=(int)c;
sekunda1=(c-minuta)*60;
sekunda2=(sekunda1-(int)sekunda1)*10;

if(sekunda2>=5)
{
	sekunde=(int)sekunda1+1;
}

else
{
sekunde=(int)sekunda1;	
}

if(sekunde==60)
{
	sekunde=0;
	minuta++;
	if(minuta==60)
	{
		minuta=0;
		stepen++;
	}
}


if(sekunde>30)
{
	for(j=i; j<n-1; j++)
	{
		niz[j]=niz[j+1];
	}
	
n--;
i--;
continue;
}
 printf("%d stepeni %d minuta %d sekundi \n" , stepen,minuta,sekunde);
 
}





if(niz[i]<0)
{
a=niz[i];
stepen=(int)a;
c=(a-stepen)*(-1)*60;
minuta=(int)c;
sekunda1=(c-minuta)*60;
sekunda2=(sekunda1-(int)sekunda1)*10;


if(sekunda2>=5)
{
	sekunde=(int)sekunda1+1;
}

else
{
sekunde=(int)sekunda1;	
}

if(sekunde==60)
{
	sekunde=0;
	minuta++;
	if(minuta==60)
	{
		minuta=0;
		stepen--;
	}
}


if(sekunde>30)
{
	for(j=i; j<n-1;j++)
	{
		niz[j]=niz[j+1];
	}
n--;
i--;
continue;
}


 printf("%d stepeni %d minuta %d sekundi\n" , stepen,minuta,sekunde);

}
}


	return 0;

}
