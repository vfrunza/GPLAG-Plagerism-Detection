/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class GradjaninBiH {
	enum Pol {Musko, Zensko};
	std::string ime_i_prezime;
	long long int jmbg;
	int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
	public: 
		GradjaninBiH(std::string, long long int);
		GradjaninBiH(std::string, int, int, int, int, Pol);
		std::string DajImeIPrezime() const;
		long long int DajJMBG() const;
		int DajDanRodjenja() const;
		int DajMjesecRodjenja() const;
		int DajGodinuRodjenja() const;
		int DajSifruRegije() const;
		Pol DajPol() const;
		void PromijeniImeIPrezime(std::string);
};

GradnaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
	jmbg /= 10;
	this->godina_rodjenja = 0;
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		tmp += jmbg % 10;
		tmp *= 10;
		jmbg /= 10;
	}
	tmp /= 10;
	for (int i = 0; i < 3; i++) {
		godina_rodjenja += tmp % 10;
		godina_rodjenja *= 10;
		tmp /= 10;
	}
	godina_rodjenja += 2000;
	if (godina_rodjenja > 2017)
		godina_rodjenja -= 1000;
}

int main () {
	return 0;
}