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

using namespace std;

string IzvrniString(string s)
{
	
    for(int i = 0; i < s.length() / 2; i++)
        swap(s.at(i), s.at(s.length() - i - 1));
        return s;
}
string Izvrni(string s)
{
	string rec;
	int n = s.length() % 2;
	if(n != 0)
		for(int i = s.length() / 2; i >= 0; i--)
			rec.push_back(s.at(i));
	else if(n == 0)
		for(int i = s.length() / 2 - 1; i >= 0; i--)
			rec.push_back(s.at(i));
	
	return rec;
}
int SubString(string str, string sub, int n)
{
	if(str == "" || sub == "")
		return -666;
		
	if(sub.length() > str.length())
		return -1;
	else if(sub.length() == str.length())
		return sub == str;

	for(int i = n < 0 ? 0 : n + 1; i < str.length() - sub.length() + 1; i++)
		{
			int j = 0;
			for(; j < sub.length(); j++)
				if(str.at(i + j) != sub.at(j))
					break;
			if(j == sub.length())
				return i;
		}
		return -1;
}


string NapraviPalindrom(string recenica, std::vector<string> fraze)
{
	for(int i = 0; i < fraze.size(); i++)
	{
		int prosle = -1, tren = -1;
		while(1)
		{
			prosle = tren;
			tren = SubString(recenica, fraze.at(i), prosle);
			
			if(tren >= 0 ) 
		 		recenica.insert(tren + fraze.at(i).length(), IzvrniString(fraze.at(i)));
		 	if(prosle != -1 || prosle == tren ) 
		 		break;
		}
	}
	return recenica;
}
string NapraviPoluPalindrom(string recenica, std::vector<string> fraze)
{
	for(int i = 0; i < fraze.size(); i++)
	{
		int prosli = -1, trenutni = -1;
		while(1)
		{
			prosli = trenutni;
			trenutni = SubString(recenica, fraze.at(i), prosli);
			string tmp = Izvrni(fraze.at(i));
			if(trenutni >= 0)
			{
			    if(fraze.at(i).length() % 2 == 0)
					recenica.replace(trenutni + fraze.at(i).length() /2 , tmp.length() , tmp);
				else 
					recenica.replace(trenutni + fraze.at(i).length() /2 , tmp.length(), tmp);
			}
				
				if(prosli != -1 || prosli == trenutni)
					break;
		}
	}
	return recenica;
}


int main ()
{
	string rec, tmp;
	std::vector<string> fraza ;
	
	cout<<"Unesite recenicu: ";
	getline(cin, rec);
	
	cout<<"Unesite fraze: ";
	
	while(1)
	{
		getline(cin, tmp);
		if(tmp == "")
			break;
		fraza.push_back(tmp);
	}
	
	cout<<"Recenica nakon Palindrom transformacije: ";
	cout<<NapraviPalindrom(rec, fraza)<<endl;
	cout<<"Recenica nakon PoluPalindrom transformacije: ";
	cout<<NapraviPoluPalindrom(rec, fraza)<<endl;
	
	return 0;
}