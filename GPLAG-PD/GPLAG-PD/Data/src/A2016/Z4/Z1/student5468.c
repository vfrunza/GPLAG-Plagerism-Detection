#include <stdio.h>
void unesi(char* niz,int vel){
	int i=0;
	char znak=getchar();
	if (znak=='\0')
	znak=getchar();
	while(i<vel-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
char* izbaci_najcescu(char* s){
	char *ret=s,*prvo_slovo[1000],*kraj_rijeci[1000],rijec[1000][1000]={{0}},*pomocni1,*pomocni2,rijec_za_izbaciti[1000],*pokazivac_rijec_za_izbaciti,konvertovano_velika,*kraj_rijeci_pronadjene;
	int neslovo=1,broj_rijeci=0,i,broj_slova=0,j,red,k,brojac_ponavljanja_rijeci[1000]={0},broj_reda_maximuma,logicka_rijec,konvertovano_mala;
	//postavljanje pokazivaca na pocetak svake rijeci i prebrojavanje rijeci
	if(*s=='\0') return ret;
	while(*s!='\0'){
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
        neslovo=1;
        else if (neslovo==1){
         neslovo=0;
         prvo_slovo[broj_rijeci]=s;
         broj_rijeci++;
        }
		s++;
	}
	//postavljanje pokazivaca na kraj rijeci
	for(i=0; i<broj_rijeci; i++){
		kraj_rijeci[i]=prvo_slovo[i];
		while((*kraj_rijeci[i]>='A' && *kraj_rijeci[i]<='Z') || (*kraj_rijeci[i]>='a' && *kraj_rijeci[i]<='z'))
		kraj_rijeci[i]++;
		/*prepisivanje rijeci u matricu*/
		j=0;
		while(kraj_rijeci[i]>prvo_slovo[i]){
				rijec[i][j]=*prvo_slovo[i];
			prvo_slovo[i]++;
			j++;
		}
		rijec[i][j]='\0';
	}
	//pronalazenje istih redova matrice
	for(i=0; i<broj_rijeci-1; i++){
		for(j=i+1; j<broj_rijeci; j++){
			red=1;
			k=0;
			while((rijec[i][k]!='\0')&&(rijec[j][k]!='\0')){
				if((rijec[i][k]!=rijec[j][k]) && (rijec[i][k]!=rijec[j][k]+('a'-'A')) && (rijec[i][k]!=rijec[j][k]-('a'-'A')))
					red=0;
					k++;
			}
			if(rijec[i][k]!=rijec[j][k])
				red=0;
			if(red){
			brojac_ponavljanja_rijeci[i]++;
			}
		}
	}
	//pronalazenje rijeci za izbacivanje
	broj_reda_maximuma=0;
	for(i=1; i<broj_rijeci-1; i++){
			if(brojac_ponavljanja_rijeci[i]>brojac_ponavljanja_rijeci[broj_reda_maximuma])
				broj_reda_maximuma=i;
		}
	
	for(i=0; rijec[broj_reda_maximuma][i]!='\0' ; i++){
		rijec_za_izbaciti[i]=rijec[broj_reda_maximuma][i];
	}
	rijec_za_izbaciti[i]='\0';
	/*prebojavanje duzine rijeci*/
		pomocni1=rijec_za_izbaciti;
		pomocni2=rijec_za_izbaciti;
		while(*pomocni2!='\0'){
			pomocni2++;
		}
		broj_slova=0;
		while(pomocni1<pomocni2){
			pomocni1++;
			broj_slova++;
		}
		
	pokazivac_rijec_za_izbaciti=rijec_za_izbaciti;
	s=ret;
	//izbacivanje rijeci
	while(*s!='\0'){
		logicka_rijec=1;
		pomocni1=s;
		if(((s==ret) || ((*(s-1)<'A' || *(s-1)>'Z') && (*(s-1)<'a' || *(s-1)>'z'))) && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			for(i=0; i<broj_slova; i++){
				
				konvertovano_velika=*(pokazivac_rijec_za_izbaciti+i)-('a'-'A');
				konvertovano_mala=*(pokazivac_rijec_za_izbaciti+i)+('a'-'A');
				if((*(pomocni1+i)!=*(pokazivac_rijec_za_izbaciti+i)) && (*(pomocni1+i)!=konvertovano_velika) && (*(pomocni1+i)!=konvertovano_mala))
					logicka_rijec=0;
			
			
				
			}
			if(*(pomocni1+i-1)!='\0')
				if(((*(pomocni1+i)>='A' && *(pomocni1+i)<='Z') || (*(pomocni1+i)>='a' && *(pomocni1+i)<='z')))
					logicka_rijec=0;
		}
		else logicka_rijec=0;
		
		if(logicka_rijec==1){
		kraj_rijeci_pronadjene=s;
		pomocni2=s;
		while((*kraj_rijeci_pronadjene>='A' && *kraj_rijeci_pronadjene<='Z') || (*kraj_rijeci_pronadjene>='a' && *kraj_rijeci_pronadjene<='z'))
            kraj_rijeci_pronadjene++;
		while(*kraj_rijeci_pronadjene!='\0'){
            *pomocni2=*kraj_rijeci_pronadjene;
            pomocni2++;
            kraj_rijeci_pronadjene++;
		}
		*pomocni2='\0';
		}
		s++;
	}
	return ret;
}
int main() {
char tekst[100];
printf("Unesite tekst: ");
unesi(tekst,100);
printf("String nakon funkcije: '%s'", izbaci_najcescu(tekst));
	return 0;
}
