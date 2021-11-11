#include <stdio.h>

int dva_od_tri (int niz1[], int n1 ,int niz2[], int n2 ,int niz3[], int n3)
{
	int n=0,i,j,k,p,m=0,temp,l;
	
	for (i=0; i<n1; i++)
	{
		l=0;
		temp=niz1[i];
        p=0;

		for (m=0; m<i; m++)
		{
			if (temp==niz1[m])
			{
				p=1;
			}
		}
		if (p)
        {
            break;
        }


		for (j=0; j<n2; j++)
		{
			if (temp==niz2[j])
			{
				l=1;
			}
		}
		for (k=0; k<n3; k++)
		{
			if (temp==niz3[k])
			{
				l=0;
			}
		}
		if (l==1)
		{
			n++;
		}

	}


	/*u drugom i trecem*/
	for (i=0; i<n2; i++)
	{
		l=0;
		temp=niz2[i];

		p=0;
		for (m=0; m<i; m++)
		{
			if (temp==niz2[m])
			{
				p=1;
			}
		}
		if (p)
        {
            break;
        }

		for (j=0; j<n3; j++)
		{
			if (temp==niz3[j])
			{
				l=1;
			}
		}
		for (k=0; k<n1; k++)
		{
			if (temp==niz1[k])
			{
				l=0;
			}
		}
		if (l==1)
		{
			n++;
		}
	}


	/*u prvom i trecem*/
	for (i=0; i<n1; i++)
	{
		l=0;
		temp=niz1[i];

		p=0;
		for (m=0; m<i; m++)
		{
			if (temp==niz1[m])
			{
				p=1;
			}
		}
		if (p)
        {
            break;
        }

		for (m=0; m<i; m++)
		{
			if (temp==niz1[m])
			{
				continue;
			}
		}

		if (i!=n1-1 && temp==niz1[i+1])
		{
			continue;
		}

		for (j=0; j<n3; j++)
		{
			if (temp==niz3[j])
			{
				l=1;
			}
		}
		for (k=0; k<n2; k++)
		{
			if (temp==niz2[k])
			{
				l=0;
			}
		}
		if (l==1)
		{
			n++;
		}

	}
	return n;
}

int main() { 
	int niz1[10000];
	int niz2[10000]; 
	int niz3[10000];
  int vel1, vel2, vel3;
  int i,j,k;
 scanf("%d", &vel1);
  scanf("%d", &vel2);
   scanf("%d", &vel3);
   
printf("Unesite clanove prvog niza:\n");
    for (i=0; i<vel1; i++) {
        scanf("%d", &niz1[i]);
    }
   
    
    printf("Unesite clanove drugog niza:\n");
    for (j=0; j<vel2; j++) {
        scanf("%d", &niz2[j]);
    }
   
    
    printf("Unesite clanove treceg niza:\n");
    for (k=0; k<vel3; k++) {
        scanf("%d", &niz3[k]);
    }
    
   printf("\n%d", dva_od_tri(niz1, vel1, niz2, vel2, niz3, vel3));
	return 0;
}
