#include <stdio.h>
#include <ctype.h>
int main() {
	//printf("Zadaća 1, Zadatak 3");
	char bojaAutomobila,a;
	int c=0,b=0,s=0,v=0,p=0,ukupno=0;
	printf("Unesite vozila: ");
	do{
		bojaAutomobila=getchar();
		bojaAutomobila=toupper(bojaAutomobila);
		if(bojaAutomobila=='\n')
			continue;
		switch(bojaAutomobila){
			case 'C':
				c++;
				ukupno++;
				break;
			case 'B':
				b++;
				ukupno++;
				break;
			case'S':
				s++;
				ukupno++;
				break;
			case 'V':
				v++;
				ukupno++;
				break;
			case 'P':
				p++;
				ukupno++;
				break;
			case 'K':
				break;
			default:
				printf("Neispravan unos\n");
				break;
		}
	}while(bojaAutomobila!='K');
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	printf("Najpopularnija boja je ");
	if(ukupno==0){
		printf("crna (0.00%).");
		return 0;
	}
	if(c>=b && c>=s && c>=v && c>=p)
		printf("crna (%.2f%).", ((float)c/ukupno*100+ 0.));
	if(b>c && b>=s && b>=v && b>=p)
		printf("bijela (%.2f%).", ((float)b/ukupno*100+ 0.));
	if(s>c && s>b && s>=v && s>=p)
		printf("siva (%.2f%).", ((float)s/ukupno*100+ 0.));
	if(v>c && v>b && v>s && v>=p)
		printf("crvena (%.2f%).", ((float)v/ukupno*100+ 0.));
	if(p>c && p>b && p>s && p>v)
		printf("plava (%.2f%).", ((float)p/ukupno*100+ 0.));
	return 0;
}
//I molim te ne naginji se kroz prozor
