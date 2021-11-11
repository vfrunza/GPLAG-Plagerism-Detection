#include <stdio.h>

void kodiraj(char *s, char *tabela)
{
	char *p_tabela=tabela, *s_pocetak=s;
	int niz_brojaca[100]={0};
	int i=0;
	
	for(i=32;i<127;i++)
	{
		*p_tabela=i;
		p_tabela++;
	}
	*p_tabela='\0';
	
	p_tabela=tabela;
	
	while(*s_pocetak!='\0')
	{
		for(i=0;i<=96;i++)
		{
			if(*s_pocetak=='')
		}
		s_pocetak++;
	}
	
	
	
}


int main() {
	return 0;
}
