#include <stdio.h>
#include <math.h>

#define size 100

int main() {
	
	int niz[size];
	int c[1000];
	int rj[1000];
	int n, i, temp;
	double tmp;
	int cif = 0;
	int br = 0;
	
	for(i = 0; i < 1000; i++){
		c[i] = -1;
		rj[i] = -1;
	}
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	printf("Unesite clanove niza: ");
	for(i = 0; i < n; i++){
		scanf("%lf", &tmp);
		
		if(tmp < 0 || tmp != (int)tmp){
			i--;
			printf("ne valja unos\n");
			continue;
		}
		
		niz[i] = tmp;
	}
	
	br = 0;
	
	for(i = 0; i < n; i++){
		/*Ako su brojevi dvocifreni*/
		if(niz[i] > 9){
			temp = niz[i];
			cif = 0;
			
			/*Br cifara*/
			while(temp > 0){
				temp /= 10;
				cif++;
			}
			
			temp = niz[i];
			br += cif;
			
			/*Cifre u niz C*/
			while(cif > 0){
				c[br - cif] = temp/(int)pow(10, cif - 1);
				
				temp -= c[br - cif]*pow(10, cif - 1);
				
				cif--;
			}
			
			
		}else{
			/*ako nisu haha*/
			br++;
			c[br-1] = niz[i];
		}
	}
	
	br = 0;
	temp = 0;
	
	for(i = 0; i < 1000; i++){
		
		if(br == 0){
			rj[temp] = c[i];
			br++;
		}else{
			if(c[i] == c[i - 1]){
				br++;
			}else{
				rj[temp+1] = br;
				temp+=2;
				rj[temp] = c[i];
				br = 1;
			}
		}
		
	}
	
	printf("Finalni niz glasi:\n");
	for(i = 0; i < 1000; i++){
		if(rj[i] == -1) break;
		printf("%d ", rj[i]);
	}
	
	return 0;
}
