#include <stdio.h>
#include <string.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
/*Poredi dvije rijeci koje se zavrsavaju razmakom*/
int poredi_rijeci (char *s1,char *s2){
	while ((*s1!=' ' || *s1!='\0') && (*s2!=' ' || *s2!='\0')){
		if(*s1==*s2){
			s1++;
			s2++;
			if(*s1=='\0' || *s2=='\0') break;
			if(*s1==' ' || *s2==' ') break;
		}
		else return 0;
	}
	
	/*ako je jedan string zavrsen a drugi nije*/
	if((*s1==' ' || *s1=='\0') && (*s2!=' ' && *s2!='\0')) return 0;
	if ((*s2==' ' || *s2=='\0') && (*s1!=' ' && *s1!='\0'))return 0;
	if(*s1==' ' || *s1=='\0') s1--;
	if(*s2==' ' || *s2=='\0') s2--;
	if(*s1==*s2) return 1;
	return 0;
}
/*Broj slova u rijeci*/
int brojsl(char*s1){
	int brsl=0;
	while ((*s1>=65 && *s1<=90) || (*s1>=97 && *s1<=122)){
		brsl++; s1++;
		if(*s1=='\0') break;
	}
	return brsl;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
    char*p=tekst, *q=tekst, *zamjena;
    int brojslovarijeci, brojslovazamjene, i, razlika, j, desiosebreak=0;
    for(i=0;i<broj_rijeci;i++){
        p=tekst;
        while(*p!='\0'){
            brojslovarijeci=0;
            brojslovazamjene=0;
            while(*p==' '){
                p++;
                if(*p=='\0'){
                    desiosebreak=1;
                    break;
                }
            if(desiosebreak) break;
            }
            if(poredi_rijeci(p,*(rijeci+i))){
                brojslovarijeci=brojsl(*(rijeci+i));
                brojslovazamjene=brojsl(*(zamjene+i));
                /*Mora se pomjeriti udesno za velicinu razlike*/
                if(brojslovazamjene>brojslovarijeci){
                    razlika=brojslovazamjene-brojslovarijeci;
                    q=p;
                    while(*q!='\0') q++;
                    while(q!=p){
                        *(q+razlika)=*q;
                        q--;
                    }
                    zamjena=*(zamjene+i);
                    for(j=0;j<brojslovazamjene;j++){
                        *q=*zamjena;
                        q++;
                        zamjena++;
                    }
                }
                /*Mora se pomjeriti ulijevo za velicinu razlike*/
                else if(brojslovarijeci>brojslovazamjene){
                    razlika=brojslovarijeci-brojslovazamjene;
                    q=p;
                    
                    for(j=0;j<brojslovazamjene;j++){
                        *q=**(zamjene+i);
                        q++;
                        (*(zamjene+i))++;
                    }
                    while(*(q+razlika)!='\0'){
                        *q=*(q+razlika);
                        q++;
                    }
                    *q='\0';
                }
                /*velicina stringa ostaje ista*/
                else if(brojslovazamjene==brojslovarijeci){
                    q=p;
                    zamjena=*(zamjene+i);
                    for(j=0;j<brojslovarijeci;j++){
                        *q=*zamjena;
                        q++;
                        zamjena++;
                    }
                }
                
            }
            /*Dolazi do kraja ispitanje rijeci*/
            while(*p!=' '){
                    if(*p=='\0') break;
                    p++;
            }
        }
    }
    return tekst;
}

int main (){
    char tekst[100];
    printf("Unesite tekst: ");
    unesi(tekst,100);
    char *zamjene[3]={"dobro"};
    char *rijeci[3] = {"dobro"};
    int broj_rijeci=1;
    printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, broj_rijeci));

    return 0;
}