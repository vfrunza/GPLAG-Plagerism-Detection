#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
typedef std::vector<std::vector<Polje>> Tabla;
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

std::string Napravi_string_iz_broja (int x)
{
    int kopija_x = x;
    
    std::string s_x;
    
    if (kopija_x<0)
        kopija_x*=-1;
        
    while (kopija_x>0)
        {
            int a = kopija_x%10;
            char c = a+48;
            s_x.push_back(c);
            
            kopija_x/=10;
        }
        
    int l = s_x.length()-1;
    for (int i{};i<s_x.length();i++)
    {
        if (i>=l)
            break;
        
        char c = s_x[i];
        s_x[i] = s_x[l];
        s_x[l] = c;
    }
    
    if (x<0)
        s_x = '-'+s_x;
    
    return s_x;
}

int Prebroji_mine_u_okolini (const Tabla &polja, int x, int y)
{
    int broj_mina = 0;
    
    bool opseg_x_manje = true;
    bool opseg_x = true;
    bool opseg_x_vece = true;
    bool opseg_y_manje = true;
    bool opseg_y = true;
    bool opseg_y_vece = true;
    
    if (x-1<0 || x-1>=polja.size())
        opseg_x_manje = false;
    if (x<0 || x>=polja.size())
        opseg_x = false;
    if (x+1<0 || x+1>=polja.size())
        opseg_x_vece = false;
    if (y-1<0 || y-1>=polja[0].size())
        opseg_y_manje = false;
    if (y<0 || y>=polja[0].size())
        opseg_y = false;
    if (y+1<0 || y+1>=polja[0].size())
        opseg_y_vece = false;
       
    if (opseg_x_manje == true && opseg_y_manje == true)
        {
            if (polja[x-1][y-1] == Polje::Mina)
                broj_mina++;
        }
    
    if (opseg_x_manje == true && opseg_y == true)
        {
            if (polja[x-1][y] == Polje::Mina)
                broj_mina++;
        }
    
    if (opseg_x_manje == true && opseg_y_vece == true)
        {
            if (polja[x-1][y+1] == Polje::Mina)
                broj_mina++;
        }
        
    if (opseg_x == true && opseg_y_manje == true)
        {
            if (polja[x][y-1] == Polje::Mina)
                broj_mina++;
        }
        
    if (opseg_x == true && opseg_y_vece == true)
        {
            if (polja[x][y+1] == Polje::Mina)
                broj_mina++;
        }
        
    if (opseg_x_vece == true && opseg_y_manje == true)
        {
            if (polja[x+1][y-1] == Polje::Mina)
                broj_mina++;
        }
        
    if (opseg_x_vece == true && opseg_y == true)
        {
            if (polja[x+1][y] == Polje::Mina)
                broj_mina++;
        }
        
    if (opseg_x_vece == true && opseg_y_vece == true)
        {
            if (polja[x+1][y+1] == Polje::Mina)
                broj_mina++;
        }
        
    return broj_mina;
}


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
    for (int i{};i<mine.size();i++)
        {
            if (mine[i].size() != 2)
                throw std::domain_error ("Ilegalan format zadavanja mina");
        }
    
    
    for (int i{};i<mine.size();i++)
        {
            for (int j{};j<mine[i].size();j++)
                {
                    if (mine[i][j] >= n)
                        throw std::domain_error ("Ilegalne pozicije mina");
                    
                    if (mine[i][j] < 0)
                        throw std::domain_error ("Ilegalne pozicije mina");
                }
        }
    
    
    std::vector<std::vector<Polje>> tabla (n, std::vector<Polje> (n));
    
    for (int i{};i<n;i++)
        {
            for (int j{};j<n;j++)
                tabla[i][j] = Polje::Prazno;
        }
    
    
    for (int i{};i<mine.size();i++)
        {
            int a = mine[i][0];
            int b = mine[i][1];
            
            tabla[a][b] = Polje::Mina;
        }
    
    
    return tabla;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    
    std::string s_x = Napravi_string_iz_broja(x);
    std::string s_y = Napravi_string_iz_broja(y);
    
    std::string izuzetak = "Polje ("+s_x+","+s_y+") ne postoji";
    
    if (x < 0 || x>=polja.size())
        throw std::domain_error (izuzetak);
    
    for (int i{};i<polja.size();i++)
        {
            if (y<0 || y>=polja[i].size())
                throw std::domain_error (izuzetak);
        }
    
    std::vector<std::vector<int>> rezultat (3, std::vector<int> (3));
    
    rezultat[0][0] = Prebroji_mine_u_okolini(polja,x-1,y-1);
    rezultat[0][1] = Prebroji_mine_u_okolini(polja,x-1,y);
    rezultat[0][2] = Prebroji_mine_u_okolini(polja,x-1,y+1);
    rezultat[1][0] = Prebroji_mine_u_okolini(polja,x,y-1);
    rezultat[1][1] = Prebroji_mine_u_okolini(polja,x,y);
    rezultat[1][2] = Prebroji_mine_u_okolini(polja,x,y+1);
    rezultat[2][0] = Prebroji_mine_u_okolini(polja,x+1,y-1);
    rezultat[2][1] = Prebroji_mine_u_okolini(polja,x+1,y);
    rezultat[2][2] = Prebroji_mine_u_okolini(polja,x+1,y+1);
    
    return rezultat;
    
}


void BlokirajPolje(Tabla &polja, int x, int y)
{
    std::string s_x = Napravi_string_iz_broja(x);
    std::string s_y = Napravi_string_iz_broja(y);
    
    std::string izuzetak = "Polje ("+s_x+","+s_y+") ne postoji";
    
    if (x < 0 || x>=polja.size())
        throw std::domain_error (izuzetak);
    
    for (int i{};i<polja.size();i++)
        {
            if (y<0 || y>=polja[i].size())
                throw std::domain_error (izuzetak);
        }
    
    if (polja[x][y] != Polje::BlokiranoPrazno || polja[x][y] != Polje::BlokiranoPosjeceno || polja[x][y] != Polje::BlokiranoMina)
        {
            if (polja[x][y] == Polje::Prazno)
                polja[x][y] = Polje::BlokiranoPrazno;
            else if (polja[x][y] == Polje::Posjeceno)
                polja[x][y] = Polje::BlokiranoPosjeceno;
            else if (polja[x][y] == Polje::Mina)
                polja[x][y] = Polje::BlokiranoMina;
        }
}


void DeblokirajPolje(Tabla &polja, int x, int y)
{
    std::string s_x = Napravi_string_iz_broja(x);
    std::string s_y = Napravi_string_iz_broja(y);
    
    std::string izuzetak = "Polje ("+s_x+","+s_y+") ne postoji";
    
    if (x < 0 || x>=polja.size())
        throw std::domain_error (izuzetak);
    
    for (int i{};i<polja.size();i++)
        {
            if (y<0 || y>=polja[i].size())
                throw std::domain_error (izuzetak);
        }
        
    if (polja[x][y] != Polje::Prazno || polja[x][y] != Polje::Posjeceno || polja[x][y] != Polje::Mina)
        {
            if (polja[x][y] == Polje::BlokiranoPrazno)
                polja[x][y] = Polje::Prazno;
            else if (polja[x][y] == Polje::BlokiranoPosjeceno)
                polja[x][y] = Polje::Posjeceno;
            else if (polja[x][y] == Polje::BlokiranoMina)
                polja[x][y] = Polje::Mina;
        }
    
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    bool opseg_x_manje = true;
    bool opseg_x = true;
    bool opseg_x_vece = true;
    bool opseg_y_manje = true;
    bool opseg_y = true;
    bool opseg_y_vece = true;
    
    if (x-1<0 || x-1>=polja.size())
        opseg_x_manje = false;
    if (x<0 || x>=polja.size())
        opseg_x = false;
    if (x+1<0 || x+1>=polja.size())
        opseg_x_vece = false;
    if (y-1<0 || y-1>=polja[0].size())
        opseg_y_manje = false;
    if (y<0 || y>=polja[0].size())
        opseg_y = false;
    if (y+1<0 || y+1>=polja[0].size())
        opseg_y_vece = false;
       
    if (smjer == Smjerovi::GoreLijevo)
        {
            if (opseg_x_manje != true || opseg_y_manje != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x-1][y-1] == Polje::BlokiranoPosjeceno || polja[x-1][y-1] == Polje::BlokiranoPrazno || polja[x-1][y-1] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
            
            polja[x][y] = Polje::Posjeceno;
            
            x--;
            y--;
        }
    
    if (smjer == Smjerovi::Gore)
        {
            if (opseg_x_manje != true || opseg_y != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x-1][y] == Polje::BlokiranoPosjeceno || polja[x-1][y] == Polje::BlokiranoPrazno || polja[x-1][y] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            x--;
        }
    
    if (smjer == Smjerovi::GoreDesno)
        {
            if (opseg_x_manje != true || opseg_y_vece != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x-1][y+1] == Polje::BlokiranoPosjeceno || polja[x-1][y+1] == Polje::BlokiranoPrazno || polja[x-1][y+1] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            x--;
            y++;
        }
        
    if (smjer == Smjerovi::Lijevo)
        {
            if (opseg_x != true || opseg_y_manje != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x][y-1] == Polje::BlokiranoPosjeceno || polja[x][y-1] == Polje::BlokiranoPrazno || polja[x][y-1] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            y--;
        }
        
    if (smjer == Smjerovi::Desno)
        {
            if (opseg_x != true || opseg_y_vece != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x][y+1] == Polje::BlokiranoPosjeceno || polja[x][y+1] == Polje::BlokiranoPrazno || polja[x][y+1] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            y++;
        }
        
    if (smjer == Smjerovi::DoljeLijevo)
        {
            if (opseg_x_vece != true || opseg_y_manje != true)
                throw std::out_of_range ("Izlazak van igrace table");
            
            if (polja[x+1][y-1] == Polje::BlokiranoPosjeceno || polja[x+1][y-1] == Polje::BlokiranoPrazno || polja[x+1][y-1] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            x++;
            y--;
        }
        
    if (smjer == Smjerovi::Dolje)
        {
            if (opseg_x_vece != true || opseg_y != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x+1][y] == Polje::BlokiranoPosjeceno || polja[x+1][y] == Polje::BlokiranoPrazno || polja[x+1][y] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            x++;
        }
        
    if (smjer == Smjerovi::DoljeDesno)
        {
            if (opseg_x_vece != true || opseg_y_vece != true)
                throw std::out_of_range ("Izlazak van igrace table");
                
            if (polja[x+1][y+1] == Polje::BlokiranoPosjeceno || polja[x+1][y+1] == Polje::BlokiranoPrazno || polja[x+1][y+1] == Polje::BlokiranoMina)
                throw std::logic_error ("Blokirano polje");
                
            polja[x][y] = Polje::Posjeceno;
            
            x++;
            y++;
        }
        
    
    if (polja[x][y] == Polje::Mina)
        {
            for (int i{};i<polja.size();i++)
                {
                    for (int j{};j<polja[i].size();j++)
                        polja[i][j] = Polje::Prazno;
                }
            
            return Status::KrajPoraz;
        }
        
    int broj_praznih = 0;
    for (int i{};i<polja.size();i++)
        {
            for (int j{};j<polja[i].size();j++)
                if (polja[i][j] == Polje::Prazno)
                    broj_praznih++;
        }
        
    if (broj_praznih == 0)
        return Status::KrajPobjeda;
        
    
    return Status::NijeKraj;
}


Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    
    if (novi_x < 0 || novi_x >= polja.size())
        throw std::out_of_range ("Izlazak van igrace table");
        
    if (novi_y < 0 || novi_y >= polja[0].size())
        throw std::out_of_range ("Izlazak van igrace table");
        
    if (polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
        throw std::logic_error ("Blokirano polje");
    
    polja[x][y] = Polje::Posjeceno;
            
    x = novi_x;
    y = novi_y;
    
    if (polja[x][y] == Polje::Mina)
        {
            for (int i{};i<polja.size();i++)
                {
                    for (int j{};j<polja[i].size();j++)
                        polja[i][j] = Polje::Prazno;
                }
            
            return Status::KrajPoraz;
        }
        
    int broj_praznih = 0;
    for (int i{};i<polja.size();i++)
        {
            for (int j{};j<polja[i].size();j++)
                if (polja[i][j] == Polje::Prazno)
                    broj_praznih++;
        }
        
    if (broj_praznih == 0)
        return Status::KrajPobjeda;
        
    
    return Status::NijeKraj;
}


void PrijaviGresku (KodoviGresaka greska)
{
    if (greska == KodoviGresaka::PogresnaKomanda)
        std::cout<<"Nerazumljiva komanda!"<<std::endl;
        
    if (greska == KodoviGresaka::NedostajeParametar)
        std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
        
    if (greska == KodoviGresaka::NeispravanParametar)
        std::cout<<"Parametar komande nije ispravan!"<<std::endl;
        
    if (greska == KodoviGresaka::SuvisanParametar)
        std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
        
}


bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
    std::string s;
    std::getline(std::cin,s);
    
    for (int i{};i<s.length();i++)
        {
            if (s[i] == 'P')
                {
                    if (i+1<s.length())
                        {
                            if (s[i+1] == '1')
                                {
                                    std::string s_smjer;
                                    bool rijec = false;
                                    int broj_rijeci = 0;
                                    for (int j{i+2};j<s.length();j++)
                                        {
                                            if (s[j] != ' ')
                                                {
                                                    s_smjer.push_back(s[j]);
                                                    rijec = true;
                                                }
                                                
                                            if (s[j] == ' ' && rijec == true)
                                                {
                                                    rijec = false;
                                                    broj_rijeci++;
                                                }
                                        }
                                    
                                    if (rijec == true)
                                        broj_rijeci++;
                                        
                                    if (s_smjer.size() == 0)
                                        {
                                            greska = KodoviGresaka::NedostajeParametar;
                                            return false;
                                        }
                                        
                                    if (s_smjer == "GL")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::GoreLijevo;
                                            return true;
                                        }
                                        
                                    else if (s_smjer == "G")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::Gore;
                                            return true;
                                        }
                                    
                                    else if (s_smjer == "GD")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::GoreDesno;
                                            return true;
                                        }
                                        
                                    else if (s_smjer == "D")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::Desno;
                                            return true;
                                        }
                                        
                                    else if (s_smjer == "DoD")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::DoljeDesno;
                                            return true;
                                        }
                                        
                                    else if (s_smjer == "Do")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::Dolje;
                                            return true;
                                        }
                                    
                                    else if (s_smjer == "DoL")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::DoljeLijevo;
                                            return true;
                                        }
                                        
                                    else if (s_smjer == "L")
                                        {
                                            komanda = Komande::PomjeriJednoMjesto;
                                            smjer = Smjerovi::Lijevo;
                                            return true;
                                        }
                                    else if (broj_rijeci>1)
                                        {
                                            greska = KodoviGresaka::SuvisanParametar;
                                            return false;
                                        }
                                    else
                                        {
                                            greska = KodoviGresaka::NeispravanParametar;
                                            return false;
                                        }
                                }
                            else if (s[i+1] == '>')
                                {
                                    int kopija_x = 0;
                                    int kopija_y = 0;
                                    std::string s_koordinata_x;
                                    std::string s_koordinata_y;
                                    
                                    bool rijec = false;
                                    int broj_rijeci = 0;
                                    for (int j{i+2};j<s.length();j++)
                                        {
                                            if (s[j] == ' ' && rijec == true)
                                                {
                                                    rijec = false;
                                                    broj_rijeci++;
                                                }
                                                
                                            if (broj_rijeci == 0 && s[j] != ' ')
                                                {
                                                    if (s[j]>='0' && s[j]<='9')
                                                    {
                                                        rijec = true;
                                                        s_koordinata_x.push_back(s[j]);
                                                    }
                                                    else
                                                    {
                                                        greska = KodoviGresaka::NeispravanParametar;
                                                        return false;
                                                        
                                                    }
                                                }
                                            
                                            if (broj_rijeci == 1 && s[j] != ' ')
                                                {
                                                    if (s[j]>='0' && s[j]<='9')
                                                    {
                                                        rijec = true;
                                                        s_koordinata_y.push_back(s[j]);
                                                    }
                                                    else
                                                    {
                                                        greska = KodoviGresaka::NeispravanParametar;
                                                        return false;
                                                        
                                                    }
                                                }
                                        }
                                    
                                    if (rijec == true)
                                        broj_rijeci++;
                                        
                                    if (s_koordinata_x.size() == 0 || s_koordinata_y.size() == 0)
                                        {
                                            greska = KodoviGresaka::NedostajeParametar;
                                            return false;
                                        }
                                        
                                    if (broj_rijeci > 2)
                                        {
                                            greska = KodoviGresaka::SuvisanParametar;
                                            return false;
                                        }
                                        
                                    for (int j{};j<s_koordinata_x.size();j++)
                                        {
                                            if (s_koordinata_x[j]>='0' && s_koordinata_x[j]<='9')
                                                kopija_x = kopija_x*10+s_koordinata_x[j]-48;
                                            else
                                                {
                                                    greska = KodoviGresaka::NeispravanParametar;
                                                    return false;
                                                }
                                        }
                                    
                                    for (int j{};j<s_koordinata_y.size();j++)
                                        {
                                            if (s_koordinata_y[j]>='0' && s_koordinata_y[j]<='9')
                                                kopija_y = kopija_y*10+s_koordinata_y[j]-48;
                                            else
                                                {
                                                    greska = KodoviGresaka::NeispravanParametar;
                                                    return false;
                                                }
                                        }
                                        
                                    komanda = Komande::PomjeriDalje;
                                    x = kopija_x;
                                    y = kopija_y;
                                    return true;
                                }
                            else if (s[i+1] == 'O')
                                {
                                    std::string provjera;
                                    for (int j{i+2};j<s.length();j++)
                                        {
                                            if (s[j] != ' ')
                                                provjera.push_back(s[j]);
                                        }
                                        
                                    if (provjera.size() != 0)
                                        {
                                            greska = KodoviGresaka::SuvisanParametar;
                                            return false;
                                        }
                                        
                                    komanda = Komande::PrikaziOkolinu;
                                    return true;
                                }
                        }
                    else
                        {
                            greska = KodoviGresaka::PogresnaKomanda;
                            return false;
                        }
                }
            else if (s[i] == 'B')
                {
                    int kopija_x = 0;
                    int kopija_y = 0;
                    std::string s_koordinata_x;
                    std::string s_koordinata_y;
                                    
                    bool rijec = false;
                    int broj_rijeci = 0;
                    for (int j{i+1};j<s.length();j++)
                            {
                                if (s[j] == ' ' && rijec == true)
                                    {
                                        rijec = false;
                                        broj_rijeci++;
                                    }
                                                
                                if (broj_rijeci == 0 && s[j] != ' ')
                                    {
                                        rijec = true;
                                        s_koordinata_x.push_back(s[j]);
                                    }
                                            
                                    if (broj_rijeci == 1 && s[j] != ' ')
                                        {
                                        rijec = true;
                                        s_koordinata_y.push_back(s[j]);
                                        }
                            }
                                    
                        if (rijec == true)
                            broj_rijeci++;
                                        
                        if (s_koordinata_x.size() == 0 || s_koordinata_y.size() == 0)
                            {
                                greska = KodoviGresaka::NedostajeParametar;
                                return false;
                            }
                                        
                        if (broj_rijeci > 2)
                            {
                                greska = KodoviGresaka::SuvisanParametar;
                                return false;
                            }
                                        
                            for (int j{};j<s_koordinata_x.size();j++)
                                {
                                    if (s_koordinata_x[j]>='0' && s_koordinata_x[j]<='9')
                                        kopija_x = kopija_x*10+s_koordinata_x[j]-48;
                                    else
                                        {
                                            greska = KodoviGresaka::NeispravanParametar;
                                            return false;
                                        }
                                }
                                    
                            for (int j{};j<s_koordinata_y.size();j++)
                                {
                                    if (s_koordinata_y[j]>='0' && s_koordinata_y[j]<='9')
                                        kopija_y = kopija_y*10+s_koordinata_y[j]-48;
                                    else
                                        {
                                            greska = KodoviGresaka::NeispravanParametar;
                                            return false;
                                        }
                                }
                                        
                            komanda = Komande::Blokiraj;
                            x = kopija_x;
                            y = kopija_y;
                            return true;
                }
            else if (s[i] == 'D')
                {
                    int kopija_x = 0;
                    int kopija_y = 0;
                    std::string s_koordinata_x;
                    std::string s_koordinata_y;
                                    
                    bool rijec = false;
                    int broj_rijeci = 0;
                    for (int j{i+1};j<s.length();j++)
                            {
                                if (s[j] == ' ' && rijec == true)
                                    {
                                        rijec = false;
                                        broj_rijeci++;
                                    }
                                                
                                if (broj_rijeci == 0 && s[j] != ' ')
                                    {
                                        rijec = true;
                                        s_koordinata_x.push_back(s[j]);
                                    }
                                            
                                    if (broj_rijeci == 1 && s[j] != ' ')
                                        {
                                        rijec = true;
                                        s_koordinata_y.push_back(s[j]);
                                        }
                            }
                                    
                        if (rijec == true)
                            broj_rijeci++;
                                        
                        if (s_koordinata_x.size() == 0 || s_koordinata_y.size() == 0)
                            {
                                greska = KodoviGresaka::NedostajeParametar;
                                return false;
                            }
                                        
                        if (broj_rijeci > 2)
                            {
                                greska = KodoviGresaka::SuvisanParametar;
                                return false;
                            }
                                        
                            for (int j{};j<s_koordinata_x.size();j++)
                                {
                                    if (s_koordinata_x[j]>='0' && s_koordinata_x[j]<='9')
                                        kopija_x = kopija_x*10+s_koordinata_x[j]-48;
                                    else
                                        {
                                            greska = KodoviGresaka::NeispravanParametar;
                                            return false;
                                        }
                                }
                                    
                            for (int j{};j<s_koordinata_y.size();j++)
                                {
                                    if (s_koordinata_y[j]>='0' && s_koordinata_y[j]<='9')
                                        kopija_y = kopija_y*10+s_koordinata_y[j]-48;
                                    else
                                        {
                                            greska = KodoviGresaka::NeispravanParametar;
                                            return false;
                                        }
                                }
                                        
                            komanda = Komande::Deblokiraj;
                            x = kopija_x;
                            y = kopija_y;
                            return true;
                }
            else if (s[i] == 'Z')
                {
                    std::string provjera;
                    for (int j{i+1};j<s.length();j++)
                            {
                                if (s[j] != ' ')
                                    provjera.push_back(s[j]);
                            }
                                        
                        if (provjera.size() != 0)
                            {
                                greska = KodoviGresaka::SuvisanParametar;
                                return false;
                            }
                                        
                            komanda = Komande::ZavrsiIgru;
                            return true;
                }
            else if (s[i] == 'K')
                {
                    std::string provjera;
                    for (int j{i+1};j<s.length();j++)
                            {
                                if (s[j] != ' ')
                                    provjera.push_back(s[j]);
                            }
                                        
                        if (provjera.size() != 0)
                            {
                                greska = KodoviGresaka::SuvisanParametar;
                                return false;
                            }
                                        
                            komanda = Komande::KreirajIgru;
                            return true;
                }
            else
                {
                    greska = KodoviGresaka::PogresnaKomanda;
                    return false;
                }
        }
        
    return false;
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
    if (komanda == Komande::PomjeriJednoMjesto)
        {
            try
            {
            Status test = Idi(polja,x,y,p_smjer);
            std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
            
            if (test == Status::KrajPobjeda)
                {
                    for (int i{};i<polja.size();i++)
                        {
                            for (int j{};j<polja[i].size();j++)
                                polja[i][j] = Polje::Prazno;
                        }
                        
                    std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
                    throw std::runtime_error ("Igra zavrsena");
                }
                
            if (test == Status::KrajPoraz)
                {
                    for (int i{};i<polja.size();i++)
                        {
                            for (int j{};j<polja[i].size();j++)
                                polja[i][j] = Polje::Prazno;
                        }
                        
                    std::cout<<"Nagazili ste na minu"<<std::endl;
                    throw std::runtime_error ("Igra zavrsena");
                    
                }
            }
            catch(std::out_of_range e)
            {
                std::cout<<e.what()<<std::endl;
            }
            catch(std::logic_error e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
        
    if (komanda == Komande::PomjeriDalje)
        {
            try
            {
            Status test = Idi(polja,x,y,p_x,p_y);
            std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
            
            if (test == Status::KrajPobjeda)
                {
                    for (int i{};i<polja.size();i++)
                        {
                            for (int j{};j<polja[i].size();j++)
                                polja[i][j] = Polje::Prazno;
                        }
                        
                    std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
                    throw std::runtime_error ("Igra zavrsena");
                }
                
            if (test == Status::KrajPoraz)
                {
                    for (int i{};i<polja.size();i++)
                        {
                            for (int j{};j<polja[i].size();j++)
                                polja[i][j] = Polje::Prazno;
                        }
                        
                    std::cout<<"Nagazili ste na minu"<<std::endl;
                    throw std::runtime_error ("Igra zavrsena");
                    
                }
            }
            catch(std::out_of_range e)
            {
                std::cout<<e.what()<<std::endl;
            }
            catch(std::logic_error e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
        
    if (komanda == Komande::Blokiraj)
        {
            try
            {
            BlokirajPolje(polja,p_x,p_y);
            }
            catch(std::domain_error e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
        
    if (komanda == Komande::Deblokiraj)
       {
           try
           {
                DeblokirajPolje(polja,p_x,p_y);
           }
           catch(std::domain_error e)
           {
               std::cout<<e.what()<<std::endl;
           }
       }
    
    if (komanda == Komande::PrikaziOkolinu)
        {
            try
            {
            std::vector<std::vector<int>> v = PrikaziOkolinu(polja,x,y);
            for (int i{};i<v.size();i++)
                {
                    for (int j{};j<v[i].size();j++)
                        std::cout<<v[i][j]<<" ";
                    std::cout<<std::endl;
                }
            }
            catch (std::domain_error e)
            {
                std::cout<<e.what()<<std::endl;
            }
        }
        
    if (komanda == Komande::ZavrsiIgru)
        {
            for (int i{};i<polja.size();i++)
                    {
                        for (int j{};j<polja[i].size();j++)
                            polja[i][j] = Polje::Prazno;
                    }
            
            throw std::runtime_error ("Igra zavrsena");
            
        }
        
    if (komanda == Komande::KreirajIgru)
        {
            std::cout<<"Unesite broj polja: ";
            int n;
            std::cin>>n;
            std::cin.ignore(100000, '\n');
            
            std::cout<<"Unesite pozicije mina: ";
            std::vector<std::vector<int>> mine;
            
            while(true)
            {
               std::string upis;
               std::getline(std::cin,upis);
               bool prolaz = true;
               int prvi = 0;
               int drugi = 0;
               int i = 0;
               if (upis[i] == '.')
                    break;
                
                if (upis[i] != '(')
                    prolaz = false;
                
                if (prolaz == true)
                    {
                        i++;
                        for (i;i<upis.length();i++)
                            {
                                if (upis[i] == ',')
                                    break;
                                    
                                else if (upis[i]>='0' && upis[i]<='9')
                                    prvi = prvi*10+upis[i]-48;
                                
                                else
                                    {
                                        prolaz = false;
                                        break;
                                    }
                            }
                            
                        if (prvi >= n)
                            prolaz = false;
                            
                    }
                    
                if (prolaz == true)
                    {
                        i++;
                        for (i;i<upis.length();i++)
                            {
                                if (upis[i] == ')')
                                    break;
                                    
                                else if (upis[i]>='0' && upis[i]<='9')
                                    drugi = drugi*10+upis[i]-48;
                                
                                else
                                    {
                                        prolaz = false;
                                        break;
                                    }
                            }
                            
                        if (drugi >= n)
                            prolaz = false;
                    }
                
                if (prolaz == false)
                    std::cout<<"Greska, unesite ponovo!"<<std::endl;
                else
                    {
                        std::vector<int> pomocni;
                        pomocni.push_back(prvi);
                        pomocni.push_back(drugi);
                        
                        mine.push_back(pomocni);
                    }
            }
            
        try
        {
            polja = KreirajIgru(n,mine);
        }
        catch (std::domain_error e)
        {
            std::cout<<e.what();
        }
        }
}










int main ()
{
    Tabla polja;
    int x = 0;
    int y = 0;
    Komande komanda;
    Smjerovi smjer;
    KodoviGresaka greska;
    
    try
    {
        while (true)
            {
                std::cout<<"Unesite komandu: ";
                int p_x;
                int p_y;
                bool test = UnosKomande(komanda,smjer,p_x,p_y,greska);
                
                if (test == true)
                    IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
                else
                    PrijaviGresku(greska);
                
            }
    }
    catch (std::runtime_error e)
    {
        std::cout<<"Dovidjenja!";
    }
    
	return 0;
}