#include <stdio.h>
#include <math.h>

int izbaci_cifre (int brojevi[],int vel1,int cifre[],int vel2)
{
	int novi[20],broj,cifra,vel=0,br=0,i,j,k,l;

	for(i=0; i<vel2; i++) {
		for(j=i+1; j<vel2; j++) {
			if(cifre[i]==cifre[j]) {
				return 0;
			}
		}
		if(cifre[i] <= -1 ||cifre[i]>9) return 0;
	}
	/*rastavljanje clanova niza brojevi[] na cifre i smjestanje tih cifara u novi niz*/
	for(i=0; i<vel1; i++) {
		vel=0;
		broj=brojevi[i];
		if(broj<0) {
			broj=-broj;
		}
		while(broj!=0) {
			cifra=broj%10;
			novi[vel]=cifra;
			vel++;
			broj=broj/10;
		}
		/*izbacivanje svih cifara iz svih clanova prvog niza koje se nalaze u drugom nizu */
		for(l=0; l<vel; l++) {
			for(j=0; j<vel2; j++) {
				if(novi[l]==cifre[j]) {
					for(k=l; k<vel-1; k++) {
						novi[k]=novi[k+1];
					}
					vel--;
					l--;
					break;
				}
			}
		}
		br=0;
		for(l=(vel)-1; l>=0; l--) {
			br=10*br+novi[l];
		}
		if(brojevi[i] > 0)	brojevi[i]=br;
		else brojevi[i]=-br;
	}
	return 1;
}


int main()
{
	int brojevi[50],cifre[50],rez,i,j,vel1,vel2;

	/*unos niza brojevi[]*/
	for(i=0; i<50; i++) {
		printf("Unesite %d. broj: ",i+1 );
		scanf("%d",&brojevi[i]);
		if(brojevi[i]==-1) break;
	}

	/*unos niza cifre[]*/
	for(j=0; j<50; j++) {
		printf("Unesite %d. cifru: ",j+1 );
		scanf("%d",&cifre[j]);
		if(cifre[j]==-1) break;
	}
	vel1=i;
	vel2=j;
	/*poziv funkcije izbaci_cifre*/
	rez=izbaci_cifre(brojevi,vel1,cifre,vel2);

	for(i=0; i<vel1; i++) {
		printf("%d ",rez);
	}
	return 0;
}
