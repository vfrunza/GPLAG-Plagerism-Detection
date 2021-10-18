#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename Tip>
auto IzdvojiDijagonale3D(Tip Kontejner, SmjerKretanja Pravac)->typename std::remove_reference<decltype(*Kontejner.begin())>::type
{
    bool plohe=true, matrica=true;
    for (int i=0; i<Kontejner.size(); i++)
    {
        if(i!=0)
        {
            if(Kontejner[i].size!=Kontejner[i-1].size)
            plohe=false;
        }
        for (int j=1; j<Kontejner.size(); j++)
        {
            if(Kontejner[i][j].size()!=Kontejner[i][j-1].size())
            matrica=false;
        }
    }
    if(!matrica) throw std::domain_error ("Redovi nemaju isti broj elemenata");
    if(!plohe) throw std::domain_error ("Plohe nemaju isti broj redova");
}

int main ()
{
    int x, y, z, n;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>x>>y>>z;
    if(x<0||y<0||z<0)
    {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            for (int k=0; k<z; k++)
            {
                int d;
                std::cin>>d;
            }
        }
    }
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin>>n;
    if(n<0||n>5)
    {
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
    }
	return 0;
}