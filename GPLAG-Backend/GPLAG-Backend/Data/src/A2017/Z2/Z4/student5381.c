#include <stdio.h>

int main() {
	int A[100][100],B[100][100],C[100][100];
	int i,j,m,n;
	int AA[10000],BB[10000],CC[10000];
	int min1,temp1,min2,temp2,min3,temp3;
	int jednaki=1;
	do{
	   printf ("Unesite brojeve M i N: ");
	   scanf ("%d %d",&m,&n);
	}
	while (m<0 || m>100 || n<0 || n>100);
	/*Unos clanova matrice.*/
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		scanf ("%d", &A[i][j]);
	}
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		scanf ("%d", &B[i][j]);
	}
	printf ("Unesite clanove matrice C: ");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		scanf ("%d", &C[i][j]);
	}
	/*U sljedece tri petlje 2d nizove pretvaramo u 1d nizove.*/
	for (i=0;i<m;i++)
	{ for (j=0;j<n;j++)
	   AA[i*n+j]=A[i][j];}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		BB[i*n+j]=B[i][j];
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		CC[i*n+j]=C[i][j];
	}
	/*U naredne tri petlje 1d nizove koje smo dobili iz 2d nizova sortiramo po velicini od najmanjeg ka najvecem.*/
	for (i=0;i<m*n;i++)
	{
		min1=i;
		for (j=i+1;j<m*n;j++){
			if (AA[j]<AA[min1])
			min1=j;
		}
		temp1=AA[i];
		AA[i]=AA[min1];
		AA[min1]=temp1;
	}
	for (i=0;i<m*n;i++)
	{
		min2=i;
		for (j=i+1;j<m*n;j++){
			if (BB[j]<BB[min2])
			min2=j;
		}
		temp2=BB[i];
		BB[i]=BB[min2];
		BB[min2]=temp2;
	}
	for (i=0;i<m*n;i++)
	{
		min3=i;
		for (j=i+1;j<m*n;j++)
		{ if (CC[j]<CC[min3])
			min3=j;
		}
		temp3=CC[i];
		CC[i]=CC[min3];
		CC[min3]=temp3;
	}
	/*Ako matrice stvarno zadovoljavaju uslov zadatka one ce sad (kao 1d nizovi) biti potpuno jednaki.Uz pomoc logicke varijable provjeravamo ovaj uslov.*/
	for (i=0;i<m*n;i++)
	{
		if (AA[i]!=BB[i] || AA[i]!=CC[i])
		{
			jednaki=0;
			break;
		}
		else
		jednaki=1;
	}
	if (jednaki)
	printf ("DA\n");
	else
	printf ("NE\n");
	return 0;
}
