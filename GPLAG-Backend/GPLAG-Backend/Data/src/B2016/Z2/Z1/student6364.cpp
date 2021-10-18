#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
    for(int i = 0; i < mine.size(); i++)
    {
        if(mine[i].size() != 2) throw std::domain_error("Ilegalan format zadavanja mina");    
    }
    for(int i = 0; i < mine.size(); i++)
    {
        for(int j = 0; j < 2; j++)
            if(mine[i][j] >= n || mine[i][j] < 0) throw std::domain_error("Ilegalne pozicije mina");
    }
    Tabla ploca(n, std::vector<Polje> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            ploca[i][j] = Polje::Prazno;
    }
    for(int i = 0; i < mine.size(); i++)
    {
            ploca[mine[i][0]][mine[i][1]] = Polje::Mina;
    }
    return ploca;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
    if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0) throw std::domain_error("Polje ("+ std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
    if(polja[x][y] == Polje::Prazno)
        polja[x][y] = Polje::BlokiranoPrazno;
    else if(polja[x][y] == Polje::Posjeceno)
        polja[x][y] = Polje::BlokiranoPosjeceno;
    else if(polja[x][y] == Polje::Mina)
        polja[x][y] = Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja, int x, int y)
{
        if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0) throw std::domain_error("Polje ("+ std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
        if(polja[x][y] == Polje::BlokiranoPrazno)
            polja[x][y] = Polje::Prazno;
        else if(polja[x][y] == Polje::BlokiranoPosjeceno)
            polja[x][y] = Polje::Posjeceno;
        else if(polja[x][y] == Polje::BlokiranoMina)
            polja[x][y] = Polje::Mina;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    Status vrati = Status::KrajPobjeda;
    int n = polja.size();
    switch(int(smjer))
    {
        case 0: 
            if(x == 0 || y == 0) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x-1][y-1] == Polje::BlokiranoPosjeceno || polja[x-1][y-1] == Polje::BlokiranoPrazno || polja[x-1][y-1] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                x -= 1;
                y -= 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            } break;
        case 1:
            if(x == 0) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x-1][y] == Polje::BlokiranoPosjeceno || polja[x-1][y] == Polje::BlokiranoPrazno || polja[x-1][y] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                x -= 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            } break;
        case 2:
            if(x == 0 || y == polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x-1][y+1] == Polje::BlokiranoPosjeceno || polja[x-1][y+1] == Polje::BlokiranoPrazno || polja[x-1][y+1] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                x -= 1;
                y += 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            } break;
        case 3: 
            if(y == polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x][y+1] == Polje::BlokiranoPosjeceno || polja[x][y+1] == Polje::BlokiranoPrazno || polja[x][y+1] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                y += 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            }
        case 4: 
            if(x == polja.size()-1 || y == polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x+1][y+1] == Polje::BlokiranoPosjeceno || polja[x+1][y+1] == Polje::BlokiranoPrazno || polja[x+1][y+1] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
                polja[x][y] = Polje::Posjeceno;
                x += 1;
                y += 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                } break;
        case 5:
            if(x == polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x+1][y] == Polje::BlokiranoPosjeceno || polja[x+1][y] == Polje::BlokiranoPrazno || polja[x+1][y] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                x += 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            } break;
        case 6:
            if(x == polja.size()-1 || y == 0) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x+1][y-1] == Polje::BlokiranoPosjeceno || polja[x+1][y-1] == Polje::BlokiranoPrazno || polja[x+1][y-1] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                x += 1;
                y -= 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            } break;
        case 7:     
            if(y == 0) throw std::out_of_range("Izlazak van igrace table");
            else if(polja[x][y-1] == Polje::BlokiranoPosjeceno || polja[x][y-1] == Polje::BlokiranoPrazno || polja[x][y-1] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
            else {
                polja[x][y] = Polje::Posjeceno;
                y -= 1;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(polja[i][j] == Polje::Prazno)
                        {
                            vrati = Status::NijeKraj;
                            return vrati;
                        }
                    }
                }
            } break;
        }
    return vrati;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    Status vrati = Status::KrajPobjeda;
    int n = polja.size();
    if(novi_x >= n || novi_y >= n || novi_x < 0 || novi_y < 0) throw std::out_of_range("Izlazak van igrace table");
    else if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
            { 
                throw std::logic_error("Blokirano polje");
                vrati = Status::KrajPoraz;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        polja[i][j] = Polje::Prazno;
                }
            }
    else {
        polja[x][y] = Polje::Posjeceno;
        x = novi_x;
        y = novi_y;                
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(polja[i][j] == Polje::Prazno)
                {
                    vrati = Status::NijeKraj;
                    return vrati;
                }
            }
        }
    } return vrati;
}
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
void PrijaviGresku (KodoviGresaka greska)
{
    if(greska == KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
    else if(greska == KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!";
    else if(greska == KodoviGresaka::SuvisanParametar) std::cout<<"Parametar komande nije ispravan!";
    else if(greska == KodoviGresaka::NeispravanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";
}
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
/*std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0) throw std::domain_error("Polje ("+ std::to_string(x) + "," + std::to_string(y) + ") ne postoji");
    std::vector<std::vector<int>> mat (3, std::vector<int>(3));
    std::vector<int> brojaci(9, 0);
    int n = polja.size();
    for(int i = x-1; i <= x+1; i++)
    {
        for(int j = y-1; j <= y+1; j++)
        {
            if()
        }
    }
}
*/
int main ()
{	
	return 0;
}