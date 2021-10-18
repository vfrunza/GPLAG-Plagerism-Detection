#include <iomanip>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum class Polje{ Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi{ GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef vector<vector<Polje>> Tabla;
typedef vector<vector<int>> Matrica;

Tabla KreirajIgru(int n, Matrica &mine) {
    if(n<=0) throw domain_error("Ilegalna velicina");
    Tabla t(n, vector<Polje> (n,Polje::Prazno));
    for(int i=0;i<mine.size();i++) {
        int a(0),b(1);
        if(mine.at(i).size()!=2) throw domain_error("Ilegalan format zadavanja mina");
        if(mine.at(i).at(a)>=n || mine.at(i).at(b)>=n || mine.at(i).at(a)<0 || mine.at(i).at(b)<0) throw domain_error("Ilegalne pozicije mina");
        t.at(mine.at(i).at(a)).at(mine.at(i).at(b))=Polje::Mina;
    }
    return t;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y) {
    if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw domain_error ("Polje (x,y) ne postoji");
    Matrica okolina(3,vector<int> (3,0));
    int a(0),b(0),c(0),d(0),e(0),f(0);
    if(x>0) c=x-1;
    if(y>0) d=y-1;
    for(int i=c;i<=x+1;i++) {
        b=0;
        for(int j=d;j<=y+1;j++) {
            if(i==x && j==y) continue;
            if(i>0) e=i-1;
            if(j>0) f=j-1;
            for(int k=e;k<=i+1;k++) {
                for(int l=f;l<=j;l++) {
                    if(k==i && l==j) continue;
                    if(polja.at(k).at(l)==Polje::Mina) okolina.at(a).at(b)+=1;
                }
            }
            b++;
        }
        a++;
    }
    return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
    if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw domain_error ("Polje (x,y) ne postoji");
    if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
    if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
    if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
    if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw domain_error ("Polje (x,y) ne postoji");
    if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
    if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
    if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
    if(smjer==Smjerovi::GoreLijevo) {
        if(x-1<0 || x-1>=polja.size() || y-1<0 || y-1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        x--,y--;
    }
    else if(smjer==Smjerovi::Gore) {
        if(x-1<0 || x-1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        x--;
    }
    else if(smjer==Smjerovi::GoreDesno) {
        if(x-1<0 || x-1>=polja.size() || y+1<0 || y+1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        x--,y++;
    }
    else if(smjer==Smjerovi::Desno) {
        if(y+1<0 || y+1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y+1)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        y++;
    }
    else if(smjer==Smjerovi::DoljeDesno) {
        if(x+1<0 || x+1>=polja.size() || y-1<0 || y-1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        x++,y--;
    }
    else if(smjer==Smjerovi::Dolje) {
        if(x+1<0 || x+1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        x++;
    }
    else if(smjer==Smjerovi::DoljeLijevo) {
        if(x+1<0 || x+1>=polja.size() || y+1<0 || y+1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        x++,y++;
    }
    else if(smjer==Smjerovi::Lijevo) {
        if(y-1<0 || y-1>=polja.size()) throw out_of_range ("Izlazak van igrace table");
        if(polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
        y--;
    }
    if(polja.at(x).at(y)==Polje::Mina) {
        Tabla nova(polja.size(), vector<Polje> (polja.size(),Polje::Prazno));
        polja=nova;
        return Status::KrajPoraz;
    }
    else {
        polja.at(x).at(y)=Polje::Posjeceno;
        for(int i=0;i<polja.size();i++) {
            for(int j=0;j<polja.size();j++) {
                if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;
            }
        }
        return Status::KrajPobjeda;
    }
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
    if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw out_of_range ("Izlazak van igrace table");
    if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
    x=novi_x;
    y=novi_y;
    if(polja.at(x).at(y)==Polje::Mina) {
        Tabla nova(polja.size(), vector<Polje> (polja.size(), Polje::Prazno));
        polja=nova;
        return Status::KrajPoraz;
    }
    else {
        polja.at(x).at(y)=Polje::Posjeceno;
        for(int i=0;i<polja.size();i++) {
            for(int j=0;j<polja.size();j++) {
                if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;
            }
        }
        return Status::KrajPobjeda;
    }
}

void PrijaviGresku(KodoviGresaka greska) {
    if(greska==KodoviGresaka::PogresnaKomanda) cout << "Nerazumljiva komanda!";
    else if(greska==KodoviGresaka::NedostajeParmetar) cout << "Komanda trazi parametar koji nije naveden!";
    else if(greska==KodoviGresaka::SuvisanParametar) cout << "Parametar komande nije ispravan!";
    else if(greska==KodoviGresaka::NeispravanParametar) cout << "Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
    cout << "Unesite komandu: ";
    string kom;
    getline(cin,kom);
    for(int i=0;i<kom.size();i++) {
        while(kom.at(i)==' ') i++;
        if(kom.at(i)=='P') {
            i++;
            if(kom.at(i)=='1') {
                while(kom.at(i)==' ') {
                    if(i==kom.size()-1) {
                        greska=KodoviGresaka::NedostajeParmetar;
                        return false;
                    }
                    i++;
                }
                if(kom.at(i)=='G' && (i==kom.size()-1 || kom.at(i)==' ')) {
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::Gore;
                    return true;
                }
                if(kom.at(i)=='G' && kom.at(i+1)=='L') {
                    i++;
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::GoreLijevo;
                    return true;
                }
                if(kom.at(i)=='G' && kom.at(i+1)=='D') {
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::GoreDesno;
                    return true;
                }
                if(kom.at(i)=='D' && (i==kom.size()-1 || kom.at(i)==' ')) {
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::Desno;
                    return true;
                }
                if(kom.at(i)=='D' && kom.at(i+1)=='o' &&  (i+1==kom.size()-1 || kom.at(i+2)==' ')) {
                    i++;
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::Dolje;
                    return true;
                }
                if(kom.at(i)=='D' && kom.at(i+1)=='o' && kom.at(i+2)=='L') {
                    i+=2;
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::DoljeLijevo;
                    return true;
                }
                if(kom.at(i)=='D' && kom.at(i+1)=='o' && kom.at(i+2)=='D') {
                    i+=2;
                    while(kom.at(i)==' ') {
                        if(kom.at(i)!=' ') {
                            greska=KodoviGresaka::SuvisanParametar;
                            return false;
                        }
                        i++;
                    }
                    komanda=Komande::PomjeriJednoMjesto;
                    smjer=Smjerovi::DoljeDesno;
                    return true;
                }
                
            }
            else if(kom.at(i)=='>') {
                while(kom.at(i)==' ') {
                    if(i==kom.size()-1) {
                        greska=KodoviGresaka::PogresnaKomanda;
                        return false;
                    }
                    if(kom.at(i)!=' ' && (kom.at(i)<'0' || kom.at(i)>'9')) {
                        greska=KodoviGresaka::PogresnaKomanda;
                        return false;
                    }
                    i++;
                }
                string broj_x, broj_y;
                while(kom.at(i)>='0' && kom.at(i)<='9') {
                    if(kom.at(i)<'0' || kom.at(i)>'9') {
                        greska=KodoviGresaka::NeispravanParametar;
                        return false;
                    }
                    broj_x.push_back(kom.at(i));
                    i++;
                }
                while(kom.at(i)==' ') {
                    if(i==kom.size()-1) {
                        greska=KodoviGresaka::NedostajeParmetar;
                        return false;
                    }
                    i++;
                }
                while(kom.at(i)>='0' && kom.at(i)<='9') {
                    if(kom.at(i)<'0' || kom.at(i)>'9') {
                        greska=KodoviGresaka::NeispravanParametar;
                        return false;
                    }
                    broj_y.push_back(kom.at(i));
                    i++;
                }
                while(i<=kom.size()-1) {
                    if(kom.at(i)!=' ') {
                        greska=KodoviGresaka::SuvisanParametar;
                        return false;
                    }
                    i++;
                }
                komanda=Komande::PomjeriDalje;
                x=stoi(broj_x);
                y=stoi(broj_y);
            }
            else if(kom.at(i)=='O') {
                while(i<=kom.size()-1) {
                    if(kom.at(i)!=' ') {
                        greska=KodoviGresaka::SuvisanParametar;
                        return false;
                    }
                    i++;
                }
                komanda=Komande::PrikaziOkolinu;
                return true;
            }
            else {
                greska=KodoviGresaka::PogresnaKomanda;
                return false;
            }
        }
        else if(kom.at(i)=='B') {
            while(i<=kom.size()-1) {
                if(kom.at(i)!=' ') {
                    greska=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                i++;
            }
            komanda=Komande::Blokiraj;
            return true;
        }
        else if(kom.at(i)=='D') {
            while(i<=kom.size()-1) {
                if(kom.at(i)!=' ') {
                    greska=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                i++;
            }
            komanda=Komande::Deblokiraj;
            return true;
        }
        else if(kom.at(i)=='Z') {
            while(i<=kom.size()-1) {
                if(kom.at(i)!=' ') {
                    greska=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                i++;
            }
            komanda=Komande::ZavrsiIgru;
            return true;
        }
        else if(kom.at(i)=='K') {
            while(i<=kom.size()-1) {
                if(kom.at(i)!=' ') {
                    greska=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                i++;
            }
            komanda=Komande::KreirajIgru;
            return true;
        }
        else {
            greska=KodoviGresaka::PogresnaKomanda;
            return false;
        }
    }
    return true;
} 

/*void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x= 0,int p_y=0) {
    if(komanda==Komande::PomjeriJednoMjesto) {
        Status s(Idi(polja,x,y,p_smjer));
    }
    else if(komanda==Komande::PomjeriDalje) {
        Status s(Idi(polja,x,y,p_x,p_y);
    }
    else if(komanda==Komande::Blokiraj) {
        BlokirajPolje(polja,p_x,p_y);
    }
    else if(komanda==Komande::Deblokiraj) {
        DeblokirajPolje(polja,p_x,p_y);
    }
    else if(komanda==Komande::PrikaziOkolinu) {
        PrikaziOkolinu(polja,p_x,p_y);
    }
    else if(komanda==Komande::ZavrsiIgru) {
        
    }
    else if(komanda== Komande::KreirajIgru) {
        
    }
}*/

int main() {
}