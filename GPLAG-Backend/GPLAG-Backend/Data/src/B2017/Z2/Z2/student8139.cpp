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
#include <set>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
enum class Boje {Pik, Tref, Herc, Karo} boja;
vector<string>v{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
vector<string>v2{"Pik", "Tref", "Herc", "Karo"};

void IspisiKarte(std::list<std::pair<Boje, std::string> > l){
    for(auto i : l){
            if(i.first == Boje(0)) std::cout<<"pik";
            else if(i.first == Boje(1)) std::cout<<"tref";
            else if(i.first == Boje(2)) std::cout<<"herc";
            else std::cout<<"karo";
        std::cout<<" | " << i.second<<std::endl;
    }
}

   list<pair<Boje, string>> KreirajSpil(){
       list<pair<Boje, string>>lista(52);
       int x = 0;
       boja=Boje(x);
       int k(0);
       for(auto it=lista.begin();it!=lista.end();it++){
           *it=make_pair(boja, v[k]);
           k++;
           if(k==v.size()){
               k=0;
               x++;
               boja=Boje(x);
           }

       }
       return lista;
   }

   bool pom(pair<Boje,string>p, multimap<Boje, string>&m){
       for(auto it=m.begin(); it!=m.end();it++){
           // std::cout<<"g";
           if(p.first==it->first && p.second==it->second)
           return true;
       }
       return false;
   }

   int pretraziVektor(string s){
    for(int i = 0; i<v.size(); i++)
        if(s == v[i]) return i;
    return -1;
   }

   bool SmislenSpil(list<pair<Boje, string>> l){
    Boje trenutna_boja = (*(l.begin())).first;
    int trenutni_broj = pretraziVektor((*(l.begin())).second);

    for(auto it = l.begin(); it!=l.end(); it++){
        if(it == l.begin()) continue;
        Boje procitana_boja = it->first;
        int procitani_broj = pretraziVektor(it->second);

        if((int)procitana_boja == (int)trenutna_boja){
            if(trenutni_broj >= procitani_broj) return false;
        }
        if((int)procitana_boja < (int)trenutna_boja) return false;
    }
return true;
   }

    void IzbaciKarte(list<pair<Boje, string>>&l, multimap<Boje, string>&m){
    if(l.size()>52)throw logic_error("Neispravna lista!");
        if(!SmislenSpil(l)) throw logic_error("nije smisleno");
        for(auto it=l.begin();it!=l.end();it++){
            pair<Boje, string>p=*it;
            if(pom(*it, m)){
                it = l.erase(it);
                it = l.begin();
                for(auto it2 = m.begin(); it2 != m.end(); it2++){
                    if(p.first==it2->first && p.second==it2->second){
                        m.erase(it2);
                    }
                }
            }
        }
    }

    queue<pair<string,string>>IzbaciKarteRazbrajanjem(list<pair<Boje, string>>&l, const short int &r, const int &b){
        if(r<1 || r>52 ||b<1)throw logic_error("Neispravni elementi za izbacivanje!");
        if(l.size()>52)throw logic_error("Neispravna lista!");
        queue<pair<string, string>> red;
        short int br(1);
        int koliko(0);

        for(auto it=l.begin();it!=l.end();){
            if(br==r) {
            koliko++;
            string pom=v2[(int)it->first];
            red.push(make_pair(pom,it->second));
            it=l.erase(it);
            br=1;
            it--;
            }
            else br++;
            if(koliko == b) break;
            it++;
            if(it == l.end()) it = l.begin();
        }
        return red;
    }

    int pretraziBoje(string s){
        for(int i = 0; i<v2.size(); i++)
            if(s == v2[i]) return i;
        return -1;
    }

    void VratiPrvihNKarata(list<pair<Boje,string>>&l, queue<pair<string, string>>&red, int n){
        if(n>red.size())throw range_error("Nedovoljno karata u redu!");
        if(n<0)throw domain_error("Broj n je besmislen!");
        if(l.size()>52)throw logic_error("Neispravna lista!");
        int br(0);
        while(n != 0){
            auto element = red.front();
            red.pop();
            n--;
            int redni_broj_boje = pretraziBoje(element.first);
            int redni_broj_broja = pretraziVektor(element.second);

            for(auto it = l.begin(); it != l.end(); it++){
                int boja_u_listi = (int)it->first;
                int redni_broj_u_listi = pretraziVektor(it->second);
                if(redni_broj_boje == boja_u_listi && redni_broj_u_listi > redni_broj_boje){
                    l.insert(it, std::make_pair(Boje(redni_broj_boje), element.second));
                    break;
                }
                else if(redni_broj_boje > boja_u_listi){
                    l.insert(it, std::make_pair(Boje(redni_broj_boje), element.second));
                    break;
                }
            }
        }
    }


int main ()
{
    auto l = KreirajSpil();
    std::multimap<Boje, string> m{ {Boje(0), "5"}, {Boje(0), "6"}, {Boje(0), "6"}
    };
    auto red = IzbaciKarteRazbrajanjem(l, 12, 6);
    IspisiKarte(l);
    std::cout<<red.size();
    std::cout<<std::boolalpha<<SmislenSpil(l);
	return 0;
}