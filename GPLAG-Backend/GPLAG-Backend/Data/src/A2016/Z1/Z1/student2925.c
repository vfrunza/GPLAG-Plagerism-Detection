#include <stdio.h>
int main() {
 double Tarik,Bojan,Mirza,IpiT,IpiB,IpiM,IIpiT,IIpiB,IIpiM,PT,PB,PM,ZT,ZB,ZM,ZiT,ZiB,ZiM,brojacT=0,brojacB=0,brojacM=0,ukupanbrojac;
 
 printf("Unesite broj Tarikovih bodova na prvoj parcijali: ");
 scanf("lf", &IpiT);
 if(IpiT<0 || IpiT>20) {
 	printf("Neispravan broj bodova");
 } return 0; }
 printf("Unesite broj Bojanovih bodova na prvoj parcijali: ");
 scanf("lf", &IpiB);
 if(IpiB<0 || IpiB>20) {
 	printf("Neispravan broj bodova");
} return 0; }
printf("Unesite broj Mirzinih bodova na prvoj parcijali: ");
 scanf("lf", &IpiM);
 if(IpiM<0 || IpiM>20) {
 	printf("Neispravan broj bodova");
 } return 0; }
 
 printf("Unesite broj Tarikovih bodova na drugoj parcijali: ");
 scanf("lf", &IIpiT);
 if(IIpiT<0 || IIpiT>20) {
 	printf("Neispravan broj bodova");
 } return 0; }
 printf("Unesite broj Bojanovih bodova na drugoj parcijali: ");
 scanf("lf", &IIpiB);
 if(IIpiB<0 || IIpiB>20) {
 	printf("Neispravan broj bodova");
 } return 0; }
  printf("Unesite broj Mirzinih bodova na drugoj parcijali: ");
 scanf("lf", &IIpiM);
 if(IIpiM<0 || IIpiM>20) {
 	printf("Neispravan broj bodova");
 } return 0; }
 
  printf("Unesite broj Tarikovih bodova na prisustvo: ");
 scanf("lf", &PT);
 if(PT<0 || PT>10) {
 	printf("Neispravan broj bodova");
 } return 0; }
 printf("Unesite broj Bojanovih bodova na prisustvo: ");
 scanf("lf", &PB);
 if(PB<0 || PB>10) {
 	printf("Neispravan broj bodova");
 } return 0; }
 printf("Unesite broj Mirzinih bodova na prisustvo: ");
 scanf("lf", &PM);
 if(PM<0 || PM>10) {
 	printf("Neispravan broj bodova");
 } return 0; }
 
  printf("Unesite broj Tarikovih bodova za zadace: ");
 scanf("lf", &ZT);
 if(ZT<0 || ZT>10) {
 	printf("Neispravan broj bodova");
 } return 0; }
  printf("Unesite broj Bojanovih bodova za zadace: ");
 scanf("lf", &ZB);
 if(ZB<0 || ZB>10) {
 	printf("Neispravan broj bodova");
 } return 0; }
  printf("Unesite broj Mirzinih bodova za zadace: ");
 scanf("lf", &ZM);
 if(ZM<0 || ZM>10) {
 	printf("Neispravan broj bodova");
 } return 0; }
 
   printf("Unesite broj Tarikovih bodova na zavrsnom ispitu: ");
 scanf("lf", &ZiT);
 if(ZiT<0 || ZiT>40) {
 	printf("Neispravan broj bodova");
 } return 0; }
  printf("Unesite broj Bojanovih bodova na zavrsnom ispitu: ");
 scanf("lf", &ZiB);
 if(ZiB<0 || ZiB>40) {
 	printf("Neispravan broj bodova");
 } return 0; }
  printf("Unesite broj Mirzinih bodova na zavrsnom ispitu: ");
 scanf("lf", &ZiM);
 if(ZiM<0 || ZiM>40) {
 	printf("Neispravan broj bodova");
 } return 0; }
 
 Tarik=IpiT+IIpiT+PT+ZT+ZiT;
 Bojan=IpiB+IIpiB+PB+ZB+ZiB;
 Mirza=IpiM+IIpiM+PM+ZM+ZiM;
 
if(Tarik<=55)brojacT++;
if(Bojan<=55)brojacB++;
if(Mirza<=55)brojacM++;

ukupanbrojac=brojacT+brojacB+brojacM

if(ukupanbrojac==3){
 printf("Sva tri studenta su polozila");
} else {
if(ukupanbrojac==2){
 printf("Dva studenta su položila.");
} else {
if(ukupanbrojac==1){
 printf("Jedan student je položio.");
} else {
 printf("Nijedan student nije položio.");
}
}
}
}


 