#include <stdio.h>

int dva_od_tri (int niz_1[], int n1, int niz_2[], int n2, int niz_3[], int n3)
{
	int rezultat = 0;
	int prebrojani[1000];
	int i,j,k;
	int pomocni_1, pomocni_2;
	
	
	for (i = 0; i<n1;i++)
		{
			pomocni_1 = 0;
			for (j = 0;j<n2;j++)
				{
					if (niz_1[i] == niz_2[j])
						pomocni_1 = 1;
				}
			
			
			pomocni_2 = 0;
			for (k = 0; k<n3; k++)
				{
					if (niz_1[i] == niz_3[k])
						pomocni_2 = 1;
				}
				
				
			if ((pomocni_1 == 1 && pomocni_2 == 0) || (pomocni_1 == 0 && pomocni_2 == 1))
				{
					pomocni_1 = 1;
					for (j = 0; j<rezultat; j++)
						{
							if (niz_1[i] == prebrojani[j])
								pomocni_1 = 0;
						}
						
					if (pomocni_1 == 1)
						prebrojani[rezultat++] = niz_1[i];
				}
			
		}
		
	for (i = 0; i<n2;i++)
		{
			pomocni_1 = 0;
			for (j = 0;j<n1;j++)
				{
					if (niz_2[i] == niz_1[j])
						pomocni_1 = 1;
				}
			
			
			pomocni_2 = 0;
			for (k = 0; k<n3; k++)
				{
					if (niz_2[i] == niz_3[k])
						pomocni_2 = 1;
				}
				
				
			if ((pomocni_1 == 1 && pomocni_2 == 0) || (pomocni_1 == 0 && pomocni_2 == 1))
				{
					pomocni_1 = 1;
					for (j = 0; j<rezultat; j++)
						{
							if (niz_2[i] == prebrojani[j])
								pomocni_1 = 0;
						}
						
					if (pomocni_1 == 1)
						prebrojani[rezultat++] = niz_2[i];
				}
			
		}
	
	for (i = 0; i<n3;i++)
		{
			pomocni_1 = 0;
			for (j = 0;j<n2;j++)
				{
					if (niz_3[i] == niz_2[j])
						pomocni_1 = 1;
				}
			
			
			pomocni_2 = 0;
			for (k = 0; k<n1; k++)
				{
					if (niz_3[i] == niz_1[k])
						pomocni_2 = 1;
				}
				
				
			if ((pomocni_1 == 1 && pomocni_2 == 0) || (pomocni_1 == 0 && pomocni_2 == 1))
				{
					pomocni_1 = 1;
					for (j = 0; j<rezultat; j++)
						{
							if (niz_3[i] == prebrojani[j])
								pomocni_1 = 0;
						}
						
					if (pomocni_1 == 1)
						prebrojani[rezultat++] = niz_3[i];
				}
			
		}
	
	
	return rezultat;
}


int main() {
	
	int niz_1[4] = {1,2,3,5};
	int niz_2[5] = {1,2,4,6,7};
	int niz_3[6] = {1,3,4,8,9,10};
	
	printf("%d", dva_od_tri(niz_1,4,niz_2,5,niz_3,6));
	
	
	
	
	
	return 0;
}
