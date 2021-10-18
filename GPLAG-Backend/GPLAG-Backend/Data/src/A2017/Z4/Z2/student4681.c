#include <stdio.h>

int provjeri_duzine(char* t, int* b, int size) {
	int result = 1, i, j = 0, count = 1, txtSize = 0, wordSize = 0;
	char previous = *t, *first = t;
	t++;
	while(*t!='\0') {
		txtSize++;
		if((*t == ' ' && ((previous>64 && previous<91) || (previous>96 && previous<123))) || (!((*t>64 && *t<91) || (*t>96 && *t<123)) && ((previous>64 && previous<91) || (previous>96 && previous<123)))) {
			wordSize++;
		}
		previous = *t;
		t++;
		if(*t=='\0' && ((previous>64 && previous<91) || (previous>96 && previous<123))) wordSize++;
	}

	t = first;
	previous = *t;
	t++;
	for(i=0; i<txtSize; t++) {
		if(j >= size) return 0;
		if((*t == ' ' && ((previous>64 && previous<91) || (previous>96 && previous<123))) || (!((*t>64 && *t<91) || (*t>96 && *t<123)) && ((previous>64 && previous<91) || (previous>96 && previous<123)))) {
			if(*b != count) {
				return 0;
			} else {
				b++;
				if(*t == ' ' && ((previous>64 && previous<91) || (previous>96 && previous<123)))
					j++;
			}
		}
		if(wordSize != size) return 0;
		if((*t>64 && *t<91) || (*t>96 && *t<123))  {
			count++;
		} else {
			count = 0;
		}
		previous = *t;
//	if(*t == '\0') return 0;
		i++;
	}
	return result;
}

int main() {
	return 0;
}
