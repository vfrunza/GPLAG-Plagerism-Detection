#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void ObrniRijec (string s)
{
	string izlaz;
	for (int i=izlaz.length()-1; i>=0; i--);
}	


string Obrni_fraze (string s, vector<string> v)
{
	for (int i=0; i<v.size(); i++)
	{
		for (int j=0; j<s.length(); j++)
		{
			
			string s=v[i];
		}
	}
	return s;
}








int main()
{
	string s,fraze;
	vector<string> v;
	cout << "Unesite rijec: ";
	std::getline(std::cin, s);
	cout << "Unesite fraze: ";
	std::getline(std::cin,fraze);
	Obrni_fraze(s,v);
	//ObrniRijec(s);
	for (int i=s.length()-1; i>=0; i--)
	cout << s[i];
	return 0;
}



