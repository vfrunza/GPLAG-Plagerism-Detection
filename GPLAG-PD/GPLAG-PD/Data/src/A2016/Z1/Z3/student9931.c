#include <stdio.h>
#include <math.h>
#define E 0.0001
int main() {
	char boja;
int B,C,S,V,P,max;
float postotak=0,w=0;
C=0;
B=0;
S=0;
V=0;
P=0;
	printf("Unesite vozila: ");
do{
	scanf("%c",&boja);
	
	if(boja =='B' || boja =='b'){
	B++;
	w++;
	}
		 if(boja =='C' || boja =='c'){
	C++;
	w++;}
		else if(boja =='S' || boja =='s'){
	S++;
	w++;}
		else if(boja =='V' || boja =='v'){
	V++;
	w++;}
		else if(boja =='P' || boja =='p'){
	P++;
	w++;}
        if(boja!='C' && boja!='c' && boja!='B' && boja!='b' && boja!='S' && boja!='s' && boja!='V' && boja!='v' && boja!='P' && boja!='p' && boja!='K' &&  boja!='k'){
        	printf("Neispravan unos\n");
        	
        }
 }   
while(boja!='k' && boja!='K');
max=C;
if(B>max){
	max=B;
}
if(S>max){
	max=S;
}
if(V>max){
	max=V;
}
if(P>max){
	max=P;
}
if(C>max){
	max=C;
}
if((fabs(w-0) > E))
postotak=(max*100)/w;
else if((fabs(w-0) < E)) postotak=0;
printf("Ukupno evidentirano %.0f vozila.\n",w);
if(max==C){
	printf("Najpopularnija boja je crna (%.2f%%).",postotak);
}
else if(max==B){
	printf("Najpopularnija boja je bijela (%.2f%%).",postotak);
}
else if(max==S){
	printf("Najpopularnija boja je siva (%.2f%%).",postotak);
}
else if(max==V){
	printf("Najpopularnija boja je crvena (%.2f%%).",postotak);
}
else if(max==P){
	printf("Najpopularnija boja je plava (%.2f%%).",postotak);
}
		return 0;
}
