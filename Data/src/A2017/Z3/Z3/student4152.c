#include <stdio.h>
#include <stdlib.h>
int izbaci_cifre(int brojevi[] int velicina, int* cifre[], int vel)
{
 int broj_c[10], i, j, k, cifra, br_c=0, znak=1, pravilnost=1;
 //testiramo pravilnost niza niz
 for(i=0; i<vel; i++)
 {
 if((*(cifre+i)<0)||(*(cifre+i)>9))
 pravilnost=0;
 }
 if(pravilnost==1)
 {
 //radimo apsolutnu vrijednost broja i pamtimo predznak
 if(broj<0)
 {
 znak=-1;
 broj*=znak;
 }
 cifra=broj;
 //prebacujemo broj u niz cifara
 //racunamo broj cifara u broj-u
 while(cifra>=1)
 {
 brojevi[br]=cifra%10;
 cifra/=10;
 br++;
 }
 //iz niza cifara broj_c vadimo brojeve koje se traze u nizu niz
 for(i=0; i<br; i++)
 {
 for(j=0; j<vel; j++)
 {
 if(brojevi[i]==*(niz+j))
 {
 for(k=i; k<br; k++)
 brojevi[k]=brojvi[k+1];
 br--;
 i-=1;
 }
 }
 }
 broj=0;
 //pretvaramo filtrirani broj_c ponovo u broj, i vracamo ga u glavni program
 for(i=(br-1); i>=0; i--)
 {
 broj+=brojvi[i];
 broj*=10;
 }
 broj=broj/10*znak;
 return broj;
 }
 else return -99999;
}
int main()
{
 int broj, niz[10], i=0;
 printf("Unesite niz brojeva: ");
 scanf("%d", &niz);
 if (broj)
 {
 printf("Unesite niz cifara (-1 za kraj): ");
 do
 {
 scanf("%d", &niz[i]);
 i++;
 }
 while(niz[i-1]!=-1);
 i--;
 if(izbaci_cifre(brojevi, , i)!=-99999)
 printf("Broj bez cifara glasi: %d", izbaci_cifre(broj, niz, i));
 else printf("Neispravan unos");
 }
 else printf("Neispravan unos");
 return 0;
}