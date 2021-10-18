#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	double niz[500],ugao=0;
	double temp=0;
	int n=0,i=0,j=0,stepen=0,minute=0,sekunde=0;
	
	/*unos broja uglova*/
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	/*unos niza uglova u radijanima*/
		for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);}
		
		/*ispis*/
		printf("Uglovi su:\n");
		for(i=0;i<n;i++){
			temp=niz[i];
		ugao=(temp*180)/PI;
		stepen=(int)ugao;
		ugao=ugao-stepen;
		ugao=ugao*60;
		minute=(int)ugao;
		
		ugao=ugao-minute;
		ugao=ugao*60;
		if(ugao<0) ugao=ugao-0.5;
		else
		ugao=(ugao+0.5);
		
		sekunde=(int)ugao;
		
		
		
		
		if(sekunde==60){
		sekunde=0;
		minute++;
		
		}
		if(minute==60){
		minute=0;
		stepen++;
		}
		if(sekunde==-60){
		sekunde=0;
		minute--;
		
		}
		if(minute==-60){
		minute=0;
		stepen--;
		}
		
		
		if(sekunde>30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			
			
		
		i--;
		n--;
		continue;}
		else if(sekunde<-30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			i--;
			n--;
			continue;
		}
		else{
		if(sekunde>=0) printf("%d stepeni %d minuta %d sekundi\n",stepen,minute,sekunde); else
		printf("%d stepeni %d minuta %d sekundi\n",stepen,-minute,-sekunde);
	}}
	

	
	
	
	return 0;
}
