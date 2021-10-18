#include <stdio.h>

int dva_od_tri (int *p1, int vel_1, int *p2, int vel_2, int *p3, int vel_3)
{
	int i, j, k;
	int brojac, temp, temp_brojac;
	brojac=0;
	
	
	for (j = 0; j < vel_1; j++) {
		temp_brojac=1;
		temp=*(p1+j);
		for (i = j-1; i >= 0; i--) {
			if (*(p1+j)==*(p1+i))
				break;
		}

		if (i==-1) {
			for (i = 0; i < vel_2; i++) {
				if (*(p2+i)==temp) {
					temp_brojac++;
					break;
				}
			}

			for (i = 0; i < vel_3; i++) {
				if (*(p3+i)==temp) {
					temp_brojac++;
					break;
				}
			}

			if (temp_brojac==2)
				brojac++;
		}
	}

	for (j = 0; j < vel_2; j++) {
		temp_brojac=1;
		temp=*(p2+j);

		for (i = j-1; i >= 0; i--) {
			if (*(p2+j)==*(p2+i))
				break;
		}

		if (i==-1) {
			for (i = 0; i < vel_3; i++) {
				if (*(p3+i)==temp) {
					for (k = 0; k < vel_1; k++) {
						if (*(p1+k)==temp)
							break;
					}
					if (k==vel_1)
						temp_brojac++;
					break;
				}
			}

			if (temp_brojac==2)
				brojac++;
		}
	}

	return brojac;
}

int main()
{
	int niz1[10]= {0,3,4,4,5,6,7,8,9,0};
	int niz2[10]= {1,1,2,4,5,6,7,8,9,0};
	int niz3[10]= {1,1,1,4,5,6,7,8,9,0};
	printf("%d",dva_od_tri(niz1,0,niz2,10,niz3,10));
	return 0;
}
