#include <stdio.h>
#define PI 3.1415926
#include<stdlib.h>
#include<math.h>

int main() {
	int step=0, min=0, sec=0,i,j,k;

	double totsec=0, ugao[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d",&k);
	
        for(i=0; i<k; i++){
        	scanf("%lf", &ugao[i]);
        }
                printf("Uglovi su:\n");
                
                 for(i=0; i<k; i++)
{
	totsec=fabs((ugao[i]*180/PI)*3600);
	totsec=abs((int)(totsec+0.5));
	step=(totsec/3600);
	min=abs((totsec-step*3600)/60);
	sec=abs((totsec-step*3600-min*60));


if(sec>=60)
{
	min+=1;
	sec-=60;
}
if(min>=60){
	step+=1;
	min-=60;;
}
if(sec>30)
{
	for(j=i; j<k-1; j++)
	{
		ugao[j]=ugao[j+1];
	}
	
	k--;
	i--;
}
    else if(ugao[i]<0)
          
          	printf("-%d stepeni %d minuta %d sekundi\n",step,min,sec);
          
         else{
         printf("%d stepeni %d minuta %d sekundi\n", step,min,sec);}}
                   
	return 0;
}







