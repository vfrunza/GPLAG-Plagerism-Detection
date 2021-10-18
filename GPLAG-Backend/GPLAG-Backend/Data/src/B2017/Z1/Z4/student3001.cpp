/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>

std::string NapraviPalindrom(std::string s, std::vector<std::string> v)
{
	if(v.size()==0)return s;
	if(s.size()==0)return {};
	for(int i(0);i<v.size();i++)
	{
		for(int j(0);j<v.at(i).size();j++)
		{
			for(int k(0);k<s.size();k++)
			{
				//if(k==s.size()-1 && v.at(i).size()!=1)break;
				if(s.at(k)!=v.at(i).at(j))continue;
				int brojac(0);
				int f(k);
				while(s.at(k)==v.at(i).at(j) && j<v.at(i).size() && k<s.size())
				{
					brojac++;
					//if(k!=s.size()-1 && j!=v.at(i).size()-1)k++;
				
					if(j==v.at(i).size()-1 || k==s.size()-1)break;
					j++;
					k++;
				}
				
				if(brojac==v.at(i).size() && 
				(k==s.size()-1 || ((s.at(k+1)<'a' || s.at(k+1)>'z') && (s.at(k+1)<'A' || s.at(k+1)>'Z'))) && 
				(f==0 || ((s.at(f-1)<'a' || s.at(f-1)>'z') && (s.at(f-1)<'A' || s.at(f-1)>'Z'))))
				{
					for(j=v.at(i).size()-1;j>=0;j--)
					{
						//if(k==s.size()-1){

							//s.insert(s.begin()+(k+1),v.at(i).at(j));
							//k++;
						//}
					//else{}
					s.insert(s.begin()+(k+1), v.at(i).at(j));
					k++;
					}
				}
			j=0;	
			}
			break;
		}
	}
	return s;
	
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string>v){
	if(v.size()==0 || s.size()==0)return s;
	for(int i(0);i<v.size();i++)
	{
		for(int j(0);j<v.at(i).size();j++)
		{
			for(int k(0);k<s.size();k++)
			{
				//if(k==s.size()-1)break;
				if(s.at(k)!=v.at(i).at(j))continue;
				int brojac(0);
				int f(k);
				while(s.at(k)==v.at(i).at(j) && j<v.at(i).size())
				{
					brojac++;
					//if(k!=s.size()-1)k++;
					//if(k!=s.size()-1 && j!=v.at(i).size()-1)k++;
					if(j==v.at(i).size()-1 || k==s.size()-1)break;
					j++;
					k++;
				}
				if(brojac==v.at(i).size() && 
				(k==s.size()-1 || ((s.at(k+1)<'a' || s.at(k+1)>'z') && (s.at(k+1)<'A' || s.at(k+1)>'Z'))) 
				&& (f==0 || ((s.at(f-1)<'a' || s.at(f-1)>'z') && (s.at(f-1)<'A' || s.at(f-1)>'Z'))))
				{
					//if(k==s.size()-1)k=k-(v.at(i).size()/2)+1;
					//else k=k-(v.at(i).size()/2);
					//if(v.at(i).size()%2==0)
					k=k-(v.at(i).size()/2);
					k++;
					for(j=(v.at(i).size()/2-1);j>=0;j--)
					{
						
						s.at(k)=v.at(i).at(j);
						k++;
					}
					/*else if(v.at(i).size()%2!=0)
					{
						int a(v.at(i).size()/2);
						k=k-(v.at(i).size()/2);
						for(j=(v.at(i).size()/2);j>=0;j--)
						{
							s.at(k)=v.at(i).at(j);
							k++;
						}
					}*/
				}
				j=0;
			}
			break;
		}
	}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";	std::string fraza;
	std::vector<std::string>fraze;
	do
	{
		std::getline(std::cin, fraza);
		if(fraza.size()!=0)fraze.push_back(fraza);
		if(fraza.size()==0)break;
	}while(1);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(recenica,fraze);
	std::cout<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(recenica, fraze);

	return 0;
}