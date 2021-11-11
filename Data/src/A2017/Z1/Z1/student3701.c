#include <stdio.h>

int main() {

float novaSUMA=0,min=0;
char tarik,bojan,mirza;
char novi_red;
float suma1=0, suma2=0, suma3=0,suma4=0,suma5=0, suma6=0, suma7=0,suma8=0,suma9=0;
float a,b,c;
float pizza1=6.80, pizza2=8.00, pizza3=5.30;
float hamburger1=3.30, hamburger2=3.00, hamburger3=5.00;
float cevapi1=5.00, cevapi2=3.90, cevapi3=6.00;

printf("Unesite jelo za Tarika: ");
scanf("%c", &tarik);
scanf("%c", &novi_red);

printf("Unesite jelo za Bojana: ");
scanf("%c", &bojan);
scanf("%c", &novi_red);

printf("Unesite jelo za Mirzu: ");
scanf("%c", &mirza);
scanf("%c", &novi_red);


if(tarik=='P') 
{
    suma1+=pizza1;
    suma2+=pizza2;
    suma3+=pizza3;
}
else if(tarik=='H')
{
    suma1+=hamburger1;
    suma2+=hamburger2;
    suma3+=hamburger3;
}
else if(tarik=='C')
{
    suma1+=cevapi1;
    suma2+=cevapi2;
    suma3+=cevapi3;
}


if(bojan=='P') 
{
    suma1+=pizza1;
    suma2+=pizza2;
    suma3+=pizza3;
}
else if(bojan=='H')
{
    suma1+=hamburger1;
    suma2+=hamburger2;
    suma3+=hamburger3;
}
else if(bojan=='C')
{
    suma1+=cevapi1;
    suma2+=cevapi2;
    suma3+=cevapi3;
}

if(mirza=='P') 
{
    suma1+=pizza1;
    suma2+=pizza2;
    suma3+=pizza3;
}
else if(mirza=='H')
{
    suma1+=hamburger1;
    suma2+=hamburger2;
    suma3+=hamburger3;
}
else if(mirza=='C')
{
    suma1+=cevapi1;
    suma2+=cevapi2;
    suma3+=cevapi3;
}

if(suma1<suma2 && suma1<suma3) { min=suma1; printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%.2f KM). \n", suma1); }
else if(suma2<suma1 && suma2<suma3) {min=suma2; printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2); }
else { min=suma3; printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3); }

novaSUMA=suma1-suma1*0.1;

if(min!=suma1) {
    
    a=pizza1*0.1;
    b=hamburger1*0.1;
    c=cevapi1*0.1;
    
    
    float p,q,r;
p=hamburger1-b;
q=pizza1-a;
r=cevapi1-c;

if(suma1-p<min && suma1-p>suma1-q && suma1-p>suma1-r)
    novaSUMA=suma1-p;
else if(suma1-q<min && suma1-p<suma1-q && suma1-q>suma1-r)
    novaSUMA=suma1-q;
else if(suma1-r<min && suma1-p<suma1-r && suma1-q<suma1-r)
    novaSUMA=suma1-r;
    
    
    

if(novaSUMA<min)
    printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", novaSUMA);

}   




return 0;
}

	