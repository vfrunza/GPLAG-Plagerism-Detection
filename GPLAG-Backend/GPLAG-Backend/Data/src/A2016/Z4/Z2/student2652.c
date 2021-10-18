#include <stdio.h>
char *kodiraj (char *s1, char *s2){
	int max,max1,j,i,seq[96];
	i=0; while (i<96) {
		seq[i]=0;
		i++;
	}
	
	char *p = s1, *q= s2, *r= s2, *return1 = s1;
	while ( *p!='\0') {seq[*p-32]++; p++;}
	j = 0; 
	while (j<95){
		max = -1;
		i = 0;
		while (i<95){
		if (seq[i]>max){max = seq[i]; max1 =i;}
		i++;
		}
		seq[max1]=-1;
		*s2 = max1+32;
		s2++;
		j++;
	}
	while ( *s1 != '\0') {
		q = r;
		i = 0; 
		while (i<95){
			if (*s1 == *q) {
				*s1 = 126 -i;
				break;
			}
			q++;
			if (*q =='\0') break;
			i++;
		}
		s1++;
	}
	return return1;
	}
char* dekodiraj (char *s1, char*s2)
{
	int i, broj = 0;
	char *return1 =s1, *q = s2, *r =s2;
	while (*r !='\0'){
		broj++; r++; }
	while (*s1!='\0'){
		s2 = q;
		i = 0; 
		while (i<broj){
			if (*s1 == 126-i){
				*s1 = *s2;
				break;
			}
			s2++;
			if (*s2 == '\0') break;
			i++;
		}
		s1++;
	}
	return return1;
	} 

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
