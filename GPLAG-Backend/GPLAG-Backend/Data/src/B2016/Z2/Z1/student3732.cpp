#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

// Zamjena za bagljivu std::to_string
template <typename T>
  std::string to_string(T x) {
    std::ostringstream s; s << x; return s.str();
  }

enum class Polje {
  Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
  GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
  NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
  PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
  PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
  ZavrsiIgru, KreirajIgru, Debug
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
  Tabla polja(n, std::vector<Polje>(n, Polje::Prazno));
  for(const auto &v : mine) {
    if(v.size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");
    if(v[0] < 0 || v[0] >= n || v[1] < 0 || v[1] >= n)
      throw std::domain_error("Ilegalne pozicije mina");
    polja[v[0]][v[1]] = Polje::Mina;
  }
  return polja;
}

bool LegalnoPolje(const Tabla &polja, int x, int y) {
  return x >= 0 && x < polja.size() && y >= 0 && y < polja[x].size();
}

void ValidirajPolje(const Tabla &polja, int x, int y) {
  if(!LegalnoPolje(polja, x, y))
    throw std::domain_error("Polje (" + to_string(x) + "," + to_string(y) + ") ne postoji");
}

int prebroj_mine(const Tabla &polja,int x,int y) {
	int broj_mina = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if(i+x<0 || i+x>=polja.size())continue;
			if(j+y<0 || j+y>=polja.at(0).size())continue;
			if(polja.at(i+x).at(j+y)==Polje::Mina || polja.at(i+x).at(j+y)==Polje::BlokiranoMina)  {
				broj_mina++;
			}
		}
	}
	return broj_mina;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y) {
  ValidirajPolje(polja, x, y);
	 std::vector<std::vector<int>> izlaz;
	izlaz.resize(3);
	for (int i = 0; i < 3; i++) {
		izlaz.at(i).resize(3);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//moguce da van table moraju biti sve 0
			izlaz.at(i).at(j)=prebroj_mine(polja,i-1+x,j-1+y);
			if(polja.at(i).at(j)==Polje::Mina)izlaz.at(i).at(j)-=1;
		}
	}
	return izlaz;
}

std::vector<std::vector<int>> _PrikaziOkolinu(const Tabla &polja, int x, int y) {
  std::vector<std::vector<int>> m(3, std::vector<int>(3));

  for(int i = x - 1; i <= x + 1; i++)
    for(int j = y - 1; j <= y + 1; j++) {
      int brojac(0);
      for(int p = i - 1; p <= i + 1; p++)
        for(int q = j - 1; q <= j + 1; q++)
          if(LegalnoPolje(polja, p, q) && p != i && q != j &&
            (polja[p][q] == Polje::Mina || polja[p][q] == Polje::BlokiranoMina))
              brojac++;
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

void PreskociRazmake() {
  while(std::cin.peek() == ' ') std::cin.get();
}

bool ProcesirajGresku(KodoviGresaka &gdje, KodoviGresaka kod) {
  std::cin.clear();
  std::cin.ignore(10000, '\n');
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
  else if(znak == '?') komanda = Komande::Debug;
  else ima_greska = true;
  if(ima_greska)
    return ProcesirajGresku(greska, KodoviGresaka::PogresnaKomanda);
  if(komanda == Komande::PomjeriJednoMjesto) {
    PreskociRazmake();
    if(std::cin.peek() == '\n')
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
      PreskociRazmake();
      if(std::cin.peek() == '\n')
        return ProcesirajGresku(greska, KodoviGresaka::NedostajeParametar);
      std::cin >> x;
      if(!std::cin)
        return ProcesirajGresku(greska, KodoviGresaka::NeispravanParametar);
      PreskociRazmake();
      if(std::cin.peek() == '\n')
        return ProcesirajGresku(greska, KodoviGresaka::NedostajeParametar);
      std::cin >> y;
      if(!std::cin || (std::cin.peek() != ' ' && std::cin.peek() != '\n'))
        return ProcesirajGresku(greska, KodoviGresaka::NeispravanParametar);
  }
  PreskociRazmake();
  if(std::cin.peek() != '\n')
    return ProcesirajGresku(greska, KodoviGresaka::SuvisanParametar);
  return true;
}

void ispisiTablu(std::vector<std::vector<Polje> >);
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
  Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
    Status rezultat(Status::NijeKraj);
    try {
      if(komanda == Komande::PomjeriJednoMjesto) rezultat = Idi(polja, x, y, p_smjer);
      else if(komanda == Komande::PomjeriDalje) {
        rezultat = Idi(polja, x, y, p_x, p_y);
      }
      else if(komanda == Komande::Blokiraj) BlokirajPolje(polja, p_x, p_y);
      else if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja, p_x, p_y);
      else if(komanda == Komande::PrikaziOkolinu) {
        std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja, x, y));
        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) std::cout << okolina[i][j] << " ";
          std::cout << std::endl;
        }
      }
      else if(komanda == Komande::Debug)
        for(int i = 0; i < polja.size(); i++) {
          for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
          std::cout << std::endl;
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
};

void ispisiTablu(std::vector<std::vector<Polje>> polja){
   for(int i = 0; i < polja.size(); i++) {
          for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
          std::cout << std::endl;
        }
}

//staviti test gdje se vidi da mora biti blokirano početno polje!
//kreirajIgru (4,2)- testirana: 2 za errore, 1 samo za nju, možda još neki tricky duplo zdavanje mjina ili nešto ili kad se ne zadaju kordinate redom 
//prikazi okolinu (4,2) - granicni, normalni, izuzecim izuzeci negativni
//blokiraj i deblokiraj (5,2) - izuzeci 2x, trivia, blokiranje istog polja, sve varijante
//Idi 4 parametra ( ,1)
int __main(){
 //AT (skriveni) - sve moguce greske u UnosKomande
    while (true) {
      Komande komanda;
      Smjerovi smjer;
      int x = 0, y = 0;
      KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
      UnosKomande(komanda, smjer, x, y, greska);
      if(komanda == Komande::ZavrsiIgru) break;
      std::cout << int(greska) << " ";
    }
}


 //0 0
int main() {
//AT (bonus) - da li je zahardkodiran unos koordinata 
  std::vector<std::vector<int>> mine = {{0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
  std::vector<std::vector<Polje>> tabla = KreirajIgru(3, mine);
  try{
    BlokirajPolje(tabla, 13,13);
  }
   catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
  try{
    DeblokirajPolje(tabla, 133,133);
  }
   catch(std::domain_error e){
    std::cout << e.what() << std::endl;
  }
}
