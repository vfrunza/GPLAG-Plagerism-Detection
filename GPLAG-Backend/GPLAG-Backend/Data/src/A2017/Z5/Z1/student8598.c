#include <stdio.h>

int main() {
int q=8, j=35;
do {
	j += q++;
	printf("%d\n", j);
} while (++q<9);
j%=q-3;
printf("q=%d,j=%d",q,j);
return 0;
}