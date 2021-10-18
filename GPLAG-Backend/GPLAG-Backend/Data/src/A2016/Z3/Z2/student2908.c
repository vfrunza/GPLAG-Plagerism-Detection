#include <stdio.h>
#include <math.h>

void ubaci(int* niz,int vel){
	int broj,i,j,suma[100]={0};
	for(i=0;i<vel;i++){
    	broj=fabs(niz[i]);
		while(broj!=0){
       		suma[i] += broj % 10;
       		broj= broj / 10;
    	}
	}
	i--;
	vel*=2;
	for(j=vel-1;j>0;j--){
		if(j%2==1){
      		niz[j] = suma[i];
   			i--;
		}
		if(j%2==0){
			niz[j]=niz[j/2];
		}
	}
}

int izbaci(int* niz,int vel){
	int  i,j, nizF[77]={1,1},k;
	for(i=2; i<77; i++){
		nizF[i]=nizF[i-1]+nizF[i-2]; 
    }
   	for(i=0; i<vel; i++){
   		for(j=1;j<77;j++){
   			if(niz[i]==nizF[j]){
   				for (k=i; k<vel-1; k++) {
					niz[k] = niz[k+1];
 				}
				vel--;            
				i--;
				break;
			}
		}
   	}
	return vel;
}

int main() {
	int niz[100],i,vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<vel;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,vel);
	vel*=2;
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel-1;i++)
		printf("%d, ", niz[i]);
	printf("%d.", niz[i]);
	return 0;
}
