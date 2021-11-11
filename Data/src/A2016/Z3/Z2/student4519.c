#include <stdio.h>
int suma_cifara (int broj){
	int temp, suma = 0, zadnjaC;
	if(broj < 10) return broj;
    temp = broj;
    /*racunamo sumu cifara*/
    while(temp>0){
         zadnjaC=temp%10;
         suma+=zadnjaC;
         temp=temp/10;
    }
	return suma;
}
void ubaci (int niz[], int vel){
     int i;
     
     for (i=9; i>=0; i--){
         (niz[i+i])=(niz[i]);
     }/*ubacujemo sume cifara*/     
     for(i=1; i<vel; i+=2){
         niz[i]=suma_cifara(niz[i-1]);
     }
}
int Fibornacci(int br1){/*vraca isti broj ako je clan fib niza*/
/*vraca sljedeci clan fib niza, ako broj nije clan njega*/
    int prvi=1,drugi=1,sljedeci;
    if(br1==1) return 1;
    sljedeci=prvi+drugi;
    while(prvi+drugi<br1){
       sljedeci=prvi+drugi;
       prvi=drugi;
       drugi=sljedeci;
    }
    
    return sljedeci;  
}

int izbaci (int niz[],int vel){
    int i,j,f;
    
    int max=niz[0];
    for(i=1; i<vel; i++)
       if(niz[i]>max) max=niz[i];

    for(i=0; i<vel ; i++){
       f=Fibornacci(niz[i]);    
       if(f>max) continue; 
       if(niz[i]==f){
           for(j=i; j<vel-i; j++)
              niz[j]=niz[j+1];
           vel--;
           i--;
       }
    }
    return vel;
}

int main() {
	int i,velicina,niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	   scanf("%d ", &niz[i]); 
	
	velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<velicina; i++)
	   printf("%d \n", niz[i]);
	
	return 0;
}
