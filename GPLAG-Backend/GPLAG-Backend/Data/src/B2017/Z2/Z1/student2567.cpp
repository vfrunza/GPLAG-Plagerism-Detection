#include <iostream>
#include <vector>

using namespace std;

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

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


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
    Tabla T;    // inicijalizira tabelu
    if(n <= 0) throw std::domain_error ("Ilegalna veličina");
    T.resize(n);
    for(int i = 0; i < n; i++)
        T[i].resize(n);    //postavljamo veličinu

    for(int i = 0; i < n; i++)    //postavimo sva polja da su prazna, moze se desiti da baci izzuzetak ispod pa da ostane ne inicijalizirano
        for(int j = 0;  j < n; j++)
            T[i][j] = Polje::Prazno;

    for(int i = 0; i < mine.size(); i++)
    {
        if(mine[i].size() != 2)   throw std::domain_error ("Ilegalan format zadavanja mina");
        if((mine[i][0] > (n-1) && mine[i][0] < 0) || (mine[i][1] > (n-1) && mine[i][1] < 0)) throw std::domain_error ("Ilegalne pozicije mina");
        T[mine[i][0]][mine[i][1]] = Polje::Mina;
    }

    return T;
}

bool JelUnutra (int n, int i , int j)
{
    if(i < 0 || i > (n-1) || j < 0 || j > (n-1)) return false;
    return true;
}

int Prebroj (const Tabla &polja, int i, int j)
{
    int n = polja.size();
    int broj = 0;
    if(JelUnutra(n,i-1,j) && polja[i-1][j]==Polje::Mina) broj++;
    if(JelUnutra(n,i-1,j-1) && polja[i-1][j-1]==Polje::Mina) broj++;
    if(JelUnutra(n,i-1,j+1) && polja[i-1][j+1]==Polje::Mina) broj++;
    if(JelUnutra(n,i+1,j) && polja[i+1][j]==Polje::Mina) broj++;
    if(JelUnutra(n,i+1,j-1) && polja[i+1][j-1]==Polje::Mina) broj++;
    if(JelUnutra(n,i+1,j+1) && polja[i+1][j+1]==Polje::Mina) broj++;
    if(JelUnutra(n,i,j-1) && polja[i][j-1]==Polje::Mina) broj++;
    if(JelUnutra(n,i,j+1) && polja[i][j+1]==Polje::Mina) broj++;

    return broj;

}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    int n = polja.size();
    if(x < 0 || x > (n-1) || y < 0 || y > (n-1)  )throw std::domain_error ("Polje (x,y) ne postoji");

    std::vector<std::vector<int>> m;
    m.resize(3);
    for(int i = 0; i < 3; i++)
        m[i].resize(3);

    m[0][0] = Prebroj(polja,x-1,y-1);
    m[0][1] = Prebroj(polja,x-1,y);
    m[0][2] = Prebroj(polja,x-1,y+1);
    m[1][0] = Prebroj(polja,x,y-1);
    m[1][1] = Prebroj(polja,x,y);
    m[1][2] = Prebroj(polja,x,y+1);
    m[2][0] = Prebroj(polja,x+1,y-1);
    m[2][1] = Prebroj(polja,x+1,y);
    m[2][2] = Prebroj(polja,x+1,y+1);

    return m;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
    int n = polja.size();
    if(x < 0 || x > (n-1) || y < 0 || y > (n-1)  )throw std::domain_error ("Polje (x,y) ne postoji");

    if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
    if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
    if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
    int n = polja.size();
    if(x < 0 || x > (n-1) || y < 0 || y > (n-1)  )throw std::domain_error ("Polje (x,y) ne postoji");

    if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
    if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
    if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    int n = polja.size();
    if(novi_x < 0 || novi_x > n-1 || novi_y < 0 || novi_y > n-1) throw std::out_of_range ("Izlazak van igrace table");
    if(polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno) throw std::logic_error ("Blokirano polje");
    x = novi_x;
    y = novi_y;

    if(polja[x][y] == Polje::Mina) return Status::KrajPoraz;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(polja[i][j] == Polje::Prazno)
            {
                return Status::NijeKraj;
            }
        }
    }
    return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    int novi_x, novi_y;

    if(smjer == Smjerovi::Desno) {novi_x = x; novi_y = y+1; }
    if(smjer == Smjerovi::Dolje) {novi_x = x+1; novi_y = y; }
    if(smjer == Smjerovi::DoljeDesno) {novi_x = x+1; novi_y = y+1; }
    if(smjer == Smjerovi::DoljeLijevo) {novi_x = x+1; novi_y = y-1; }
    if(smjer == Smjerovi::Gore) {novi_x = x-1; novi_y = y; }
    if(smjer == Smjerovi::GoreDesno) {novi_x = x-1; novi_y = y+1; }
    if(smjer == Smjerovi::GoreLijevo) {novi_x = x-1; novi_y = y-1; }
    if(smjer == Smjerovi::Lijevo) {novi_x = x; novi_y = y-1; }
    
    return Idi(polja, x, y, novi_x, novi_y);
}


void PrijaviGresku(KodoviGresaka kod_greske)
{
    if(kod_greske == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
    else if(kod_greske == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
    else if(kod_greske == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
    else if(kod_greske == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!\n";
}

bool jeLiBroj(string mozdaBroj) {
    for (int i = 0; i < mozdaBroj.length(); i++) {
        if (mozdaBroj[i] < '0' || mozdaBroj[i] > '9') {
            return false;
        }
    }
    return true;
}

int parsiraj(string naredba, int start, string& dioNaredbe) {
    int i = start;
    for (; i < naredba.length(); i++) {
        if (dioNaredbe.length() == 0 && naredba[i] == ' ') {
            continue;
        } else if (naredba[i] == ' ') {
            break;
        }
        dioNaredbe += naredba[i];
    }
    return i;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
    string korisnickiUnosSaTastature;
    cout << "Unesite komandu: " << endl;
    getline(std::cin, korisnickiUnosSaTastature);
    string sifraKomande = "";
    string argument1 = "";
    string argument2 = "";
    string argument3 = "";
    int pozicija = parsiraj(korisnickiUnosSaTastature, 0, sifraKomande);
    pozicija = parsiraj(korisnickiUnosSaTastature, pozicija, argument1);
    pozicija = parsiraj(korisnickiUnosSaTastature, pozicija, argument2);
    pozicija = parsiraj(korisnickiUnosSaTastature, pozicija, argument3);
    
    if (argument3.length() > 0) {
        greska = KodoviGresaka::SuvisanParametar;
        return false;
    }
    
    if (sifraKomande == "P1") {
        if (argument2.length() > 0) {
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        komanda = Komande::PomjeriJednoMjesto;
        if (argument1 == "GL") { smjer = Smjerovi::GoreLijevo; }
        else if (argument1 == "G") { smjer = Smjerovi::Gore; }
        else if (argument1 == "GD") { smjer = Smjerovi::GoreDesno; }
        else if (argument1 == "D") { smjer = Smjerovi::Desno; }
        else if (argument1 == "DoD") { smjer = Smjerovi::DoljeDesno; }
        else if (argument1 == "Do") { smjer = Smjerovi::Dolje; }
        else if (argument1 == "DoL") { smjer = Smjerovi::DoljeLijevo; }
        else if (argument1 == "L") { smjer = Smjerovi::Lijevo; }
        else {
            if (argument1.length() == 0) { greska = KodoviGresaka::NedostajeParametar;}
            else { greska = KodoviGresaka::NeispravanParametar; }
            return false;
        }
        return true;
    }
    if (sifraKomande == "P>" || sifraKomande == "B" || sifraKomande == "D") {
        if (sifraKomande == "P>") { komanda = Komande::PomjeriDalje; }
        if (sifraKomande == "B") { komanda = Komande::Blokiraj; }
        if (sifraKomande == "D") { komanda = Komande::Deblokiraj; }
        if (argument1.length() == 0 || argument2.length() == 0) {
            greska = KodoviGresaka::NedostajeParametar;
            return false;
        }
        if (!jeLiBroj(argument1) || !jeLiBroj(argument2)) {
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        x = stoi(argument1);
        y = stoi(argument2);
        return true;
    }
    if (sifraKomande == "PO" || sifraKomande == "Z" || sifraKomande == "K") {
        if (sifraKomande == "PO") { komanda = Komande::PrikaziOkolinu; }
        if (sifraKomande == "Z") { komanda = Komande::ZavrsiIgru; }
        if (sifraKomande == "K") { komanda = Komande::KreirajIgru; }
        
        if (argument1.length() > 0) {
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        return true;
    }
    greska = KodoviGresaka::PogresnaKomanda;
    return false;
    
}

int main()
{




     while(true) {
        Komande komanda;
        Smjerovi smjer;
        int x;
        int y;
        KodoviGresaka greska;
        bool sveURedu = UnosKomande(komanda, smjer, x, y, greska);
        if (!sveURedu) {
            switch(greska) {
                case KodoviGresaka::PogresnaKomanda:
                cout << "PogresnaKomanda" << endl;
                break;
            case KodoviGresaka::NedostajeParametar:
                cout << "NedostajeParametar" << endl;
                break;
            case KodoviGresaka::SuvisanParametar:
                cout << "SuvisanParametar" << endl;
                break;
            case KodoviGresaka::NeispravanParametar:
                cout << "NeispravanParametar" << endl;
                break;
            }
        }
        switch(komanda) {
            case Komande::PomjeriJednoMjesto:
                cout << "PomjeriJednoMjesto" << endl;
                switch(smjer) {
                    case Smjerovi::GoreLijevo:
                    cout << "GoreLijevo" << endl;
                    break;
                case Smjerovi::Gore:
                    cout << "Gore" << endl;
                    break;
                case Smjerovi::GoreDesno:
                    cout << "GoreDesno" << endl;
                    break;
                case Smjerovi::Desno:
                    cout << "Desno" << endl;
                    break;
                case Smjerovi::DoljeDesno:
                    cout << "DoljeDesno" << endl;
                    break;
                case Smjerovi::Dolje:
                    cout << "Dolje" << endl;
                    break;
                case Smjerovi::DoljeLijevo:
                    cout << "DoljeLijevo" << endl;
                    break;
                case Smjerovi::Lijevo:
                    cout << "Lijevo" << endl;
                    break;
                }
                break;
            case Komande::PomjeriDalje:
                cout << "PomjeriDalje" << endl;
                break;
            case Komande::Blokiraj:
                cout << "Blokiraj" << endl;
                break;
            case Komande::Deblokiraj:
                cout << "Deblokiraj" << endl;
                break;
            case Komande::PrikaziOkolinu:
                cout << "PrikaziOkolinu" << endl;
                break;
            case Komande::ZavrsiIgru:
                cout << "ZavrsiIgru" << endl;
                break;
            case Komande::KreirajIgru:
                cout << "KreirajIgru" << endl;
                break;
        }
        cout << x << endl << y << endl;
    }  
    
    return 0;
}
