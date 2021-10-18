#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* neutral elements in html */
#define BRSTR	"<BR>"
#define BRSTRT	"<BR/>"

/* struct for nodes for html tags */
struct Node {
	int type;
	int index;
	char tag[100];
};

/* find an open or a closed tag in a string */
struct Node tag_type(char html[], int _SIZE, int pos) {
	/* initial */
	struct Node _izlaz = {0, -1};
	char *output = _izlaz.tag;
	int i = 0, j = 0, _valid = 0, _shift = 0;
	
	/* both open and closed tag is formed <TAG> but with different type in structure */
	for(i = pos; i < _SIZE-1; i++) {
		if(html[i] == '<') {
			
			if(html[i+1] == '/') _valid = 1;
			else if(html[i+1] != '/') _valid = 2;
			else _valid = 0;
			
			if(_valid) {
				j = i;
				while(html[j] != '\0' && (j < _SIZE && html[j] != '>')) {
					*output++ = toupper(html[j+_shift]);
					j++;
					if(j == i+1 && _shift != -1 && _valid == 1)
						_shift = 1;
				}
				if(html[j] == '>') {
					if(_valid != 1) 
						*output++ = '>';
					*output = '\0';
					
					_izlaz.type = _valid;
					_izlaz.index = j;
					return _izlaz;
				}
				else break;
			}
		}
	}
	return _izlaz;
}

/* FUNCTION TO CHECK VALIDITY OF HTML CODE */
int provjeri(const char* edit) {
	/* initial */
	struct Node* _arrCheck;
	struct Node _temp = {0,0};
	
	char *html = malloc((strlen(edit)+1)*sizeof(char));
	char *temp_html;
	
	int _opened = 0, _SIZE = 0;
	int _TAGS = 0, i = 0;
	
	/* go through array and add tags to stack */
	while(*edit != '\0') {
		/* find a tag */
		if(*edit == '<') _opened = 1;
		else if(*edit == '>') {
			html[_SIZE++] = *edit;
			_opened = 0;
		}
		/* remove all text from html tags; add tags */
		if(_opened == 1) {
			while(*edit != ' ' && *edit != '>') html[_SIZE++] = *edit++;
			edit--;
			_TAGS++;
			_opened = 0;
		}
		edit++;
	}
	html[_SIZE++] = '\0';

	/* reallocate array to save memory */
	temp_html = realloc(html, (strlen(html)+1)*sizeof(char));
	if(temp_html == NULL) {
		/* memory leak problem */
		free(html);
		return 0;
	}
	else html = temp_html;
	
	/* create tree and check validity of tags in stack */
	_arrCheck = malloc(_TAGS*sizeof(struct Node));
	do {
		_temp = tag_type(html, _SIZE, _temp.index);
		if(_temp.index == -1) break;
		
		if(strcmp(_temp.tag, BRSTR) == 0 || strcmp(_temp.tag, BRSTRT) == 0) 
			_TAGS--;
		else
			_arrCheck[i++] = _temp;
	
		/* remove members from stack if same tags with different types */
		if(i >= 2) {
			if(_arrCheck[i-1].type == 1 && _arrCheck[i-2].type == 2) {
				if(strcmp(_arrCheck[i-1].tag, _arrCheck[i-2].tag) == 0) {
					
					/* check if valid tag */
					if(strlen(_arrCheck[i-1].tag) > 2) {
						_TAGS = _TAGS - 2;
						i = i - 2;
					}
				} 
			}
		}
	} while(_temp.index != -1);
	
	/* free memory */
	free(_arrCheck);
	free(html);
	
	/* validity return */
	if(_TAGS != 0)
		return 0;
	return 1;
}

int main() {
	return 0;
}