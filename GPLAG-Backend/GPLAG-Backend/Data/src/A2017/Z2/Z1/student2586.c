#include <stdio.h>

int main() {
int i,j,mat[3][3] = {{7,7,8},
{8,5,1},{7,5,4}};
int rez=0;
for (i=0; i<3; i++)
	rez+=mat[i][3-i-1];
printf("rez=%d", rez);
return 0;
}