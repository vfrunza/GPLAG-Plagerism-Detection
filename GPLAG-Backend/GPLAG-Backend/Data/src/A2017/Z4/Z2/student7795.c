#include <stdio.h>
#include <ctype.h>

/* check arrays function */
int provjeri_duzine(char *input, int arr[], int length) {
	/* initial */
	char *text = input;
	int i = 0, _wordLen = 0, _add = 0, _checkEnd = 0;
	
	/* start going through the array */
	while(*text != '\0') {
		/* go through non-aplhabet values */
		while(!isalpha(*text) && *text != '\0')
			text++;
		
		/* search for a word */
		_add = 0;
		_wordLen = 0;
		while(isalpha(*text)) {
			_wordLen++;
			text++;
			_add = 1;
		}
		
		/* check validity of array 2 */
		if(_add && length < i+1) return 0;
		else if(_wordLen == arr[i] && _add) i++;
		else return 0;
		
		/* check length */
		if(i == length) {
			_checkEnd = 1;
			break;
		}
		
	}
	
	/* check end of string */
	if(_checkEnd) {
		while(*text != '\0') {
			if(isalpha(*text))
				return 0;
			text++;
		}
	}
	
	/* undersized char array */
	if(i < length)
		return 0;

	return 1;
}

int main() {
	return 0;
}