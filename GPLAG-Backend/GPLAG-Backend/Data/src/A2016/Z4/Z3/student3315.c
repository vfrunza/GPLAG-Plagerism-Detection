#include <stdio.h>

int uporedi(char *rijec1, char *rijec2, int duzina){
	char *m=rijec1, *n=rijec2;
	int brojac=0;
	while(*n!='\0'){
		if(*m!=*n)
			return 0;
		m++;
		n++;
		brojac++;
	}
	if(*n=='\0'&&brojac!=duzina)		
			return 0;
	return 1;
}
char  *prepisi(char *tekst,char *rijec1, char *rijec2, int duzina, int brojac){
	int i;
	char *n=rijec2, *kraj=tekst, *m=rijec1;
	if(brojac==0){
		while(*kraj!='\0') kraj++;
		char *pok=rijec1;
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
			char *pok=rijec1+1;
			while(pok!=kraj-duzina+1){
				*pok=*(pok+duzina-1);
				pok++;
			}
			
			*rijec1=*rijec2;
			return tekst;
		}
		while(*kraj!='\0') kraj++;
		if(brojac>duzina){
			while(kraj!=m){
				*(kraj+brojac-duzina)=*kraj;
				kraj--;
			}
		}
		if(brojac<duzina){
			char *oduzima=m+duzina-brojac-1;
			while(oduzima!=kraj-(duzina-brojac)){
				*oduzima=*(oduzima+duzina-brojac);
				oduzima++;
			}
			
			
		}
		
	}
	
	
	for(i=0;i<brojac;i++)
		*(m+i)=*(n+i);
	return tekst;
	
}
char *p, *pok[100], *p_rijec[100], *p_zamjena[100];
char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci){
	int i=0,j=0,brojac_slova[100]={0}, brojac_rijeci=1, zamjena_velicina[50]={0};
	

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

	
	int a,b;
	for(i=0;i<brojac_rijeci;i++){
		for(j=0;j<broj_rijeci;j++){
			if(uporedi(pok[i],p_rijec[j],brojac_slova[i])){ 
				tekst=prepisi(tekst,pok[i],p_zamjena[j],brojac_slova[i], zamjena_velicina[j]);
				
				if(zamjena_velicina[j]>brojac_slova[i]){
					for(a=0;a<zamjena_velicina[j]-brojac_slova[i];a++){
						for(b=i;b<brojac_rijeci;b++)
							pok[b+1]++;
					}
				}
				if(zamjena_velicina[j]<brojac_slova[i]){
					for(a=0;a<-zamjena_velicina[j]+brojac_slova[i];a++){
						for(b=i;b<brojac_rijeci;b++)
							pok[b+1]--;
					}
				}
			}
				
		}
	}
	
	
	
	
	
	return tekst;
}



int main() {
	char tekst[100]="Ispisi dati tekst";
	char *rijeci[3]={"proba", "Ovo", "je"};
	char *zamjene[3]={"a", "a", "a"};
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 3));
	return 0;
}