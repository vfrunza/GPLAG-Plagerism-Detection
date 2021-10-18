#include <stdio.h>
#include <math.h>
typedef unsigned char _bool;
#define true 1
#define false 0
char* ubaci_broj(char* s, int n){
	char* p = s;
	unsigned n2 = (n >= 0) ? n : (-n);
	unsigned len =0;
	unsigned count = 0;
	unsigned i;
	unsigned temp = n2;
	_bool neg = (n >= 0) ? false : true;
	_bool end;
	do{
		count++;
		temp = temp/10;
	} while (temp != 0);
	temp = n2;
	while (*s != '\0'){
		if (*s == ' '){
			if (len > 0){
				end = true;
				n2 = temp;
				char *k = s;
				while (*k != '\0'){
					k++;
					if(*k != ' ' && *k != '\0'){
						end = false;
					}
				}
					if (end){
						break;
					}
				
					if (*(s + 1) == ' '){
						while (k >s){
					    *(k + (neg ? count + 1 : count)) = *k;
                        k--;
						}
						k++;
					}
					else {
						while (k > s){
							*(k + (neg ? count + 2 : count + 1)) = *k;
                        	k--;
						}
						
						*(k + (neg ? count + 2  : count + 1)) = *k;
                        k++;
		
					}
					if(neg == 1){
						*k++ = '-';
					}
					for (i = count;i>0;i--){
						*k++ = n2 / pow(10,i - 1) + '0';
						n2 = n2 % (unsigned)pow(10,i - 1);
					}
					len = 0;
					s = k;
				}
			}
			else {
				len++;
			}
		s++;
	}
	return p;
}
int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
