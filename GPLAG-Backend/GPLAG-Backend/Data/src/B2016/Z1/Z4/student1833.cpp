/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include<stdexcept>
std::string ObrniFraze(std::string recenica, std::vector<std::string> rijeci)
{
	//prolazak kroz svaku rijec
	for(int i=0;i<rijeci.size();i++)
	{
		//jedna od rijeci
		//da li se rijec poklapa
		std::string rijec=rijeci[i];
	//	bool postojiRazmak=false;
		int u=0;
		/*
		while(rijec[u]==' ')
		u++;
		for(u;u<rijec.size();u++)
		{
		
		if(rijec[u]==' ') 
		{
			for(int ou=u;ou<rijec.size();ou++)
			{
				if(rijec[ou]!=' ') postojiRazmak=true;
			}
		}
		}
		std::string pomocna="";
		for(int o=0;o<rijec.size();o++)
		{
			if(o<(rijec.size()-1))
			{
				bool bioRazmak=false;
				bool Pocetak=false;
				while(rijec[o]==' ')
				{
					if(o==0) Pocetak=true;
					bioRazmak=true;
					o++;
				}
				if(bioRazmak && !Pocetak && o<rijec.size())
				pomocna.push_back(' ');
				else if(o<rijec.size())
				pomocna.push_back(rijec[o]);
			}
			else if(rijec[rijec.size()-1]!=' ')
			pomocna.push_back(rijec[rijec.size()-1]);
		}
		rijec.resize(0);
		rijec=pomocna;*/
		int brojac=0;
		for(int j=0;j<recenica.length();j++)
		{
			int trenutnoSlovo=j;
			while(recenica[j]==rijec[brojac] )//&& rijec[brojac]!='.')
			{
				if(brojac==(rijec.size()-1))
				{
					/*if(postojiRazmak)
					{
					if(j-brojac>0)
					if(recenica[j-brojac-1]>='A' && recenica[j-brojac-1]<='Z' || recenica[j-brojac-1]>='a' && recenica[j-brojac-1]<='z')
					{
						brojac=0;
						j++;
						break;
					}
					if(j+1<recenica.size())
					if(recenica[j+1]>='A' && recenica[j+1]<='Z' || recenica[j+1]>='a' && recenica[j+1]<='z')
					{
						brojac=0;
						j++;
						break;
					}
					}*/
					int krajRijeci=j;
					//rijeci su se poklopile
					for(int k=0;k<rijec.size();k++)
					{
						recenica[krajRijeci]=rijec[k];
						krajRijeci--;
						
					}
					//break;
					j=trenutnoSlovo;
					brojac=0;
				}
				else
				{
				brojac++;
				j++;
				}
			}
			brojac=0;
		}
	}
	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci)
{
	//ako je vektor rijeci prazan, sve rijeci zamjeni
	//prolazak kroz svaku rijec
	std::string nova;
	std::string novaRijec;
	if(rijeci.size()==0)
	{
		int brojac=0;
		//sad promjeni svaku rijec
		for(int i=0;i<recenica.size();i++)
		{
			if(recenica[i]>='A' && recenica[i]<='Z' || recenica[i]>='a' && recenica[i]<='z')
			{
				
				brojac++;
				if(i>=(recenica.size()-1))
				{
					//zadnja rijec
					char prvo=recenica[i-brojac];
					recenica.push_back(' ');
					recenica.push_back('q');
					for(int k=i-brojac;k<recenica.size()-1;k++)
					{
						recenica[k]=recenica[k+1];
					}
					for(int k=recenica.size()-1;k>i+1;k--)
					{
						recenica[k]=recenica[k-3];
					}
					recenica[i-1]=prvo;
					recenica[i]='a';
					recenica[i+1]='y';
					
				}
			}
			else 
			{
				if(brojac!=0)
				{
					
					//zamjeni rijeci
					char prvo=recenica[i-brojac];
					recenica.push_back(' ');
					recenica.push_back('q');
					for(int k=i-brojac;k<recenica.size()-1;k++)
					{
						recenica[k]=recenica[k+1];
					}
					for(int k=recenica.size()-1;k>i+1;k--)
					{
						recenica[k]=recenica[k-3];
					}
					recenica[i-1]=prvo;
					recenica[i]='a';
					recenica[i+1]='y';
					i++;
				}
				brojac=0;
			}
		}
	}
	else
	for(int i=0;i<rijeci.size();i++)
	{
		//jedna od rijeci
		//da li se rijec poklapa
		std::string rijec=rijeci[i];
		for(int o=0;o<rijec.size();o++)
		{
			if(!(rijec[o]>='A' && rijec[o]<='Z' || rijec[o]>='a' && rijec[o]<='z'))
			{
				nova.resize(0);
				novaRijec.resize(0);
			throw  std::domain_error("Nekorektan izbor riječi");
			}
		}
		novaRijec="";
		int brojac=0;
		for(int j=0;j<recenica.length();j++)
		{
			bool nadjen=false;
			novaRijec="";
			while(recenica[j]==rijec[brojac])
			{
				if(brojac==(rijec.size()-1))
				{
					
					if(j-brojac>0)
					if(recenica[j-brojac-1]>='A' && recenica[j-brojac-1]<='Z' || recenica[j-brojac-1]>='a' && recenica[j-brojac-1]<='z')
					{
						brojac=0;
						j++;
						break;
					}
					if(j+1<recenica.size())
					if(recenica[j+1]>='A' && recenica[j+1]<='Z' || recenica[j+1]>='a' && recenica[j+1]<='z')
					{
						brojac=0;
						j++;
						break;
					}
					
					
					if(j-brojac>0)
					{
						if(recenica[j-brojac-1]!=' ') break;
					}
					nadjen=true;
					int krajRijeci=j;
					//rijeci su se poklopile
				/*	novaRijec="";
					//prvo slovo
					for(int k=j-brojac+1;k<=j;k++)
					{
						novaRijec+=recenica[k];
					}
					novaRijec+=recenica[j-brojac];
					novaRijec+="ay";
					nova+=novaRijec;
					*/
					char prvo=recenica[j-brojac];
					recenica.push_back(' ');
					recenica.push_back('q');
					for(int k=j-brojac;k<recenica.size()-1;k++)
					{
						recenica[k]=recenica[k+1];
					}
					for(int k=recenica.size()-1;k>j+1;k--)
					{
						recenica[k]=recenica[k-3];
					}
					recenica[j]=prvo;
					recenica[j+1]='a';
					recenica[j+2]='y';
					
					// ide od drugog slova danas je lijep: danas je ijep
					
					break;
					
				}
				else
				{
				brojac++;
				j++;
				}
			}
			brojac=0;
		//	if(!nadjen && i==0)
		//	nova+=recenica[j];
		}
	}
	return recenica;
}
int main ()
{
	
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	getline(std::cin,recenica);
	std::vector<std::string> rijeci;
	std::cout<<"Unesite fraze: ";
	while(true)
	{
		std::string p;
	//	std::cin.ignore(2);
		getline(std::cin,p);
		if (p.size()==0) {break;}
		rijeci.push_back(p);
		
	}
	std::string recenica1=recenica;
	try {
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,rijeci);
	}
	catch(std::domain_error &err) {
		std::cout <<"Izuzetak: Nekorektan izbor rijeci";
	}
	catch(...)
	{
		std::cout<<"Izuzetak: Nekorektan izbor rijeci";
	}
	std::cout<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,rijeci);
	return 0;
}