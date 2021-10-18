#include <stdio.h>
int max (int matrica[100][100], int visina, int sirina)
{
	int ponavljanje [100][100];
	int i, j, g, h, brojac, max1=1, max=matrica[0][0];
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			ponavljanje[i][j]=-1;
			brojac=1;
			for (g=0; g<visina; g++) {
				for (h=i+1; h<sirina; h++) {
					/*Petlja koja trazi da li se broj ponavlja.*/
					if (matrica[i][j]==matrica[g][h])
						brojac++;
					/*Da brojac ne bi brojao dva puta isti element*/
					ponavljanje[g][h]=0;
				}
			}
			if (ponavljanje[i][j]!=0)
				ponavljanje[i][j]=brojac;
		}
	}
	/*Dodjeljicanje maximumu broj koji se najvise ponavlja*/
	for (i=0; i<visina; i++) {
		for (j=0; j<sirina; j++) {
			if (ponavljanje[i][j]==max1) {
				if (matrica[i][j]<max)
					max=matrica [i][j];
			} else if (matrica [i][j]>max)
				max=matrica[i][j];
		}
	}
	return max;

}
int izbaci_kolone (int matrica[100][100], int visina, int sirina, int n)
{
	int xkolona, i, j,g;
	/*Trazenje kolone koja treba da se izbaci*/
	for (j=0; j<sirina; j++) {
		for (i=0; i<visina; i++) {
			if (matrica[i][j]==n) {
				xkolona=i;
				matrica[i][xkolona]=matrica[i][i+1];
				sirina--;
				if (sirina==0)
					continue;
			}
		}
	}


	return matrica[i][j];
}
int main()
{
	int m1[100][100], i, j, s, v, maksimum, brojac1=1, brojac2=1, kolona, g, h;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf ("%d %d", &s,&v);
	for (i=0; i<v; i++) {
		printf ("Unesite elemente %d. reda: ",brojac1);
		for (j=0; j<s; j++ ) {
			scanf ("%d", &m1[i][j]);
		}
		brojac1++;
	}
	j=0;
	while ( j<s) {
		printf ("\nNakon %d. prolaza matrica glasi: \n", brojac2);
		maksimum=max(m1,v,s);
		kolona=izbaci_kolone(m1,v,s,maksimum);
		printf ("%d", kolona);
	}
}
brojac2++;
if (brojac2==s)
{
	printf ("\nNakon %d. prolaza matrica je prazna.", brojac2);
	break;
}
j++;

}

return 0;
}
++