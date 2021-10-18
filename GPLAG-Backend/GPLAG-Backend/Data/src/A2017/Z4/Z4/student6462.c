#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Rad sa Stackom - prototipi */
struct stack_entry {
	char *data;
	struct stack_entry *next;
};

struct Stack {
	struct stack_entry *top;
	int size;
};

/* Pseudo konstruktor */
struct Stack* newStack();
/* kreira string u memoriji i vraca pokazivac na taj string */
char *cpystr(char*);
/* dodaje novi clan na stack */
int push(struct Stack*, char*);
/* vraca string koji se nalazi na vrhu stack-a */
char *top(struct Stack*);
/* brise clan na vrhu stack-a */
void pop(struct Stack*);
/* provjerava da li je stack prazan */
int empty(struct Stack*);
/* ispraznjava stack */
void clear(struct Stack*);
/* brise stack iz memorije */
void destroy(struct Stack*);
/* end Stack */

/* Prototipi funkcija za zadatak */
int provjeri(char*);

int main() {
	
	return 0;
}

/* provjeri - IMPLEMENTACIJA */
int provjeri(char *s) {
	struct Stack *checker = newStack();
	char *ctrlPtr, *lastOpened, *tmp;
	int currTagLen, i;
	
	while(*s != '\0') {
		if (*s == '<' && *(s + 1) == '/') {
			s += 2;
			
			lastOpened = top(checker);
			//printf("\\%s\n", lastOpened);
			if (lastOpened == NULL) {
				destroy(checker);
				return 0;
			}
				
			while(isalnum(*s) && *lastOpened != '\0')
				if (tolower(*s++) != *lastOpened++) {
					//printf("Pada na %c != %c\n", *s, *lastOpened);
					destroy(checker);
					return 0;
				}
					
			if (isalnum(*s) || *lastOpened != '\0') {
				destroy(checker);
				return 0;
			}
			
			pop(checker);
		}
		else if (*s == '<') {
			s++;
			
			ctrlPtr = s;
			currTagLen = 0;
			
			while(isalnum(*ctrlPtr++))
				currTagLen++;
				
			if (currTagLen == 0) {
				destroy(checker);
				return 0;
			}
				
			tmp = malloc(currTagLen + 1);
			if (tmp == NULL) {
				destroy(checker);
				return -1; /*fail*/
			}
				
			for(i = 0; i < currTagLen; i++, s++)
				tmp[i] = tolower(*s);
			tmp[currTagLen] = '\0';
			
			//printf("%s\n", tmp);
			push(checker, tmp);
			free(tmp);
		}
		
		s++;
	}
	//printf("\n");
	
	if (!empty(checker)) {
		destroy(checker);
		return 0;
	}
	
	destroy(checker);
	return 1;
}
/* END provjeri */

/* Stack "metode" - IMPLEMENTACIJA */
/* Ako na ovo sumnjate, branit cu slobodno... ali mi je stvarno mrsko pisati
   dokumentaciju za ovakvo nesto, previse je standardno, obicna linked lista
   koja ima uvijek pokazivac na posljednji element */
struct Stack* newStack() {
	struct Stack *tmp = malloc(sizeof *tmp);
	
	if (tmp != NULL) {
		tmp->top = NULL;
		tmp->size = 0;
	}
	
	return tmp;
}

char *cpystr(char* value) {
	char *tmp = malloc(strlen(value) + 1);
	if (tmp != NULL)
		strcpy(tmp, value);
		
	return tmp;
}

int push(struct Stack *S, char *newEntry) {
	struct stack_entry *tmp = malloc(sizeof *tmp);
	
	if (tmp != NULL) {
		tmp->data = cpystr(newEntry);
		tmp->next = S->top;
		S->top = tmp;
		S->size++;
		
		return 1;
	}
	
	return 0;
}

char *top(struct Stack *S) {
	if (!empty(S))
		return S->top->data;
		
	return NULL;
}

void pop(struct Stack *S) {
	if (!empty(S)) {
		struct stack_entry *tmp = S->top;
		S->top = S->top->next;
		
		free(tmp->data);
		free(tmp);
		
		S->size--;
	}
}

int empty(struct Stack *S) {
	if (S != NULL && S->top != NULL && S->size != 0)
		return 0;
		
	return 1;
}

void clear(struct Stack *S) {
	while (!empty(S))
		pop(S);
}

void destroy(struct Stack *S) {
	clear(S);
	free(S);
}