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

using std::string;
typedef std::vector<string> vs;

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

bool je_slovo(char c) {
	return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

string ObrniFraze(string s, vs fraze) {
	for (string f : fraze) {
		int vel = f.size();
		if (vel < 2) continue;
		for (int i = 0; i < s.size(); i++) {
			if (s.substr(i, vel) != f) continue;
			
			for (int j = 0; j < vel/2; j++)
				swap(&s.at(i + j), &s.at(i + vel - j - 1));
			
			// abb fraza ab
			// bab ili bba
			// treba bab
			// ili ipak bba
			//i += vel;
		}
	}
	return s;
}

string IzmijeniUPigLatin(string s, vs fraze) {
	for (string f : fraze)
		for (char c : f)
			if (!je_slovo(c))
				throw std::domain_error("Nekorektan izbor rijeci");
	
	for (int i = 0; i < s.size(); i++) {
		if (!je_slovo(s.at(i))) continue;
		
		int poc = i;
		while (i < s.size() && je_slovo(s.at(i))) i++;
		int kraj = i;
		
		if (fraze.size() != 0) {
			bool ima = false;
			string rijec = s.substr(poc, kraj - poc);
			for (string f : fraze)
				if (f == rijec)
					ima = true;
			
			if (!ima) continue;
		}
		
		
		char c = s.at(poc);
		for (int j = poc; j+1 < kraj; j++)
			s.at(j) = s.at(j+1);
		s.at(kraj - 1) = c;
		
		string ostatak = "";
		if (kraj < s.size()) 
			ostatak = s.substr(kraj);
		s = s.substr(0, kraj) + "ay" + ostatak;
		i = kraj + 1;
	}
	
	return s;
}

int main() {
	using std::cout;
	using std::cin;
	using std::getline;
	
	cout << "Unesite recenicu: ";
	string s;
	getline(cin, s);
	
	cout << "Unesite fraze: ";
	vs fraze;
	for (;;) {
		string f;
		getline(cin, f);
		if (f.size() == 0) break;
		fraze.push_back(f);
	}
	
	try {
		cout << "Recenica nakon PigLatin transformacije: " 
			 << IzmijeniUPigLatin(s, fraze) << '\n';
	} catch (std::domain_error e) {
		cout << "Izuzetak: " << e.what() << '\n';
	}
	
	cout << "Recenica nakon obrtanja fraza: "
		 << ObrniFraze(s, fraze);
	
	return 0;
}