#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3)
{
	int Broj=0,i,j,k,l,prviclan,drugiclan,treciclan,dodaj=1,nastavi=1;
	
	/*Provjera da li se broj nalazi u prvom i drugom nizu a ne u trecem*/
	
	for(i=0;i<n1;i++)
	{
		nastavi=1;
		prviclan=niz1[i];
		if(i>0) for(l=i-1;l>=0;l--) if(prviclan==niz1[l]) nastavi=0;
		if(nastavi)
		{
			for(j=0;j<n2;j++)
			{
				nastavi=1;
				dodaj=1;
				drugiclan= niz2[j];
				if(j>0) for(l=j-1;l>=0;l--) if(drugiclan==niz2[l]) nastavi=0;
				if(nastavi)
				{
					if(prviclan==drugiclan)
					{
						for(k=0;k<n3;k++)
						{
							treciclan=niz3[k];
							if(treciclan==prviclan)
							{
								dodaj=0;
								break;
							}
						}
						if(dodaj)
						{
							Broj++;
							/*printf("%d %d\n",prviclan,drugiclan);*/
						}
					}
				}
			}
		}
	}
	
	
	/*Provjerava da li je broj u prvom i trecem nizu a ne u drugom*/
	
	for(i=0;i<n1;i++)
	{
		nastavi=1;
		prviclan=niz1[i];
		if(i>0) for(l=i-1;l>=0;l--) if(prviclan==niz1[l]) nastavi=0;
		if(nastavi)
		{
			for(j=0;j<n3;j++)
			{
				nastavi=1;
				dodaj=1;
				drugiclan=niz3[j];
				if(j>0) for(l=j-1;l>=0;l--) if(drugiclan==niz3[l]) nastavi=0;
				if(nastavi)
				{
					if(prviclan==drugiclan)
					{
						for(k=0;k<n2;k++)
						{
							treciclan=niz2[k];
							if(treciclan==prviclan)
							{
								dodaj=0;
								break;
							}
						}
						if(dodaj) Broj++;
					}
				}
			}
		}
	}
	
	/*Provjera da li se broj nalazi u drugom i trecem nizu a ne u prvom*/
	
	for(i=0;i<n2;i++)
	{
		nastavi=1;
		prviclan=niz2[i];
		if(i>0) for(l=i-1;l>=0;l--) if(prviclan==niz2[l]) nastavi=0;
		if(nastavi)
		{
			for(j=0;j<n3;j++)
			{
				nastavi=1;
				dodaj=1;
				drugiclan=niz3[j];
				if(j>0) for(l=j-1;l>=0;l--) if(drugiclan==niz3[l]) nastavi=0;
				if(nastavi)
				{
					if(prviclan==drugiclan)
					{
						for(k=0;k<n1;k++)
						{
							treciclan=niz1[k];
							if(treciclan==prviclan)
							{
								dodaj=0;
								break;
							}
						}
						if(dodaj) Broj++;
					}
				}
			}
		}
	}
	return Broj;
}

int main ()
{
	int niz1[]={0,0,0,0};
	int niz2[]={0,0,0,0};
	int niz3[]={0,0,0,0};
	int rez=dva_od_tri(niz1,4,niz2,4,niz3,4);
	printf("%d",rez);
	return 0;
}