#include <stdio.h>

int uporedi(char *prva, char *druga, int duzina){
	char *p=prva, *d=druga;
	int brojac=0;
	while(*d!='\0'){
		if(*p!=*d)
			return 0;
		p++;
		d++;
		brojac++;
	}
	if(*d=='\0'&&brojac!=duzina)
			return 0;
	return 1;
}
	
char  *prepisi(char *tekst,char *prva, char *druga, int duzina, int brojac){
	int i;
	char *d=druga, *kraj=tekst, *p=prva;
	if(brojac==0){
		while(*kraj!='\0') kraj++;
		char *pok=prva;
		while(pok!=kraj-duzina){
			*pok=*(pok+duzina);
			pok++;
			
		}
		*pok='\0';
		return tekst;
	}
	
	if(brojac!=duzina){
		if(brojac==1){
			while(*kraj!='\0') kraj++;
			char *pok=prva+1;
			while(pok!=kraj-duzina+1){
				*pok=*(pok+duzina-1);
				pok++;
			}
			*pok='\0';
			*prva=*druga;
			return tekst;
		}
		while(*kraj!='\0') kraj++;
		if(brojac>duzina){
			while(kraj!=p){
				*(kraj+brojac-duzina)=*kraj;
				kraj--;
			}
		}
		if(brojac<duzina){
			char *oduzima=p+duzina-brojac-1;
			while(oduzima!=kraj-(duzina-brojac)){
				*oduzima=*(oduzima+duzina-brojac);
				oduzima++;
			}
			*oduzima='\0';
			
		}
		
	}
	
	
	for(i=0;i<brojac;i++)
		*(p+i)=*(d+i);
	return tekst;
	
}

char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci){
	int i=0,j=0,k,z,brojac_slova[100]={0}, brojac_rijeci=1, zamjena_velicina[50]={0};
	char *p, *pok[100], *p_rijec[100], *p_zamjena[100];

	for(i=0;i<broj_rijeci;i++){
		p_zamjena[i]=zamjene[i];
	}
	for(i=0;i<broj_rijeci;i++){
		char *z=p_zamjena[i];
		while(*z!='\0'){
			zamjena_velicina[i]++;
			z++;
		}
	}
	
	for(i=0;i<broj_rijeci;i++){
		p_rijec[i]=rijeci[i];
	}
	
	p=tekst;
	pok[j]=p;
	i=0;
	while(*p!='\0'){
		if(*p==' '){
			brojac_rijeci++;
			do{
				p++;
			}while(*p==' ');
			i++;
			j++;
			pok[j]=p;
			continue;
			
		}
		brojac_slova[i]++;
		p++;
	}

	for(i=0;i<brojac_rijeci;i++){
		for(j=0;j<broj_rijeci;j++){
			if(uporedi(pok[i],p_rijec[j],brojac_slova[i])){ 
				tekst=prepisi(tekst,pok[i],p_zamjena[j],brojac_slova[i], zamjena_velicina[j]);
				int z;
				if(zamjena_velicina[j]>brojac_slova[i]){
					for(k=0;k<zamjena_velicina[j]-brojac_slova[i];k++){
						for(z=i;z<brojac_rijeci;z++)
							pok[z+1]++;
					}
				}
				if(zamjena_velicina[j]<brojac_slova[i]){
					for(k=0;k<-zamjena_velicina[j]+brojac_slova[i];k++){
						for(z=i;z<brojac_rijeci;z++)
							pok[z+1]--;
					}
				}
			}
		}
	}
	
	return tekst;
}



int main() {
	char *rijeci[3]={"realno", "Ovo", "nije"};
	char *zamjena[3]={"zix", "zax", "zex"};
	char tekst[100]="Ovo nije realno";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjena, 3));
	return 0;
}