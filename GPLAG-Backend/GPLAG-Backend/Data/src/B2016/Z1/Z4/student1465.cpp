/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

string ObrniFraze(string recenica, vector<string> spisak_fraza)
{
	for(int i = 0; i < spisak_fraza.size(); i++) {
		for(int pocetak_substr = 0; pocetak_substr < recenica.length(); pocetak_substr++) {
			for(int duzina_substr = 1; duzina_substr < recenica.length() - pocetak_substr + 1; duzina_substr++) {
				if(recenica.substr(pocetak_substr, duzina_substr) == spisak_fraza.at(i)) {
					int pocetak{pocetak_substr}, kraj{pocetak_substr + duzina_substr - 1};
					while(pocetak < kraj) {
						char pomocni;
						pomocni = recenica[pocetak];
						recenica[pocetak] = recenica[kraj];
						recenica[kraj] = pomocni;
						pocetak++;
						kraj--;
					}
				}
			}
		}
	}
	return recenica;
}

string IzmijeniUPigLatin(string recenica, vector<string> spisak_rijeci)
{
	for(int s = 0; s < spisak_rijeci.size(); s++) {
		{
			for(int t = 0; t < spisak_rijeci[s].size(); t++) {
				if((spisak_rijeci[s][t] < 'a' && spisak_rijeci[s][t] > 'Z') || spisak_rijeci[s][t] < 'A' || spisak_rijeci[s][t] >'z') 
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci\n");
			}
		}
	}
	for(int i = 0; i < spisak_rijeci.size(); i++) {
		for(int pocetak_substr = 0; pocetak_substr < recenica.length(); pocetak_substr++) {
			for(int duzina_substr = 1; duzina_substr < recenica.length() - pocetak_substr; duzina_substr++) {
					if((recenica.substr(pocetak_substr, duzina_substr) == spisak_rijeci.at(i)) && ((pocetak_substr == 0 && ((recenica[pocetak_substr] > 'A' && recenica[pocetak_substr] < 'Z') || (recenica[pocetak_substr] > 'a' && recenica[pocetak_substr] < 'z'))) || ((pocetak_substr > 0) && ((recenica[pocetak_substr - 1] < 'a' && recenica[pocetak_substr - 1] > 'Z') || (recenica[pocetak_substr - 1] < 'A' || recenica[pocetak_substr - 1] > 'z') && ((recenica[pocetak_substr] > 'a' && recenica[pocetak_substr] < 'z') || (recenica[pocetak_substr] > 'A' && recenica[pocetak_substr] < 'Z')))))) {
					char prvo_slovo = recenica[pocetak_substr];
					recenica.erase(pocetak_substr, 1);
					recenica.insert(pocetak_substr + duzina_substr - 1, 1, prvo_slovo);
					recenica.insert(pocetak_substr + duzina_substr, "ay");
				}
			}
		}
	}
	return recenica;
}
	int main () {
		string recenica;
		cout << "Unesite recenicu: ";
		getline(cin, recenica);
		vector <string> spisak_fraza;
		cout << "Unesite fraze: ";
		try {
			while(1) {
			string rijec;
			getline(cin, rijec);
			spisak_fraza.push_back(rijec);
			if(cin.peek() == '\n') break;
			}
			string nova_recenica = recenica;
			nova_recenica = IzmijeniUPigLatin(nova_recenica, spisak_fraza);
			cout << "Recenica nakon PigLatin transformacije: ";
			cout << nova_recenica << endl;
		}
		catch(domain_error izuzetak) {
			cout << izuzetak.what();
		}
		cout << "Recenica nakon obrtanja fraza: ";
		recenica = ObrniFraze(recenica, spisak_fraza);
		cout << recenica << endl;
		return 0;
	}