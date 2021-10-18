#include <stdio.h>¸
/*for petlja za i*/
if(zbir_cifara>=k) {
			/*rotiranje niza*/
			for(j=granica; j<i; j++) {
				temp2=niz[granica];
				for(l=granica; l<i; l++) {
					niz[l]=niz[l+1];
				}
				niz[i]=temp2;
			}
			granica++;
}

int main() {
	printf("Zadaća 3, Zadatak 4");
	return 0;
}
