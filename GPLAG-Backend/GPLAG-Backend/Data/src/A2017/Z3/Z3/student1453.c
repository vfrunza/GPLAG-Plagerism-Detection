#include <stdio.h>
#include <math.h>

int izbaci_cifre (int *niz1, int v1, int *niz2, int v2)
{
	int i,j,k,temp, broj, l, br, da,vrati,a;
	int *p=niz1;
	int niz3[1000]; 
	int niz4[1000];
	i=0; j=0; k=0; br=0; da=0; vrati=1;
	while(i<v1)
	{
		l=0;
		br=0; 
		niz4[i]=0;
		temp=fabs(niz1[i]);
		do
		{
			broj=temp%10;
			temp/=10;
			niz3[l]=broj;
			l++;
		}while(temp>0);
		
		
		while(j<l)
		{
			da=1;
			while(k<v2)
			{
				if(niz3[j]==niz2[k])
				da=0;
				k++;
			}
			k=0;
			
			if(da==1)
			{
				a=1;
				while(k<br) {a=a*10; k++;}k=0;
				niz4[i]=niz4[i]+niz3[j]*a;
				br++;
				da=0;
			}
			j++;
			
			
		}
		j=0;
	
		i++;	
	}
	
	i=0;
	j=0;
	
	while(i<v1)
	{
		if(niz1[i]<0)
		niz4[i]=niz4[i]*(-1);
		i++;
	}i=0;
	
	while(i<v1)
	{
		
		*p=niz4[i];
		p++;
		i++;
	}i=0;
	
	while(i<v2)
	{
		if(niz2[i]<0 || niz2[i]>=10) vrati=0;
		for(j=i+1; j<v2; j++)
		{
			if(niz2[i]==niz2[j])
			vrati=0;
		}
		i++;
	}
	return vrati;
}







/*int izbaci_cifre(int niz[10], int niz2[10])
{
	int i,j,suma;
	
	int  niz3[10];
	int k=1;
	k*=10;
	for(i=0;i<10;i++) {
	while(niz[i]!=0) {
		int b=niz[i]%10;
		int temp=1;
		for(i=0;i<10;i++) {
			b==niz[i]; temp=0;
		}
		if(temp==1) {
			suma= b*k;
			k*=10;
		}
	}
		
	}
	
	
}*/
	








int main() {
	int brojevi[] = {25, 235, 1235, 252, 22552255};
int cifre[] = {2, 3, 5};
int i;
izbaci_cifre(brojevi, 5, cifre, 3);
for (i=0; i<5; i++)
  printf("%d ", brojevi[i]);
	return 0;
}
