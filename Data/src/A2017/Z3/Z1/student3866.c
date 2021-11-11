#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int dva_od_tri(int n1[], int v1, int n2[], int v2, int n3[], int v3)
{
	int br=0, i1, i2, i3, j1, j2;

	for (i1=0; i1<v1; i1++) {
		bool nadjen1=false, nadjen2=false, nadjen3=false;

		for (j1=0; j1<i1; j1++)
			if(n1[j1]==n1[i1])
				nadjen1=true;
		if(nadjen1) continue;

		for(i2=0; i2<v2; i2++)
			if(n2[i2]==n1[i1])
				nadjen2=true;

		for (i3=0; i3<v3; i3++)
			if(n3[i3]==n1[i1])
				nadjen3=true;

		if((nadjen2 && !nadjen3) || (!nadjen2 && nadjen3))
			br++;
	}

	for (i2=0; i2<v2; i2++) {
		bool nadjen1=false, nadjen2=false, nadjen3=false;

		for (j2=0; j2<i2; j2++) 
			if(n2[j2]==n2[i2])
				nadjen2=true;
			if(nadjen2) continue;

			for(i1=0; i1<v1; i1++)
				if(n1[i1]==n2[i2])
					nadjen1=true;
			if(nadjen1) continue;

			for(i3=0; i3<v3; i3++)
				if(n3[i3]==n2[i2]&& !nadjen3)
					nadjen3=true;

			if (nadjen3)  br++;

		}
		return br;
	}
	int main()
	{
		
		return 0;
	}
