#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define vel1 10
#define vel2 20

/*Funkcija za dodavanje clanova sabiranjem cifara prethodnog clana*/
void f(int *niz, int vel){
	int i,br1,br2=0,cifra;
	for(i=0; i<vel*2; i++){
		if(i%2==1){
			br1=*(niz+i-1);
			while(br1!=0){
				/*Dodavanje clanova sabiranjem cifara prethodnog clana*/ 
				cifra=br1%10;
				br2+=cifra;
				br1/=10;
			}
			br2=abs(br2);
			*(niz+i)=br2;
			br2=0;
		}
	}
}
/*Funkcija za ubacivanje u niz*/
void ubaci(int *niz, int vel){
	int i;
	for(i=vel-1; i>=0; i--){
	   /*Pomjeranje clanova niza*/
	   *(niz+2*i)=*(niz+i);
	}
	f(niz,vel);
}

/*Funkcija za izbacivanje iz niza*/
int izbaci (int *niz, int vel){
	int i,k,j,prvibr=0,drugibr=1,slijedecibr;
	i=0;
	while(i<vel){
		prvibr=0;
		drugibr=1;
		j=1;
		while(j<100000){
			if(j==1)
			slijedecibr=j;
			else {
				slijedecibr=prvibr+drugibr;
				prvibr=drugibr;
				drugibr=slijedecibr;
		    }
	    	if(slijedecibr==*(niz+i)){
	    	  k=i;
		      while(k<vel-1){
			    *(niz+k)=*(niz+k+1);
                k++;		      
		      	
		      }
	          vel--;
	          i--;
	          break;
             }
             j++;
		}
		i++;
	}	
 return vel;
}


int main() {
	int niz[20],i,m;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d", &niz[i]);
	
	/*Pozivanje f-je ubaci*/
	ubaci(niz,vel1);
	/*Pozivanje f-je izbaci*/
	m=izbaci(niz,vel2);
	/*Ispis niza*/
	printf("Modificirani niz glasi: ");
	for(i=0;i<m;i++){
		if ((m-1)>i){
			printf("%d, ", niz[i]);
		}
		else {
			printf("%d. ", niz[i]);
		}
	}
	return 0;
}
