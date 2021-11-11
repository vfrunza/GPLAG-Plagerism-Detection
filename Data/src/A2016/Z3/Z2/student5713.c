#include <stdio.h>
 int niz[400]={0};


void ubaci(int *niz, int vel){
	int p=vel;
	
	int fiksna=vel; 
	int i, suma, y, j, a, negative=0;
	
	for(i=0; i<fiksna; i++){/*ponavlja se pocetno vel puta*/

	if(*(niz+2*i)<0) negative=1;
		else negative=0;
		
		a=*(niz+2*i);/*pamtimo vr. clana niza, posto cemo ga dijeliti, da bismo dobili zbir cifara*/
		suma=0;
		
		do{
			y=*(niz+2*i)%10;
			suma+=y;
			*(niz+2*i)/=10;
		}while(*(niz+2*i)!=0);
		
		*(niz+2*i)=a;/*vracamo staru vr*/
		p++;/*povecavamo vr velicine niza za jedno mjesto*/
		for(j=p-1; j>=p+i-(fiksna-1); j--) *(niz+j)=*(niz+j-1);
		/*petlja kojom pomjeramo elemente za jedno mjesto, oslobadjamo mjesto t*/
		if(negative==1) suma=-suma;
		*(niz+2*i+1)=suma;/*u mjesto t ubacujemo sumu cifara prethodnog clana niza*/
	}
}

int izbaci(int *niz, int vel){
	int maxi; 
	int niz_fibonaci[1000]={0};
	int dalje=0, i, prvi=1, drugi=1, k=0, j;
	
			
	maxi=*niz;
	for(i=0; i<vel; i++) 
	{if(*(niz+i)>maxi) maxi=*(niz+i);}
		
	i=0;
	niz_fibonaci[i]=1;
	if(maxi>1){
		do{	
			i++;
			dalje=prvi+drugi;
			prvi=drugi;
			drugi=dalje;
		
	 niz_fibonaci[i]=dalje;	
		
	} while(niz_fibonaci[i]<maxi);
	}
	
	maxi=i;
	i=0;
	for(i=0; i<vel; i++){
		for(j=0; j<=maxi; j++){
			
			if(*(niz+i)==*(niz_fibonaci+j) ){/*memorijska greska, */
			for(k=i; k<vel-1; k++) *(niz+k)=*(niz+k+1);
				vel--; i--; break;
			}
			
			
			
		}if(vel==0)  break;
	}
	 
	 return vel;
		}
	





int main() {
	int i,c;
	
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	scanf("%d", &niz[i]);

		
	ubaci(niz, 10);
	c=izbaci(niz, 20);
	if(c==0) {printf("Prazan niz."); return 0;}
	printf("Modificirani niz glasi: ");
	for(i=0; i<c; i++){
		if(i!=c-1)printf("%d, ", niz[i]);
		else printf("%d.", niz[i]);
		
	}
	
	return 0;
}
