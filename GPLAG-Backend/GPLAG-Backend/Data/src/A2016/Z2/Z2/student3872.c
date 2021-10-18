#include <stdio.h>
#include<math.h>
#define PI 3.1415926
#define broj_el 500
int main() {
	int n,j, i ; 
	long double radijan[broj_el];long double ugao[broj_el];
	long double min[broj_el], sec[broj_el];
	int stepen[broj_el];
	int minute[broj_el];
	int sekunde[broj_el];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%Lf", &radijan[i]);
		ugao[i]=radijan[i]*180/PI;
			stepen[i]=(int)ugao[i];
		
	ugao[i]-=stepen[i];
	ugao[i]*=60;
	min[i]=ugao[i];

	
	minute[i]=(int) ugao[i];
	ugao[i]-=minute[i];
	ugao[i]*=60;
	sec[i]=ugao[i];
	
	sekunde[i]=(int) ugao[i];

	if(sec[i]-sekunde[i]>0.5f) { sekunde[i]+=1;}
	if(sec[i]-sekunde[i]<(-0.5f)) { sekunde[i]-=1;}
	if(min[i]-minute[i]>0.5f) { minute[i]+=1; }
	if(min[i]-minute[i]<(-0.5f)) { minute[i]-=1;}
	if(sec[i]>59.5f) { minute[i]+=1; sekunde[i]=0;}
	if(sec[i]<(-59.5f)) { minute[i]-=1;minute[i]=fabs(minute[i]); sekunde[i]=0;}
	
	if(min[i]>59.5f) { stepen[i]+=1; minute[i]=0; }
	if(min[i]<(-59.5f)) {stepen[i]-=1; minute[i]=0;}
	while(stepen[i]>360.0f) { stepen[i]-=360; }
	while(stepen[i]<(-360.0f)) { stepen[i]+=360;}
if(minute[i]<0) { minute[i]=fabs(minute[i]);}
if(sekunde[i]<0) { sekunde[i]=fabs(sekunde[i]);}
		
		
	} 

		for(i=0;i<n;i++)
		{
			if(fabs(sekunde[i])>30)
			{
				for(j=i;j<n;j++)
				{
					ugao[j]=ugao[j+1];
					stepen[j]=stepen[j+1];
					minute[j]=minute[j+1];
					sekunde[j]=sekunde[j+1];
				
				}
n--;				i--;
			}
		}
		printf("Uglovi su:\n");
		for(i=0;i<n;i++) {
		{ if(radijan[i]==0) printf("0 stepeni 0 minuta 0 sekundi\n");
		else	printf("%d stepeni %d minuta %d sekundi\n", stepen[i], minute[i], sekunde[i]);
		} }
	
	return 0;
	
}

