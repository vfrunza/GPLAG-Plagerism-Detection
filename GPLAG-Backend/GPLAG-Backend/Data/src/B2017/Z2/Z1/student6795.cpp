#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajIgru(int velicina, Matrica mat)
{
    //Provjera velicine Table
    if(velicina <= 0) throw std::domain_error("Ilegalna veličina");
    //Provjera Matrice za mine
    for(int red(0); red<mat.size(); ++red) if(mat.at(red).size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");

    for(int i(0); i<velicina; ++i) {
        for(int j(0); j<2; ++j) {
            if(mat.at(i).at(j) < 0 || mat.at(i).at(j) >= velicina) throw std::domain_error("Ilegalne pozicije mina");
        }
    }

    //Kraj provjera

    Tabla pocetak_igre(velicina);
    for(int i(0); i<velicina; ++i) {
        pocetak_igre.at(i).resize(velicina);
    }

    for(int i(0); i<velicina; ++i) {
        for(int j(0); j<velicina; ++j) {
            pocetak_igre.at(i).at(j) = Polje::Prazno;
        }
    }

    int red_mine(0), kolona_mine;
    //Miniranje Table
    for(int x(0); x<mat.size(); ++x) {
        for(int y(0); y<2; ++y) {

            if(y == 0) {
                red_mine = mat.at(x).at(0);
                continue;
            }
            if(y == 1) {
                kolona_mine = mat.at(x).at(1);
                pocetak_igre.at(red_mine).at(kolona_mine) = Polje::Mina;
            }
        }
    }

    return pocetak_igre;
}

Matrica PrikaziOkolinu(Tabla igra, int x, int y)
{

    Matrica okolina(3);
    for(int i(0); i<3; ++i) {
        okolina.at(i).resize(3);
    }

    if(x < 0 || x >= igra.size() || x >= igra.at(0).size()) {
        std::string poruka("Polje (");
        std::string iks(std::to_string(x));
        std::string ipsilon(std::to_string(y));
        poruka = poruka + iks + "," + ipsilon + ") ne postoji";
        throw std::domain_error(poruka);
    }
    if(y < 0 || y >= igra.size() || y >= igra.at(0).size()) {
        std::string poruka("Polje (");
        std::string iks(std::to_string(x));
        std::string ipsilon(std::to_string(y));
        poruka = poruka + iks + "," + ipsilon + ") ne postoji";
        throw std::domain_error(poruka);
    }
    --x;
    --y;

    bool preskoci(false);
    int brojac_mina(0);
    for(int i(x); i<3; ++i) {
        for(int j(y); j<3; ++j) {

            if(i-1 < 0) preskoci = true;
            if(!preskoci) {
                if(igra.at(i-1).at(j) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(i-1 < 0 || j + 1 >= igra.at(0).size()) preskoci = true;
            if(!preskoci) {
                if(igra.at(i-1).at(j+1) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(j-1 < 0 || i - 1 < 0) preskoci = true;
            if(!preskoci) {
                if(igra.at(i-1).at(j-1) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(i+1 >= igra.size()) preskoci = true;
            if(!preskoci) {
                if(igra.at(i+1).at(j) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(j+1 >= igra.at(0).size() || j + 1 < 0) preskoci = true;
            if(!preskoci) {
                if(igra.at(i+1).at(j+1) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(j+1 >= igra.at(0).size() || j - 1 < 0) preskoci = true;
            if(!preskoci) {
                if(igra.at(i+1).at(j-1) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(j-1 < 0) preskoci = true;
            if(!preskoci) {
                if(igra.at(i).at(j-1) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            if(j+1 >= igra.at(0).size()) preskoci = true;
            if(!preskoci) {
                if(igra.at(i).at(j+1) == Polje::Mina) brojac_mina++;
            }
            preskoci = false;

            okolina.at(i).at(j) = brojac_mina;
            brojac_mina = 0;
        }
    }

    return okolina;
}

void BlokirajPolje(Tabla &igra, int x, int y)
{
    std::string amar("Sta ima");
    if(x < 0 || x >= igra.size() || x >= igra.at(0).size()) {
        std::string poruka("Polje (");
        std::string iks(std::to_string(x));
        std::string ipsilon(std::to_string(y));
        poruka = poruka + iks + "," + ipsilon + ") ne postoji";
        throw std::domain_error(poruka);
    }
    if(y < 0 || y >= igra.size() || y >= igra.at(0).size()) {
        std::string poruka("Polje (");
        std::string iks(std::to_string(x));
        std::string ipsilon(std::to_string(y));
        poruka = poruka + iks + "," + ipsilon + ") ne postoji";
        throw std::domain_error(poruka);
    }

    if(igra.at(x).at(y) == Polje::Prazno) igra.at(x).at(y) = Polje::BlokiranoPrazno;
    if(igra.at(x).at(y) == Polje::Posjeceno) igra.at(x).at(y) = Polje::BlokiranoPosjeceno;
    if(igra.at(x).at(y) == Polje::Mina) igra.at(x).at(y) = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &igra, int x, int y)
{

    if(x < 0 || x > igra.size() || x > igra.at(0).size()) {
        std::string poruka("Polje (");
        std::string iks(std::to_string(x));
        std::string ipsilon(std::to_string(y));
        poruka = poruka + iks + "," + ipsilon + ") ne postoji";
        throw std::domain_error(poruka);
    }
    if(y < 0 || y >= igra.size() || y >= igra.at(0).size()) {
        std::string poruka("Polje (");
        std::string iks(std::to_string(x));
        std::string ipsilon(std::to_string(y));
        poruka = poruka + iks + "," + ipsilon + ") ne postoji";
        throw std::domain_error(poruka);
    }

    if(igra.at(x).at(y) == Polje::BlokiranoPrazno) igra.at(x).at(y) = Polje::Prazno;
    if(igra.at(x).at(y) == Polje::BlokiranoPosjeceno) igra.at(x).at(y) = Polje::Posjeceno;
    if(igra.at(x).at(y) == Polje::BlokiranoMina) igra.at(x).at(y) = Polje::Mina;
}

enum Status Idi(Tabla &igra, int &x, int &y, enum Smjerovi smjer)
{

    if(smjer == Smjerovi::GoreLijevo) {
        if(x-1 < 0 || y-1 < 0) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        --x;
        --y;
    }

    else if(smjer == Smjerovi::Gore) {
        if(x-1 < 0) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        --x;
    }

    else if(smjer == Smjerovi::GoreDesno) {
        if(x-1 < 0 || y+1 >= igra.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        --x;
        ++y;
    }

    else if(smjer == Smjerovi::Desno) {
        if(y+1 >= igra.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        ++y;
    }

    else if(smjer == Smjerovi::DoljeDesno) {
        if(x+1 >= igra.size() || y+1 >= igra.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        ++x;
        ++y;
    }

    else if(smjer == Smjerovi::Dolje) {
        if(x+1 >= igra.size()) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        ++x;
    }

    else if(smjer == Smjerovi::DoljeLijevo) {
        if(x+1 >= igra.size() || y-1 < 0 ) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        ++x;
        --y;
    }

    else if(smjer == Smjerovi::Lijevo) {
        if(y-1 < 0) throw std::out_of_range("Izlazak van igrace table");
        igra.at(x).at(y) = Polje::Posjeceno;
        --y;
    }

    //Provjera gdje se sada nalazi igrac
    if(igra.at(x).at(y) == Polje::Mina) return Status::KrajPoraz;
    if(igra.at(x).at(y) == Polje::BlokiranoPosjeceno || igra.at(x).at(y) == Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");

    int brojac_praznih(0);
    for(int i(0); i<igra.size(); ++i) {
        for(int j(0); j<igra.at(0).size(); ++j) {
            if(igra.at(i).at(j) == Polje::Prazno) brojac_praznih++;
        }
    }

    if(brojac_praznih == 1) return Status::KrajPobjeda;


    return Status::NijeKraj;
}

enum Status Idi(Tabla &igra, int &x, int &y, int xx, int yy)
{

    if(xx < 0 || xx >= igra.size()) throw std::out_of_range("Izlazak van igrace table");
    else if(yy < 0 || yy >= igra.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
    if(igra.at(xx).at(yy) == Polje::BlokiranoPosjeceno || igra.at(xx).at(yy) == Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");

    igra.at(x).at(y) = Polje::Posjeceno;
    x = xx;
    y = yy;

    //Provjera gdje se sada nalazi igrac
    if(igra.at(x).at(y) == Polje::Mina) return Status::KrajPoraz;

    int brojac_praznih(0);
    for(int i(0); i<igra.size(); ++i) {
        for(int j(0); j<igra.at(0).size(); ++j) {
            if(igra.at(i).at(j) == Polje::Prazno) brojac_praznih++;
        }
    }

    if(brojac_praznih == 1) return Status::KrajPobjeda;


    return Status::NijeKraj;
}

void PrijaviGresku(enum KodoviGresaka greske)
{

    if(greske == KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
    else if(greske == KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
    else if(greske == KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
    else if(greske == KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
    std::string unesena_komanda;
    std::getline(std::cin, unesena_komanda);

    if(unesena_komanda == "Z") {
        komanda = Komande::ZavrsiIgru;
        return true;
    } else if(unesena_komanda == "K") {
        komanda = Komande::KreirajIgru;
        return true;
    } else if(unesena_komanda == "PO") {
        komanda = Komande::PrikaziOkolinu;
        return true;
    }

    //Za P1
    std::string pomocni;
    int pocetno_i(0),brojac(0);
    if(unesena_komanda == "P") {
        return false;
    }
    for(int i(0); i<unesena_komanda.length(); ++i) {

        //ocisti razmake
        if(unesena_komanda.at(i) == ' ') continue;

        if(unesena_komanda.at(i) == 'P' && unesena_komanda.at(i+1) == '1') {
            ++i;
            ++i;
            while(unesena_komanda.at(i) == ' ') ++i;
            pocetno_i = i;
            while(unesena_komanda.at(i) != ' ') {
                ++i;
                ++brojac;
                if(i == unesena_komanda.length()) break;
            }
            pomocni = unesena_komanda.substr(pocetno_i, brojac);

            if(pomocni != "GL" && pomocni != "G" && pomocni != "GD" && pomocni != "D" && pomocni != "DoD" && pomocni != "Do" && pomocni != "DoL" && pomocni != "L") {
                greska = KodoviGresaka::PogresnaKomanda;
                return false;
            }

            if(pomocni == "GL") {
                smjer = Smjerovi::GoreLijevo;
                return true;
            } else if(pomocni == "G") {
                smjer = Smjerovi::Gore;
                return true;
            } else if(pomocni == "GD") {
                smjer = Smjerovi::GoreDesno;
                return true;
            } else if(pomocni == "D") {
                smjer = Smjerovi::Desno;
                return true;
            } else if(pomocni == "DoD") {
                smjer = Smjerovi::DoljeDesno;
                return true;
            } else if(pomocni == "Do") {
                smjer = Smjerovi::Dolje;
                return true;
            } else if(pomocni == "DoL") {
                smjer = Smjerovi::DoljeLijevo;
                return true;
            } else if(pomocni == "L") {
                smjer = Smjerovi::Lijevo;
                return true;
            }
            break;
        } else break;
    }

    pomocni = "";

    //Za P>
    brojac = 0;
    for(int i(0); i<unesena_komanda.length(); ++i) {

        //ocisti razmake
        if(unesena_komanda.at(i) == ' ') continue;

        if(unesena_komanda.at(i) == 'P' && unesena_komanda.at(i+1) == '>') {
            ++i;
            ++i;
            while(unesena_komanda.at(i) == ' ') ++i;
            pocetno_i = i;
            while(unesena_komanda.at(i) >= '0' && unesena_komanda.at(i)<='9') {
                ++i;
                ++brojac;
            }
            pomocni = unesena_komanda.substr(pocetno_i, brojac);
            x = std::stoi(pomocni);
            while(unesena_komanda.at(i) == ' ') ++i;
            brojac = 0;
            pocetno_i = i;
            while(unesena_komanda.at(i) >= '0' && unesena_komanda.at(i)<='9') {
                ++i;
                ++brojac;
                if(i==unesena_komanda.length()) break;
            }
            pomocni = "";
            pomocni = unesena_komanda.substr(pocetno_i, brojac);
            y = std::stoi(pomocni);
        } else break;
    }

    //ZA B
    brojac = 0;
    for(int i(0); i<unesena_komanda.length(); ++i) {

        //ocisti razmake
        if(unesena_komanda.at(i) == ' ') continue;

        if(unesena_komanda.at(i) == 'B' && unesena_komanda.at(i+1) == ' ') {
            ++i;
            ++i;
            while(unesena_komanda.at(i) == ' ') ++i;
            pocetno_i = i;
            while(unesena_komanda.at(i) >= '0' && unesena_komanda.at(i)<='9') {
                ++i;
                ++brojac;
            }
            pomocni = unesena_komanda.substr(pocetno_i, brojac);
            x = std::stoi(pomocni);
            while(unesena_komanda.at(i) == ' ') ++i;
            brojac = 0;
            pocetno_i = i;
            while(unesena_komanda.at(i) >= '0' && unesena_komanda.at(i)<='9') {
                ++i;
                ++brojac;
                if(i==unesena_komanda.length()) break;
            }
            pomocni = "";
            pomocni = unesena_komanda.substr(pocetno_i, brojac);
            y = std::stoi(pomocni);
        } else break;
    }

    //ZA D
    brojac = 0;
    for(int i(0); i<unesena_komanda.length(); ++i) {

        //ocisti razmake
        if(unesena_komanda.at(i) == ' ') continue;

        if(unesena_komanda.at(i) == 'D' && unesena_komanda.at(i+1) == ' ') {
            ++i;
            ++i;
            while(unesena_komanda.at(i) == ' ') ++i;
            pocetno_i = i;
            while(unesena_komanda.at(i) >= '0' && unesena_komanda.at(i)<='9') {
                ++i;
                ++brojac;
            }
            pomocni = unesena_komanda.substr(pocetno_i, brojac);
            x = std::stoi(pomocni);
            while(unesena_komanda.at(i) == ' ') ++i;
            brojac = 0;
            pocetno_i = i;
            while(unesena_komanda.at(i) >= '0' && unesena_komanda.at(i)<='9') {
                ++i;
                ++brojac;
                if(i==unesena_komanda.length()) break;
            }
            pomocni = "";
            pomocni = unesena_komanda.substr(pocetno_i, brojac);
            y = std::stoi(pomocni);
        } else break;
    }

    greska = KodoviGresaka::PogresnaKomanda;


    return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
//   if(komanda == Komande)


}

int main ()
{
    try {
        Tabla igra(0);
        enum Komande komanda;
        enum KodoviGresaka greske;
        enum Smjerovi smjer;
        int x(0), y(0),p_x,p_y;

        //Sve dok se ne unese Z
        while(1) {

            std::cout<<"Unesite komandu: ";
            if(UnosKomande(komanda, smjer, x, y, greske)) {
                if(komanda == Komande::ZavrsiIgru) {
                    std::cout<<"Dovidjenja!";
                    return 0;
                }
                if(komanda == Komande::KreirajIgru) IzvrsiKomandu(komanda, igra, x, y);
            }
            if(greske == KodoviGresaka::PogresnaKomanda) PrijaviGresku(greske);

        }









    } catch(...) {
        std::cout<<"Neocekivani Izuzetak";
    }





    return 0;
}