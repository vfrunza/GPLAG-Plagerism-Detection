#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
char* izbaci_najcescu(char* s){
	int i=0,brojac[1000],raz=1,br_rijec=0,j;
	char* poc;
	char* a;
	char* b;
	char* c;
	a=s,b=s,c=s;
		while(*a!='\0'){
		while(*b!=' ' && *b!='\n' && *b!='\0' && *b!='-') b++;
			while((*a!=' ' || *a!='\n' || *a!='-') && (*b!=' ' || *b!='\n' || *b!='-')){
			if(*a++==*b++)
			continue;
			else { break; }
		}
		if((*a==' ' || *a=='\n' || *a=='\0' || *a=='-') && (*b==' ' || *b=='\n' || *b=='\0' || *b=='-'))
		brojac[i]++;
		a=c;
		if(*b!='\0'){
			while(*a!=' ' && *a!='\n' && *a!='\0' && *a!='-')
			a++;
			c=++a;
			i++;
			b=a;
		}	
				else
					while(*b++!=' ' && *b!='\n' && *b!='\0' && *b!='-');
					
						}
		
	c=s;
	int max=0;
	for(j=0;j<i;j++){
		if(brojac[max]<brojac[i])
		max=i;
	}
	while(*s!='\0'){
		if(*s==' ' || *s=='-'){
			raz=1;
		}
			else if(raz==1){
				raz=0;
				if(*s==' ' || *s=='-')
				raz=0;
				br_rijec++;
				if(br_rijec==i)
				poc=s;
				if(br_rijec==i+1){
					while(*poc++=*s++);
				
					return c;
				}
			}
			s++;
		}
		if(br_rijec==i)
		*poc=='\0';
		return c;
	

	
}

int main() {
	char s[1000];
	printf("Unesi string: ");
	unesi(s,1000);
	printf("%s",izbaci_najcescu(s));
	return 0;
}
