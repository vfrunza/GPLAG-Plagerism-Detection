#include <stdio.h>

int dva_od_tri(int A[], int n1, int B[], int n2, int C[], int n3) {
	int x,y,r,r2,*temp,*temp2,*temp3,sum,last,N,P[100],*a,*b,*c,END,z;
	r = 0;
	r2 = 0;
	a = A;
	b= B;
	c= C ;
	temp = a;
	temp2 = b;
	temp3 = c;
	END = 0;
	sum = 0;
	for(x=0;x<n1;x++){
		for(y=x + 1;y<n1;y++){
			if(*a == *(a + y)){
				*(a + y) = 0;
			}
		}
		a++;
	}
	
	for (x=0;x<n1;x++){
		b = temp2;
		c =temp3;
		r = 0;
		r2 = 0;
		for(y = 0;y<n2;y++){
			if (*a == *b){
				r = 1;
			}
			b++;
		}
		for (z = 0;z<n3;z++){
			if (*a == *c){
				r2 = 1;
			}
			c++;
		}
		if (r != r2){
			sum = sum + 1;
		}
		a++;
	}
	a = temp;
	b = temp2;
	c =temp3;
	for (x=0;x<n3;x++){
		a = temp;
		b =temp2;
		r = 0;
		r2 = 0;
		for(y = 0;y<n2;y++){
			if (*c == *b){
				r = 1;
			}
			b++;
		}
		for (z = 0;z<n1;z++){
			if (*a == *c){
				r2 = 1;
			}
			a++;
		}
		if (r != r2){
			if(r > r2){
			sum = sum + 1;
			}
		}
		c++;
	}
	return sum;
}
	
	
	
int main() {
	printf("Zadaća 3, Zadatak 1");
	return 0;
}
