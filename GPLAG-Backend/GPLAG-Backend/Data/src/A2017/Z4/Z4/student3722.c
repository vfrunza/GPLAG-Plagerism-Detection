#include <stdio.h>

int provjeri(char *s){
    char p1[1000];
    char p2[1000];
	int i=0;
	int j=0;
	int k=0;
	int brojac=0;
	int k_ov;
	int brojac2=0;
	int beze;
	while(*(s+i)!='\0'){
		if(*(s+i)=='<') brojac++;
		i++;
	}
	if(brojac%2!=0) return 0;
	
	i=0;
	while(*(s+i)!='\0'){
		if(*(s+i)=='<' && *(s+i+1)!='/'){
			while(*(s+i)!='>'){
				*(p1+j)=*(s+i);
				j++;
				i++;
			}
			*(p1+j)='>';
			j++;
		}
		i++;
		
	}
	*(p1+j)='\0';
	i=0;
	while(*(s+i)!='\0'){
		if(*(s+i)=='<' && *(s+i+1)=='/'){
			while(*(s+i)!='>'){
				*(p2+k)=*(s+i);
				k++;
				i++;
			}
			*(p2+k)='>';
			k++;
		}
		i++;
	}
	*(p2+k)='\0';
	
	
}
int main(){
	char string[100]="<b><a>proba</b></a>";
	int rezultat;
	rezultat=provjeri(string);
	printf("Konacni rezultat je %d", rezultat);
	return 0;
}