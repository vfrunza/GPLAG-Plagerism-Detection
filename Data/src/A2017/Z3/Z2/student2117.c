#include <stdio.h>
#include <math.h>

float zaokruzi1(float a[],int n)
{   int i;
    for(i = 0; i < n; i++)
    { 
	a[i] = roundf((a[i]) * 10) / 10;
	
    }
	
	return *a;
}

void preslozi(float a[],int z, int k)
{
	int i,sumacifara,j;
	int* pom;
	int b[1000];
	zaokruzi1(a,z);
	for(i = 0; i < z; i++)
	{   
		sumacifara = 0;
		pom = a;
		while(a[i] !=  0)
		{
			sumacifara +=fabs (((int) a[i]*10) % 10);
			a[i] /= 10;
		}
		
	
			for( j=0; j<z; j++)
			{
				if(sumacifara < 14) a[i]=b[j]; else a[j]=b[i];
			}
		
	}
	
	
	
}
int main() {

	


    return 0;
}
