// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;


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
    
}

int main ()
{
	return 0;
}