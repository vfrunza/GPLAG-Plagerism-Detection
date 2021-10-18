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
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

enum class Polje{ Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina };
enum class Smjerovi {GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status {NijeKraj,KrajPoraz,KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda,NeispravnaKomanda,NeispravanParametar,NedostajeParametar,SuvisanParametar};
enum class Komande {PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int x,vector<vector<int>> &tabla){
	Tabla poljezaminu(x,vector<Polje>(x,Polje::Prazno));
	for(const auto &vek : tabla){
		if(vek.size()!=2)throw domain_error ("Ilegalan format zadavanja mina!");
		if(vek[0]<0 || vek[0]>=x || vek[1]<0 || vek[1]>=x){
			throw domain_error("Ilegalne pozicije mina");
		}
		poljezaminu[vek[0]][vek[1]]=Polje::Mina;
	}
	return poljezaminu;
}
bool LegalnoPolje(const Tabla &poljezaigru,int x,int y){
	if(x>0 && x<poljezaigru.size() && y>0 && y<poljezaigru[x].size()) return true;
	else return false;
}
void ValidirajPolje(const Tabla &polja, int x, int y) {
  if(!LegalnoPolje(polja, x, y))
    throw std::domain_error("Polje (" + to_string(x) + "," + to_string(y) + ") ne postoji");
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
  std::vector<std::vector<int>> m(3, std::vector<int>(3));
  ValidirajPolje(polja, x, y);
  for(int i = x - 1; i <= x + 1; i++)
    for(int j = y - 1; j <= y + 1; j++) {
      int brojac(0);
      for(int p = i - 1; p <= i + 1; p++)
        for(int q = j - 1; q <= j + 1; q++) {
          if(LegalnoPolje(polja, p, q) && !(p == i && q == j) &&
            (polja[p][q] == Polje::Mina || polja[p][q] == Polje::BlokiranoMina))
              brojac++;
        }
      m[i - x + 1][j - y + 1] = brojac;
    }
  return m;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
  ValidirajPolje(polja, x, y);
  if(polja[x][y] < Polje::BlokiranoPrazno)
    polja[x][y] = Polje(int(polja[x][y]) + 3);
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
  ValidirajPolje(polja, x, y);
  if(polja[x][y] >= Polje::BlokiranoPrazno)
    polja[x][y] = Polje(int(polja[x][y]) - 3);
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
  if(!LegalnoPolje(polja, novi_x, novi_y))
    throw std::out_of_range("Izlazak van igrace table");
  if(polja[novi_x][novi_y] >= Polje::BlokiranoPrazno)
    throw std::logic_error("Blokirano polje");
  polja[x][y] = Polje::Posjeceno;
  x = novi_x; y = novi_y;
  if(polja[x][y] == Polje::Mina || polja[x][y] == Polje::BlokiranoMina) {
    for(int i = 0; i < polja.size(); i++)
      for(int j = 0; j < polja[i].size(); j++) polja[i][j] = Polje::Prazno;
    return Status::KrajPoraz;
  }
  bool ima_prazno(false);
  for(int i = 0; i < polja.size(); i++)
    for(int j = 0; j < polja[i].size(); j++)
      if(!(i == x && j == y) && polja[i][j] == Polje::Prazno) ima_prazno = true;
  if(!ima_prazno) return Status::KrajPobjeda;
  return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
  int dx[]{-1, -1, -1, 0, 1, 1, 1, 0};
  int dy[]{-1, 0, 1, 1, 1, 0, -1, -1};
  return Idi(polja, x, y, x + dx[int(smjer)], y + dy[int(smjer)]);
}

void PrijaviGresku(KodoviGresaka greska) {
  const char *tekstovi[] = {"Nerazumljiva komanda!", "Komanda trazi parametar koji nije naveden!",
	"Zadan je suvisan parametar nakon komande!", "Parametar komande nije ispravan!"};
  std::cout << tekstovi[int(greska)] << std::endl;
}

int PreskociRazmake() {
  while(std::cin.peek() == ' ') std::cin.get();
  return std::cin.peek();
}

bool ProcesirajGresku(KodoviGresaka &gdje, KodoviGresaka kod) {
  std::cin.clear(); std::cin.ignore(10000, '\n');
  gdje = kod;
  return false;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
  bool ima_greska(false);
  char znak;
  std::cin >> znak;
  if(znak == 'P') {
    char znak2(std::cin.get());
    if(znak2 == '1') komanda = Komande::PomjeriJednoMjesto;
    else if(znak2 == '>') komanda = Komande::PomjeriDalje;
    else if(znak2 == 'O') komanda = Komande::PrikaziOkolinu;
    else ima_greska = true;
  }
  else if(znak == 'B') komanda = Komande::Blokiraj;
  else if(znak == 'D') komanda = Komande::Deblokiraj;
  else if(znak == 'Z') komanda = Komande::ZavrsiIgru;
  else if(znak == 'K') komanda = Komande::KreirajIgru;
  else ima_greska = true;
  if(ima_greska)
    return ProcesirajGresku(greska, KodoviGresaka::PogresnaKomanda);
  if(komanda == Komande::PomjeriJednoMjesto) {
    if(PreskociRazmake() == '\n')
      return ProcesirajGresku(greska, KodoviGresaka::NedostajeParametar);
    std::string par, legalne[]{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
    std::cin >> par;
    int gdje_je(-1);
    for(int i = 0; i < 8; i++)
      if(legalne[i] == par) gdje_je = i;
    if(gdje_je == -1)
      return ProcesirajGresku(greska, KodoviGresaka::NeispravanParametar);
    smjer = Smjerovi(gdje_je);
  }
  if(komanda == Komande::PomjeriDalje || komanda == Komande::Blokiraj ||
    komanda == Komande::Deblokiraj) {
      if(PreskociRazmake() == '\n')
        return ProcesirajGresku(greska, KodoviGresaka::NedostajeParametar);
      std::cin >> x;
      if(!std::cin)
        return ProcesirajGresku(greska, KodoviGresaka::NeispravanParametar);
      if(PreskociRazmake() == '\n')
        return ProcesirajGresku(greska, KodoviGresaka::NedostajeParametar);
      std::cin >> y;
      if(!std::cin || (std::cin.peek() != ' ' && std::cin.peek() != '\n'))
        return ProcesirajGresku(greska, KodoviGresaka::NeispravanParametar);
  }
  if(PreskociRazmake() != '\n')
    return ProcesirajGresku(greska, KodoviGresaka::SuvisanParametar);
  return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
    Status rezultat(Status::NijeKraj);
    try {
      if(komanda == Komande::PomjeriJednoMjesto) rezultat = Idi(polja, x, y, p_smjer);
      else if(komanda == Komande::PomjeriDalje) rezultat = Idi(polja, x, y, p_x, p_y);
      else if(komanda == Komande::Blokiraj) BlokirajPolje(polja, p_x, p_y);
      else if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja, p_x, p_y);
      else if(komanda == Komande::PrikaziOkolinu) {
        std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) std::cout << okolina[i][j] << " ";
          std::cout << std::endl;
        }
      }
      else if(komanda == Komande::KreirajIgru) {
        int n;
        std::cout << "Unesite broj polja: ";
        std::cin >> n;
        std::vector<std::vector<int>> mine;
        std::cout << "Unesite pozicije mina: ";
        for(;;) {
          char znak;
          bool ima_greska(false);
          int x, y;
          std::cin >> znak;
          if(znak == '.') break;
          if(znak != '(') ima_greska = true;
          if(!ima_greska) {
            std::cin >> x >> znak;
            if(!std::cin || znak != ',') ima_greska = true;
          }
          if(!ima_greska) {
            std::cin >> y >> znak;
            if(!std::cin || znak != ')') ima_greska = true;
          }
          if(ima_greska || x < 0 || x >= n || y < 0 || y >= n) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Greska, unesite ponovo!" << std::endl;
          }
          else mine.push_back({x, y});
        }
        polja = KreirajIgru(n, mine);
      }
      if(komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje)
        std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
    }
    catch(std::domain_error e) {
      std::cout << e.what() << std::endl;
    }
    catch(std::out_of_range e) {
      std::cout << e.what() << std::endl;
    }
    catch(std::logic_error e) {
      std::cout << e.what() << std::endl;
    }
    if(komanda == Komande::PomjeriJednoMjesto || komanda == Komande::PomjeriDalje) {
      if(rezultat == Status::KrajPobjeda)
        std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
      if(rezultat == Status::KrajPoraz)
        std::cout << "Nagazili ste na minu" << std::endl;
      if(rezultat != Status::NijeKraj) komanda = Komande::ZavrsiIgru;
    }
    if(komanda == Komande::ZavrsiIgru) {
      for(int i = 0; i < polja.size(); i++)
        for(int j = 0; j < polja[i].size(); j++) polja[i][j] = Polje::Prazno;
      throw std::runtime_error("Igra zavrsena");
    }
}

int main(){
  try {
    Tabla polja;
    int xpozicija(0), ypozicija(0);
    for(;;) {
      Komande komanda;
      Smjerovi smjer;
      int x, y;
      KodoviGresaka greska;
      std::cout << "Unesite komandu: ";
      if(UnosKomande(komanda, smjer, x, y, greska))
        IzvrsiKomandu(komanda, polja, xpozicija, ypozicija, smjer, x, y);
      else
        PrijaviGresku(greska);
    }
  }
  catch(...) {
    std::cout << "Dovidjenja!" << std::endl;
  }
  return 0;
}
