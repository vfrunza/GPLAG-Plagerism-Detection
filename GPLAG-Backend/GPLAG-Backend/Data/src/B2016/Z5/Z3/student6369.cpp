#include <iostream>
#include <string>

using namespace std;

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

Dani &operator ++(Dani &d) {
 return d = Dani((int(d) + 1) % 7);
}
Dani operator ++(Dani &d, int) {
 Dani pomocni(d); ++d; return pomocni;
}
Dani operator +(Dani d, int n) {
 return Dani((int(d) + n) % 7);
}

ostream& operator <<(ostream &tok, Dani d){
	string niz[7]{"Ponedjeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedjelja"};
	return tok<<niz[d];
}


int main () {
	for(Dani d = Ponedjeljak; d <= Nedjelja; d++) {
		std::cout << d << std::endl;
		if(d==Nedjelja) break; //da ne udje u beskonacnu, jer ce poslije nedjelje vratit na 0 opet i sve tako..
	}
	return 0;
}