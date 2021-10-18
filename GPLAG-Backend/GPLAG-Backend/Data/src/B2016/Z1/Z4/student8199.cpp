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

using namespace std;

void Obrni(string &tekst, int p, int k) {
	k--;
	while (p < k) {
		char tmp = tekst[p];
		tekst[p] = tekst[k];
		tekst[k] = tmp;
		k--;
		p++;
	}
}

void PigLatin(string &tekst, int p, int k) {
	string tmp;
	string ay("ay");
	tmp += tekst.substr(0, p);
	tmp += tekst.substr(p + 1, k - p - 1);
	tmp += tekst[p];
	tmp += ay;
	tmp += tekst.substr(k, tekst.size() - k);
	
	tekst = tmp;
}

/*vector<string> Fraze(vector <string> s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == ' ') {
				string k;
				k = s[i].substr(j + 1, s[i].size() - j);
				s.push_back(k);
				k = s[i].substr(0, j);
				s.push_back(k);
				for (int k = j; k < s.size() - 1; k++) {
					s[k] = s[k + 1];
				}
			}
		}
	}
	
	for (int i = 0; i < s.size(); i++) {
		//for (int j = 0; j < s[i].size(); j++) {
			cout << s[i] << endl;;
		//}
	}
	
	return s;
}*/

/*void ObrniFraze(string &tekst, vector<string> fraze) {
	fraze = Fraze (fraze);
	for (int i = 0; i < tekst.size(); i++) {
		if ((tekst[i] >= 'A' && tekst[i] <= 'Z') || (tekst[i] >= 'a' && tekst[i] <= 'z')) {
			int p(i);
			
			while ((tekst[i] >= 'A' && tekst[i] <= 'Z') || (tekst[i] >= 'a' && tekst[i] <= 'z')) i++;
			
			int k(i);
			string tmp;
			tmp = tekst.substr(p, k - p);
			bool there(false);
			
			for (int j = 0; j < fraze.size(); j++) {
				if (fraze[j] == tmp) {
					there = true;
				}
			}
			
			if (there) {
				Obrni(tekst, p, k);
			}
		}
	}
}*/

void ObrniFraze (string &tekst, vector<string> fraze) {
	for (int i = 0; i < tekst.size(); i++) {
		int pom(i);
		for (int j = 0; j < fraze.size(); j++) {
			if (tekst[i] == fraze[j][0]) {
				int p(i), br(0), k(0);
				
				while (tekst[i] == fraze[j][k]) {
					i++;
					k++;
					br++;
				}
				
				int z(i);
				
				//z--;
				k--;
				
				if (br == fraze[j].size()) {
					Obrni(tekst, p, z);
				}
				if (k == fraze[j].size()) {
					Obrni(tekst, p, z - 1);
				}
				i = pom;
			}
			i = pom;
		}
		i = pom;
	}
}


void IzmijeniUPigLatin(string &tekst, vector<string> fraze) {
	for (int i = 0; i < tekst.size(); i++) {
		if ((tekst[i] >= 'A' && tekst[i] <= 'Z') || (tekst[i] >= 'a' && tekst[i] <= 'z')) {
			int p(i);

			while ((tekst[i] >= 'A' && tekst[i] <= 'Z') || (tekst[i] >= 'a' && tekst[i] <= 'z')) i++;

			int k(i);
			string tmp;
			tmp = tekst.substr(p, k - p);
			bool there(false);

			for (int j = 0; j < fraze.size(); j++) {
				if (fraze[j] == tmp) {
					there = true;
				}
			}

			if (there) {
				PigLatin(tekst, p, k);
			}
		}
	}
}

int main ()
{
	string tekst;
	vector<string> fraze(3);
	
	cout << "Unesite recenicu: ";
	getline(cin, tekst);
	
	cout << "Unesite fraze: ";
	while (true) {
		string tmp;
		getline(cin, tmp);
		if (tmp.size() == 0) break;
		fraze.push_back(tmp);
	}
	
	string tekst2(tekst);
	
	ObrniFraze(tekst, fraze);
	
	IzmijeniUPigLatin(tekst2, fraze);
	
	/*for (int i = 0; i < fraze.size(); i++) {
		cout << fraze[i] << endl;
	}*/
	
	cout << "Recenica nakon PigLatin transformacije: "<< tekst2 << endl;
	cout << "Recenica nakon obrtanja fraza: " << tekst << endl;
	
	return 0;
}