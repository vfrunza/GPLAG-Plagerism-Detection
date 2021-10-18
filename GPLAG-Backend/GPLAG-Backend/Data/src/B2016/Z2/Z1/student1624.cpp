#include <iostream>
#include <vector>

using namespace::std;

typedef vector<vector<Polje>> Tabla;
enum class Polje
{
	Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};

Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
    for(auto x: mine)
    {
        if(x.size() != 2)
            throw domain_error("Ilegalan format zadavanja mina");
        if(x[0] > m && x[1] > m)
            throw domain_error("Ilegalne pozicije mina");
    }
    Tabla a(m);
	for(int i = 0; i < m;i++)
	{
	    a.push_back(vector<Polje>(m));
	    for(int j = 0;j < m;j++)
	    {
	        a[i][j] = Polje::Prazno;
	        for(auto x:mine)
	        {
	            if(i == x[0] && j == x[1])
	                a[i][j] = Polje::Mina;
	        }
	    }
	}
	return a;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    if(x < 0 || y < 0 || x >= m || y >=m)
    {
        string a;
        a = "Polje (" + x + "," + y + ") ne postoji";
        throw domain_error(a);
    }
    vector<vector<int>> okolina;
    vector<vector<int>> poz{{x-1,y-1},{x-1,y},{x-1,y+1},{x,y-1},{x,y},{x,y+1},{x+1,y-1},{x+1,y},{x+1,y+1}};
    
}
void BlokirajPolje(Tabla &Polja, int x, int y)
{
    
}
void DeblokirajPolje(Tabla &polja, int xm int y)
