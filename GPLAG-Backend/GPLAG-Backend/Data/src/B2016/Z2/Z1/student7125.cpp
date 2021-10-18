#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

// -------------------ENUM---------------------
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru, KreirajIgru
};
enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoProsjeceno, BlokiranoMina
};
enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
typedef std::vector<std::vector<Polje>> Tabla;
// -------------------ENUM (end)---------------------

// -------------------PROTOTIPI---------------------
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
bool Pogresanformat(std::vector<std::vector<int>> &testsubj);
bool VanOpsega(std::vector<std::vector<int>> &testsubj, int granice);
void BrojMina(const Tabla &polja, int &x, int &y, std::vector<std::vector<int>> &Okolina);
bool NemaPraznih(Tabla &polja);
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
bool TacanUnos(std::string &unos);
bool Mine(std::string &unos);
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x= 0, int p_y = 0);
void Obrisi(Tabla &polje);
void PrijaviGresku(KodoviGresaka greska);
int BrojParametara(std::string &unos);
bool Test(std::string ulaz);
// -------------------PROTOTIPI (end)---------------------

// -------------------MAIN FUNKCIJA---------------------
int main ()
{
    Tabla polja;
    int  tek_x(0),tek_y(0);
    try {
        while(true) {
            std::cout << "Unesite komandu: ";
            Komande komanda;
            Smjerovi smjer;
            int x(0),y(0);
            KodoviGresaka greska;
            if(UnosKomande(komanda,smjer,x,y,greska)) {
                try {
                    IzvrsiKomandu(komanda,polja,tek_x,tek_y,smjer,x,y);
                } catch(std::runtime_error) {
                    throw;
                }
            }
            else{
                PrijaviGresku(greska);
            }
        }
    } catch(std::runtime_error error) {
        std::cout << "Dovidjenja!";
    }

    return 0;
}
// -------------------MAIN FUNKCIJA (end)---------------------

//--------------------Pogresanformat--------------------------
bool Pogresanformat(const std::vector<std::vector<int>> &testsubj)
{
    for(auto &x : testsubj)
        if(x.size() != 2)
            return true;


    return false;
}
//--------------------Pogresanformat (end)--------------------------

//----------------------OBIČNA I OVERLOADED FUNKCIJE VanOpsega--------------------
bool VanOpsega(const std::vector<std::vector<int>> &testsubj, int granice)
{
    for(auto &x : testsubj)
        for(auto &y : x)
            if(y < 0 || y >= granice)
                return true;

    return false;
}
bool VanOpsega(const Tabla &testsubj, int &x_koord, int &y_koord)
{
    if(x_koord < 0 || x_koord >= testsubj.size())
        return true;

    for(auto &x : testsubj)
        if(y_koord < 0 || y_koord >= x.size())
            return true;

    return false;
}
//----------------------OBIČNA I OVERLOADED FUNKCIJE VanOpsega (end)--------------------


//----------------------KreirajIgru--------------------
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
    if(Pogresanformat(mine)) throw std::domain_error("Ilegalan format zadavanja mina");
    if(VanOpsega(mine,n))   throw std::domain_error("Ilegalne pozicije mina");

    Tabla mapa(n,std::vector<Polje>(n,Polje::Prazno));

    for(int k(0); k < mine.size(); k++)
        for(int i(0); i < n; i++)
            for(int j(0); j < n; j++)
                if(i == mine[k][0] && j == mine[k][1])
                    mapa[i][j] = Polje::Mina;

    return mapa;
}
//----------------------KreirajIgru (end)--------------------


//---------------------PrikaziOkolinu i njoj pomocna funkcija-------------------------------
void BrojMina(const Tabla &polja, int &x, int &y, std::vector<std::vector<int>> &Okolina)
{
    static int k(0);
    static int red(x);

    if(red != x)
        red = x;

    for(int i(x-1); i < x+2; i++) {

        if(i > -1 && i < polja.size())
            for(int j(y-1); j < y+2; j++)
                if(j > -1 && j < polja[i].size() && !(i == x && j == y))
                    if(polja[i][j] == Polje::Mina)
                        Okolina[red][k]++;
    }

    k++;
    if( k == 3)
        k = 0;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{

    if(VanOpsega(polja,x,y)) throw std::domain_error("Polje (" + std::to_string(x) +"," + std::to_string(y) + ") ne postoji");
    std::vector<std::vector<int>> Okolina(3,std::vector<int>(3));

    for(int i(x-1); i < x+2; i++)
        for(int j(y-1); j < y+2; j++)
            if(i> -1 && j > -1)
                BrojMina(polja, i,j,Okolina);

    return Okolina;
}
//---------------------PrikaziOkolinu i njoj pomocna funkcija (end)-------------------------------

//------------------------------Blokiraj i Deblokiraj-----------------------------------
void BlokirajPolje(Tabla &polja, int x, int y)
{
    if(VanOpsega(polja,x,y)) throw std::domain_error("Polje (" + std::to_string(x) +"," + std::to_string(y) + ") ne postoji");

    for(int i(0); i < polja.size(); i++)
        for(int j(0); j < polja.size(); j++)
            if(i == x && j == y) {
                if(polja[i][j] == Polje::Prazno)
                    polja[i][j] = Polje::BlokiranoPrazno;

                else if(polja[i][j] == Polje::Mina)
                    polja[i][j] = Polje::BlokiranoMina;

                else if(polja[i][j] == Polje::Posjeceno) polja[i][j] = Polje::BlokiranoProsjeceno;
            }
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
    if(VanOpsega(polja,x,y)) throw std::domain_error("Polje (" + std::to_string(x) +"," + std::to_string(y) + ") ne postoji");

    for(int i(0); i < polja.size(); i++)
        for(int j(0); j < polja.size(); j++)
            if(i == x && j == y) {
                if(polja[i][j] == Polje::BlokiranoPrazno)
                    polja[i][j] = Polje::Prazno;
                else if(polja[i][j] == Polje::BlokiranoMina)
                    polja[i][j] = Polje::Mina;
                else if(polja[i][j] == Polje::BlokiranoProsjeceno) polja[i][j] = Polje::Posjeceno;
            }
}
//------------------------------Blokiraj i Deblokiraj (end)-----------------------------------

//------------------------------Idi FUNKCIJE i njima pomocne----------------------------------
void Obrisi(Tabla &polje)
{
    for(auto &x : polje)
        for(auto &y : x)
            y = Polje::Prazno;
}
bool NemaPraznih(Tabla &polja)
{
    int br_praznih(0);
    for(auto &x : polja)
        for(auto &y : x)
            if(y == Polje::Prazno)
                br_praznih++;

    if(br_praznih == 1 || br_praznih == 0)
        return true;

    return false;
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    if(VanOpsega(polja,x,y)) throw std::out_of_range("Izlazak van igrace table");
    polja[x][y] = Polje::Posjeceno;
    int tempx(x),tempy(y);
    switch(int(smjer)) {
    case 0:
        x--,y--;
        break;
    case 1:
        x--;
        break;
    case 2:
        x--,y++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x++,y++;
        break;
    case 5:
        x++;
        break;
    case 6:
        x++,y--;
        break;
    case 7:
        y--;
        break;

    }

    if(VanOpsega(polja,x,y)){ 
        x = tempx;
        y = tempy;
        throw std::out_of_range("Izlazak van igrace table");
        
    }

    else if(polja[x][y] == Polje::Mina) {
        Obrisi(polja);
        return Status::KrajPoraz;
    } else if(polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina || polja[x][y] == Polje::BlokiranoProsjeceno){
        x = tempx;
        y = tempy;
        throw std::logic_error("Blokirano polje");
    }

    else if(NemaPraznih(polja))
        return Status::KrajPobjeda;

    else return Status::NijeKraj;
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    if(VanOpsega(polja,novi_x,novi_y)) throw std::out_of_range("Izlazak van igrace table");
    if(polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_y] == Polje::BlokiranoProsjeceno)
        throw std::logic_error("Blokirano polje");

    polja[x][y] = Polje::Posjeceno;
    x = novi_x;
    y = novi_y;
    if(polja[novi_x][novi_y] == Polje::Mina) {
        Obrisi(polja);
        return Status::KrajPoraz;
    }
    if(NemaPraznih(polja))
        return Status::KrajPobjeda;

    else return Status::NijeKraj;

}
//------------------------------Idi FUNKCIJE i njima pomocne (end)----------------------------------

//------------------------------UnosKomande------------------------------
int BrojParametara(std::string &unos)
{
    int p(0);
    int duzina(unos.length());
    int param(0);
    while(p < duzina) {
        while(p < duzina && unos[p] == ' ') p++;
        if(unos[p] >= '0' && unos[p] <='9')
            param++;
   
        while(p < duzina && unos[p] != ' ') p++;
            
        if(p < duzina && param >= 2)
            if(unos[p] != ' ')
                param++;
        
        
        p++;
    }

    
return param;
}
bool TacanUnos(std::string &unos)
{
    int p(0);
    int duzina(unos.length());
    while(p < duzina && unos[p] == ' ') p++;
    if(p < duzina && (unos[p] == 'B' || unos[p] == 'D')) {
        p++;
        while(p < duzina) {
            if(!(unos[p] == ' ' || unos[p] >= '0' && unos[p] <='9'))
                return false;
            p++;
        }
    } else if(unos[p] == 'P') {
        p++;
        if (unos[p] == '>') {
            p++;
                while(p < duzina && unos[p] == ' ') p++;
                
                if(p < duzina &&  !(unos[p] >= '0' && unos[p] <='9'))
                    return false;
        }
    }
    return true;
}

bool Mine(std::string &unos)
{
    int p(0);
    int duzina(unos.length());
    while(p < duzina) {
        if(unos[0] != '(')
            return false;
        p++;
        while(p < duzina && unos[p] != ',') {
            if(!(unos[p] >= '0' && unos[p] <= '9'))
                return false;
            p++;
        }

        if(p < duzina && unos[p] != ',')
            return false;
        p++;
        while(p < duzina && unos[p] != ')') {
            if(!(unos[p] >= '0' && unos[p] <= '9'))
                return false;
            p++;
        }

        if(p < duzina && unos[p] != ')')
            return false;
        p++;
    }

    return true;
}

bool Test(std::string ulaz){
    int p(0); 
    int duzina(ulaz.length());
    if(ulaz[p] == 'Z' || ulaz[p] == 'K'){
    p++;
    while(p < duzina){
            if(ulaz[p] != ' ')
            return true;
        
        p++;
    }
    }
    else if(ulaz[p] == 'P'){
        p++;
        while(p<duzina){
            if(ulaz[p] != ' ' && ulaz[p] != 'O')
                return true;
                
            p++;
        }
    }
    return false;
}

void PrijaviGresku(KodoviGresaka greska)
{

    switch(int(greska)) {
    case 0:
        std::cout << "Nerazumljiva komanda!" << std::endl;
        break;
    case 1:
        std::cout << "Komanda trazi parametar koji nije naveden!"<< std::endl;
        break;
    case 2:
        std::cout << "Zadan je suvisan parametar nakon komande!"<< std::endl;
        break;
    case 3:
        std::cout <<"Parametar komande nije ispravan!" << std::endl;
        break;
    }
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
    std::string unos_komande;
    std::getline(std::cin,unos_komande);
    int duzina(unos_komande.length());
    int p(0);
    while(p < duzina && unos_komande[p] == ' ') p++;
    switch(unos_komande[p]) {

    case 'K': {
        if(Test(unos_komande)){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }

        komanda = Komande::KreirajIgru;
        return true;
        break;
    }
    case 'Z':
    if(Test(unos_komande)){
            greska = KodoviGresaka::PogresnaKomanda;
            return false;
        }
        komanda = Komande::ZavrsiIgru;
        return true;
        break;
    case 'D':
        if(TacanUnos(unos_komande)) {
            int param(BrojParametara(unos_komande));
            if(param > 2){
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
            else if(param < 2){
                greska = KodoviGresaka::NedostajeParametar;
            }
            p++;
            while(p < duzina && unos_komande[p] == ' ') p++;
            x = unos_komande[p] - '0';
            p++;
            while(p < duzina && unos_komande[p] == ' ') p++;
            y = unos_komande[p] - '0';
            komanda = Komande::Deblokiraj;
            return true;
        } else {
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        break;
    case 'B':
        if(TacanUnos(unos_komande)) {
            int param(BrojParametara(unos_komande));
            if(param > 2){
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
            else if(param < 2){
                greska = KodoviGresaka::NedostajeParametar;
            }
            p++;
            while(unos_komande[p] == ' ') p++;
            x = unos_komande[p] - '0';
            p++;
            while(p < duzina && unos_komande[p] == ' ') p++;
            y = unos_komande[p] - '0';
            komanda = Komande::Blokiraj;
            return true;
        } else {
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }

        break;
    case 'P':
        if(p+1 < duzina && unos_komande[p+1] == 'O') {
            if(Test(unos_komande)){
            greska = KodoviGresaka::PogresnaKomanda;
            return false;
        }
            komanda = Komande::PrikaziOkolinu;
            return true;
        }
            if(p+1 < duzina && unos_komande[p+1] == '1') {
                p+=2;
                int z(p);
                while(z < duzina){
                    if (unos_komande[z] != ' ' && unos_komande[z] != 'G' && unos_komande[z] != 'L' && unos_komande[z] != 'o' && unos_komande[z]!='D'){
                        greska = KodoviGresaka::NeispravanParametar;
                        return false;
                    }
                    z++;
                }
                komanda = Komande::PomjeriJednoMjesto;
                while(unos_komande[p] == ' ') p++;
                int q(p);
                while( q< duzina && unos_komande[q] != ' ') q++;
                if(unos_komande.substr(p,q-p) == "G")
                    smjer = Smjerovi::Gore;
                else if(unos_komande.substr(p,q-p) == "GL")
                    smjer = Smjerovi::GoreLijevo;
                else if(unos_komande.substr(p,q-p) == "GD")
                    smjer = Smjerovi::GoreDesno;
                else if(unos_komande.substr(p,q-p) == "D")
                    smjer = Smjerovi::Desno;
                else if(unos_komande.substr(p,q-p) == "L")
                    smjer = Smjerovi::Lijevo;
                else if(unos_komande.substr(p,q-p) == "Do")
                    smjer = Smjerovi::Dolje;
                else if(unos_komande.substr(p,q-p) == "DoD")
                    smjer = Smjerovi::DoljeDesno;
                else if(unos_komande.substr(p,q-p) == "DoL")
                    smjer = Smjerovi::DoljeLijevo;
                else if(q - p == 0){
                    greska = KodoviGresaka::NedostajeParametar;
                    return false;
                }
                else{
                    greska = KodoviGresaka::SuvisanParametar;
                }
                    
                return true;
            } else if(p+1 < duzina && unos_komande[p+1] == '>') {
                if(!TacanUnos(unos_komande)){
                    greska = KodoviGresaka::NeispravanParametar;
                    return false;
                }
                int param(BrojParametara(unos_komande));
                if(param > 2){
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
            else if(param < 2){
                greska = KodoviGresaka::NedostajeParametar;
                return false;
            }
                int novi_x(0),novi_y(0);
                int stepen(1);

                p = unos_komande.length()-1;
                komanda = Komande::PomjeriDalje;
                while(unos_komande[p] == ' ') p--;
                while(unos_komande[p] >= '0' && unos_komande[p] <= '9') {
                    novi_y += (unos_komande[p--] - '0')*stepen;
                    stepen*=10;
                }
                y = novi_y;
                stepen = 1;
                while(unos_komande[p] == ' ') p--;
                while(unos_komande[p] >= '0' && unos_komande[p] <= '9') {
                    novi_x += (unos_komande[p--] - '0')*stepen;
                    stepen*=10;
                }
                x = novi_x;

                return true;
            }


         else {
            greska = KodoviGresaka::PogresnaKomanda;
            return false;
        }
        break;

    default:
        greska = KodoviGresaka::PogresnaKomanda;
        break;
    }

    return false;
}
//------------------------------UnosKomande (end)------------------------------

//------------------------------IzvrsiKomandu-----------------------------------
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer, int p_x, int p_y)
{
    try{
    switch(int(komanda)) {
    case 0: {
        Status status(Idi(polja,x,y,p_smjer));
        switch(int(status)) {
        case 0:
            break;
        case 1:
            std::cout << "Nagazili ste na minu" << std::endl;
            Obrisi(polja);
            throw std::runtime_error("Igra zavrsena");
            break;
        case 2:
            std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
            Obrisi(polja);
            throw std::runtime_error("Igra zavrsena");
            break;
        }
        std::cout << "Tekuca pozicija igraca je (" << x << ","<< y <<")" << std::endl;
        break;
    }
    case 1: {
        Status status2(Idi(polja,x,y,p_x,p_y));
        switch(int(status2)) {
        case 0:
            break;
        case 1:
            std::cout << "Nagazili ste na minu" << std::endl;
            throw std::runtime_error("Igra zavrsena");
            break;
        case 2:
            std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
            throw std::runtime_error("Igra zavrsena");
            break;
        }
        std::cout << "Tekuca pozicija igraca je (" << x << ","<<y <<")" << std::endl;

        break;
    }
    case 2:
        BlokirajPolje(polja,p_x,p_y);
        break;
    case 3:
        DeblokirajPolje(polja,p_x,p_y);
        break;
    case 4: {
        auto okolina(PrikaziOkolinu(polja,x,y));
        for(auto &x : okolina) {
            for(auto &y : x)
                std::cout << y <<" ";
            std::cout << std::endl;
        }
        break;
    }
    case 5: {
        throw std::runtime_error("Igra zavrsena");
        break;
    }
    case 6: {
        std::cout << "Unesite broj polja: ";
        int n;
        std::cin >> n;
        std::cout << "Unesite pozicije mina: ";
        std::string pozicije;
        std::vector<std::vector<int>> Minirano;
        std::cin.ignore(10000,'\n');
        int i(0);
        while(true) {
            std::getline(std::cin,pozicije);

            if(pozicije == ".")
                break;
            int x_koord(0),y_koord(0);

            if(Mine(pozicije)) {
                int p(pozicije.length() - 2),stepen(1);
                int q(0);
                while(pozicije[q] != ',')
                    q++;

                while(pozicije[p] != '(') {


                    while(q < p) {
                        y_koord += (pozicije[p] - '0')*stepen;
                        stepen *=10;
                        p--;
                    }

                    p--;
                    stepen *= 10;
                    if(pozicije[p+1] == ',')
                        stepen = 1;

                    if(pozicije[p] >= '0' && pozicije[p] <= '9')
                        x_koord += (pozicije[p] - '0')*stepen;
                }

                if(x_koord >= 0 && x_koord < n && y_koord >= 0 && y_koord < n) {
                    Minirano.resize(i+1);
                    Minirano[i].push_back(x_koord);
                    Minirano[i].push_back(y_koord);
                    i++;
                } else
                    std::cout << "Greska, unesite ponovo!" << std::endl;
            } else
                std::cout << "Greska, unesite ponovo!" << std::endl;
        }
        polja = KreirajIgru(n,Minirano);
       
 
        break;
    }

    }
        
    }catch(std::domain_error error) {
                    std::cout << error.what() << std::endl;
                } catch(std::out_of_range error) {
                    std::cout << error.what() << std::endl;;
                } catch(std::logic_error error) {
                    std::cout << error.what() << std::endl;
}
}
//------------------------------IzvrsiKomandu (end)-----------------------------------