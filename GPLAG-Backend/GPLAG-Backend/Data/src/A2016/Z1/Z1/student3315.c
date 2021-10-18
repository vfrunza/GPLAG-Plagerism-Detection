#include <stdio.h>


int main() {
double a,b,c,d,e,f,g,h,p,j,k,r,m,n,o;
double Tk,Bn,Ma; 
printf("Unesite bodove za Tarika:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&a);
if(a<0 || a>20) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&b);
if(b<0 || b>20) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&c);
if(c<0 || c>10) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&d);
if(d<0 || d>10) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&e);
if(e<0 || e>40) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Unesite bodove za Bojana:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&f);
if(f<0 || f>20) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&g);
if(g<0 || g>20) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&h);
if(h<0 || h>10) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&p);
if(p<0 || p>10) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&j);
if(j<0 || j>40) {
    printf("Neispravan broj bodova");
    return 0;
}

printf("Unesite bodove za Mirzu:\n");
printf("I parcijalni ispit: ");
scanf("%lf",&k);
if(k<0 || k>20) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&r);
if(r<0 || r>20) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%lf",&m);
if(m<0 || m>10) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%lf",&n);
if(n<0 || n>10) {
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&o);
if(o<0 || o>40) {
    printf("Neispravan broj bodova");
    return 0;
}

    Tk=a+b+c+d+e;
if(Tk<55)
Tk=0;
if(Tk>=55 && Tk<65)
Tk=6;
if(Tk>=65 && Tk<75)
Tk=7;
if(Tk>=75 && Tk<85)
Tk=8;
if(Tk>=85 && Tk<92)
Tk=9;
if(Tk>=92 && Tk<100)
Tk=10;

    Bn=f+g+h+p+j;
if(Bn<55)
Bn=0;
if(Bn>=55 && Bn<65)
Bn=6;
if(Bn>=65 && Bn<75)
Bn=7;
if(Bn>=75 && Bn<85)
Bn=8;
if(Bn>=85 && Bn<92)
Bn=9;
if(Bn>=92 && Bn<100)
Bn=10;
    
    Ma=k+r+m+n+o;
if(Ma<55)
Ma=0;
if(Ma>=55 && Ma<65)
Ma=6;
if(Ma>=65 && Ma<75)
Ma=7;
if(Ma>=75 && Ma<85)
Ma=8;
if(Ma>=85 && Ma<92)
Ma=9;
if(Ma>=92 && Bn<100)
Ma=10;

if(Tk==0 && Bn==0 && Ma==0) {
printf("Nijedan student nije polozio.\n");
}
if((Tk==0 && Bn==0 && Ma>=6) || (Tk>=6 && Bn==0 && Ma==0) || (Tk==0 && Bn>=6 && Ma==0)){
printf("Jedan student je polozio.\n");
}
if((Tk>=6 && Bn>=6 && Ma==0) || (Tk==0 && Bn>=6 && Ma>=6) || (Tk>=6 && Bn==0 && Ma>=6)){
printf("Dva studenta su polozila.\n");
}
if(Tk!=0 && Bn!=0 && Ma!=0) 
printf("Sva tri studenta su polozila.\n");

if(Tk==Bn && Bn==Ma && Tk!=0 && Bn!=0 && Ma!=0)
printf("Sva tri studenta imaju istu ocjenu.\n");
if(((Tk==Bn && Bn!=Ma) || (Bn==Ma && Ma!=Tk) || (Tk==Ma && Ma!=Bn)) && (Tk!=0 && Bn!=0 && Ma!=0))
printf("Dva od tri studenta imaju istu ocjenu.\n");
if(Tk!=Bn && Bn!=Ma && Tk!=0 && Bn!=0 && Ma!=0)
printf("Svaki student ima razlicitu ocjenu.\n");

return 0;
}