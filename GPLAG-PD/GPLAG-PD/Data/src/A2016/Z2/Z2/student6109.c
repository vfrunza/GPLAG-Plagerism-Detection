#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	int broj, stepeni, minute, sekunde;
	double niz[500]; 
	int i, j, k;
	double radijan, pomocni;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &broj);
	
	j=0;
	while(j<broj)
	{
		scanf("%lf", &radijan);
		niz[j]=radijan;
		j++;
	}
	
	printf("Uglovi su:\n");
	
	for(i=0;i<j;i++)
	{
		pomocni=fabs(niz[i]);
		pomocni=pomocni*180/PI;
		stepeni=(int)pomocni;
		minute=(int)((pomocni - stepeni)*60);
		sekunde=(int)((((pomocni - stepeni)*60 - minute )*60)+0.5);
		if(sekunde+0.001>60) {sekunde=0; minute+=1;}
		if(minute==60) {minute=0; stepeni+=1;}
		
		
		if(sekunde>30 || sekunde<-30)
		{
			for(k=i;k<j-1;k++)
			{
				niz[k]=niz[k+1];
			}
			j--;
			i--;
		}
	}
	
	
	for(i=0;i<j;i++)
	{	
		pomocni=niz[i];
		if(pomocni<0)
		{
			pomocni=fabs(pomocni);
			pomocni=pomocni*180/PI;
			stepeni=(int)pomocni;
			minute=(int)((pomocni - stepeni)*60);
			sekunde=(int)((((pomocni - stepeni)*60 - minute )*60)+0.5);
			if(sekunde+0.001>60) {sekunde=0; minute+=1;}
			if(minute==60) {minute=0; stepeni+=1;}
			stepeni=stepeni*(-1);
			printf("%d stepeni %d minuta %d sekundi\n", stepeni , minute, sekunde);
		}
		else if(pomocni>=0)
		{
			pomocni=pomocni*180/PI;
			stepeni=(int)pomocni;
			minute=(int)((pomocni - stepeni)*60);
			sekunde=(int)((((pomocni - stepeni)*60 - minute )*60)+0.5);
			if(sekunde+0.001>60) {sekunde=0; minute+=1;}
			if(minute==60) {minute=0; stepeni+=1;}
			printf("%d stepeni %d minuta %d sekundi\n", stepeni , minute, sekunde);
		}
	}
	
	
	
	return 0;
}
