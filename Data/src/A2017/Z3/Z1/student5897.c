#include <stdio.h>
int NemaBroja(int niz[],int suma, int br)
{
	int i,k;
	for(i=0; i<suma; i++) {
		if(niz[i]==br) {
			k=0;
			return k;
		}
	}
	k=1;
	return k;
}
int NemaDuplikata(int niz[], int suma, int br, int i)
{
	int j,k;
	for(j=0; j<suma; j++) {
		if(j>i && niz[j]==br) {
			k=0;
			return k;
		}
	}
	k=1;
	return k;
}
int dva_od_tri( int a[], int suma1, int b[], int suma2, int c[], int suma3)
{
	int rez2=0,i,j,k,br;

	for(i=0; i<suma1; i++) {
		br=0;
		for(j=0; j<suma2; j++) {
			if (b[j]==a[i]) {
				br=1;
				break;
			} else br=0;
		}
		for(k=0; k<suma3; k++) {
			if(br==1 && c[k]==a[i]) {
				br=0;
				break;
			} else if (c[k]==a[i] && br==0 ) {
				br=1;
				break;
			}
		}
		if (br==1 && NemaDuplikata(a,suma1,a[i],i)) rez2++;
	}

	for(i=0; i<suma2; i++) {
		for(j=0; j<suma3; j++) {
			if (c[j]==b[i] && NemaBroja(a,suma1,b[i]) && NemaBroja(a,suma1,c[j]) && NemaDuplikata(c,suma3,c[j],j) && NemaDuplikata(b,suma2,b[i],i) ) {
				rez2++;
			}
		}
	}
	return rez2;

}

int main()
{

	return 0;
}
