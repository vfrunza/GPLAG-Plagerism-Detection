#include <stdio.h>

int main()
{
double prvi_tarik,drugi_tarik,prisustvo_tarik,zadace_tarik,zavrsni_tarik,prvi_bojan,drugi_bojan,prisustvo_bojan,zadace_bojan,zavrsni_bojan,prvi_mirza,drugi_mirza,prisustvo_mirza,zadace_mirza,zavrsni_mirza,suma1,suma2,suma3;
int ocjena_t=0,ocjena_m=0,ocjena_b=0;
/*Unos ostvarenih bodova studenata*/
printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
scanf("%lf", &prvi_tarik);
if(prvi_tarik>20 || prvi_tarik<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &drugi_tarik);
if(drugi_tarik<0 || drugi_tarik>20){
   printf("Neispravan broj bodova") ;
   return 0;
    
}
printf("Prisustvo: ");
scanf("%lf", &prisustvo_tarik);
if(prisustvo_tarik<0 || prisustvo_tarik>10){
 printf("Neispravan broj bodova");
 return 0;
}
printf("Zadace: ");
scanf("%lf", &zadace_tarik);
if(zadace_tarik>10 || zadace_tarik<0){
 printf("Neispravan broj bodova");
 return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &zavrsni_tarik);
if(zavrsni_tarik<0 || zavrsni_tarik>40){
  printf("Neispravan broj bodova");
  return 0;
}
printf("Unesite bodove za Bojana:\n");
printf("I parcijalni ispit: ");
scanf("%lf", &prvi_bojan);
if(prvi_bojan<0 || prvi_bojan>20){
  printf("Neispravan broj bodova");
  return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &drugi_bojan);
if(drugi_bojan<0 || drugi_bojan>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf", &prisustvo_bojan);
if(prisustvo_bojan<0 || prisustvo_bojan>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf", &zadace_bojan);
if(zadace_bojan<0 || zadace_bojan>10){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &zavrsni_bojan);
if(zavrsni_bojan<0 || zavrsni_bojan>40){
    printf("Neispravan broj bodova");
    return 0;
}

printf("Unesite bodove za Mirzu:\n");
printf("I parcijalni ispit: ");
scanf("%lf", &prvi_mirza);
if(prvi_mirza<0 || prvi_mirza>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &drugi_mirza);
if(drugi_mirza<0 || drugi_mirza>20){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf", &prisustvo_mirza);
if(prisustvo_mirza>10 || prisustvo_mirza<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf", &zadace_mirza);
if(zadace_mirza>10 || zadace_mirza<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &zavrsni_mirza);
if(zavrsni_mirza<0 || zavrsni_mirza>40){
    printf("Neispravan broj bodova");
    return 0;
}
/*Racunanje ocjena prema ostvarenim bodovima*/
suma1=prvi_tarik+drugi_tarik+prisustvo_tarik+zadace_tarik+zavrsni_tarik;
if(suma1>=55 && suma1<65)
 ocjena_t=6;
else if(suma1>=65 && suma1<75)
 ocjena_t=7;
else if(suma1>=75 && suma1<85)
 ocjena_t=8;
else if(suma1>=85 && suma1<92)
 ocjena_t=9;
else if(suma1>=92 && suma1<=100)
 ocjena_t=10;
suma2=prvi_bojan+drugi_bojan+prisustvo_bojan+zadace_bojan+zavrsni_bojan;
if(suma2>=55 && suma2<65)
 ocjena_b=6;
else if(suma2>=65 && suma2<75)
 ocjena_b=7;
else if(suma2>=75 && suma2<85)
 ocjena_b=8;
else if(suma2>=85 && suma2<92)
 ocjena_b=9;
else if(suma2>=92&& suma2<=100)
 ocjena_b=10;
suma3=prvi_mirza+drugi_mirza+prisustvo_mirza+zadace_mirza+zavrsni_mirza;
if(suma3>=55 && suma3<65)
 ocjena_m=6;
else if(suma3>=65 && suma3<75)
 ocjena_m=7;
else if(suma3>=75 && suma3<85)
 ocjena_m=8;
else if(suma3>=85 && suma3<92)
 ocjena_m=9;
else if(suma3>=92 && suma3<=100)
 ocjena_m=10;
 
/*Ispis ostvarenog uspjeha studenata i uporedjivanje ocjena*/
if(suma1>=55 && suma2>=55 && suma3>=55){
  printf("Sva tri studenta su polozila.\n");
if(ocjena_t==ocjena_b && ocjena_b==ocjena_m && ocjena_m==ocjena_t)
  printf("Sva tri studenta imaju istu ocjenu.\n");
else if(ocjena_t!=ocjena_b && ocjena_b!=ocjena_m && ocjena_m!=ocjena_t)
  printf("Svaki student ima razlicitu ocjenu.\n");
else
  printf("Dva od tri studenta imaju istu ocjenu.\n");
}

else if((suma1>=55 && suma2<55 && suma3<55) || (suma1<55 && suma2>=55 && suma3<55) || (suma1<55 && suma2<55 && suma3>=55))
 printf("Jedan student je polozio.\n");
else if(suma1<55 && suma2<55 && suma3<55)
 printf("Nijedan student nije polozio.\n");
else
 printf("Dva studenta su polozila.\n");

return 0;
}













































