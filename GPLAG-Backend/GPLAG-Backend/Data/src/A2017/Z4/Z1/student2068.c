#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n')znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int velicina_broja(int br){
	int brojac=0;
	int cifra;
	if(br<0)brojac++;
	while(br!=0){
		cifra=br%10;
		brojac++;
		br=br/10;
		
	}
	return brojac;
}

/*int cifra_broja(int br){
	int cifra;
	cifra=br%10;
	return cifra;
}*/

char* ubaci_broj (char* tekst, int broj){
	char* s=tekst;
	int vel;
	
	vel=velicina_broja(broj);
	
	broj=broj+'\0';
	while(*tekst!='0'){
		
		char* pocetak=tekst;
		char* kraj=tekst;
		
		while(*kraj!='\0')kraj++;
		while(*pocetak==' '){
			
			
			pocetak++;
		}
		 while(kraj>pocetak){
		 	 *(kraj+vel)=*kraj;
		 	     
		         kraj--;
		 }
		 
		
		
		
		tekst++;
	
	
	}
	return s;
}



int main() {
	int n;
	char niz[100];
	printf("Unesi: ");
	unesi(niz,100);
	printf("Unesite broj: ");
	scanf("%d",&n);
	printf("%s",ubaci_broj(niz,n));
//printf("%d",velicina_broja(n));
	return 0;
}
