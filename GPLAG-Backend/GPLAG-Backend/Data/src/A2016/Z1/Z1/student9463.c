#include <stdio.h>
#define E 0.0001

int main() {
	float s1p1, s1p2, s1pr, s1dz, s1zi, s2p1, s2p2, s2pr, s2dz, s2zi, s3p1, s3p2, s3pr, s3dz, s3zi, s1zb, s2zb, s3zb, s1oc, s2oc, s3oc;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
		scanf("%f", &s1p1);
		if (s1p1<0||s1p1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
		scanf("%f", &s1p2);
		if (s1p2<0||s1p2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
		scanf("%f", &s1pr);
		if (s1pr<0||s1pr>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
		scanf("%f", &s1dz);
		if (s1dz<0||s1dz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
		scanf("%f", &s1zi);
		if (s1zi<0||s1zi>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
		scanf("%f", &s2p1);
		if (s2p1<0||s2p1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
		scanf("%f", &s2p2);
		if (s2p2<0||s2p2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
		scanf("%f", &s2pr);
		if (s2pr<0||s2pr>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
		scanf("%f", &s2dz);
		if (s2dz<0||s2dz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
		scanf("%f", &s2zi);
		if (s2zi<0||s2zi>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
		scanf("%f", &s3p1);
		if (s3p1<0||s3p1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
		scanf("%f", &s3p2);
		if (s3p2<0||s3p2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
		scanf("%f", &s3pr);
		if (s3pr<0||s3pr>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
		scanf("%f", &s3dz);
		if (s3dz<0||s3dz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
		scanf("%f", &s3zi);
		if (s3zi<0||s3zi>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	s1zb = s1p1 + s1p2 + s1dz + s1pr + s1zi;
	s2zb = s2p1 + s2p2 + s2dz + s2pr + s2zi;
	s3zb = s3p1 + s3p2 + s3dz + s3pr + s3zi;
	
	
				 if(s1zb>=55 && s1zb<65){
				s1oc = 6;
			}
			else if(s1zb>=65 && s1zb<75){
				s1oc = 7;
			}
			else if(s1zb>=75 && s1zb<85){
				s1oc = 8;
			}
			else if(s1zb>=85 && s1zb<92){
				s1oc = 9;
			}
			else if(s1zb>=92 && s1zb<=100){
				s1oc = 10;
			}
			else{
				s1oc = 1;
			}
	
				 if(s2zb>=55 && s2zb<65){
				s2oc = 6;
			}
			else if(s2zb>=65 && s2zb<75){
				s2oc = 7;
			}
			else if(s2zb>=75 && s2zb<85){
				s2oc = 8;
			}
			else if(s2zb>=85 && s2zb<92){
				s2oc = 9;
			}
			else if(s2zb>=92 && s2zb<=100){
				s2oc = 10;
			}
			else{
				s2oc = 1;
			}
	
				 if(s3zb>=55 && s3zb<65){
				s3oc = 6;
			}
			else if(s3zb>=65 && s3zb<75){
				s3oc = 7;
			}
			else if(s3zb>=75 && s3zb<85){
				s3oc = 8;
			}
			else if(s3zb>=85 && s3zb<92){
				s3oc = 9;
			}
			else if(s3zb>=92 && s3zb<=100){
				s3oc = 10;
			}
			else{
				s3oc = 1;
			}
			
			 	 if((s1zb+E)<55 && (s2zb+E)<55 && (s3zb+E)<55){
			 		printf("Nijedan student nije polozio.\n");
			 }
			else if((s1zb+E)>=55 && (s2zb+E)>=55 && (s3zb+E)>=55){
					printf("Sva tri studenta su polozila.\n");
			}
			else if((s1zb+E)>=55 && (s2zb+E)<55 && (s3zb+E)<55){
					printf("Jedan student je polozio.\n");
			}
			else if((s1zb+E)<55 && (s2zb+E)>=55 && (s3zb+E)<55){
					printf("Jedan student je polozio.\n");
			}
			else if((s1zb+E)<55 && (s2zb+E)<55 && (s3zb+E)>=55){
					printf("Jedan student je polozio.\n");
			}
			else {
				printf("Dva studenta su polozila.");
			}
		if((s1zb+E)>=55 && (s2zb+E)>=55 && (s3zb+E)>=55){
				 if ((s1oc==s2oc)&&(s2oc==s3oc)&&(s3oc==s1oc)){
				printf("Sva tri studenta imaju istu ocjenu.");	
			}
			else if((s1oc!=s2oc)&&(s2oc!=s3oc)&&(s3oc!=s1oc)){
				printf("Svaki student ima razlicitu ocjenu.");
			}
			else {
				printf("Dva od tri studenta imaju istu ocjenu.");
			}
		}
}