#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <deque>
#include <type_traits>
 
enum class SmjerKretanja{NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};
 
template <typename Tip>
Tip PjescaniSat(const Tip &kont, SmjerKretanja smjer)
{
    Tip novi;
    int n=kont.size();
    if(n==0) return novi;
    int br(0);
    for(auto m : kont)
    {
        for(auto v : m)
        {
            for(auto x : v) br++;
               
        }
    }
    if(br==0) return novi;
    for(auto m : kont)
    {
        for(auto v : m)
        {
            if(v.size()!=m.size() || v.size()!=kont.size() || m.size()!=kont.size())
            {
                throw std::domain_error("3D matrica nema oblik kocke");
            }
        }
        if(m.size()!=kont.size()) throw std::domain_error("3D matrica nema oblik kocke");
    }
    if(n%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
    //npr vektor dekova vektora, x ce bit vektor dekova vektora, y ce bit dek vektora, z ce biti vektor brojeva, w ce biti broj
    typename std::remove_reference<decltype(kont)>::type x;
    typename std::remove_reference<decltype(kont.at(0))>::type y;
    typename std::remove_reference<decltype(kont.at(0).at(0))>::type z;
    typename std::remove_reference<decltype(kont.at(0).at(0).at(0))>::type w=kont.at(0).at(0).at(0);
    for(int k=0;k<n;k++)
    {
        novi.push_back(y);
        for(int i=0;i<n;i++)
        {
            novi.at(k).push_back(z);
            if(i<=n/2)
            {
                for(int j=0;j<n-i*2;j++)
                {
                    novi.at(k).at(i).push_back(w);
                }
            }
            else
            {
                for(int j=0;j<(i-n/2)*2+1;j++)
                {
                    novi.at(k).at(i).push_back(w);
                }
            }
        }
    }
    int broj2(0),broj3(0);
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tempi=i,tempj=j,tempk=k;
                if(smjer==SmjerKretanja::DoljeGore)
                {
                    tempi=n-i-1;
                }
                else if(smjer==SmjerKretanja::LijevoDesno)
                {
                    int temp=tempi;
                    tempi=tempj;
                    tempj=temp;
                }
                else if(smjer==SmjerKretanja::DesnoLijevo)
                {
                    int temp=tempi;
                    tempi=tempj;
                    tempj=n-1-temp;
                }
                else if(smjer==SmjerKretanja::NaprijedNazad)
                {
                    int temp=tempi;
                    tempi=tempk;
                    tempk=temp;
                }
                else if(smjer==SmjerKretanja::NazadNaprijed)
                {
                    int temp=tempi;
                    tempi=tempk;
                    tempk=n-1-temp;
                }
                if(i<=n/2 && j>=i && j<=(n-i-1)) novi.at(k).at(broj2).at(broj3++)=kont.at(tempk).at(tempi).at(tempj);
                else if(i>n/2 && i>=j && i>=n-j-1) novi.at(k).at(broj2).at(broj3++)=kont.at(tempk).at(tempi).at(tempj);
               
            }
            broj3=0;
            broj2++;
        }
        broj2=0;
    }
    return novi;
}
 
int main()
{
   
    try
    {
 
        std::cout<<"Unesite dimenziju (x/y/z): ";
        int n;
        while(1)
        {
            std::cin>>n;
            if(n<=0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
            else break;
        }
        std::vector<std::deque<std::deque<int>>> kont;
        std::cout<<"Unesite elemente kontejnera: ";
        for(int k=0;k<n;k++)
        {
            kont.push_back(std::deque<std::deque<int>>(n));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int unos;
                    std::cin>>unos;
                    kont.at(k).at(i).push_back(unos);
                }
            }
        }
        std::cout<<"Unesite smjer kretanja [0 - 5]: ";
        int m;
        while(1)
        {
            std::cin>>m;
            if(m<0 || m>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
            else break;
        }
        SmjerKretanja smjer=SmjerKretanja(m);
        auto novo=PjescaniSat(kont,smjer);
       
        std::cout<<std::endl<<"Pjescani sat unesene matrice je:"<<std::endl;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                if(n-novo.at(k).at(i).size()>0) std::cout<<std::setw((n-novo.at(k).at(i).size())*2)<<" ";
                for(int j=0;j<novo.at(k).at(i).size();j++)
                {
                    if(j==novo.at(k).at(i).size()-1) std::cout<<" "<<std::setw(3)<<novo.at(k).at(i).at(j);
                    else std::cout<<" "<<std::setw(3)<<novo.at(k).at(i).at(j);
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }
        /*
        for(auto m:novo)
        {
            for(auto v:m)
            {
                for(auto x : v) std::cout<<x<<" ";
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }
        typename std::remove_reference<decltype(vekt)>::type x;
        typename std::remove_reference<decltype(vekt.at(0))>::type y;
        typename std::remove_reference<decltype(vekt.at(0).at(0))>::type z;
        x.push_back(y);
        x.at(0).push_back(z);
        x.at(0).at(0).push_back(5);
        x.at(0).at(0).push_back(6);
        std::cout<<x.at(0).at(0).at(1);
        std::cout << typeid(x).name() << '\n';
        std::cout << typeid(y).name() << '\n';
        std::cout << typeid(z).name() << '\n';*/
    }  
    catch(std::length_error izuzetak)
    {
        std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}