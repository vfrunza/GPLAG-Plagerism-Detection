#include <stdio.h>
struct pomocna{
	char*poc;
	int broj;
	char*kr;
	
};

void najduzi_bp(char* s1, char* s2){
struct pomocna niz[100];
char *pocetak;
int duzina,max,i=0,j,mjesto;
char*kraj;
char* dupli;

	char*dupli_pocetak;
	char*p;
	dupli_pocetak=s1;
	while(*(dupli_pocetak+1)!='\0') {
		dupli=dupli_pocetak+1;
		while(*dupli != '\0' && *dupli != ' ') {
		
			if(*dupli_pocetak==*dupli || *dupli_pocetak+32==*dupli || *dupli_pocetak+32==*dupli+32 || *dupli_pocetak==*dupli+32) {
				char *spremi = 0;
				if(*(dupli + 1) != '\0')
				{
					p=dupli+1;
					spremi = dupli;
					while(*p!='\0') 
					{
						*dupli=*p;
						p++;
						dupli++;
					}
					*dupli='\0';
				}
				else
				{	*dupli = '\0';
					break;
				}
				if(spremi != 0)
				{
					dupli = spremi;
					dupli--;
				}
			}
			dupli++;
		}
		dupli_pocetak++;
	}
	


while(*s1!='\0'){
   while(*s1!='\0' && (*s1<='9' && *s1>='0' ) || (*s1<=64  && *s1>=32) || (*s1>90 && *s1<=96)  ){
   	s1++;
   }
	duzina=0;
	niz[i].poc=s1;
	while(*s1!='\0' && ((*s1>64 && *s1<91) || (*s1>96 && *s1<124)) && *s1!=' '){
	duzina++;
	s1++;
	}

niz[i].kr=s1;
niz[i].broj=duzina;
i++;
}
max=niz[0].broj;
for(j=0;j<i;j++){
	if(niz[j].broj>max){
		max=niz[j].broj;
		mjesto=j;
	}
	
}
pocetak=niz[mjesto].poc;
kraj=niz[mjesto].kr;

while(*pocetak!=*kraj){
	*s2=*pocetak;
	pocetak++;
	s2++;
}
*s2='\0';
}

int main() {
	
   char niz1[10];
   char pomocni[]={"Abcdef predsjed bcdefg"};
        najduzi_bp (pomocni, niz1);
        printf ("Niz: '%s'\n", pomocni);
        printf ("Niz: '%s'", niz1);
  
	return 0;
}
