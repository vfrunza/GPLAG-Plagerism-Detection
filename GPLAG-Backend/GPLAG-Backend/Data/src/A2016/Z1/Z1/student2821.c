#include <stdio.h>
int main (){
		double a,b,c,d,f,g,h,i,j,k,l,m,n,o,p,z1,z2,z3;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&a);
	if(a>20|| a<0){
		printf("Neispravan broj bodova");
		return 0;}
	else{ 
	printf("II parcijalni ispit: ");
	scanf("%lf",&b);
	}if(b<0 || b>20){
		printf("Neispravan broj bodova");
		return 0;
	}else{
		printf("Prisustvo: ");
		scanf("%lf",&c);
	}if(c<0 || c>10){
		printf("Neispravan broj bodova");
		return 0;
	}else{
		printf("Zadace: ");
		scanf("%lf",&d);
	}if(d<0 || d>10){
		printf("Neispravan broj bodova");
		return 0; }
	else{
		printf("Zavrsni ispit: ");
		scanf("%lf",&f);
	}if(f<0 || f>40){
		printf("Neispravan broj bodova");
		return 0;
	}else {
		printf("Unesite bodove za Bojana:\n");
		printf("I parcijalni ispit: ");
	  scanf("%lf",&g);}
	if(g<0 || g>20){
		printf("Neispravan broj bodova");
		return 0;} 
	else {
		printf("II parcijalni ispit: ");
		scanf("%lf",&h);
	}if(h<0 || h>20){
		printf("Neispravan broj bodova");
		return 0; }
	else{
		printf("Prisustvo: ");
		scanf("%lf",&i);
	}if(i<0 || i>10){
		printf("Neispravan broj bodova");
		return 0; }
	else {
		printf("Zadace: ");
		scanf("%lf",&j);
	}if(j<0 || j>10){
		printf("Neispravan broj bodova");
		return 0; }
	else{
		printf("Zavrsni ispit: ");
		scanf("%lf",&k);
	}if(k<0 || k>40){
		printf("Neispravan broj bodova");
		return 0;}
	else{
		printf("Unesite bodove za Mirzu: \n");
		printf("I parcijalni ispit: ");
		scanf("%lf",&l);
	}if(l<0 || l>20){
		printf("Neispravan broj bodova");
		return 0;}
	else{
		printf("II parcijalni ispit: ");
	    scanf("%lf",&m);}
	if(m<0 || m>20){
		printf("Neispravan broj bodova");
		return 0; }
	else{
		printf("Prisustvo: ");
		scanf("%lf",&n);
	}if(n<0 || n>10){
		printf("Neispravan broj bodova");
		return 0; }
	else {
		printf("Zadace: ");
		scanf("%lf",&o);
		}
		if(o<0 || o>10){
		printf("Neispravan broj bodova");
		return 0;}
	else{
		printf("Zavrsni ispit: ");
		scanf("%lf",&p);
		if(p<0 || p>40){
			printf("Neispravan broj bodova");
			return 0;
		}
		
	if ((a+b+c+d+f)<55 && (g+h+i+j+k)<55 && (l+m+n+o+p)<55){
		printf("Nijedan student nije polozio.\n");
	}else if ((a+b+c+d+f)>=55 && (g+h+i+j+k)>=55 && (l+m+n+o+p)<55|| (a+b+c+d+f)>=55 && (g+h+i+j+k)<55 && (l+m+n+o+p)>=55 || (a+b+c+d+f)<55 && (g+h+i+j+k)>=55 && (l+m+n+o+p)>=55) {
		printf("Dva studenta su polozila.\n");
	}else if(((a+b+c+d+f)>=55) && (g+h+i+j+k)<55 && (l+m+n+o+p)<55 || ((a+b+c+d+f)<55 && (g+h+i+j+k)>=55 && (l+m+n+o+p)<55) || ((a+b+c+d+f)<55 && (g+h+i+j+k)<55 && (l+m+n+o+p)>=55)){
		printf("Jedan student je polozio.\n");
	}else if ((a+b+c+d+f)>=55 && (g+h+i+j+k)>=55 && (l+m+n+o+p)>=55){
		printf("Sva tri studenta su polozila.\n");
	}
	if (a+b+c+d+f>=55 && a+b+c+d+f<65){
		z1=6;
		
	}else if(a+b+c+d+f>=65 && a+b+c+d+f<75){
		z1=7;
	}else if (a+b+c+d+f>=75 && a+b+c+d+f<85){
		z1=8;
	}else if(a+b+c+d+f>=85 && a+b+c+d+f<92){
		z1=9;
	}else if(a+b+c+d+f>=92 && a+b+c+d+f<=100){
		z1=10;
	}if(g+h+i+j+k>=55 && g+h+i+j+k<65){
		z2=6;
	}else if(g+h+i+j+k>=65 && g+h+i+j+k<75){
		z2=7;
	}else if(g+h+i+j+k>=75 && g+h+i+j+k<85){
		z2=8;
	}else if(g+h+i+j+k>=85 && g+h+i+j+k<92){
		z2=9;
	}else if(g+h+i+j+k>=92 && g+h+i+j+k<=100){
		z2=10;
	}if(l+m+n+o+p>=55 && l+m+n+o+p<65){
		z3=6;
	}else if(l+m+n+o+p>=65 && l+m+n+o+p<75){
		z3=7;
	}else if(l+m+n+o+p>=75 && l+m+n+o+p<85){
		z3=8;
	}else if(l+m+n+o+p>=85 && l+m+n+o+p<92){
		z3=9;
	}else if(l+m+n+o+p>=92 && l+m+n+o+p<=100){
		z3=10;
	}
	
	if((a+b+c+d+f)>=55 && (g+h+i+j+k)>=55 && (l+m+n+o+p)>=55){
	if(z1==z2 && z2==z3) {
		printf("Sva tri studenta imaju istu ocjenu.");
	}else if (z1==z2 && z1!=z3 ||z1==z3 && z1!=z2 || z2==z3 && z1!=z2){
		printf("Dva od tri studenta imaju istu ocjenu.");
	}else {
		printf("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
	}
	}
	
}
