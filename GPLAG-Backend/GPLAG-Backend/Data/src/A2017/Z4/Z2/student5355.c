#include <stdio.h>


int provjeri_duzine(char*s, int niz[], int duzina)
{
	int i=-1, brojac=0; 
	int j=0, brojach=0, provjeri=0;
	char *p=s;
	
	while(*s != '\0') {
		if (((*s>='A'&&*s<='Z') || (*s>='a' && *s<='z')) &&(*s !=' '))
		{

brojach++;
	s++;
	provjeri=1;
	}
	else if((*s<'A' || *s>'Z') || (*s<'a' && *s>'z'))
	{
		brojach=0;
		if(provjeri == 1) j++;
		provjeri = 0;
		s++;
	}
	
}
s--;
if(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && (*s != ' '))
j++;
 if(j!=duzina) return 0;
 provjeri = 1;
 
 while(*p != '\0'){
 	
 	if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (*p != ' '))
 	{
 	brojac++;
 	p++;
 	if(provjeri ==1){
 		i++;
 	}
 	provjeri = 0;
	
} else if ((*p<'A' || *p>'Z') || (*p<'a' && *p>'z')){
	
	if(provjeri==0){
		p--;
	}
	
	if(((*p>='A' && *p<='Z') ||(*p>='a' && *p<='z')))
	if (brojac != niz[i]) return 0;
	if(provjeri == 0) {
		p++;
	}
	brojac=0;
	provjeri = 1;
	p++;
}
}
 return 1;
}

int main () {
	
	return 0;
}