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
std::string ObrniFraze(std::string s,std::vector<std::string> fr)
{
	std::string c;
	std::string vratiti;
	for(int i=0;i<fr.size();i++)
	{
		int duzina1(fr[i].length());
		for(int j=0;j<s.length();j++)
		{
			int duzina2(j+duzina1);
			if(duzina2<=s.length())
			{
				c=s.substr(j,duzina1);
				if(c==fr[i])
				{
					vratiti=s.substr(0,j);
					int b(c.length()-1);
					for(int k=0;k<c.length()/2;k++)
					{
						char pomoc;
						pomoc=c[k];
						c[k]=c[b];
						c[b]=pomoc;
						b--;
					}
					vratiti+=c;
					vratiti+=(s.substr(duzina2,s.length()));
					s=vratiti;
					vratiti="";
				}
			}
		}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> fr)
{
	int pozicija2=0,pozicija1=0;
	std::string vratiti;
	std::string poredjenje;
	if(fr.size()!=0)
	{
		for(int i=0;i<fr.size();i++)
		{
			for(int j=0;j<fr[i].length();j++)
			{
				if((fr[i][j]<'A' && fr[i][j]!=' ') || (fr[i][j]>'Z' && fr[i][j]<'a') || (fr[i][j]>'z'))
				{
					throw std::domain_error("Nekorektan izbor riječi");
				}
			}
		}
		for(int i=0;i<s.length()-1;i++)
		{
			if((s[i]==' ' && s[i+1]!=' ')||(s[i]!=' ' && s[i+1]!=' ' && i==0))
			{
				if(i!=0)
				{
					i++;
				}
				pozicija1=i;
				while(s[i]!=' ' && i<s.length())
				{
					pozicija2++;
					i++;
				}
				poredjenje=s.substr(pozicija1,pozicija2);
				bool slucaj(false);
				for(int j=0;j<fr.size();j++)
				{
					if(poredjenje==fr[j])
					{
						char pomoc(poredjenje[0]);
						for(int k=0;k<poredjenje.length();k++)
						{
							if(k<poredjenje.length()-1)
							{
								poredjenje[k]=poredjenje[k+1];
							}
							else
							{
								poredjenje[k]=pomoc;
							}
						}
						slucaj=true;
						goto l1;
					}
				}
				vratiti+=poredjenje+" ";
				l1:
				if(slucaj)
				{
					vratiti+=poredjenje+"ay"+" ";
				}
				i--;
				pozicija2=0;
			}
		}
	}
	if(fr.size()==0)
	{
		for(int i=0;i<s.length()-1;i++)
		{
			if((s[i]==' ' && s[i+1]!=' ')||(s[i]!=' ' && s[i+1]!=' ' && i==0))
			{
				if(i!=0)
				{
					i++;
				}
				pozicija1=i;
				while(s[i]!=' ' && i<s.length())
				{
					pozicija2++;
					i++;
				}
				poredjenje=s.substr(pozicija1,pozicija2);
				char pomoc;
				int a(poredjenje.length()-1);
				pomoc=poredjenje[0];
				poredjenje[0]=poredjenje[a];
				poredjenje[a]=pomoc;
				vratiti+=poredjenje+"ay"+" ";
				i--;
				pozicija2=0;
			}
		}
	}
	return vratiti;
}
int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica,'\n');
	std::string pomocna;
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for(;;)
	{
		std::getline(std::cin,pomocna,'\n');
		if(pomocna!="")
		{
			fraze.push_back(pomocna);
		}
		else
		{
			break;
		}
	}
	try
	{
	std::string recenica2(recenica);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::string s2(IzmijeniUPigLatin(recenica,fraze));
	std::cout<<s2<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::string obrnute_fraze(ObrniFraze(recenica2,fraze));
	std::cout<<obrnute_fraze<<std::endl;
	}
	catch(...)
	{
		std::cout<<"Nekorektan izbor riječi";
	}
	return 0;
}