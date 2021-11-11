#include <stdio.h>

int stepenuj(int br)
{
	int i, stepenovani=1;
	for(i=0; i<br; i++)
	{
			stepenovani*=10;	
	}
	return stepenovani;
}

int izbaci_cifre(int niz_jed[], int br1, int niz_dva[], int br2){
	int i, j, k, temp1, temp2, temp3, cifre=0, ostatak, isti=0, stepen;;
	
	for(i=0; i<br2; i++)
		if (niz_dva[i]<0 || niz_dva[i]>9)
			return 0;
	for(i=0; i<br2; i++)
	{
		for(j=i+1; j<br2; j++)
			if (niz_dva[i]==niz_dva[j])
				return 0;
	}
	
	for(i=0; i<br1; i++)
	{
		cifre=0;
		temp1=niz_jed[i];
		while(temp1!=0)
		{
			cifre++;
			temp1/=10;
		}
		if (niz_jed[i]>0)
			temp2=niz_jed[i];
		else if (niz_jed[i]<0)
			temp2=niz_jed[i]*(-1);
		temp3=0;
		/*rastavljanje brojeva na cifre i provjeravanje sa drugim nizom*/
		for(j=0; j<cifre; j++)
		{
			isti=0;
			stepen=cifre-1-j;
			ostatak=temp2/stepenuj(stepen);
			for(k=0; k<br2; k++)
			{
				if (niz_dva[k]==ostatak)
				{
					isti=1;
					break;
				}
			}
			if (isti==0)
				temp3+=ostatak*stepenuj(stepen);
			else if (isti==1)
				temp3/=10;
			temp2-=ostatak*stepenuj(stepen);	
		}
		if (niz_jed[i]>0)
			niz_jed[i]=temp3;
		else if (niz_jed[i]<0)
			niz_jed[i]=temp3*(-1);
	}
	return 1;

}

int main() {
	int i, niz_jed[100], niz_dva[100], br1, br2, rezultat;
	
	printf("Unesite broj elemenata prvog niza: ");
	scanf("%d",&br1);
	printf("Unesite niz cijelih brojeva: ");
	for(i=0; i<br1; i++)
		scanf("%d",&niz_jed[i]);
		
	printf("Unesite broj elemenata drugog niza: ");
	scanf("%d",&br2);
	printf("Unesite niz cifara: ");
	for(i=0; i<br2; i++)
		scanf("%d",&niz_dva[i]);
		
	rezultat=izbaci_cifre(niz_jed,br1,niz_dva,br2);	
		
	if (rezultat==0)
		printf("Greska u nizu dva");
	else if (rezultat==1)
	{
		for(i=0; i<br1; i++)
			printf("%d ", niz_jed[i]);
	}
		
		
	return 0;
}