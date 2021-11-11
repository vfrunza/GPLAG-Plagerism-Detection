#include <stdio.h>

int main() {
	int vel;
	int niz1[100];
	int niz3[200];
	int niz2[1000];
	int broj_u_ciframa[5];
	int broj=0;
	int i=0;
	int *pok1=niz2;
	int *pok2=niz2;
	int j=0;
	int k=0;
	int p=0;
	int brojac=0;
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	printf ("Unesite clanove niza: ");
	for (i=0;i<vel;i++){
		scanf ("%d",&niz1[i]);
	}
	for (i=0;i<vel;i++){
		j=0;
		while (niz1[i]!=0){
			broj_u_ciframa[j]=niz1[i]%10;
			niz1[i]=niz1[i]/10;
			j++;
		}
		for (k=j-1;k>=0;k--){
			niz2[p]=broj_u_ciframa[k];
			p++;
		}
	}
	pok2=niz2+p;
	i=0;
	j=0;
	while(pok1!=pok2){
        brojac=0;
        broj=niz2[i];
        while((*pok1)==broj){
            pok1++;
            brojac++;
            i++;
        }
        niz3[j]=broj;
        j++;
        niz3[j]=brojac;
        j++;
	}
    printf ("Finalni niz glasi: \n");
	for (i=0;i<j;i++){
		printf ("%d  ",niz3[i]);
	}
	return 0;
}
