/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> izdvojiGadne(vector<int>& niz, bool test ) {
	vector<int> rez;
	if(niz.empty()) return rez;
	
	for(int i = 0; i < niz.size(); i++)
	{
		if(niz[i] ==0)
		{
			if(test == false) rez.push_back(niz[i]);
			continue;
		}
		int pomoc = niz[i];
		int brojevi[3] = {0,0,0};
		while(pomoc !=0)
		{
			int cifra = pomoc % 3;
			pomoc /= 3;
			brojevi[cifra]++;
		}
		
		bool vecIma = false;
		for(int j = 0; j < rez.size(); j++)
		{
			if(niz[i] == rez[j])
			{
				vecIma = true;
				break;
			}
		}
		if(brojevi[0] % 2 == 0 && brojevi[1] % 2 == 0 && test == true && vecIma == false) rez.push_back(niz[i]);
		bool odvratni = true;
		for(int i = 0; i < 3; i++)
		{
			if(brojevi[i] != 0)
			{
				if(brojevi[i] % 2 != 1)
				{
					odvratni = false;
					break;
				}
			}
		}
		if(odvratni == true && test == false && vecIma == false) rez.push_back(niz[i]);
		}
	return rez;
	}
int main() {
	int vel;
	vector<int> niz;
	cin>> vel;
	for(int i = 0; i < vel; i++)
	{
		int help;
		cin >> help;
		niz.push_back(help);
	}
	bool test;
	cin >> test;
	
	vector<int> rjes = izdvojiGadne(niz, test);
	
	for(int i = 0; i < rjes.size(); i++)
	{
		cout << rjes[i] << ", ";
	}
	
	return 0;
}








