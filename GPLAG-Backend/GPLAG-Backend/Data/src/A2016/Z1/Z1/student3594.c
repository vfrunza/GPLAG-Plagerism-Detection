#include <stdio.h>

int main() {
	
float TarikP1, TarikP2, TarikP, TarikZ, TarikZavr, BojanP1, BojanP2, BojanZ, BojanP, BojanZavr, MirzaP1, MirzaP2, MirzaZ, MirzaP, MirzaZavr, TarikUkupno, BojanUkupno, MirzaUkupno;
float epsilon=0.000004;
int TarikOcjena=0, BojanOcjena=0, MirzaOcjena=0;

printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
scanf("%f", &TarikP1);
if(TarikP1<0.0f || TarikP1>20.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%f", &TarikP2);
if(TarikP2<0.0f || TarikP2>20.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%f", &TarikP);
if(TarikP<0.0f || TarikP>10.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f", &TarikZ);
if(TarikZ<0.0f || TarikZ>10.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%f", &TarikZavr);
if(TarikZavr<0.0f || TarikZavr>40.0f){
	printf("Neispravan broj bodova");
	return 0;
}

printf("Unesite bodove za Bojana: \n");
printf("I parcijalni ispit: ");
scanf("%f", &BojanP1);
if(BojanP1<0.0f || BojanP1>20.0f) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%f", &BojanP2);
if(BojanP2<0.0f || BojanP2>20.0f) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%f", &BojanP);
if(BojanP<0.0f || BojanP>10.0f) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f", &BojanZ);
if(BojanZ<0.0f || BojanZ>10.0f) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%f", &BojanZavr);
if(BojanZavr<0.0f || BojanZavr>40.0f) {
	printf("Neispravan broj bodova");
	return 0;
}

printf("Unesite bodove za Mirzu: \n");
printf("I parcijalni ispit: ");
scanf("%f", &MirzaP1);
if(MirzaP1<0.0f || MirzaP1>20.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%f", &MirzaP2);
if(MirzaP2<0.0f || MirzaP2>20.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%f", &MirzaP);
if(MirzaP<0.0f || MirzaP>10.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f", &MirzaZ);
if(MirzaZ<0.0f || MirzaZ>10.0f){
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%f", &MirzaZavr);
if(MirzaZavr<0.0f || MirzaZavr>40.0f){
	printf("Neispravan broj bodova");
	return 0;
}


TarikUkupno=TarikP1+TarikP2+TarikP+TarikZ+TarikZavr;
BojanUkupno=BojanP1+BojanP2+BojanP+BojanZ+BojanZavr;
MirzaUkupno=MirzaP1+MirzaP2+MirzaP+MirzaZ+MirzaZavr;


if (TarikUkupno<(55.0f-epsilon) && MirzaUkupno<(55.0f-epsilon) && BojanUkupno<(55.0f-epsilon)) {
	printf("Nijedan student nije polozio.");
}

else if ((TarikUkupno>=(55.0f-epsilon) && MirzaUkupno<55.0f && BojanUkupno<55.0f) || (TarikUkupno<55.0f && MirzaUkupno>=55.0f && BojanUkupno<55.0f) ||(TarikUkupno<55.0f && MirzaUkupno<55.0f && BojanUkupno>=55.0f)){
	printf("Jedan student je polozio.");
}
else if ((TarikUkupno>=55.0f && MirzaUkupno>55.0f && BojanUkupno<55.0f) || (TarikUkupno<55.0f && MirzaUkupno>=55.0f && BojanUkupno>=55.0f) ||(TarikUkupno>=55.0f && MirzaUkupno<55.0f && BojanUkupno>=55.0f)){
	printf("Dva studenta su polozila.");
}
else{
	printf("Sva tri studenta su polozila.\n");



if(TarikUkupno>55.0f && TarikUkupno<65.0f){
	TarikOcjena=6;
}
else if(TarikUkupno>65.0f && TarikUkupno<75.0f){
	TarikOcjena=7;
}
else if(TarikUkupno>75.0f && TarikUkupno<85.0f){
	TarikOcjena=8;
}
else if (TarikUkupno>85.0f && TarikUkupno<92.0f){
	TarikOcjena=9;
}
else{
	TarikOcjena=10;
}

if(BojanUkupno>=55.0f && BojanUkupno<65.0f){
	BojanOcjena=6;
}
else if(BojanUkupno>=65.0f && BojanUkupno<75.0f){
	BojanOcjena=7;
}
else if(BojanUkupno>=75.0f && BojanUkupno<85.0f){
	BojanOcjena=8;
}
else if (BojanUkupno>=85.0f && BojanUkupno<92.0f){
	BojanOcjena=9;
}
else{
	BojanOcjena=10;
}

if(MirzaUkupno>=55.0f && MirzaUkupno<65.0f){
	MirzaOcjena=6;
}
else if(MirzaUkupno>=65.0f && MirzaUkupno<75.0f){
	MirzaOcjena=7;
}
else if(MirzaUkupno>=75.0f && MirzaUkupno<85.0f){
	MirzaOcjena=8;
}
else if (MirzaUkupno>=85.0f && MirzaUkupno<92.0f){
	MirzaOcjena=9;
}
else{
	MirzaOcjena=10;
}

if(TarikOcjena==MirzaOcjena && MirzaOcjena==BojanOcjena){
	printf("Sva tri studenta imaju istu ocjenu.");
}
else if((TarikOcjena!=MirzaOcjena && MirzaOcjena==BojanOcjena) || (TarikOcjena==MirzaOcjena && MirzaOcjena!=BojanOcjena) || (TarikOcjena==BojanOcjena && TarikOcjena!=MirzaOcjena)) {
	printf("Dva od tri studenta imaju istu ocjenu.");
}
else{
	printf("Svaki student ima razlicitu ocjenu.");
}

}
	return 0;
}
