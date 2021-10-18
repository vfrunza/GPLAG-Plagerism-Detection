#include <stdio.h>
#include <math.h>
void zaokruzi1(float *A, int n){
	float *a,x;
	a = A;
	for (x =0;x<n;x++){
		*a = round(*a * 10);
		*a = *a /10;
		a++;
	}
}

void preslozi(float A[],int len, int k){
	float niz1[100],niz2[100],*a;
	int x,c1,c2,temp,sum,temp2;
	zaokruzi1(A,len);
	c1= 0;
	c2 = 0;
	a = A;
	for (x = 0;x<len;x++){
		sum = 0;
		temp =fabs( *(A + x) * 10);
		do {
			temp2 = temp % 10;
			sum = sum + temp2;
			temp = temp / 10;
		} while (temp > 0);
		if (sum >= k){
			niz2[c2] = *(A + x);
			c2++;
		} else if 
		(sum < k){                                                                               
			niz1[c1] = *(A + x);
			c1++;
		}
	}
	for (x=0;x<len;x++){
		if(x < c2){
			*(A + x) = *(niz2 + x);
		} else{
			*(A + x) = *(niz1 + x - c2);
		}
	}

}


int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
