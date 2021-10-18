#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int A[100] = {0},B[100] = {0},C[1000]= {0},D[1000],i,temp,temp2,v,p,a,k,length,n,c,j,count,b,z,num,a2;
	k =0;
	z = 1;
	printf("Unesite velicinu niza: ");
	do {
		scanf("%d",&v);
	} while(v < 0 || v > 100);
	printf("Unesite clanove niza: ");
	for(i=0;i<v;i++){
		scanf("%d",&a);
		A[i] = a;
		count = 0;
		temp = a;
		if (temp < 10) {
			count =  1;
		} else{
		while (temp > 0) {
			temp = temp / 10;
			count++;
		}
		temp = a;
		}
			while (count > 0) {
				B[k] = temp / pow(10,count - 1);
				temp = temp % (int) pow(10,count - 1);
				count--;
				k++;
		}
	}

	printf ("Finalni niz glasi: \n");
	for(i = 0;i<k;i++) {
		printf ("%d",B[i]);
		c = i;
		z = 1;
		while (B[i + 1] == B[i] && i != k - 1 ){
			z++;
			i++;
		}
		printf (" %d ",z);
	}
	return 0;
}
