#include <stdio.h>
void unesi (char*niz,int vel){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(znak!='\n'&& i<vel-1){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
void najduzi_bp(char* s1, char* s2){
	int najduzarijec;
	najduzarijec=*s1;
	
	
	while(*s1!='\0'){
		
	}
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
