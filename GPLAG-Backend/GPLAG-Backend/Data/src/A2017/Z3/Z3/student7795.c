#include <stdio.h>
#include <stdlib.h>

/* remove given digits from number / izbaci_cifre prototype */
int _removeDigit(int num, int dig[], int lenD) {
	int temp = num, digit, _jump;
	int finalValue = 0, shift = 1, i;
	
	while(temp != 0) {
		digit = abs(temp % 10);
		temp = temp / 10;
		_jump = 0;
		
		for(i = 0; i < lenD; i++) { 
			if(dig[i] == digit)  {
				_jump = 1;
				break;
			}
		}
		
		if(_jump)
			continue;
		
		finalValue = finalValue + shift*digit;
		shift = shift*10;
	}
	if(num < 0) return -finalValue;
	else return finalValue;
}

int izbaci_cifre(int* A, int lenA, int dig[], int lenD) {
	/* initial */
	int i;
	int* t = A;
	/* check validity of digits to remove array */
	int _num[10] = {0};
	for(i = 0; i < lenD; i++) {
		if(dig[i] < 0 || dig[i] > 9)
			return 0;
		else if(++_num[dig[i]]>1) 
			return 0;
	}
	
	/* swap the numbers */
	for(i = 0; i < lenA; i++) {
		*t = _removeDigit(*t, dig, lenD);
		t++;
	}
	
	return 1;
}

int main() {
	
	return 0;
}
