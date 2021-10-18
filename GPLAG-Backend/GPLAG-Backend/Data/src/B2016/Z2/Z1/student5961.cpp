#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>

enum class Polje {
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;
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
    ZavrsiIgru, KreirajIgru
};
std::string PretvoriBroj(int broj){
    int brojac(1);
    int broj2(broj);
    while(broj2 > 9){
        broj2/= 10;   brojac*=10;
    }
    std::string s;
    int i(0);
    while(brojac >= 1){
        if(brojac > 0) {
            s += broj/brojac +'0';
            broj -= (broj/brojac)*brojac;
        }
        else s += broj+'0';
        brojac/= 10;
        i++;
    }
    return s;
}
//  Provjerava ispravnost iza kljucne komande i ocitava potrebne varijable
bool ProvjeriSmjer(std::string s, Smjerovi &smjer, KodoviGresaka &greska, int &ima_greska){
    int i(0);
    while(i < s.length() && s[i] == ' ') i++;
    i += 2;
    while(i < s.length() && s[i] == ' ') i++;
    int brojac(0);
    while(i < s.length() && s[i] != ' ') {
        i++; brojac++;
    }
    if (brojac > 3){
        greska = KodoviGresaka::NeispravanParametar; return false;
    }
    else if(!brojac){
        greska = KodoviGresaka::NedostajeParametar; ima_greska =1; return false;
    }
    if(brojac == 3){
        std::string tmp(s.substr(i-brojac, brojac));
        if(tmp == "DoD")
            smjer = Smjerovi::DoljeDesno;
        else if(tmp == "DoL")
            smjer = Smjerovi::DoljeLijevo;
        else{
            greska = KodoviGresaka::NeispravanParametar; ima_greska = 1; return false;
        }
    }
    else if(brojac == 2){
        std::string tmp(s.substr(i-brojac, brojac));
        if(tmp == "GL")
            smjer = Smjerovi::GoreLijevo;
        else if(tmp == "GD")
            smjer = Smjerovi::GoreDesno;
        else if(tmp == "Do")
            smjer = Smjerovi::Dolje;
        else {
            greska = KodoviGresaka::NeispravanParametar; ima_greska = 1; return false;
        }
    }
    else {
        std::string tmp(s.substr(i-brojac, brojac));
        if(tmp == "L")
            smjer = Smjerovi::Lijevo;
        else if(tmp == "D")
            smjer = Smjerovi::Desno;
        else if(tmp == "G")
            smjer = Smjerovi::Gore;
        else{
            greska = KodoviGresaka::NeispravanParametar; ima_greska = 1; return false;
        }
    }
    while(i < s.length() && s[i] == ' ')i++;
    if(i < s.length() && s[i] != ' '){
        greska = KodoviGresaka::SuvisanParametar; ima_greska = 1; return false;
    }

    return true;
}
// Provjerava string nakon ocitavnja komande!
bool ProvjeriString(std::string s, KodoviGresaka &greska, int &ima_greska){
    int i(0);
    while(i < s.length() && s[i] == ' ') i++;
    if(s.length() > i && s[i] == 'P') {
        i++;
        if(i < s.length() && s[i] == 'O') i++;
        else {
            greska = KodoviGresaka::NeispravanParametar; ima_greska = 1;
            return false;
        }
    }
    else if(i < s.length() && s[i] == 'Z') i++;
    else if(i < s.length() && s[i] == 'K') i++;
    while(i < s.length() && s[i] != ' ') i++;
    while(i < s.length() && s[i] == ' ') i++;
    if(i < s.length()){
        greska = KodoviGresaka::SuvisanParametar; ima_greska = 1;
        return false;
    }
    return true;
}
//Provjerava za tip komande sa koordinatama
bool ProvjeriKoordinate(std::string s, int &x, int &y, KodoviGresaka  &greska, int &ima_greska){
    int i(0);
    while(i < s.length() && s[i] == ' ') i++;
    if(i < s.length() && s[i] == 'P') {
        i++;
        if(i < s.length() && s[i] == '>') i++;
    }
    else if(i < s.length() && s[i] == 'B') i++;
    else if(i < s.length() && s[i] == 'D') i++;
    int ima(0);
    x =0; y =0;
    while(i < s.length() && s[i] == ' ') i++;
    while(i < s.length() && s[i] != ' '){
        if(s[i] < '0' || s[i] > '9') {
            greska = KodoviGresaka::NeispravanParametar; ima_greska = 1;
            return false;
        }
        ima = 1;
        x = x*10 + (s[i] - '0');
        i++;
    }
    while(i < s.length() && s[i] == ' ') i++;
    while(i < s.length() && s[i] != ' '){
        if(s[i] < '0' || s[i] > '9'){
            greska = KodoviGresaka::NeispravanParametar; ima_greska = 1;
            return false;
        }
        ima = 2;
        y = y*10 +(s[i] - '0');
        i++;
    }
    while(i < s.length()) {
        if (s[i] != ' ') {
            greska = KodoviGresaka::SuvisanParametar; ima_greska = 1;
            return false;
        }
        i++;
    }
    if(ima < 2 && i > 0){
        greska = KodoviGresaka::NeispravanParametar; ima_greska = 1;
        return false;
    }
    if(ima == 0){
        greska = KodoviGresaka::NedostajeParametar; ima_greska = 1;
        return false;
    }
    return true;
}
// Ciscenje svih polja na Prazno
void OcistiPolja(Tabla &polja){
    for(int i(0); i < polja.size(); i++)
        for(int j(0); j < polja[i].size(); j++)
            polja[i][j] = Polje::Prazno;
}
//   Provjeravanje zavrsetka igre
bool Gotovo(Tabla polja, int x, int y){
    for(int i(0); i < polja.size(); i++)
        for(int j(0); j < polja[i].size(); j++){
            if((polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) && (i != x || j != y))
                return false;
        }
    return true;
}

bool NijeDobraMatrica(std::vector<std::vector<int>> mat){
    for(int i(0); i < mat.size(); i++){
        if(mat[i].size() != 2) return true;
    }
    return false;
}
// Kreira tabelu s minama
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
    if(NijeDobraMatrica(mine)) throw std::domain_error("Ilegalan format zadavanja mina");
    std::vector<std::vector<Polje>> tabela_mina;
    try{
        tabela_mina.resize(n);
        for(int i(0); i < n; i++) tabela_mina[i].resize(n);
    }
    catch(std::bad_alloc){
        exit(1);
    }
    for(int i(0); i < mine.size(); i++){
        if(mine[i][0] < 0 || mine[i][0] >= n || mine[i][1] < 0 || mine[i][1] >= n)
            throw std::domain_error("Ilegalne pozicije mina");
    }
    //Unos praznina
    for(int i(0); i < n; i++)
        for(int j(0); j < n; j++)
            tabela_mina[i][j] = Polje::Prazno;
    //Unos mina
    for(int i(0); i < n; i++){
        for(int j(0); j < n; j++){
            for(int k(0); k < mine.size(); k++){
                if(i == mine[k][0] && j == mine[k][1]) {
                    tabela_mina[i][j] = Polje::Mina;
                    break;
                }
            }
        }
    }
    return tabela_mina;
}
//  Prikazuje okolinu izabranog polja
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
    if(x > polja.size()-1 || x < 0 || y > polja[0].size()-1 || y < 0 || !polja.size())
        throw std::domain_error("Polje ("+PretvoriBroj(x)+","+PretvoriBroj(y)+ ") ne postoji");
    std::vector<std::vector<int>> izlazna(3, std::vector<int>(3));
    ///////////////////////////////////////////////////////////////////////
    for(int i(0); i < 3; i++){
        for(int j(0); j < 3; j++){
            int brojac(0);
            for(int k(x-2+i); k <= x+i; k++){
                if(k < 0) k = 0;
                if(k >= polja.size()) break;
                for(int h(y-2+j); h <= y+j; h++){
                    if(h < 0) h = 0;
                    if(h >= polja[k].size()) break;
                    if((k != x-1+i || h != y-1+j) && polja[k][h] == Polje::Mina) brojac++;
                }
            }
            izlazna [i][j] = brojac;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    return izlazna;
}
//  Blokira polje oznaceno sa (x,y)///////////////////////////////////////////////
void BlokirajPolje(Tabla &polja, int x, int y) {
    if (x < 0 || y < 0 || x >= polja.size() || y >= polja[0].size())
        throw std::domain_error("Polje (" + PretvoriBroj(x)+","+PretvoriBroj(y)+") ne postoji");

    if(int(polja[x][y]) < 3) polja[x][y] = Polje(int(polja[x][y]) + 3);
}
// Deblokira izabrano polje/////////////////////////////////////////////////////
void DeblokirajPolje(Tabla &polja, int x, int y){
    if (x < 0 || y < 0 || x > polja.size()-1 || y > polja[0].size()-1 || !polja.size())
        throw std::domain_error("Polje (" + PretvoriBroj(x) + "," + PretvoriBroj(y)+ ") ne postoji");
    if(int(polja[x][y]) >= 3) polja[x][y] = Polje(int(polja[x][y]) - 3);
}
// Pomjera na odabrano polje u odabranom smijeru/////////////////////////////////
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
    int a, b;
    switch(int(smjer)){
        case 0:
            a = x-1; b = y-1; break;
        case 1:
            a = x-1; b = y; break;
        case 2:
            a = x-1; b = y+1; break;
        case 3:
            a = x; b = y+1; break;
        case 4:
            a = x+1; b = y+1; break;
        case 5:
            a = x+1; b = y; break;
        case 6:
            a = x+1; b = y-1; break;
        case 7:
            a = x; b = y-1; break;
    }
    if(a < 0 || b < 0 || a >= polja.size() || b >= polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
    else if(polja[a][b] == Polje::Mina) return Status::KrajPoraz;
    else if(int(polja[a][b]) >= 3) throw std::logic_error("Blokirano polje");
    polja[x][y] = Polje::Posjeceno;
    x = a; y = b;
    if(Gotovo(polja, x, y)) return Status::KrajPobjeda;
    return Status::NijeKraj;
}
// Pomijera direktno na odabrano mijesto///////////////////////////////////////
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
    if(novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja[0].size())  //Ako je izvan tabele
        throw std::out_of_range("Izlazak van igrace table");
    //Ne smije biti blokirano polje
    if(int(polja[novi_x][novi_y]) >= 3)
        throw std::logic_error("Blokirano polje");
    if(polja[novi_x][novi_y] == Polje::Mina){    // Ako je izabrana mina => poraz
        OcistiPolja(polja); return Status::KrajPoraz;
    }
    polja[x][y] = Polje::Posjeceno;
    x = novi_x; y = novi_y;
    return Status::NijeKraj;
}
// Ispisuje tip greske na konzolu///////////////////
void PrijaviGresku(KodoviGresaka prijava){
    if(prijava == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!\n";
    if(prijava == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!\n";
    if(prijava == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!\n";
    if(prijava == KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!\n";
}
// Konzola preko koje se unose odabiri vrijednosti itd.../////////////////////
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
    std::string naredba;
    std::getline(std::cin, naredba);
    int i(0), ima_greska(0);
    while(naredba[i] == ' ' && i < naredba.length()) i++;
    if(naredba.length()- i > 1 && naredba.substr(i, 2) == "P1" && ProvjeriSmjer(naredba, smjer, greska, ima_greska)){
        komanda = Komande(0);
        return true;
    }
    else if(naredba.length() - i > 1 && naredba.substr(i, 2) == "P>" && ProvjeriKoordinate(naredba, x, y, greska, ima_greska)){
        komanda = Komande(1);
        return true;
    }
    else if(naredba.length()-i > 0 && naredba.substr(i, 1) == "B" && ProvjeriKoordinate(naredba, x, y, greska, ima_greska)){
        komanda = Komande(2);
        return true;
    }
    else if(naredba.length()-i > 0  && naredba.substr(i, 1) == "D" && ProvjeriKoordinate(naredba, x, y, greska, ima_greska)){
        komanda = Komande(3);
        return true;
    }
    else if(naredba.length()-i > 1 && naredba.substr(i, 2) == "PO" && ProvjeriString(naredba, greska, ima_greska)){
        komanda = Komande(4);
        return true;
    }
    else if(naredba.length()-i > 0 && naredba.substr(i, 1) == "Z" && ProvjeriString(naredba, greska, ima_greska)){
        komanda = Komande(5);
        return true;
    }
    else if(naredba.length()-i > 0 && naredba.substr(i, 1) == "K" && ProvjeriString(naredba, greska, ima_greska)){
        komanda = Komande(6);
        return true;
    }
    else if(ima_greska) return false;
    else {
        greska = KodoviGresaka::PogresnaKomanda;
        return false;
    }
    return true;
}
// Unos mina i njovo testiranje tokom unosa/////////////////////
void UnosMina(std::vector<std::vector<int>> &mine, int dimenzije){
    int k(0);
    while(true){
        std::string unos;
        std::getline(std::cin, unos);
        if(unos.length() == 1 && unos[0] == '.') return;
        int i(0), x(0), y(0), brojac(0);
        while(i < unos.length()){
            while(i < unos.length() && unos[i] == ' ') i++;
            if(unos[i] == '('){i++; brojac++;}
            else {
                std::cout << "Greska, unesite ponovo!\n";
                i++; break;
            }
            if(i < unos.length() && unos[i] >= '0' && unos[i] <= '9') {
                brojac++;
                while (i < unos.length() && unos[i] >= '0' && unos[i] <= '9') {
                    x = x * 10 + (unos[i] - '0');
                    i++;
                }
                if(x >= dimenzije){
                    std::cout << "Greska, unesite ponovo!\n"; break;
                }
            }
            else {
                std::cout << "Greska, unesite ponovo!\n";    break;
            }
            if(i < unos.length() && unos[i] == ',') {
                i++; brojac++;
            }
            else {
                std::cout << "Greska, unesite ponovo!\n";    break;
            }
            if(i < unos.length() && unos[i] >= '0' && unos[i] <= '9') {
                brojac++;
                while (i < unos.length() && unos[i] >= '0' && unos[i] <= '9') {
                    y = y * 10 + (unos[i] - '0');
                    i++;
                }
                if(y >= dimenzije){
                    std::cout << "Greska, unesite ponovo!\n"; break;
                }
            }
            else {
                std::cout << "Greska, unesite ponovo!\n"; break;
            }
            if(i < unos.length() && unos[i] == ')') {
                i++; brojac++;
                while(i < unos.length() && unos[i == ' ']) i++;
                if(i < unos.length()){
                    std::cout << "Greska, unesite ponovo!\n";
                    brojac = 0; break;
                }
                else break;
            }
            i++;
        }
        if(brojac == 5){
            mine.resize(k+1);
            mine[k].push_back(x); mine[k].push_back(y);
            k++;
        }
    }
}
// Dispečer/////////////////////////////////////////////////////////////////////////////////////////
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
    KodoviGresaka greska;
    if(komanda == Komande::KreirajIgru){
        int br_polja;    std::cout << "Unesite broj polja: ";
        std::cin >> br_polja;
        std::cout << "Unesite pozicije mina: ";
        std::vector<std::vector<int>> mine;
        UnosMina(mine, br_polja);
        polja = KreirajIgru(br_polja, mine);
    }
    else if(komanda == Komande::Blokiraj) {
        try{
            BlokirajPolje(polja, p_x, p_y);
        }
        catch(std::domain_error izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
    }
    else if(komanda == Komande::Deblokiraj){
        try{
            DeblokirajPolje(polja, p_x, p_y);
        }
        catch(std::domain_error izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
    }
    else if(komanda == Komande::PomjeriJednoMjesto){
        try{
            auto dokle(Idi(polja, x, y, p_smjer));
            if(int(dokle) == 1 || int(dokle) == 2) return;
            std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
        }
        catch(std::out_of_range izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
    }
    else if(komanda == Komande::PomjeriDalje){
        try{
            auto dokle(Idi(polja, x, y, p_x, p_y));
            if(int (dokle) == 1 || int(dokle) == 2) return;
            std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";
        }
        catch(std::out_of_range izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
    }
    else if(komanda == Komande::PrikaziOkolinu){
        try{
            auto okolina(PrikaziOkolinu(polja, x, y));
            for(int i(0); i < okolina.size(); i++){
                for(int j(0); j < okolina[i].size(); j++){
                    std::cout << okolina[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        catch(std::domain_error izuzetak){
            std::cout << izuzetak.what() << "\n";
        }
    }
    else PrijaviGresku(greska);
}

////////////////////////////////////////////////////////////////////////////
int main () {
    Komande komanda;
    Tabla polja;
    int x(0), y(0), p_x, p_y;
    KodoviGresaka greska;
    Smjerovi p_smjer;
    while(true){
        std::cout << "Unesite komandu: ";
        auto ispravna_komanda(UnosKomande(komanda, p_smjer, p_x, p_y, greska));
        if(ispravna_komanda && komanda != Komande::ZavrsiIgru)
            IzvrsiKomandu(komanda, polja, x, y, p_smjer, p_x, p_y);
        else {
            std::cout << "Dovidjenja!"; break;
        }
    }
    return 0;
}