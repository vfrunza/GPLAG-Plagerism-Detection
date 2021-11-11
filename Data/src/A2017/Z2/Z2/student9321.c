#include <stdio.h>
void x(char*p){
*(p+1)=*(p+1)+1;
*p++='*';
p+=1;
*--p='*';
}

int main() {
	char c[]="Danska";
	x(c);
	printf("%s",c);
	return 0;
}
