#include <stdio.h>
#include <math.h>
int cifre(int broj){
	int brojac=0;
	while (broj!=0)
{
	broj=broj/10;
	brojac++;
	
}return brojac;
}
void izbaci_cifre(int* niz, int broj_clanova1, int* niz_izbacivaca, int broj_clanova2){
	int i,j,k;
	int cifra=0;
	int izbacivacki_clan;
	int* h=niz_izbacivaca;
	
		// uzimamo clan niza
			for(j=0;j<broj_clanova1;j++){
				int broj;
				int broj_cifara=0;
				
				
				// pronalazimo clan koji treba izbacit
				niz_izbacivaca=h;
	for(i=0;i<broj_clanova2;i++){
		izbacivacki_clan=(*niz_izbacivaca);
					broj=(*niz);
					int f;
					if(broj<0){
						f=1;
					}else{f=0;}
				broj_cifara=cifre(broj);
			int	novi_clan=0;
			
			// izbacivanje clana koji treba
					while (broj!=0)
				{
					for(k=0; k<broj_cifara;k++){
				cifra=fabs(broj%10);
				broj=broj/10;
				if(cifra!=izbacivacki_clan){
					novi_clan+=cifra*pow(10,k);
				}else{
					k--;
					broj_cifara--;
				}
				}
			}
			
			if(f==1){
	novi_clan=-novi_clan;}
	
			*niz=novi_clan;
			niz_izbacivaca++;
	
		
	}niz++;
	
}
}

int main() {
	

	return 0;
}
