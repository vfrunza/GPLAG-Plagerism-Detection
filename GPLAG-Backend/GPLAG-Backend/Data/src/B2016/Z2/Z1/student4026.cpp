/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>

typedef std::vector<std::vector<Polje>> Tabla;

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina,
};

enum class Smjerovi {
	GoreLijevo, Gre, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};




int main ()
{
	Tabla KreirajIgru (int n, const std::vector<std::vector<std::vector<int>> &mine);
	std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y);
	void BlokirajPolje (Tabla &polja, int x, int y);
	void DeblokirajPolje (Tabla &polja, int x, int y);
	Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
	Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y);
	std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y);
	
	bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y,
	  KodoviGresaka &greska);
	  
	enum class Komande {
		PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
		ZavrsiIgru, KreirajIgru
	};
	
	void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
	  Smjerovi P_smjer = Smjerovi::Gore, int P_x = 0, int p_y = 0);
	return 0;
}