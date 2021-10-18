#include <iostream>
#include <vector>

bool DaLiJeProst (int x) {
	if (x < 0) x *= -1;
	if (x<=1) return false;
	for (int i=2; i <= x / 2; i++) 
		if (x%i == 0) return false;
	return true;
}
bool DaLiJeSimetrican (std::vector<int>v1) {
	bool simetricni(true);
	int j(v1.size()-1);
	for (int i = 0; i < v1.size()/2; i++) {
		if(v1.at(i) != v1.at(j)) simetricni=false;
		j--;
	}
	return simetricni;
}
std::vector<int> BrojUTernarni (int br) {
	std::vector<int>v ;
	if (br<0) br*=-1;
	while (br>0) {
		int ostatak = br%3;
		v.push_back(ostatak);
		br/=3;
	}
	return v;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>v1, bool Prosti) {
	if (Prosti==true) {
		for (int i = 0; i < v1.size(); i++) {
			if(! DaLiJeProst(v1.at(i))) {
				v1.erase(v1.begin()+i);
				i--;
			}
		} }
	else 
	{ 
		for (int i = 0; i < v1.size(); i++) {
			if(DaLiJeProst(v1.at(i))) {
				v1.erase(v1.begin()+i);
				i--;
			}
		}
	}
	for(int i=0; i<v1.size(); i++) {
		if(!DaLiJeSimetrican(BrojUTernarni(v1.at(i))))  {
			v1.erase(v1.begin() + i) ;
			i--;
		}
	}
	return v1;
}

int main ()
{
	std::vector<int>v1 ;
	int br;
	 std::cout << "Unesite elemente vektora (-1 za kraj): " ;
	 std::cin >> br;
	 while (br != -1) {
	 	v1.push_back(br);
	 	std::cin >> br;
	 }
	 std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: " ;
	 int unos;
	 bool KojiBiramo;
	 do {
	 std::cin >> unos;
	if (unos != 1 && unos != 0)  std::cout << "Neispravan unos! Unesite ponovo: ";} 
	while (unos != 1 && unos != 0);
	KojiBiramo=unos;
	 std::vector<int>Sredjeni ;
	 Sredjeni=IzdvojiSimetricneTernarne(v1,KojiBiramo);
	 if (KojiBiramo == true)	{if (Sredjeni.empty()) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	  else {
	 	std::cout << "Prosti simetricni brojevi iz vektora su: ";
	 for (int i = 0; i < Sredjeni.size(); i++) {
	 	if(i<Sredjeni.size()-1) std::cout << Sredjeni.at(i) << ", ";
	 	else std::cout << Sredjeni.at(i) << ".";
	 } } }
	 else {if (Sredjeni.empty()) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	 else {
	 	std::cout << "Slozeni simetricni brojevi iz vektora su: " ;
	 for (int i = 0; i < Sredjeni.size(); i++) {
	 	if(i<Sredjeni.size()-1) std::cout << Sredjeni.at(i) << ", ";
	 	else std::cout << Sredjeni.at(i) << ".";
	 }}}
	 
	return 0;
}