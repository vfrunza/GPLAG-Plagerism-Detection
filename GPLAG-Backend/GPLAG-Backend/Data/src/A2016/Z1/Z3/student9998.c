#include <stdio.h>

int main() {
	char vozila;
	int br_c=0, br_b=0, br_s=0, br_v=0, br_p=0,ukupno=0;
	double p_c,p_b,p_s,p_v,p_p;
	printf("Unesite vozila: ");

	while(1){
		vozila=getchar();
		if(vozila=='\n') vozila=getchar();
	   // scanf("%c",&vozila);
		if(vozila=='K'|| vozila=='k') break;
	    if(vozila=='C' || vozila=='c') { br_c++; ukupno++;}
		else if(vozila=='B' || vozila=='b') {br_b++; ukupno++;}
		else if(vozila=='S' || vozila=='s') {br_s++; ukupno++;}
		else if(vozila=='V' || vozila=='v') {br_v++; ukupno++;}
		else if (vozila=='P' || vozila=='p') {br_p++; ukupno++;}
	    else printf("Neispravan unos\n");
	}
	
	if(ukupno==0){
		p_c=0;p_b=0;p_s=0;p_v=0;p_p=0;
	}
	else{
		p_c=((double)br_c/ukupno)*100;
		p_b=((double)br_b/ukupno)*100;
		p_s=((double)br_s/ukupno)*100;
		p_v=((double)br_v/ukupno)*100;
		p_p=((double)br_p/ukupno)*100;
	  }
/*	if(ukupno==0){
		printf("Ukupno evidentirano 0 vozila.\n");
		printf("Najpopularnija boja je crna (0.00%).");
	}
	else{*/
	if (br_c-br_b>=0 && br_c-br_s>=0 && br_c-br_v>=0 && br_c-br_p>=0){
		printf("Ukupno evidentirano %d vozila.\n",ukupno);
		printf("Najpopularnija boja je crna (%.2lf%%).",p_c);
	}
	
	else if(br_b-br_c>=0 && br_b-br_s>=0 && br_b-br_v>=0 && br_b-br_p>=0){
		printf("Ukupno evidentirano %d vozila.\n",ukupno);
		printf("Najpopularnija boja je bijela (%.2lf%%).",p_b);
	}
	
	else if(br_s-br_c>=0 && br_s-br_b>=0 && br_s-br_v>=0 && br_s-br_p>=0){
		printf("Ukupno evidentirano %d vozila.\n",ukupno);
		printf("Najpopularnija boja je siva (%.2lf%%).",p_s);
	}
	
	else if(br_v-br_c>=0 && br_v-br_b>=0 && br_v-br_s>=0 && br_v-br_p>=0){
		printf("Ukupno evidentirano %d vozila.\n",ukupno);
		printf("Najpopularnija boja je crvena (%.2lf%%).",p_v);
	}
	
	else if(br_p-br_c>=0 && br_p-br_b>=0 && br_p-br_s>=0 && br_p-br_v>=0){
		printf("Ukupno evidentirano %d vozila.\n",ukupno);
		printf("Najpopularnija boja je plava (%.2lf%%).",p_p);
	}
	
	return 0;
}
