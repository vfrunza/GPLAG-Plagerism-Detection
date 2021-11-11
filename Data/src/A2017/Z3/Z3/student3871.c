#include <stdio.h>
int izbaci(int br, int niz[], int vel)
{
 int negativan,s=0,k=1,i;
 if(br<0)
 {
  negativan=1;
  br*=-1;
 }
 else negativan=0;
 
 while (br!=0)
 {
  int trenutno=br%10,ima=0;
  for(i=0;i<vel;i++)
  {
   if(niz[i]==trenutno) ima=1;
  }
  if(ima==0)
  {
   s+=k*(trenutno);
   k*=10;
  }
  br/=10;
 }
 if(negativan) return s*-1;
 else return s;
}
int izbaci_cifre(int niz[], int vel1, int niz2[], int vel2)
{
 int i,j;
 for(i=0;i<vel2;i++)
 {
  if(niz2[i]<0 || niz2[i]>9) return 0;
 }
 for(i=0;i<vel2;i++)
 {
  for(j=0;j<vel2;j++)
  {
   if(i==j){
   }
   else 
   {
    if(niz2[i]==niz2[j]) return 0;
   }
  }
 }
 for(i=0;i<vel1;i++)
 {
  niz[i]=izbaci(niz[i],niz2,vel2);
 }
 return 1;
}
int main() {
	return 0;
}


/*
#include <stdio.h>

int izbaci_cifre(int niz1[], int n1, int niz2[], int n2)
{
	int temp1,temp2=0,cifra;
	int predznak=1;
	int i,j;
	
	/*Provjera da li su cifre u drugom nizu ispravne i da li se ponavljaju
	for(i=0;i<n2;i++)
	{
		if(niz2[i]<0 || niz2[i]>9) return 0;
		for(j=i-1;j>=0;j--)
		{
			if(niz2[i]==niz2[j]) return 0;
		}
	}
	for(i=0;i<n1;i++)
	{
		/*Brisemo predznak broja i pamtimo koji je bio
		predznak=1; 
		if(niz1[i]<0) 
		{
			niz1[i]*=-1;
			predznak=-1;
		}
		
		/*Izbacivanje cifri
		temp1=niz1[i];
		temp2=0;
		for(j=0;j<n2;j++)
		{
			temp2=0;
			while(temp1!=0)
			{
				cifra=temp1%10;
				if(niz2[j]!=cifra) 
				{
					temp2+=cifra;
					temp2*=10;
				}
				temp1/=10;
			}
			temp2/=10;
			temp1=temp2;
		}
		if(n2%2!=0)
		{
			temp2=0;
			while(temp1!=0)
			{
				temp2+=temp1%10;
				temp2*=10;
				temp1/=10;
			}
			temp2/=10;
			temp1=temp2;
		}
		niz1[i]=temp1*predznak;
		
		
	}
	return 1;
}

int main() 
{
	int brojevi[] = {12345, -12345};
int cifre[] = {3,1,2};
izbaci_cifre(brojevi, 2, cifre,3);
printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
*/