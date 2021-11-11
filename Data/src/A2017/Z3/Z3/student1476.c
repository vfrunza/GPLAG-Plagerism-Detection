#include <stdio.h>

int izbaci_cifre(int *niz, int vel, int *cifre, int vel2){
	int i, j, q, k, p;
	int c;
	int pomocni[100];
	int transformirani[100];
	int negativan =1;
	
	int velicina=0;
	
	for(i=0; i<vel2; i++){
		if(cifre[i]<0 || cifre[i]>9) return 0;
	}
	
	
	for(i=0; i<vel; i++){
		c=niz[i];
		negativan = 1;
		if(c<0){
			c=-c;
			negativan=-1;
		}
		j=0;
		
		do{
			pomocni[j] = c%10;
			j++;
			c/=10;
		} while(c!=0);
		velicina=j;
		for(q=j; q<100; q++){
			pomocni[q]=0;
		}
		q=0;
		for(j=velicina-1; j>=0; j--){
			transformirani[q]=pomocni[j];
			q++;
		}
		j=q;
		for(k=q; k<100; k++){
			transformirani[k]=0;
		}
		
		for(j=0; j<q; j++){
			for(k=0; k<vel2; k++){
				if(transformirani[j]==cifre[k]){
					for(p=j; p<q-1; p++){
						transformirani[p]=transformirani[p+1];
					}
					q--;
					j--;
					break;
				}
			}
		}
		if(q==0) transformirani[q]=0;
		
		niz[i]=0;
		
	
		/*pretvaranje niza u broj*/
		for(j=0; j<q; j++){
			niz[i] *= 10;
			niz[i] += transformirani[j];
		}
		if(negativan==-1) {
			niz[i]*=negativan;
		}
		
		
	}
	
	for(i=0; i<vel2; i++){
		for(j=i+1; j<vel2; j++){
			if(cifre[i]==cifre[j]) return 0;
		}
	}
	return 1;
}

int main(){
	int niz[5]={23, 24,25, 28, 9};
	int cifre[3]={2, 7, 3};
	int i=0;
	if(izbaci_cifre(niz, 5, cifre, 3)) printf("Uspjesno.");
	else printf("Nije uspjesno.");
	/*for(i=0; i<5; i++){
		
		printf("%d, ", niz[i]);
	}*/
	
	return 0;
}