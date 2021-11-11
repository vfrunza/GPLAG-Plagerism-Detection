#include <stdio.h>
int daj_prost() {
int j=2,broj=0;
static int i=1;
do{i++;
for(j=2;j<=i;){
if(i==j){
broj=i;
break;}
else if(i%j==0){
break;}
else if(i%j!=0){
j++;}}}while(broj!=i);
return broj;}

int main()
{
int suma=0;
int pb;
int A,B,m;

printf("Unesite brojeve A i B: ");
scanf("%d %d",&A ,&B);
while(A<=0 /*|| B<=0*/ || A>=B){
if(A<=0){
 printf("A nije prirodan broj.\nUnesite brojeve A i B: ");}
/*else if(B<=0){
 printf("B nije prirodan broj.\nUnesite brojeve A i B: ");}*/
else if(A>=B){
 printf("A nije manje od B.\nUnesite brojeve A i B: ");}
 scanf("%d %d", &A , &B);}
for(m=0;m<B;m++)
{ pb=daj_prost();
if(pb>A && pb<B){ 
 suma=suma+pb;}}
/*while(pb<B){
 pb=daj_prost();
if(pb>A && pb<B){
 suma=suma+pb;}}*/
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

    return 0;
}