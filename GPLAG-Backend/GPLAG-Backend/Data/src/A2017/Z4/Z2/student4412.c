#include <stdio.h>

int provjeri_duzine(char *s, int *niz, int duzina){
	int broj, i=0, logicka=1;
	 char *p=s;
	while(*p!='\0'){
		if((p==s && ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')))
		|| (((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
		&& (!((*(p-1)>='A' && *(p-1)<='Z') || (*(p-1)>='a' && *(p-1)<='z'))))) {
			//if(i>=duzina) return 0;
			broj=0;
			while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')){
			broj++;
			p++;
			}
			if(broj!=niz[i]){
				logicka=0;
				break;
			}
			p--;
			i++;
		}
		p++;
	}
	if(i!=duzina) return 0;
	return logicka;
}
int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
