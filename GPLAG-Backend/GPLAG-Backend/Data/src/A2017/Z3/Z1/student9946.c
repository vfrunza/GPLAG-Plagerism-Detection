#include <stdio.h>
int dva_od_tri (int niz1[], int b1,int niz2[],int b2,int niz3[],int b3)
{
	int zajednickiNiz12[100],brojac1=0;
	int zajednickiNiz13[100],brojac2=0;
	int zajednickiNiz23[100],brojac3=0;
	int brojJednakih=0,i,j;

	for(i=0; i<b1; i++) {
		if(i!=0 && niz1[i]==niz1[i-1]) {
			break;
		}

		for(j=0; j<b2; j++) {

			if(niz1[i]==niz2[j]) {

				zajednickiNiz12[brojac1]=niz2[j];
				brojac1++;

				break;
			}
		}


	}

	for(i=0; i<b1; i++) {
		if(i!=0 && niz1[i]==niz1[i-1]) {
			break;
		}
		for(j=0; j<b3; j++) {
			if(niz1[i]==niz3[j]) {
				zajednickiNiz13[brojac2]=niz3[j];
				brojac2++;
				break;
			}
		}

	}
	for(i=0; i<b2; i++) {
		if(i!=0 && niz2[i]==niz2[i-1]) {
			break;
		}
		for(j=0; j<b3; j++) {
			if(niz2[i]==niz3[j]) {
				zajednickiNiz23[brojac3]=niz2[i];
				brojac3++;
				break;
			}
		}

	}
	brojJednakih=brojac1+brojac2+brojac3;
	for(i=0; i<brojac1; i++) {
		for(j=0; j<b3; j++) {
			if(zajednickiNiz12[i]==niz3[j]) {

				brojJednakih--;
				break;
			}
		}

	}
	for(i=0; i<brojac2; i++) {
		for(j=0; j<b2; j++) {
			if(zajednickiNiz13[i]==niz2[j]) {

				brojJednakih--;
				break;
			}
		}

	}
	for(i=0; i<brojac3; i++) {
		for(j=0; j<b1; j++) {
			if(zajednickiNiz23[i]==niz1[j]) {

				brojJednakih--;
				break;
			}
		}

	}
	for(i=0; i<brojac2; i++) {
		for(j=i+1; j<brojac2; j++) {
			if(zajednickiNiz13[i]==zajednickiNiz13[j]) {

				brojJednakih--;
				break;
			}
		}

	}
		for(i=0; i<brojac1; i++) {
		for(j=i+1; j<brojac1; j++) {
			if(zajednickiNiz12[i]==zajednickiNiz12[j]) {

				brojJednakih--;
				break;
			}
		}

	}
	for(i=0; i<brojac3; i++) {
		for(j=i+1; j<brojac3; j++) {
			if(zajednickiNiz23[i]==zajednickiNiz23[j]) {

				brojJednakih--;
				break;
			}
		}

	}
	return brojJednakih;
}
int main()
{
 int niz1[] = {1, 2, 3}, n1 = sizeof niz1 / sizeof *niz1;
    int niz2[] = {3, 2, 3}, n2 = sizeof niz2 / sizeof *niz2;
    int niz3[] = {2, 2}, n3 = sizeof niz3 / sizeof *niz3;
      
  printf ("%d ", dva_od_tri(niz3, n3, niz2, n2, niz1, n1));
 
  
	return 0;
}
