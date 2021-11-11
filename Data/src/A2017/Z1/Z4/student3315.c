                             -------------> DATOTEKE <-------------
                             
                             
VAZNO ZA DATOTEKE: 
FUNKCIJA FSCANF CITA SVE NORMALNO OSIM KADA IMAMO STRING KOJI SADRZI RAZMAKE, TADA NE RADI DOBRO!
FUNKCIJU FGETC-MOZEMO DA KORISTIMO KOD BINARNIH DATOTEKA, FSCANF I FPRINTF NE SMIJEMO


napomena: zadatak sa datotekom uradjen u tutu-5 (zad-1) sa materijali.etf---> VAZNO ZBOG ISCITAVANJA IZ DATOTEKE
                             
                             
                             

ZADATAK1                             
iz ulazne datoteke i nput.txt se čitaju podaci znak po znak, te ako se neki
znak (karakter) ulazne datoteke ponavlja n ili više puta zaredom, treba taj niz
znakova upisati u izlaznu datoteku output.txt

#include <stdio.h>

int main(){
 int n;
 int c;
 int prvi_put=1;
 int brojac=1;
 printf("Unesite broj: ");
 scanf("%d",&n);
 
 
 if(n<1)
 printf("Pogresan unos");
 
 FILE* ulaz=fopen("input.txt","r");
 if(ulaz==NULL){
  printf("Nije uspjelo otvaranje datoteke!");
  return 1;
 }
 
 FILE* izlaz=fopen("output.txt","w");
 if(izlaz==NULL){
  printf("Nije uspjelo otvaranje datoteke!");
 }
 
 
 int i=1;
 int stari_znak;
 int novi_znak;
 int kontrolna=1;
 int upisano=0;
 
 while((novi_znak=fgetc(ulaz))!=EOF){
 
  if(kontrolna==1){
   kontrolna++;
   stari_znak=novi_znak;
   continue;
  }
  else{
   if(stari_znak==novi_znak){
    stari_znak=novi_znak;
    brojac++;
    
    while((novi_znak=fgetc(ulaz))==stari_znak){
     stari_znak=novi_znak;
     brojac++;
    }
    if(novi_znak!=stari_znak){
        
     if(brojac<n){
      brojac=1;
      stari_znak=novi_znak;
     }
     else{
      while(i<=brojac){
       fputc(stari_znak,izlaz);
       upisano=1;
       i++;
      }
      i=1;
      brojac=1;
      stari_znak=novi_znak;
      continue;
     }
     
     
    }
    
   }
   else{
    stari_znak=novi_znak;
    continue;
   }
   
  }
 
  }

 fclose(ulaz);
 fclose(izlaz);
 
 return 0;
 
}


ZADATAK 2
iz ulazne datoteke i nput.txt se čitaju
podaci znak po znak, a u izlaznu datoteku output.txt se zapisuju svi karakteri iz
ulazne datoteke čija je ASCII vrijednost između x i y (uključujući i ta dva):

int main(){
 int c;
 char x,y;
 printf("Unesite znakove x i y: ");
 scanf("%c %c",&x,&y);
 
 if(y<x){
  printf("Pogresan unos");
  return 0;
 }
 
 FILE* ulaz=fopen("input.txt","r");
 if(ulaz==NULL){
  printf("Nije moguce citanje iz datoteke!");
  return 1;
 }
 
 FILE* izlaz=fopen("output.txt","w");
 if(izlaz==NULL){
  printf("Nije moguce pisati u datoteku!");
  return 2;
 }
 
 int znak;
 
 while((znak=fgetc(ulaz))!=EOF){
  if((znak>=x && znak<=y)){
   fputc(znak,izlaz);
  }
  else{
  continue;
  }
 }
 
 
 while((c=fgetc(izlaz))!=EOF){
  c=fgetc(izlaz);
  printf("%c",c);
 }
 
fclose(ulaz);
fclose(izlaz);

 return 0;

}

ZADATAK3

Napisati program koji od korisnika zahtijeva unos niza brojeva, najviše 100. Unos
se prekida kada korisnik unese -1. Nakon toga unesene brojeve treba upisati u
binarnu datoteku brojevi.bin. Na kraju, program ispisuje sadržaj datoteke.

int main(){
 int niz[100];
 int i;
 //printf("Unesite niz brojeva: ");
 for(i=0;i<100;i++){
  scanf("%d",&niz[i]);
  if(niz[i]==(-1))
  break;
 }
 int velicina=i;
 
 FILE* pok=fopen("brojevi.bin","wb");
 if(pok==NULL){
  printf("Problemi sa otvaranjem datoteke!");
  return 1;
 }
 
 fwrite(niz,sizeof(i),velicina,pok);
 if(ferror(pok)){
  printf("Ne mozemo upisati u datoteku!");
 }
 
 fclose(pok);
 
 FILE* ulaz=fopen("brojevi.bin","rb");
 if(ulaz==NULL){
  printf("Problemi sa otvaranjem datoteke!");
 }
 
 int ucitano;
 int rezultat[100];
 ucitano=fread(rezultat,sizeof(ucitano),velicina,ulaz);
 if(ferror(ulaz))
 printf("greska");
 

 
 
 int j;
 for(j=0;j<ucitano;j++){
  printf("%d",rezultat[j]);
 }
 
 fclose(ulaz);
 
 return 0;
 
 
}


ZADATAK4-URADJEN U ZSR-12 ZAD-5 binarna datoteka

Napišite funkciju analiza koja čita podatke iz ovakve datoteke, pronalazi
broj koji se pojavljuje najviše puta u datoteci (ako se više brojeva pojavljuje isti broj
puta, uzima se najmanji od njih). Funkcija vraća ukupan broj pojavljivanja u datoteci
brojeva koji su veći od tog broja



ZSR13

ucitavanje podataka iz datoteke u niz struktura, imamo imena gradova sa razmacima!!
te zapisivanje istih podataka i nihovo ispisivanje na ekran


struct Grad{
 int br_stanovnika;
 char ime_grada[30];
};


void ucitaj(struct Grad niz[],int n,int velicina){
 FILE* ulaz=fopen("gradovi.txt","r");
 
 char niz1[30];
 
 char znak;
 int temp;
 
 int i=0;
 int kontrolna=0;
 while(kontrolna<=n){
  
  while(1){
   znak=fgetc(ulaz);
   if(znak==',' || znak==EOF)
   break;
   
   niz1[i]=znak;
   i++;
  
  }
  niz1[i]='\0';
  i=0;
  
  strcpy(niz[kontrolna].ime_grada,niz1);
  
 //printf("%s",niz[kontrolna].ime_grada);
  
  while(fscanf(ulaz,"%d",&niz[kontrolna].br_stanovnika)==1);
 
 // printf("%d\n",niz[kontrolna].broj_stanovnika);
  kontrolna++;
  
  
 }

}

void zapisi(struct Grad niz[],int velicina, int stanovnici){
 FILE* izlaz=fopen("izlaz.txt","w");
 int i;
 for(i=0;i<velicina;i++){
  if(niz[i].br_stanovnika>stanovnici){
   fprintf(izlaz,"%s\n",niz[i].ime_grada);
  }
 }

}


void ispisi(struct Grad niz[],int broj_gradova,char znak){
 int i;
 int temp=0;
 for(i=0;i<broj_gradova;i++){
  if(niz[i].ime_grada[temp]==znak){
   printf("%s\n",niz[i].ime_grada);
  }
 }
 
}

int main(){
struct Grad gradovi[10];
ucitaj(gradovi,3,2);
zapisi(gradovi,3,556453);
ispisi(gradovi,3,'T');

 return 0;
}






