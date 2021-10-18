#include <stdio.h>
void unesi(char niz[], int velicina)
{
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

void najduzi_bp(char* s1, char* s2){
	int niz1[100],i,broj_slova=0,broj_rijeci=0,a=0,max,niz2[100],j=0;
    while(*s1!='\0'){
        if(*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z')){
        razmak=1;
        for(b=j; b>0; b--){
        for(c=b-1; c>0; c--){
        	if(niz2[b]==niz2[c])
        	niz2[c]=niz2[c+1];
        	j--;
        	c--;
        }
        }
        }
		else if(razmak==1)
		razmak=0;
		if(razmak==0){
		j++;
		char*p=*(s1++);
		while(!(*p>='A' && *p<='Z' || *p>='a' && *p<='z')){
		if(*s1==*p){
	
			}
		p++;
		}
		s1++;
    	for(a=0; a<i; a++){
    		
    	}
    }
        }
    }
}
