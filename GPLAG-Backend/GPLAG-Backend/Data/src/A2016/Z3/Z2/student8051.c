#include <stdio.h>
#include<stdlib.h>


int zbir(int k){
    //Ova funkcija ustvari uzima vrijednost clana pocetnog niza i sabira mu cifre. 
    //K je ustvari varijabla koja ima vrijednost nekog clana u nizu.
    int suma=0;
    while(k>0){
        suma+=k%10;
        k/=10;
    }
    return suma;
}


void ubaci(int niz[],int vel){
    int *p,*q;
    int i=2*vel;
    for(i=vel-1;i>=0;i--)
    {
        //Pokazivaci p i q su tu da uduplaju niz, odnosno da naprave slobodno prostora iza clanova niza.
        p=niz+i*2;
        q=niz+i;
        *p=*q;
    }
    int k;
    for(i=0;i<2*vel;i+=2)
    {
        p=niz+i;
        q=p+1;
        k=abs(*p);
        //Pokazivac p pokazuje na clanove niza, q pokazuje na "slobodan" prostor. 
        //k je varijabla koja ima apsolutnu vrijednost od clanova niza.
        *q=zbir(k);
        //q ustvari poprima vrijednost zbira cifara. 
    }
    
}

int najveci(int niz[],int vel){
    int maxi=niz[0],i=0;
    //Ova funkcija odredjuje najveci element u nizu.
    for(i=0;i<vel;i++)
        if(maxi<niz[i])
            maxi=niz[i];
    
    return maxi;
}

int izbaci(int niz[],int vel){
    int fib[1000]={0};
    int m,brc=2,i,j=0,p;
    m=najveci(niz,vel);
    // m  je varijabla koja govori koji je najveci broj u nizu niz[]. Ovo sam koristio kako ne bi bespotrebno opteretio program, odnosno da 
    // ne trazi prvih 1000 clanova fibonacijevog niza, vec je dovoljno da najveci fibonacijev broj bude jednak najvecem clanu, ili zadnjem fibonacijevom
    // broju a da nije veci od najveceg clana u nizu niz[].
    fib[0]=1;
    fib[1]=1;
    
    for(i=2;i<1000;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        //brc je brojac koji racuna koliko ima clanova u nizu fib.
        brc++;
        if(fib[i]>m)
            break;
    }
    brc--;
    
    int z;
    i=0;
    for(i=0;i<vel;i++)
    {
        for(j=1;j<brc;j++)
        {
            //Ukoliko je clan niz[i] jednak nekom fibonacijevom broju, on se izbacuje.
            if(niz[i]==fib[j])
            {
                //izbacivanje clanova iz niza, te smanjivanje velicine niza...
                for(z=i;z<vel-1;z++)
                    niz[z]=niz[z+1];
                vel--;
                i--;
                break;
            }
        }
    }
    return vel;
    
    
}


int main() {
	int a[20],i,vel2,vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	    scanf("%d",&a[i]);
	ubaci(a,vel);
	vel*=2;
	vel2=izbaci(a,vel);
	//vel2 je velicina niza nakon modifikovanja, odnosno njegova krajnja velicina.
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel2-1;i++)
	{
	    printf("%d, ",a[i]);
	}
	printf("%d. ",a[i]);
	return 0;
}