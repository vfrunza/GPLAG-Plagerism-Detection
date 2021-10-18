#include <stdio.h>

int izbaci_cifre(int niz[] , int velniz,int nizcifri[] , int velnizcifri)
{
	int temp, i,j,novi_broj=0,negativan=0,daLi=0,k=1;

	/*Idi preko niza cifri*/
	for (i=0; i<velnizcifri; i++) {
		if (nizcifri[i]<0 || nizcifri[i]>9)
			return 0;
		for (j=i+1; j<velnizcifri; j++)
			if (nizcifri[i]==nizcifri[j])
				return 0;


	}
	/*Izbaci trazene cifre iz svakog broja niza pojedinacno*/
	for (i=0; i<velniz; i++) {
		temp=niz[i];
		if (temp<0) {
			negativan=1;
			temp*=-1;
		}
		while (temp>0) {

			for (j=0; j<velnizcifri; j++)
				if (nizcifri[j]==temp%10)
					daLi=1;

			if (daLi==0) {
				novi_broj+=k*(temp%10);
				k*=10;
			}
			daLi=0;
			temp/=10;
		}

		/*Prije brisanja cifri provjeri jeli broj bio pozitivan ili negativan*/
		if (negativan==1)
			niz[i]=-novi_broj;
		else
			niz[i]=novi_broj;
		novi_broj=0;
		negativan=0;
		k=1;
	}

	return 1;
}

int main ()
{
	return 0;
}