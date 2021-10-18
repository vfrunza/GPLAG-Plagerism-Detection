#include <stdio.h>
#define P1 6.80
#define P2 8.00
#define P3 5.30 
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
char T, B, M, novi_red;
double D1=0, D2=0, D3=0, D4, min, max;
int h=0, p=0, c=0;
printf("Unesite jelo za Tarika: "); 
scanf ("%c", &T);
scanf("%c", &novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c", &B); 
scanf("%c", &novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c", &M);
scanf("%c", &novi_red);

/*tarik hamburger*/
if(T=='H')
{
    
    D1=D1+H1;
    D2=D2+H2;
    D3=D3+H3;
    h++;
    }
/*tarik pizza*/
else if(T=='P')
{
    D1=D1+P1;
    D2=D2+P2;
    D3=D3+P3;
    p++;
}
/*tarik cevapi*/
else if(T=='C')
{
    D1=D1+C1;
    D2=D2+C2;
    D3=D3+C3;
    c++;
}

/*bojan hamburher*/
if(B=='H')
{
    D1=D1+H1;
    D2=D2+H2;
    D3=D3+H3;
    h++;
}
/*bojan pizza*/
else if(B=='P')
{
    D1=D1+P1;
    D2=D2+P2;
    D3=D3+P3;
    p++;
}
/*bojan cevapi*/
else if(B=='C')
{
    D1=D1+C1;
    D2=D2+C2;
    D3=D3+C3;
    c++;
}

/*mirza hamburger*/
if(M=='H')
{
    D1=D1+H1;
    D2=D2+H2;
    D3=D3+H3;
    h++;
}
/*mirza pizza*/
if(M=='P')
{
    D1=D1+P1;
    D2=D2+P2;
    D3=D3+P3;
    p++;
}
/*mirza cevapi*/
if(M=='C')
{
    D1=D1+C1;
    D2=D2+C2;
    D3=D3+C3;
    c++;
}

/*NAJNIZA CIJENA*/
min=D1;
if(D2<min)
{
  min=D2;    
}
if(D3<min)
{
  min=D3;
}
/*najvise stavki*/
max=h*H1;
if(max<p*P1)
{
    max=p*P1;
}
if(max<c*C1)
{
    max=c*C1;
}

/*popust*/
D4=D1-0.1*max;

/*uslovi za ispisivanje*/
if(D1<D2 && D1<D3)
{
    printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", D1);
}
else if(D2<D1 && D2<D3)
{
    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", D2);
    if(D4<D2)
    {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", D4);
    }
}

else if(D3<D1 && D3<D2)
{
    printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", D3);
    if(D4<D3)
    {
        printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", D4);
    }
}

return 0;
}




