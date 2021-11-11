#include <stdio.h>
#include <math.h>
#define eps 0.000001
int main() {
char boja;
float c=0, b=0, s=0, v=0, p=0, u, max;


printf("Unesite vozila: ");

for(;;){
    
scanf("%c", &boja);
    
if(boja=='c' || boja=='C')
c++;
else if(boja=='b' || boja=='B')
b++;
else if(boja=='s' || boja=='S')
s++;
else if(boja=='v' || boja=='V')
v++;
else if(boja=='p' || boja=='P')
p++;
else if(boja=='k' || boja=='K')
break;
else
printf("Neispravan unos \n");
}

u=c+b+s+v+p;
printf("Ukupno evidentirano %.0f vozila.", u);

if(u!=0){
   
c=(c/u)*100;
b=(b/u)*100;
s=(s/u)*100;
v=(v/u)*100;
p=(p/u)*100;

max=c; 

if(max<b)
    max=b;
if(max<s)
    max=s;
if(max<v)
    max=v;
if(max<p)
    max=p;


if(fabs(max-c)< eps)
    printf("\nNajpopularnija boja je crna (%.2f%%).", c);
else if(fabs(max-b)< eps)
    printf("\nNajpopularnija boja je bijela (%.2f%%).", b);
else if(fabs(max-s)< eps)
    printf("\nNajpopularnija boja je siva (%.2f%%).", s);
else if(fabs(max-v)< eps)
    printf("\nNajpopularnija boja je crvena (%.2f%%).", v);
else if(fabs(max-p)< eps)
    printf("\nNajpopularnija boja je plava (%.2f%%).", p);

} else{ 
    c=0;
    printf("\nNajpopularnija boja je crna (%.2f%%).", c);
}
return 0;

}
