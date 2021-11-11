#include <stdio.h>

int main() {
	int nizA[100],nizB[100],broj_elemenata,broj_cifara,i;
	printf("Unesi broj brojeva: ");
	scanf("%d",&broj_elemenata);
	printf("Unesi niz brojeva: ");
	for(i=0;i<broj_elemenata;i++)
	scanf("%d",&nizA[i]);
	printf("Unesi broj cifara: ");
	scanf("%d",&broj_cifara);
	printf("Unesi niz cifara: ");
	for(i=0;i<broj_cifara;i++)
	scanf("%d",&nizB[i]);
	return 0;
}
