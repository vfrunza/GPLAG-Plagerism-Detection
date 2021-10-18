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
    PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru (int n,const std::vector<std::vector<int>> &mine)
{
    Tabla mapa;
    if (n<=0) throw std::domain_error("Ilegalna velicina");
    mapa.resize(n);
    for (int i=0; i<mapa.size(); i++) {
        mapa.at(i).resize(n);
    }
    for (int i=0; i<mapa.size(); i++) {
        for (int j=0; j<mapa.at(i).size(); j++) {
            mapa.at(i).at(j)=Polje::Prazno;
        }
    }
    for (int i=0; i<mine.size(); i++) {
        if (mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
    }
    for (int i=0; i<mine.size(); i++) {
        int x(mine.at(i).at(0));
        int y(mine.at(i).at(1));
        if (x>n || y>n) throw std::domain_error("Ilegalne pozicije mina");
        mapa.at(x).at(y)=Polje::Mina;
    }
    return mapa;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    if (x>polja.size() || y>polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
    std::vector<std::vector<int>> okolina (3,std::vector<int>(3));
    int brx=x-1;
    int bry=y-1;
    for (int i=0; i<okolina.size(); i++) {
        for (int j=0; j<okolina.at(i).size(); j++) {
            int brojac=0;
            if (brx-1>=0 && bry-1>=0 && polja.at(brx-1).at(bry-1)==Polje::Mina) brojac++;
            if (brx-1>=0 && bry>=0 && polja.at(brx-1).at(bry)==Polje::Mina) brojac++;
            if (brx-1>=0 && bry+1>=0 && bry+1<polja.size() && polja.at(brx-1).at(bry+1)==Polje::Mina) brojac++;
            if (bry-1>=0 && brx>=0 && polja.at(brx).at(bry-1)==Polje::Mina) brojac++;
            if (brx>=0 && bry+1>=0 && bry<polja.size() && polja.at(brx).at(bry+1)==Polje::Mina) brojac++;
            if (bry-1>=0 && brx+1>=0 && brx+1<polja.size() && polja.at(brx+1).at(bry-1)==Polje::Mina) brojac++;
            if (brx+1>=0 && bry>=0 && brx+1<polja.size() && polja.at(brx+1).at(bry)==Polje::Mina) brojac++;
            if (brx+1>=0 && bry+1>=0 && brx+1<polja.size() && bry+1<polja.size() && polja.at(brx+1).at(bry+1)==Polje::Mina) brojac++;
            okolina.at(i).at(j)=brojac;
            bry++;
            if (bry>y+1) {
                bry=y-1;
                brx++;
            }
            if (brx>x+1) return okolina;
        }
    }

    return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
    if (x>polja.size() || y>polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
    if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
    else if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
    else if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
    if (x>polja.size() || y>polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
    if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
    else if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
    else if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    if (smjer==Smjerovi::GoreLijevo) {
        if (x-1<0 || y-1<0 || x-1>=polja.size() || y-1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        x--;
        y--;
    } else if (smjer==Smjerovi::Gore) {
        if (x-1<0 || y<0 || x-1>=polja.size() || y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        x--;
    } else if (smjer==Smjerovi::GoreDesno) {
        if (x-1<0 || y+1<0 || x-1>=polja.size() || y+1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        x--;
        y++;
    } else if (smjer==Smjerovi::Desno) {
        if (x<0 || y+1<0 || x>=polja.size() || y+1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y+1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        y++;
    } else if (smjer==Smjerovi::DoljeDesno) {
        if (x+1<0 || y+1<0 || x+1>=polja.size() || y+1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        x++;
        y++;
    } else if (smjer==Smjerovi::Dolje) {
        if (x+1<0 || y<0 || x+1>=polja.size() || y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        x++;
    } else if (smjer==Smjerovi::DoljeLijevo) {
        if (x+1<0 || y-1<0 || x+1>=polja.size() || y-1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        x++;
        y--;
    } else if (smjer==Smjerovi::Lijevo) {
        if (x<0 || y-1<0 || x>=polja.size() || y-1>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
        if (polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
        polja.at(x).at(y)=Polje::Posjeceno;
        y--;
    }
    if (polja.at(x).at(y)==Polje::Mina) {
        for (int i=0; i<polja.size(); i++) {
            for (int j=0; j<polja.at(i).size(); j++) {
                polja.at(i).at(j)=Polje::Prazno;
            }
        }
        return Status::KrajPoraz;
    }
    for (int i=0; i<polja.size(); i++) {
        for (int j=0; j<polja.at(i).size(); j++) {
            if (polja.at(i).at(j)==Polje::Prazno)
                return Status::NijeKraj;
        }
    }
    return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y,int novi_x, int novi_y)
{
    if (novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
    if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
    x=novi_x;
    y=novi_y;
    polja.at(x).at(y)=Polje::Posjeceno;
    if (polja.at(x).at(y)==Polje::Mina) {
        for (int i=0; i<polja.size(); i++) {
            for (int j=0; j<polja.at(i).size(); j++) {
                polja.at(i).at(j)=Polje::Prazno;
            }
        }
        return Status::KrajPoraz;
    }
    for (int i=0; i<polja.size(); i++) {
        for (int j=0; j<polja.at(i).size(); j++) {
            if (polja.at(i).at(j)==Polje::Prazno)
                return Status::NijeKraj;
        }
    }
    return Status::KrajPobjeda;
}

void PrijaviGresku (KodoviGresaka &greska)
{
    if (greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
    else if (greska==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!";
    else if (greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan! ";
    else if (greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)
{
    std::string unos;
    std::getline(std::cin,unos);
    for (int i=0; i<=unos.length(); i++) {
        if (unos.at(i)==' ') continue;
        if (unos.at(i)=='P' || unos.at(i)=='K' || unos.at(i)=='B' || unos.at(i)=='Z' || unos.at(i)=='D') {
            if (unos.at(i)=='K') {
                if (i==unos.length()-1) {
                    komanda=Komande::KreirajIgru;
                    return true;
                }
                i++;
                if (unos.at(i)==' ') {
                    while (unos.at(i)==' ') {
                        i++;
                        if (i==unos.length()) {
                            komanda=Komande::KreirajIgru;
                            return true;
                        }
                        if (unos.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                    }
                } else {
                    greska=KodoviGresaka::SuvisanParametar;
                    return false;
                }
            }


            if (unos.at(i)=='Z') {
                if (i==unos.length()-1) {
                    komanda=Komande::ZavrsiIgru;
                    return true;
                }
                i++;
                if (unos.at(i)==' ') {
                    while (unos.at(i)==' ') {
                        i++;
                        if (i==unos.length()) {
                            komanda=Komande::ZavrsiIgru;
                            return true;
                        }
                        if (unos.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                    }
                } else {
                    greska=KodoviGresaka::SuvisanParametar;
                    return false;
                }
            }


            if (unos.at(i)=='B') {
                int br1,br2;
                for (int i=0; i<unos.length(); i++) {
                    if (unos.at(i)==' ') continue;
                    if (isdigit(unos.at(i))) {
                        br1=unos.at(i)-'0';
                        i++;
                        if (unos.at(i)==' ') {
                            while (unos.at(i)==' ') {
                                i++;
                            }
                            if (isdigit(unos.at(i))) {
                                br2=unos.at(i)-'0';
                                if (i==unos.length()-1) {
                                    komanda=Komande::Blokiraj;
                                    x=br1;
                                    y=br2;
                                    return true;
                                }
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                        if (i==unos.length()) {
                                            komanda=Komande::Blokiraj;
                                            x=br1;
                                            y=br2;
                                            return true;
                                        }
                                    }
                                } else {
                                    greska=KodoviGresaka::SuvisanParametar;
                                    return false;
                                }
                            } else {
                                greska=KodoviGresaka::NedostajeParmetar;
                                return false;
                            }
                        } else {
                            greska=KodoviGresaka::NedostajeParmetar;
                            return false;
                        }
                    } else {
                        greska=KodoviGresaka::NedostajeParmetar;
                        return false;
                    }
                }
            }


            if (unos.at(i)=='D') {
                int br1,br2;
                for (int i=0; i<unos.length(); i++) {
                    if (unos.at(i)==' ') continue;
                    if (isdigit(unos.at(i))) {
                        br1=unos.at(i)-'0';
                        i++;
                        if (unos.at(i)==' ') {
                            while (unos.at(i)==' ') {
                                i++;
                            }
                            if (isdigit(unos.at(i))) {
                                br2=unos.at(i)-'0';
                                if (i==unos.length()-1) {
                                    komanda=Komande::Deblokiraj;
                                    x=br1;
                                    y=br2;
                                    return true;
                                }
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                        if (i==unos.length()) {
                                            komanda=Komande::Deblokiraj;
                                            x=br1;
                                            y=br2;
                                            return true;
                                        }
                                    }
                                } else {
                                    greska=KodoviGresaka::SuvisanParametar;
                                    return false;
                                }
                            } else {
                                greska=KodoviGresaka::NedostajeParmetar;
                                return false;
                            }
                        } else {
                            greska=KodoviGresaka::NedostajeParmetar;
                            return false;
                        }
                    } else {
                        greska=KodoviGresaka::NedostajeParmetar;
                        return false;
                    }
                }
            }

            if (unos.at(i)=='P') {
                for(int i=0; i<unos.size(); i++) {
                    if (unos.at(i)==' ') {
                        while (unos.at(i)==' ') i++;
                    }
                    if (unos.at(i)=='O') {
                        if (i==unos.length()-1) {
                            komanda=Komande::PrikaziOkolinu;
                            return true;
                        }
                        i++;
                        if (unos.at(i)==' ') {
                            while (unos.at(i)==' ') {
                                i++;
                                if (i==unos.length()) {
                                    komanda=Komande::PrikaziOkolinu;
                                    return true;
                                } else {
                                    greska=KodoviGresaka::SuvisanParametar;
                                    return false;
                                }
                            }
                        } else {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                    } else if (unos.at(i)=='>') {
                        int br1,br2;
                        for (int i=0; i<unos.length(); i++) {
                            if (unos.at(i)==' ') continue;
                            if (isdigit(unos.at(i))) {
                                br1=unos.at(i)-'0';
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                    }
                                    if (isdigit(unos.at(i))) {
                                        br2=unos.at(i)-'0';
                                        if (i==unos.length()-1) {
                                            komanda=Komande::Deblokiraj;
                                            x=br1;
                                            y=br2;
                                            return true;
                                        }
                                        i++;
                                        if (unos.at(i)==' ') {
                                            while (unos.at(i)==' ') {
                                                i++;
                                                if (i==unos.length()) {
                                                    komanda=Komande::Deblokiraj;
                                                    x=br1;
                                                    y=br2;
                                                    return true;
                                                }
                                            }
                                        } else {
                                            greska=KodoviGresaka::SuvisanParametar;
                                            return false;
                                        }
                                    } else {
                                        greska=KodoviGresaka::NedostajeParmetar;
                                        return false;
                                    }
                                } else {
                                    greska=KodoviGresaka::NedostajeParmetar;
                                    return false;
                                }
                            } else {
                                greska=KodoviGresaka::NedostajeParmetar;
                                return false;
                            }
                        }
                    }



                    else if (unos.at(i)=='1') {
                        for (int i=0; i<unos.length(); i++) {
                            if (unos.at(i)==' ') continue;
                            if (unos.at(i)=='G') {
                                if (i==unos.length()-1) {
                                    komanda=Komande::PomjeriJednoMjesto;
                                    smjer=Smjerovi::Gore;
                                    return true;
                                }
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                        if (i==unos.length()) {
                                            komanda=Komande::PomjeriJednoMjesto;
                                            smjer=Smjerovi::Gore;
                                            return true;
                                        }
                                    }
                                }
                                if (unos.at(i)=='L') {
                                    if (i==unos.length()-1) {
                                        komanda=Komande::PomjeriJednoMjesto;
                                        smjer=Smjerovi::GoreLijevo;
                                        return true;
                                    }
                                    i++;
                                    if (unos.at(i)==' ') {
                                        while (unos.at(i)==' ') {
                                            i++;
                                            if (i==unos.length()) {
                                                komanda=Komande::PomjeriJednoMjesto;
                                                smjer=Smjerovi::GoreLijevo;
                                                return true;
                                            }
                                        }
                                    } else {
                                        greska=KodoviGresaka::SuvisanParametar;
                                        return false;
                                    }
                                } else if (unos.at(i)=='D') {
                                    if (i==unos.length()-1) {
                                        komanda=Komande::PomjeriJednoMjesto;
                                        smjer=Smjerovi::GoreDesno;
                                        return true;
                                    }
                                    i++;
                                    if (unos.at(i)==' ') {
                                        while (unos.at(i)==' ') {
                                            i++;
                                            if (i==unos.length()) {
                                                komanda=Komande::PomjeriJednoMjesto;
                                                smjer=Smjerovi::GoreDesno;
                                                return true;
                                            }
                                        }
                                    } else {
                                        greska=KodoviGresaka::SuvisanParametar;
                                        return false;
                                    }
                                }
                            } else if (unos.at(i)=='D') {
                                if (i==unos.length()-1) {
                                    komanda=Komande::PomjeriJednoMjesto;
                                    smjer=Smjerovi::Desno;
                                    return true;
                                }
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                        if (i==unos.length()) {
                                            komanda=Komande::PomjeriJednoMjesto;
                                            smjer=Smjerovi::Desno;
                                            return true;
                                        }
                                    }
                                }
                                if (unos.at(i)=='o') {
                                    if (i==unos.length()-1) {
                                        komanda=Komande::PomjeriJednoMjesto;
                                        smjer=Smjerovi::Dolje;
                                        return true;
                                    }
                                    i++;
                                    if (unos.at(i)==' ') {
                                        while (unos.at(i)==' ') {
                                            i++;
                                            if (i==unos.length()) {
                                                komanda=Komande::PomjeriJednoMjesto;
                                                smjer=Smjerovi::Dolje;
                                                return true;
                                            }
                                        }
                                    }
                                    if (unos.at(i)=='D') {
                                        if (i==unos.length()-1) {
                                            komanda=Komande::PomjeriJednoMjesto;
                                            smjer=Smjerovi::DoljeDesno;
                                            return true;
                                        }
                                        i++;
                                        if (unos.at(i)==' ') {
                                            while (unos.at(i)==' ') {
                                                i++;
                                                if (i==unos.length()) {
                                                    komanda=Komande::PomjeriJednoMjesto;
                                                    smjer=Smjerovi::DoljeDesno;
                                                    return true;
                                                }
                                            }
                                        } else {
                                            greska=KodoviGresaka::SuvisanParametar;
                                            return false;
                                        }
                                    } else if (unos.at(i)=='L') {
                                        if (i==unos.length()-1) {
                                            komanda=Komande::PomjeriJednoMjesto;
                                            smjer=Smjerovi::DoljeLijevo;
                                            return true;
                                        }
                                        i++;
                                        if (unos.at(i)==' ') {
                                            while (unos.at(i)==' ') {
                                                i++;
                                                if (i==unos.length()) {
                                                    komanda=Komande::PomjeriJednoMjesto;
                                                    smjer=Smjerovi::DoljeLijevo;
                                                    return true;
                                                }
                                            }
                                        } else {
                                            greska=KodoviGresaka::SuvisanParametar;
                                            return false;
                                        }
                                    }
                                }
                            } else if (unos.at(i)=='L') {
                                if (i==unos.length()-1) {
                                    komanda=Komande::PomjeriJednoMjesto;
                                    smjer=Smjerovi::Lijevo;
                                    return true;
                                }
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                        if (i==unos.length()) {
                                            komanda=Komande::PomjeriJednoMjesto;
                                            smjer=Smjerovi::Lijevo;
                                            return true;
                                        }
                                    }
                                } else {
                                    greska=KodoviGresaka::SuvisanParametar;
                                    return false;
                                }
                            } else {
                                greska=KodoviGresaka::NedostajeParmetar;
                                return false;
                            }
                        }
                    } else {
                        greska=KodoviGresaka::NedostajeParmetar;
                        return false;
                    }
                }
            } else {
                greska=KodoviGresaka::PogresnaKomanda;
                return false;
            }
        } else {
            greska=KodoviGresaka::PogresnaKomanda;
            return false;
        }
    }
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer, int p_x = 0, int p_y = 0)
{
    if (komanda==Komande::PomjeriJednoMjesto) {
        Status s=Idi(polja,x,y,p_smjer);
        std::cout<<"Tekuca pozicija igrača je ("<<x<<","<<y<<")";
        if (s==Status::KrajPobjeda) {
            std::cout<<"Bravo, obisli ste sva sigurna polja";
            for (int i=0; i<polja.size(); i++) {
                for (int j=0; j<polja.at(i).size(); j++) {
                    polja.at(i).at(j)=Polje::Prazno;
                }
            }
            throw std::runtime_error ("Igra zavrsena");
        } else if (s==Status::KrajPobjeda) {
            std::cout<<"Nagazli ste na minu";
            for (int i=0; i<polja.size(); i++) {
                for (int j=0; j<polja.at(i).size(); j++) {
                    polja.at(i).at(j)=Polje::Prazno;
                }
            }
            throw std::runtime_error ("Igra zavrsena");
        }
    }
    if (komanda==Komande::PomjeriDalje) {
        Status s=Idi(polja,x,y,p_x,p_y);
        std::cout<<"Tekuca pozicija igrača je ("<<x<<","<<y<<")";
        if (s==Status::KrajPobjeda) {
            std::cout<<"Bravo, obisli ste sva sigurna polja";
            for (int i=0; i<polja.size(); i++) {
                for (int j=0; j<polja.at(i).size(); j++) {
                    polja.at(i).at(j)=Polje::Prazno;
                }
            }
            throw std::runtime_error ("Igra zavrsena");
        } else if (s==Status::KrajPobjeda) {
            std::cout<<"Nagazli ste na minu";
            for (int i=0; i<polja.size(); i++) {
                for (int j=0; j<polja.at(i).size(); j++) {
                    polja.at(i).at(j)=Polje::Prazno;
                }
            }
            throw std::runtime_error ("Igra zavrsena");
        }
    }
    if (komanda==Komande::ZavrsiIgru) {
        for (int i=0; i<polja.size(); i++) {
            for (int j=0; j<polja.at(i).size(); j++) {
                polja.at(i).at(j)=Polje::Prazno;
            }
        }
        throw std::runtime_error ("Igra zavrsena");
    }
    if (komanda==Komande::PrikaziOkolinu) {
        std::vector<std::vector<int>> vek=PrikaziOkolinu(polja,x,y);
        for (int i=0; i<vek.size(); i++) {
            for (int j=0; j<vek.at(i).size(); j++) {
                std::cout<<vek.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
    if (komanda==Komande::Blokiraj) {
        BlokirajPolje(polja,x,y);
    }
    if (komanda==Komande::Deblokiraj) {
        DeblokirajPolje(polja,x,y);
    }
    if (komanda==Komande::KreirajIgru) {
        Tabla nova(0);
        int n,k,br1,br2;
        std::string unos;
        for (;;) {
            std::cout<<"Unesite broj polja: ";
            std::cin>>n;
            if (n<=0 || !std::cin) {
                std::cout<<"Greska, unesite ponovo!"<<std::endl;
                std::cin.ignore(1000,'\n');
                std::cin.clear();
            } else break;
        }
        std::vector<std::vector<int>> vektor_mina(100);
        std::cout<<"Unesite pozicije mina: ";
        for (;;) {
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            bool tacka(false);
            bool pom(false);
            std::getline(std::cin,unos);
            for (int i=0; i<unos.length(); i++) {
                if (unos.at(i)==' ') continue;
                if (unos.at(i)=='(') {
                    i++;
                    if (unos.at(i)==' ') {
                        while (unos.at(i)==' ') {
                            i++;
                        }
                    }
                    if (isdigit(unos.at(i))) {
                        br1=unos.at(i)-'0';
                        i++;
                        if (unos.at(i)==' ') {
                            while (unos.at(i)==' ') {
                                i++;
                            }
                        }
                        if (unos.at(i)==',') {
                            i++;
                            if (unos.at(i)==' ') {
                                while (unos.at(i)==' ') {
                                    i++;
                                }
                            }
                            if (isdigit(unos.at(i))) {
                                br2=unos.at(i)-'0';
                                i++;
                                if (unos.at(i)==' ') {
                                    while (unos.at(i)==' ') {
                                        i++;
                                    }
                                }
                                if (unos.at(i)==')') {
                                    if (i==unos.length()-1) {
                                        vektor_mina.at(k).push_back(br1);
                                        vektor_mina.at(k).push_back(br2);
                                        pom=true;
                                        break;
                                    }
                                    i++;
                                    if (unos.at(i)==' ') {
                                        while (unos.at(i)==' ') {
                                            i++;
                                            if (i==unos.length()) {
                                                vektor_mina.at(k).push_back(br1);
                                                vektor_mina.at(k).push_back(br2);
                                                pom=true;
                                                break;
                                            }
                                        }
                                    }  else {
                                        std::cout<<"Greska, unesite ponovo!"<<std::endl;
                                        break;
                                    }
                                } else {
                                    std::cout<<"Greska, unesite ponovo!"<<std::endl;
                                    break;
                                }
                            } else {
                                std::cout<<"Greska, unesite ponovo!"<<std::endl;
                                break;
                            }
                        } else {
                            std::cout<<"Greska, unesite ponovo!"<<std::endl;
                            break;
                        }
                    } else {
                        std::cout<<"Greska, unesite ponovo!"<<std::endl;
                        break;
                    }
                } else if (unos.at(i)=='.') {
                    tacka=true;
                    break;
                } else {
                    std::cout<<"Greska, unesite ponovo!"<<std::endl;
                    break;
                }
            }
            if (tacka) break;
            if (pom) k++;
            else continue;
        }
        vektor_mina.resize(k);
        nova=KreirajIgru(k,vektor_mina);
    }
}

int main ()
{
    try {
        Smjerovi s;
        KodoviGresaka g;
        int x,y,p_x,p_y;
        Komande kom;
        Tabla p;
        for (;;) {
            std::cout<<"Unesite komandu: ";
            UnosKomande(kom,s,p_x,p_y,g);
            if (UnosKomande) IzvrsiKomandu(kom,p,x,y,s,p_x,p_y);
            else PrijaviGresku(g);
        }
    } catch (std::runtime_error izuzetak) {
        std::cout<<"Doviđenja!"<<std::endl;
    }
    return 0;
}