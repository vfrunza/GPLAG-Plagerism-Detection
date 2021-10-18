#include <stdio.h>
void unesi(char niz[], int velicina){
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

void najduzi_bp(char* s1, char* s2){
	int i=0, br=1, max=0;
	while(*s1!='\0'){
		if(*s1>='A'&& *s1<='Z'){
			char* p=(s1+1);
			while((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')){
				if(*s1!=*p && *s1!=*p+32) br++;
				p++;
			}
		}
			
		if(*s1>='a'&& *s1<='z'){
			char* p=(s1+1);
			while((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')){
				if(*s1!=*p && *s1!=*p-32) br++;
				p++;
			}
		}
			
			if(br>max){
				max=br;
				for(i=0; i<br; i++)
					*(s2+i)=*(s1+i);
			}
		br=1;
		s1++;
	}
}
int main() {
	char s1[100], s2[100];
	printf("Unesite tekst: ");
	unesi(s1,100);
	najduzi_bp(s1,s2);
	printf("%s",s2);
	return 0;
}
