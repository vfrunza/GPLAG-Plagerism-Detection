#include <stdio.h>


int prost(int n) /* povratna vrijednost ove funkcije jeste logicka vrijednost */
{
    int i, b=0;

   	for (i=2; i<n; i++) /*petlja koja provjerava da li eprost broj */
   	{
   		if(n%i==0)
   		{
   			b=1;
   			break;
   		}
   	}
    if (b==1)
    return 0;
    else 
    return 1;
}

int daj_prost () /* Povratna vrijednost ove funkcije jeste prost broj */
{
    static int c=2;  /* upotrebljavamo staticku promjenjljivu da bi svakim pozivom funkcije dobili naredni prost broj*/
    while(1) /* upotrebom while petlje omogucavamo da ispunjenje uslova znaci kraj funkcije */
    {
        if(prost(c)) 
        {
            c++;
            return (c-1);
        }
        c++;
    }
}

int main() {
    int a,b, suma=0, prostbroj;
    printf("Unesite brojeve A i B: ");
    
    do
    {
        scanf("%d%d",&a,&b);
        if(a<1){
            printf("A nije prirodan broj.\nUnesite brojeve A i B: ");
        }
        if(a>=b){
            printf("A nije manje od B. \nUnesite brojeve A i B: ");
        }
           
        
    }
    while(a<1 || b<=a);
    
    while(1)/* prekid petlje znaci pronalazak onog prostog broja koji je veci od b*/
    {
        prostbroj=daj_prost(); /*pozivanje funkcije koja salje proste brojeve*/
        if(prostbroj<b && prostbroj>a)
        suma=suma+prostbroj;
        if(prostbroj>=b) break;
    } 
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
    
    
   
    return 0;
    
    
	
	
}
