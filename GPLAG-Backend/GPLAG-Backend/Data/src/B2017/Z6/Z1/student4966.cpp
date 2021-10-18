/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <fstream>
class Spremnik {
protected:
	std::string naziv;
	double vlastitatezina;
public:
	Spremnik(std::string ime, double tezina) : naziv(ime), vlastitatezina(tezina) {}
	double DajTezinu() const {
		return vlastitatezina;
	}
	virtual double DajUkupnuTezinu() const = 0;
	virtual void Ispisi() const = 0;
	virtual ~Spremnik() {}
	virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
};
class Sanduk : public Spremnik {
	std::vector<double> tezinepredmeta;
public:
	Sanduk(double tezina, std::string ime, std::vector<double> tezine) : Spremnik(ime, tezina), tezinepredmeta(std::move(tezine)) {}
	double DajUkupnuTezinu() const override {
		double tezinapr(0);
		std::for_each(tezinepredmeta.begin(), tezinepredmeta.end(), [&tezinapr](double weight) { tezinapr += weight; });
		return DajTezinu() + tezinapr;
	}
	void Ispisi() const override;
	std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
};
class Vreca : public Spremnik {
	double tezinamaterije;
public:
	Vreca(double tezina, std::string naziv, double tezinamaterije) : Spremnik(naziv, tezina), tezinamaterije(tezinamaterije) {}
	double DajUkupnuTezinu() const override {
		return DajTezinu() + tezinamaterije;
	}
	void Ispisi() const override {
		std::cout << "Vrsta spremnika: Vreca" << std::endl << "Sadrzaj: " << naziv << std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)" << std::endl << "Tezina pohranjene materije: " << tezinamaterije << " (kg)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
	}
	std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this); }
};
class Bure : public Spremnik {
	double specificnatezina, zapremina;
public: 
	Bure(double tezina, std::string naziv, double spectezina, double zapremina) : Spremnik(naziv,tezina), specificnatezina(spectezina), zapremina(zapremina) {}
	double DajUkupnuTezinu() const override {
		return DajTezinu() + (specificnatezina / 1000.)*zapremina;
	}
	void Ispisi() const override {
		std::cout << "Vrsta spremnika: Bure\nSadrzaj: " << naziv << "\nVlastita tezina: " << DajTezinu() << " (kg)\nSpecificna tezina tecnosti: " << specificnatezina << " (kg/m^3)\nZapremina tecnosti: " << zapremina << " (l)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
	}
	std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure>(*this); }
};
class Skladiste {
	std::vector<std::shared_ptr<Spremnik>> spremnici;
public:
	Skladiste() {}
	Skladiste(const Skladiste &s);
	Skladiste(Skladiste &&s);
	Skladiste &operator =(const Skladiste &s);
	Skladiste &operator =(Skladiste &&s);
	Spremnik* DodajSanduk(double tezina, std::string ime, std::vector<double> tezine);
	Spremnik* DodajVrecu(double tezina, std::string naziv, double tezinamaterije);
	Spremnik* DodajBure(double tezina, std::string naziv, double spectezina, double zapremina);
	Spremnik* DodajSpremnik(Spremnik* pok, bool daLiSePredajeKlasi);
	void BrisiSpremnik(Spremnik* pok);
	Spremnik& DajNajlaksi();
	Spremnik& DajNajtezi();
	int BrojPreteskih(int broj) const;
	void IzlistajSkladiste() const;
	void UcitajIzDatoteke(std::string nazivdat);
	~Skladiste() {}
};
int main()
{
	Skladiste skladiste;
	std::string s("ROBA.TXT");
	skladiste.UcitajIzDatoteke(s);
	skladiste.IzlistajSkladiste();
    return 0;
}

// IMPLEMENTACIJA
	//Sanduk::public
void Sanduk::Ispisi() const {
	std::cout << "Vrsta spremnika: Sanduk" << std::endl << "Sadrzaj: " << naziv << std::endl << "Tezine predmeta: ";
	std::for_each(tezinepredmeta.begin(), tezinepredmeta.end(), [](double weight) { std::cout << weight << " "; });
	std::cout <<"(kg)"<< std::endl << "Vlastita tezina: " << DajTezinu() << " (kg)"<<std::endl << "Ukupna tezina: " << DajUkupnuTezinu() <<" (kg)"<<std::endl;
}

	//Skladiste::public
Skladiste::Skladiste(const Skladiste &s) {
	for (int i = 0; i < s.spremnici.size(); i++) {
		spremnici.push_back(s.spremnici[i]->DajKopiju());
	}
}
Skladiste::Skladiste(Skladiste &&s) : spremnici(std::move(s.spremnici)) { s.spremnici.clear(); }
Skladiste& Skladiste::operator =(const Skladiste &s) {
	spremnici.clear();
	for (int i = 0; i < s.spremnici.size(); i++) {
		spremnici.push_back(s.spremnici[i]->DajKopiju());
	}
	return *this;
}
Skladiste& Skladiste::operator =(Skladiste &&s) {
	std::swap(spremnici, s.spremnici);
	return *this;
}
Spremnik* Skladiste::DodajSanduk(double tezina, std::string ime, std::vector<double> tezine) {
	spremnici.push_back(std::make_shared<Sanduk>(tezina, ime, tezine));
	return &(*spremnici[spremnici.size() - 1]);
}
Spremnik* Skladiste::DodajBure(double tezina, std::string naziv, double spectezina, double zapremina) {
	spremnici.push_back(std::make_shared<Bure>(tezina, naziv, spectezina, zapremina));
	return &(*spremnici[spremnici.size() - 1]);
}
Spremnik* Skladiste::DodajVrecu(double tezina, std::string naziv, double tezinamaterije) {
	spremnici.push_back(std::make_shared<Vreca>(tezina, naziv, tezinamaterije));
	return &(*spremnici[spremnici.size() - 1]);
}
Spremnik* Skladiste::DodajSpremnik(Spremnik* pok, bool daLiSePredajeKlasi) {
	if (daLiSePredajeKlasi) 
		spremnici.push_back(std::shared_ptr<Spremnik>(pok));
	else 
		spremnici.push_back(pok->DajKopiju());
	return &(*spremnici[spremnici.size() - 1]);
}
void Skladiste::BrisiSpremnik(Spremnik* pok) {
	for (auto it = spremnici.begin(); it != spremnici.end(); it++) 
		if (&(**it) == pok) { spremnici.erase(it); break; }
}
Spremnik& Skladiste::DajNajlaksi() {
	if (spremnici.empty()) throw std::range_error("Skladiste je prazno");
	return **std::min_element(spremnici.begin(), spremnici.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) {
		return (p1->DajTezinu() < p2->DajTezinu());
	});
}
Spremnik& Skladiste::DajNajtezi() {
	if (spremnici.empty()) throw std::range_error("Skladiste je prazno");
	return **std::max_element(spremnici.begin(), spremnici.end(), [](std::shared_ptr<Spremnik> p1, std::shared_ptr<Spremnik> p2) {
		return (p1->DajTezinu() < p2->DajTezinu());
	});
}
int Skladiste::BrojPreteskih(int broj) const {
	int brojvecih(0);
	for (int i = 0; i < spremnici.size(); i++) {
		if (spremnici[i]->DajUkupnuTezinu()>broj) brojvecih++;
	}
	return brojvecih;
}
void Skladiste::IzlistajSkladiste() const {
	std::vector<std::shared_ptr<Spremnik>> temp(spremnici);
	std::sort(temp.begin(),temp.end(),[](std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) { return pok1->DajUkupnuTezinu()>pok2->DajUkupnuTezinu();});
	std::for_each(temp.begin(), temp.end(), [](std::shared_ptr<Spremnik> p) { p->Ispisi(); });
}
void Skladiste::UcitajIzDatoteke(std::string nazivdat) {
	std::ifstream datoteka(nazivdat);
	if (!datoteka) throw std::logic_error("Trazena datoteka ne postoji");
	char znak;
	std::string ime;
	std::vector<std::shared_ptr<Spremnik>> spremnici2;
	while (datoteka >> znak && std::getline(datoteka, ime)) {
		if (znak == 'S') {
			double tezina;
			int brojpr;
			std::vector<double> tezine;
			datoteka >> tezina >> brojpr;
			if (!datoteka) throw std::logic_error("Datoteka sadrzi besmislene podatke");
			for (int i = 0; i < brojpr; i++) {
				double tezinapr;
				datoteka >> tezinapr;
				tezine.push_back(tezinapr);
			}
			if (!datoteka) throw std::logic_error("Datoteka sadrzi besmislene podatke");
			spremnici2.push_back(std::make_shared<Sanduk>(tezina, ime, tezine));
			datoteka.ignore(100, '\n');
		}
		else if (znak == 'V') {
			double tezinavrece, tezinamaterije;
			datoteka >> tezinavrece >> tezinamaterije;
			if (!datoteka) throw std::logic_error("Datoteka sadrzi besmislene podatke");
			spremnici2.push_back(std::make_shared<Vreca>(tezinavrece, ime, tezinamaterije));
			datoteka.ignore(100, '\n');
		}
		else if (znak == 'B') {
			double tezinabureta, specgustina, zapremina;
			datoteka >> tezinabureta >> specgustina >> zapremina;
			if (!datoteka) throw std::logic_error("Datoteka sadrzi besmislene podatke");
			spremnici2.push_back(std::make_shared<Bure>(tezinabureta, ime, specgustina, zapremina));
			datoteka.ignore(100, '\n');
		}
		else throw std::logic_error("Datoteka sadrzi besmislene podatke");
	}
	if (datoteka.bad()) throw std::logic_error("Problemi pri citanju datoteke");
	spremnici.clear();
	spremnici=std::move(spremnici2);
}