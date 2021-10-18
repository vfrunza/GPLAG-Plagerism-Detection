#include <stdio.h>
#include <stdlib.h>
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
int okreni(int a){
    int tmp=a,cifra,okrenut=0;
    while(tmp!=0){
        cifra=tmp%10;
        okrenut=okrenut*10+cifra;
        tmp/=10;
    }
    return okrenut;

}
int broj_cifri(int a){
    int temp=a,brojac=0;
    while(temp!=0){
        brojac++;
        temp/=10;
    }
    return brojac;
}
char* ubaci_broj(char* tekst, int broj){
    char* pocetak=tekst,*kraj;
    int razmak=1,pomak,cifra,unos,brojac=0;
    while(*tekst!='\0'){
        if(*tekst==' '){
            if(razmak==0){
                tekst++;
                unos=okreni(broj);
                pomak=broj_cifri(broj);
                kraj=tekst;
                pomak++;
                if(unos<0){
                    pomak++;
                }
                while(*kraj!='\0') kraj++;
                while(kraj>=tekst){
                    *(kraj+pomak)=*kraj;
                    kraj--;
                }
                if(unos<0) *tekst++='-';
                while(unos!=0){
                    cifra=unos%10;
                    *tekst=abs(cifra)+'0';
                    tekst++;
                    unos/=10;
                }
                *tekst=' ';


            }
            razmak=1;
        }
        else if(razmak==1){
            razmak=0;
            brojac++;

        }

        tekst++;
    }
    return pocetak;

}
int main (){
    char a[100];
    printf("Unesite recenicu: ");
    unesi(a,100);
    printf("%s", ubaci_broj(a, -21));
    return 0;
}
