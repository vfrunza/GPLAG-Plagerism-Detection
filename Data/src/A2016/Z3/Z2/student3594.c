#include <stdio.h>

void ubaci(int p[], int clan){
	int i, k, suma=0, temp;
	
	for(i=0; i<clan*2; i+=2){
			temp=p[i];
			if(temp<0)
			temp*=(-1);

		while(temp>0){
			suma+=temp%10;
			temp=temp/10;
		}

		for(k=2*(clan-1);k>i;k--){
			p[k+1]=p[k];
		}
	
		p[i+1]=suma;
		suma=0;

	}
}

int izbaci(int p[], int clan)
{
    int i, j, prvi_clan, drugi_clan, treci_clan;
    
    for(i=0; i<clan; i++) {
        prvi_clan=1;
        drugi_clan=2;
        treci_clan=prvi_clan+drugi_clan;
        	
        	while(treci_clan<p[i]){
            prvi_clan=drugi_clan;
            drugi_clan=treci_clan;
            treci_clan=prvi_clan+drugi_clan;
        }
        
        if(p[i]==1 || p[i]==2 || p[i]==treci_clan) {
            for(j=i; j<clan-1; j++)
            p[j]=p[j+1];
            clan--;
            i--;
        }
   
    }
    return clan;
}


int main(){
	
	int i, niz[20], x;


	printf("Unesite niz od 10 brojeva: ");

	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	
	 	ubaci(niz,i);
		x=izbaci(niz,i*2);
	
	printf("Modificirani niz glasi: ");
	
	for(i=0; i<x; i++){
		if(i==x-1)
			printf("%d.", niz[i]);
		else
			printf("%d, ", niz[i]);
	}

	return 0;
}
