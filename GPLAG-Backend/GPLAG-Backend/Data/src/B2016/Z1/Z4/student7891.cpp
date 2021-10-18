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



using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
typedef std::vector<string> VektorStringova;

void IzvrniString(string &s)
{
	char a;
	for(int i=0; i<s.length()/2; i++)
	{
		a=s[i];
		s[i]=s[s.length()-1-i];
		s[s.length()-1-i]=a;
	}
}
void PrvoSlovoNazad(string &s)
{
	char a(s[0]);
	for(int i=0; i<s.length(); i++)
	{
		if(i==s.length()-1) { s[i]=a; break;}
		s[i]=s[i+1];

		
	}
}

string ObrniFraze(string recenica, VektorStringova izrazi)
{
	for(int i=0; i<izrazi.size(); i++)
	{

		for(int j=0; j<recenica.length(); j++)
		{
			while(recenica[j]==' ' && j<recenica.length()) j++;
			int pocetak(0);
			pocetak=j;
			
		
			if(recenica.substr(pocetak,izrazi[i].length()) == izrazi[i])
				{
					
					j=pocetak;
					string rijec=recenica.substr(pocetak,izrazi[i].length());
					IzvrniString(rijec);
					for(int k=0; k<rijec.length(); k++)
					{
						recenica[j]=rijec[k];
						j++;
					}
					j=pocetak;
					
				}
			
			
				
				
			
		}
	}
	return recenica;
}

string IzmijeniUPigLatin(string recenica, VektorStringova izrazi)
{
	for(int i=0; i<izrazi.size(); i++)
	{
		for( int j=0; j<izrazi[i].size(); j++)
		{
			if((izrazi[i][j]<'A' || izrazi[i][j]>'Z') && ( izrazi[i][j]<'a' ||izrazi[i][j]>'z'))
			{
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	
	}
	for(int i=0; i<izrazi.size(); i++)
	{
		for(int j=0; j<recenica.length(); j++)
		{
			while(recenica[j]==' ' && j<recenica.length()) j++;
			int pocetak(0), kraj(0);
			pocetak=j;
			while(recenica[j]!=' ' && j<recenica.length()) j++;
			kraj=j;
			int n=kraj-pocetak;
			if(recenica.substr(pocetak, n)== izrazi[i])
			{
				j=pocetak;
			
				recenica=recenica.substr(0,kraj)+"  "+recenica.substr(kraj,recenica.length());
				
				
				string rijec=recenica.substr(pocetak, n);
				
				PrvoSlovoNazad(rijec);
				rijec=rijec+"ay";
			
				for(int k=0; k<rijec.length(); k++)
					{
						recenica[j]=rijec[k];
						j++;
					}
				j=pocetak;

			}
		}
	}
	return recenica;
}





int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	std::getline(cin,recenica);
	VektorStringova vs;
	string fraza;
	cout<<"Unesite fraze: ";
	do{
		std::getline(cin, fraza);
		if(fraza=="") break;
		vs.push_back(fraza);
	}while(fraza!="");
	string s1=IzmijeniUPigLatin(recenica, vs);
	string s2=ObrniFraze(recenica,vs);
	try{
		
		cout<<"Recenica nakon PigLatin transformacije: "<<s1<<endl;
		
	}
	catch(std::domain_error e)
	{
		cout<<e.what()<<endl;
	}
	cout<<"Recenica nakon obrtanja fraza: "<<s2<<endl;
	
	
	
	return 0;
}