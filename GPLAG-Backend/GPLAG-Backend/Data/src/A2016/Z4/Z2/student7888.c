#include <stdio.h>

	void unesi (char niz[], int velicina)	{
		char znak = getchar();
		if (znak == '\n') znak = getchar();
		int i = 0;
		
		while(i < velicina-1 && znak != '\n')	{	niz[i] = znak;
			i++;
			znak = getchar();
		}
		
		niz[i] = '\0';
	}
	
	char* kodiraj (char* niz, char* niz1)	{
		int brojac,brojac2;
		char* s = niz;
		char* p = niz;
		char temp;
		char* i = niz1;
		char* j = niz1;
		int asci = 32;
		char niz2[1000];
		char *x ;
		char *y ;
		char *z ;
		char *izbaci;
		char* t;
		char* ret = niz1;
		int v = 0;
		int bobgraditelj;

			while ( *s != '\0')	{
				niz2[v] = *s;
				v++;
				s++;
			}
				niz2[v] = '\0';
				s = niz;
		
		 x = niz2;
		 y = niz2;
		 z = niz2;
		 t = niz2;
		 izbaci = niz2;
			while(1)	{
				if (asci == 127)	{
					*i = '\0';
					break;
				}
				*i=asci;
				asci++;
				i++;
			}
				
				i = niz1;
				
					while (*x != '\0')	{
								y = niz2;
								brojac = 0;
						while ( *y != '\0')	{
							if ( *y == *x) 	brojac++;
							y++;
						}
						
						while (*z != '\0')	{
							while ( *z == *x ) z++;
								brojac2 = 0;
								t = niz2;
								
						while ( *t != '\0')	{
							if ( *t == *z)	brojac2++;
							t++;	
						}
							if (brojac2 > brojac)	{
								temp = *x;
								*x = *z;
								*z = temp;
								brojac = brojac2;	
							}
							if (brojac2 == brojac)	{
								if ( *z  > *x )	{
									temp = *x;
									*x = *z;
									*z = temp;
								}
							}
								
						
							z++;
						}
						
							izbaci = x;
							izbaci++;
						while ( *izbaci != '\0')	{
								if ( *izbaci == *x)	{
									
									while (*(izbaci+1) != '\0'){
										*izbaci = *(izbaci+1);
										izbaci++;
									}
										*izbaci = '\0';
										izbaci = x;
								}
									
									izbaci++;
						}
						
						x++;
					}
						
							x = niz2;
							j = i;
					while ( *x != '\0')	{
						
						while ( *i != '\0')	{
							if ( *x == *i)	{
								while ( *(i+1) != '\0')	{
									*i = *(i+1);
									i++;
								}
									*i = '\0';
								if ( *i == '\0') break;	
							}
								i++;
						}
							i = j;
						while ( *i != '\0')	i++;
							
						while ( i > j)	{
							*(i+1) = *i;
							i--;
						}
							*i = *x;
							x++;
							j++;
						
					}
							i = niz1;
							s = niz;
							
						while ( *s != '\0')	{
							
							bobgraditelj = 0;
							
							while ( *i != '\0')	{
							if ( *s == *i)	break;
							bobgraditelj++;	
							i++;
							
							}
							
							i = niz1;
							*s = 126 - bobgraditelj;
							s++;
						}	
						
						return ret;
				}
	

	
					
		
		
	

int main() {
	char niz[1000];
	char niz1[1000] ;
	unesi (niz,1000);
	printf (" %s ", kodiraj(niz,niz1));
	return 0;
}