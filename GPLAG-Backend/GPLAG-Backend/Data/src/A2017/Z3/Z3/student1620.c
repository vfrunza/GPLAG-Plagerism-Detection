#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int izbaci_cifre (int *A,int n1, int *B, int n2) {
	int *a,*b, C[10000],D[1000],h,temp,temp2,temp3,y,z,x,g,o,wrong,negative,q,u,repeat,r;
	a = A;
	b = B;
	h = 0;
	u = 0;
	repeat = 0;
	negative = 0;
	wrong = 0;
	for (o=0;o<n2;o++){
		temp = *b;
		D[o] = temp;
		b++;
	}
	for (q=0;q<o;q++){
		if (q == o - 1){
			;
		} else {
			for(r = q + 1;r<o;r++){
				if(D[q] == D[r]){
					repeat = 1;
				}
			}
		}
	}
	b = B;
	for(u=0;u<n2;u++){
		temp = *b;
		b++;
		if (temp < 0 || temp > 9 || repeat == 1){
			wrong = 1;
		}
	}
	if (wrong == 1){
		return 0;
	} else {
	a = A;
	for (x=0;x<n1;x++){
		negative = 0;
		temp3 = 0;
		g=0;
		temp = *a;
		h=0;
		if (temp < 0){
			negative = 1;
			temp = abs(temp);
		}
		while (temp > 0)
		{
			temp2 = temp % 10;
			C[g] = temp2;
			temp = temp / 10;
			g++;
		}
		for (y=0;y<g;y++){
			for(z=0;z<n2;z++){
				if(C[y] == B[z]){
					C[y] = 0;
				}
			}
		}
		for(y=0;y<g;y++){
			if(C[y] == 0){
				;
			} else {
				temp3 = temp3 + C[y] * pow(10,h);
				h++;
			}
		}
		if (temp3 == 0){
			*a = 0;
			a++;
		} else {
			if (negative == 1){
				*a = -temp3;
				a++;
			} else {
				*a = temp3;
				a++;	
			}
		}
}
}
return 1;
}
int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
