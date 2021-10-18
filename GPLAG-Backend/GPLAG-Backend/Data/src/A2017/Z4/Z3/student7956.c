#include <stdio.h>

void unesi (char niz[], int velicina)
{
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}


int ponavlja (char* s)
{
	int niz[200] = {0}, i = 0, j;
	char temp1, temp2;

	while(s[i]!= '\0') {
		j = i + 1;
		temp1 = s[i];

		if(temp1>= 'A' && temp1<='Z')
			temp1 = temp1 + 32;
		niz[temp1- 'a']++;
		while (s[j]!= '\0') {
			temp2 = s[j];

			if(temp2 >= 'A' && temp2 <= 'Z')
				temp2 = temp2 + 32;

			if(temp1 == temp2) {
				niz[temp2 - 'a']++;
				if(niz[temp2-'a']>1) {
					return 1;
				}
			}
			j++;
		}
		i++;

	}
	return -1;
}

int vrati_index(char* s)
{
	int i=0;
	int j=0;
	char temp1, temp2;
	while(s[i]!= '\0') {
		j = i + 1;
		temp1 = s[i];
		if(s[i] >='A' && s[i] <= 'Z') temp1+= 32;
		while (s[j]!= '\0') {
			temp2 = s[j];
			if (s[j] >= 'A' && s[j] <= 'Z')
				temp2+=32;
			if(temp1 == temp2) {
				return j;
			}
			j++;

		}
		i++;

	}
	return 0;
}


void najduzi_bp (char* s1, char* s2)
{
	int duzina1 = 0, duzina2 = 0, i = 0, j = 0, br1 = 0, br2 = 0;
	char pom[1000];

	while(s1[i]!= '\0') {
		j=0;
		while(s1[i] != ' ') {
			pom[j] = s1[i];
			j++;
			i++;
			duzina1++;
			if(s1[i] == '\0') {
				i--;
				break;
			}

		}
		i++;
		pom [j] ='\0';

		if(ponavlja(pom)==1) {
			j=0;
			br1=0;
			br2 = 0;
			while (j<vrati_index(pom)) {
				br1++;
				j++;
			}
			j=0;

			while(pom[vrati_index(pom)+j] != '\0') {
				br2++;
				j++;
			}
			if(br1>=br2) {
				pom[vrati_index(pom)]= '\0';
			} else {
				j=0;
				while(j<=br2) {
					pom[j] = pom[vrati_index(pom)+j];
					j++;
				}
				duzina1 = br2;
				pom[j] = '\0';
			}
		}
		if(duzina1 > duzina2) {
			j = 0;
			while(pom[j] != '\0') {
				s2[j] = pom[j];
				j++;
			}
			duzina2 = duzina1;
			s2[j] = '\0';

		}
		duzina1 = 0;

	}

}

int main()
{
	return 0;
}
