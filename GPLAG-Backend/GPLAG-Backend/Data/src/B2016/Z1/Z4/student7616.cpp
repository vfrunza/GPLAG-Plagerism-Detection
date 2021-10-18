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

std::string ObrniFraze(std::string s,std::vector<std::string> v)
{
	std::string pom;
	bool cs;
	for(int l=0; l< v.size(); l++)
	{
		pom=v[l];
		for(int i=0; i<s.size() ;i++)
		{
			cs=true;
			int b(0);
			for(int j=i; j<s.size(); j++)
			{
				if(b==pom.size()) break;
				if(pom[b] != s[j])
				{
					cs=false; break;
				}
				b++;
			}
		if(cs && b==pom.size())
			{
				for(int k=pom.size()-1; k>=0; k--,i++) s[i]=pom[k];
			}
			
		}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string str, std::vector<std::string> v)
{
	std::string pom,dodaj{"ay"},a,s;
	s=str;
	for(int l=0; l<v.size(); l++)
		{
			pom=v[l];
			for(int i=0; i<pom.length(); i++)
			{
				if((pom[i]<'a' && pom[i] >'z') || ((pom[i]<'A' && pom[i]>'Z')) || pom[i] ==' ')  
				throw std::domain_error("Nekorektan izbor rijeci ");
				
			}
		}
	bool cs(true);
	if(v.size()  == 0) cs=false;
	if(cs){
		for(int l=0; l<v.size(); l++)
		{
			pom=v[l];
			for(int i=0; i<str.length(); i++)
			{
				while((s[i]>='a' && s[i] <='z') || (s[i]>='A' && s[i]<='Z' && i<str.length()))
				{
					a.push_back(s[i]); i++;
				}
				if(a.size()!=0)
				{
					if(a==pom)
					{
						std::string zapamti;
						zapamti.push_back(s[i-a.length()]);
						s.erase(i-a.length(),1);
						s.insert(i-1,zapamti);
						s.insert(i,dodaj);
						i+=2;
						a.resize(0);
						str=s;
					}
					a.resize(0);
				}
			}
		}
		return str;
		
	}
		
		for(int i=0; i<str.length();i++)
		{
			while((s[i]>='a' && s[i] <='z') || (s[i]>='A' && s[i]<='Z' && i<str.length()))
			{
				a.push_back(s[i]); i++;
			}
			if(a.size()!=0)
			{
				std::string zapamti;
				zapamti.push_back(s[i-a.length()]);
				s.erase(i-a.length(),1);
				s.insert(i-1,zapamti);
				s.insert(i,dodaj);
				i+=2;
				a.resize(0);
				str=s;
			}
		}
		return str;
}
	
int main ()
{
	std::string s,p;
	std::vector<std::string> v;
	std::cout <<"Unesite recenicu: " ;
	std::getline(std::cin,s);
	try
	{
		std::cout <<"Unesite fraze: ";
		do{
			std::getline(std::cin,p);
			if(p!="") v.push_back(p);
		}
		while(p!="");
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<IzmijeniUPigLatin(s,v)<<std::endl;
		

	}
	
	catch(std::domain_error e)
	{
		std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		std::cout<<"Recenica nakon obrtanja fraza: ";
		std::cout<<ObrniFraze(s,v);
		return 0;
	}

    std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<ObrniFraze(s,v);
	
	return 0;
}