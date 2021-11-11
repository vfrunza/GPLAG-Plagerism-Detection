/*4. (0,5 bodova) 



Također su poznate Cirkularne matrice. Cirkularna matrica je matrica kod koji svaki red ima iste elemente kao red 
iznad pomaknute za jedno mjesto u desno, pri čemu element koji je u prethodnom redu bio posljednji u sljedećem postaje 
prvi. Možemo zaključiti da je svaka cirkularna matrica ujedno i Teplicova, dok obrnuto ne važi. 
Primjer cirkularne matrice:



Napišite program koji korisniku omogućuje unos dva prirodna broja M i N manja ili jednaka od 100. Koristite do-while
petlju da osigurate da su brojevi u traženom opsegu (jednu petlju za oba broja). 


Zatim korisnik unosi matricu realnih brojeva čije su dimenzije MxN, te na kraju ispisuje jednu od poruka "Matrica je
cirkularna", "Matrica je Teplicova" ili "Matrica nije ni cirkularna ni Teplicova".


Primjer ulaza i izlaza:
Unesite M i N: 101 5
Pogresan unos!
Unesite M i N: 99 -1
Pogresan unos!
Unesite M i N: 4 5
Unesite elemente matrice: 1 2 3 4 5 5 1 2 3 4 4 5 1 2 3 3 4 5 1 2
Matrica je cirkularna


*/
#include <stdio.h>
#include <math.h>
#define epsilon 0.001
int main() {
	int m,n,i,j,templic,cirkularna;
	double A[100][100]={{0}};
	

					
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m,&n);
		 if((m<=0 || m>100) || (n<=0 || n>100)){
				 	printf("Pogresan unos!\n");
				 }
		
				
			}
	while ((m<=0 || m>100) || (n<=0 || n>100));
	printf("Unesite elemente matrice: ");
	for (i=0; i<m; i++){
			for (j=0; j<n; j++){
				 scanf("%lf", &A[i][j]); 
			}
	}
	
	templic=0;
	cirkularna=0;
	/*U matematici je poznat pojam Teplicove matrice. Teplicova matrica je matrica kod koje su svi elementi 
na glavnoj dijagonali međusobno jednaki, ali su i na svakoj dijagonali koja je paralelna sa glavnom dijagonalom svi 
elementi također međusobno jednaki. Primjer Teplicove matrice:*/

		for (i=0; i<m-1; i++){
			for (j=0; j<n-1; j++){
				if(fabs(A[i][j]-A[i+1][j+1])<epsilon)
	templic=1;
	else{
		templic=0;
		break;
	}
				
			}
			if(templic==0)
			break;
		}
	
			for (i=0; i<m-1; i++){
			for (j=0; j<n-1; j++){
	if((templic==1) &&	(fabs(A[i][n-1]-A[i+1][0])<epsilon))
	{
				cirkularna=1;
	}
	else{		cirkularna=0;
				break;
	}
			}
			if(cirkularna==0)
			break;
			}
		if (cirkularna==1 || m==1) printf("Matrica je cirkularna");
		else
		if(templic==1 || n==1) printf("Matrica je Teplicova");
		else
		 printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
