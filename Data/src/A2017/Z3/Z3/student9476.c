#include <stdio.h>
#include <math.h>

int izbaci_cifre(int* nizbrojeva,int duz1,int* nizcifara,int duz2)
{
	
	int* p_br=nizbrojeva;					int* p_cif=nizcifara;
	
	int i,j,g,powbr,temp,predznak;			int broj_bez_cif,brojac_cifri,cifra_broja;
	
	
	//Ako drugi niz ima 2 ista elementa ili element veci od 9 ili element manji od 0
	for(i=0;i<duz2;i++)
	for(j=0;j<duz2;j++)
	if(p_cif[i]<0 || p_cif[i]>9 || (p_cif[i]==p_cif[j] && i!=j)) return 0;
	
	
	
	
	for(i=0;i<duz1;i++)
	{
		predznak=0;
		broj_bez_cif=0;
		brojac_cifri=0;
		if(p_br[i]<0) predznak=1;
		p_br[i]=fabs(p_br[i]);
		temp=p_br[i];
	
		
		
		//Trazim broj cifara broja
		do
		{
			temp/=10; 
			brojac_cifri++;
		}while(temp>0);

		temp=p_br[i];
		brojac_cifri--;
		
		//Gledam za svaku cifru elementa niza1 ako se nalazi u niz2, i ako ne dodajem na broj_bez_cif
		do
		{
			powbr=pow(10,brojac_cifri--);
		    cifra_broja=temp/powbr;
		    
			for(j=0;j<duz2;j++)
				if(p_cif[j]==cifra_broja) break;
			
			if(j==duz2)
			broj_bez_cif=broj_bez_cif*10+cifra_broja;
			
			temp=temp-cifra_broja*powbr;
			
		}while(brojac_cifri>=0);
		
		p_br[i]=broj_bez_cif;
		if(predznak)p_br[i]*=-1;
	}
	return 1;
	
}



int main() {
	
	return 0;
}
