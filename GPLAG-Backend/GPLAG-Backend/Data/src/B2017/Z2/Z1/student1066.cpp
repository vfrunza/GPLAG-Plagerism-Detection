#include <iostream>  // NAPOMENA: ČESTO MI SE DEŠAVALO DA SAM MORAO VEĆE DIJELOVE KODA KOPIRATI TAKO DA NE MISLITE DA SAM PREPISAO
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
#include <iomanip>
#include <cmath>

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
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

typedef std::vector<std::vector<int>> IntMatrica;

void PrijaviGresku (KodoviGresaka greska)
{
    if (greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
    else if (greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!";
    else if (greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
    else if (greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";
}

Tabla KreirajIgru (int n, const IntMatrica &mine)
{
    if (n<=0) throw std::domain_error ("Ilegalna veličina");
    Tabla tabla(n);
    for (int i = 0; i<n; i++) // Inicijalizacija polja table na Prazno
        for (int j = 0; j<n; j++)
            tabla.at(i).push_back(Polje::Prazno);    // Ubaciavnje Praznih polja

    for (int i = 0; i<mine.size(); i++) {
        if (mine.at(i).size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");  // Ako je format različit od 2 baca se izuzetak
        for (int j = 0; j<2; j++) {
            if (mine.at(i).at(0)>=n || mine.at(i).at(1)>=n || mine.at(i).at(0)<0 || mine.at(i).at(1)<0) throw std::domain_error ("Ilegalan format zadavanja mina");
            tabla.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;   // Ubacivanje mina
        }
    }
    return tabla;
}

IntMatrica PrikaziOkolinu (const Tabla &polja, int x, int y)
{
    if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");
    int suma(0);
    IntMatrica mat(3,std::vector<int>(3));
    for (int r=x-1; r<=x+1; r++) {   // Ako je x,y , inda idem od gornjeg lijevog ugla, tj. x-1, y-1, sabirati sve matrice okolo tih vrijesnoti
        for (int q=y-1; q<=y+1; q++) {
            int a=r;
            int b=q;
            for (int i=a-1; i<=a+1; i++) {
                for (int j=b-1; j<=b+1; j++) {
                    if (i==a && j==b) continue;
                    if ((i>=0 && i<polja.size()) && (j>=0 && j<polja.size()) && polja.at(i).at(j)==Polje::Mina)  // Ako je unutar polja i ako je mina suma mina oko tog polja ++
                        suma++;
                }
            }
            mat.at(r-x+1).at(q-y+1)=suma;  // Ubacivanje u matricu sumu mina oko tog polja
            suma=0;
        }
    }
    return mat;
}

void BlokirajPolje (Tabla &polja, int x, int y)
{
    if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");
    if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
    else if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
    else if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje (Tabla &polja, int x, int y)
{
    if (x<0 || x>=polja.size() || y<0 || y>=polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");
    if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
    else if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
    else if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    if (novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range ("Izlazak van igrace table");
    if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano Polje");
    if (polja.at(novi_y).at(novi_y)==Polje::Mina) {
        for (int i = 0; i<polja.size(); i++)
            for (int j = 0; j<polja.size(); j++)
                polja.at(i).at(j)=Polje::Prazno;
        return Status::KrajPoraz;
    }
    bool prazno(true);
    for (int i = 0; i<polja.size(); i++) {
        for (int j = 0; j<polja.size(); j++) {
            if (polja.at(i).at(j)==Polje::Prazno) prazno=false;
        }
    }
    if (prazno) return Status::KrajPobjeda;
    x=novi_x;
    y=novi_y;
    return Status::NijeKraj;

}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    polja.at(x).at(y)=Polje::Posjeceno;
    int x_prim(x),y_prim(y);
    if (smjer==Smjerovi::GoreLijevo) {
        x=x-1;
        y=y-1;
    } else if (smjer==Smjerovi::Gore) {
        x=x-1;
    } else if (smjer==Smjerovi::GoreDesno) {
        x=x-1;
        y=y+1;
    } else if (smjer==Smjerovi::Desno) {
        y=y+1;
    } else if (smjer==Smjerovi::DoljeDesno) {
        x=x+1;
        y=y+1;
    } else if (smjer==Smjerovi::Dolje) {
        x=x+1;
    } else if (smjer==Smjerovi::DoljeLijevo) {
        x=x+1;
        y=y-1;
    } else if (smjer==Smjerovi::Lijevo) {
        y=y-1;
    }
    return Idi(polja,x_prim,y_prim,x,y);
}

bool UlazDimenzije (double n)     // Provjerava sve mogucnosti ulaza
{
    if (fabs(n-int(n))>0.00001) return false;
    else if (!std::cin || std::cin.peek()!='\n') return false;
    else if (n<0) return false;
    return true;
}

bool UlazMine (double M, int n)     // Provjerava sve mogucnosti ulaza kao i da li je ulaz bio tacka
{
    if (fabs(M-int(M))>0.00001) return false;
    else if (!std::cin || std::cin.peek()!='\n') return false;
    else if (M<0 || M>=n) return false;
    return true;
}

IntMatrica UnesiMine (const int n) // Popraviti unos
{
    std::vector<std::complex<int>> M;
    std::complex<int> Mina;
    bool zapamti(false);
    while (1) {
        std::cin>>Mina;
        if (zapamti && std::cin.peek()=='\n') break;
        if (!(UlazMine(real(Mina),n) && UlazMine(imag(Mina),n))) {
            std::cout<<"Greska, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            zapamti=false;
            continue;
        }
        if((real(Mina)==0 && imag(Mina)==0)) {
            zapamti=false;
            std::cout<<"Greska, unesite ponovo!"<<std::endl;
            continue;
        }
        zapamti=true;
        M.push_back(Mina);
    }
    IntMatrica vrati(M.size(),std::vector<int>(2));
    for (int i = 0; i<M.size(); i++) {
        vrati.at(i).at(0)=real(M.at(i));
        vrati.at(i).at(1)=imag(M.at(i));
    }
    return vrati;

}

int UnesiBrojPolja (double &n)
{
    while (1) {
        std::cin>>n;
        if (!UlazDimenzije(n)) {
            std::cout<<"Greska, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        } else return n;
    }
}

std::string PrvaRijec (std::string s)
{
    std::string vrati;
    while (s.at(0)==' ')
        s.erase(s.begin());
    int i=0;
    while (i<s.size() && s.at(i)!=' ') {
        vrati.push_back(s.at(i));
        i++;
    }
    return vrati;
}

std::string PrveDvijeRijeci (std::string s)
{
    std::string vrati;
    while (s.at(0)==' ')
        s.erase(s.begin());
    int i =0;
    while (i<s.size() && s.at(i)!=' ') {
        vrati.push_back(s.at(i));
        i++;
    }
    while (i<s.size() && s.at(i)==' ')
        s.erase(s.begin()+i);

    vrati.push_back(' ');
    while (i<s.size() && s.at(i)!=' ') {
        vrati.push_back(s.at(i));
        i++;
    }
    return vrati;
}

std::vector<int> DvaBroja (std::string s)
{
    std::vector<int> vrati(2);
    int i(0);
    while (s.at(0)==' ')
        s.erase(s.begin());
    while (i<s.size() && s.at(i)!=' ')
        i++;
    while (s.size()>i && s.at(i)==' ')
        i++;

    std::vector <int> cifre;
    while (s.size()>i && s.at(i)>='0' && s.at(i)<='9') {
        cifre.push_back(s.at(i)-'0');
        i++;
    }
    int suma(0);
    for (int j = 0; j<cifre.size(); j++)
        suma+=cifre.at(j)*pow(10,cifre.size()-j-1);
    vrati.at(0)=suma;
    while (s.size()>i && s.at(i)==' ')
        i++;

    cifre.resize(0);
    if (!(s.size()>i && s.at(i)>='0' && s.at(i)<='9')) return {-1,-1};
    while (s.size()>i && s.at(i)>='0' && s.at(i)<='9') {
        cifre.push_back(s.at(i)-'0');
        i++;
    }
    suma=0;
    for (int j = 0; j<cifre.size(); j++)
        suma+=cifre.at(j)*pow(10,cifre.size()-j-1);
    vrati.at(1)=suma;

    while (s.size()>i && s.at(i)==' ')
        i++;
    if (i==s.size()) return vrati;
    return {-1,-1};
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int&y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
    if (komanda==Komande::PomjeriJednoMjesto) {
        Status trenutni_status(Idi(polja,x,y,p_smjer));
        if (trenutni_status==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva polja";
        else if (trenutni_status==Status::KrajPoraz) std::cout<<"Nagazili ste na minu";
        else
            std::cout<<"Tekuca pozicija igraca je: ("<<x<<","<<y<<")";
    } else if (komanda==Komande::PomjeriDalje) {
        std::cin>>p_x>>p_y;
        Idi(polja,x,y,p_x,p_y);
    } else if (komanda==Komande::Blokiraj) {
        BlokirajPolje(polja,x,y);
    } else if (komanda==Komande::Deblokiraj) {
        DeblokirajPolje(polja,x,y);
    } else if (komanda==Komande::PrikaziOkolinu) {
        IntMatrica okolina(PrikaziOkolinu(polja,x,y));
        for (int i = 0; i<okolina.size(); i++) {
            for (int j=0; j<okolina.size(); j++) {
                std::cout<<okolina.at(i).at(j)<<" ";
            }
            std::cout << std::endl;
        }

    }

    else if (komanda==Komande::ZavrsiIgru) throw std::runtime_error ("Igra zavrsena");

    else if (komanda==Komande::KreirajIgru) {
        double b;
        std::cout<<"Unesite broj polja: ";
        int n(UnesiBrojPolja(b));  // Unos dimenzije ploče
        std::cout<<"Unesite pozicije mina: ";
        IntMatrica M(UnesiMine(n));  // Unos mina
        Tabla MineSweeper(KreirajIgru(n,M));  // Kreiranje igre
    }
}

//BIo sam prvo napisao u main sadrzaj ove funkcije pa sam ga cijelog kopirao gore nazada tako da ne mislite da sam prepisao nesto
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
    std::string s;
    std::getline(std::cin,s);

    if (PrveDvijeRijeci(s)=="P1 GL") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::GoreLijevo;
    } else if (PrveDvijeRijeci(s)=="P1 G") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::Gore;
    } else if (PrveDvijeRijeci(s)=="P1 GD") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::GoreDesno;
    } else if (PrveDvijeRijeci(s)=="P1 D") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::Desno;
    } else if (PrveDvijeRijeci(s)=="P1 DoD") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::DoljeDesno;
    } else if (PrveDvijeRijeci(s)=="P1 Do") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::Dolje;
    } else if (PrveDvijeRijeci(s)=="P1 DoL") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::DoljeLijevo;
    } else if (PrveDvijeRijeci(s)=="P1 L") {
        komanda=Komande::PomjeriJednoMjesto;
        smjer=Smjerovi::Lijevo;
    }

    else if (PrvaRijec(s)=="P>") {
        auto parametri(DvaBroja(s));
        if (parametri.at(0)==-1) {
            greska=KodoviGresaka::NedostajeParametar;
            return false;
        } else {
            x=parametri.at(0);
            y=parametri.at(1);
        }
        komanda=Komande::PomjeriDalje;
    }

    else if (PrvaRijec(s)=="B") {
        auto parametri(DvaBroja(s));
        if (parametri.at(0)==-1) {
            greska=KodoviGresaka::NedostajeParametar;
            return false;
        } else {
            x=parametri.at(0);
            y=parametri.at(1);
        }
        komanda=Komande::Blokiraj;
    } else if (PrvaRijec(s)=="D") {
        auto parametri(DvaBroja(s));
        if (parametri.at(0)==-1) {
            greska=KodoviGresaka::NedostajeParametar;
            return false;
        } else {
            x=parametri.at(0);
            y=parametri.at(1);
        }
        komanda=Komande::Deblokiraj;
    }

    else if (PrvaRijec(s)=="PO") {
        komanda=Komande::PrikaziOkolinu;
    }

    else if (PrvaRijec(s)=="Z") {
        komanda=Komande::ZavrsiIgru;
    }

    else if (PrvaRijec(s)=="K") {
        komanda=Komande::KreirajIgru;
    } else {
        greska=KodoviGresaka::PogresnaKomanda;
        return false;
    }
    return true;
}

int main ()
{
    try {
        KodoviGresaka kod_greske;
        Komande komanda;
        komanda=Komande::KreirajIgru;
        Smjerovi smjer;
        Tabla MineSweeper;

        int x(0),y(0);
        for(;;) {
            std::cout<<"Unesite komandu: ";
            if ((UnosKomande(komanda,smjer,x,y,kod_greske)))
                IzvrsiKomandu(komanda,MineSweeper,x,y,smjer);
            else {
                PrijaviGresku(kod_greske);
                break;
            }
        }
        std::cout<<"Dovidjenja";
    } catch (std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch (std::out_of_range izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch (std::runtime_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    return 0;
}