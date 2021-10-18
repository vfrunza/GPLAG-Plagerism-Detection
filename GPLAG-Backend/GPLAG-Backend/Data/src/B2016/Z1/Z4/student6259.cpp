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

using std::vector;
using std::string;
using std::cin;
using std::cout;

string ObrniFraze(string s, vector<string>vektor) {
	
	return s;
}
int main ()
{	
	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin, recenica);
	vector<string> fraze;
	cout<<"Unesite fraze: ";
	cin.ignore(1000, '\n');
	fraze.resize(1);
	for(int i(0); i<fraze.size(); i++) {
		//fraze.resize(fraze.size()+1);
		getline(cin, fraze.at(i));
		cin.ignore(1);
	}
	
	for(int i(0); i<fraze.size(); i++) {
		cout<<fraze.at(i)<<"  ";
	}
	
	return 0;
}