#include <stdio.h>
#define MAX 500
#define PI 3.14

int main() {
	
	
	float a[MAX];
	float ukupno=0;
	int i,n, j,st=0, min=0, sec=0;
	
	printf("Unesite broj uglova: \n");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%f", &a[i]);
		ukupno=(a[i]*180/PI)*3600;
		ukupno=(int)(ukupno+0.5);
		st=ukupno/3600;
		min=(ukupno-st*3600)/60;
		sec=ukupno-st*3600-min*60;
		
		if(sec>=60){
			min++;
			sec-=60;
		}
		if(min>=60){
			st++;
			min-=60;
			
		}
		if(sec>30){
			for(j=i; j<n-1; j++)
			{
				a[j]=a[j+1];
			}
			n--;
		    i--;
		}
		printf("Uglovi su:\n  %d  stepeni  %d minuta %d  sekundi \n", st,min,sec );
		
	}
	
	
	
	return 0;
}
