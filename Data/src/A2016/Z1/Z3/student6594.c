#include <stdio.h>
int main() {
int crna=0,bijela=0,siva=0,plava=0,crvena=0,d=0;
char a='a';
float proc;
printf("Unesite vozila: ");
do{
		scanf("%c",&a);	
	if(a=='c' || a=='C')
		crna++;
	 else if(a=='b' || a=='B')
		bijela++;
	else if(a=='s' ||a=='S')
		siva++;
	else if(a=='p'|| a=='P')
		plava++;
	else if(a=='v' || a=='V')
		crvena++;
	 else if(a=='k' || a=='K')
		break;
		else printf("Neispravan unos\n");
	   }while(1); 
				d=crna+bijela+crvena+plava+siva;	
	printf("Ukupno evidentirano %d vozila.\n",d);
			if(crna>=bijela && crna>=plava && crna>=crvena && crna>=siva){
		proc=(crna*100)/(float)d;
		if(d==0)
		proc=0.;
			printf("Najpopularnija boja je crna (%.2f%%).",proc);
			return 0;
					}
	if(bijela>=crna && bijela>=plava && bijela>=crvena && bijela>=siva){
				proc=(bijela*100)/(float)d;
			printf("Najpopularnija boja je bijela (%.2f%%).",proc);
			return 0;
					}
	if(siva>=crna && siva>=bijela && siva>=plava && siva>=crvena){
	proc=(siva*100)/(float)d;
	printf("Najpopularnija boja je siva (%.2f%%).",proc);
	return 0;
}
		if(crvena>=crna && crvena>=bijela && crvena>=plava && crvena>=siva){
	proc=(crvena*100)/(float)d;
	printf("Najpopularnija boja je crvena (%.2f%%).",proc);
	return 0;
	}

	if(plava>=crna && plava>=bijela && plava>=crvena && plava>=siva){
			proc=(plava*100)/(float)d;
			printf("Najpopularnija boja je plava (%.2f%%).",proc);
			return 0;
					}
	}
		


