#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;
using std::deque;

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename tip>
auto IzdvojiDijagonale3D(tip kont, SmjerKretanja s) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    for(int i=0;i<kont.size();i++)
    {
        if(kont.at(i).size()!=kont.at(0).size()) throw std::domain_error("Plohe nemaju isti broj redova");
        for(int j=0;j<kont.at(0).size();j++)
        {
            if(kont.at(i).at(j).size()!=kont.at(0).at(0).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    if(!kont.size() || !kont.at(0).size() || !kont.at(0).at(0).size())
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2;
        return d2;
    }
    if(s==SmjerKretanja::NaprijedNazad)
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2(kont.size());
        int dub;
        if(kont.at(0).size()<kont.at(0).at(0).size()) dub=kont.at(0).size(); else dub=kont.at(0).at(0).size();
        for(int i=0;i<kont.size();i++)
        {
            for(int j=0;j<dub;j++)
            {
                d2.at(i).push_back(kont.at(i).at(j).at(j));
            }
        }
        return d2;
    }
    if(s==SmjerKretanja::NazadNaprijed)
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2(kont.size());
        int dub;
        if(kont.at(0).size()<kont.at(0).at(0).size()) dub=kont.at(0).size(); else dub=kont.at(0).at(0).size();
        for(int i=kont.size()-1;i>=0;i--)
        {
            for(int j=0;j<dub;j++)
            {
                d2.at(kont.size()-1-i).push_back(kont.at(i).at(j).at(kont.at(0).at(0).size()-1-j));
            }
        }
        return d2;
    }
    if(s==SmjerKretanja::GoreDolje)
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2(kont.at(0).size());
        int dub;
        if(kont.size()<kont.at(0).at(0).size()) dub=kont.size(); else dub=kont.at(0).at(0).size();
        for(int i=0;i<kont.at(0).size();i++)
        {
            for(int j=0;j<dub;j++)
            {
                d2.at(i).push_back(kont.at(kont.size()-1-j).at(i).at(j));
            }
        }
        return d2;
    }
    if(s==SmjerKretanja::DoljeGore)
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2(kont.at(0).size());
        int dub;
        if(kont.size()<kont.at(0).at(0).size()) dub=kont.size(); else dub=kont.at(0).at(0).size();
        for(int i=kont.at(0).size()-1;i>=0;i--)
        {
            for(int j=0;j<dub;j++)
            {
                d2.at(kont.at(0).size()-1-i).push_back(kont.at(kont.size()-1-j).at(i).at(kont.at(0).at(0).size()-1-j));
            }
        }
        return d2;
    }
    if(s==SmjerKretanja::LijevoDesno)
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2(kont.at(0).at(0).size());
        int dub;
        if(kont.at(0).size()<kont.size()) dub=kont.at(0).size(); else dub=kont.size();
        for(int i=0;i<kont.at(0).at(0).size();i++)
        {
            for(int j=0;j<dub;j++)
            {
                d2.at(i).push_back(kont.at(kont.size()-1-j).at(j).at(i));
            }
        }
        return d2;
    }
    if(s==SmjerKretanja::DesnoLijevo)
    {
        typename std::remove_reference<decltype(kont.at(0))>::type d2(kont.at(0).at(0).size());
        int dub;
        if(kont.at(0).size()<kont.size()) dub=kont.at(0).size(); else dub=kont.size();
        for(int i=kont.at(0).at(0).size()-1;i>=0;i--)
        {
            for(int j=0;j<dub;j++)
            {
                d2.at(kont.at(0).at(0).size()-1-i).push_back(kont.at(j).at(j).at(i));
            }
        }
        return d2;
    }
    typename std::remove_reference<decltype(kont.at(0))>::type d2;
    return d2;
}

int main ()
{
    int x, y, z, si;
    SmjerKretanja s[6]={SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    cout << "Unesite dimenzije (x y z): ";
    cin >> x >> y >> z;
    if(x<=0 || y<=0 || z<=0)
    {
        cout << "Neispravne dimenzije kontejnera!\n";
        return 0;
    }
    vector<deque<deque<int>>> v(x, deque<deque<int>>(y, deque<int>(z)));
    cout << "Unesite elemente kontejnera:\n";
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            for(int k=0;k<z;k++)
            {
                cin >> v.at(i).at(j).at(k);
            }
        }
    }
    cout << "Unesite smjer kretanja [0 - 5]: ";
    cin >> si;
    if(si<0 || si>5)
    {
        cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    try
    {
        deque<deque<int>> vd=IzdvojiDijagonale3D(v, s[si]);
        if(s[si]==SmjerKretanja::NaprijedNazad) cout << "NaprijedNazad:\n";
        if(s[si]==SmjerKretanja::NazadNaprijed) cout << "NazadNaprijed:\n";
        if(s[si]==SmjerKretanja::GoreDolje) cout << "GoreDolje:\n";
        if(s[si]==SmjerKretanja::DoljeGore) cout << "DoljeGore:\n";
        if(s[si]==SmjerKretanja::LijevoDesno) cout << "LijevoDesno:\n";
        if(s[si]==SmjerKretanja::DesnoLijevo) cout << "DesnoLijevo:\n";
        for(int i=0;i<vd.size();i++)
        {
            for(int j=0;j<vd.at(0).size();j++)
            {
                cout.width(4);
                cout << vd.at(i).at(j);
            }
            cout << "\n";
        }
    }
    catch(std::domain_error ero)
    {
        cout << ero.what();
    }
    return 0;
}