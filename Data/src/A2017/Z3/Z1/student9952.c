#include <stdio.h>
#include <stdlib.h>
void prebroj(int niz[],int velicina,int p[], int w[]);

int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3);

int main()
{

	int niz1[]= {1,2,3,5};
	int niz2[]= {1,2,4,6,7};
	int niz3[]= {1,3,4,8,9,10};

	printf("\n%d",dva_od_tri(niz1,4,niz2,5,niz3,6));
	return 0;
}

/*------------------------------

funkcija koja u jedan niz stavlja vrijednosti koje se ne ponavljaju,
a u drugi niz upisuje u koliko nizova se broj pojavljuje


-----------------------------------------*/
void prebroj(int* niz, int velicina, int p[] , int w[])
{
	int i,j;
	int k;
	int t;

	for(i=0; i<velicina; i++)
	{
		k=0;
		while(1)
		{
			if( p[k]==0 && w[k]==0 )
			{
				p[k]=*(niz+i);
				w[k]++;
				break;
			}
			else if(p[k]==*(niz+i))
			{
				t=0;
				for(j=i-1; j>-1; j--)
				{
					if(  (*(niz+i)) == (*(niz+j))  )t=1;
				}

				if(!t)
				{
					w[k]++;
				}
				break;
			}
			else
			{
				k++;
			}

		}
	}


}

/*----------------------------------

-----------------------------------*/
int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3)
{

	int *p=(int*)malloc(sizeof(int)*(vel1+vel2+vel3+1));
	int *w=(int*)malloc(sizeof(int)*(vel1+vel2+vel3+1));
	int i;
	int k=0;
	int broj=0;
	for(i=0;i<vel1+vel2+vel3+1;i++)
	{
		p[i]=0;
		w[i]=0;
	}
	prebroj(niz1,vel1,p,w);
	prebroj(niz2,vel2,p,w);
	prebroj(niz3,vel3,p,w);

	while(w[k]!=0)
	{
		if(w[k]==2)broj++;
		k++;
	}
free(p);
free(w);

	return broj;

}