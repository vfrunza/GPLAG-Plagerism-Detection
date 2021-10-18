#include <stdio.h>

int main() {
	
	double a,b,c,d,e,UK1,UK2,UK3,y,x,v,n,m,q,w,r,t,u;
	int oc1,oc2,oc3,znak=0;
	
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &a); if (a<0 || a>20) { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf", &b); if (b<0 || b>20) { printf("Neispravan broj bodova"); return 0; }
	printf("Prisustvo: ");
	scanf("%lf", &c); if(c<0 || c>10) { printf ("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf", &d); if(d<0 || d>10) { printf ("Neispravan broj bodova"); return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf", &e); if(e<0 || e>40) { printf("Neispravan broj bodova"); return 0 ; }
	
	UK1=a+b+c+d+e;
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &y); if(y<0 || y>20) { printf("Neispravan broj bodova"); return 0 ; }
	printf("II parcijalni ispit: ");
	scanf("%lf", &x); if(x<0 || x>20) { printf("Neispravan broj bodova"); return 0 ; }
	printf("Prisustvo: ");
	scanf("%lf", &v); if(v<0 || v>10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf", &n); if(n<0 || n>10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf", &m); if(m<0 || m>40) { printf("Neispravan broj bodova"); return 0; }
	
	UK2=y+x+v+n+m;
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &q); if(q<0 || q>20) { printf("Neispravan broj bodova"); return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf", &w); if(w<0 || w>20) { printf("Neispravan broj bodova"); return 0; }
	printf("Prisustvo: ");
	scanf("%lf", &r); if(r<0 || r>10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zadace: ");
	scanf("%lf", &t); if(t<0 || t>10) { printf("Neispravan broj bodova"); return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf", &u); if(u<0 || u>40) { printf("Neispravan broj bodova"); return 0; }
	
	UK3=q+w+r+t+u;
	
	if(UK1<55) oc1=5;
	else if(UK1>=55 && UK1<65) oc1=6;
	else if(UK1>=65 && UK1<75) oc1=7;
	else if(UK1>=75 && UK1<85) oc1=8;
	else if(UK1>=85 && UK1<92) oc1=9;
	else if(UK1>=92) oc1=10;
	
	if(UK2<55) oc2=5;
	else if(UK2>=55 && UK2<65) oc2=6;
	else if(UK2>=65 && UK2<75) oc2=7;
	else if(UK2>=75 && UK2<85) oc2=8;
	else if(UK2>=85 && UK2<92) oc2=9;
	else if(UK2>=92) oc2=10;
	
	if(UK3<55) oc3=5;
	else if(UK3>=55 && UK3<65) oc3=6;
	else if(UK3>=65 && UK3<75) oc3=7;
	else if(UK3>=75 && UK3<85) oc3=8;
	else if(UK3>=85 && UK3<92) oc3=9;
	else if(UK3>=92) oc3=10;
	
	if(oc1==5 && oc2==5 && oc3==5) printf("Nijedan student nije polozio.");
	else if((oc1!=5 && oc2==5 && oc3==5) || (oc1==5 && oc2!=5 && oc3==5) || (oc1==5 && oc2==5 && oc3!=5)) printf("Jedan student je polozio.");
	else if ((oc1!=5 && oc2!=5 && oc3==5) || (oc1!=5 && oc2==5 && oc3!=5) || (oc1==5 && oc2!=5 && oc3!=5)) printf("Dva studenta su polozila.");
	
	if(oc1!=5 && oc2!=5 && oc3!=5) { printf("Sva tri studenta su polozila.\n"); znak=1; }
	
	if(oc1==oc2 && oc2==oc3 && znak==1) printf("Sva tri studenta imaju istu ocjenu.");
	else if(oc1!=oc2 && oc2!=oc3 && oc1!=oc3 &&znak==1) printf("Svaki student ima razlicitu ocjenu.");
	else if(((oc1==oc2 && oc1!=oc3) || (oc1==oc3 && oc3!=oc2) || (oc2==oc3 && oc3!=oc1)) && znak==1) printf("Dva od tri studenta imaju istu ocjenu.");
    
    
	
	return 0;
}
