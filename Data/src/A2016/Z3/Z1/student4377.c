#include <stdio.h>

int daj_prost()
{
    static int prost=1; /* prema preporuci profesora koristi se staticka varijabla */
    int nadjen=0, i;

    while(nadjen != 1) 
    {
        prost++;
        nadjen=1;
        for(i=2; i<prost; i++)
        {
            if(prost%i==0)
            {
                nadjen=0;
            }
        }
    }
    
    return prost;	
}

int main() 
{
    int a, b, suma=0, c=0, d=0; 

    do
    {
        printf("Unesite brojeve A i B: ");
        scanf("%d %d", &a, &b);
        
        if(a <=0)
        {
            printf("A nije prirodan broj.\n");
        }
        else if(b<=a) 
        {
            printf("A nije manje od B.\n");
        }
    } 
    while(a<=0 || b<=a);
    
    while(c <= a) 
    {    
        c = daj_prost(); 
    }
    suma = c; 
    
    if(c >= b)  /* u slucaju da nema prostih brojeva izmedju A i B */
    {
        suma = 0;
        printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
    }
    else
    {
        while(b > d) 
        {    
            d = daj_prost();
            suma += d; 
        }
    
        suma -= d;
        printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
    }
    
    return 0;
}