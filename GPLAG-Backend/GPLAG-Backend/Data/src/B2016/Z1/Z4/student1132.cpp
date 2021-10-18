#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
std::string ObrniFraze(std::string s,std::vector<std::string> v)
{
	for(auto fr:v)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s.substr(i,fr.size()) == fr)
			{
				for(int j = 0;j < fr.size()/2; j++)
				{
					auto tmp = s[i+j];
					s[i+j] = s[i+fr.size()-1-j];
					s[i+fr.size()-1-j] = tmp;
				}
			}
		}
	}
	return s;
}
bool isAlpha(char x)
{
	return (x>='a' && x<='z') || (x>='A' && x<='Z');
}
std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v)
{
	std::string rez;
	if(v.size() != 0)
	{
		for(int i=0;i<s.size();i++)
		{
			bool ima = false;
			for(auto e:v)
			{
				for(auto c:e) if(!(c>='A' && c<='Z') && !(c>='a' && c<='z')) throw std::domain_error("Nekorektan izbor rijeci");
				if((i == 0 || !isAlpha(s[i-1])) && (s.substr(i,e.size())) == e && (i+e.size() == s.size() || !isAlpha(s[i+e.size()]) ))
				{
					rez += s.substr(i+1,e.size()-1) + s[i] + "ay";
					ima = true;
					i = i + e.size() - 1;
					break;
				}
			}
			if(!ima) rez+=s[i];
		}
	}
	else
	{
		for(int i=0;i<s.size();i++)
		{
			if(isAlpha(s[i]) && (i==0 || !isAlpha(s[i-1]) ))
			{
				int duzina=0;
				for(;i+duzina<s.size();duzina++) if(!isAlpha(s[i+duzina])) break;
				rez += s.substr(i+1,duzina-1) + s[i] + "ay";
				i+= duzina-1;
			}
			else rez+= s[i];
		}
	}
	
	return rez;
}
int main ()
{
	std::string s,fr;
	std::cout<< "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<< "Unesite fraze: ";
	std::vector<std::string> v;
	for(;;)
	{
		getline(std::cin,fr);
		if(fr == "") break;
		v.push_back(fr);
	}
	try
	{
	std::string res = IzmijeniUPigLatin(s,v);
	std::cout<<"Recenica nakon PigLatin transformacije: "<< res;
	}
	catch(...)
	{
		std::cout<<"Izuzetak: Nekorektan izbor rijeci";
	}
	std::cout<<"\nRecenica nakon obrtanja fraza: "<< ObrniFraze(s,v);
	return 0;
}