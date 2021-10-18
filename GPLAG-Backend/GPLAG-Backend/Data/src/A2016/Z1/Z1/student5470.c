#include <stdio.h>
int main() {
	double bod1t, bod2t, bodpt, bodzt, bodzit,bod1b, bod2b, bodpb, bodzb, bodzib,bod1m, bod2m, bodpm, bodzm, bodzim,st, sb,sm;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bod1t);
	if (bod1t<0 || bod1t>20)
	{printf("Neispravan broj bodova"); return 0;}
	else
	printf("II parcijalni ispit: ");
	scanf("%lf", &bod2t);
	if (bod2t<0 || bod2t>20)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Prisustvo: ");
	scanf("%lf", &bodpt);
	if (bodpt<0 || bodpt>10)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Zadace: ");	
	scanf("%lf", &bodzt);
	if (bodzt<0 || bodzt>10)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Zavrsni ispit: ");
	scanf("%lf", &bodzit);
	if (bodzit<0 || bodzit>40)
{	printf("Neispravan broj bodova"); return 0;}
	else
	st=(bod1t+bod2t+bodpt+bodzt+bodzit);
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bod1b);
	if (bod1b<0 || bod1b>20)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("II parcijalni ispit: ");
	scanf("%lf", &bod2b);
	if (bod2b<0 || bod2b>20)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Prisustvo: ");
	scanf("%lf", &bodpb);
	if (bodpb<0 || bodpb>10)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Zadace: ");	
	scanf("%lf", &bodzb);
	if (bodzb<0 || bodzb>10)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Zavrsni ispit: ");
	scanf("%lf", &bodzib);
	if (bodzib<0 || bodzib>40)
{	printf("Neispravan broj bodova"); return 0;}
	else
sb=(bod1b+bod2b+bodpb+bodzb+bodzib);
	
		printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bod1m);
	if (bod1m<0 || bod1m>20)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("II parcijalni ispit: ");
	scanf("%lf", &bod2m);
	if (bod2m<0 || bod2m>20)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Prisustvo: ");
	scanf("%lf", &bodpm);
	if (bodpm<0 || bodpm>10)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Zadace: ");	
	scanf("%lf", &bodzm);
	if (bodzm<0 || bodzm>10)
{	printf("Neispravan broj bodova"); return 0;}
	else
	printf("Zavrsni ispit: ");
	scanf("%lf", &bodzim);
	if (bodzim<0 || bodzim>40)
{	printf("Neispravan broj bodova"); return 0;}
	else{
		sm=(bod1m+bod2m+bodpm+bodzm+bodzim);
	if(st<55 && sb<55 && sm<55) printf("Nijedan student nije polozio.");
	if((st<55 && sb<55 && sm>=55)||(st>=55 && sb<55 && sm<55)||(st<55 && sb>=55 && sm<55)) printf("Jedan student je polozio.");
	if((st<55 && sb>=55 && sm>=55)||(st>=55 && sb>=55 && sm<55)||(st>=55 && sb<55 && sm>=55)) printf("Dva studenta su polozila.");
	if(st>=55 && sb>=55 && sm>=55)
	{printf("Sva tri studenta su polozila.\n");
		if(((st>=55 && st<65)&&(sb>=55 && sb<65)&&(sm>=55 && sm<65))||
		   ((st>=65 && st<75)&&(sb>=65 && sb<75)&&(sm>=65 && sm<75))||
		   ((st>=75 && st<85)&&(sb>=75 && sb<85)&&(sm>=75 && sm<85))||
		   ((st>=85 && st<92)&&(sb>=85 && sb<92)&&(sm>=85 && sm<92))||
		   ((st>=92 && st<=100)&&(sb>=92 && sb<=100)&&(sm>=92 && sm<=100))) 
			printf("Sva tri studenta imaju istu ocjenu.");
		else	if((((st>=55 && st<65)&&(sb>=55 && sb<65))||((st>=55 && st<65)&&(sm>=55 && sm<65))||((sb>=55 && sb<65)&&(sm>=55 && sm<65)))||
			   (((st>=65 && st<75)&&(sb>=65 && sb<75))||((st>=65 && st<75)&&(sm>=65 && sm<75))||((sb>=65 && sb<75)&&(sm>=65 && sm<75)))||
			   (((st>=75 && st<85)&&(sb>=75 && sb<85))||((st>=75 && st<85)&&(sm>=75 && sm<85))||((sb>=75 && sb<85)&&(sm>=75 && sm<85)))||
			   (((st>=85 && st<92)&&(sb>=85 && sb<92))||((st>=85 && st<92)&&(sm>=85 && sm<92))||((sb>=85 && sb<92)&&(sm>=85 && sm<92)))||
			   (((st>=92 && st<=100)&&(sb>=92 && sb<=100))||((st>=92 && st<=100)&&(sm>=92 && sm<=100))||((sb>=92 && sb<=100)&&(sm>=92 && sm<=100))))
			   			printf("Dva od tri studenta imaju istu ocjenu.");
			   			else printf("Svaki student ima razlicitu ocjenu.");}

			
	}
	return 0;
}
