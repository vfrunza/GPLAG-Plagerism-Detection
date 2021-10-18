#include <stdio.h>

int main() 
{
 int  ocjenaTarik,
      ocjenaBojan,
      ocjenaMirza;

 float tarikBodovi, 
       bojanBodovi,
       mirzaBodovi,
       PTI,
       PTII,
       PT,
       ZIT,
       DZT,
       PBI,
       PBII,
       PB,
       ZIB,
       DZB,
       PMI,
       PMII,
       PM,
       ZIM,
       DZM;
 printf ("Unesite bodove za Tarika:\n");
 
 printf ("I parcijalni ispit: ");
 scanf ("%f", &PTI);
 
 if(PTI<0 || PTI>20)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("II parcijalni ispit: ");
  scanf ("%f", &PTII);
 if(PTII<0 || PTII>20)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("Prisustvo: ");
  scanf ("%f", &PT);
 if(PT<0 || PT>10)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("Zadace: ");
  scanf ("%f", &DZT);
 if(DZT<0 || DZT>10)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
 printf ("Zavrsni ispit: ");
 scanf ("%f", &ZIT);
 if(ZIT<0 || ZIT>40)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
 
 
  printf ("Unesite bodove za Bojana:\n");
 
 printf ("I parcijalni ispit: ");
 scanf ("%f", &PBI);
 
 if(PBI<0 || PBI>20)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("II parcijalni ispit: ");
  scanf ("%f", &PBII);
 if(PBII<0 || PBII>20)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("Prisustvo: ");
  scanf ("%f", &PB);
 if(PB<0 || PB>10)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("Zadace: ");
  scanf ("%f", &DZB);
 if(DZB<0 || DZB>10)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
 printf ("Zavrsni ispit: ");
 scanf ("%f", &ZIB);
 if(ZIB<0 || ZIB>40)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
 
 
 
  printf ("Unesite bodove za Mirzu:\n");
 
 printf ("I parcijalni ispit: ");
 scanf ("%f", &PMI);
 
 if(PMI<0 || PMI>20)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("II parcijalni ispit: ");
  scanf ("%f", &PMII);
 if(PTII<0 || PTII>20)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("Prisustvo: ");
  scanf ("%f", &PM);
 if(PM<0 || PM>10)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
  printf ("Zadace: ");
  scanf ("%f", &DZM);
 if(DZM<0 || DZM>10)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
 printf ("Zavrsni ispit: ");
 scanf ("%f", &ZIM);
 if(ZIM<0 || ZIM>40)
 {
  printf("Neispravan broj bodova");
  return 0;
 }
 
 tarikBodovi=PTI+PTII+PT+ZIT+DZT;
 bojanBodovi=PBI+PBII+PB+ZIB+DZB;
 mirzaBodovi=PMI+PMII+PM+ZIM+DZM;
   
 if(tarikBodovi>=0 && tarikBodovi<55)
 {
  ocjenaTarik=5;
 }
 else if(tarikBodovi>=55 && tarikBodovi<65)
 {
  ocjenaTarik=6;
 }
 else if (tarikBodovi>=65 && tarikBodovi<75)
 {
  ocjenaTarik=7;
 }
 else if(tarikBodovi>=75 && tarikBodovi<85)
 {
  ocjenaTarik=8;
 }
 else if(tarikBodovi>=85 && tarikBodovi<92)
 {
  ocjenaTarik=9;
 }
 else if(tarikBodovi>=92 && tarikBodovi<100)
 {
  ocjenaTarik=10;
 }


if(bojanBodovi>=0 && bojanBodovi<55)
 {
  ocjenaBojan=5;
 }
 else if(bojanBodovi>=55 && bojanBodovi<65)
 {
  ocjenaBojan=6;
 }
 else if (bojanBodovi>=65 && bojanBodovi<75)
 {
  ocjenaBojan=7;
 }
 else if(bojanBodovi>=75 && bojanBodovi<85)
 {
  ocjenaBojan=8;
 }
 else if(bojanBodovi>=85 && bojanBodovi<92)
 {
  ocjenaBojan=9;
 }
 else if(bojanBodovi>=92 && bojanBodovi<100)
 {
  ocjenaBojan=10;
 }



if(mirzaBodovi>=0 && mirzaBodovi<55)
 {
  ocjenaMirza=5;
 }
 else if(mirzaBodovi>=55 && mirzaBodovi<65)
 {
  ocjenaMirza=6;
 }
 else if (mirzaBodovi>=65 && mirzaBodovi<75)
 {
  ocjenaMirza=7;
 }
 else if(mirzaBodovi>=75 && mirzaBodovi<85)
 {
  ocjenaMirza=8;
 }
 else if(mirzaBodovi>=85 && mirzaBodovi<92)
 {
  ocjenaMirza=9;
 }
 else if(mirzaBodovi>=92 && mirzaBodovi<100)
 {
  ocjenaMirza=10;
 }





 if(ocjenaTarik==5 && ocjenaMirza==5 && ocjenaBojan==5)
 {
  printf("Nijedan student nije polozio.\n");
  return 0;
 }

 if((ocjenaTarik!=5 &&  ocjenaMirza==5 && ocjenaBojan==5) || (ocjenaTarik==5 &&  ocjenaMirza!=5 && ocjenaBojan==5))
 {
  printf("Jedan student je polozio.\n");
  return 0;
  }
  if(ocjenaTarik==5 &&  ocjenaMirza==5 && ocjenaBojan!=5)
  {
   printf("Jedan student je položio.\n");
   return 0;
  }
  if(ocjenaTarik!=5 &&  ocjenaMirza!=5 && ocjenaBojan!=5)
  {
   printf("Sva tri studenta su polozila.\n");
  }
   if(ocjenaMirza==ocjenaTarik && ocjenaMirza==ocjenaBojan && ocjenaBojan==ocjenaTarik)
   {
    printf ("Sva tri studenta imaju istu ocjenu.\n");
   }
    
   if(ocjenaTarik!=ocjenaMirza&& ocjenaMirza!=ocjenaBojan && ocjenaTarik!=ocjenaBojan && ocjenaTarik!=5 && ocjenaMirza!=5)
   {
    printf("Svaki student ima razlicitu ocjenu.\n");
   }
      
   if(ocjenaTarik!=5 && ocjenaBojan!=5 && ocjenaMirza==5)
   {
    printf("Dva studenta su polozila.\n");
   }
   if(ocjenaMirza!=5 && ocjenaBojan!=5 && ocjenaTarik==5)
   {
    printf("Dva studenta su polozila.\n");
   }
   if(ocjenaTarik!=5 && ocjenaBojan==5 && ocjenaMirza!=5)
   {
    printf("Dva studenta su polozila.\n");
   }
   if(ocjenaTarik==ocjenaMirza && ocjenaBojan!=ocjenaTarik)
  {
   printf("Dva od tri studenta imaju istu ocjenu.\n");
  }
  if(ocjenaTarik==ocjenaBojan && ocjenaTarik!=ocjenaMirza)
  {
   printf("Dva od tri studenta imaju istu ocjenu.\n");
  }
  if(ocjenaBojan==ocjenaMirza)
  {
   printf("Dva od tri studenta imaju istu ocjenu.\n");
  }


  
  return 0;
   }