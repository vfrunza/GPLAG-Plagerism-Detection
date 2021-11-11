#include <stdio.h>
int main() {
	char a;
	float c=0,b=0,s=0,v=0,p=0,i=0;
	float u;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &a);
		if(a == 'C' || a == 'c'){
		i++;c++;}
		else if(a == 'B' || a == 'b'){
		i++;b++;}
		else if(a == 'S' || a == 's'){
		i++;s++;}
		else if(a == 'V' || a == 'v'){
		i++;v++;}
		else if(a == 'P' || a == 'p'){
		i++;p++;}
		else if(a == 'K' || a == 'k');
		else{
        printf("Neispravan unos\n");}
		}while(a!='k' && a!='K');
		printf("Ukupno evidentirano %g vozila.",i);
		if(i==0){
		printf("\nNajpopularnija boja je crna (0.00%%).");
		return 0;}
		
		if(c>=b&&c>=s&&c>=v&&c>=p){
			u=(c/i)*100;
			printf("\nNajpopularnija boja je crna (%.2f%%).",u);
			return 0;
		}
			if(b>=c&&b>=s&&b>=v&&b>=p){
			u=(b/i)*100;
			 printf("\nNajpopularnija boja je bijela (%.2f%%).",u);
			 return 0;
		}
			if(s>=b&&s>=c&&s>=v&&s>=p){
			u=(s/i)*100;	
			 printf("\nNajpopularnija boja je siva (%.2f%%).",u);
			 return 0;
		}
			if(v>=b&&v>=s&&v>=c&&v>=p){
			u=(v/i)*100;	
			 printf("\nNajpopularnija boja je crvena (%.2f%%).",u);
			 return 0;
		}
			if(p>=b&&p>=s&&p>=v&&p>=c){
			u=(p/i)*100;	
			 printf("\nNajpopularnija boja je plava (%.2f%%).",u);
			 return 0;
		}
	return 0;
}
