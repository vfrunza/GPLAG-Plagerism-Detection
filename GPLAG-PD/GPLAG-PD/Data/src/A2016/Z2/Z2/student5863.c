#include <stdio.h>
#include<math.h>
#define PI 3.1415926

int main() {
	
	int n;
	float st,stepeni,minute,sekunde,y;
	float niz[500];
	int i,j;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&niz[i]);
	}
	
	for(i=0;i<n;i++)
	{
	st=niz[i]*180/PI;
	stepeni=(int)st;
	minute=(int)((st-stepeni)*60);
	sekunde=(st-stepeni-minute/60.)*3600;
		y=round(sekunde);
		
		if(y==60) {minute=minute+1; y==0;}
	if(minute==60){
		stepeni=stepeni+1;
		minute==0;
	}
	
	if(y==-60) {minute=minute-1; y==0;}
	if(minute==-60){
		stepeni=stepeni-1;
		minute==0;
	}
	
		
		
	
		if(y>30 ||y<-30)
{
		for(j=i;j<n-1;j++)
		{
			niz[j]=niz[j+1];
		}
		n--;
		i--;
			
	
	
		}}
		for( i=0; i<n;i++){
			
	st=niz[i]*180/PI;
	stepeni=(int)st;
	minute=(int)((st-stepeni)*60);
	sekunde=(st-stepeni-minute/60.)*3600;
	
	if(sekunde==60) {minute=minute+1; sekunde==0;}
	if(minute==60){
		stepeni=stepeni+1;
		minute==0;
	}
printf("%.f stepeni ",stepeni);
printf("%.f minuta ",fabs(minute));
printf("%.f sekundi \n",fabs(sekunde));
	}

	return 0;
}


