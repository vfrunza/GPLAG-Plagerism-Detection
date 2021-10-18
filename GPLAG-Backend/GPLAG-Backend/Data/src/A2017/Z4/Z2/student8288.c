#include <stdio.h>
int provjeri_duzine(char* s1,int* niz, int duzina)
{
	int da=1;
	int i=0;
	int gl_brojac=0;

	while(s1[i]!='\0')
	{
		int brojac=0;



					if((s1[i+brojac]>='A' && s1[i+brojac]<='Z') || (s1[i+brojac]>='a' && s1[i+brojac]<='z'))

		{
		while(1)
			{
			if((s1[i+brojac]>='A' && s1[i+brojac]<='Z') || (s1[i+brojac]>='a' && s1[i+brojac]<='z'))
				{

				brojac++;
				}

			else{
			break;}
	 		}

i+=brojac-1;
if(gl_brojac<duzina)
{

    		if(brojac!=niz[gl_brojac++])
		{
			da=0;
			return da;
		}
		}
		else
            		{
			da=0;
			return da;
		}
		if(s1[i-1] == '\0') break;

		}
		i++;
	}
	if(gl_brojac!=duzina) da=0;
else da=1;
	return da;

}
int main() {

/* AT7: Vise uzastopnih ne-slova razlicitog tipa */
char tekst[] = "Space... The final frontier... These are the voyages of the starship Enterprise. Its five-year mission: to explore strange new worlds, to seek out new life and new civilizations, to boldly go where no man has gone before!";
int niz[] = {5, 3, 5, 8, 5, 3, 3, 7, 2, 3, 8, 10, 3, 4, 4, 7, 2, 7, 7, 3, 6, 2, 4, 3, 3, 4, 3, 3, 13, 2, 6, 2, 5, 2, 3, 3, 4, 6};
int niz2[] = {1,2,3,4,5}; /* reda radi */

printf("%d ", provjeri_duzine(tekst, niz, 4));
printf("%d ", provjeri_duzine(tekst, niz, 38));
printf("%d ", provjeri_duzine(tekst, niz2, 5));
}