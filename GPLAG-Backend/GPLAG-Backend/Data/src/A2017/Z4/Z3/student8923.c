#include <stdio.h>
#define razlika 'a'-'A'

int Korektno(char s){
	return ((s>='a' && s<='z') || (s>='A' && s<='Z'));
}

int JeSuLiVelika(char s){
	return s>='A' && s<='Z';
}

void PostaviNiz(unsigned int niz[], int vel){
	unsigned int i;
	for(i=0;i<vel;i++){
		niz[i]=0;
	}
}

void najduzi_bp(char* s1, char* s2){
	char* p=s1, *p1=s1, *p2=s1, *temp1, *temp2;
	unsigned int niz_slova[200]={0}; /*dovoljno velike niz koji ce brojati karaktere*/
	int najveca=0;
	unsigned int pretvori=0;
	while(*s1!='\0'){
		p=s1;
		temp1=p;/*pocetak*/
		while(Korektno(*p) && *p!=' ' && *p!='\0'){
			/*da bi provjeravali ponavljanje istih karaktera najlakse je preko histograma*/
			if(niz_slova[*p]==0){
				/*Ako su velika slova pretvori ih u mala*/
				if(JeSuLiVelika(*p)){
					pretvori=*p+razlika;
					niz_slova[pretvori]++; /*brojimo karaktere*/
				}else{
					niz_slova[*p]++;
				}
				p++;
			}
			else break;
		}
		temp2=p; /*kraj*/
		/*sada nalazimo najduzu rijec*/
		if(temp2-temp1>najveca){
			najveca=temp2-temp1;
			p1=temp1;
			p2=temp2;
		}
		/*trebamo restartovat niz*/
		PostaviNiz(niz_slova,200);
		s1++;
	}
	/*sada nam preostaje da pronadjenu rijec prekopiramo u s2*/
	while(p1!=p2){
		*s2++ = *p1++;
	}
	*s2='\0';
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
