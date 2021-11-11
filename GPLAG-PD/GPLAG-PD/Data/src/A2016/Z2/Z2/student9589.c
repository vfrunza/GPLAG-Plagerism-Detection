#include <stdio.h>
#define PI 3.1415926
#include <math.h>
#define eps 0.001
int main() {
int n;
int broj_el;
double stepeni;
double minute;
double sekunde;
double pom;
int i;
int j;
double niz[500];

printf("Unesite broj uglova: ");
scanf("%d",&broj_el);

for(i=0;i<broj_el;i++){
	scanf("%lf",&niz[i]);
}
for(i=0;i<broj_el;i++){
	pom=niz[i]*180/PI;
	stepeni=(int)pom;
	minute=(int)((pom-stepeni)*3600)/60;
	sekunde=(((pom-stepeni)*60)-minute)*60;


	sekunde=fabs(sekunde);
	if(((sekunde-((int)sekunde)))*100>50){
		sekunde=(sekunde+0.5);
		sekunde=(int)sekunde;
			
		
	}else {
		sekunde=(int)sekunde;
			
	}
	if(fabs(sekunde-60)<eps&&niz[i]>0){
	sekunde=0;
		minute+=1;
		if(fabs(minute-60)<eps){
		stepeni+=1;
			minute=0;
		}
	}else if(fabs(fabs(sekunde)-60)<eps&&niz[i]<0){
		sekunde=0;
		minute-=1;
	if(fabs(fabs(minute)-60)<eps){
		stepeni-=1;
		minute=0;
		
	}
	}
	

	
	if(fabs(sekunde)>30){
		for(j=i;j<broj_el-1;j++){
			niz[j]=niz[j+1];
		}
		broj_el--;
		i--;
	}
}
	sekunde=0;
	stepeni=0;
	minute=0;
	printf("Uglovi su:\n");
for(i=0;i<broj_el;i++){
		pom=niz[i]*180./PI;
	stepeni=(int)pom;
	minute=(int)((pom-stepeni)*60);
	sekunde=((((niz[i]*180./PI)-(int)stepeni)*60)-(int)minute)*60;
	sekunde=fabs(sekunde);
		
	sekunde=(int)(sekunde+0.5);
	if(fabs(sekunde-60)<eps&&niz[i]>0){
		sekunde=0;
		minute+=1;
		if(fabs(minute-60)<eps){
		stepeni+=1;
			minute=0;
		}
	}else if(fabs(fabs(sekunde)-60)<eps&&niz[i]<0){
			sekunde=0;
		minute-=1;
	if(fabs(fabs(minute)-60)<eps){
		stepeni-=1;
		minute=0;
		
	}
	}
minute=fabs(minute);

	
	printf("%0.lf stepeni %0.lf minuta %0.lf sekundi\n",stepeni,minute,sekunde);
	
}


	return 0;
}


