#include <stdio.h>

int main() {
	int n=1, i, j=0, x[20], y[20], k, a=1, b=1;
	for(i=0; i<20; i++){
		x[i]=50;
		y[i]=50;
	}
		
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<= 0 || n>10)
		printf("Pogresan unos\n");
	}while(n<= 0 || n>10);
/*	for(i=0; i<n; i++){
		do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		a[x]=x;
		b[y]=y;
		}while(x < 0 || x>=20 || y < 0 || y>=20);
		
	}
	//niz a za x koordinatu, niz b za y koordinatu
		
	for(i=0; i<20; i++){				//radi samo kada se unosi samo jedna tacka !
		
			if(i == b[i]){
				for(j=0; j<20; j++){
					if(j==a[j])
						printf("*");
					else printf(" ");
				}
			}
		
		if(i!=b[i])
		printf("\n");
	}
	
	
/*	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(i == b[i] && j == a[i]) printf("*");
			else printf("X");
			
		}
		if(i!=b[i])
		printf("\n");
			
		
		
	}
*/	
	
	
		for(i=0; i<n; i++){
		do{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a, &b);
		x[i]=a;
		y[i]=b;
		if(a < 0 || a>=20 || b < 0 || b>=20)
			printf("Pogresan unos\n");
		}while(a < 0 || a>=20 || b < 0 || b>=20);
		
	}
	//niz a za x koordinatu, niz b za y koordinatu
		
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
			{
				for(k=0; k<10; k++)
				{
					if(x[k] == j && y[k] == i) {
						printf("*");
						break;
					}
					
				}
				if(x[k]!=j)
					printf(" ");
				
			}
		
		printf("\n");
	}

	
	
	
	return 0;
}
