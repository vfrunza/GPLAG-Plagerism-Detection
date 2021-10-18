#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int izbaci_cifre(int *brojevi,int velbr,int *cifre,int velcif)
{
	int *pbr=brojevi, *pc=cifre, cifra,j,i,clan,prolaz=0,t=0;
	for(i=0; i<velcif; i++) {
		if(*(pc+i)<0 || *(pc+i)>9) return 0;
		for(j=i+1; j<velcif; j++) {
			if(*(pc+i)==*(pc+j)) return 0;
		}
	}
	for(i=0; i<velbr; i++) {
		clan=*(pbr+i);
		*(pbr+i)=0;

		do {
			cifra=clan%10;
			clan=clan/10;
			for(j=0; j<velcif; j++) {
				if(abs(cifra)==*(pc+j)) t=1;
			}
			if(t==0) *(pbr+i)+=pow(10,prolaz)*cifra;
			else prolaz--;
			prolaz++;
			t=0;
		} while(clan%10!=0 || clan/10!=0);
		prolaz=0;

	}

	return 1;
}
int main()
{
	int brojevi[] = {12345, -12345};
	int cifre[] = {3,5};

	izbaci_cifre(brojevi, 2, cifre, 2);
	printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
