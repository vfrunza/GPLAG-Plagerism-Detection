#include <iostream>
#include <vector>
#include <stdexcept>
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
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
    Tabla t;
    t.resize(n);
    for(int i(0); i < n; i++)
        t[i].resize(n);
        
    for(int i(0); i < n; i++)
        for(int j(0); j < n; j++)
            t[i][j] = Polje::Prazno;
            
    for(int i(0); i < mine.size(); i++)
    {
        if(mine[i].size() != 2)
            throw std::domain_error("Ilegalan format zadavanja mina");
        if(mine[i][0] >= n || mine[i][1] >= n || mine[i][0] < 0 || mine[i][1] < 0)
            throw std::domain_error("Ilegalne pozicije mina");
        t[mine[i][0]][mine[i][1]] = Polje::Mina;
    }
    
    return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
        throw std::domain_error("Polje(x,y) ne postoji");
    int n = polja.size();
    std::vector<std::vector<int>> matrica(n, std::vector<int>(n, 0));
    for(int i(0); i < 3; i++)
    {
        for(int j(0); j < 3; j++)
        {
            int brojMina = 0;
            for(int k(0); k < 8; k++)
            {
                if(x-1 >= 0 && y-1 >= 0)
                    if(polja[x-1][y-1] == Polje::Mina)
                        brojMina++;
                if(x-1 >= 0)
                    if(polja[x-1][y] == Polje::Mina)
                        brojMina++;
                if(x-1 >= 0 && y + 1 < polja.size())
                    if(polja[x-1][y+1] == Polje::Mina)
                        brojMina++;
                if(y+1 < polja.size())
                    if(polja[x][y+1] == Polje::Mina)
                        brojMina++;
                if(x+1 < polja.size() && y+1 < polja.size())
                    if(polja[x+1][y+1] == Polje::Mina)
                        brojMina++;
                if(x+1 < polja.size())
                    if(polja[x+1][y] == Polje::Mina)
                        brojMina++;
                if(x+1 < polja.size() && y - 1 <= 0)
                    if(polja[x+1][y-1] == Polje::Mina)
                        brojMina++;
                if(y - 1 <= 0)
                    if(polja[x][y-1] == Polje::Mina)
                        brojMina++;
            }
            
            matrica[i][j] = brojMina;
        }
    }
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
    if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
        throw std::domain_error("Polje(x,y) ne postoji");
    if(polja[x][y] == Polje::Prazno)
        polja[x][y] = Polje::BlokiranoPrazno;
    else if(polja[x][y] == Polje::Posjeceno)
        polja[x][y] = Polje::BlokiranoPosjeceno;
    else if(polja[x][y] == Polje::Mina)
        polja[x][y] = Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja, int x, int y)
{
    if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size())
        throw std::domain_error("Polje(x,y) ne postoji");
    if(polja[x][y] == Polje::BlokiranoPrazno)
        polja[x][y] = Polje::Prazno;
    else if(polja[x][y] == Polje::BlokiranoPosjeceno)
        polja[x][y] = Polje::Posjeceno;
    else if(polja[x][y] == Polje::BlokiranoMina)
        polja[x][y] = Polje::Mina;
}
void OcistiTablu(Tabla &polja)
{
    int n = polja.size();
    for(int i(0); i < n; i++)
        for(int j(0); j < n; j++)
            polja[i][j] = Polje::Prazno;
}
bool ProvjeriPraznaPolja(Tabla &polja)
{
    int n = polja.size();
    for(int i(0); i < n; i++)
        for(int j(0); j < n; j++)
            if(polja[i][j] == Polje::Prazno)
                return false;
    return true;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    polja[x][y] = Polje::Posjeceno;
    if(smjer == Smjerovi::GoreLijevo)
    {
        x--; y--;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            x++; y++;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            x++; y++;
            throw std::logic_error("Blokirano polje");
        }
        
    }
    else if(smjer == Smjerovi::Gore)
    {
        x--;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            x++;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            x++;
            throw std::logic_error("Blokirano polje");
        }
    }
    else if(smjer == Smjerovi::GoreDesno)
    {
        x--; y++;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            x++; y--;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            x++; y--;
            throw std::logic_error("Blokirano polje");
        }
    }
    else if(smjer == Smjerovi::Desno)
    {
        y++;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            y--;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            y--;
            throw std::logic_error("Blokirano polje");
        }
    }
    else if(smjer == Smjerovi::DoljeDesno)
    {
        x++; y++;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            x--; y--;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            x--; y--;
            throw std::logic_error("Blokirano polje");
        }
    }
    else if(smjer == Smjerovi::Dolje)
    {
        x++;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            x--;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            x--; 
            throw std::logic_error("Blokirano polje");
        }
    }
    else if(smjer == Smjerovi::DoljeLijevo)
    {
        x++; y--;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            x--; y++;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            x--; y++;
            throw std::logic_error("Blokirano polje");
        }
    }
    else if(smjer == Smjerovi::Lijevo)
    {
        y--;
        if(x < 0 || y < 0 || x >= polja.size() || y >= polja.size())
        {
            y++;
            throw std::out_of_range("Izlazak van igrace table");
        }
        else if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
        {
            y++;
            throw std::logic_error("Blokirano polje");
        }
    }
    
    if(polja[x][y] == Polje::Mina)
    {
        OcistiTablu(polja);
        return Status::KrajPoraz;
    }
    if(ProvjeriPraznaPolja(polja))
        return Status::KrajPobjeda;
        
    return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    polja[x][y] = Polje::Posjeceno;
    if(novi_x < 0 || novi_y < 0 || novi_x >= polja.size() || novi_y >= polja.size())
        throw std::out_of_range("Izlazak van igrace table");
    else if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || 
    polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
        throw std::logic_error("Blokirano polje");
    x = novi_x;
    y = novi_y;
    if(polja[x][y] == Polje::Mina)
    {
        OcistiTablu(polja);
        return Status::KrajPoraz;
    }
    if(ProvjeriPraznaPolja(polja))
        return Status::KrajPobjeda;
    return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska)
{
    if(greska == KodoviGresaka::PogresnaKomanda)
        std::cout << "Nerazumljiva komanda!";
    else if(greska == KodoviGresaka::NedostajeParmetar)
        std::cout << "Komanda trazi parametar koji nije naveden!";
    else if(greska == KodoviGresaka::NeispravanParametar)
        std::cout << "Parametar komande nije ispravan!";
    else if(greska == KodoviGresaka::SuvisanParametar)
        std::cout << "Zadan je suvisan parametar nakon komande!";    
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
    std::cout << "Unesite komandu: "
    std::string s;
    std::getline(std::cin, s);
    std::string temp;
    int brojac = 0;
    while(1)
    {
        if(s[brojac] == ' ')
            brojac++;
        else 
            break;
    }
    for(; brojac < s.size(); brojac++)
        temp += s[brojac];
    s = temp;    
    if(s == "K")
    {
        std::cout << "Unesite broj polja: ";
        int n;
        std::cin >> n;
        
    }
}
int main ()
{
	return 0;
}