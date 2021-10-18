#include <stdio.h>
int main() {
	int niz[10], i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	} printf("Modificirani niz glasi: ");
	for(i=0; i<10; i++){
		if(niz[i]<0){
			if(i==9) printf("%d.", niz[i]);
			else printf("%d, ", niz[i]);
		}
		
		
	}
return 0;
}
