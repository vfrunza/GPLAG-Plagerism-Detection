#include <stdio.h>

int main() {
	
char tarik,bojan,mirza;
double r=0,f=0,b=0,min;
int hambas=0,pizza=0,cevap=0;

printf("Unesite jelo za Tarika: ");
scanf("%c",&tarik);
printf("Unesite jelo za Bojana: ");
scanf(" %c",&bojan);
printf("Unesite jelo za Mirzu: ");
scanf(" %c",&mirza);

//tare
if(tarik=='P'){r+=6.80;f+=8.00;b+=5.30;pizza++;}
else if(tarik=='H'){r+=3.30;f+=3.00;b+=5.00;hambas++;}
else {r+=5.00;f+=3.90;b+=6.00;cevap++;}
//boki
if(bojan=='P'){r+=6.80;f+=8.00;b+=5.30;pizza++;}
else if(bojan=='H'){r+=3.30;f+=3.00;b+=5.00;hambas++;}
else{r+=5.00;f+=3.90;b+=6.00;cevap++;}
//mirza
if(mirza=='P'){r+=6.80; f+=8.00; b+=5.30;pizza++;}
else if(mirza=='H'){r+=3.30;f+=3.00;b+=5.00;hambas++;}
else{r+=5.00;f+=3.90;b+=6.00;cevap++;}

	min=r;
	if(f<min) min=f;
	if(b<min) min=b;
    
    if(min==r){
    	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",min);
    	return 0;
    	}
    else if(min==f) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",min);
    else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",min);
    
    
    if(hambas==1 && pizza==1 && cevap==1){
        r=r-6.80*0.1;
    }
    if(pizza==2) r=r-13.60*0.1;
    else if(pizza==3) r=r-r*0.1;
	else if(hambas==3) r=r-r*0.1;
	else if(hambas==2 && pizza==1) r=r-6.80*0.1;
	else if(hambas==2 && cevap==1) r=r-6.60*0.1;
	else if(cevap==2) r=r-10.0*0.1;
	else if(cevap==3) r=r-r*0.1;
	
	if(r<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",r);
	return 0;
}
