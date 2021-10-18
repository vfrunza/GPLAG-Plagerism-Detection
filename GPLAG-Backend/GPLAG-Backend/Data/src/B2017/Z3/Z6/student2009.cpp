#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <exception>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <memory>
using std::queue;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::pair;
int gvelicina {};



vector<string> TipKarata {"Pik", "Tref", "Herc", "Karo"};
vector<string> Karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
using std::shared_ptr;
enum class Boje
{
    Pik=0,Tref=1,Herc=2,Karo=3
};
typedef std::multimap<Boje, std::string> MMapa;
struct Karta {
    Boje boja;
    string vrijednost;
};

struct Cvor {
    Karta karta;
    shared_ptr<Cvor> sljedeci;
};

void IspisSpila(shared_ptr<const Cvor> c) {
    shared_ptr<const Cvor> p = c;
    int TipKarte=0;
    for(;;) {
        cout << TipKarata.at(TipKarte) << ": ";
        shared_ptr<const Cvor> temp(p);
        int brojac {};
        while(temp!=nullptr && temp->karta.boja == p->karta.boja) {
            brojac++;
            temp = temp->sljedeci;
            if(temp==c) break;
        }
        if(brojac>0 && int(p->karta.boja)==TipKarte) {
            for(int i=0; i<brojac; i++,p=p->sljedeci)
                if(int(p->karta.boja)==TipKarte) cout << p->karta.vrijednost << " ";
            if(p==c) return;
        }
        cout << endl;
        TipKarte++;
        if(TipKarte>3 && !p) return;
    }
}

shared_ptr<Cvor> KreirajSpil() {
    shared_ptr<Cvor>pocetak(nullptr); shared_ptr<Cvor>prethodni {nullptr};
    int TipKarte=0;
    while(TipKarte<=3) {
        for(int i=0; i<Karte.size(); i++) {
            shared_ptr<Cvor> novi {nullptr};
            try {
                novi = shared_ptr<Cvor>(new Cvor {{static_cast<Boje>(TipKarte),Karte.at(i)},nullptr});
                if(!pocetak) pocetak=novi;
                else prethodni->sljedeci =novi;
                prethodni=novi;
            } catch(...) {
                throw std::bad_alloc();
            }
        }
        TipKarte++;
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}

shared_ptr<Cvor>DajZadnji(shared_ptr<Cvor>c) {
   shared_ptr<Cvor> p=c;
    if(c==nullptr) return nullptr;
    do {
        p=p->sljedeci;
    } while(p!=nullptr && p->sljedeci!=c);
    return p;
}

shared_ptr<Cvor> DajPrethodni(shared_ptr<Cvor>pocetak,shared_ptr<Cvor>c) {
    shared_ptr<Cvor>p=pocetak;
    if(pocetak==nullptr) return nullptr;
    do {
        p=p->sljedeci;
    } while(p!=nullptr && p->sljedeci!=c);
    return p;
}

bool validanSpil(shared_ptr<const Cvor> c) {
    shared_ptr<const Cvor> p=c;
    do {
        bool validan {false};
        for(int i=0; i<Karte.size(); i++,p=p->sljedeci) {
            if(p==nullptr) return true;
            if(int(p->karta.boja)<0 || int(p->karta.boja)>3) return false;
            if(p->karta.vrijednost==Karte.at(i)) {
                validan=true;
                break;
            }
        }
        if(!validan) return false;
    } while(p!=c);
    return true;
}

bool ispravnoSortiranSpil(shared_ptr<Cvor> c) {
    if(!c) return true;
    shared_ptr<Cvor> p=c;
    vector<pair<Boje,string>> v;
    do {
        v.push_back(std::make_pair(p->karta.boja,p->karta.vrijednost));
        p=p->sljedeci;
    } while(p!=nullptr && p!=c);

    std::sort(v.begin(),v.end(),[](pair<Boje,string> x,pair<Boje,string> y) {
        return (int(x.first)<int(y.first) || (int(x.first)==int(y.first) &&
                                              std::find(Karte.begin(),Karte.end(),x.second)-Karte.begin() < std::find(Karte.begin(),Karte.end(),y.second)-Karte.begin()));
    });
    p=c;
    for(int i=0; i<v.size(); i++,p=p->sljedeci)
        if(p->karta.boja != v.at(i).first || (p->karta.boja==v.at(i).first && p->karta.vrijednost != v.at(i).second )) return false;
    return true;
}

int PrebrojSpil(shared_ptr<const Cvor> c) {
    shared_ptr<const Cvor> q=c;
    int velicina {};
    if(q!=nullptr)
        do {
            q=q->sljedeci;
            velicina++;
        } while(q!=nullptr && q!=c);
    return velicina;
}

void IzbaciKarte(shared_ptr<Cvor> &c, MMapa &m) {
    int velicina=PrebrojSpil(c);
    if(velicina>52 || !validanSpil(c) || !ispravnoSortiranSpil(c))
        throw std::logic_error("Neispravna lista!");
    vector<MMapa::iterator> mbrisanje;
    for(auto i=m.begin(); i!=m.end(); std::advance(i,1)) {
        shared_ptr<Cvor>p=c;
        for(int j=0; j<velicina; j++,p=p->sljedeci) {
            if(velicina>=1 && p->sljedeci->karta.boja == i->first && p->sljedeci->karta.vrijednost==i->second) {
                if(velicina>=2) {
                    bool pocetak {false};
                    if(p->sljedeci==c) pocetak=true; 
                    shared_ptr<Cvor>next=p->sljedeci->sljedeci;
                    p->sljedeci=nullptr;
                    p->sljedeci=next;
                    if(pocetak) c=p->sljedeci;
                }
                mbrisanje.push_back(i);
                velicina--;
                if(velicina==1) c->sljedeci=nullptr;
                break;
            }
        }

    }
    if(velicina==0) c=nullptr;
    for(int i=0; i<mbrisanje.size(); i++) m.erase(mbrisanje.at(i));
}

void pomjeri(shared_ptr<Cvor>&q,int broj) {
    while(broj>0 && q!=nullptr) {
        q=q->sljedeci;
        broj--;
    }
}

std::stack<pair<string,string>> IzbaciKarteRazbrajanjem(shared_ptr<Cvor>&c,const short int &r, const int &b) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int velicina=PrebrojSpil(c);
    if(velicina>52 || !validanSpil(c) || !ispravnoSortiranSpil(c)) throw std::logic_error("Neispravna lista!");
    std::stack<pair<string,string>> s;
    shared_ptr<Cvor> p=c;
    pomjeri(p,r-1);
    int brojac=b;
    while(brojac!=0) {
        short int i = r-1;
        shared_ptr<Cvor>prethodni=DajPrethodni(c,p);
        /*cout << "Brisat ce se: " << TipKarata.at(int(p->karta.boja)) << " " << p->karta.vrijednost <<endl;*/
        s.push(std::make_pair(TipKarata.at(int(p->karta.boja)),p->karta.vrijednost));
        shared_ptr<Cvor>&next=p->sljedeci;
        prethodni->sljedeci=nullptr;

        /*delete p;*/
        velicina--;
        if(velicina==0) {
            c=nullptr;
            break;
        }
        prethodni->sljedeci=next;
        if(p==c) {c=nullptr;c=next;}
        p=next;
        /*cout << "Poslije brisanja: " << TipKarata.at(int(p->karta.boja)) << " " << p->karta.vrijednost <<endl;*/
        shared_ptr<Cvor>zadnji=DajZadnji(c);
        while(i!=0) {
            pomjeri(p,1);
            i--;
        }
        brojac--;
        zadnji->sljedeci=c;
        if(velicina==1) c->sljedeci=nullptr;
    }
    gvelicina=velicina;
    return s;
}


bool Prisutan(shared_ptr<Cvor>c, pair<Boje,string> x) {
    if(!c) return false;
    shared_ptr<Cvor>p=c;
    do {
        if(p->karta.boja==x.first && p->karta.vrijednost==x.second) return true;
        p=p->sljedeci;
    } while(p!=nullptr && p!=c);
    return false;
}

void Podesi(shared_ptr<Cvor>&c, pair<Boje,string> x)
{
    shared_ptr<Cvor>novi = shared_ptr<Cvor>(new Cvor {{x.first,x.second},nullptr});
    int velicina=PrebrojSpil(c);
    if(velicina==0) {
        c=novi;
        return;
    } else if(velicina==1) {
        int i1 {},i2 {};
        for(int i=0; i<Karte.size(); i++,i1++) if(c->karta.vrijednost==Karte.at(i)) break;
        for(int i=0; i<Karte.size(); i++,i2++) if(novi->karta.vrijednost==Karte.at(i)) break;
        if(c->karta.boja<novi->karta.boja || (c->karta.boja==novi->karta.boja && i1<i2)) {
            c->sljedeci=novi;
            c->sljedeci->sljedeci=c;
        } else {
            shared_ptr<Cvor>temp=c;
            c=novi;
            c->sljedeci=temp;
            c->sljedeci->sljedeci=c;
        }
        return;
    }

    int i1 {};
    for(int i=0; i<Karte.size(); i++,i1++) if(novi->karta.vrijednost==Karte.at(i)) break;
    shared_ptr<Cvor>p=c;
    /*cout  << "Novi: " << TipKarata.at(int(novi->karta.boja)) << " " << novi->karta.vrijednost << endl;*/
    for(;;) {
        shared_ptr<Cvor>prethodni=DajPrethodni(c,p);
        shared_ptr<Cvor> zadnji=DajZadnji(c);
        int i2 {},i3 {};
        for(int i=0; i<Karte.size(); i++,i2++) if(p->karta.vrijednost==Karte.at(i)) break;
        for(int i=0; i<Karte.size(); i++,i3++) if(prethodni->karta.vrijednost==Karte.at(i)) break;
        
       /* cout  << "Trenutni: " << TipKarata.at(int(p->karta.boja)) << " " << p->karta.vrijednost << endl;
        cout  << "Prethodni: " << TipKarata.at(int(prethodni->karta.boja)) << " " << prethodni->karta.vrijednost << endl; */
        
        if(novi->karta.boja>=prethodni->karta.boja && novi->karta.boja<=p->karta.boja) {
            if((i1>=i3 || novi->karta.boja>prethodni->karta.boja) && (i1<=i2 || novi->karta.boja<p->karta.boja)) {
                prethodni->sljedeci=novi;
                novi->sljedeci=p;
                break;
            }
        }

        if(prethodni==zadnji){
            // Dva slucaja - stavljamo novi zadnji ili novi prvi
            
            //Novi zadnji
            if(novi->karta.boja>=prethodni->karta.boja && i1>i3){
                prethodni->sljedeci=novi;
                novi->sljedeci=c;
                break;
            }
            
            // Novi prvi
            else if(novi->karta.boja<p->karta.boja || (novi->karta.boja==p->karta.boja && i1<=i2)){
                prethodni->sljedeci=novi;
                c=novi;
                c->sljedeci=p;
                break;
            }
        }
        
        p=p->sljedeci;
    }

}

bool validanStack(pair<string,string> p) {
    bool validan {false};
    for(int i=0; i<TipKarata.size(); i++)
        if(p.first==TipKarata.at(i)) validan=true;
    if(!validan) return false;
    for(int i=0; i<Karte.size(); i++)
        if(p.second==Karte.at(i)) validan=true;
    if(!validan) return false;
    return true;
}

void VratiPosljednjihNKarata(shared_ptr<Cvor>&c, std::stack<pair<string,string>> s, int n) {
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    else if(n>s.size()) throw std::range_error("Nedovoljno karata u steku!");
    while(n!=0) {
        int i;
        if(!validanStack(s.top())) throw std::logic_error("Neispravne karte");
        for(i=0; i<4; i++) if(s.top().first==TipKarata.at(i)) break;
        pair<Boje,string> temp(std::make_pair(static_cast<Boje>(i),s.top().second));
        shared_ptr<Cvor>&p=c;
        if(!Prisutan(p,temp)) Podesi(p,temp);
        n--;
        s.pop();
        gvelicina++;
    }
}

int main () {
    /*int r;
    cout << "Unesite korak razbrajanja: ";
    cin >> r;
    int b;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> b;
    shared_ptr<Cvor> spil {nullptr};
   try {
        spil = KreirajSpil();
        auto q=IzbaciKarteRazbrajanjem(spil,r,b);
        cout << "U spilu trenutno ima " << gvelicina << " karata, i to:"<< endl;
        IspisSpila(spil);
        int p;
        cout << endl;
        cout << "Unesite broj karata koje zelite vratiti u spil: ";
        cin >> p;
        VratiPosljednjihNKarata(spil,q,p);
        cout << "U spilu trenutno ima " << gvelicina << " karata, i to:"<< endl;
        IspisSpila(spil);
    } catch(std::exception &ex) {
        cout << "Izuzetak: " << ex.what();
    } 

     shared_ptr<Cvor>spil {nullptr};
     try {
         spil = KreirajSpil();
         MMapa mapa {{Boje::Pik,"3"},{Boje::Pik,"4"},{Boje::Pik,"5"},{Boje::Pik,"6"},{Boje::Pik,"7"},
             {Boje::Pik,"8"},{Boje::Pik,"9"},{Boje::Pik,"10"},{Boje::Pik,"J"},{Boje::Pik,"K"},{Boje::Pik,"A"},{Boje::Pik,"Q"},
             {Boje::Tref,"2"},{Boje::Tref,"3"},{Boje::Tref,"4"},{Boje::Tref,"5"},{Boje::Tref,"6"},{Boje::Tref,"7"},{Boje::Tref,"10"},
             {Boje::Karo,"2"},{Boje::Karo,"3"},{Boje::Karo,"4"},{Boje::Karo,"5"},{Boje::Karo,"6"},{Boje::Karo,"7"},
             {Boje::Karo,"8"},{Boje::Karo,"9"},{Boje::Karo,"10"},{Boje::Karo,"J"}
         };
         IzbaciKarte(spil,mapa);
         IspisSpila(spil);
     } catch(std::exception &ex) {
         cout << "Izuzetak: " << ex.what() << endl;
     }
     if(spil!=nullptr) spil->sljedeci=nullptr;
     spil=nullptr;*/
     
    return 0;
}
