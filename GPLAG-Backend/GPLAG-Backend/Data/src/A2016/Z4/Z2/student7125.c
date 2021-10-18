#include <stdio.h>

char *kodiraj (char *s, char tabela[]);
char *dekodiraj (char *s, char tabela[]);
int prebroji (char *s, char znak);
int strcmp(const char *s1, const char *s2);

int main() {
	char t[]= "a";
	char k[100] = "";
	dekodiraj(kodiraj(t,k),k);
	printf("%s",  t);
	
	return 0;
}

int prebroji(char* s, char znak){
    int broj = 0;
    while (*s != '\0') {
        if (*s == znak)
            broj++;
        s++;
    }
    return broj;
}

int strcmp(const char *s1, const char *s2){
	
	while(*s1 != 0 && *s2 != 0){
		
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2) return -1;
		s1++;
		s2++;
	}
	
	if(*s1 != 0) return 1;
	if(*s2 != 0) return -1;
	
	return 0;
}

char *kodiraj (char *s, char tabela[]){
	
	char znak[96], stemp[1];
	int ponov[96] = {-1}, nije_bio = 1, vel = 0, svel = 0 , i = 32, temp, j ;
	char *p = s, *q = s, *k = s, *z = znak, *t = stemp, *tab = tabela;
	int *bp = ponov, *bq = ponov;
	
		
	while(*k != 0){
			
		q = s;
		nije_bio = 1;
			
		while (q < k){
			if(*q == *k)
				nije_bio = 0;
			q++;
		}
		if(nije_bio)
			*z++ = *k;
			k++;
	}
	
		
	*z = '\0';
	z = znak;
					
	while(*z != 0){		
			
		*bp++ = prebroji(s, *z);
		z++;
		svel++;
	}

	bp = ponov;
	z = znak;
		
	while (*bp != 0){
		vel++;
		bp++;
	}
	vel -= 1;
	svel -= 1;
	bp = ponov;
	
	while (*bp != 0){
		bq = ponov + vel;
		k = znak + svel;
		
		while(bq > bp){
			if (*bp < *bq){
				temp = *bp;
				*bp = *bq;
				*bq = temp;
				
				*t = *z;
				*z = *k;
				*k = *t;
			}
			
			else if (*bp == *bq){
				if (strcmp(z,k) == 1){
					*t = *z;
					*z = *k;
					*k = *t;
				}
			}
			
			bq--;
			k--;
	
		}
		bp++;
		z++;
		
	}
	
	z = znak;
	
	while (*z != 0)
		*tab++ = *z++;
	
	while(tab < tabela + 95) {
		
		nije_bio = 1;
		z = znak;
		
		while(*z != 0){
			if(*z == i)
				nije_bio = 0;
				
			z++;
		}
				
			if(nije_bio)	
				*tab++ = i;
				
			i++;
		
	}
	
	*tab = '\0';
	tab = tabela;
	p = s;
	while(*p != 0){
		for (j = 0; j < 95; j++)
			if(*p == tabela[j]){
				*p = 126 - j;
				break;
			}
			
			p++;
	}
	
	*p = '\0';

	return s;
}
	
char *dekodiraj (char *s, char tabela[]){
	char *p = s;
	
	while(*p != 0){
		*p = tabela[126-*p];
		p++;
	}

	return s;
}

