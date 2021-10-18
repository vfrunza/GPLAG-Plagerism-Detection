/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

void Obrni(std::string &s)
{
	for(int i=0; i<s.length()/2; i++)
	{
		char pomocna(s[i]);
		s[i]=s[s.length()-1-i];
		s[s.length()-1-i]=pomocna;
	}
}

std::string PigLatin(std::string s)
{
	std::string novi;
	std::string a("ay");
	for(int i=1; i<s.size(); i++)
	{
		novi.push_back(s[i]);
	}
	novi.push_back(s[0]);
	for(int i=0; i<a.length(); i++)
	{
		novi.push_back(a[i]);
	}
	return novi;
}

std::string ObrniFraze(std::string s, std::vector<std::string> v)
{
	for(int i=0; i<v.size(); i++)
	{
		int j(0);
		while(j<s.length())
		{
			if(v[i][0]==s[j])
			{
				int k(j);
				int l(0);
				while(v[i][l]==s[j])
				{
					if(l==v[i].size()-1)
					{
						std::string pomocna(v[i]);
						Obrni(pomocna);
						for(int z=0; z<v[i].size(); z++)
						{
							s[k+z]=pomocna[z];
						}
					}
					l++;
					j++;
				}
			}
			j++;
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{
	int j(0);
	while(j<v.size())
	{
		int k(0);
		std::string pomocni(v[j]);
		while(k<pomocni.length())
		{
			if((pomocni[k]<'a' || pomocni[k]>'z') && (pomocni[k]<'A' || pomocni[k]>'Z')) throw std::domain_error("Nekorektan izbor rijeci");
			k++;
		}
		j++;
	}
	std::string glavni;
	int i(0);
	int br(0);
	while(s[i]==' ')
	{
		glavni.push_back(s[i]);
		i++;
	}
	while(i<s.length())
	{
		int j(i);
		std::string novi;
		while(s[i]!=' ' && i<s.length())
		{
			novi.push_back(s[i]);
			i++;
		}
		for(int k=0; k<v.size(); k++)
		{
			if(novi==v[k])
			{
				br+=2;
				novi=PigLatin(novi);
				for(int z=0; z<novi.length(); z++)
				{
					glavni.push_back(novi[z]);
				}
				break;
			}
		}
		if(glavni.length()-br<i)
		{
			while(j<i)
			{
				glavni.push_back(s[j]);
				j++;
			}
		}
		while(s[i]==' ' && i<s.length())
		{
			glavni.push_back(s[i]);
			i++;
		}
	}
	return glavni;
}

int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> v;
	std::cout << "Unesite fraze: ";
	for(;;)
	{
		std::string pomocni;
		std::getline(std::cin, pomocni);
		if(pomocni.size()<1) break;
		v.push_back(pomocni);
		
	}
	try
	{
		std::string a(IzmijeniUPigLatin(s,v));
		std::cout << "Recenica nakon PigLatin transformacije: " << a;
	}
	catch(std::domain_error n)
	{
		std::cout << "Izuzetak: " << n.what();
	}
	std::string novi(ObrniFraze(s,v));
	std::cout << std::endl << "Recenica nakon obrtanja fraza: " << novi;
	return 0;
}