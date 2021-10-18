#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <string>
#include <iterator>


typedef std::vector<std::string> vekstring;

std::vector<int> BrojDjece(vekstring v, int broj_timova)
{
    int broj_clanova_tima=v.size()/broj_timova;
    std::vector<int> clanovi_tima;
    clanovi_tima.resize(broj_timova);
    int velicina=v.size();
    for(int i=0; i<broj_timova; i++) {
        clanovi_tima[i]=broj_clanova_tima;
        if(velicina%broj_timova!=0) {
            clanovi_tima[i]=broj_clanova_tima+1;
            velicina--;
        }
    }
    return clanovi_tima;
}

int KolikoSlovaImaIme(std::string s)
{
    unsigned int brojac(0);
    for(unsigned int i(0); i<s.size(); i++) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9'))
            brojac++;
    }
    return brojac;
}


void IsprazniSet(std::set<std::string> &skup)
{
    auto it=skup.begin();
    while(skup.begin()!=skup.end()) {
        it=skup.erase(it);

    }
}


std::vector<std::set<std::string>> Razvrstavanje(  vekstring v, int broj_timova)
{
    if(broj_timova<=0 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    struct Dijete {
        std::string ime;
        Dijete * sljedeci;
    }
    std::vector<std::set<std::string>> konacno;
    std::set<std::string> tim;
    std::vector<int> vek=BrojDjece(v, broj_timova); //vektor ciji su elementi broj clanova svakog tima

    //kreiranje kruzne liste
    Dijete*prvi(nullptr),*poslednji,*novi;
    for(int i=0; i<v.size(); i++) {
        novi=new Dijete;
        novi->ime=v[i];    //kopiranje imena u listu
        novi->sljedeci=nullptr;
        if(prvi==nullptr)prvi=novi;
        else poslednji->sljedeci=novi;
        poslednji=novi;
/*
        for(Dijete *p=prvi; p!=poslednji; p=p->sljedeci) {
            if(p==poslednji) p->sljedeci=prvi;
        }*/

        int brojac=v.size();//brojac djece

        int br_zadnjeg_u_timu(0);
        int br(0);
        Dijete prvo;
        for(int i=0; i<broj_timova; i++) {

            int trenutni_tim=vek[i];

            for(int j=0; j<trenutni_tim; j++) {
                if(brojac==0) break;

                if(i==0 && j==0) {
                    tim.insert(prvo.ime);
                    br=KolikoSlovaImaIme(prvo.ime);
                    j++;

                    //brisanje imena iz liste
                    Dijete pom;
                    
                    brojac--;
                    if(j==vek[i])break;
                }
                if(i==0) {
                    for(int k=0; k<br-1; k++) {
                        if(p==poslednji) p->sljedeci=prvi;
                        p=p->sljedeci;
                        if(p==poslednji) p->sljedeci=prvi;
                    }
                } else {
                    for(int k=0; k<br_zadnjeg_u_timu-1; k++) {
                        if(*p==poslednji) p->sljedeci=prvi;
                        p=p->sljedeci;
                        if(*p==poslednji) p->sljedeci=prvi;
                    }

                }

                br=KolikoSlovaImaIme(p->ime);
                tim.insert(p->ime);
                br_zadnjeg_u_timu=br;
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
                brojac--;
            }
            konacno.push_back(tim);
            IsprazniSet(tim);
            if(brojac==0)break;
        }

        return konacno;

    }

    void IspisiSkupSaZarezima(std::set<std::string> skup) {
        int mjesto(0);
        for(auto it=skup.begin(); it!=skup.end(); it++) {
            if( mjesto==skup.size()-1) std::cout<<*it;
            else std::cout<<*it<<", ";
            mjesto++;
        }
    }


    int main () {

        int n;
        std::cout<<"Unesite broj djece: ";
        std::cin>>n;

        std::cout<<"Unesite imena djece: ";
        std::cin.ignore(1000, '\n');
        vekstring imena;
        for(int i=0; i<n; i++) {
            std::string s;
            std::getline (std::cin, s);
            imena.push_back(s);
        }
        std::cout<<"\nUnesite broj timova: ";
        int broj_timova;
        std::cin>>broj_timova;
        try {
            auto v(Razvrstavanje(imena,broj_timova));

            for(int i=0; i<v.size(); i++) {
                std::cout<<"Tim "<<i+1<<": ";
                IspisiSkupSaZarezima(v[i]);
                std::cout<<std::endl;
            }
        } catch(std::logic_error e) {
            std::cout<<e.what();
        }
        return 0;
    }



    /*
    struct Dijete{
        std::string element;
        Dijete*veza;
    };
    */
    /*
       //kreiranje kruzne liste
       Dijete*prvi(nullptr),*poslednji,*novi;
       for(int i=0;i<v.size();i++){
       novi=new Dijete;
       novi->element=v[i];    //kopiranje imena u listu
       novi->veza=nullptr;
       if(prvi==nullptr)prvi=novi;
       else poslednji->veza=novi;
       poslednji=novi;
       poslednji->veza=prvi->veza;
       }
      */