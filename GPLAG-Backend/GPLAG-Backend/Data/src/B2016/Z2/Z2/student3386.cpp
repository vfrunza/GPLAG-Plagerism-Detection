// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

using std::vector;
using std::deque;
using std::cin;
using std::cout;

enum class SmjerKretanja{NaprijedNazad=0, NazadNaprijed=1, GoreDolje=2, DoljeGore=3, LijevoDesno=4, DesnoLijevo=5};

template<typename Tip>
auto IzdvojiDijagonale3D(Tip kont,SmjerKretanja smjer)-> typename std::remove_reference<decltype(kont.at(0))>::type
{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type mali_kont;
    mali_kont mali;
    if(kont.size()==0 or kont.at(0).size()==0 or kont.at(0).at(0).size()==0)
        return mali;
    for(int i=0;i<kont.size()-1;i++)
        if(kont.at(i).size()!=kont.at(i+1).size())
            throw std::domain_error("Plohe nemaju isti broj redova");
    auto velicina=kont.at(0).at(0).size();
    for(int i=0;i<kont.size();i++)
        for(int j=0;j<kont.at(i).size();j++)
            if(kont.at(i).at(j).size()!=velicina)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
    int k=0;
    if(smjer==SmjerKretanja::NaprijedNazad)
    {
        mali.resize(kont.size());
        for(int i=0;i<kont.size();i++)
        {
            for(int j=0;j<kont.at(0).size();j++)
            {
                mali.at(i).push_back(kont.at(i).at(j).at(j));
            }
        }
    }
    else if(smjer==SmjerKretanja::NazadNaprijed)
    {
        k=0;
        mali.resize(kont.size());
        for(int i=kont.size()-1;i>=0;i--)
        {
            int a=kont.at(i).size();
            int f=kont.at(i).at(0).size()-1;
            for(int j=0;j<a;j++)
            {
                mali.at(k).push_back(kont.at(i).at(j).at(f--));
            }
            k++;
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje)
    {
        k=0;
        int a=0;
        mali.resize(kont.at(0).size());
        for(int j=0;j<kont.at(0).size();j++)
        {
            a=0;
            for(int i=kont.size()-1;i>=0;i--)
            {
                mali.at(k).push_back(kont.at(i).at(j).at(a++));
            }
            k++;
        }
    }
    else if(smjer==SmjerKretanja::DoljeGore)
    {
        k=0;
        mali.resize(kont.at(0).size());
        int a=kont.at(0).at(0).size()-1;
        for(int j=kont.at(0).size()-1;j>=0;j--)
        {
            int x=a;
            for(int i=kont.size()-1;i>=0;i--)
            {
                mali.at(k).push_back(kont.at(i).at(j).at(a--));
            }
            a=x;
            k++;
        }
    }
    else if(smjer==SmjerKretanja::LijevoDesno)
    {
        mali.resize(kont.at(0).at(0).size());
        for(int j=0;j<kont.at(0).at(0).size();j++)
        {
            int f=0;
            for(int i=kont.size()-1;i>=0;i--)
                mali.at(k).push_back(kont.at(i).at(f++).at(j));
            k++;
        }
    }
    else if(smjer==SmjerKretanja::DesnoLijevo)
    {
        mali.resize(kont.at(0).at(0).size());
        for(int j=kont.at(0).at(0).size()-1;j>=0;j--)
        {
            int f=0;
            for(int i=0;i<kont.size();i++)
                mali.at(k).push_back(kont.at(i).at(f++).at(j));
            k++;
        }
    }
    return mali;
}
int main ()
{
    int x,y,z;
    vector<deque<deque<int>>> v;
    SmjerKretanja smjer;
    for(;;)
    {
        cout<<"Unesite dimenzije (x y z): ";
        cin>>x>>y>>z;
        if(x<0 or y<0 or z<0)
        {
            cout<<"Neispravne dimenzije kontejnera!";
            return 0;
        }
        v.resize(x);
        
        for(int i=0;i<x;i++)
        {
            v.at(i).resize(y);
            for(int j=0;j<y;j++)
                v.at(i).at(j).resize(z);
        }
        cout<<"Unesite elemente kontejnera: \n";
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                for(int k=0;k<z;k++)
                    cin>>v.at(i).at(j).at(k);
        cout<<"Unesite smjer kretanja [0 - 5]: ";
        int n;
        cin>>n;
        if(n==0)
            smjer=SmjerKretanja::NaprijedNazad;
        else if(n==1)
            smjer=SmjerKretanja::NazadNaprijed;
        else if(n==2)
            smjer=SmjerKretanja::GoreDolje;
        else if(n==3)
            smjer=SmjerKretanja::DoljeGore;
        else if(n==4)
            smjer=SmjerKretanja::LijevoDesno;
        else if(n==5)
            smjer=SmjerKretanja::DesnoLijevo;
        else
        {
            cout<<"Smjer kretanja nije ispravan!\n";
            return 0;
        }
        break;
    }
    deque<deque<int>> a;
    try
    {
        a=IzdvojiDijagonale3D(v,smjer);
        if(smjer==SmjerKretanja::NaprijedNazad)
            cout<<"NaprijedNazad: \n";
        else if(smjer==SmjerKretanja::NazadNaprijed)
            cout<<"NazadNaprijed: \n";
        else if(smjer==SmjerKretanja::GoreDolje)
            cout<<"GoreDolje: \n";
        else if(smjer==SmjerKretanja::DoljeGore)
            cout<<"DoljeGore: \n";
        else if(smjer==SmjerKretanja::LijevoDesno)
            cout<<"LijevoDesno: \n";
        else if(smjer==SmjerKretanja::DesnoLijevo)
            cout<<"DesnoLijevo: \n";
        for(auto d:a)
        {
            for(auto c:d)
                cout<<std::setw(4)<<c;
            cout<<"\n";
        }
    }
    catch(std::domain_error e)
    {
        cout<<e.what();
    }
	return 0;
}