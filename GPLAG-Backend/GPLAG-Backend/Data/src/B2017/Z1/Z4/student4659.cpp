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

using namespace std;

vector<int> indexOf(string s1, string s2) {
	vector<int> index;
	
	for(;;) {
		if(s1.find(s2) == string::npos)
			break;
			
		int stringIndex = s1.find(s2);	
			
		index.push_back(stringIndex);
		
		for(int i=0; i<s2.length(); i++) {
			s1.at(i + stringIndex) = '~';
		}
	}
	
	return index;
}

string Obrnut(string s){
	string pov = "";
	
	for(int i=s.length() - 1; i>=0; i--) 
		pov += s.at(i);
		
	return pov;
}

string NapraviPalindrom(string s, vector<string> v){
	for(int i=0; i<v.size(); i++) {
		string trenutnaRijec = v.at(i);
		
		vector<int> index = indexOf(s, trenutnaRijec);
		
		if(index.size() == 0)
			continue;
			
		
		string tmp = "";
		int currentElement = 0;
		
		for(int j=0; j<s.length() + 1; j++) {
			if(currentElement < index.size() && j == index.at(currentElement) + trenutnaRijec.length()) {
				tmp += Obrnut(trenutnaRijec);
				currentElement++;
			}
			
			if(j < s.length())
				tmp += s.at(j);
		}
		
		s = tmp;
	}
	
	return s;
}

string NapraviPoluPalindrom(string s, vector<string> v){
	for(int i=0; i<v.size(); i++) {
		string trenutnaRijec = v.at(i);
		
		vector<int> index = indexOf(s, trenutnaRijec);
		
		if(index.size() == 0)
			continue;
			
		
		string tmp = "";
		int currentElement = 0;
		
		for(int j=0; j<s.length() + 1; j++) {
			if(j < s.length()) {
				if(currentElement < index.size() && j == index.at(currentElement)) {
					int duzinaRijeci = trenutnaRijec.length();
					int uzmiSrednji = 0;
					
					if(duzinaRijeci%2 != 0) {
						duzinaRijeci--;
						uzmiSrednji = 1;
					}
						
					duzinaRijeci /= 2;
					
					for(int k=0; k<duzinaRijeci; k++) {
						tmp += trenutnaRijec.at(k);
					}
					
					if(uzmiSrednji == 1) {
						tmp += trenutnaRijec.at(duzinaRijeci);
					}
					
					for(int k=duzinaRijeci-1; k>=0; k--) {
						tmp += trenutnaRijec.at(k);
					}
						
					j += trenutnaRijec.length() - 1;
					currentElement++;
				}
				else 
					tmp += s.at(j);	
			}
		}
		
		s = tmp;
	}
	
	return s;
}

int main ()
{
	/*vector<string> v = {"zadaca", "Tehnike programiranja", "drugih predmeta", "proba", "Ovo", "nope", "test"};

	string rez = NapraviPoluPalindrom("Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta", v);

	cout << rez;*/
	cout << "Unesite recenicu: ";
	
	string rec;
	
	getline(cin, rec);

	vector<string> v;
	
	cout << "Unesite fraze: ";

	for(;;) {
		string x;
		
		getline(cin, x);
		

		if(x == "")
			break;
		v.push_back(x);
	}
	
	cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(rec, v) << endl;
	cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(rec, v) << endl;
}