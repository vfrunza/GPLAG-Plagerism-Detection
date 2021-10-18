#include <stdio.h>

int izbaci_cifre(int br[], int vel1, int crf)
{
	int i=0, j=0, k=0;
	int br2[10]= {0};
	int znak=1, urednost=1, temp=0;
	int b=0;
	for(i=1; i<=vel1; i++) {
		if( (*(br+i)>9) || (*(br+i)<0) ) {
			urednost=0;
		}
	}
	if(urednost==1) {
		if(crf<0) {
			znak=-1;
			crf = znak * -1;

		}

		temp=crf;

		while(temp>=1) {
			br2[b]=temp%10;
			temp= temp/10;
			b++;
		}

		for(i=0; i<b; b++) {
			for(j=0; j<vel1; j++) {
				if((br2+i)==*(br+j)) {
					for(k=i; k<b; k++)
						br2[k]=br2[k+1];

					b--;
					i = i-1 ;

				}
			}
		}
		crf=0;
		i=b-1;
		for(i; i>=0; i--) {
			crf = crf + br2[i];
			crf = crf * 10;
		}
		crf=crf/10*znak;
		return crf;
	} else return -1111;

	}

int main()
{
	int cifra=0;
	int brojevi[100]={0};
	int i=0, vel1=0, a=0;

	printf("\nUnesite broj:");
	scanf("%d", &cifra);
	printf("\nUnesite velicinu niza:");
	scanf("%d", &vel1);
	printf("\nUnesite niz brojeva: ");
	for(i=0; i<vel1; i++) {
		scanf("%d",&brojevi[i]);
	}
	a=izbaci_cifre(brojevi,vel1,cifra);
	if(a!=-1111)
		printf("Broj bez cifara glasi: %d", a);
	else printf("Neispravan unos");
	return 0;
}
