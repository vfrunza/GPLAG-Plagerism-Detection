#include <stdio.h>

int provjeri_duzine (char s [], int niz [], int y) 
{
    int i=0; 
    int j=0;
    int x=0;
    int brojac=0;
    
    for (i=0; i<y; i++)
    {
        if ( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') )
        brojac++;
        
        else 
        {
            if (brojac==niz[j])
            {
                x=1;
                j++;
                brojac=0;
                if (j>=y)
                break;
            }
            
            else 
            {
                x=0;
                break;
            }
        }
    }
return x;
}

void unesi(char niz [], int velicina) {
	int i=0;
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	while (i<velicina - 1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
niz[i]='\0';
}


int main ()
{
    int i=0; 
    int niz[400];
    char a[1000];
    int y;
    unesi(a,1000);
    for (i=0; i<400; i++)
    scanf ("%d", &niz[i]);
    scanf ("%d", &y);
    printf("%d", provjeri_duzine(a, niz, y));
return 0;
}