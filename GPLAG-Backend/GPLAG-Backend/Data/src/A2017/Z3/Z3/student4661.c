#include <stdio.h>
#include <math.h>

int izbaci_cifre (int niz1[], int velicina1, int niz2[], int velicina2){
	
	int i, j, k=0, r, f, t, a=0, niz3[1000];
	for(i=0; i<velicina2; i++){
		if(niz2[i]<0 || niz2[i]>9)
		return 0;
	}
	
	for(i=0; i<velicina2; i++){
		for(j=i+1; j<velicina2; j++){
			if(niz2[i]==niz2[j])
			return 0;
		}
	}
	
	for(i=0; i<velicina1; i++){
		
		if (niz1[i]<0){
			niz1[i]=niz1[i]*(-1);
			a=1;
		}
		for(j=0; j<velicina2; j++){
			
		/*rastavljanje na cifre*/
		while(niz1[i]>0){
			niz3[k]=niz1[i]%10;
			niz1[i]=niz1[i]/10;
			k++;
		}
			
			for(t=0; t<k; t++){
				if(niz3[t]==niz2[j]){
					
					for(f=t; f<k-1; f++){
						niz3[f]=niz3[f+1];
						
					}
					k--;
					t--;
				}
			}
			
			for(r=k-1; r>=0; r--){
				niz1[i]=niz1[i]+niz3[r]*(pow(10,r));
			}
			k=0;
		}
	
		
		if(a==1){
			niz1[i]=niz1[i]*(-1);
		}
		a=0;
	}
	return 1;

	}

int main() {
	int niz1[1000], niz2[1000], i, m, n, a;
	
	printf("Unesite velicinu niza 1: ");
	scanf("%d", &m);
	printf("Unesite brojeve niza 1: ");
	for(i=0; i<m; i++){
		scanf("%d", &niz1[i]);
	}
	
	printf("Unesite velicinu niza 2: ");
	scanf("%d", &n);
	printf("Unesite brojeve niza 2: ");
	for(i=0; i<n; i++){
		scanf("%d", &niz2[i]);
	}
	
	a=izbaci_cifre(niz1, m, niz2, n);
	printf("%d", a);
	
	for(i=0; i<m; i++){
		printf("%d", niz1[1]);
	}
	
	
	return 0;
}
