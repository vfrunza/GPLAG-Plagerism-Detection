#include <stdio.h>

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

int broj_rijeci(char *s){
	int br=0;
	
	while(*s!='\0'){
	    if(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) && ((*(s-1)>='a' && *(s-1)<='z') || (*(s-1)>='A' && *(s-1)<='Z'))) br++;
		
		s++;
	}
	br++;
	//printf("%d\n",br);
	return br;
	
}     

int provjeri_duzine (char *pok,int niz[], int vel){
    
    int i=0,br=0,br_rijeci;
   
    
    br_rijeci=broj_rijeci(pok);
    
    
    if(br_rijeci==vel){
        
        while(*pok!='\0'){
           if(!((*pok>='a' && *pok<='z') || (*pok>='A' && *pok<='Z')))pok++;
           else {
                while((*pok>='a' && *pok<='z') || (*pok>='A' && *pok<='Z')){
                    br++;
                    pok++;
                }
               // printf("%d\n",br);
                if(br==niz[i])return 1;
                else return 0;
                    i++;
                    br=0;
                }  
            pok++;
        }
    }    
   else return 0;
   
   return 0;
}


int main() {
	
char tekst[] = "Ovo je neki primjer teksta";
int niz[] = {3, 2, 4, 7, 6};
int bezveze_niz[] = {1, 2, 3, 4, 5};

printf("%d \n", provjeri_duzine(tekst, niz, 5));
printf("%d ", provjeri_duzine(tekst, bezveze_niz, 5));

	return 0;
}
