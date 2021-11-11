#include <stdio.h>

void izbaci_clan(int niz[],int vel,int indeks){
    int i;
        for(i=indeks;i<vel-1;i++){
            niz[i]=niz[i+1];
    }
	
}

void ubaci(int niz_A[],int velicina_niza){
    int q,suma,cifre,Broj_brojeva;
    for(q=velicina_niza-1;q>=0;q--){
        niz_A[q*2]=niz_A[q];
    }
    for(q=0;q<velicina_niza;q++){
        suma=0;
        Broj_brojeva=niz_A[q*2];
        if(Broj_brojeva<0){
            Broj_brojeva=-Broj_brojeva;
        }
        while(Broj_brojeva!=0){
            cifre=Broj_brojeva%10;
            suma=suma+cifre;
            Broj_brojeva=Broj_brojeva/10;
        }
        niz_A[(q*2)+1]=suma;
        
    }
}


int izbaci(int niz1[],int br_el){
    int i,BROJ1,elemntmax;
    int t=0;
    int z=1;
    
    
    elemntmax=niz1[0];
    for(i=0;i<br_el;i++){
        if(niz1[i]>elemntmax){
            elemntmax=niz1[i];
        }
    }
    BROJ1=t+z;
    
    while(BROJ1<=elemntmax){
        for(i=0;i<br_el;i++){
            if(niz1[i]==BROJ1){
                izbaci_clan(niz1,br_el,i);
                br_el--;
                i--;
            }
        }
        
        t=z;
        z=BROJ1;
        BROJ1=t+z;
        
    }
    return br_el;
}

int main() {
    
    int i,br;
    int od_niza[20];
    
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++){
        scanf("%d",&od_niza[i]);
    }
	
	ubaci(od_niza,10);
	br=izbaci(od_niza,20);
	
	printf("Modificirani niz glasi: ");
	
	for(i=0;i<br;i++){
	    if(i==br-1){
	        printf("%d.",od_niza[i]);
	    }else{
	        printf("%d, ",od_niza[i]);
	    }
	}
	
	return 0;
}
