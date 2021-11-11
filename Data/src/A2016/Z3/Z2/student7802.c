#include <stdio.h>
#include <stdlib.h>

int sum(int p){

    int suma=0,broj,zadnji_broj;
    broj=p;


    if(broj==0){
        suma=0;
    }else{
        if (broj<0) broj=abs(broj);
        while(broj!=0){
        
        zadnji_broj = (broj)%10; 
        suma = suma + zadnji_broj;
        broj=(broj)/10;
        }
    }
return suma;
}

int fibonacci(int a) {
    int prvi=0,drugi=1,sljedeci,i;
    for(i=0;i<a;i++) {
       
        sljedeci=prvi+drugi;
        prvi=drugi;
        drugi=sljedeci;
    if(sljedeci==a) {
        return 1;
    }  
    }
    return 0;
 
}

void ubaci (int* p, int n) {
	int *pok,*q,*zadnji,*reset=p;
    int i;
    
    pok=p;
    
    /* pok postavimo na vrijednost 10-og clana u nizu */
    pok=p+n-1;
    
    /* zadnji na zadnje mjesto koje smo rezervisali u memoriji za ovaj niz */
    zadnji=p+2*n-2;
    
    /* upisujemo na svkao drugo mjesto od kraja prema pocetku vrijednosti koje smo unjeli */
    for(i=0;i<n;i++){
        
        *zadnji=*pok;
        zadnji=zadnji-2;
        pok--;
    }
    
    pok=p;
    q=p;
    
    /* sad na neparna mjesta upisujemo brojeve koje smo dobili iz funkcije suma koja sumira vrijednosti svake cifre broja*/
    
    for(i=0;i<2*n;i++){ 
        q=pok-1;
        if(i%2!=0) *pok=sum(*q);
        pok++;
        }
        
}

int izbaci (int *p,int velicina) {
int i,j,niz[20],*q=p;
 
/*upisujem niz koji sam dobio iz funkcije ubaci kako bi radio sa njim u ovoj funkciji*/
 
for(i=0;i<velicina;i++) {
    niz[i]=*p;
    p++;
   
}
 
    for(i=0;i<velicina;i++) {
        
    /*svaki clan niza ove funkcije saljemo da provjerimo da li je on fibonacijev broj*/
        
    if(fibonacci(niz[i])==1) {
    
    /*ako jest izbacimo ga iz niza*/
        for(j=i;j<velicina-1;j++) {
            niz[j]=niz[j+1];
        }
        velicina--;
        i--;
 
        }
    }
    
    /*vratimo pokazivac na pocetak niza i upisemo ga u njegovu adresu na koju pokazuje p*/
    p=q;
    for(i=0;i<velicina;i++) {
        *p=niz[i];
        p++;
        
    }
   
    return velicina;
   
}


int main(){
    int k,n=10,niz[20],i;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++){
        
        scanf("%d", &niz[i]);
        
    }

    
    ubaci(niz,n);
    k=izbaci(niz,2*n);
    
    if(k==0){
        
        printf("Prazan niz");
        return 0;
        
    }
    
    printf("Modificirani niz glasi: ");
    for(i=0;i<k;i++){
        if(i==k-1) 
            printf("%d.", niz[i]);
        else
            printf("%d, ", niz[i]);
        
    }
 return 0;
 }