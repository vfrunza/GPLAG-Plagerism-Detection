#include <stdio.h>
int f1 (int*a, int b) {
	*a=*a/b;
	return *a++;
}
int main() {
	int A[4]={100,101,102,103};
	int B[3][3]={1,2,3,4};
	int b=1;
	b=B[0][2]+*(A+2);
	printf ("%d\n", b);
	b=f1(B+1, b+1);
	printf ("%d\n", b);
	return 0;
}
