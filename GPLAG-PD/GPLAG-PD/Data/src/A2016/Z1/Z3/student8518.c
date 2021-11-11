#include<stdio.h>
int main ()
{
	int Crnaboja=0,Bijelaboja=0,Sivaboja=0,Crvenaboja=0,Plavaboja=0,U;
	char znak;
	float P,max;
	printf("Unesite vozila: ");
	 while (1){
	 	scanf("%c",&znak);
	   if (znak=='C'|| znak=='c'){
		Crnaboja++ ;}
		else if (znak=='B'|| znak=='b'){
		Bijelaboja++ ;}
		else if (znak=='S'|| znak=='s'){
		Sivaboja++ ;}
		else if (znak=='V'|| znak=='v'){
		Crvenaboja++ ;}
		else if (znak=='P'|| znak=='p'){
		Plavaboja++ ;}
		else if (znak=='k' || znak=='K'){
			break ; }
         	else {
			printf ("Neispravan unos \n");	} }
			
		U=Crnaboja+Bijelaboja+Sivaboja+Crvenaboja+Plavaboja ;
	   printf("Ukupno evidentirano %d vozila.",U);
	   if(U==0){
	   	printf("\nNajpopularnija boja je crna (0.00%%).");}
	   	else {
	   
	   max=Crnaboja; 
	   znak='c';
	   if(Bijelaboja>max) {
	   	max=Bijelaboja;znak='b';}
	   	if(Sivaboja>max) {
	   		max=Sivaboja ; znak='s'; }
	   		if(Plavaboja>max){
	   			max=Plavaboja ;znak='p' ;}
	   			if(Crvenaboja>max){
	   				max=Crvenaboja; znak='v';}
	   				P=max/U *100 ;
	   				if(znak=='c'){
	   					printf("\nNajpopularnija boja je crna (%.2f%%).",P);}
	   				if(znak=='b'){
	   					printf("\nNajpopularnija boja je bijela (%.2f%%).",P);}
	   				if(znak=='s'){
	   					printf("\nNajpopularnija boja je siva (%.2f%%).",P);}
	                if(znak=='p'){
	   					printf("\nNajpopularnija boja je plava (%.2f%%).",P);}
	                if(znak=='v'){
	   					printf("\nNajpopularnija boja je crvena (%.2f%%).",P);}
	   	}
	   					return 0 ;}