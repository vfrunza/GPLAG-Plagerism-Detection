#include <stdio.h>
int main() {
double c,p1=6.00,p2=8.00,p3=5.30,h1=3.30,h2=3.00,h3=5.00,c1=5.00,c2=3.90,c3=6.00,p,k,t,l;
char T,B,M,novi_red;
printf("unesite jelo za Tarika: ");
scanf("%c",&T);
scanf("%c",&novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c",&B);
scanf("%c",&novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c",&M);
scanf("%c",&novi_red);
if(T=="H"&& B=="H" && M=="H"){
k=3*h1;
t=3*h2;
l=3*h3;
c=(h1*10)/100;
p=k-3*c;
}
else if (T=="C" && B=="C" && M=="C"){
k=3*c1;
t=3*c2;
l=3*c3;
c=(c1*10)/100;
p=k-3*c;
}
else if((T=="H" && B=="H" && M=="C")||(T=="H" && B=="C" && M=="H")||(T=="C" && B=="H" && M=="H")){
k=2*h1+c1;
t=2*h2+c2;
l=2*h3+c3;
if(h1<c1)
c=(c1*10)/100;
else 
c=2*(h1*10)/100;
p=k*c;
}
else if((T=="H" && B=="H" && M=="P")||(T=="H" && B=="P" && M=="M")||(T=="P" && B=="H" && M=="H")){
k=2*h1+p1;
t=2*h2+p2;
l=3*h3+p3;
if(h1<p1)
c=(p1*10)/100;
else
c=2*(h1*10)/100;
p=k-c;
}
else if((T=="C" && B=="C" && M=="H")||(T=="C" && B=="H" && M=="C")||(T=="H" && B=="C" && M=="C")){
k=2*c1+h1;
t=2*c2+h2;
l=2*c3+h3;
if(c1<h1)
c=(h1*10)/100;
else
c=2*(c1*10)/100;
p=k-c;
}
else if((T=="C" && B=="C" && M=="P")||(T=="C" && B=="P" && M=="C")||(T=="P" && B=="C" && M=="C")){
k=2*c1+p1;
t=2*c2+p2;
l=2*c3+p3;
if(c1<p1)
c=(p1*10)/100;
else
c=2*(c1*10)/100;
p=k-c;
}
else if((T=="P" && B=="P" && M=="H")||(T=="P" && B=="H" && M=="P")||(T=="H" && B=="P" && M=="P")){
k=2*p1+h1;
t=2*p2+h2;
l=2*p3+h3;
if(p1<h1)
c=(c1*10)/100;
else
c=2*(p1*10)/100;
p=k-c;
}
else if((T=="P" && B=="P" && M=="C")||(T=="P" && B=="C" && M=="P")||(T=="C" && B=="P" && M=="P")){
k=2*p1+c1;
t=2*p2+c2;
l=2*p3+c3;
if(p1<c1)
c=(c1*10)/100;
else
c=2*(p1*10)/100;
p=k-c;
}
else if((T=="P" && B=="H" && M=="C")||(T=="C" && B=="P" && M=="H")||(T=="H" && B=="P" && M=="C")||(T=="C" && B=="H" && M=="P")||(T=="H" && B=="C" && M=="P")||(T=="P" && B=="C" && M=="H")){
k=c1+h1+p1;
t=c2+h2+p2;
l=c3+h3+p3;
if(p1>h1 && p1>c1)
c=(p1*10)/100;
else if(h1>p1 && h1>c1)
c=(h1*10)/100;
else
c=(c1*10)/100;
p=k-c;
}
if(k<t && k<l)
printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",k);
else if(t<k && t<l){
printf("Najjeftiniji je Fst-food \"Trovac\" (%.2f KM),\n",t);
if(p<t)
printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM),\n",p);
}
else{
printf("Najjaeftiniji je Bistro \"Lorelei\" (%.2f KM),\n",l);
if(p<l)
printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM),\n",p);
}
return 0;
}
