#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
string izvrni(string s)
{
	int i;
	for(i=0;i<s.length()/2;i++);
	{
		char temp(s.at(i));
		s.at(i)=s.at(s.length()-i-1);
		s.at(s.length()-i-1)=temp;
	}
	return s;
}
string ObrniFraze(string s, vector<string> vs)
{
	bool jeste_fraza(true);
	for(int i(0);i<vs.size();i++)
	{
		for(int j(0);j<s.length();j++)
		{
			if(vs.at(i).at(j)==s.at(j))
			{
				int brojac(j);
				while(vs.at(i).at(brojac)==s.at(brojac))brojac++;
				if(brojac-j==vs.at(i).size())jeste_fraza=true;
				else jeste_fraza=false;
			}
			if(jeste_fraza)
			{
				string izvrnuti(izvrni(vs.at(i)));
				for(int k(j);k<vs.at(i).size();k++)
				{
					s.at(k)=izvrnuti.at(k-j);
				}
				
			}
			jeste_fraza=true;
		}
	}
}
int main ()
{
	string s;
	vector<string>vs ;
	cout<<"Unesite recenicu: ";
	getline(cin,s);
	cout<<"Unesite fraze: ";
	//ne znam kad treba da bude rekid unosa
	return 0;
}