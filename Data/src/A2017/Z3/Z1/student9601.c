#include <stdio.h>
int dva_od_tri(int niz1[], int x, int niz2[], int y, int niz3[], int z)
{
 int i,br=0,p,j,s,clan1,clan2,clan3,add,dalje;
 /*Ispitivanje ima li clana u prvom i drugom, a ne u trecem nizu*/
 for(i=0;i<x;i++)
 {
  dalje=1;
  clan1=niz1[i];
  if(i>0) for(p=i-1;p>=0;p--)
   if(clan1==niz1[p]) dalje=0;
  if(dalje)
  {
   for(j=0;j<y;j++)
   {
    dalje=1;
    add=1;
    clan2=niz2[j];
    if(j>0) for(p=j-1;p>=0;p--)
     if(clan2==niz2[p]) dalje=0;
      if(dalje)
      {
       if(clan1==clan2)
       {
        for(s=0;s<z;s++)
        {
         clan3=niz3[s];
         if(clan3==clan1)
         {
          add=0;
          break;
         }
        }
        if(add) br++;
       }
      }
   }
  }
 }
 /*U drugom i trecem, a ne u prvom*/
 for(i=0;i<y;i++)
 {
  dalje=1;
  clan1=niz2[i];
  if(i>0) for(p=i-1;p>=0;p--)
   if(clan1==niz2[p]) dalje=0;
    if(dalje)
    {
     for(j=0;j<z;j++)
     {
      dalje=1;
      add=1;
      clan2=niz3[j];
      if(j>0)
      for(p=j-1;p>=0;p--)
      if(clan2==niz3[p]) dalje=0;
       if(dalje)
       {
        if(clan1==clan2)
        {
         for(s=0;s<x;s++)
         {
          clan3=niz1[s];
          if(clan3==clan1)
          {
           add=0;
           break;
          }
         }
         if(add) br++;
        }
       }
     }
    }
 }
 /*Prvi i treci, a ne drugi niz*/
 for(i=0;i<x;i++)
 {
  dalje=1;
  clan1=niz1[i];
  if(i>0) for(p=i-1;p>=0;p--) if(clan1==niz1[p]) dalje=0;
  if(dalje)
  {
   for(j=0;j<z;j++)
   {
    dalje=1;
    add=1;
    clan2=niz3[j];
    if(j>0) for(p=j-1;p>=0;p--)
    if(clan2==niz3[p]) dalje=0;
    if(dalje)
    {
     if(clan1==clan2)
     {
      for(s=0;s<y;s++)
      {
       clan3=niz2[s];
       if(clan3==clan1)
       {
        add=0;
        break;
       }
      }
      if(add) br++;
     }
    }
   }
  }
 }
 return br;
}
int main() {
	return 0;
}

/*
#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3)
{
    int i,brojac=0,dodaj=1,j,Broj=0;
	int max=n1;
	int niz[100000];
	if(n2>max) max=n2;
	if(n3>max) max=n3;
 
    /*Pravimo niz i niz brojaca svih brojeva koji se nalaze u sva tri niza, bez ponavljanja istih
	for(i=0;i<max;i++)
    {
        if(i<n1)
        {
            dodaj=1;
            for(j=0;j<brojac;j+=2)
            {
                if(niz[j]==niz1[i])
                {
                    dodaj=0;
                    break;
                }
            }
            if(dodaj)
            {
                niz[brojac]=niz1[i];
                niz[brojac+1]=0;
                brojac+=2;
            }
        }

        if(i<n2)
        {
            dodaj=1;
            for(j=0;j<brojac;j+=2)
            {
                if(niz[j]==niz2[i])
                {
                    dodaj=0;
                    break;
                }
            }
            if(dodaj)
            {
                niz[brojac]=niz2[i];
                niz[brojac+1]=0;
                brojac+=2;
            }
        }
        if(i<n3)
        {
            dodaj=1;
            for(j=0;j<brojac;j+=2)
            {
                if(niz[j]==niz3[i])
                {
                    dodaj=0;
                    break;
                }
            }
            if(dodaj)
            {
                niz[brojac]=niz3[i];
                niz[brojac+1]=0;
                brojac+=2;
            }
        }
    }

    /*Prebrojavamo sve brojeve i uvecavamo nizove
    for(i=0;i<brojac;i+=2)
    {
        for(j=0;j<n1;j++)
        {
            if(niz1[j]==niz[i])
            {
                niz[i+1]++;
                break;
            }
        }
        for(j=0;j<n2;j++)
        {
            if(niz2[j]==niz[i])
            {
                niz[i+1]++;
                break;
            }
        }
        for(j=0;j<n3;j++)
        {
            if(niz3[j]==niz[i])
            {
                niz[i+1]++;
                break;
            }
        }
    }
    
    /*Svi brojaci koji imaju vrijednost 2 su dakle brojevi koji se nalaze u dva od tri niza
    for(i=1;i<brojac;i+=2)
    {
        if(niz[i]==2) Broj++;
    }
	return Broj;
}

int main()
{
    /* AT1: Primjer iz zadatka 
int niz1[] = {0, 1, 2};
int niz2[] = {0, 1, 2};
int niz3[] = {1, 1, 1};
int rez = dva_od_tri(niz1, 3, niz1, 3, niz1, 0);
printf("%d", rez);
	return 0;
}

*/