#include <stdio.h>

int izbaci_cifre(int *brojevi,int vel1,int *cifre,int vel2)
{
	int i,j,cifra,da_li_se_nalazi,temp=0,temp1=0,temp2,broj=0,konacan_broj;
	for (i=0; i<vel2; i++) {
		if (cifre[i]<0 || cifre[i]>9) return 0;
		for (j=i-1; j>=0; j--) {
			if (cifre[i]==cifre[j]) return 0;
		}
	}

	for (i=0; i<vel1; i++) {
		temp1=0;
		temp2=brojevi[i];
		if(temp2<0) temp2*=-1;
		while (temp2!=0) {
			cifra=temp2%10;
			da_li_se_nalazi=0;
			for (j=0; j<vel2; j++) {
				if (cifra==cifre[j]) {
					da_li_se_nalazi++;
				}
			}

			if (da_li_se_nalazi==0) {
				temp=(temp1*10)+cifra;
				temp1=temp;
			}
			temp2/=10;

		}

		broj=0;

		if (temp==0) konacan_broj=0;
		while (temp!=0) {
			cifra=temp%10;
			konacan_broj=(broj*10)+cifra;
			broj=konacan_broj;
			temp/=10;
		}


		if (brojevi[i]<0) konacan_broj*=-1;
		brojevi[i]=konacan_broj;
	}
	return 1;
}



int main()
{
	int brojevi[] = {25, 235, 1235, 252, 22552255};
	int cifre[] = {2, 3, 5};
	int i;
	izbaci_cifre(brojevi, 5, cifre, 3);
	for (i=0; i<5; i++)
		printf("%d ", brojevi[i]);

	return 0;
}
