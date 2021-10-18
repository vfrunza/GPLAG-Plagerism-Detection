#include <stdio.h>


 int slovo (char s)
 {
 	if (s >= 'A' && s <= 'Z') 
 	{
 	return 1;
 	}
 	if (s >= 'a' && s <= 'z')
 	{
 		return 1;
 	}
 	
 	return 0;
 }

    int provjeri_duzine (char *string, int niz[], int vel)
     {
        int	brojac = 0, l = 0;
        while(1)
         {
	       if (brojac == vel)
	         {
		      return 0;
	         }
	          l = 0;
	
	           while (slovo(*string))
	           {
	        	string++;
		        l++;
	           }
	if( l != niz[brojac]) 
	{
		return 0;
	}	
	while( *string != '\0' && !slovo(*string))
	{
	string++;
	}
	if(*string == '\0') break;
	brojac++;
    }
    if(brojac != vel - 1)
      { 
       return 0;
      }
      return 1;
        }

  void unesi (char niz[], int vel)
  {
	char z = getchar();
	if (z == '\n')
	{
	z = getchar();
	}
	int i = 0;
	while (i < vel - 1 && z != '\n')
	{
		niz [i] = z;
		i++;
		z = getchar();
	}
	niz [i] = '\n';
  }
int main() {
char *recenica = "Ovo je neki primjer teksta '\n'";
int p []  = {3,2,4,7,6};
printf ("'\n'");
printf("%d", provjeri_duzine(recenica, p, 5));
return 0;
}
