/*Napišite program koja obavlja sljedeći zadatak: Potrebno je unijeti cijeli broj N, pomoću do-while petlje 
osigurati da je N cijeli broj djeljiv sa 4 veći ili jednak 8. Zatim nacrtati oblik kao na slici sastavljen od 
kvadrata u gornjem desnom i donjem lijevom uglu, X-a u gornjem lijevom i znaka plus u donjem desnom uglu.

N=8: 				N=12:
\  /+--+ 			\    /+----+
 \/ |  |             \  / |    |
 /\ |  |              \/  |    |
/  \+--+              /\  |    |
+--+ ||              /  \ |    |
|  |-++-            /    \+----+
|  |-++-            +----+  ||
+--+ ||             |    |  ||
                    |    |--++--
					|    |--++--
					|    |  ||
					+----+  ||


Napomena: Pri rješavanju zadatka NIJE dozvoljeno koristiti nizove niti matrice!*/

#include <stdio.h>

int main() {
    int n,i,j;
    
	printf("Unesite broj N:");
	scanf("%d", &n);
	
	while(n<8||n%4!=0){
		printf(" Neispravno N!\nUnesite broj N:");
		scanf("%d", &n);
	}
	printf("\n");

for(i=0; i<n/2; i++){
	for(j=0; j<n/2; j++){
		if(i==j){
			printf("\\");
		} else if (i==n/2-1-j){
			printf("/");
		} else {
			printf(" ");
		}
	}
	
	/*KVADRAT*/
	for(j=0; j<n/2; j++){
		if((i==0 || i==n/2-1) && (j==0 || j==n/2-1)){
			printf("+");
		} else if (i==0 || i==n/2-1){
			printf("-");
		} else if (j==0 || j==n/2-1){
			printf("|");
		} else {
			printf(" ");
		}
	}
	
	
	printf("\n");
}


for(i=0; i<n/2 ;i++){
	for(j=0; j<n/2; j++){
		if((i==0 || i==n/2-1) && (j==0 || j==n/2-1)){
			printf("+");
		} else if (i==0 || i==n/2-1){
			printf("-");
		} else if (j==0 || j==n/2-1){
			printf("|");
		} else {
			printf(" ");
		}
		
	}
	
	/*PLUS*/
	
	for(j=0;j<n/2;j++){
		if ((i==n/4 || i==n/4-1) && (j==n/4 || j==n/4-1)){
			printf("+");
		} else if (i==n/4 || i==n/4-1){
			printf("-");
		} else if (j==n/4 || j==n/4-1){
			printf("|");
		} else {
			printf(" ");
		}
		
	}
	
	printf("\n");
	
}

	return 0;
}
