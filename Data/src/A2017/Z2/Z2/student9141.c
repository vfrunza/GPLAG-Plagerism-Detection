#include <stdio.h>

int main() {
    int velicina, i=0, c=0, p=0, cifra=0, brojcifara=0, pomocnibrojac=0, element=0, velicinafinalnog=0, ukupnocifara=0;
    int niz[100]={0}, pomocni[1000]={0}, finalni[1000];
    do{
	    printf("Unesite velicinu niza: ");
	    scanf("%d", &velicina);
    }while(velicina<0 || velicina>100);
    printf("Unesite clanove niza: ");
    for(i=0; i<velicina; i++){
        scanf("%d", &niz[i]);
        if(niz[i]<0) i--;
    }
    for(i=velicina-1; i>=0; i--){
        element=niz[i];
        if(element==0){
            brojcifara++;
        }else{
            while(element>0){ 
                element/=10;
                brojcifara++;
            }
        }
    }
    ukupnocifara=brojcifara;
    for(i=velicina-1; i>=0; i--){
        element=niz[i];
        if(element==0){
            pomocni[brojcifara-1]=0;
            brojcifara--;
        }else{
            do{
                  cifra=element%10;
                  pomocni[brojcifara-1]=cifra;
                  brojcifara--;
                  element=element/10;
            }while(element>0);
        }
    }
    for(i=0; i<ukupnocifara; ){
        pomocnibrojac=1;
        while(pomocni[p+i+1]==pomocni[i] && (p+i+1)<ukupnocifara){
            pomocnibrojac++;
            p++;
        }
        finalni[c]=pomocni[i];
        finalni[++c]=pomocnibrojac;
        i=i+p+1;
        c++;
        velicinafinalnog+=2;
        p=0;
    }
    
    
    
    printf("Finalni niz glasi:\n");
    for(i=0; i<velicinafinalnog; i++){ 
        if(i==0) printf("%d", finalni[i]);
        else printf(" %d", finalni[i]);
    }
	return 0;
}
