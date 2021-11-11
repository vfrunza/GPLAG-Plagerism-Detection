#include <stdio.h>

int daj_prost() {
    static int d=1;
	int prost,j;
/*logicku varijablu prost postavljam na vrijednost 1(istina)*/    
    prost=1;
/* provjeravanje da li je broj prost*/
do
{ d++;
for (j=2;j<d;j++)
{
   
    if (d%j==0)
    { prost=0; break;}
    else if (d%j!=0) prost=1; }
/* ako je ostatak pri dijeljenju razlicit od 0 taj broj je prost i to je povratna vrijednost*/
if(prost==1) {return d;}}while (d<30000000000);
    
}

int main() {
	
int y,a,b,suma;
printf ("Unesite brojeve A i B: ");

do {
scanf ("%d %d", &a, &b);

/*osiguravanje pravilnog unosa*/
if (a>=b) {
printf ("A nije manje od B.\n");
printf ("Unesite brojeve A i B: ");
} 

if (a<=0){
printf ("A nije prirodan broj.\n");
printf ("Unesite brojeve A i B: ");
} 

} while(a<=0 || b<=0 || a>=b);


suma=0;
y=daj_prost(); 

/*izracunavanje sume*/
do{
     
y=daj_prost();
if (a<y && b>y)
suma+=y;

}while (y<b);

printf ("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}
