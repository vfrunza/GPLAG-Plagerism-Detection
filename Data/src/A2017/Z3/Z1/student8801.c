#include <stdio.h>
int pronadji_max(int *niz,int vel);
int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3,int vel3)
{

	int i,j,brojaci1[100]= {0},brojaci2[100]= {0},brojaci3[100]= {0},max1=pronadji_max(niz1,vel1),max2=pronadji_max(niz2,vel2),max3=pronadji_max(niz3,vel3),niz[3]= {0},max=0;
	int brojac=0;

	niz[0]=max1;
	niz[1]=max2;
	niz[2]=max3;
	max=pronadji_max(niz,3);

	for(i=0; i<vel1; i++) {
		for(j=0; j<vel2; j++) {
			if(niz1[i]==niz2[j]) {    //poredjenje 1. i 2. niza
				brojaci1[niz1[i]]=1;
				break;

			}

		}

	}
	for(i=0; i<vel2; i++) {
		for(j=0; j<vel3; j++) {
			if(niz2[i]==niz3[j]) {
				//poredjenje 2. i 3. niza
				brojaci2[niz2[i]]=1;
				break;

			}

		}

	}

	for(i=0; i<vel1; i++) {
		for(j=0; j<vel3; j++) {
			if(niz1[i]==niz3[j]) {
				//poredjenje 1. i 3. niza
				brojaci3[niz1[i]]=1;
				break;

			}

		}

	}

	for(i=0; i<=max; i++) {
		if((brojaci1[i]==1 && brojaci2[i]==0 && brojaci3[i]==0) || (brojaci1[i]==0 && brojaci2[i]==1 && brojaci3[i]==0) || (brojaci1[i]==0 && brojaci2[i]==0 && brojaci3[i]==1))
			brojac++;



	}
	return brojac;

}
int pronadji_max(int *niz,int vel)
{
	int i;
	int max=niz[0];
	for(i=0; i<vel; i++) {   // funcija trazi maksimum niza
		if(niz[i]>max)
			max=niz[i];
	}

	return max;
}

int main()
{
	int a;
	int niz1[4]= {1,2,3,5},niz2[5]= {1,2,4,6,7},niz3[6]= {1,3,4,8,9,10};
	a=dva_od_tri(niz1,4,niz2,5,niz3,6);
	printf("%d",a);







	return 0;
}