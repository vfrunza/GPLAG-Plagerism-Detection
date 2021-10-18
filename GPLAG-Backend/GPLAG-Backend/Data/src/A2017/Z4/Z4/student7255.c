#include <stdio.h>


int provjeri (char *html)
{
	char* pok = html;
	char *pomocni = pok;
	char ime[100];
	int i;
	int broj_slova = 0;
	char* provjera_atributa = pok;
	int otvoreni = 0;
	int provjera = 1;
	char apostrof = 39;	
	
	while (*pok != '\0')
	{
		if (*pok == '<' && *(pok+1) == '/')
			{
				if (pok == html)
					return 0;
					
				while(*pok != '>')
					pok++;
			}
		
		else if (*pok == '<')
		{
			pomocni = pok;
			broj_slova = 0;
			
			for (i = 0; i < 100; i++)
				ime[i] = '\0';
			
			while(*pomocni != '>')
				{
					if (*pomocni == '\0')
						return 0;
						
					else if (*pomocni == ' ')
						{
							provjera_atributa = pomocni;
							provjera_atributa++;
							
							if (*provjera_atributa == ' ')
								{
									while (*provjera_atributa == ' ')
										provjera_atributa++;
								}
							
							if (*provjera_atributa != '>'){
							while(*provjera_atributa != '=')
								{
									if ((*provjera_atributa>='A' && *provjera_atributa<='Z') || (*provjera_atributa>='a' && *provjera_atributa<='z') || (*provjera_atributa>='1' && *provjera_atributa<='9'))
										provjera_atributa++;
									else
										return 0;
								}
								
							provjera_atributa++;
							if (*provjera_atributa != '"')
								return 0;
								
							provjera_atributa++;
								
							while(*provjera_atributa != '"')
								{
									if ((*provjera_atributa>='A' && *provjera_atributa<='Z') || (*provjera_atributa>='a' && *provjera_atributa<='z') || (*provjera_atributa>='1' && *provjera_atributa<='9'))
										provjera_atributa++;
									else
										return 0;
								}
								
							provjera_atributa++;
							if (*provjera_atributa != '>')
								return 0;
								
							pomocni = provjera_atributa;
							pomocni--;
							}
						}
						
					else if ((*pomocni>='A' && *pomocni<='Z') || (*pomocni>='a' && *pomocni<='z') || (*pomocni>='1' && *pomocni<='9'))
						{
							ime[broj_slova] = *pomocni;
							broj_slova++;
							
						}
						
					pomocni++;
				}
				
			if (broj_slova == 0)
				return 0;
				
			ime[broj_slova] = '\0';
			pok = pomocni;
			otvoreni = 0;
			
			pomocni++;
			while (*pomocni != '\0')
				{
					if (*pomocni == '<' && *(pomocni+1) != '/')
						otvoreni++;
					else if (*pomocni == '<' && *(pomocni+1) == '/')
						{
							pomocni++;
							pomocni++;
							i = 0;
							provjera = 1;
							while (*pomocni != '>')
							{
								if ((*pomocni>='A' && *pomocni<='Z') || (*pomocni>='a' && *pomocni<='z') || (*pomocni>='1' && *pomocni<='9'))
								{
									if (i == broj_slova)
										{
											provjera = 0;
											break;
										}
										
									if (*pomocni != ime[i])
										{
											provjera = 0;
											break;
										}
									
								}
								
								i++;
								pomocni++;
							}
							
							if (provjera == 0)
								otvoreni--;
								
							else
								{
									if (otvoreni != 0)
										return 0;
										
										
									
									break;
								}
							
						}
						
					pomocni++;
					if (*pomocni == '\0')
						return 0;
				}
			
		}
		
		
		
		
	pok++;
	}
	
	
	
	
	
	
	return 1;
}





int main() {
	
	char tekst[100] = "<div>Primjer</div>";
	printf("%d", provjeri(tekst));
	
	
	
	return 0;
}
