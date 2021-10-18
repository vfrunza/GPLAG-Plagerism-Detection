#include <stdio.h>


    int faktorijel(int x) {
    	int s=1;
    	int i;
    	for(i=1; i<=x; i++)
    	s=s*i;
    	return s;
    }
    
 int main() {
 	int n;
 	printf("Unesite broj: ");
 	scanf("%d",&n);
 	faktorijel(n)
 }
