/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::domain_error;

string Umetni(string recenica, int pozicija, string rijec, int rijecpozicija, int duzina)
{
	for (int i=rijecpozicija; i<duzina; i++)
		recenica.insert(recenica.begin() + pozicija, rijec[i]);
	return recenica;
}

string Obrisi(string recenica, int pozicija, int duzina)
{  
	int brojac(0);
	int i=pozicija;
	while (1)
	{
		recenica.erase(recenica.begin() + i);
		brojac++;
		if (brojac==duzina) break;
	} 
	return recenica;
}

bool DaLiSePojavljuje(string fraza, string recenica)
{
	for (int i=0; i<recenica.length(); i++)
	{
		int j(0);
		if (recenica[i]==fraza[j])
		{
			bool ima(true);
			int brojac(0);
			while (j<fraza.length() and i<recenica.length())
			{
				if (recenica[i]!=fraza[j]) 
				{	
					ima=false;
					break;
				}
				j++;
				i++;
				brojac++;
			}
			i--;
			if (ima and i<recenica.length() and !((recenica[i+1]>='A' and recenica[i+1]<='Z') or (recenica[i+1]>='a' and recenica[i+1]<='z')) 
			and j==fraza.length() and (i-brojac==-1 or !((recenica[i-brojac]>='A' and recenica[i-brojac]<='Z') or (recenica[i-brojac]>='a' and recenica[i-brojac]<='z')))) return true;
			else if (ima and i==recenica.length()-1  and j==fraza.length() and 
			!((recenica[i-brojac]>='A' and recenica[i+1]<='Z') or (recenica[i-brojac]>='a' and recenica[i-brojac]<='z'))) return true;
		}
	}
	return false;
}

int PozicijaodKojePocinjeIzdvajanje(string recenica, string fraza)
{
	for (int i=0; i<recenica.length(); i++)
	{
		int j(0);
		int pozicija;
		if (recenica[i]==fraza[j])
		{
			pozicija=i;
			bool ima(true);
			int brojac(0);
			while (j<fraza.length() and i<recenica.length())
			{
				if (recenica[i]!=fraza[j])
				{
					ima=false;
					break;
				}
				i++;
				j++;
				brojac++;
			}
			i--;
			if (ima and i<recenica.length() and !((recenica[i+1]>='A' and recenica[i+1]<='Z') or (recenica[i+1]>='a' and recenica[i+1]<='z')) 
			and j==fraza.length() and (i-brojac==-1 or !((recenica[i-brojac]>='A' and recenica[i-brojac]<='Z') or (recenica[i-brojac]>='a' and recenica[i-brojac]<='z')))) return pozicija;
			else if (ima and i==recenica.length()-1  and j==fraza.length() and 
			!((recenica[i-brojac]>='A' and recenica[i+1]<='Z') or (recenica[i-brojac]>='a' and recenica[i-brojac]<='z'))) return pozicija;
		}
	}
	return -1;
}

string Sufiks(char znak, string s)
{
	s.resize(3);
	s[0]=znak;
	s[1]='a';
	s[2]='y';
	return s;
}

string ObrnutaFraza(string s)
{
	string pomocni=s;
	int j(0);
	for (int i=s.length()-1; i>=0; i--)
	{
		pomocni[j]=s[i];
		j++;
	}
	return pomocni;
}

bool BaciIzuzetak(string s)
{
	for (int i=0; i<s.length(); i++)
		if (!((s[i]>=65 and s[i]<=90) or (s[i]>=97 and s[i]<=122))) return true;
	return false;
}

string IzmijeniUPigLatin(string recenica, vector<string> fraze)
{
	int pozicija;
	string dodaj{"ay"};
	if (fraze.size()==0)
	{
		bool rijec(false);
		int brslova;
		for (int i=0; i<recenica.length(); i++)
		{
			if ((i==0 or !((recenica[i-1]>='A' and recenica[i-1]<='Z') or (recenica[i-1]>='a' and recenica[i-1]<='z'))) and 
			((recenica[i]>='A' and recenica[i]<='Z') or (recenica[i]>='a' and recenica[i]<='z')) and i<recenica.length()) rijec=true;
			if (rijec) 
			{
				pozicija=i;
				brslova=0;
				while (i<recenica.length() and ((recenica[i]>='A' and recenica[i]<='Z') or (recenica[i]>='a' and recenica[i]<='z'))) 
				{
					i++; 
					brslova++;
				}
				if (i==recenica.length() or !((recenica[i]>='A' and recenica[i]<='Z') or (recenica[i]>='a' and recenica[i]<='z'))) 
				{
					i--;
					string fraza=recenica.substr(pozicija, brslova);
					recenica=Obrisi(recenica, pozicija, fraza.length());
					char znak=fraza[0];
					fraza=Obrisi(fraza, 0, 1);
					dodaj=Sufiks(znak, dodaj);
					fraza+=dodaj;
					recenica=Umetni(recenica, pozicija, ObrnutaFraza(fraza), 0, fraza.length());
				}
			}
			rijec=false;
		}
	}
	else 
	{
		for (int i=0; i<fraze.size(); i++)
		{
			if (BaciIzuzetak(fraze[i])) throw domain_error("Nekorektan izbor rijeci");
			if (DaLiSePojavljuje(fraze[i], recenica))
			{
				string fraza=fraze[i];
				if (PozicijaodKojePocinjeIzdvajanje(recenica, fraza)!=-1) pozicija=PozicijaodKojePocinjeIzdvajanje(recenica, fraza);
				recenica=Obrisi(recenica, pozicija, fraza.length());
				char znak=fraza[0];
				fraza=Obrisi(fraza, 0, 1);
				dodaj=Sufiks(znak, dodaj);
				fraza+=dodaj;
				recenica=Umetni(recenica, pozicija, ObrnutaFraza(fraza), 0, fraza.length());
				i--; 
			}
		}
	} 
	return recenica;
}

string ObrniFraze(string recenica, vector<string> fraze)
{
	for (int i=0; i<fraze.size(); i++)
	{
		string fraza=fraze[i];
		int pozicija;
		for (int j=0; j<recenica.length(); j++)
		{
			int k=0;
			if (recenica[j]==fraza[k])
			{
				bool ima(true);
				pozicija=j;
				int p=j;
				while (k<fraza.length() and j<recenica.length())
				{
					if (recenica[j]!=fraza[k])
					{
						ima=false;
						break;
					}
					k++;
					j++;
				}
				j=p;
				if (ima and k==fraza.length())
				{
					fraza=ObrnutaFraza(fraza);
					recenica=Obrisi(recenica, pozicija, fraza.length());
					recenica=Umetni(recenica, pozicija, ObrnutaFraza(fraza), 0, fraza.length());
					fraza=ObrnutaFraza(fraza);
				}
			}
		}
	}
	return recenica;
}

int main()
{
	string recenica;
	cout << "Unesite recenicu: ";
	getline(cin, recenica);
	vector<string> fraze;
	string s;
	cout << "Unesite fraze: ";
	while(1)
	{
		getline(cin, s);
		if (s.length()!=0) fraze.push_back(s);
		else if (s.length()==0) break;
	}
	try
	{
		string piglatin=IzmijeniUPigLatin(recenica, fraze);
		cout << "Recenica nakon PigLatin transformacije: " << piglatin << endl;
	}
	catch (domain_error izuzetak)
	{
		cout << "Izuzetak: " << izuzetak.what() << endl;
	}
	string obrnifraze=ObrniFraze(recenica, fraze);
	cout << "Recenica nakon obrtanja fraza: " << obrnifraze;
	return 0;
} 