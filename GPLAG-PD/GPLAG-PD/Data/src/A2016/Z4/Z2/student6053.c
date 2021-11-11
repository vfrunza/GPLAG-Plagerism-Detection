#include <stdio.h>
char* kodiraj(char* string_1, char* string_2 ){
char* a=string_1;
char* b=string_1;
int i;
int j;
int max=0;
int br [95] = {0};
char* string_string = string_2;
int nesto;


while (*b != NULL ) { 
	for(i=0; i<95; i++) {
		if(*b == i+32 ) 
		br [i] ++;
		
	}
	
	b++;
}

for(i=0; i<96;i++) {
	for (j=0;j<95; j++){
		if(br[max]<br[j])
		max = j;
		
	}
	*string_2 = max+32;
	string_2 ++;
	br[max] = -1;
	max=0;
	
	}
	*string_2 = NULL;
	string_2 = string_string;
	while (*a != NULL) {
		while(*a != *string_string)
		string_string++;
		
		nesto = string_string - string_2 ;
		*a=126-nesto;
		string_string=string_2;
		a++;
		
		
		
	}
	return string_1;
}

char* dekodiraj(char* string_1, char* string_2 ){
	char* m=string_1;
	char* n=string_2;
	int varijabla;
	int i;
	while (*m != NULL){
	varijabla=126-*m; 
	for(i=0;i<varijabla;i++)
		n++;
	
	*m=*n; 
	n=string_2;
	m++;
	
	}
	return string_1;
}
int main() {
int i;	
char string [] = "LLMLNLNMONM";
char niz_1 [500] = " ";
char niz_2 [500] = " ";

printf ("%s",kodiraj(string,niz_1));
for(i=0;i<10;i++);
printf("%c", niz_1 [i]);
printf ("%s",kodiraj(string, niz_2));
for(i=0;i<10;i++);
printf("%c", niz_2 [i]);
printf("%s",dekodiraj(string,niz_2));
printf("%s",dekodiraj(string,niz_1));




	return 0;
}
