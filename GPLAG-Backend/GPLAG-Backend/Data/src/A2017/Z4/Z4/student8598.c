#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
struct stack_entry {
	char *data;
	struct stack_entry* next;
};

struct stack_t {
	struct stack_entry* head;
};

struct stack_t
*newstack(void)
{
	struct stack_t*stack=malloc(sizeof *stack);
	if(stack) {
		stack->head=NULL;

	}
	return stack;
}

char*copystring(char* str){
	char *tmp=malloc(strlen(str)+1);
	if(tmp)
	strcpy(tmp,str);
	return tmp;
}

void push(struct stack_t *thestack, char* value){
	struct stack_entry *entry=malloc(sizeof *entry);
	if(entry){
		entry->data=copystring(value);
		entry->next=thestack->head;
		thestack->head=entry;
	}
}

char* top(struct stack_t *thestack){
	if(thestack && thestack->head)
	return thestack->head->data;
	else 
	return NULL;
}

void pop(struct stack_t *thestack){
	if(thestack->head!=NULL){
		struct stack_entry*tmp=thestack->head;
		thestack->head=thestack->head->next;
		free(tmp->data);
		free(tmp);
	}
}

void clear(struct stack_t *thestack){
	while(thestack->head!=NULL)
	pop(thestack);
}

void destroystack(struct stack_t **thestack)
{
  clear(*thestack);
  free(*thestack);
  *thestack = NULL;
}

int provjeri(char *htmlkod)
{
	char tag[100];

	struct stack_t *thestack=newstack();
	int i=0,zatvorentag=0,j=0,d=0, k=0, m=0;
		
	for(i=0; i<strlen(htmlkod); i++) {
		if(htmlkod[i]=='<') {
			if(htmlkod[i+1]=='/')
				zatvorentag=1;
			else
				zatvorentag=0;
			j=0;
			if(htmlkod[i+1] == '>') return 0;
			while(htmlkod[i+1+j]!='>') {
				if(htmlkod[i+1+j]==' ') break;
				j++;
			}
			if(j>0) {
				memset(&tag[0],0,sizeof(tag));
				d=0;
				if(zatvorentag)
					j--;
				while(d<j) {
				
					       if(zatvorentag)
						      tag[d]= htmlkod[i+d+2];
					else
						tag[d]=	htmlkod[i+d+1];
					d++;

				}
			}
			if(zatvorentag){
				
				char *data;
				data=top(thestack);
			 for(k=0; k < strlen(data); k++){
				data[k]=data[k]>0x40&&data[k]<0x5b?data[k]|0x60:data[k];
			}
				for (m = 0; m < strlen(tag); m++) {
            tag[m] = tag[m] > 0x40 && tag[m] < 0x5b ? tag[m] | 0x60 : tag[m];
          }
				if(strcmp(data,tag)==0) {
					pop(thestack);
				}
				else {
					  clear(thestack);
				  destroystack(&thestack);
				  char *data =  0;
				  return 0;
				}
				}
					else
					push(thestack,tag);
				}
			}
			if(thestack->head==NULL) {
				  clear(thestack);
					  destroystack(&thestack);
			return 1;
			}
			else {
				  clear(thestack);
				  destroystack(&thestack);
			return 0;
			}
}
int main()
{
	char x[100];
	int a;
	printf("Unesite velicinu stringa: ");
	scanf("%d", &a);
	printf("Unesite html kod: ");
	unesi(x,a);
	printf("%d", provjeri(x));
	return 0;
}