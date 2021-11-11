#include <stdio.h>

int SaberiCifre(int x){
    int n=0;
    if (x<0) x*=-1;
    while(x>0){
        n+= x%10;
        x/= 10;
    }
    return n;
}

void ubaci(int niz[], int vel){
	int i, j, t, m;
	for(i=0; i<vel; i++){
	    m=niz[i];
	    t=SaberiCifre(m);
	    vel++;
	    for(j=vel-1; j>i; j--){
	        niz[j]=niz[j-1];
	    }
	    niz[i+1]=t;
	    i++;
	}
}

/*void ubaci(int niz[], int vel){
    int niz1[vel];
    int i;
    for(i=0; i<vel; i++) niz1[i]=niz[i];
    
}*/

int dajFib(){
    static int a=0;
    static int b=1;
    int n;
    n=a+b;
    a=b;
    b=n;
    return n;
}

int izbaci(int niz[], int vel){
    int i,j,k,t, max=niz[0];

    for(i=0; i<vel; i++){
        if(niz[i]>max) max=niz[i];
    }
    while(1){
        t=dajFib();
        for(j=0; j<vel; j++){
            if(niz[j]==t){
                for(k=j+1; k<vel; k++){
                    niz[k-1]=niz[k];
                }
                vel--;
                j--;
            }
        }
        if(t>max) break;
    }
    return vel;
}

int main() {
    int niz[20];
    int i, t;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
        scanf("%d", &niz[i]);
    }
    ubaci(niz,10);
    t=izbaci(niz,20);
    printf("Modificirani niz glasi:");
    for(i=0; i<t-1; i++){
        printf(" %d,", niz[i] );
    }
    printf(" %d.", niz[i]);
    return 0;
}
 
