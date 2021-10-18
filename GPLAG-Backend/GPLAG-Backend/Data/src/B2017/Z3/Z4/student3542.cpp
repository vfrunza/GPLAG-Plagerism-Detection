/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <list>
#include <queue>
#include <new>
#include <stdexcept>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

enum class Boje {Pik = 0, Tref = 1, Herc = 2, Karo = 3};

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::pair<Boje, std::string> Karta;
typedef std::queue<std::pair<std::string,std::string>> Red;

std::vector<std::string> znakovi {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
std::vector<std::string> boje {"Pik", "Tref", "Herc", "Karo"};

Spil KreirajSpil()
{
     Spil spil(52);
     auto it(spil.begin());
     for (int i{0}; i < 4; i++)
          for (int j{0}; j < 13; j++)
               *it++ = std::make_pair(Boje(i), znakovi.at(j));
     return spil;
}

Spil SortirajSpil (const Spil& spil)
{
     Spil tempSpil{KreirajSpil()};
     Spil sortiranSpil{spil};
     sortiranSpil.sort ([=] (Karta x, Karta y)
                                             {
                                                  int i{0}, j{0}, k{0};
                                                  for (auto it = tempSpil.begin(); it != tempSpil.end(); it++, k++)
                                                  {
                                                       if (*it == x)
                                                            i = k;
                                                       if (*it == y)
                                                            j = k;
                                                  }
                                                  return  i < j; 
                                             }
                                             );
     return sortiranSpil;
                                             
}

void Ispisi (Spil& spil)
{
     spil = SortirajSpil(spil);
     auto it(spil.begin());
     
     for (int i{0}; i < 4; i++)
     {
          std::cout << boje.at(i) << ": ";
          while ((*it).first == Boje(i) && it != spil.end())
          {
               std::cout << (*it).second << " ";
               it++;
          }
          std::cout << std::endl;
     }
               
}

void ValidirajSpil (Spil& spil)
{
     if (spil != SortirajSpil(spil) || spil.size() > 52)
          throw std::logic_error ("Neispravna lista!");
}

void ValidirajRed(Red& red)
{
     Red temp(red);
     while (!temp.empty())
     {
          if (std::find(boje.begin(), boje.end(), temp.front().first) == boje.end()
               || std::find(znakovi.begin(), znakovi.end(), temp.front().second) == znakovi.end())
               throw std::logic_error("Neispravne karte!");
          temp.pop();
     }
}

Red IzbaciKarteRazbrajanjem(Spil &spil, const short int& r, const int& b)
{
     if (r < 1 || r > 52 || b < 1) 
          throw std::logic_error("Neispravni elementi za izbacivanje!");
     ValidirajSpil(spil);
     Red red;
     int brojIzbacenih{0};
     auto it(spil.begin());
     
     for (int i{0}, j{1}; i < spil.size(); i++, j++)
     {
          if (brojIzbacenih == b)
               break;
          if (!(j % r) && brojIzbacenih < b)
          {
               red.push(std::make_pair(boje.at(int(it->first)),it->second));
               auto temp = spil.erase(it);
               it = temp;
               brojIzbacenih++;
               it--;
          }
          
          if (i + 1 >= spil.size())
               i = -1;
          
          it++;
          if (it == spil.end())
               it = spil.begin();
     }
     return red;
}

void VratiPrvihNKarata (Spil& spil, Red &red, int n)
{
     if (n < 0)
          throw std::domain_error ("Broj n je besmislen!");
          
     ValidirajRed(red);
     if (red.size() < n)
          throw std::range_error ("Nedovoljno karata u redu!");
     
     ValidirajSpil(spil);
     
     while (!red.empty() && n > 0)
     {
          std::pair<std::string, std::string> karta{red.front()};
          int pozicija = std::find(boje.begin(), boje.end(), karta.first) - boje.begin();
          spil.push_back(std::make_pair(Boje(pozicija), karta.second));
          red.pop();
          n--;
     }
     spil = SortirajSpil(spil);
}

void IzbaciKarte(Spil &spil, std::multimap <Boje, std::string>& mapa)
{
     ValidirajSpil(spil);
     
     for(auto it = mapa.begin(); it != mapa.end(); )
          if (std::find (spil.begin(), spil.end(), std::make_pair((*it).first, (*it).second)) != spil.end())
          {
               spil.erase(std::find (spil.begin(), spil.end(), std::make_pair((*it).first, (*it).second)));
               it = mapa.erase(it);
          }
          else it++;
     spil = SortirajSpil(spil);
}

int main()
{
     Spil spil(KreirajSpil());
     int r{0}, b{0}, n{0};
     try
     {
          std::cout << "Unesite korak razbrajanja: ";
          std::cin >> r;
          std::cout << "Unesite broj karata koje zelite izbaciti: ";
          std::cin >> b;
          Red red{IzbaciKarteRazbrajanjem(spil, r, b)};
          std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
          Ispisi(spil);
          
          try
          {
               std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
               std::cin >> n;
               VratiPrvihNKarata(spil, red, n);
               std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
               Ispisi(spil);
          }
          catch (const std::domain_error& e)
          {
               std::cout << "Izuzetak: " << e.what();
          }
          catch (const std::range_error& e)
          {
               std::cout << "Izuzetak: " << e.what();
          }
     }
     catch (const std::logic_error& e)
     {
          std::cout << "Izuzetak: " << e.what();
     }
     
     return 0;
}




int _main1()
{
     //Test funkcije IzbaciKarte
     std::list<std::pair<Boje, std::string>> spil = KreirajSpil();
     std::multimap <Boje, std::string> mapa1 {{Boje(0), "A"}, {Boje(1), "K"}, {Boje(2), "Q"}, {Boje(3), "J"}};
     IzbaciKarte(spil, mapa1);
     std::cout << mapa1.size() << std::endl;
     Ispisi(spil);
     
     std::multimap <Boje, std::string> mapa2 {{Boje(0), "A"}, {Boje(1), "K"}, {Boje(2), "A"}, {Boje(3), "K"}};
     IzbaciKarte(spil, mapa2);
     std::cout << mapa2.size() << std::endl;
     Ispisi(spil);
     
     std::multimap <Boje, std::string> mapa3 {{Boje(0), "A"}, {Boje(1), "K"}, {Boje(2), "A"}, {Boje(3), "K"}};
     IzbaciKarte(spil, mapa3);
     std::cout << mapa3.size() << std::endl;
     Ispisi(spil);
     
     spil = KreirajSpil();
     std::multimap <Boje, std::string> mapa4 {{Boje(0), "A"}, {Boje(1), "K"}, {Boje(0), "A"}, {Boje(1), "K"}};
     IzbaciKarte(spil, mapa4);
     std::cout << mapa4.size() << std::endl;
     Ispisi(spil);
     
     spil.resize(0);
     IzbaciKarte(spil, mapa4);
     std::cout << mapa4.size() << std::endl;
     
     return 0;
}