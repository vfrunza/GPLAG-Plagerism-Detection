#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;
using std::string;

string ObrniFraze(string s, vector<string> popi)
{
	for(int i=0;i<popi.size();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if(s[j]==popi[i][0])
			{
				int bis=0;
				bool isti=true;
				while(isti && j+bis<s.length() && bis<popi[i].length())
				{
					if(s[j+bis]!=popi[i][bis]) isti=false;
					bis++;
				}
				if(bis!=popi[i].length()) isti=false;
				if(isti)
				{
					if(bis%2!=0)
					{
						for(int k=j;k<j+(bis-1)/2;k++)
						{
							char temp;
							temp=s[k];
							s[k]=s[j+bis-1-(k-j)];
							s[j+bis-1-(k-j)]=temp;
						}
					}
					if(bis%2==0)
					{
						for(int k=j;k<j+bis/2;k++)
						{
							char temp;
							temp=s[k];
							s[k]=s[j+bis-(k-j)-1];
							s[j+bis-(k-j)-1]=temp;
						}
					}
					j+=bis;
				}
			}
		}
	}
	return s;
}

string IzmijeniUPigLatin(string s, vector<string> popi)
{
	for(int i=0;i<popi.size();i++)
	{
		for(int j=0;j<popi[i].length();j++)
		{
			if((popi[i][j]<'A' || (popi[i][j]>'Z' && popi[i][j]<'a') || popi[i][j]>'z')) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		}
	}
	for(int i=0;i<popi.size();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if((j==0 || (s[j-1]<'A' || (s[j-1]>'Z' && s[j-1]<'a') || s[j-1]>'z') ) && s[j]==popi[i][0] && j+popi[i].length()<=s.length() && (j+popi[i].length()==s.length() || (s[j+popi[i].length()]<'A' || (s[j+popi[i].length()]>'Z' && s[j+popi[i].length()]<'a') || s[j+popi[i].length()]>'z')))
			{
				int bis=0;
				bool isti=true;
				while(isti && j+bis<s.length() && bis<popi[i].length())
				{
					if(s[j+bis]!=popi[i][bis]) isti=false;
					bis++;
				}
				if(bis!=popi[i].length()) isti=false;
				if(isti)
				{
					char prvos=s[j];
					int k;
					for(k=j;k<j+bis-1;k++) s[k]=s[k+1];
					s[k]=prvos;
					k++;
					s=s.substr(0, k) + "ay" + s.substr(k, s.length()-k);
				}
			}
		}
	}
	if(popi.size()==0)
	{
		for(int j=0;j<s.length();j++)
		{
			if(((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z')) && (j==0 || (s[j-1]<'A' || (s[j-1]>'Z' && s[j-1]<'a') || s[j-1]>'z') ))
			{
				int bis=0, m=j;
				while(m<s.length() && ((s[m]>='A' && s[m]<='Z') || (s[m]>='a' && s[m]<='z')))
				{
					bis++;
					m++;
				}
				char prvos=s[j];
				int k;
				for(k=j;k<j+bis-1;k++) s[k]=s[k+1];
				s[k]=prvos;
				k++;
				s=s.substr(0, k) + "ay" + s.substr(k, s.length()-k);
			}
		}
	}
	return s;
}

int main ()
{
	string s;
	cout << "Unesite recenicu: ";
	std::getline(cin, s);
	vector<string> fr;
	cout << "Unesite fraze: ";
	string a;
	do
	{
		std::getline(cin, a);
		if(a!="") fr.push_back(a);
	}while(a!="");
	string c=s;
	try
	{
		c=IzmijeniUPigLatin(s, fr);
		cout << "Recenica nakon PigLatin transformacije: ";
		cout << c << '\n';
	}
	catch(std::domain_error ero)
	{
		cout << ero.what();
	}
	string d;
	d=ObrniFraze(s, fr);
	cout << "\nRecenica nakon obrtanja fraza: " << d << '\n';
	return 0;
}