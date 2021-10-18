#include <stdio.h>

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	int i, j=0,k=0,h=0,x;
	char *p=tekst,*t=tekst;
	char* kraj=p;
	if(tekst==NULL || broj_rijeci<=0) return t;
	while(*tekst!='\0'){
		for(i=0;i<broj_rijeci;i++){
			while(*tekst!=' ' && *tekst!=',' && rijeci[i][j]!='\0'){
				if(*tekst!=rijeci[i][j]) break;
				tekst++;
				j++;
			}
			if((*tekst==' ' || *tekst==',' || *tekst=='\0') && rijeci[i][j]=='\0'){
				k=0;h=0;
				while(rijeci[i][k]!='\0') k++; 
				while(zamjene[i][h]!='\0') h++;
				while(*kraj!='\0') kraj++;
				while(kraj>p){
					*(kraj+h-k)=*kraj;
					kraj--;
				}
				for(x=0;x<h;x++){
					if(*p==' '&& x==0) p++;
					*p=zamjene[i][x];
					p++;
					tekst=p;
				}
			}
			else if(j==broj_rijeci-1 || *tekst=='-' || *tekst==','){
				while(*tekst!=' ' && *tekst!='\0')tekst++;
			}			
			p=tekst;
			j=0;
		}
		
		tekst++;
	}
	return t;
}

int main(){
	char* rijeci[2] = { "c" };
	char* zamjene[2] = {  "Prijestolonasljednikovica" };

	/* Ovako cemo zadati tekst da bi vrijednosti >3 bile neinicijalizirane */
	char tekst[100];
	tekst[0] = 'c';
	tekst[1] = ' ';
	tekst[2] = 'c';
	tekst[3] = '\0';

	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	
	return 0;
}
