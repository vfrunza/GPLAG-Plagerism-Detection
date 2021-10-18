#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <iomanip>


enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename kontejner_tip>
auto IzdvojiDijagonale3D (kontejner_tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    typename std::remove_reference<decltype(kont.at(0))>::type rezultat_prazan;
    
    for (int i{};i<kont.size();i++)
        {
            if (kont.at(i).size() != kont.at(0).size())
                throw std::domain_error ("Redovi nemaju isti broj elemenata");
                
                for (int j{};j<kont.at(i).size();j++)
                    {
                        if (kont.at(i).at(j).size() != kont.at(i).at(0).size())
                            throw std::domain_error ("Plohe nemaju isti broj redova");
                    }
        }
    
    if (smjer == SmjerKretanja::NaprijedNazad)
        {
            typename std::remove_reference<decltype(kont.at(0))>::type rezultat;
            for (int i{};i<kont.size();i++)
                rezultat.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type (kont.at(0).size()));
              
            int a = 0; 
            for (int i{};i<kont.size();i++)
                {
                    int b = 0; 
                    for (int j{};j<kont.at(i).size();j++)
                        {
                            for (int k{};k<kont.at(i).at(j).size();k++)
                                {
                                    if (j == k)
                                        rezultat.at(a).at(b) = kont.at(i).at(j).at(k);
                                }
                            b++;
                        }
                    a++;
                }
                
            return rezultat;
        }
    
    
    if (smjer == SmjerKretanja::NazadNaprijed)
        {
            typename std::remove_reference<decltype(kont.at(0))>::type rezultat;
            for (int i{};i<kont.size();i++)
                rezultat.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type (kont.at(0).size()));
                
            int a = 0; 
            for (int i{kont.size()-1};i>=0;i--)
                {
                    int b = 0; 
                    for (int j{};j<kont.at(i).size();j++)
                        {
                            for (int k{kont.at(i).at(j).size()-1};k>=0;k--)
                                {
                                    if (k+j == kont.at(i).at(j).size()-1)
                                        rezultat.at(a).at(b) = kont.at(i).at(j).at(k);
                                }
                            b++;
                        }
                    a++;
                }
                
            return rezultat;
        }
        
    if (smjer == SmjerKretanja::GoreDolje)
        {
            typename std::remove_reference<decltype(kont.at(0))>::type rezultat;
            for (int i{};i<kont.at(0).size();i++)
                rezultat.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type (kont.size()));
                
            int a = 0;
            for (int i{kont.size()-1};i>=0;i--)
                {
                    for (int j{};j<kont.at(i).size();j++)
                        {
                           rezultat.at(j).at(a) = kont.at(i).at(j).at(a);
                        }
                    a++;
                }
                
            return rezultat;
        }
            
    if (smjer == SmjerKretanja::DoljeGore)
        {
            typename std::remove_reference<decltype(kont.at(0))>::type rezultat;
            for (int i{};i<kont.at(0).size();i++)
                rezultat.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type (kont.size()));
                
            int a = kont.at(0).at(0).size()-1;
            int b = 0;
            for (int i{kont.size()-1};i>=0;i--)
                {
                    int c = 0;
                    for (int j{kont.at(i).size()-1};j>=0;j--)
                        {
                           rezultat.at(c).at(b) = kont.at(i).at(j).at(a);
                           c++;
                        }
                    b++;
                    a--;
                }
                
            return rezultat;
        }
        
    if (smjer == SmjerKretanja::LijevoDesno)
        {
            typename std::remove_reference<decltype(kont.at(0))>::type rezultat;
            for (int i{};i<kont.at(0).at(0).size();i++)
                rezultat.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type (kont.size()));
                
            int a = 0; 
            for (int i{kont.size()-1};i>=0;i--)
                {
                    int b = 0; 
                    for (int j{};j<kont.at(0).at(0).size();j++)
                        {
                           rezultat.at(j).at(a) = kont.at(i).at(a).at(j);
                        }
                    a++;
                }
                
            return rezultat;
            
        }
        
    if (smjer == SmjerKretanja::DesnoLijevo)
        {
             typename std::remove_reference<decltype(kont.at(0))>::type rezultat;
            for (int i{};i<kont.at(0).at(0).size();i++)
                rezultat.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type (kont.size()));
                
            int a = 0; 
            for (int i{};i<kont.size();i++)
                {
                    int b = 0; 
                    for (int j{kont.at(0).at(0).size()-1};j>=0;j--)
                        {
                           rezultat.at(b).at(a) = kont.at(i).at(a).at(j);
                           b++;
                        }
                    a++;
                }
                
            return rezultat;
        }
    
    
    
    
    return rezultat_prazan;
}


void Ispisi_smjer (int smjer)
{
    if (smjer == 0)
        std::cout<<"NaprijedNazad: "<<std::endl;
    
    if (smjer == 1)
        std::cout<<"NazadNaprijed: "<<std::endl;
        
    if (smjer == 2)
        std::cout<<"GoreDolje: "<<std::endl;
        
    if (smjer == 3)
        std::cout<<"DoljeGore: "<<std::endl;
        
    if (smjer == 4)
        std::cout<<"LijevoDesno: "<<std::endl;
    
    if (smjer == 5)
        std::cout<<"DesnoLijevo: "<<std::endl;
}




int main ()
{
    
    try
    {
        std::cout<<"Unesite dimenzije (x y z): ";
        int x,y,z;
        std::cin>>x>>y>>z;
        
        if (x<0 || y<0 || z<0)
            {
                std::cout<<"Neispravne dimenzije kontejnera!";
                return 0;
            }
        
        std::cout<<"Unesite elemente kontejnera: "<<std::endl;
        std::vector<std::deque<std::deque<int>>> kont (x);
        for (int i{};i<x;i++)
            {
                kont[i].resize(y);
                for (int j{};j<y;j++)
                    {
                        kont[i][j].resize(z);
                        for (int k{};k<z;k++)
                            std::cin>>kont[i][j][k];
                    }
            }
        
        std::cout<<"Unesite smjer kretanja [0 - 5]: ";
        int smjer;
        std::cin>>smjer;
        
        if (smjer<0 || smjer>5)
            {
                std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
            }
        
        Ispisi_smjer(smjer);
        
        std::deque<std::deque<int>> ispis = IzdvojiDijagonale3D(kont,(SmjerKretanja)smjer);
        
        for (int i{};i<ispis.size();i++)
            {
                for (int j{};j<ispis[i].size();j++)
                    std::cout<<std::right<<std::setw(4)<<ispis[i][j];
                    
                std::cout<<std::endl;
            }
        
        
        
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what();
    }
    
    
    
    
    
	return 0;
}