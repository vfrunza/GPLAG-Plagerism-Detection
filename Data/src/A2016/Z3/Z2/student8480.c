#include <stdio.h>

int fib(int f)
{
    int prvi=1,drugi=1,sljedeci=0; //Prva dva broja u fibonacijevom nizu su uvijek 1
    
    if(f==drugi) return 1; //Provjeravamo da li je poslani broj jednak 1, jer u ispitivanju u petlji preskoci 1
    
    while(sljedeci<=f) //Pravimo sami fibonacijev niz do tog broja
    {
        sljedeci=prvi+drugi;
        
        if(sljedeci==f) return 1; //Ako je fibonacijev broj funkcija vrati 1, ako nije nastavlja traziti do zadanog broja
        
        
        prvi=drugi;
        drugi=sljedeci;
        
     }
     
    return 0; /* Ako nije nasla fibonacijev broj, tj nije prekinula rad do sada, nije bilo return-a, 
    na kraju vratimo 0 tj nije fibonacijev br */
}



int suma(int s)
{ int suma=0;

    if(s<0) s=s*(-1); //Ako posalje negativan broj, treba ga gledati kao pozitivan
    
    while(s!=0) //Sve dok je broj veci od nule, uzimamo mu cifre i sabiramo ih
    {
        suma+=s%10;
        s/=10;
        
    }
    
    
    return suma;
   
}

void ubaci(int niz[], int vel)
{ 
    int nizA[200000]; //Veliki pomocni niz
    int i;
    for(i=0;i<vel;i++) nizA[2*i]=niz[i]; //Pomocni niz popunjavamo na parnim mjestima
    
    for(i=1;i<vel*2;i+=2) //Pomocni niz na neparnim mjestima ispunjavamo sumom cifara proslog niza
    
    {
        int broj=nizA[i-1];
        if(broj<0) broj=broj*(-1);
        
        int sumacifara=suma(broj);
        
        nizA[i]=sumacifara;
        
    }
    
    
    for(i=0;i<vel*2;i++)  /*Pomocni niz prekopiramo u zadani jer funkcija ne moze vratiti pomocni niz,
    on je nastao u funkciji i tu i zavrsava */
    
    { niz[i]=nizA[i];} 
        
    
}

int izbaci (int niz[], int vel)
{
    int i, j;
    
    for(i=0;i<vel;i++) //Idemo po nizu
    {
        if(fib(niz[i])) //Ako je neki clan niza fibonacijev br treba ga izbaciti
        {
            
            for(j=i;j<vel-1;j++)    {niz[j]=niz[j+1];} /*Izbacivanje kao u predavanju, sa drugom petljom krenemo 
            i elemenat postaje onaj sljedeci */
            
           vel--;
           i--;
        }
        
    }
    
    return vel;
}


int main() {
int i;
int niz[20]; //Da je bilo niz[10] u funkciji ubaci bi se krahirao program

printf("Unesite niz od 10 brojeva: ");

for(i=0;i<10;i++)
   {
       scanf("%d", &niz[i] );
       
   }
    
    ubaci (niz,10);
    
    int novavel=izbaci(niz,20); //Spasimo u novavel koliko je elemenata ostalo
    
    printf("Modificirani niz glasi: ");
    
    for(i=0;i<novavel-1;i++)
    
    printf("%d, ", niz[i]);
    
    printf("%d.", niz[i]);
    
	return 0;
}
