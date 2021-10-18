#include <stdio.h>

void unesi(char niz[],int velicina){
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void najduzi_bp(char* s1, char* s2){
	while(*s1!='\0'){
		
		*s2=*s1;
		
		s1++;
		s2++;
	}
}


int main() {
	char niz1[100];
	char niz2[100];
	printf("Unesite string: ");
	unesi(niz1,100);
	
	
	najduzi_bp(niz1,niz2);
	
	return 0;
}
