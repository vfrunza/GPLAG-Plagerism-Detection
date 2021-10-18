#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

void SmjerKretanjaIspis (SmjerKretanja sk)
{
    if (sk>SmjerKretanja(-1) && sk<SmjerKretanja(6))
    {
        if (sk==SmjerKretanja::NaprijedNazad) std::cout << "NaprijedNazad:"<<std::endl;
        else if (sk==SmjerKretanja::NazadNaprijed) std::cout << "NazadNaprijed:"<<std::endl;
        else if (sk==SmjerKretanja::GoreDolje) std::cout << "GoreDolje:"<<std::endl;
        else if (sk==SmjerKretanja::DoljeGore) std::cout << "DoljeGore:"<<std::endl;
        else if (sk==SmjerKretanja::LijevoDesno) std::cout << "LijevoDesno:"<<std::endl;
        else std::cout << "DesnoLijevo:"<<std::endl;
    }
    else std::cout << "Smjer kretanja nije ispravan!"<<std::endl;
}

template <typename tip>
void DaLiJeKontPravilan (tip d3)
{
    int velicina;
    {
        auto zavelicinureda (d3.at(0).at(0));
        velicina=zavelicinureda.size();
    }
    int brojredova;
    {
        auto zabrojredova (d3.at(0));
        brojredova=zabrojredova.size();
    }
    std::cout << "Velicina: "<<velicina<<std::endl;
    std::cout << "Broj redova: "<<brojredova<<std::endl;
}

template <typename tip>
auto IzdvojiDijagonale3D (tip d3, SmjerKretanja sk) ->typename std::remove_reference<decltype(d3.at(0))>::type
{
    typename std::remove_reference<decltype(d3.at(0))>::type d;
    
    DaLiJeKontPravilan(d3);
    
    int z(d3.size()-1);
    
    auto zadimenziju (d3.at(0));
    int y(zadimenziju.size()-1);
    
    auto zadimenziju1 (d3.at(0).at(0));
    int x(zadimenziju1.size()-1);
    
    if (sk==SmjerKretanja::DoljeGore)
    {
       for (int i=y; i>=0; i--)
       {
           int z1(z),x1(x);
           decltype (zadimenziju1) svi;
           while (z1>=0 && x1>=0)
           {
               svi.push_back(d3.at(z1).at(i).at(x1));
               z1--; x1--;
           }
           d.push_back(svi);
       }
    }
    else if (sk==SmjerKretanja::GoreDolje)
    {
        for (int i=0; i<=y; i++)
       {
           int z1(z),x1(0);
           decltype (zadimenziju1) svi;
           while (z1>=0 && x1<=x)
           {
               svi.push_back(d3.at(z1).at(i).at(x1));
               z1--; x1++;
           }
           d.push_back(svi);
       }
    }
    else if (sk==SmjerKretanja::LijevoDesno)
    {
        for (int i=0;i<=x;i++)
        {
            int z1(z), y1(0);
            decltype (zadimenziju1) svi;
            while (z1>=0 && y1<=y)
            {
                svi.push_back(d3.at(z1).at(y1).at(i));
                z1--;y1++;
            }
            d.push_back(svi);
        }
    }
    else if (sk==SmjerKretanja::DesnoLijevo)
    {
        for (int i=x;i>=0;i--)
        {
            int z1(0),y1(0);
            decltype (zadimenziju1) svi;
            while (z1<=z && y1<=y)
            {
                svi.push_back(d3.at(z1).at(y1).at(i));
                z1++;y1++;
            }
            d.push_back(svi);
        }
    }
    else if (sk==SmjerKretanja::NaprijedNazad)
    {
        for (int i=0; i<=z; i++)
        {
            int y1(0),x1(0);
            decltype (zadimenziju1) svi;
            while (y1<=x && x1<=y)
            {
                svi.push_back(d3.at(i).at(y1).at(x1));
                y1++; x1++;
            }
            d.push_back(svi);
        }
    }
    else if (sk==SmjerKretanja::NazadNaprijed)
    {
        for (int i=z;i>=0;i--)
        {
            int x1(x),y1(0);
            decltype (zadimenziju1) svi;
            while (x1>=0 && y1<=y)
            {
                svi.push_back(d3.at(i).at(y1).at(x1));
                y1++;x1--;
            }
            d.push_back(svi);
        }
    }
    return d;
}

int main ()
{
    std::cout <<std::endl <<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>> x>>y>>z;
    
    if (x<0 || y<0 || z<0) 
    {
        std::cout << "Neispravne dimenzije kontejnera!"<<std::endl;
        return 0;
    }

    std::vector<std::deque<std::deque<int>>> d3; 
    std::deque<int> zdimenzija;
    std::deque<std::deque<int>> ydimenzija;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite elemente kontejnera: ";
    for (int k=0;k<x;k++) 
    { 
        ydimenzija.resize(0);
        for (int j=0;j<y;j++)  
        {    
            zdimenzija.resize(0);
            for (int i=0; i<z; i++)
            {
                int zt;
                std::cin>>zt;
                zdimenzija.push_back(zt);
            }
            ydimenzija.push_back(zdimenzija);
        }
        d3.push_back(ydimenzija);
    }
    std::cout <<std::endl <<"Unesite smjer kretanja [0 - 5]: ";
    SmjerKretanja sk;
    int ski;
    std::cin>> ski;
    sk=SmjerKretanja(ski);
    std::deque<std::deque<int>> d(IzdvojiDijagonale3D(d3,sk));
    SmjerKretanjaIspis(sk);
    for (int i=0; i<d.size();i++)
    {
        for (int j=0;j<d[0].size();j++)
        {
            std::cout.width(4);
            std::cout << d[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}