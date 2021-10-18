#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
using std::string;
string Palindrom(string a)
{
	string s;
	if(a.length()>1)
	{
	for(int i=a.length()-1; i>=0; i--) {
		s.push_back(a.at(i));
	}
	return s;
	}
	else return a;

}
string PoluPalindrom(string a)
{
	string s;
	if(a.length()>1)
	{
	for(int i=(a.length()/2)-1;i>=0;i--)
	{
		s.push_back(a.at(i));
	}	
	return s;
	}
	else return a;
	
}
string NapraviPalindrom(string s,std::vector<string>v)
{
	string palindrom,s1;
	int pom,br(0);
	int d(s.length());
	if(s.length()==0) return s;
	if(s.length()==1) { s.push_back(s.at(0)); return s; }
	else if(v.size()==0) return s;
	s.insert(d," ");
for(int i=0;i<v.size();i++)
{
	s1=Palindrom(v.at(i));
	for(int j=0;j<s.length();j++)
	{
		pom=j;
     	for(int k=0;k<v.at(i).length();k++)
		{
			if(v.at(i).length()>1)
		{
			if(s.at(j)==v.at(i).at(k))
			{
				if(j==s.length()-1) break;
				br++;
				j++;
			}
		}

		else if(v.at(i).length()==1) { br=1; break; }
		}
			if(v.at(i).length()>1&&((br==v.at(i).length()&&(s.at(j)==' '||s.at(j)==','))||(br==v.at(i).length()&&s.at(j)!=' '&&s.at(j-1)==' ' )))
			{
					s.insert(j,s1);
			}
			 if(v.at(i).length()<=1&&v.at(i).at(0)==s.at(j)&&(s.at(j+1)==' '||s.at(j+1)==',')) { s.insert(j,s1); break; }
		br=0;
		j=pom;
		
	}
}
s.resize(s.size()-1);
	return s;
}
string NapraviPoluPalindrom(string s,std::vector<string>v)
{
	string polupalindrom;
	int br(0),duzina,pom,d;
	d=s.length();
	if(d==0||d==1) return s;
	else if(v.size()==0) return s;
	s.insert(d," ");
	for(int i=0;i<v.size();i++)
	{
		polupalindrom=PoluPalindrom(v.at(i));
		duzina=polupalindrom.length();
		for(int j=0;j<s.length();j++)
		{
			 pom=j;
			for(int k=0;k<v.at(i).length();k++)
			{
				if(v.at(i).length()>1)
				{
				if(s.at(j)==v.at(i).at(k))
				{
					if(j==s.length()-1) break;
					br++;
					j++;
				}
				}
			}
			
				if((v.at(i).length()>1&&v.at(i).length()==br&&((s.at(j)==' '||s.at(j)==',')))||(v.at(i).length()>1&&br==v.at(i).length()&&s.at(j)!=' '&&s.at(j-1)==' ')) 
				{
						s.replace(j-duzina,duzina,polupalindrom);
				}		
				if(v.at(i).length()<=1&&v.at(i).at(0)==s.at(j)&&(s.at(j+1)==' '||s.at(j+1)==','))
				{
					s.replace(j,1,polupalindrom);
				}	
			br=0;	
			 j=pom;
		}
	}
	s.resize(s.length()-1);
	return s;
}
int main ()
{
	string s,s1;
	std::vector<string>v; 
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout << "Unesite fraze: ";
	for(;;)
	{
		std::getline(std::cin,s1);
		if(s1.length()!=0)
			v.push_back(s1);
		else break;	
	}

	std::cout << "Recenica nakon Palindrom transformacije: " <<NapraviPalindrom(s,v)<<std::endl;
	std::cout <<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,v);
	return 0;
}