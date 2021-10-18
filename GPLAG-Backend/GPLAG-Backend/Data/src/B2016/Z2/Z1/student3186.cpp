//B 16/17, Zadaća 2, Zadatak 1
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

enum class Polje {
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine) 
{
    // Testiranje da li su koordinate..
    for (int i=0; i<mine.size(); ++i) 
        if (not(mine[i].size() == 2))  throw std::domain_error ("Ilegalan format zadavanja mina");
    // Testiranje da li izlazi iz opsega..
    for (int i=0; i < mine.size(); ++i)
        if (mine[i][0] >= n or mine[i][0] < 0 or mine[i][1] >= n or mine[i][1] < 0)
            throw std::domain_error ("Ilegalne pozicije mina");
    
    // Inicijalizacija prazne table..
    Tabla igracka_tabla (n, std::vector<Polje> (n, Polje::Prazno));
    
    // Dodjela mina na praznu plohu..
    for (int x=0; x<mine.size(); ++x) {
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (mine[x][0] == i and mine[x][1] == j)
                    igracka_tabla[i][j] = Polje::Mina;
    }   return igracka_tabla;
}

void IzbaciPolje (int x, int y) {   
    throw std::domain_error (std::string ("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji"));
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) 
{
    // Test da li koord izlazi iz opsega..
    if (x < 0 or x >=polja.size() or y < 0 or y >= polja[0].size())  IzbaciPolje(x,y);//throw std::domain_error ("Polje (x,y) ne postoji");
    // else vrati mi vektor..
    std::vector<std::vector<int>> OkolneMine (3, std::vector<int> (3,0));
    
    // Provjeri sve okolne tacke..
    int input_red(0);
    for (int osa_x=x-1; osa_x<=x+1; ++osa_x) {
        int input_kolona(0);
        for (int osa_y=y-1; osa_y<=y+1; ++osa_y) {
            int brojac(0);
            // Provjeri sve okolne okolnih..
            for (int red=osa_x-1; red<=osa_x+1; ++red) {
                if (red < 0 or red >= polja.size()) continue;
                for (int vrsta=osa_y-1; vrsta<=osa_y+1; ++vrsta) {
                    if (vrsta < 0 or vrsta >= polja[y].size()) continue;
                    if (osa_x == red and osa_y == vrsta) continue;
                    if (polja[red][vrsta] == Polje::Mina) brojac++;
                }
            }
            OkolneMine [input_red][input_kolona++] = brojac;
        }   input_red++;
    }   return OkolneMine;   
}

void BlokirajPolje (Tabla &polja, int x, int y) {
    if (x<0 or x >=polja.size() or y<0 or y>=polja[0].size()) IzbaciPolje(x, y);//throw std::domain_error ("Polje (x,y) ne postoji");
    if (polja[x][y] == Polje::Prazno)       polja[x][y] = Polje::BlokiranoPrazno;
    if (polja[x][y] == Polje::Posjeceno)    polja[x][y] = Polje::BlokiranoPosjeceno;
    if (polja[x][y] == Polje::Mina)         polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje (Tabla &polja, int x, int y) {
    if (x<0 or x >=polja.size() or y<0 or y>=polja[0].size()) IzbaciPolje(x, y);//throw std::domain_error ("Polje (x,y) ne postoji");
    if (polja[x][y] == Polje::BlokiranoPrazno)      polja[x][y] = Polje::Prazno;
    if (polja[x][y] == Polje::BlokiranoPosjeceno)   polja[x][y] = Polje::Posjeceno;
    if (polja[x][y] == Polje::BlokiranoMina)        polja[x][y] = Polje::Mina;
}

enum class Status {
    NijeKraj, KrajPoraz, KrajPobjeda
};

enum class Smjerovi {
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

bool ImaLiPraznih (const Tabla &polja, const int &x, const int &y) {
    for (int i=0; i<polja.size(); ++i)
        for (int j=0; j<polja[i].size(); ++j) {
            if (x == i and y == j)  continue;
            if (polja[i][j] == Polje::Prazno or polja[i][j] == Polje::BlokiranoPrazno)
                return false; 
            }   return true;
}

void PostaviPrazne (Tabla &polja) {
    for (int i=0; i<polja.size(); ++i)
        for (int j=0; j<polja[i].size(); ++j)
            polja[i][j] = Polje::Prazno;
}
// Varijanta I..
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
    // Out of range..
    if ((smjer == Smjerovi::GoreLijevo and ((x-1) <0 or (x-1)>=polja.size() or (y-1)<0 or (y-1)>=polja[0].size())) or
    (smjer == Smjerovi::Gore and ((x-1)<0 or (x-1)>=polja.size() or y<0 or y >= polja[0].size())) or
    (smjer == Smjerovi::GoreDesno and ((x-1)<0 or (x-1)>=polja.size() or (y+1)<0 or (y+1)>=polja[0].size())) or
    (smjer == Smjerovi::Desno and (x<0 or x>=polja.size() or (y+1)<0 or (y+1)>=polja[0].size())) or 
    (smjer == Smjerovi::DoljeDesno and ((x+1)<0 or (x+1)>=polja.size() or (y+1)<0 or (y+1)>=polja[0].size())) or
    (smjer == Smjerovi::Dolje and ((x+1)<0 or (x+1)>=polja.size() or y<0 or y>=polja[0].size())) or
    (smjer == Smjerovi::DoljeLijevo and ((x+1)<0 or (x+1)>=polja.size() or (y-1)<0 or (y-1) >=polja[0].size())) or
    (smjer == Smjerovi::Lijevo and (x<0 or x>=polja.size() or (y-1)<0 or (y-1)>=polja[0].size())))
        throw std::out_of_range ("Izlazak van igrace table");
    
    // Logic error..
    if ((smjer == Smjerovi::GoreLijevo and (polja[x-1][y-1] == Polje::BlokiranoPrazno or polja[x-1][y-1] == Polje::BlokiranoPosjeceno or polja[x-1][y-1] == Polje::BlokiranoMina)) or
    (smjer == Smjerovi::Gore and (polja[x-1][y]==Polje::BlokiranoPrazno or polja[x-1][y]==Polje::BlokiranoPosjeceno or polja[x-1][y]==Polje::BlokiranoMina)) or
    (smjer == Smjerovi::GoreDesno and (polja[x-1][y+1]==Polje::BlokiranoPrazno or polja[x-1][y+1]==Polje::BlokiranoPosjeceno or polja[x-1][y+1]==Polje::BlokiranoMina)) or
    (smjer == Smjerovi::Desno and (polja[x][y+1]==Polje::BlokiranoPrazno or polja[x][y+1]==Polje::BlokiranoPosjeceno or polja[x][y+1]==Polje::BlokiranoMina)) or
    (smjer == Smjerovi::DoljeDesno and (polja[x+1][y+1]==Polje::BlokiranoPrazno or polja[x+1][y+1]==Polje::BlokiranoPosjeceno or polja[x+1][y+1]==Polje::BlokiranoMina)) or
    (smjer == Smjerovi::Dolje and (polja[x+1][y]==Polje::BlokiranoPrazno or polja[x+1][y]==Polje::BlokiranoPosjeceno or polja[x+1][y]==Polje::BlokiranoMina)) or
    (smjer == Smjerovi::DoljeLijevo and (polja[x+1][y-1]==Polje::BlokiranoPrazno or polja[x+1][y-1]==Polje::BlokiranoPosjeceno or polja[x+1][y-1]==Polje::BlokiranoMina)) or
    (smjer == Smjerovi::Lijevo and (polja[x][y-1]==Polje::BlokiranoPrazno or polja[x][y-1]==Polje::BlokiranoPosjeceno or polja[x][y-1]==Polje::BlokiranoMina)))
        throw std::logic_error ("Blokirano polje");
        
    // Kretanje..
    if (smjer == Smjerovi::GoreLijevo)          polja[x--][y--] = Polje::Posjeceno;
    else if (smjer == Smjerovi::Gore)           polja[x--][y] = Polje::Posjeceno;
    else if (smjer == Smjerovi::GoreDesno)      polja[x--][y++] = Polje::Posjeceno;
    else if (smjer == Smjerovi::Desno)          polja[x][y++] = Polje::Posjeceno;
    else if (smjer == Smjerovi::DoljeDesno)     polja[x++][y++] = Polje::Posjeceno;
    else if (smjer == Smjerovi::Dolje)          polja[x++][y] = Polje::Posjeceno;
    else if (smjer == Smjerovi::DoljeLijevo)    polja[x++][y--] = Polje::Posjeceno;
    else if (smjer == Smjerovi::Lijevo)         polja[x][y--] = Polje::Posjeceno;
    
    if (polja[x][y] == Polje::Mina) {
        PostaviPrazne (polja);
        return Status::KrajPoraz;
    }
    else if (ImaLiPraznih(polja, x, y) and not(polja[x][y] == Polje::Mina))   return Status::KrajPobjeda;
    else return Status::NijeKraj;
}
// Varijanta II..
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
    if (novi_x<0 or novi_x>=polja.size() or novi_y<0 or novi_y>=polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
    if (polja[novi_x][novi_y] == Polje::BlokiranoPrazno or polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno or polja[novi_x][novi_y] == Polje::BlokiranoMina)
        throw std::logic_error ("Blokirano polje");
        
    polja[x][y] = Polje::Posjeceno;
    x = novi_x; y = novi_y;
    
    if (polja[x][y] == Polje::Mina) {
        PostaviPrazne (polja);
        return Status::KrajPoraz;
    }
    else if (ImaLiPraznih (polja, x, y) and not(polja[x][y] == Polje::Mina))  return Status::KrajPobjeda;
    else return Status::NijeKraj;
}

enum class KodoviGresaka {
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku (KodoviGresaka error_tekst) {
    if (error_tekst == KodoviGresaka::PogresnaKomanda)          std::cout << "Nerazumljiva komanda!" << std::endl;
    else if (error_tekst == KodoviGresaka::NedostajeParametar)  std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
    else if (error_tekst == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
    else if (error_tekst == KodoviGresaka::SuvisanParametar)    std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

enum class Komande {
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj,
    PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) 
{
    std::string input;
    std::getline (std::cin, input);
    bool kontrolna {false};
    
    int brojac_inputa(0), temp_x(0), temp_y(0);
    std::string temp_komanda,   temp_parametar;
    
    for (int i=0; i<input.length(); ++i) {
        if (input[i] == ' ')    continue;
        else {
            if (brojac_inputa == 0) {
                while (i < input.length() and not(input[i] == ' '))
                    temp_komanda += input[i++];
                    brojac_inputa++;    i--;
            }
            else if (brojac_inputa and temp_komanda == "P1") {
                while (i< input.length() and not(input[i] == ' '))
                    temp_parametar += input[i++];
                    brojac_inputa++;    i--;
            }
            else if (brojac_inputa and (temp_komanda == "P>" or temp_komanda == "B" or temp_komanda == "D") and (input[i] >= '0' and input[i] <= '9')) {
                    while (i< input.length() and (input[i] >= '0' and input[i] <= '9')) {
                        if (brojac_inputa == 1) {      temp_x = temp_x*10 + int(input[i++] - '0');   }
                        else if (brojac_inputa == 2) {    temp_y = temp_y*10 + int(input[i++] - '0'); }
                    }   brojac_inputa++;    i--;
            }
            else {
                kontrolna = true;
                while (i< input.length() and (input[i] != ' ')) i++;
                brojac_inputa++;
            }
        }
    }
    
    if (brojac_inputa == 2 and temp_komanda == "P1") {
        komanda = Komande::PomjeriJednoMjesto;
        
        if (temp_parametar == "GL")         smjer = Smjerovi::GoreLijevo;
        else if (temp_parametar == "G")     smjer = Smjerovi::Gore;
        else if (temp_parametar == "GD")    smjer = Smjerovi::GoreDesno;
        else if (temp_parametar == "D")     smjer = Smjerovi::Desno;
        else if (temp_parametar == "DoD")   smjer = Smjerovi::DoljeDesno;
        else if (temp_parametar == "Do")    smjer = Smjerovi::Dolje;
        else if (temp_parametar == "DoL")   smjer = Smjerovi::DoljeLijevo;
        else if (temp_parametar == "L")     smjer = Smjerovi::Lijevo;
        else {  greska = KodoviGresaka::NeispravanParametar;   return false;   
        }   return  true;
    }
    else if (brojac_inputa < 2 and temp_komanda == "P1") {
        greska = KodoviGresaka::NedostajeParametar;
        return false;
    }
    else if (brojac_inputa == 3 and (temp_komanda == "P>" or temp_komanda == "B" or temp_komanda == "D")) {
        if (temp_komanda == "P>")         komanda = Komande::PomjeriDalje;
        else if (temp_komanda == "B")     komanda = Komande::Blokiraj;
        else if (temp_komanda == "D")     komanda = Komande::Deblokiraj;
            x = temp_x;     y = temp_y;     return true;    
    }
    else if (brojac_inputa < 3 and (temp_komanda == "P>" or temp_komanda == "B" or temp_komanda == "D")) {
        if (kontrolna) {    greska = KodoviGresaka::NeispravanParametar;    return false;   }
        else {              greska = KodoviGresaka::NedostajeParametar;     return false;   }
    }
    else if (brojac_inputa == 1 and (temp_komanda == "PO" or temp_komanda == "Z" or temp_komanda == "K")) {
        if (temp_komanda == "PO")           komanda = Komande::PrikaziOkolinu;
        else if (temp_komanda == "Z")       komanda = Komande::ZavrsiIgru;
        else if (temp_komanda == "K")       komanda = Komande::KreirajIgru;
        return true;
    }
    else if (brojac_inputa == 1 and not(temp_komanda == "PO" or temp_komanda == "Z" or temp_komanda == "K" or
    temp_komanda == "P>" or temp_komanda == "B" or temp_komanda == "D" or temp_komanda == "P1")) {
                greska = KodoviGresaka::PogresnaKomanda;    
                return false;
    }
    else if (brojac_inputa == 0) {
        greska = KodoviGresaka::NedostajeParametar;
        return false;
    }
    else {
        greska = KodoviGresaka::SuvisanParametar;
        return false;
    }
}

void ZavrsiIgru (Tabla &polja) {
    for (int i=0; i<polja.size(); ++i)
        for (int j=0; j<polja[i].size(); ++j)
            polja[i][j] = Polje::Prazno;
    throw std::runtime_error ("Igra zavrsena!");
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
    if (komanda == Komande::PomjeriJednoMjesto) {
        try {
            Status idi_temp (Idi(polja, x, y, p_smjer));
            if (idi_temp == Status::KrajPobjeda) {
                std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
                ZavrsiIgru(polja);
            }   else if (idi_temp == Status::KrajPoraz) {
                std::cout << "Nagazili ste na minu" << std::endl;
                ZavrsiIgru(polja);
            }   else    std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
        }   catch (std::domain_error text) {    std::cout << text.what() << std::endl;  }
            catch (std::out_of_range text) {    std::cout << text.what() << std::endl;  }
    }
    else if (komanda == Komande::PomjeriDalje) {
        try {
            Status idi_temp (Idi(polja, x, y, p_x, p_y));
            if (idi_temp == Status::KrajPobjeda) {
                std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
                ZavrsiIgru(polja);
            }   else if (idi_temp == Status::KrajPoraz) {
                std::cout << "Nagazili ste na minu" << std::endl;
                ZavrsiIgru(polja);
            }   else    std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
        }   catch (std::domain_error text) {    std::cout << text.what() << std::endl;  }
            catch (std::out_of_range text) {    std::cout << text.what() << std::endl;  }
            catch (std::logic_error text)  {    std::cout << text.what() << std::endl;  }
    }
    else if (komanda == Komande::Blokiraj) {
        try {
            BlokirajPolje(polja, p_x, p_y);
        }   catch (std::domain_error text) {    std::cout << text.what() << std::endl;  }
    }   
    else if (komanda == Komande::Deblokiraj) {
        try {
            DeblokirajPolje(polja, p_x, p_y);
        }   catch (std::domain_error text) {    std::cout << text.what() << std::endl;  }
    }
    else if (komanda == Komande::PrikaziOkolinu) {
        try {
            for (auto red : PrikaziOkolinu(polja, x, y)) {
                for (auto x : red)  std::cout << x << " ";
                std::cout << std::endl;
            }
        }   catch (std::domain_error text)  {   std::cout << text.what() << std::endl;  }
    }   
    else if (komanda == Komande::ZavrsiIgru) {
        ZavrsiIgru(polja);
    }   
    else if (komanda == Komande::KreirajIgru) {
        int n_polja;
        std::cout << "Unesite broj polja: ";
        std::cin >> n_polja;
        std::cin.clear();   std::cin.ignore(10000, '\n');
        
        int vel(0);
        std::cout << "Unesite pozicije mina: ";
        std::vector<std::vector<int>> Mine;
        for (;;) {
            std::string input;
            std::getline (std::cin, input);
            
            if (input == ".")   break;
            else {
                bool tacan_format(true);
                int x(0), y(0), brojac(0);
                for (int i=0; i<input.length(); ++i) {
                    if (input[i] == ' ')    continue;
                    else if (brojac == 0 and input[i] == '(')   brojac++;
                    else if (brojac == 1 and (input[i] >= '0' and input[i] <= '9')) {
                        while (i<input.length() and (input[i] >= '0' and input[i] <= '9'))
                            x = x*10 + int(input[i++]-'0');     brojac++;   i--;
                    }   else if (brojac == 2 and input[i] == ',')   brojac++;
                    else if (brojac == 3 and (input[i] >= '0' and input[i] <= '9')) {
                        while (i<input.length() and (input[i] >= '0' and input[i] <= '9'))
                            y = y*10 + int(input[i++]-'0');     brojac++;   i--;
                    }   else if (brojac == 4 and input[i] == ')')   brojac++;
                    else tacan_format = false;
                }
                
                if (brojac == 5 and (x >= 0 and x < n_polja and y >= 0 and y < n_polja) and tacan_format) {
                    Mine.resize(++vel); Mine[vel-1].resize(2);
                    Mine [vel-1][0] = x;  Mine[vel-1][1] = y;
                }   else {
                    std::cout << "Greska, unesite ponovo!" << std::endl;
                }
            }
        }   try {   polja = (KreirajIgru(n_polja, Mine));   }
        catch (std::domain_error text) {    std::cout << text.what() << std::endl;  }
    }
}

int main ()
{   
    Tabla igracka_tabla(0, std::vector<Polje> (0, Polje::Prazno));
    int x_original(0), y_original(0);

    for (;;) {
        std::cout << "Unesite komandu: ";
        int x(0), y(0); Komande komanda; Smjerovi smjer; KodoviGresaka greska;
        if (UnosKomande (komanda, smjer, x, y, greska)) try {
        IzvrsiKomandu (komanda, igracka_tabla, x_original, y_original, smjer, x, y);
        }   catch (std::runtime_error) {    std::cout << "Dovidjenja!";    break;  } 
        else PrijaviGresku(greska);
    }   return 0;
}