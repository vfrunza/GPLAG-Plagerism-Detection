MATRICEE i NIZOVI

#include <stdio.h>
#define r 10 /* broj redova */
#define k 10 /* broj kolona */
int main()
{
/* int mat[r][k]; // ovako bi deklarisali cijelobrojnu matricu */
 double mat[r][k]; /* deklarišemo 2D niz (matricu) sa r - brojem redova i k - brojem kolona */
 int i, j; /* potrebni brojaci za dvostruku for petlju */
 int min, maks; /* varijabla u koju cemo smjestiti najmanji i najveci element */
 int i_min=0, i_maks=0; /* varijable za cuvanje indeksa u kojem redu se nalaze min i maks */
 int temp; /* pomocna varijabla za eventualnu zamjenu redova */
 for (i=0; i<r; i++) {
 for (j=0; j<k; j++) {
 printf("Unesite element matrice [%i][%i]: ", i+1, j+1);
 scanf("%lf", &mat[i][j]);
/* scanf("%i", &mat[i][j]); // ovako bi unijeli elemente cijelobrojne matrice (int) */
 }
 }
min=mat[0][0];
maks=mat[0][0];
 for (i=0; i<r; i++) {
 for (j=0; j<k; j++) {
 if (mat[i][j]<min) {
min=mat[i][j];
i_min=i;
 }
 if (mat[i][j]>maks) {
maks=mat[i][j];
i_maks=i;
 }
 }
 }
 if (i_min==i_maks) {
 printf("Najmanji i najveci element su u istom redu !");
 return 0;
 }
 else {
 	
 /* zamjena mjesta redova */
 for(i=0; i<r; i++) {
temp=mat[i_maks][i];
mat[i_maks][i]=mat[i_min][i];
mat[i_min][i]=temp;
 }
 printf("\n");
 
 
 /* ispisivanje 2D niza (matrice) */
 printf("Matrica sa zamjenjenim redovima: \n");
 for (i=0; i<r; i++) {
 for (j=0; j<k; j++) {
 printf("%3.f", mat[i][j]);
 }
 printf("\n");
 }
 }
 return 0;
}

SUMA ELEMENATA NA RUBU MATRICE

#include <stdio.h>
#define A 3 /* broj redova */
#define B 3 /* broj kolona */
int main()
{
double M[A][B]; /* deklarišemo 2D niz (realnu matricu) sa A - brojem redova i B - brojem
kolona */
 int i, j; /* brojaci za for petlje */
 double suma=0; /* varijabla u koju cemo smjestiti sumu svih rubnih elemenata */
 for (i=0; i<A; i++) {
 for (j=0; j<B; j++) {
 printf("Unesite element niz[%i][%i]: ", i+1, j+1);
 scanf("%lf", &M[i][j]);
 }
 }
 for (i=0; i<A; i++) {
 for (j=0; j<B; j++) {
 if ( (i==0) || (i==A-1) || (j==0) || (j==B-1) ) {
suma+=M[i][j];
 }
 }
 }
 printf("Suma elemenata na rubu unijete matrice je: %.2f", suma);
return 0;
}






#include <stdio.h>
#define BROJ_ELEMENATA 5
int main()
{
 int i;
 int a[BROJ_ELEMENATA], b[BROJ_ELEMENATA], c[BROJ_ELEMENATA];
 /* Unose elemenata niza A */
 for(i = 0; i < BROJ_ELEMENATA; i++) {
 printf("Unesite %i. element niza A: ", i + 1);
 scanf("%i", &a[i]);
 }
 /* Unose elemenata niza B */
 for(i = 0; i < BROJ_ELEMENATA; i++) {
 printf("Unesite %i. element niza B: ", i + 1);
 scanf("%i", &b[i]);
 }
 /* Racunanje elemenata niza C po zadanoj formuli*/
 for(i=0; i<BROJ_ELEMENATA; i++) {
c[i]=2*a[i]+b[i];
 }
 /* Ispis elemenata sva tri niza */
 printf("Elementi niza A su: \n");
 for(i=0; i<BROJ_ELEMENATA; i++) {
 printf("%i ", a[i]);
 }
 printf("\nElementi niza B su: \n");
 for(i=0; i<BROJ_ELEMENATA; i++) {
 printf("%i ", b[i]);
 }
 printf("\nElementi niza C su: \n");
 for(i=0; i<BROJ_ELEMENATA; i++) {
 printf("%i ", c[i]);
 }
/* U zadatku nije eksplicitno navedeno, ali unos elemenata nizova A i B, te ispis sva tri niza je
 mogao biti drugacije uradjen, konkretno mislim na manji broj for petlji.
Ispis clanova sva tri niza bi preko jedne for petlje izgledao ovako:
/* grupno ispisivanje nizova A, B i C */
for(i=0; i<BROJ_ELEMENATA; i++) {
printf("\n%i. element niza A je: %.2f\n", i+1, a[i]);
printf("%i. element niza B je: %.2f\n", i+1, b[i]);
printf("%i. element niza C je: %.2f\n", i+1, c[i]); */
return 0;
}



PROST BROj

#include <stdio.h>
int main()
{
 int i, n;
 int prost=1;

 printf("Unesite broj n: ");
 scanf("%i", &n);
 
 
 /* Provjera unesenog broja */
 if (n<=0) {printf("Broj nije prirodan."); return 0;}
 else if (n==1) {printf("Broj nije niti prost, niti slozen."); return 0;}
 else {
i=2; /* Krecemo dijeljenjem sa brojem 2, i dijelimo dok je i<n, tj. do n-1 ukljucivo. */
 while(i<n) {
 if (n%i==0) {
prost=0;
 break;
 }
i++; /* Moramo manuelno/rucno/sami povecavati brojac jer koristimo while petlju */
 }
 }
 if (prost) {printf("Broj je prost."); return 0;}
 else {printf("Broj je slozen."); 
 return 0;}



NAJCESCA RIJEC STRING

char* izbaci_najcescu(char *s){
	char *p, *pok[500];
	int i=0, j=0,brojac[500]={0}, brojac_rijeci=1, najcesca[500]={0};
	p=s;
	pok[j]=p;
	if(*p=='\0')
		return NULL;
	while(*p!='\0'){
		if((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127)){
			brojac_rijeci++;
			do{
				p++;
			}while((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127));
			j++;
			i++;
			pok[j]=p;
			continue;
		}
		brojac[i]++;
		p++;
	}
	
	
	for(i=0;i<brojac_rijeci-1;i++){
		for(j=i+1;j<brojac_rijeci;j++){
			if(poredjenje(pok[i], pok[j],brojac[i], brojac[j]))
				najcesca[i]++;
		}
	}
	//u nizu imamo koliko se ponavlja rijec u nasem strigu//
	
	int max;
	max=0;
   for(i=0;i<brojac_rijeci;i++){
		if(najcesca[i]>najcesca[max]) 	
			max=i;
	}
	//clan najcesce rijeci//
	for(i=0;i<brojac_rijeci;i++){
		if(max==i) i++;
		if(poredjenje(pok[max], pok[i], brojac[max], brojac[i])){
			p=pok[i];
			if(i==brojac_rijeci-1){
				*p='\0';
				break;
			}
			while(*p!='\0'){
				*p=*(p+brojac[i]);	
				if(*p=='\0') break;
				p++;
			}
			do{
				pok[i]++;
			}while((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127));
			for(j=i+1;j<brojac_rijeci;j++){
				pok[j]-=brojac[i];
				
			}
			
		}
		
	}
	//izbacene su ponovljene rijeci osim prve//
	p=pok[max];
	while(*p!='\0'){
		*p=*(p+brojac[max]);	
		if(*p=='\0') break;
		p++;
	}
	
	return s;
}	


SUMA PROSTIH BROJEVA IZMEDJU DVA BROJA

#include <stdio.h>

int daj_prost() {
	int prost=1,i;
	static int p=1;
	while(2) {
		p++;
		for(i=2;i<p;i++) {
			if(p%i==0) {
				prost=0;
				break;
			}
			else{
				prost=1;
			}
		}
		if(prost==1) {
			return p;
		}
	}
}
	
	
	int main() {
	int A,B,i,x,suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		
		
		if((A==B) || (A>B)) {
			printf("A nije manje od B.\n");
			continue;
		}
		
		
		if(A==0 || (A<0 && B<0))
		printf("A nije prirodan broj.\n");
		else
		break;
	}
	while(2);
	
	for(i=0;i<B;i++) {
		x=daj_prost();
		if(x>A && x<B) {
			suma+=x;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d. ",A,B,suma);
		
return 0;
}




FIBBONACIJEV NIZ

/* Funkcija za ubacivanje elementa u niz  */
void ubaci(int niz[],int velicina_niza) {
    int element_niza,m=1;
    int i,j,broj;
    int dr_velicina=2*velicina_niza;
    int drugi_niz[20];
    int suma=0;
    for(i=0;i<dr_velicina;i++){
        if(i%2==0){
            drugi_niz[i]=niz[i/2];
            }
            else {

           element_niza=niz[i-m];
                while(element_niza!=0){
                    broj=element_niza%10;
                    suma+=abs(broj);
                    element_niza=element_niza/10;
                }
                drugi_niz[i]=suma;
                suma=0;
                m=m+1;
            }
        }
        for(j=0;j<dr_velicina;j++){
            niz[j]=drugi_niz[j];
        }
        
    }

/* Funkcija za izbacivanje elemenata iz niza */

int izbaci(int*p,int velicina_niza) {
    int fibonacci,i,k,m;
    for(i=0;i<velicina_niza;i++) {
        fibonacci=0;
        int broj;
        int prvi_broj=1;
        int drugi_broj=1;
        for(m=1;m<=*(p+i);m++) {
            if(*(p+i)==prvi_broj){
                fibonacci=1;
                break;
            }
            if(m==prvi_broj) {
                broj=prvi_broj;
                prvi_broj=prvi_broj+drugi_broj;
                drugi_broj=broj;
            }
            
        }
        
        if(fibonacci){
            k=i;
            while(k<velicina_niza-1){
                *(p+k)=*(p+k+1);
                k++;
            }
            velicina_niza--;
            i--;
        }
        
        
    }
    return velicina_niza;
}


/* Unosenje pocetnog niza i ispisivanje krajnjeg-modificiranog niza */

int main() {
int niz[20];
int i,g;
printf("Unesite niz od 10 brojeva: ");
for(i=0;i<10;i++){
    scanf("%d",&niz[i]);
}

    ubaci(niz,10);
    int niznakraju;
    niznakraju=izbaci(niz,20);
    if(niznakraju==0){
        printf("Prazan niz");
        return 0;
    }
    printf("Modificirani niz glasi: ");
    for(g=0;g<niznakraju;g++) {
        if(g<niznakraju-1 && g>=0){
            printf("%d, ",niz[g]);
        }
        else{
            printf("%d.",niz[g]);
        }
    }
    return 0;
}







IZBACIVANJE/UBACIVANJE REDOVA/KOLONA MATRICE

#include <stdio.h>

int main() {
	int M,N,i,j,m=0,t,s;
	int brojac=0,broj;
	int mat[200][200];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		if(M<1 || N<1 || M>200 || N>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
		else
		break;
	}
	while(5);

  /* Unosenje matrice */	
   printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++){
		scanf("%d",&mat[i][j]);
	}
    }
    
    for(i=0;i<M;i++) {
    	for(j=i+1;j<M;j++) {
    		brojac=0;
    		for(m=0;m<N;m++) {
    			if(mat[i][m]==mat[j][m]) {
    				brojac++;
    			}

                if(brojac==N) {
    				for(t=j+1;t<M;t++){
    					for(s=0;s<N;s++){
    						broj=mat[t-1][s];
    						
    						mat[t-1][s]=mat[t][s];
    						mat[t][s]=broj;
    					}
    				}
    				M--;
    				j--;
    			}
    		}
    	}
    }
    for(i=0;i<N;i++){
    	for(j=i+1;j<N;j++){
    		brojac=0;
    		
    		for(m=0;m<M;m++) {
    			if(mat[m][i]==mat[m][j]){
    				brojac++;
    			}
    			if(brojac==M) {
    				for(t=j+1;t<N;t++){
    					for(s=0;s<M;s++) {
    						broj=mat[s][t-1];
    						
    						mat[s][t-1]=mat[s][t];
    						mat[s][t]=broj;
    					}
    				}
    				N--;
    				j--;
    			}
    		}
    	}
    }
    
    printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for(i=0;i<M;i++) {
    	for(j=0;j<N;j++) {
    		printf("%5d",mat[i][j]);
    	}
    	printf("\n");
    }
    return 0;
    }





RAD SA STEPENIMA

#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#include <stdlib.h>

int main() {
	int k,broj_sekundi[500],broj_minuta[500],broj_stepeni[500],u;
	double niz[500],stepen,sekunda,minuta;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&u);
	
	/* Petlja pretvaranja stepeni u minute i sekunde */
	
	for(k=0;k<u;k++) {
		scanf("%lf",&niz[k]);
		
		broj_stepeni[k]=niz[k]*180/PI;
		stepen=fabs(niz[k]*180./PI)-abs(broj_stepeni[k]);
		
		broj_minuta[k]=stepen*60;
		minuta=stepen*60.-broj_minuta[k];
		
		sekunda=minuta*60.;
		broj_sekundi[k]=minuta*60;
	
		
		if(sekunda-abs(broj_sekundi[k])+0.5>=1) {
			broj_sekundi[k]++;
		}
		
		
		
		if(broj_minuta[k]+0.05>=60) {
			broj_minuta[k]=0;
			
			
		if(broj_stepeni[k]<0) 
		   broj_stepeni[k]--;
		   else
		   broj_stepeni[k]++;
		}
		
	if(abs(broj_sekundi[k])>30)
		niz[k]=(-1);
}
		printf("Uglovi su: \n");
		for(k=0;k<u;k++) {
		if(niz[k]!=(-1)){
			printf("%d stepeni %d minuta %d sekundi\n",broj_stepeni[k],broj_minuta[k],broj_sekundi[k]);
		}
		
	}
	
	return 0;
	}





CIRKULARNA I TEPLICOVA MATRICA



#include <stdio.h>

int main() {
	int p,t,k,r;
	int cirkularna_matrica=1, teplicova_matrica=1;
	
    do{
    printf("Unesite M I N: ");
    scanf("%d%d",&p,&t);
    if(t>0 && t<=100 && p>0 && p<=100){
        break;
    	printf("\nPogresan unos!");
    }
    while(5);
    
    float mat[100][100];
    printf("Unesite elemente matrice: ");
    for(k=0;k<p;k++) {
    	for(r=0;r<t;r++){
    	scanf("%f",&mat[k][r]);
    	}
    }
    
    for(k=0;k<(p-1);k++) {
        for(r=0;r<(t-1);r++) {
        if(mat[k][r]!=mat[k+1][r+1]) {
            teplicova_matrica=0;
            break;
        }    
            
        if(teplicova_matrica==0)
        break;
        }  
        
    for(k=0;k<(p-1);k++) {
        for(r=0;r<t;r++) {
            if(r==(t+1)){
                if(mat[k][r]!=mat[k-1][0]) {
                    cirkularna_matrica=0;
                    break;
                }
            }
        }

       
        if(teplicova_matrica){ 
          if(cirkularna_matrica){
              printf("Matrica je cirkularna");
              return 0;
          } else{
              printf("Matrica je Teplicova");
              return 0;
          }
}
        printf("Matrica nije ni cirkularna ni Teplicova");
        return 0;
        }
        


