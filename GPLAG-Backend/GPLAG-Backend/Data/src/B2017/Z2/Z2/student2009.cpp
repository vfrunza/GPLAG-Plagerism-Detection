#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <iomanip>
#include <string>
#include <type_traits>
enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje,
    DoljeGore, LijevoDesno, DesnoLijevo
};
using std::vector;
using std::cin;
using std::cout;
using std::deque;
using std::exception;
using std::endl;

template <typename Kontejner>
Kontejner PjescaniSat(Kontejner kont, SmjerKretanja s){
	for(int i=0; i<kont.size(); i++)
		for(int j=0; j<kont.at(i).size(); j++) {
			if(kont.at(i).size()!=kont.at(i).at(j).size()
			        || kont.at(i).size()!=kont.at(0).size() || kont.size()!=kont.at(i).at(j).size())
				throw std::domain_error("3D matrica nema oblik kocke");
			if(!(kont.at(i).size()&1 && kont.at(i).at(j).size()&1))
				throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		}

	typedef typename std::remove_reference<decltype(kont.at(0))>::type TipK1;
	typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type TipK2;
	try {
		Kontejner A(kont.size(),TipK1(kont.at(0).size()));
		TipK2 pomocni(kont.at(0).at(0).size());

		for(int i=0; i<kont.size(); i++) {
			for(int j=0,z=0; j<kont.at(i).size(); j++) {
				for(int k=0; k<kont.at(i).at(j).size(); k++)
					if(k>=z && k<=kont.at(i).at(j).size()-1-z) {
						if(int(s)==0 || int(s)==1) A.at(i).at(j).push_back(kont.at(j).at(i).at(k));
						else if(int(s)==2 || int(s)==3) A.at(i).at(j).push_back(kont.at(i).at(j).at(k));
						else A.at(i).at(j).push_back(kont.at(i).at(k).at(j));
					}
				if(j<int(kont.at(i).size()/2)) z++;
				else z--;
			}
			if(int(s)==1 || int(s)==3 || int(s)==5) std::reverse(A.at(i).begin(),A.at(i).end());
		}
		return A;
	} catch(...) {
		throw;
	}
}

int main (){
	int n;
	cout << "Unesite dimenziju (x/y/z): ";
	for(;;) {
		cin >> n;
		if(n<0) cout << "Dimenzija nije ispravna, unesite opet: ";
		else break;
	}
	cout << "Unesite elemente kontejnera: ";
	try {
		vector<deque<deque<int>>> X(n,deque<deque<int>>(n,deque<int>(n)));
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=0; k<n; k++)
					cin >> X.at(i).at(j).at(k);
		int smjer;
		cout << "Unesite smjer kretanja [0 - 5]: ";
		for(;;) {
			cin >> smjer;
			if(smjer<0 || smjer>5) cout << "Smjer nije ispravan, unesite opet: ";
			else break;
		}
		cout  << endl;
		vector<deque<deque<int>>> Y {PjescaniSat(X,static_cast<SmjerKretanja>(smjer))};
		cout << "Pjescani sat unesene matrice je: " << endl;
		for(int i=0; i<Y.size(); i++) {
			for(int j=0,z=0; j<Y.at(i).size(); j++) {
				cout << std::string(4*z,' ');
				for(int k=0; k<Y.at(i).at(j).size(); k++)
					cout << std::setw(4) << Y.at(i).at(j).at(k);
				cout << endl;
				if(j<int(Y.at(i).size()/2)) z++;
				else z--;
			}
			cout << endl;
		}
	} catch(exception &ex) {
		cout << "Izuzetak: " << ex.what();
	}
	return 0;
}