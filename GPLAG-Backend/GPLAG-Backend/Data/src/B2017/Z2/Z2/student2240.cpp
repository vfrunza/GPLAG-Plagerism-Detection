/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
#include <vector>
#include <deque>


enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename tip>
tip PjescaniSat (tip kont, SmjerKretanja smjer)
{
    for (int i{};i<kont.size();i++)
    {
        if (kont.size() != kont.at(i).size())
            throw std::domain_error ("3D matrica nema oblik kocke");
            
        if (kont.at(0).size() != kont.at(i).size())
            throw std::domain_error ("3D matrica nema oblik kocke");
        
        for (int j{};j<kont.at(i).size();j++)
        {
            if (kont.at(i).at(0).size() != kont.at(i).at(j).size())
                throw std::domain_error ("3D matrica nema oblik kocke");
        }
        
    }
    
    for (int i{};i<kont.size();i++)
    {
        if (kont.at(i).size() % 2 == 0)
            throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
            
        for (int j{};j<kont.at(i).size();j++)
        {
            if (kont.at(i).at(j).size() % 2 == 0)
                throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
            
        }
    }
    
    if (kont.size() == 1)
        return kont;
    
    tip rezultat;
    
   if (smjer == SmjerKretanja::GoreDolje)
   {
       int n = kont.size()/2;
       for (int i{};i<kont.size();i++)
       {
           typename std::remove_reference<decltype(kont.at(0))>::type pomocni_matrica;
           
           int pomocni_k = 0;
           int pomocni_granica = kont.size();
           for (int j{};j<kont.size();j++)
           {
               typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_red;
               int granica_kolone = pomocni_granica;
               int k = pomocni_k;
               for (k;k<granica_kolone;k++)
                    pomocni_red.push_back(kont.at(i).at(j).at(k)); 
               
               pomocni_matrica.push_back(pomocni_red);
               
               if (j < n)
               {
                   pomocni_k++;
                   pomocni_granica--;
               }
               else
               {
                   pomocni_k--;
                   pomocni_granica++;
               }
               
           }
           
           rezultat.push_back(pomocni_matrica);
       }
       
   }
   
   if (smjer == SmjerKretanja::DoljeGore)
   {
       int n = kont.size()/2;
       for (int i{};i<kont.size();i++)
       {
           typename std::remove_reference<decltype(kont.at(0))>::type pomocni_matrica;
           
           int pomocni_k = 0;
           int pomocni_granica = kont.size();
           for (int j{kont.size()-1};j>=0;j--)
           {
               typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_red;
               int granica_kolone = pomocni_granica;
               int k = pomocni_k;
               for (k;k<granica_kolone;k++)
                    pomocni_red.push_back(kont.at(i).at(j).at(k)); 
               
               pomocni_matrica.push_back(pomocni_red);
               
               if (j > n)
               {
                   pomocni_k++;
                   pomocni_granica--;
               }
               else
               {
                   pomocni_k--;
                   pomocni_granica++;
               }
               
           }
           
           rezultat.push_back(pomocni_matrica);
       }
       
   }
   
   if (smjer == SmjerKretanja::DesnoLijevo)
   {
       int n = kont.size()/2;
       for (int i{};i<kont.size();i++)
       {
           typename std::remove_reference<decltype(kont.at(0))>::type pomocni_matrica;
           
           int pomocni_k = 0;
           int pomocni_granica = kont.size();
           for (int j{kont.size()-1};j>=0;j--)
           {
               typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_red;
               int granica_kolone = pomocni_granica;
               int k = pomocni_k;
               for (k;k<granica_kolone;k++)
                    pomocni_red.push_back(kont.at(i).at(k).at(j)); 
               
               pomocni_matrica.push_back(pomocni_red);
               
               if (j > n)
               {
                   pomocni_k++;
                   pomocni_granica--;
               }
               else
               {
                   pomocni_k--;
                   pomocni_granica++;
               }
               
           }
           
           rezultat.push_back(pomocni_matrica);
       }
       
   }
   
   if (smjer == SmjerKretanja::LijevoDesno)
   {
       int n = kont.size()/2;
       for (int i{};i<kont.size();i++)
       {
           typename std::remove_reference<decltype(kont.at(0))>::type pomocni_matrica;
           
           int pomocni_k = 0;
           int pomocni_granica = kont.size();
           for (int j{};j<kont.size();j++)
           {
               typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_red;
               int granica_kolone = pomocni_granica;
               int k = pomocni_k;
               for (k;k<granica_kolone;k++)
                    pomocni_red.push_back(kont.at(i).at(k).at(j)); 
               
               pomocni_matrica.push_back(pomocni_red);
               
               if (j < n)
               {
                   pomocni_k++;
                   pomocni_granica--;
               }
               else
               {
                   pomocni_k--;
                   pomocni_granica++;
               }
               
           }
           
           rezultat.push_back(pomocni_matrica);
       }
       
   }
   
   if (smjer == SmjerKretanja::NaprijedNazad)
   {
       int n = kont.size()/2;
       for (int i{};i<kont.size();i++)
       {
           typename std::remove_reference<decltype(kont.at(0))>::type pomocni_matrica;
           
           int pomocni_k = 0;
           int pomocni_granica = kont.size();
           for (int j{};j<kont.size();j++)
           {
               typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_red;
               int granica_kolone = pomocni_granica;
               int k = pomocni_k;
               for (k;k<granica_kolone;k++)
                    pomocni_red.push_back(kont.at(j).at(i).at(k)); 
               
               pomocni_matrica.push_back(pomocni_red);
               
               if (j < n)
               {
                   pomocni_k++;
                   pomocni_granica--;
               }
               else
               {
                   pomocni_k--;
                   pomocni_granica++;
               }
               
           }
           
           rezultat.push_back(pomocni_matrica);
       }
       
   }
   
   if (smjer == SmjerKretanja::NazadNaprijed)
   {
       int n = kont.size()/2;
       for (int i{};i<kont.size();i++)
       {
           typename std::remove_reference<decltype(kont.at(0))>::type pomocni_matrica;
           
           int pomocni_k = 0;
           int pomocni_granica = kont.size();
           for (int j{kont.size()-1};j>=0;j--)
           {
               typename std::remove_reference<decltype(kont.at(0).at(0))>::type pomocni_red;
               int granica_kolone = pomocni_granica;
               int k = pomocni_k;
               for (k;k<granica_kolone;k++)
                    pomocni_red.push_back(kont.at(j).at(i).at(k)); 
               
               pomocni_matrica.push_back(pomocni_red);
               
               if (j > n)
               {
                   pomocni_k++;
                   pomocni_granica--;
               }
               else
               {
                   pomocni_k--;
                   pomocni_granica++;
               }
               
           }
           
           rezultat.push_back(pomocni_matrica);
       }
       
   }
    
    
    
    return rezultat;
}

int main ()
{
    try
    {
        std::cout<<"Unesite dimenziju (x/y/z): ";
        int n;
        std::cin>>n;
        std::cin.ignore(10000, '\n');
        while (n<=0)
        {
            std::cout<<"Dimenzija nije ispravna, unesite opet: ";
            std::cin>>n;
            std::cin.ignore(10000, '\n');
        }
        
        std::vector<std::deque<std::deque<int>>> upis;
        
        std::cout<<"Unesite elemente kontejnera: ";
        for (int i{};i<n;i++)
        {
            std::deque<std::deque<int>> d;
            
            for (int j{};j<n;j++)
            {
                std::deque<int> red;
                
                for (int k{};k<n;k++)
                {
                    int x;
                    std::cin>>x;
                    red.push_back(x);
                }
                
                std::cin.ignore(10000, '\n');
                d.push_back(red);
            }
            
            upis.push_back(d);
        }
        
        std::cout<<"Unesite smjer kretanja [0 - 5]: ";
        int smjer;
        std::cin>>smjer;
        
        while (true)
        {
            if (smjer>=0 && smjer<=5)
                break;
            std::cout<<"Smjer nije ispravan, unesite opet: ";
            std::cin>>smjer;
            std::cin.ignore(10000, '\n');
        }
        
        std::cout<<std::endl;
        auto ispis = PjescaniSat(upis,(SmjerKretanja)smjer);
        
        std::cout<<"Pjescani sat unesene matrice je:"<<std::endl;
        
        int velicina = n/2;
        for (int i{}; i<n; i++)
        {
            std::cout<<std::endl;
            int pomocni_l = 0;
            int pomocni_granica = n;
            
            for (int j{};j<n;j++)
            {
                int granica_kolone = pomocni_granica;
                int l = pomocni_l;
                int m = 0;
                for (int k{};k<n;k++)
                {
                    if (k>=l && k<granica_kolone)
                        std::cout<<std::right<<std::setw(4)<<ispis[i][j][m++];
                    else
                        std::cout<<"    ";
                }
                
                if (j<velicina)
                {
                    pomocni_l++;
                    pomocni_granica--;
                }
                else
                {
                    pomocni_l--;
                    pomocni_granica++;
                }
                
                std::cout<<std::endl;
            }
            
        }
    }
    catch (std::domain_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch (std::length_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
    
	return 0;
}