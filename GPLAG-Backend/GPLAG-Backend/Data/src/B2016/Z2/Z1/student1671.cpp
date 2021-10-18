#include <iostream>
#include <vector>
#include <stdexcept>

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
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
    Tabla T(n, std::vector<Polje>(n, Polje::Prazno));
    for (int i = 0; i < mine.size(); i++) if (mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina"); // provjera formata zadavanja mina
    for (int i = 0; i < mine.size(); i++)
        for (int j = 0; j < mine[i].size(); j++) 
            if (mine[i][j] < 0 || mine[i][j] >= n) throw std::domain_error ("Ilegalne pozicije mina"); // provjera koordinata mina
    for (int i = 0; i < mine.size(); i++) if (!(mine[i][0] == 0 && mine[i][1] == 0)) T[mine[i][0]][mine[i][1]] = Polje::Mina; 
    return T;   
}

void PrijaviGresku(KodoviGresaka &greska) {
    if (greska == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
    else if (greska == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
    else if (greska == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
    else std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
    if (x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
    std::vector<std::vector<int>> Okolina(3);
    int trenutni_red(0);
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            int broj_mina(0);
            for (int p = i-1; p <= i+1; p++) {
                for (int q = j-1; q <= j+1; q++) {
                    if (i >= 0 && j >= 0 && i < polja.size() && j < polja[0].size() && p >= 0 && q >= 0 && p < polja.size() && q < polja[0].size() && !(p == i && q == j) && !(p == x && q == y) && polja[p][q] == Polje::Mina) broj_mina++; 
                }
            }
            Okolina[trenutni_red].push_back(broj_mina);
        }
        trenutni_red++;
    }
    return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
    if (x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
    else if (polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
    else if (polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
    else if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
    if (x < 0 || x >= polja.size() || y < 0 || y >= polja[0].size()) throw std::domain_error ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
    else if (polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
    else if (polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
    else if (polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
    switch (smjer) {
        case Smjerovi::GoreLijevo: if (x - 1 < 0 || y - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x-1][y-1] != Polje::BlokiranoPosjeceno && polja[x-1][y-1] != Polje::BlokiranoPrazno && polja[x-1][y-1] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            x -= 1; y -= 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::Gore: if (x - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x-1][y] != Polje::BlokiranoPosjeceno && polja[x-1][y] != Polje::BlokiranoPrazno && polja[x-1][y] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            x -= 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::GoreDesno: if (x - 1 < 0 || y + 1 >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x-1][y+1] != Polje::BlokiranoPosjeceno && polja[x-1][y+1] != Polje::BlokiranoPrazno && polja[x-1][y+1] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            x -= 1; y += 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::Lijevo: if (y - 1 < 0) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x][y-1] != Polje::BlokiranoPosjeceno && polja[x][y-1] != Polje::BlokiranoPrazno && polja[x][y-1] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            y -= 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::Desno: if (y + 1 >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x][y+1] != Polje::BlokiranoPosjeceno && polja[x][y+1] != Polje::BlokiranoPrazno && polja[x][y+1] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            y += 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::DoljeLijevo: if (x + 1 >= polja.size() || y + 1 >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x+1][y-1] != Polje::BlokiranoPosjeceno && polja[x+1][y-1] != Polje::BlokiranoPrazno && polja[x+1][y-1] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            x += 1; y -= 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::Dolje: if (x + 1 >= polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x+1][y] != Polje::BlokiranoPosjeceno && polja[x+1][y] != Polje::BlokiranoPrazno && polja[x+1][y] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            x += 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
        case Smjerovi::DoljeDesno: if (x + 1 >= polja.size() || y + 1 >= polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja[x+1][y+1] != Polje::BlokiranoPosjeceno && polja[x+1][y+1] != Polje::BlokiranoPrazno && polja[x+1][y+1] != Polje::BlokiranoMina) {
            polja[x][y] = Polje::Posjeceno;
            x += 1; y += 1;
        }
        else throw std::logic_error ("Blokirano polje");
        break;
    }
    if (polja[x][y] == Polje::Mina) {
        for (int i = 0; i < polja.size(); i++) {
            for (int j = 0; j < polja[i].size(); j++) polja[i][j] = Polje::Prazno;
        }
        return Status::KrajPoraz;
    }
    else {
        for (int i = 0; i < polja.size(); i++) {
            for (int j = 0; j < polja[i].size(); j++) if (i != x && j != y && polja[i][j] == Polje::Prazno) return Status::NijeKraj;
        }
        return Status::KrajPobjeda;
    }
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
    if (novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size()) throw std::out_of_range ("Izlazak van igrace table");
    if (polja[novi_x][novi_y] != Polje::BlokiranoPosjeceno && polja[novi_x][novi_y] != Polje::BlokiranoPrazno && polja[novi_x][novi_y] != Polje::BlokiranoMina) {
        x = novi_x; y = novi_y;
    }
    else throw std::logic_error ("Blokirano polje");
    if (polja[x][y] == Polje::Mina) {
        for (int i = 0; i < polja.size(); i++) {
            for (int j = 0; j < polja[i].size(); j++) polja[i][j] = Polje::Prazno;
        }
        return Status::KrajPoraz;
    }
    else {
        for (int i = 0; i < polja.size(); i++) {
            for (int j = 0; j < polja[i].size(); j++) if (i != x && j != y && polja[i][j] == Polje::Prazno) return Status::NijeKraj;
        }
        return Status::KrajPobjeda;
    }
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
    std::string s;
    std::getline(std::cin, s);
    int i(0);
    while (s[i] == ' ') if (++i == s.length()) return false; // dodati tip greske;
    if (s[i] == 'Z' || s[i] == 'K') {
        Komande pomocna;
        if (s[i] == 'Z') pomocna = Komande::ZavrsiIgru;
        else pomocna = Komande::KreirajIgru;
        while (++i < s.length()) {
            if (s[i] != ' ') {
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
            
        }
        komanda = pomocna;
        return true;
    }
    
    else if (s[i] == 'B' || s[i] == 'D') {
        Komande pomocna;
        if (s[i] == 'B') pomocna = Komande::Blokiraj;
        else pomocna = Komande::Deblokiraj;
        i++;
        if (i == s.length()) {
            greska = KodoviGresaka::NedostajeParametar;
            return false;
        }
        while (s[i] == ' ') if (++i == s.length()) {
            greska = KodoviGresaka::NedostajeParametar;
            return false;
        }
        int suma_x(0);
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            suma_x *= 10;
            suma_x += s[i]-'0';   
        }
        while (i < s.length() && !(s[i] >= '0' && s[i] <= '9')) {
            if (s[i] != ' ') {
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }
            i++;
        }
        int suma_y(0);
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            suma_y *= 10;
            suma_y += s[i]-'0';
        }
        while (i < s.length()) {
            if (s[i++] != ' ') {    
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }
        }
        x = suma_x; 
        y = suma_y;
        komanda = pomocna;
        return true;
    }
    
    else if (s[i] == 'P') {
        i++;
        if (i == s.length()) {
            greska = KodoviGresaka::PogresnaKomanda;
            return false;
        }
        Komande pomocna;
        if (s[i] == '>') {
            pomocna = Komande::PomjeriDalje;
            i++;
            if (i == s.length()) {
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
            while (s[i] == ' ') if (++i == s.length()) {
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
            int suma_x(0);
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                suma_x *= 10;
                suma_x += s[i]-'0';
            }
            if (i == s.length()) {
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }
            while (i < s.length() && !(s[i] >= '0' && s[i] <= '9')) {
                if (s[i++] != ' ') {
                    greska = KodoviGresaka::NeispravanParametar;
                    return false;
                } 
            }
            int suma_y(0);
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                suma_y *= 10;
                suma_y += s[i]-'0';
            }
            while (i < s.length()) {
                if (s[i++] != ' ') {
                    greska = KodoviGresaka::NeispravanParametar;
                    return false;
                }
            }
            x = suma_x;
            y = suma_y;
            komanda = pomocna;
        }
        
        else if (s[i] == '1') {
            i++;
            if (i == s.length()) {
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
            while (s[i] == ' ') if (++i == s.length()) {
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
            
            if (s[i] == 'G') {
                i++;
                while (i < s.length() && s[i++] == ' ');
                if (i == s.length()) {
                    komanda = Komande::PomjeriJednoMjesto;
                    smjer = Smjerovi::Gore;
                    return true;
                }
                if (s[i] == 'D' || s[i] == 'L') {
                    Smjerovi pomocna;
                    if (s[i] == 'D') pomocna = Smjerovi::GoreDesno;
                    else pomocna = Smjerovi::GoreLijevo;
                    while (i < s.length()) {
                        if (s[i] != ' ') {
                            greska = KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda = Komande::PomjeriJednoMjesto;
                    smjer = pomocna;
                    return true;
                }
                else {
                    greska = KodoviGresaka::NeispravanParametar;
                    return false;
                }
            }
            
            
            else if (s[i] == 'D') {
                i++;
                while (i < s.length() && s[i++] == ' ');
                if (i == s.length()) {
                    komanda = Komande::PomjeriJednoMjesto;
                    smjer = Smjerovi::Desno;
                    return true;
                }
                if (s[i] == 'o') {
                    i++;
                    if (i == s.length()) {
                        greska = KodoviGresaka::PogresnaKomanda;
                        return false;
                    }
                    Smjerovi pomocna;
                    if (s[i] == 'D') pomocna = Smjerovi::DoljeDesno;
                    else if (s[i] == 'L') smjer = Smjerovi::DoljeLijevo;
                    else {
                        greska = KodoviGresaka::PogresnaKomanda;
                        return false;
                    }
                    i++;
                    while (i < s.length()) {
                        if (s[i] != ' ') {
                            greska = KodoviGresaka::NeispravanParametar;
                            return false;
                        }
                        i++;
                    }
                    smjer = pomocna;
                    komanda = Komande::PomjeriJednoMjesto;
                    return true;
                }
                else {
                    greska = KodoviGresaka::SuvisanParametar;
                    return false;
                }
            }
            
            if (s[i] == 'L') {
               i++;
               while (i < s.length()) {
                   if (s[i] != ' ') {
                       greska = KodoviGresaka::NeispravanParametar;
                       return false;
                   }
                   i++;
               }
               komanda = Komande::PomjeriJednoMjesto;
               smjer = Smjerovi::Lijevo;
               return true;
            }
        }
        
        else if (s[i] == 'O') {
            i++;
            while (i < s.size()) {
                if (s[i] != ' ') {
                    greska = KodoviGresaka::SuvisanParametar;
                    return false;
                }
                i++;
            }
            pomocna = Komande::PrikaziOkolinu;
            return true;
        }
    }
    greska = KodoviGresaka::PogresnaKomanda;
    return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
    if (komanda == Komande::KreirajIgru) {
        int n;
        std::cout << "Unesite broj polja: ";
        std::cin >> n;
        std::cout << "Unesite pozicije mina: ";
        std::vector<std::vector<int>> v;
        while (true) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::string s;
            std::getline(std::cin, s);
            int i(1);
            if (s == ".") break;
            if (s[0] != '(' || s[s.size()-1] != ')') {
                std::cout << "Greska, unesite ponovo!" << std::endl;
                continue;
            }
            int suma_x(0);
            while (s[i] >= '0' && s[i] <= '9') {
                suma_x *= 10;
                suma_x += s[i]-'0';
                i++;
            }
            i++;
            if (s[i-1] != ',') {
                std::cout << "Greska, unesite ponovo!" << std::endl;
                continue;
            }
            int suma_y(0);
            while (s[i] >= '0' && s[i] <= '9') {
                suma_y *= 10;
                suma_y += s[i]-'0';
                i++;
            }
            v.resize(v.size()+1);
            v[v.size()-1].push_back(suma_x);
            v[v.size()-1].push_back(suma_y);
        }
        polja = KreirajIgru(n, v);
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) std::cout << v[i][j] << " ";
            std::cout << std::endl;
        }
    }
    else if (komanda == Komande::ZavrsiIgru) {
        for (int i = 0; i < polja.size(); i++)
            for (int j = 0; j < polja[i].size(); j++) polja[x][y] = Polje::Prazno;
        throw std::runtime_error ("Igra zavrsena\n");
    }
    else if (komanda == Komande::PrikaziOkolinu) {
        auto okolina(PrikaziOkolinu(polja, x, y));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) std::cout << okolina[i][j] << " ";
            std::cout << std::endl;
        }
    }
    else if (komanda == Komande::Blokiraj) {
        BlokirajPolje(polja, x, y);
    }
    else if (komanda == Komande::Deblokiraj) {
        DeblokirajPolje(polja, x, y);
    }
    else if (komanda == Komande::PomjeriDalje) {
        Idi(polja, x, y, p_x, p_y);
        std::cout << "Tekuca pozicija igra je (" << x << ", " << y << ")" << std::endl;
    }
    else if (komanda == Komande::PomjeriJednoMjesto) {
        Idi(polja, x, y, p_smjer);
        std::cout << "Tekuca pozicija igraca je (" << x << ", " << y << ")" << std::endl;
    }
}

int main() {
   
   try {
       Tabla polja;
       while (true) {
           int x, y, p_x, p_y;
           Smjerovi smjer;
           Komande komanda;
           KodoviGresaka greska;
           std::cout << "Unesite komandu: ";
           if (UnosKomande(komanda, smjer, x, y, greska)) IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
           else PrijaviGresku(greska);
       }
       /*do{
       int x, y, p_x, p_y;
       Smjerovi smjer;
       Komande komanda;
       KodoviGresaka greska;
       std::cout << "Unesite komandu: ";
       if (UnosKomande(komanda, smjer, x, y, greska)) IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
       else PrijaviGresku(greska);
       for (int i = 0; i < polja.size(); i++) {
           for (int j = 0; j < polja.size(); i++) {
               if (polja[i][j] == Polje::Prazno) std::cout << "0 ";
               else std::cout << "1 ";
           }
           std::cout << std::endl;
       }
       } while (true);*/
   }
   catch (std::out_of_range) {
       
   }
   catch (std::runtime_error) {
       
   }
    return 0;
}