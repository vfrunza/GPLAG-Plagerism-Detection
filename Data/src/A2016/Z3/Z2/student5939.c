#include <stdio.h>
#include <math.h>

int suma (int broj) {
	
	int broj_1,suma_1=0;
	
	while (broj!=0) {
		broj_1=broj%10;
		suma_1=suma_1+broj_1;
		broj=broj/10;
	}
	return suma_1;
} 

void pomjeri(int niz[], int velicina) {
	int indeks = 0;
	int i;
	
	for (i=0; i < velicina; i++) {
		if (niz[i] != 0) {
			niz[indeks] = niz[i];
			indeks++;
		}
	}
	
	while (indeks < velicina) {
		niz [indeks] = 0;
		indeks ++;
	}
	
}
void ubaci (int niz[], int velicina) {
	
	int i;

	for (i=velicina; i >= 2; i--) {
		if (niz[i] > 0) {
		    niz[2 * i] = niz[i];
		    niz[2 * i + 1] = suma(niz[i]);
		}
    }
    
    if (niz[1] > 0) {
        niz[2] = niz[1];
        niz[3] = suma(niz[1]);
    }
    
    if (niz[0] > 0)
        niz[1]=suma(niz[0]);
        
       /*
    // printf ("Modificirani niz glasi: ");
	for (i=0; i<velicina; i++) {
	    	
	    if (i != velicina - 1)
	       printf("%d, ", niz[i]);
	    else 
	       printf("%d.", niz[i]);
	    
    }
    */
    
    
    
}
	
long long potpun_kv (long long broj) {
	long long korijen=sqrt(broj);
	if (korijen*korijen==broj) {
		return 1;
	}
	else {return 0;}
}

int je_li_fib (long long broj) {
	long long uslov_1=potpun_kv (5*broj*broj+4);
	long long uslov_2=potpun_kv (5*broj*broj-4);
	if (broj<0) {
		return 0;
	}
	
	if (uslov_1==1 || uslov_2==1) {
		return 1;
	}
	else {return 0;}
	
	
}

// vraca broj clanova izbacenih iz niza
int izbaci (int niz[], int velicina) {

	int i,brojac=0;
	for (i=0; i<velicina; i++) {
		if (je_li_fib(niz[i])) {
			niz[i]=0;
		}
	}
	
	pomjeri(niz,velicina);
	
	for (i=0; i<velicina; i++) {
		if (niz[i] != 0)
		    brojac++; 
	}
	
	return brojac;

}

int main() {

	int niz[20]={0},i;
	// int niz_1[20];
	printf("Unesite niz od 10 brojeva: ");
		
		for (i=0; i<10; i++) {
			scanf ("%d", &niz[i]);
		}
		
		ubaci (niz,10);
	
	
	printf ("Modificirani niz glasi: ");
	
	for (i=0; i<20; i++) {
	    	
	    if (niz[i] != 0 && i+1 < 20 && niz[i+1] != 0)
	       printf("%d, ", niz[i]);
	    else {
	       printf("%d.", niz[i]);
	       break;
	    }
	    
    }
    
	   
	    
	    int rezltat = izbaci(niz,10);
	    
	    //printf("Preostalo: %d\n", rezltat);
//printf ("%lli", je_li_fib(-75025));
	
return 0;
}
