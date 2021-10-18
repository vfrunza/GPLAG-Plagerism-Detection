#include <stdio.h>
#include <ctype.h>

int provjeri(char *s){
	char *p=s; int i;
	char niz[100][100]={{"\0"}}; // matrica
	int velicina=0; 
	
	while (*p!='\0') {
		if(*p=='<'){ 	p++; 
		// ako nismo na kraju i nismo na /
			if(*p!='\0' && *p!='/'){
				char *c=niz[velicina], *c2=niz[velicina];
				
				while (*p!='\0'&&(*p!=' ' && *p!='>')) {
					(*c++)=tolower(*p++); //ovdje smjestimo taj stingu u c da dole mozemo porediti
				}
				*c='\0'; //moze i bez ovoga 
				
				velicina++;// na kraju kad smjestimo taj string stavimo \0 da je kraj stringa 
			} 
			//ako nismo na kraju i ako je 
			
			else if(*p!='\0' && *p=='/'){
			if(velicina==0) return 0; // ako nismo nista upisali nego je npr odmah stoji / 
			char *c=niz[velicina-1]; 
			
		//	printf("pa ovo %s", c);
			int isti=1; 
			if(*p!='\0')   p++;  //preskacem ovo '/'
			if(*p==' ' || *p=='>') return 0; 
				 
			while (*p!='\0' && (*p!=' ' && *p!='>')) {
				 	if(*c!=tolower(*p)) isti=0; 
				 	c++; p++; 
				 	if(*c=='\0')  break; //Ako je div </divota> treba biti 0 jer nije tacno
				 }
			if(isti==1 && (*p==' ' || *p=='>')) velicina--;
			else return 0; 
			}
			
		} 
	if(*p=='\0') break; // ako nsmo nasli nikad otvoreno <
	p++;
	}
	//for(i=0; i<velicina; i++)
	if(velicina==0) return 1; 
	return 0; 
}


int main() {
	
printf (" %d\n", provjeri (" "));

	return 0;
}
