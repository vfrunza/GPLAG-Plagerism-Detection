/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine)
{
    if (n<=0)
        throw std::domain_error ("Ilegalna velicina");
        
    Tabla tabla (n, std::vector<Polje> (n));
        
    for (int i{};i<n;i++)
    {
        for (int j{};j<n;j++)
            tabla[i][j] = Polje::Prazno;
    }
    
    for (int i{};i<mine.size();i++)
    {
        if (mine[i].size() != 2)
            throw std::domain_error ("Ilegalan format zadavanja mina");
    }
    
    for (int i{};i<mine.size();i++)
    {
        if (mine[i][0] < 0 || mine[i][0] >= n)
            throw std::domain_error ("Ilegalne pozicije mina");
            
        if (mine[i][1] < 0 || mine[i][1] >= n)
            throw std::domain_error ("Ilegalne pozicije mina");
    }
    
    for (int i{};i<mine.size();i++)
        tabla[mine[i][0]][mine[i][1]] = Polje::Mina;
    
    return tabla;
}

int Test_okoline (const Tabla &polja, int x, int y)
{
    int brojac = 0;
    
    int a = x, b = y;
    a--;
    b--;
    
    if (a >= 0 && a < polja.size())
    {
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
        
        b++;
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
        
        b++;
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
    }
    
    a++;
    b = y - 1;
    if (a >= 0 && a < polja.size())
    {
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
        
        b += 2;
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
    }
    
    a++;
    b = y - 1;
    if (a >= 0 && a < polja.size())
    {
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
        
        b++;
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
        
        b++;
        if (b >=0 && b<polja.size())
        {
            if (polja[a][b] == Polje::Mina)
                brojac++;
        }
    }
    
    
    return brojac;
}

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

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{
    
    if (x < 0 || x >= polja.size())
        {
            auto s1 = Napravi_string_iz_broja(x);
            auto s2 = Napravi_string_iz_broja(y);
            std::string greska = "Polje (" + s1 + "," + s2 + ") ne postoji";
            throw std::domain_error (greska);
        }
        
    if (y < 0 || y >= polja.size())
        {
            auto s1 = Napravi_string_iz_broja(x);
            auto s2 = Napravi_string_iz_broja(y);
            std::string greska = "Polje (" + s1 + "," + s2 + ") ne postoji";
            throw std::domain_error (greska);
        }
        
    std::vector<std::vector<int>> rezultat (3);
    rezultat[0].push_back(Test_okoline(polja,x-1,y-1));
    rezultat[0].push_back(Test_okoline(polja,x-1,y));
    rezultat[0].push_back(Test_okoline(polja,x-1,y+1));
    rezultat[1].push_back(Test_okoline(polja,x,y-1));
    rezultat[1].push_back(Test_okoline(polja,x,y));
    rezultat[1].push_back(Test_okoline(polja,x,y+1));
    rezultat[2].push_back(Test_okoline(polja,x+1,y-1));
    rezultat[2].push_back(Test_okoline(polja,x+1,y));
    rezultat[2].push_back(Test_okoline(polja,x+1,y+1));
    
    return rezultat;
}

void BlokirajPolje (Tabla &polja, int x, int y)
{
    if (x < 0 || x >= polja.size())
        {
            auto s1 = Napravi_string_iz_broja(x);
            auto s2 = Napravi_string_iz_broja(y);
            std::string greska = "Polje (" + s1 + "," + s2 + ") ne postoji";
            throw std::domain_error (greska);
        }
        
    if (y < 0 || y >= polja.size())
        {
            auto s1 = Napravi_string_iz_broja(x);
            auto s2 = Napravi_string_iz_broja(y);
            std::string greska = "Polje (" + s1 + "," + s2 + ") ne postoji";
            throw std::domain_error (greska);
        }
        
    if (polja[x][y] == Polje::Prazno)
        polja[x][y] = Polje::BlokiranoPrazno;
        
    if (polja[x][y] == Polje::Mina)
        polja[x][y] = Polje::BlokiranoMina;
        
    if (polja[x][y] == Polje::Posjeceno)
        polja[x][y] = Polje::BlokiranoPosjeceno;
    
    
}

void DeblokirajPolje (Tabla &polja, int x, int y)
{
     if (x < 0 || x >= polja.size())
        {
            auto s1 = Napravi_string_iz_broja(x);
            auto s2 = Napravi_string_iz_broja(y);
            std::string greska = "Polje (" + s1 + "," + s2 + ") ne postoji";
            throw std::domain_error (greska);
        }
        
    if (y < 0 || y >= polja.size())
        {
            auto s1 = Napravi_string_iz_broja(x);
            auto s2 = Napravi_string_iz_broja(y);
            std::string greska = "Polje (" + s1 + "," + s2 + ") ne postoji";
            throw std::domain_error (greska);
        }
        
    if (polja[x][y] == Polje::BlokiranoPrazno)
        polja[x][y] = Polje::Prazno;
        
    if (polja[x][y] == Polje::BlokiranoMina)
        polja[x][y] = Polje::Mina;
        
    if (polja[x][y] == Polje::BlokiranoPosjeceno)
        polja[x][y] = Polje::Posjeceno;
}

Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    if (novi_x < 0 || novi_x >= polja.size())
        throw std::out_of_range ("Izlazak van igrace table");
        
    if (novi_y < 0 || novi_y >= polja.size())
        throw std::out_of_range ("Izlazak van igrace table");
        
    if (polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
        throw std::logic_error ("Blokirano polje");
        
    if (polja[x][y] == Polje::Prazno)
        polja[x][y] = Polje::Posjeceno;
        
    x = novi_x;
    y = novi_y;
    
    if (polja[x][y] == Polje::Mina)
    {
        for (int i{};i<polja.size();i++)
        {
            for (int j{};j<polja.size();j++)
                polja[i][j] = Polje::Prazno;
        }
        
        return Status::KrajPoraz;
    }
        
    int brojac = 0;
    
    
    for (int i{};i<polja.size();i++)
    {
        for (int j{};j<polja.size();j++)
        {
            if (polja[x][y] == Polje::Prazno)
                brojac++;
        }
    }
    
    if (brojac == 0)
        return Status::KrajPobjeda;
    
    return Status::NijeKraj;
}

Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    if (smjer == Smjerovi::GoreLijevo)
        return Idi (polja, x, y, x-1, y-1);
    else if (smjer == Smjerovi::Gore)
        return Idi (polja, x, y, x-1, y);
    else if (smjer == Smjerovi::GoreDesno)
        return Idi (polja, x, y, x-1, y+1);
    else if (smjer == Smjerovi::Desno)
        return Idi (polja, x, y, x, y+1);
    else if (smjer == Smjerovi::DoljeDesno)
        return Idi (polja, x, y, x+1, y+1);
    else if (smjer == Smjerovi::Dolje)
        return Idi (polja, x, y, x+1, y);
    else if (smjer == Smjerovi::DoljeLijevo)
        return Idi (polja, x, y, x+1, y-1);
    else
        return Idi (polja, x, y, x, y-1);
}

void PrijaviGresku (KodoviGresaka kod)
{
    if (kod == KodoviGresaka::PogresnaKomanda)
        std::cout<<"Nerazumljiva komanda!";
    else if (kod == KodoviGresaka::NedostajeParametar)
        std::cout<<"Komanda trazi parametar koji nije naveden!";
    else if (kod == KodoviGresaka::NeispravanParametar)
        std::cout<<"Parametar komande nije ispravan!";
    else
        std::cout<<"Zadan je suvisan parametar nakon komande!";
        
    std::cout<<std::endl;
}

bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
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

void Isprazni_tablu (Tabla &polja)
{
    for (int i{};i<polja.size();i++)
    {
        for (int j{};j<polja.size();j++)
            polja[i][j] = Polje::Prazno;
    }
}

template <typename TipBroja>
void UnosBroja(std::string prompt, std::string greska, TipBroja &broj) {
    std::cout<<prompt;
    while (!(std::cin>>broj) || std::cin.peek()!='\n') 
    {
        std::cout<<greska<<std::endl;
        std::cin.clear();
        std::cin.ignore (10000, '\n');
        std::cout<<prompt;
    }
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
    try
    {
        if (komanda == Komande::PomjeriJednoMjesto)
        {
            Status rezultat = Idi(polja,x,y,p_smjer);
            if (rezultat == Status::NijeKraj)
                std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
            
            if (rezultat == Status::KrajPobjeda)
            {
                std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
                Isprazni_tablu(polja);
                throw std::runtime_error ("Igra zavrsena");
            }
            
            if (rezultat == Status::KrajPoraz)
            {
                std::cout<<"Nagazili ste na minu"<<std::endl;
                Isprazni_tablu(polja);
                throw std::runtime_error ("Igra zavrsena");
            }
        }
        
        if (komanda == Komande::PomjeriDalje)
        {
            Status rezultat = Idi(polja,x,y,p_x,p_y);
            if (rezultat == Status::NijeKraj)
                std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
            
            if (rezultat == Status::KrajPobjeda)
            {
                std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
                Isprazni_tablu(polja);
                throw std::runtime_error ("Igra zavrsena");
            }
            
            if (rezultat == Status::KrajPoraz)
            {
                std::cout<<"Nagazili ste na minu"<<std::endl;
                Isprazni_tablu(polja);
                throw std::runtime_error ("Igra zavrsena");
            }
        }
        
        if (komanda == Komande::Blokiraj)
            BlokirajPolje(polja,p_x,p_y);
            
        if (komanda == Komande::Deblokiraj)
            DeblokirajPolje(polja,p_x,p_y);
            
        if (komanda == Komande::PrikaziOkolinu)
        {
            auto ispis = PrikaziOkolinu(polja,x,y);
            for (int i{};i<ispis.size();i++)
            {
                for (int j{};j<ispis[i].size();j++)
                    std::cout<<ispis[i][j]<<" ";
                std::cout<<std::endl;
            }
        }
        
        if (komanda == Komande::ZavrsiIgru)
        {
            Isprazni_tablu(polja);
            throw std::runtime_error ("Igra zavrsena");
        }
        
        if (komanda == Komande::KreirajIgru)
        {
            int n = 0;
            while (n == 0)
            {
                UnosBroja("Unesite broj polja: ", "Greska, unesite ponovo!", n);
                
                if (n == 0)
                    std::cout<<"Greska, unesite ponovo!"<<std::endl;
            }
                
            std::cin.ignore(10000, '\n');
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
                    
                while (upis[i] == ' ')
                    i++;
                
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
                                    
                                else if (upis [i] == ' ')
                                {
                                    
                                }
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
                                
                                else if (upis [i] == ' ')
                                {
                                    
                                }
                                
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
            
            polja = KreirajIgru(n,mine);
        }
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (std::logic_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (std::runtime_error e)
    {
        throw std::runtime_error ("Igra zavrsena");
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