#include <stdio.h>
#include <math.h>
#define vel_icina 46

/* da li je neki clan niza fibonacijev broj? */

int fibonnaci(int n){
    int niz[vel_icina],i=0;
    niz[0]=1;
    niz[1]=1;
    for(i=0;i<vel_icina;i++){
        if(i>=2){
        niz[i]=(niz[i-2]+niz[i-1]);}
    }
    for(i=0;i<vel_icina;i++){
    if(niz[i]==n){return 1;}
    }
    return 0;
}

/* izbacuje sve clanove niza koji su ujedno i fibonacijevi brojevi */
 int izbaci(int niz[],int vel){
    int i,j;

    for(i=0;i<vel;i++){
        if(fibonnaci(niz[i])){
            for(j=i;j<vel-1;j++){
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
            
        }
    }
    return vel;
}
    
/* funkcija koja vraca sumu cifara primljenog broja */ 

int suma(int n){
    int suma=0;
    while(n!=0){
        suma+=fabs(n%10);
        n=n/10;
    }
    return suma;
}

/* ubacivanje cifara broja u niz */
void ubaci(int niz[], int vel){
    int i,j,a=vel;
    for(i=0; i<a; i++){
        for(j=a-1; j>i; j--){
            niz[j+1]=niz[j];
        }
        niz[i+1]=suma(niz[i]);
        a++;
        i++;
    }

}

/* provjera */

int main(){
	
   int niz[1000],vel=10,i,y;
   
   printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<vel;i++){
        scanf("%d",&niz[i]);}
    ubaci(niz,10);
    y=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0;i<y;i++){
        if(i==y-1)
        printf("%d.",niz[i]);
        else if(i<y-1){
            printf("%d, ",niz[i]);
        }
    }       
    
    return 0;
}

