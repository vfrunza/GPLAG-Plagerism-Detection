#include <stdio.h>
void unesi (char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i < velicina -1 && znak != '\n')
    {
        niz[i] = znak;
        znak = getchar();
        i++;
    }
    niz[i] = '\0';
}

void najduzi_bp(char* s1, char* s2)
{
	int poz = 0, vel = 0, br = 0;
	char* poc = s2;
	char* pom = s1;
	bool test = true;
	while(*s1 != '\0'){
	    if(isalpha(*s1)){
	        pom = s1;
	        do{ 
	            while(br<vel){
	                
	            }
	            s2 = s1;
	            vel++;
	            s1++;
	            s2++;
	        }while(test);
	    }
	}
}

/*int broj_rijeci2(char *poc, char *kraj)
{
    int brojac = 0;
    while (poc < kraj)
    {
        brojac++;
        poc++;
    }
    return brojac;
}

void provjeri_duzine (char *s)
{
    int brojac = 0, slova, niz[10] = {0}, i;
    int max = 0;
    char *p, *q;
    
        while (*s != '\0')
        {
            if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) 
            {
                p = s;
                while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) s++;
                q = s;
                
                //s--;
                
                slova  = broj_rijeci2(p,q); //printf ("%d ", slova);
                if (max < slova) max = slova;
                //printf ("max: %d ", max);
                brojac++;
            }
            s++;
           
        }
         printf ("\n");
}*/

int main() 
{
    /*char s[100];
    printf ("Unesite string: ");
    unesi(s,100);
    printf ("Svaka rijeci u ovom stringu ima: ");
    provjeri_duzine(s); printf ("\n");*/
    return 0;
}
