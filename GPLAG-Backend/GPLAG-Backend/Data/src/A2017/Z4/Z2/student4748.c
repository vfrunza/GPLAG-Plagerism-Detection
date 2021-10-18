#include <stdio.h>
int provjeri_duzine (char* s,int niz[],int vel){
	char *temp=s;
	int p=0,brojacr=0,brs=0,i=0;
	while(*s!='\0'){
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			if(p==0){
			brojacr++;
			p=1;
		  }
		}
		else{
			p=0;
		}
	s++;	
	}
	s=temp;
	if(brojacr==vel){
	while(*s!='\0'){
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			brs++;
			s++;
	}   if (i!=vel){
		if(niz[i]==brs){
			i++;
		}}
		brs=0;
		if(*s=='\0'){
			s--;
		}
		s++;
	}
	if(i==vel){
		return 1;
	}
	else{
		return 0;
	}
  }	
  else{
  	return 0;
  }
}
int main (){
char tekst[] = "Kakav je ovo test!?!?";
int niz[] = {5,2,3,4};
int niz2[] = {5,2,3,8};
int niz3[] = {5,2,3,4,0};
printf("%d ", provjeri_duzine(tekst, niz3, 5));
printf("%d ", provjeri_duzine(tekst, niz2, 4));
printf("%d ", provjeri_duzine(tekst, niz, 4));
return 0;
}
