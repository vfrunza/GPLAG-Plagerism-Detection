// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<type_traits>
#include<deque>
#include<vector>
#include<stdexcept>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template<typename tip>
auto Transponuj(tip x)->typename std::remove_reference<decltype(x)>::type
{
    typename std::remove_reference<decltype(x)>::type rezultat;
    for(int i=0;i<x.at(0).size();i++)
    {
        typename std::remove_reference<decltype(x.at(0))>::type red;
        for(int j=0;j<x.size();j++)
        {
            red.push_back(x.at(j).at(i));
        }
        rezultat.push_back(red);
        
    }
    return rezultat;
    
}
template<typename tip>
auto IzdvojiDijagonale3D(tip kont,SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type
{
    typename std::remove_reference<decltype(kont.at(0))>::type rez;
    int brojElemenataURedu=kont.at(0).at(0).size();
    int brojElemenata=kont.at(0).size();
    for(int i=0;i<kont.size();i++)
    {
        int brojac1=0;
        for(int j=0;j<kont.at(i).size();j++)
        {
            brojac1++;
        int brojac=0;
        for(int k=0;k<kont.at(i).at(j).size();k++)
        brojac++;
        if(brojac!=brojElemenataURedu) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
        if(brojac1!=brojElemenata) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
    
    if(smjer==SmjerKretanja::NaprijedNazad)
    {
        for(int i=0;i<kont.size();i++)
        {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j=0;j<kont.at(i).size();j++)
            {
                for(int k=0;k<kont.at(i).at(j).size();k++)
                {
                    if(k==j)
                    {
                        red.push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
            rez.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::NazadNaprijed)
    {
        for(int i=kont.size()-1;i>=0;i--)
        {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j=0;j<kont.at(i).size();j++)
            {
                int dijagonala=kont.at(i).at(j).size()-1;
                for(int k=0;k<kont.at(i).at(j).size();k++)
                {
                    if((k+j)==dijagonala)
                    {
                        red.push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
            rez.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje)
    {
        for(int i=kont.size()-1;i>=0;i--)
        {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j=0;j<kont.at(i).size();j++)
            {
                for(int k=0;k<kont.at(i).at(j).size();k++)
                {
                    int pom=kont.size()-1;
                    pom=pom-i;
                    if(k==pom)
                    {
                        red.push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
            rez.push_back(red);
        }
        rez=Transponuj(rez);
    }
    else if(smjer==SmjerKretanja::DoljeGore)
    {
        for(int i=kont.size()-1;i>=0;i--)
        {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j=kont.at(i).size()-1;j>=0;j--)
            {
                for(int k=0;k<kont.at(i).at(j).size();k++)
                {
                    int pom=kont.size()-1;
                    pom=pom-i;
                    if(k==(kont.at(i).at(j).size()-1-pom))
                    {
                        red.push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
            rez.push_back(red);
        }
        rez=Transponuj(rez);
    }
    else if(smjer==SmjerKretanja::LijevoDesno)
    {
        for(int i=kont.size()-1;i>=0;i--)
        {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j=0;j<kont.at(i).size();j++)
            {
                for(int k=0;k<kont.at(i).at(j).size();k++)
                {
                    int pom=kont.size()-1;
                    pom=pom-i;
                    if(j==pom)
                    {
                        red.push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
            rez.push_back(red);
        }
        rez=Transponuj(rez);
    }
    else if(smjer==SmjerKretanja::DesnoLijevo)
    {
        for(int i=0;i<kont.size();i++)
        {
            typename std::remove_reference<decltype(kont.at(0).at(0))>::type red;
            for(int j=0;j<kont.at(i).size();j++)
            {
                for(int k=kont.at(i).at(j).size()-1;k>=0;k--)
                {
                    if(j==i)
                    {
                        red.push_back(kont.at(i).at(j).at(k));
                    }
                }
            }
            rez.push_back(red);
        }
        rez=Transponuj(rez);
    }
    return rez;
}
int main ()
{
    std::cout<<"Unesite dimenzije (x y z): ";
    int a,b,c;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    bool nijeUnesenaIspravnaKomanda=false;
    if(a<0 || b<0 || c<0)  
    {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";
    std::cout<<std::endl;
    std::deque<std::deque<std::vector<int>>> kont;
    for(int i=0;i<a;i++)
    {
        std::deque<std::vector<int>> dvaD;
        for(int j=0;j<b;j++)
        {
            std::vector<int> jedanD;
            for(int k=0;k<c;k++)
            {
                int x;
                std::cin>>x;
                jedanD.push_back(x);
            }
            dvaD.push_back(jedanD);
        }
        kont.push_back(dvaD);
    }
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int smjerx;
    std::cin>>smjerx;
    std::deque<std::vector<int>> p;
    try
    {
    if(smjerx==0)
    {
        std::cout<<"NaprijedNazad: ";
         p=IzdvojiDijagonale3D (kont, SmjerKretanja::NaprijedNazad);
    }
    else if(smjerx==1)
    {
        std::cout<<"NazadNaprijed: ";
         p=IzdvojiDijagonale3D (kont, SmjerKretanja::NazadNaprijed);
    }
    else if(smjerx==2)
    {
        std::cout<<"GoreDolje: ";
         p=IzdvojiDijagonale3D (kont, SmjerKretanja::GoreDolje);
    }
    else if(smjerx==3)
    {
        std::cout<<"DoljeGore: ";
         p=IzdvojiDijagonale3D (kont, SmjerKretanja::DoljeGore);
    }
    else if(smjerx==4)
    {
        std::cout<<"LijevoDesno: ";
         p=IzdvojiDijagonale3D (kont, SmjerKretanja::LijevoDesno);
    }
     else if(smjerx==5)
    {
        std::cout<<"DesnoLijevo: ";
         p=IzdvojiDijagonale3D (kont, SmjerKretanja::DesnoLijevo);
    }
    else
    {
        nijeUnesenaIspravnaKomanda=true;
        std::cout<<"Smjer kretanja nije ispravan!";
    }
    std::cout<<std::endl;
    if(!nijeUnesenaIspravnaKomanda)
    {
    for (const auto &red : p)
        {
            for (const auto &x : red)
                std::cout.width (4), std::cout << x;
            std::cout << std::endl;
        }
    }
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what()<<std::endl;
        return 0;
    }
    
    return 0;
}