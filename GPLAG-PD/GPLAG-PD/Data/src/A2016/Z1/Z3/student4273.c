#include <stdio.h>

int main() {
	char vozila;
	int c=0,b=0,s=0,v=0,p=0,ukupno;
	float procent;
	
	printf("Unesite vozila: ");
do{
	scanf("%c",&vozila);
	
	if(vozila=='C' || vozila=='c') c++;
	else if(vozila=='B' || vozila=='b') b++;
	else if(vozila=='S' || vozila=='s') s++;
	else if(vozila=='V' || vozila=='v') v++;
	else if(vozila=='P' || vozila=='p') p++;
	else if(vozila=='K' || vozila=='k') break;
	else printf("Neispravan unos\n"); 
}while(vozila!='K'|| vozila!='k');

ukupno=c+b+s+v+p;
printf("Ukupno evidentirano %d vozila.",ukupno);
if(ukupno==0){ procent=0; printf("\nNajpopularnija boja je crna (%.2f%%).",procent);}
else if((c>b || c==b) && (c>s || c==s) && (c>v || c==v) && (c>p || c==p)){
procent=((float)c/ukupno)*100;
printf("\nNajpopularnija boja je crna (%.2f%%).",procent);
}

else if(b>c && (b>s || b==s) && (b>v || b==v) && (b>p || b==p)){
	procent=((float)b/ukupno)*100;
	 printf("\nNajpopularnija boja je bijela (%.2f%%).",procent);
}
else if(s>c && s>b && (s>v|| s==v) && (s>p || s==p)){
	procent=((float)s/ukupno)*100;
	 printf("\nNajpopularnija boja je siva (%.2f%%).",procent);}
	 else if(v>c && v>b && v>s && (v>p || v==p)){
	procent=((float)v/ukupno)*100;
	 printf("\nNajpopularnija boja je crvena (%.2f%%).",procent);}
	 else if(p>c && p>b && p>s && p>v){
	procent=((float)p/ukupno)*100;
	 printf("\nNajpopularnija boja je plava (%.2f%%).",procent);}
	return 0;
}
