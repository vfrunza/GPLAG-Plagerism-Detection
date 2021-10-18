#include <stdio.h>
#include <ctype.h>

void najduzi_bp(char *s1, char *s2)
{
	int brojaci[128] = {0}, duzina = 0, max = 0, i = 0;
	char *p = s1;
	while (*p != '\0')
	{
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
		{
			duzina = 0;
			int a = 0;
			for (a = 0; a < 128; a++) brojaci[a] = 0;
			i = 0;
			char pomocni[1000];
			while (*p != '\0' && ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')))
			{
				if (brojaci[toupper(*p)] == 0) 
				{ 
					brojaci[toupper(*p)]++;
					pomocni[i++] = *p;
					duzina++; 
					p++;
				}
				else break;
				pomocni[i] = '\0';
				
			}
			if (duzina > max) 
			{ 
				max = duzina;
				char *jbmti = pomocni;   // jbmti ce bit zz, a jbmtidvaput zz2
				char *jbmtidvaput = s2;
				while (*jbmti != '\0') 
				{
					*jbmtidvaput = *jbmti;
					 jbmti++; jbmtidvaput++;
				}
				*jbmtidvaput = '\0';
				
			}
		}
		p++;
	}
}

int main() {
	    {//AT1
        char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);
    	}//Niz: 'primje'
	return 0;
}
