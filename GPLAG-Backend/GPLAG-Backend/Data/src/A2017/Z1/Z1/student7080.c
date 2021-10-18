#include <stdio.h>

int main() { 
	double a,b,c,d,e,f,g,h,j,k,i,o,q,r,z,Tarikocjene,Bojanocjene,Mirzaocjene;

	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&a);
		if(a>20 || a<0){
		printf("Neispravan broj bodova");
		return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf",&b);
		if(b>20 || b<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf",&c);
		if(c>10 || c<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Zadace: ");
	scanf("%lf",&d);
	if(d>10 || d<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf",&e);
		if(e>40 || e<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	
		
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&f);
		if(f>20 || f<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf",&g);
		if(g>20 || g<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf",&h);
	if(h>10 || h<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Zadace: ");
	scanf("%lf",&j);
		if(j>10 || j<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf",&k);
	 	if(k>40 || k<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&i);
		if(j>10 || j<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf",&o);
		if(o>20 || o<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf",&q);
	if(q>10 || q<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Zadace: ");
	scanf("%lf",&r);
		if(r>10 || r<0){
	printf("Neispravan broj bodova");
		return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf",&z);
	if(z>40 || z<0){
		printf("Neispravan broj bodova");
	return 0;	}

   Tarikocjene=a+b+c+d+e;
   Bojanocjene=f+g+h+j+k;
   Mirzaocjene=i+o+q+r+z;
	 if (Tarikocjene<55 && Bojanocjene <55 && Mirzaocjene<55 )
	{
		printf("Nijedan student nije polozio.");
	}
	else if ((Tarikocjene>=55 && Bojanocjene<55 && Mirzaocjene<55) 
	|| (Tarikocjene<55 && Bojanocjene>=55 && Mirzaocjene<55) 
	|| (Tarikocjene<55 && Bojanocjene<55 && Mirzaocjene>=55))
	{
		printf("Jedan student je polozio.");
	}
		else if ((Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene<55) || 
		(Tarikocjene<55 && Bojanocjene>=55 && Mirzaocjene>=55) || 
		(Tarikocjene>=55 && Bojanocjene<55 && Mirzaocjene>=55))
	{
		printf("Dva studenta su polozila.");
	}
	else if ((Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55) || (Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55) ||
	(Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55))
	{
		printf("Sva tri studenta su polozila.");
	}
	
	
		if ( ((Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55) ||
		(Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55) || 
		(Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55)) 
		&& ((Tarikocjene>=55 && Tarikocjene<65) && (Bojanocjene>=55 && Bojanocjene<65) && (Mirzaocjene>=55 && Mirzaocjene<65)) 
		|| ((Tarikocjene>=65 && Tarikocjene<75) && (Bojanocjene>=65 && Bojanocjene<75) && (Mirzaocjene>=65 && Mirzaocjene<75)) || 
		((Tarikocjene>=75 && Tarikocjene<85) && (Bojanocjene>=75 && Bojanocjene<85) && (Mirzaocjene>=75 && Mirzaocjene<85)) || 
		((Tarikocjene>=85 && Tarikocjene<92) && (Bojanocjene>=85 && Bojanocjene<92) && (Mirzaocjene>=85 && Mirzaocjene<92)) || 
		((Tarikocjene>=92 && Tarikocjene<100) && (Bojanocjene>=92 && Bojanocjene<100) && (Mirzaocjene>=92 && Mirzaocjene<100)))
		{
			printf("\nSva tri studenta imaju istu ocjenu.");
		}
		
		else if (	((Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>55) || (Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55) || (Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55)) 
		&& ((Tarikocjene>=55 && Tarikocjene<65) && (Bojanocjene>=55 && Bojanocjene<65) && (Mirzaocjene>65 && Mirzaocjene<=100)) || ((Tarikocjene>=55 && Tarikocjene<65) && (Bojanocjene>65 && Bojanocjene<100) && (Mirzaocjene>=55 && Mirzaocjene<65)) || ((Tarikocjene>65 && Tarikocjene<=100) && (Bojanocjene>=55 && Bojanocjene<65) && (Mirzaocjene>=55 && Mirzaocjene<65)) || ((Tarikocjene>=65 && Tarikocjene<75) && (Bojanocjene>=65 && Bojanocjene<75) && (Mirzaocjene<65 && Mirzaocjene>75)) || ((Tarikocjene>=65 && Tarikocjene<75) && (Bojanocjene<65 && Bojanocjene>75) && (Mirzaocjene>=65 && Mirzaocjene<75)) || ((Tarikocjene<65 && Tarikocjene>75) && (Bojanocjene>=65 && Bojanocjene<75) && (Mirzaocjene>=65 && Mirzaocjene<75)) ||((Tarikocjene>=75 && Tarikocjene<85) && (Bojanocjene>=75 && Bojanocjene<85) && (Mirzaocjene<75 && Mirzaocjene>85)) || ((Tarikocjene>=75 && Tarikocjene<85) && (Bojanocjene<75 && Bojanocjene>85) && (Mirzaocjene>=75 && Mirzaocjene<85)) || ((Tarikocjene<75 && Tarikocjene>85) && (Bojanocjene>=75 && Bojanocjene<85) && (Mirzaocjene>=75 && Mirzaocjene<85)) || ((Tarikocjene>=85 && Tarikocjene<92) && (Bojanocjene>=85 && Bojanocjene<92) && (Mirzaocjene<85 && Mirzaocjene>92)) || ((Tarikocjene>=85 && Tarikocjene<92) && (Bojanocjene<85 && Bojanocjene>92) && (Mirzaocjene>=85 && Mirzaocjene<92)) || ((Tarikocjene<85 && Tarikocjene>92) && (Bojanocjene>=85 && Bojanocjene<92) && (Mirzaocjene>=85 && Mirzaocjene<92)) ||((Tarikocjene>=92 && Tarikocjene<=100) && (Bojanocjene>=92 && Bojanocjene<=100) && (Mirzaocjene<92)) || ((Tarikocjene>=92 && Tarikocjene<=100) && (Bojanocjene<92) && (Mirzaocjene>=85 && Mirzaocjene<92)) || ((Tarikocjene<92) && (Bojanocjene>=92 && Bojanocjene<=100) && (Mirzaocjene>=92 && Mirzaocjene<100)))   
	
		{
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}
		else if	((Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55) || (Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>55) || (Tarikocjene>=55 && Bojanocjene>=55 && Mirzaocjene>=55))
		{
			printf("\nSvaki student ima razlicitu ocjenu.");
		}
	
	
	
	return 0;

}