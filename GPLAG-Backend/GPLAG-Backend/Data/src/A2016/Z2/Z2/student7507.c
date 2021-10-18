#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	int n,i,ste,min,sec,j;
	float a,n1;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	float niz[500];
	for(i=0;i<n;i++){
		scanf("%f",&niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		if(niz[i]<=0){
			a=(niz[i]*180)/PI;
			ste=a;
			a=(a-ste)*60;
			min=a;
			a=(a-min)*60-0.5;
			sec=a;
			if(sec<=-60){
				min-=1;
				sec+=60;
			}
			if(min<=-60){
				ste-=1;
				min+=60;
			}
			if(sec<=-30){
				for(j=i;j<n-1;j++){
					niz[j]=niz[j+1];
				}
				n--;
				i--;
			}
			else printf("%d stepeni %d minuta %d sekundi\n",ste,(min*-1),(sec*-1));
		}
		else if(niz[i]>=0){
			a=(niz[i]*180)/PI;
			ste=a;
			a=(a-ste)*60;
			min=a;
			a=(a-min)*60+0.5;
			sec=a;
			if(sec>=60){
				min+=1; 
				sec-=60;
			}
			if(min>=60){
				ste+=1;
				min-=60;
			}
			if(sec>30){ 
				for(j=i;j<n-1;j++){
					niz[j]=niz[j+1]; 
				}
				n--;
				i--;
		    }
			else printf("%d stepeni %d minuta %d sekundi\n",ste,min,sec);
		}
	}
	return 0;
}
