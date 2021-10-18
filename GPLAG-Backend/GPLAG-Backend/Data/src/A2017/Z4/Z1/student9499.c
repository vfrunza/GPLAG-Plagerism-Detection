#include <stdio.h>

/* function to add num into string */
char* ubaci_broj (char* input, int broj) {
	/* initial */
	int i = 0, temp, _size = 0, space = 1, _words = 0, _between = 0, _shift = 0;
	/* pointer initial */
	char* text = input;
	char* start = input;
	char* end = input;
	char* output = text;
	
	/* convert number into string */
	char num[13] = "";
	if(broj < 0) {
		num[i] = '-';
		broj = -broj;
		_size = 1;
	}
	temp = broj;
	while((temp /= 10)) _size++;
	
	if(broj == 0) num[_size] = '0';
	while(broj != 0) {
		num[_size - i] = broj % 10 + '0';
		i++;
		broj = broj/10;
	}
	
	/* start adding number between words */
	while(*text != '\0') {
		if(*text == ' ') space++;
		else if(space >= 1) {
			_words++;
			
			/* reset space between letters */
			_between = space;
			space = 0;
			
			/* check words */
			if(_words == 1) start = text;
			else if(_words == 2) {
				_words = 0;
				
				/* check if _between (spaces between two words) is =1 or >1  */
				_shift = 2;
				if(_between > 1) _shift = 1;
				while(--_between > 0) text--;
				
				end = text;
				text = start;
				
				/* increase size of input string */
				while(*text != '\0') text++;
				while(end <= text)  {
					*(text + _size + _shift) = *text;
					text--;
				}
				
				/* add number between words */
				i = 0;
				*text++ = ' ';
				while(i <= _size) {
					*text++ = num[i++];
				}
				if(_shift == 2) *text++ = ' ';
				
				/* reset pointer */
				text = end;
			}
		}
		text++;
	} 
	
	return output;
}


int main() {
	
	return 0;
}