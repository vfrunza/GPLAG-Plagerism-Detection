#include <stdio.h>

int main() {
int q,r;
char c;
for (q=5; q>1; q--)
	for (r=6; r>q; r--) {
		c = 'H'+q+r;
		printf("%c", c);
	}
return 0;
}