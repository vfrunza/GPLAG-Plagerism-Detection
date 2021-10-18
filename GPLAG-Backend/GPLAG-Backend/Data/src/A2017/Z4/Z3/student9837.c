#include <stdio.h>
#include <string.h>
#include <ctype.h>


int Slovo(char x)
{
	if((x >= 'a' && x <= 'z') || (x >='A' && x<='Z'))return 1;
	return 0;
}

void najduzi_bp(char* s1, char* s2)
{
	int i=0;
	int j=0;
	int k=0,m=0;
	int max_duzina=0, max_index=0;
	int brojaci[26];
	while(s1[i]!=0) {
		j=i+1;
		memset(brojaci, 0, sizeof(brojaci));
		m=0;
		while(Slovo(s1[j]) && s1[j]!=s1[i] && s1[j]!=tolower(s1[i]) && Slovo(s1[i]) ) {
			brojaci[tolower(s1[j])-'a']++;
			for(k=0; k<26; k++)
				if(brojaci[k]>1)m=1;
			if(m==1)break;
			j++;
		}

		if(j-i>max_duzina ) {
			max_duzina=j-i;
			max_index=i;
		}
		i++;
	}

	strncpy(s2,s1+max_index,max_duzina);

	s2[max_duzina]=0;
}

int main()
{
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
