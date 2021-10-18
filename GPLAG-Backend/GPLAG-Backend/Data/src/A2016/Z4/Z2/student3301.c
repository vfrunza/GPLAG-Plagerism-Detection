#include <stdio.h>
char *kodiraj(char *s1, char *s2){
	/* Trazenje velicine, i prebrojavanje ponavljanja */ 
	int brojac[200]={0},velicina2=200;
	int i,velicina=0;
	char *p=s1;
	while ((*p++)!='\0') velicina++;
	for (i=0;i<velicina;i++) brojac[(int)s1[i]]++;
	
	
	/* Formiranje stringa 2 na osnovu ponavljanja */ 
	int max=brojac[0],index=0;

	char *p2=s2;
	while (1){
		max=0;
		for (i=0;i<velicina2;i++){
			if (brojac[i]>max){
				max=brojac[i];
				index=i;
			} 
		}
		if (max==0) break;
		else if (max!=0){
			*p2=index;
			p2++;
		}
		for (i=0;i<velicina2;i++){
			if (i==index){
				brojac[i]=-1;
			}
		} 
	}
	*p2='\0';
	/* Sifrovanje stringa 1 */ 
	int pozicija=0;
	char *p3=s1,*p4=s2;
	while (*p3!='\0'){
		while (*p4!='\0'){
			if (*p4==*p3){
				*p3=126-pozicija;
				break;
			}
			pozicija++;
			p4++;
		}
		pozicija=0;
		p4=s2;
		p3++;
		
		
	}
	/* String2 dodjela */
	int broj=32;
	char *poc=s2, *kraj=p2;
	while (p2!=&s2[95]){
		while (*poc!=*kraj){
			if (broj==*poc){
				broj++;
				poc=s2;}
			poc++;
		}
		poc=s2;
		*p2=broj;
		p2++;
		broj++;
	}
	
	char *pok=s1;
	return pok;
}
char *dekodiraj(char *s1, char *s2){
	char *p1=s1,*p2=s2;
	int pozicija=0;
	while(*p1!='\0'){
		pozicija=126-*p1;
		*p1=*(p2+pozicija);
		p1++;
	}

	
	char *pok=s1;
	return pok;

	
}

int main() {
	char string[]="Ovo je neki testni tekst",string2[90];
	
	kodiraj(string,string2);
	printf ("%s \n",string);
	printf ("%s \n",string2);
	dekodiraj(string,string2);
	printf ("%s",string);



	return 0;
}
