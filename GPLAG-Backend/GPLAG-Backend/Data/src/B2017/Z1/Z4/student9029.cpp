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
#include <vector>
#include <string>
using namespace std;

int main ()
{
	string recenica;
	cout << "Unesite neku recenicu: ";
	getline(cin,recenica);
	
	vector<string> fraza;
	cout << "Unesite fraze: ";
	int i=0;
	do{
		getline(cin,fraza[i]);
		i++;
		if(fraza[i].length()==0) break;
		
	} while(fraza[i].length()!=0);
	cout << "Recenica glasi: " << recenica << endl;
	cout << "Fraze glase: ";
	for(int i=0; i<fraza.size(); i++) cout << fraza[i] << " ";
	return 0;
}