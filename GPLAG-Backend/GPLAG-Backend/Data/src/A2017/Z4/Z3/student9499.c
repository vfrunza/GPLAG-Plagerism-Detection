#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to find biggest subarray of non-repeating characters */
void najduzi_bp(char* s1, char* s2) {
	/* initial */
	int _maxLen = 0, num = 0;
	char *str = s1;
	char *start = s1;
	char *end = s1;
	char *cut = str;
	char *_newStr = s2;
	
	/* start searching */
	while(*str != '\0') {
		
		/* create initial array for char count */
		int arr['Z'] = {0};
		
		/* put pointers */
		cut = str;
		_newStr = s2;
		
		/* start searching for a subarray of chars */
		while(isalpha(*cut)) {
			/* lower -> upper | not case-sensitive */
			num = toupper(*cut); 
			arr[num]++;
			if(arr[num] > 1) break;  
			
			*_newStr++ = *cut++;
		}
		*_newStr = '\0';
		_newStr = s2;
		
		/* find longest subarray */
		if(strlen(_newStr) > _maxLen) {
			_maxLen = strlen(_newStr);
			start = str;
			end = cut;
		}
		str++;
	}
	
	/* rewrite the output string */
	while(start < end) {
		*s2++ = *start;
		start++;
	}
	*s2 = '\0';
}

int main() {
    return 0;
}