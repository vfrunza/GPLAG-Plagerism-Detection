#include <stdio.h>

int provjeri_duzine(char *s, int p[], int broj){
		
	int br=0, br1=0, br_rijeci=0;
	
	while(*s != '\0'){                              
	
		br=0;
		
	if((*s>=65 && *s<=90) || (*s>=97 && *s<=122)){
		
 		while( (*s>=65 && *s<=90) || (*s>=97 && *s<=122) ){
			s++;
			br++;
		}
		
		br_rijeci++;
	
		if(br != p[br1] )  return 0;
		
		if(*s == '\0') break;
		
		br1++;
	}
	s++;
	}
	
	if(br_rijeci != broj) return 0;
	
	return 1;
}

int main() {
	int niz[5]={2,3,4,2,1};
	char s[100]={"ja sam maid je o"};
	provjeri_duzine(s,niz,5);
	return 0;
}
