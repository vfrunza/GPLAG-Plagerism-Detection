#include <stdio.h>

	int provjeri_duzine (char* tekst, int niz[], int vel){
		char* pom=tekst;
		int brojac,i=0;
		int brda=0;
		int da=0;
		
		while(*pom!='\0'){
			da=0;
			brojac=0;
		
			
			if((*pom>='a' && *pom<='z') || (*pom>='A' && *pom<='Z')){
				da=1;
				while(((*pom>='a' && *pom<='z') || (*pom>='A' && *pom<='Z')) && *pom!='\0'){
					pom++;
					brojac++;
				}
			}
			
			if(*pom=='\0') pom--; 
			if(i==vel) return 0;
			if(brojac==niz[i]) brda++;
			if(da){
			i++;
			}
			
			pom++;
			
		}
		
		if(brda==vel) return 1;
		else return 0;
	}

int main() {
char tekst[] = "Kakav je ovo test!?!?";
int niz[] = {5,2,3,4};

printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}
