#include <stdio.h>

int  provjeri_duzine(char *tekst, int* niz, int x){
	int i=0, k=0,j=0;
	char* p=tekst;
	while (p[i]!='\0') {
		j=0;
		if((p[i]>='a' && p[i]<='z') || (p[i]>='A' && p[i]<='Z')){
			while((p[i]>='a' && p[i]<='z') || (p[i]>='A' && p[i]<='Z')){
				j++;		
				i++;
			}	
			if(k==x)return 0;
			if(niz[k]!=j)return 0;
			k++;
			
		}
		if(p[i]!=0)i++;		
	}
if(k!=x)return 0;
return 1;

}


int main () {

	return 0;
}