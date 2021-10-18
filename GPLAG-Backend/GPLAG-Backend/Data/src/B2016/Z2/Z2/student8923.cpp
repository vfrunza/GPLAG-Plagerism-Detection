// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include <iomanip>
#include <type_traits>
using std::cout;
using std::cin;
using std::vector;
using std::deque;
enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };
template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner kont,SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type
{
 typename std::remove_reference<decltype(kont.at(0))>::type mat;
    for(int i=0;i<kont.size();i++)
    {
        for(int j=0;j<kont.at(i).size();j++)
        {
            if(kont.at(0).at(0).size()!=kont.at(i).at(j).size())
            throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i=0;i<kont.size();i++)
    {
        if(kont.at(0).size()!=kont.at(i).size())
        throw std::domain_error("Plohe nemaju isti broj redova");
    }
if(kont.size()==0)
return mat;
 if(kont.size()==1 && kont.at(0).size()==1 && kont.at(0).at(0).size()==1)
 {
     mat=kont.at(0);
     return mat;
 }
for(int i=0;i<kont.size();i++)
{
    typename std::remove_reference<decltype(mat.at(0))>::type vek;
    for(int j=0;j<kont.at(i).size();j++)
    {
        for(int k=0;k<kont.at(i).at(j).size();k++)
        {
            if(smjer==SmjerKretanja::NaprijedNazad)
            {
               if(j==k)
               {
                  vek.push_back(kont.at(i).at(j).at(k));
               }
            }
            if(smjer==SmjerKretanja::NazadNaprijed)
            {
                if(j+k==kont.at(i).size())
                {
                    vek.push_back(kont.at(i).at(j).at(k));
                }
            }
        }
    }
    mat.push_back(vek);
}
if(smjer==SmjerKretanja::GoreDolje)
{
     typename std::remove_reference<decltype(kont.at(0))>::type mat3;
    for(int j=0;j<kont.at(0).size();j++)
    {
        typename std::remove_reference<decltype(mat3.at(0))>::type vek3;
        for(int i=kont.size()-1;i>=0;i--)
        {
            for(int k=0;k<kont.at(0).at(0).size();k++)
            {
                if(i+k==kont.size()-1)
                {
                    vek3.push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        mat3.push_back(vek3);
    }
    return mat3;
}
if(smjer==SmjerKretanja::DoljeGore)
{
    int brojac(0);
    typename std::remove_reference<decltype(kont.at(0))>::type mat3;
    for(int j=(kont.at(0).size()-1);j>=0;j--)
    {
        brojac=0;
        typename std::remove_reference<decltype(mat3.at(0))>::type vek3;
        for(int i=(kont.size()-1);i>=0;i--)
        {
            for(int k=((kont.at(0).at(0)).size()-1);k>=0;k--)
            {
                if(i+k==kont.at(0).at(0).size()-brojac)
                {
                    vek3.push_back(kont.at(i).at(j).at(k-brojac));
                }
            }
        brojac++;
        }
        mat3.push_back(vek3);
    }
return mat3;
}
if(smjer==SmjerKretanja::NazadNaprijed)
{
    typename std::remove_reference<decltype(kont.at(0))>::type mat1;
    for(int i=mat.size()-1;i>=0;i--)
    {
    mat1.push_back(mat.at(i));
    }
    return mat1;
}
if(smjer==SmjerKretanja::DesnoLijevo)
{
    typename std::remove_reference<decltype(kont.at(0))>::type mat2;
    for(int k=((kont.at(0).at(0).size())-1);k>=0;k--)
    {
        typename std::remove_reference<decltype(mat2.at(0))>::type vek2;
        for(int j=0;j<kont.at(0).size();j++)
        {
            for(int i=0;i<kont.size();i++)
            {
                if(i==j)
                {
                    vek2.push_back(kont.at(i).at(j).at(k));
                }
            }
        }
    mat2.push_back(vek2);
    }
    return mat2;
}
if(smjer==SmjerKretanja::LijevoDesno)
{
    typename std::remove_reference<decltype(kont.at(0))>::type mat2;
    for(int k=0;k<kont.at(0).at(0).size();k++)
    {
        typename std::remove_reference<decltype(mat2.at(0))>::type vek2;
        for(int j=0;j<kont.at(0).size();j++)
        {
            for(int i=(kont.size()-1);i>=0;i--)
            {
                if(i+j==kont.size()-1)
                {
                    vek2.push_back(kont.at(i).at(j).at(k));
                }
            }
        }
        mat2.push_back(vek2);
    }
    return mat2;
}
return mat;
}
int main ()
{
    cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    cin>>x>>y>>z;
    if(x<0 || y<0 || z<0)
    {
        cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    vector<deque<deque<int>>> kont(x,deque<deque<int>>(y,deque<int>(z)));
    cout<<"Unesite elemente kontejnera: ";
    for(int i=0;i<kont.size();i++)
    {
    for(int j=0;j<kont.at(i).size();j++)
    {
        for(int k=0;k<kont.at(i).at(j).size();k++)
        {
            int broj;
            cin>>broj;
            kont.at(i).at(j).at(k)=broj;
        }
    }
    }
    cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
    int brojsm;
    SmjerKretanja smjer;
    cin>>brojsm;
    if(brojsm==0)
    {
    smjer=SmjerKretanja::NaprijedNazad;
    cout<<"NaprijedNazad:";
    }
    if(brojsm==1)
    {
    smjer=SmjerKretanja::NazadNaprijed;
    cout<<"NazadNaprijed:";
    }
    if(brojsm==2)
    {
    smjer=SmjerKretanja::GoreDolje;
    cout<<"GoreDolje:";
    }
    if(brojsm==3)
    {
    smjer=SmjerKretanja::DoljeGore;
    cout<<"DoljeGore:";
    }
    if(brojsm==4)
    {
    smjer=SmjerKretanja::LijevoDesno;
    cout<<"LijevoDesno:";
    }
    if(brojsm==5)
    {
    smjer=SmjerKretanja::DesnoLijevo;
    cout<<"DesnoLijevo:";
    }
    if(brojsm<0 || brojsm>5)
    {
    cout<<"Smjer kretanja nije ispravan!"<<std::endl;
    return 0;
    }
    cout<<std::endl;
    deque<deque<int>> mat;
    try
    {
     mat=IzdvojiDijagonale3D(kont,smjer);
    }
    catch(std::domain_error izuzetak)
    {
        cout<<izuzetak.what();
        return 0;
    }
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat.at(i).size();j++)
        {
            cout<<std::setw(4)<<mat.at(i).at(j);
        }
        cout<<std::endl;
    }
   

	return 0;
}