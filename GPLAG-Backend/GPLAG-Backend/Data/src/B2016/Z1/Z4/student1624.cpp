#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace::std;

string IzmijeniUPigLatin(string a,vector<string> b)
{
	string recenica = a;
	for(string fraza :b)
	{
		if(find(fraza.begin(),fraza.end(),' ') != fraza.end())
			throw domain_error("Nekorektan izbor rijeci");
		string temp(fraza);
		temp[fraza.length()-1] = fraza[0];
		for(int i = 0; i < fraza.length()-1;i++)
		{
			temp[i] = fraza[i+1];
		}
		string::iterator f(fraza.begin());
		string::iterator pocetak(recenica.begin());
		string::iterator kraj(recenica.end());
		string::iterator it(find(pocetak,kraj,fraza[0]));
		bool treba(true);
		while(it != kraj)
		{
			if(it + fraza.length() > kraj)
				break;
			if(equal(it,it+fraza.length(),f))
			{
				if(it != recenica.begin() && it != recenica.end())
				{
					if((*(it-1) != ' ' || *(it+fraza.length()) != ' ' )&& it+fraza.length() < kraj)
						treba = false;
				}
				
				int poz(it - pocetak);
				if(treba)
				{
				copy(temp.begin(),temp.end(),it);
				recenica.resize(recenica.length()+2);
				pocetak = recenica.begin();
				kraj = recenica.end();
				string::iterator a(recenica.end()-1);
				while(a > pocetak+poz + 1+fraza.length())
				{
					*a = *(a-2);
					a--;
				}
				*a = 'y';
				a--;
				*a = 'a';
				}
			}

			it = find(it+1,kraj,fraza[0]);
		}
	}
	return recenica;
}
string ObrniFraze(string a, vector<string> b)
{
	string recenica = a;
	for(string fraza :b)
	{
		string::iterator f(fraza.begin());
		string::iterator pocetak(recenica.begin());
		string::iterator kraj(recenica.end());
		string::iterator it(find(pocetak,kraj,fraza[0]));

		while(it != kraj)
		{
			if(equal(it,it+fraza.length(),f))
			{
				reverse(it,it+fraza.length());
			}

			it = find(it+1,kraj,fraza[0]);
		}
	}
	return recenica;	
}
int main()
{
	string recenica;
	vector<string> fraze;
	cout << "Unesite recenicu: ";
	getline(cin,recenica);
	cout << "Unesite fraze: ";
	for(;;)
	{
		string a;
		getline(cin, a);
		if(a.empty())
			break;
		fraze.push_back(a);
	}
	string x;
	try
	{
		x = IzmijeniUPigLatin(recenica,fraze);
		cout << "Recenica nakon PigLatin transformacije: " << x << endl;
	}
	catch(const exception& e)
	{
		cout << "Izuzetak: " << e.what() << endl;
	}
	cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,fraze) << endl;
	
	return 0;
}