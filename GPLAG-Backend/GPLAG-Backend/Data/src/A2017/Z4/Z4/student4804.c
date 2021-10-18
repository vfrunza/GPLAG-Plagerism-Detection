#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 


int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}

int funkcija(int* p,int vel){
	int zadnja,prva
	int broj = 0;
	int i;
	for (i =0;i<vel;i++){
		int temp = *(p+i);
			if (temp < 0){
				temp = -temp;
			}
		prva = temp %10;
		zadnja = temp %10;
		
	}
}

int razmak (char* string)
	{
		int i = 0;
		while (*(string + i) != '\0')
			{
				if (*(string+i) == ' ')
					return 1;
				i++;
			}
		return 0;
	}