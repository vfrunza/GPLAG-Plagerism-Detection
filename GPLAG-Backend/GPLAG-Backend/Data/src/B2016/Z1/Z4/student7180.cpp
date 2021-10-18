/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

std::string ObrniRijec(std::string s)
{
	std::string s1;
	for(int i=s.length()-1; i>=0; i--)
	s1+=s[i];
	return s1;
}

std::string ObrniFraze (std::string s, VektorStringova v)
{
	int a=0;
	/*for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].length(); j++)
		{
			if((v[i][j]<'A' || v[i][j]>'Z') && (v[i][j]<'a' || v[i][j]>'z')) throw std::domain_error("Nekorektan izbor riječi");
		}
	} */
	if(v.size()!=0){
	do
	{
		for(int i=0; i<s.size(); i++)
		{
			if(s.substr(i, v[a].size())==v[a] )
			{
			   s=s.substr(0, i)+ObrniRijec(v[a])+s.substr(i+v[a].size(), s.size()-i);
			}
		}
		a++;
	}while(a!=v.size());
	}
	return s;
}

std::string PigLatin(std::string s)
{
	std::string s1;
	std::string s2;
	for(int i=0; i<s.length(); i++)
	{
		if(i==0) s2=s[i];
		else s1+=s[i];
	}
	s1+=s2;
	s1+="ay";
	return s1;
}

bool pocetakrecenice(int i)
{
	if(i==0) return true;
	return false;
}

bool pocetakrijeci(std::string s, int i)
{
	if(s[i]==' ') return true;
	return false;
}

std::string IzmijeniUPigLatin(std::string s, VektorStringova v)
{
	int a=0;
	std::string s1;
	if(v.size()==0) 
	{
		for(int i=0; i<s.length(); i++)
		{
			 if(toupper(s[i])<'A' || toupper(s[i])>'Z')
			 {
			 	while(toupper(s[i])<'A' || toupper(s[i])>'Z')
			 	{
			 		s1.push_back(s[i]);
			 		i++;
			 	}
			 	i--;
			 }
			 else
			 {
			 	int p=i;
			 	while(toupper(s[i])>='A' && toupper(s[i])<='Z') i++;
			 	int k=i;
			 	std::string temp;
			 	while(p!=k)
			 	{
			 		temp.push_back(s[p]);
			 		p++;
			 	}
			 	s1+=PigLatin(temp);
			 	i--;
			 }
		}
		return s1;
	}
	
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].length(); j++)
		{
			if((v[i][j]<'A' || v[i][j]>'Z') && (v[i][j]<'a' || v[i][j]>'z')) throw std::domain_error("Nekorektan izbor riječi");
		}
	}
	do
	{
		for(int i=0; i<s.size(); i++)
		{
			if(s.substr(i, v[a].size())==v[a] && (pocetakrecenice(i) || pocetakrijeci(s, i-1)))
			{
				{
					if(i+v[a].size()==s.length() || toupper(s[i+v[a].size()])<'A' || toupper(s[i+v[a].size()])>'Z')
					{
						s=s.substr(0, i)+PigLatin(v[a])+s.substr(i+v[a].size(), s.size()-i);
					}
				}
			}
		}
		a++;
	}while(a!=v.size());
	return s;
}

int main ()
{
		std::string s;
		std::cout<<"Unesite recenicu: ";
		std::getline(std::cin,s );
		std::vector<std::string> v;
		std::cout<<"Unesite fraze: ";
		while(3==3) 
		{
			std::string p;
			std::getline(std::cin, p);
			if(p.size()!=0) v.push_back(p);
			else break;
		}
		try
		{
		std::string s1=IzmijeniUPigLatin(s,v);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<s1;
		}catch(std::domain_error izuzetak)
	{
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<std::endl;
		std::string s1=ObrniFraze(s, v);
		std::cout<<"Recenica nakon obrtanja fraza: ";
		std::cout<<s1;
return 0;
}