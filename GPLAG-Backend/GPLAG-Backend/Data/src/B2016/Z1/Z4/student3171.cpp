/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

string IzmijeniUPigLatin(string s, vector<string> fraze)
{
		
		
	
	

	for(int i=0; i<fraze.size(); i++)
	{
		
		string rijec(fraze[i]);
		for(int j=0; j<rijec.length(); j++)
		{
			if(rijec[j]<'A' || rijec[j]>'z' ||(rijec[j]>'Z' && rijec[j]<'a')) throw std::domain_error("Nekorektan izbor rijeci");
		}
		
		
		for(int j=0; j<s.length(); j++)
		{
			if(s[j]==rijec[0])
			{
				int k(j);
				while((s[k]<='Z' && s[k]>='A') || (s[k]<='z' && s[k]>='a')) k++;
				int kraj(k-1);
				
				int duzina(k-j), l(0), poc(j);
				if(s[j]==rijec[l] && (s[j-1]<'A' || s[j-1]>'z' || (s[j-1]<'a' && s[j-1]>'Z')))
				{
					while(j<s.length() && l<rijec.length() && s[j]==rijec[l])
					{
						l++;
						j++;
					}
				
					if(l==rijec.length() && duzina==rijec.length())
					{
						char prvo(s[poc]);
					
						s.erase(s.begin()+poc);
						s[kraj]=prvo;
					
						kraj++;
						s.insert(s.begin()+kraj, 'a');
						kraj++;
						s.insert(s.begin()+kraj, 'y');
						kraj++;
						s.insert(s.begin()+kraj, ' ');
					
				}
				}
			}
		}
	}
	
	
	return s;
}


string ObrniFraze(string s, vector<string> fraze)
{
	for(int i=0; i<fraze.size(); i++)
	{
		string rijec(fraze[i]);
		
		
		for(int j=0; j<s.length(); j++)
		{
			
			if(s[j]==rijec[0])
			{
				int k(j);
				
				while((s[k]<='Z' && s[k]>='A') ||(s[k]<='z'&& s[k]>='a')) k++;
				int kraj(k-1);
			
				int duzina(k-j),l(0),poc(j), br(0);
			
				if(s[j]==rijec[l] && (s[j-1]<'A' || s[j-1]>'z' || (s[j-1]<'a' && s[j-1]>'Z') ))
				{
					while(j<s.length() && l<rijec.length() && s[j]==rijec[l])
					{
						l++;
						j++;
						br++;
					}
				
				
					if(l==rijec.length() && duzina==rijec.length())
					{
						char temp;
						while(poc<kraj)
						{
							temp=s[kraj];
							s[kraj]=s[poc];
							s[poc]=temp;
					
							poc++;
							kraj--;
						}
					}
				}
			}
			
		}
		
	}
	
	return s;
}


int main ()
{
	string recenica;
	cout << "Unesite recenicu: ";
	getline(cin, recenica);
	
	vector<string> fraze;
	cout <<"Unesite fraze: ";
	
	string rijec;
	
	do
	{
		std::getline(cin, rijec);
		fraze.push_back(rijec);
	}while(cin.peek()!='\n');

	
	
	try{
		cout<< "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, fraze);
	}
	
	catch(std::domain_error izuzetak)
	{
		cout<< "Izuzetak: " << izuzetak.what();
	}
	cout << endl<< "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze)<< endl;
	
	
	
	return 0;
}


