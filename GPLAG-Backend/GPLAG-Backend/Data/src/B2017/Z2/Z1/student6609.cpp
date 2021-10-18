/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo 
};

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};



typedef std::vector<std::vector<Polje>> Tabla;


bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) {
	Tabla polja (n, std::vector<Polje> (n, Polje::Prazno));
	for (const auto &v : mine) {
		if (v.size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
		if (v.at(0)<0 || v.at(0)>=n || v.at(1)<0 || v.at(1)>=n) throw std::domain_error ("Ilegalna pozicija mina");
		polja.at(v.at(0)).at(v.at(1));
	}
	return polja;
}


std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y);


void BlokirajPolje (Tabla &polja, int x, int y);


void DeblokirajPolje (Tabla &polja, int x, int y);


Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer);


Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y);


void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

void PrijaviGresku (KodoviGresaka greska) {
	const char *tekstovi[] = {"Nerazumljiva komanda!", "Komanda trazi parametar koji nije naveden!",
							"Zadan je suvisan parametar nakon komande!", "Parametar komande nije ispravan!"};
	std::cout << tekstovi[int(greska)] << std::endl;
}


int main ()
{
	/*try {
		Tabla polja;
		int x_poz(0), y_poz(0);
		for (;;) {
			Komande komanda;
			Smjerovi smjer;
			int x, y;
			KodoviGresaka greska;
			std::cout << "Unesite komandu: ";
			if (UnosKomande(komanda, smjer, x, y, greska))
				IzvrsiKomandu(komanda, polja, x_poz, y_poz, smjer, x, y);
			else PrijaviGresku(greska);
		}
	}
	catch (...) {
		std::cout << "Dovidjenja!" << std::endl;
	}*/
	return 0;
}