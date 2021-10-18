/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
bool DaLiJeSlovo(char c)
{
	if((c>='A' && c<='Z')||(c>='a' && c<='z')) return true;
	return false;
}

bool Test_Rijeci(std::vector<std::string> rijeci)
{
	for(int i=0;i<rijeci.size();i++)
	{
		std::string pomocni(rijeci[i]);
		for(int j=0;j<pomocni.length();j++)
		{
			if(!DaLiJeSlovo(pomocni[j]) && pomocni[j]!=' ' && pomocni[j]!=',' && pomocni[j]!='.') return false;
		}
	}
	return true;
}




std::string ObrniString(std::string string)
{
	std::string novi_string="";
	for(int i=string.size()-1;i>=0;i--)
	{
		novi_string+=string[i];
	}
	return novi_string;
}
	
bool DaLiSeNalazi(std::string recenica, std::string rijec)
{
	int brojac=0;
	for(int i=0;i<recenica.length();i++)
	{
		if(i!=(int)recenica.length()-1)
		{
			int brojac_slova(0);
			if(DaLiJeSlovo(recenica[i]))
			{	
				
				while(recenica[i]==rijec[brojac])
				{
					if(i==(int)recenica.length()-1) break;
					i++;
					brojac++;
					brojac_slova++;
				}
				if(DaLiJeSlovo(recenica[i])) brojac_slova++;
				if(i-brojac-1>=0)
				{
					if(DaLiJeSlovo(recenica[i-brojac-1])) brojac_slova++;
				}
				int vel=rijec.length();
				if(brojac==vel && !DaLiJeSlovo(recenica[i]) && brojac_slova==brojac)
				{
					return true;
					
				}
				else 
				{
					
					brojac=0;
					brojac_slova=0;
				}
			}
		}
	}
	return false;
}

int DajMjestoRijeci(std::string recenica, std::string rijec)
{
	int brojac=0;
	for(int i=0;i<recenica.size();i++)
	{
		if(i!=(int)recenica.size()-1)
		{
			while(recenica[i]==rijec[brojac])
			{
				if(i==(int)recenica.size())
				{
				int vel=rijec.size();
				if(brojac==vel) return i-brojac;
				break;	
				}
				i++;
				brojac++;
			}
			int vel=rijec.size();
			if(brojac==vel) return i-brojac;
			else brojac=0;
		}
	}
	return recenica.size();
}
std::string Obrni(std::string recenica,std::string fraza,int pozicija)
{
	int brojac(0);
	for(int i=pozicija;i<pozicija+fraza.size();i++)
	{
		recenica[i]=fraza[brojac];
		brojac++;
	}
	return recenica;
}
std::string ObrniFraze(std::string recenica,std::vector<std::string> rijeci)
{
	if(!(Test_Rijeci(rijeci))) throw std::domain_error("Nekorektan izbor riječi");
	for(int i=0;i<rijeci.size();i++)
	{
		if(DaLiSeNalazi(recenica,rijeci[i]))
		{
			recenica=Obrni(recenica,ObrniString(rijeci[i]),DajMjestoRijeci(recenica,rijeci[i]));
		}
	}
	return recenica;
}
std::string PretvoriUPig(std::string string)
{
	std::string pomocni("");
	for(int i=1;i<string.length();i++)
	{
		pomocni+=string[i];
	}
	pomocni+=string[0];
	pomocni+="ay";
	return pomocni;
}
std::string ZamijeniPig(std::string recenica,std::string rijec,int pozicija)
{
	std::string pomocni="";
	for(int i=0;i<pozicija;i++)
	{
		pomocni+=recenica[i];
	}
	pomocni+=PretvoriUPig(rijec);
	for(int i=pozicija+rijec.length();i<recenica.length();i++)
	{
		pomocni+=recenica[i];
	}
	return pomocni;
}




std::vector<std::string> PretvoriRecenicuURijeci(std::string recenica)
{
	std::vector<std::string> rijeci;
	std::string pomocni="";
	for(int i=0;i<recenica.length();i++)
	{
		if(DaLiJeSlovo(recenica[i]))
		{
			pomocni+=recenica[i];
		}
		else
		{
			if(pomocni.length()!=0)
			{
				rijeci.push_back(pomocni);
			}
			pomocni="";
		}
		
	}
	if(pomocni.length()!=0) 
	{
		rijeci.push_back(pomocni);
	}
	return rijeci;
	
}


std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> rijeci)
{
	if(!(Test_Rijeci(rijeci))) throw std::domain_error("Nekorektan izbor riječi");
	if(rijeci.size()!=0)
	{
		for(int j=0;j<rijeci.size();j++)
		{
			for(int i=0;i<rijeci.size();i++)
			{
				if(DaLiSeNalazi(recenica,rijeci[i]))
				{
				recenica=ZamijeniPig(recenica,rijeci[i],DajMjestoRijeci(recenica,rijeci[i]));
				}
			}
		}
	}
	else
	{
		recenica=IzmijeniUPigLatin(recenica,PretvoriRecenicuURijeci(recenica));
	}
	return recenica;
	
}
int main ()
{
	std::string recenica("");
	std::vector<std::string> fraze,pomocnii; 
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	
	std::cout<<"Unesite fraze: ";
	std::string pomocni;
	do
   {
   std::getline(std::cin,pomocni);
   	fraze.push_back(pomocni);
   }
   while(pomocni.size()!=1 && pomocni.size()!=0);
   
   for(int i=0;i<fraze.size()-1;i++)
   {
   	pomocnii.push_back(fraze[i]);
   }
   try
   {
   std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,pomocnii)<<"\n";
   std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,pomocnii);
   }
   catch(std::domain_error e)
   {
   	std::cout << e.what() << std::endl;
   }
   return 0;
}