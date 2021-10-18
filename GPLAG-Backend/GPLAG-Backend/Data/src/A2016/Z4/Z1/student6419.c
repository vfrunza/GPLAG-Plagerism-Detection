#include <stdio.h>

#include <ctype.h>

void izbaci(char *q, char *k, char *p) {
        char proba[100];
        int i=0;
        int j=0;
        char* a;
        char* b;
        while(q!=k && i<100) {
            proba[i]=*q;
            i++;
            q++;
        }
        proba[i]='\0';
        while(*p!='\0') {
            if((*p>='a' && *p<= 'z') ||  (*p>= 'A' && *p<='Z')) {
                j=0;
                q=p;
                while((*p>='a' && *p<= 'z') ||  (*p>= 'A' && *p<='Z')) {
                    j++;
                    p++;
                }
                k=p;
                if(i!=j) continue;
                a=proba;
                b=q;
                j=0;
                while(*a!='\0') {
                    if(toupper(*a)!=toupper(*q)){
                            j=1;
                            break;
                    }
                    a++;
                    q++;
                }
                if(j) continue;
                p=b;
                while(*k!='\0') {
                    *b=*k;
                    b++;
                    k++;
                }
                *b='\0';
            }
            else
                p++;
        }
    }
int funkcija(char *p, char *k, char *s) {
	int broj=0;
	int i=0;
	int j=0;
	char proba[100];
	while(p!=k && i<100) {
		proba[i]=*p;
		i++;
		p++;
	}
	proba[i]='\0';
	while(*s!='\0') {
		if((*s>='a' && *s<= 'z')  ||  (*s>= 'A' && *s<='Z')) {
			p=s;
			j=0;
			while((*p>='a' && *p<= 'z')  ||  (*p>= 'A' && *p<='Z')) {
				p++;
				j++;
			}
			if(i!=j) {
				s=p;
				continue;
			}
			k=proba;
			j=0;
			while(*k!='\0') {
				if(toupper(*k)!=toupper(*s)) {
					s=p;
					j=1;
					break;
				}
				k++;
				s++;
			}
			if(j)
				continue;
			broj++;
		}
		else s++;
	}
	return broj;
}
char* izbaci_najcescu(char* s){
	int naj=-1, brojac=0;
	char* p=s;
	char* q=s;
	char* k=s;
	char* poc = s;
	char* kraj=s;
	if(*s=='\0')
		return s;
	while(*s!='\0') {
		poc=s;
		if((*s>='a' && *s<= 'z')  ||  (*s>= 'A' && *s<='Z')) {
			while((*s>='a' && *s<= 'z') ||  (*s>= 'A' && *s<='Z')) {
				s++;
			}
			kraj=s;
			brojac = funkcija(poc, kraj, s);
			if(brojac>naj) {
				naj=brojac;
				q=poc;
				k=kraj;
			}
		}
		else
			s++;
	}
	izbaci(q, k, p);
	return p;
}
int main(){
char t[]="";
printf("'%s'", izbaci_najcescu(t));
	return 0;
}