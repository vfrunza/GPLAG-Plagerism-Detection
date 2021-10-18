// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
 
 
 
#include<vector>
#include<deque>
#include<iostream>
#include<type_traits>
#include<algorithm>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::vector;
using std::deque;
using std::setw;
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template<typename NekiTip>
auto IzdvojiDijagonale3D(NekiTip kont,SmjerKretanja a)->typename std::remove_reference<decltype(kont[0])>::type
{
    for(int i=0;i<kont.size();i++)
    {
        for(int j=0;j<kont.at(i).size();j++)
        {
            if(kont.at(i).at(j).size()!=kont.at(0).at(0).size())
            throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i=0;i<kont.size();i++)
    {
        if(kont.at(i).size()!=kont.at(0).size())
        throw std::domain_error("Plohe nemaju isti broj redova");
    }
    typename std::remove_reference<decltype(kont[0])>::type mat;
    if(a==SmjerKretanja::NaprijedNazad)
    {
        for(int i=0;i<kont.size();i++)
        {
            mat.push_back({});
            for(int j=0;j<std::min(kont.at(0).size(),kont.at(0).at(0).size());j++)
            {
                mat.at(i).push_back(kont.at(i).at(j).at(j));
            }
        }
    }
    else if(a==SmjerKretanja::NazadNaprijed)
    {
        for(int i=kont.size()-1;i>=0;i--)
        {
            mat.push_back({});
            for(int j=0;j<std::min(kont.at(0).size(),kont.at(0).at(0).size());j++)
            {
                mat.at(kont.size()-i-1).push_back(kont.at(i).at(j).at(kont.at(0).at(0).size()-j-1));
            }
        }
    }
    else if(a==SmjerKretanja::GoreDolje)
    {
        for(int i=0;i<kont.at(0).size();i++)
        {
            mat.push_back({});
            for(int j=0;j<std::min(kont.size(),kont.at(0).at(0).size());j++)
            {
                mat.at(i).push_back(kont.at(kont.size()-1-j).at(i).at(j));
            }
        }
    }
    else if(a==SmjerKretanja::DoljeGore)
    {
        for(int i=kont.at(0).size()-1;i>=0;i--)
        {
            mat.push_back({});
            for(int j=0;j<std::min(kont.size(),kont.at(0).at(0).size());j++)
            {
                mat.at(kont.at(0).size()-i-1).push_back(kont.at(kont.size()-j-1).at(i).at(kont.at(0).at(0).size()-j-1));
            }
        }
    }
    else if(a==SmjerKretanja::LijevoDesno)
    {
        for(int i=0;i<kont.at(0).at(0).size();i++)
        {
            mat.push_back({});
            for(int j=0;j<std::min(kont.size(),kont.at(0).size());j++)
            {
                mat.at(i).push_back(kont.at(kont.size()-1-j).at(j).at(i));
            }
        }
    }
    else
    {
        for(int i=kont.at(0).at(0).size()-1;i>=0;i--)
        {
            mat.push_back({});
            for(int j=0;j<std::min(kont.size(),kont.at(0).size());j++)
            {
                mat.at(kont.at(0).at(0).size()-i-1).push_back(kont.at(j).at(j).at(i));
            }
        }
    }
    return mat;
}
int main ()
{
    try
    {
    vector<deque<deque<int>>> kontejner;
    deque<deque<int>> dijagonale;
    deque<int> prazan;
    int a,b,c,smj,clan;
    cout<<"Unesite dimenzije (x y z): " ; 
    cin>>a>>b>>c;
    if(a<0 || b<0 || c<0)
        cout<<"Neispravne dimenzije kontejnera!";
    else
    {
        cout<<"Unesite elemente kontejnera: \n";
        for(int i=0;i<a;i++)
        {
            kontejner.push_back(dijagonale);
            for(int j=0;j<b;j++)
            {
                kontejner.at(i).push_back(prazan);
                for(int k=0;k<c;k++)
                {
                    cin>>clan;
                    kontejner.at(i).at(j).push_back(clan);
                }    
            }
        }
        cout<<"Unesite smjer kretanja [0 - 5]: ";
        cin>>smj;
        if(smj==0)
        {
            cout<<"NaprijedNazad: \n";
            dijagonale=IzdvojiDijagonale3D(kontejner,SmjerKretanja::NaprijedNazad);
        }
        else if(smj==1)
        {
            cout<<"NazadNaprijed: \n";
            dijagonale=IzdvojiDijagonale3D(kontejner,SmjerKretanja::NazadNaprijed);
        }
        else if(smj==2)
        {
            cout<<"GoreDolje: \n";
            dijagonale=IzdvojiDijagonale3D(kontejner,SmjerKretanja::GoreDolje);
        }
        else if(smj==3)
        {
            cout<<"DoljeGore: \n";
            dijagonale=IzdvojiDijagonale3D(kontejner,SmjerKretanja::DoljeGore);
        }
        else if(smj==4)
        {
            cout<<"LijevoDesno: \n";
            dijagonale=IzdvojiDijagonale3D(kontejner,SmjerKretanja::LijevoDesno);
        }
        else if(smj==5)
        {
            cout<<"DesnoLijevo: \n";
            dijagonale=IzdvojiDijagonale3D(kontejner,SmjerKretanja::DesnoLijevo);
        }
        else
        cout<<"Smjer kretanja nije ispravan!\n";
    for(int i=0;i<dijagonale.size();i++)
    {
        for(int j=0;j<dijagonale.at(0).size();j++)
        {
            cout<<setw(4)<<dijagonale.at(i).at(j);
        }
        cout<<"\n";
    }
    }
    }
    catch(std::domain_error izuzetak)
    {
        cout<<izuzetak.what();
    }
	return 0;
}