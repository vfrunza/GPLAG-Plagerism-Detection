#include <stdio.h>
#include<math.h>

int  izbaci_cifre(int *niz1,int vel1,int *niz2,int vel2)
{
	int i,j,r,k,l,br,br1=0;
	int postoji_broj = 0, negativan=0;
	int novi_broj = 0, pom_broj =0, isparcano = 0, desetice = 1;
	/*niz cifara,provjera da li je niz cifara ispravan*/
	for(i=0; i<vel2; i++) {
		if(niz2[i]<0 || niz2[i]>9) {
			return 0;
		}
		for(br=i+1; br<vel2; br++) {
			if(i==vel2-1) continue;
			if(niz2[i]==niz2[br]) {
				return 0;
			}
		}}
		/*niz cijelih brojeva*/
		for(j=0; j<vel1; j++) {
			
			/*parcanje prvog niza na cifre*/
			pom_broj = niz1[j];
			if(pom_broj<0) 
			{
				negativan=1;
				pom_broj *=-1;
			}
				while(pom_broj>0) {
					isparcano = pom_broj%10;
					for(k=0; k<vel2; k++) {
					if(isparcano == niz2[k])
					{
						postoji_broj = 1;
					}
				}
				if(postoji_broj== 0)
				{
					novi_broj = isparcano*desetice + novi_broj;
					desetice*=10;
				}
				pom_broj/=10;
				postoji_broj = 0;
				
			}
			if(negativan==1) novi_broj*=-1;
			niz1[j] = novi_broj;
			novi_broj = 0;
			desetice=1;
			negativan = 0;
		}
		return 1;
	}


int main()
{
	return 0;
}
