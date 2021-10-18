/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stdexcept>
enum class Boje
{
    Pik, Tref, Herc, Karo
};
std::list<std::pair <Boje,std::string>> KreirajSpila()
{
    std::list<std::pair <Boje,std::string>> lista;

    std::vector<std::string> v {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};


    std::pair<Boje,std::string> par;
    for(int j=0; j<13; j++) {
        par=std::make_pair(Boje::Pik,v[j]);
        lista.push_back(par);
    }

    std::pair<Boje,std::string> par1;
    for(int j=0; j<13; j++) {
        par1=std::make_pair(Boje::Tref,v[j]);
        lista.push_back(par1);
    }
    std::pair<Boje,std::string> par2;
    for(int j=0; j<13; j++) {
        par2=std::make_pair(Boje::Herc,v[j]);
        lista.push_back(par2);
    }
    std::pair<Boje,std::string> par3;
    for(int j=0; j<13; j++) {
        par3=std::make_pair(Boje::Karo,v[j]);
        lista.push_back(par3);
    }


    return lista;

}
void IzbaciKarte(std::list<std::pair <Boje,std::string>> &spil,std::multimap<Boje,std::string> &mm )
{
    for(auto x=spil.begin(); x!=spil.end(); x++) {
        for(auto it=mm.begin(); it!=mm.end(); it++) {
            if(x->first==it->first && x->second==it->second) {
                x=spil.erase(x);
                mm.erase(it);
                if(mm.size()==0 || spil.size()==0)break;
            } else continue;
        }

    }
} 
std::queue<std::pair<Boje,std::string>>IzbaciKarteRazbrajanjem(std::list<std::pair <Boje,std::string>> &spil,const short int &r,const int &b)
{
    if(r>52 || r<1 ||b<0) throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<Boje,std::string>> dek;
    int k=1;
    int dodatni=r;
    int bio=0;
    auto it=spil.begin();
    auto ot=spil.end();
    int br=r;
    --ot;

    for(;;) {

        if(k==br) {
            dek.push(*it);
            it=spil.erase(it);
            br=br+dodatni-1;
            bio++;
            --it;

        } else if(bio+1==b+1) break;
        else  k++;
        if(it==ot) it=spil.begin();
        else it++;
    }


    return dek;
}
void VratiPrvihNKarata(std::list<std::pair <Boje,std::string>> &spil,std::queue<std::pair<Boje,std::string>> & red,int n)
{


    if(n<0||n>52 ) throw std::logic_error("Broj n je besmislen!");

    if(red.size()<n) throw std::range_error("Nedovoljno karata u redu!");

    int duzina;
    int duzina1;
    auto it=spil.begin();
    auto ot=spil.end();
    --ot;
    int p=0,p1=0,t=0,t1=0,h=0,h1=0,k=0,k1=0;
    while(n!=0) {
        if(n==0) break;
        p=0;
        p1=0;
        t=0;
        t1=0;
        h=0;
        h1=0;
        k=0;
        k1=0;
        if(red.front().first==Boje::Pik)p=1;
        else if(red.front().first==Boje::Tref)t=1;
        else if(red.front().first==Boje::Herc)h=1;
        else if(red.front().first==Boje::Karo)k=1;


        if( red.front().second=="2") duzina=2;
        else if(red.front().second=="3") duzina=3;
        else if( red.front().second=="4") duzina=4;
        else if(red.front().second=="5") duzina=5;
        else if( red.front().second=="6") duzina=6;
        else if(red.front().second=="7") duzina=7;
        else if(red.front().second=="8") duzina=8;
        else if( red.front().second=="9") duzina=9;
        else if(red.front().second=="10") duzina=10;
        else if( red.front().second=="J") duzina=11;
        else if(red.front().second=="Q") duzina=12;
        else if( red.front().second=="K") duzina=13;
        else if( red.front().second=="A") duzina=14;

        if(it->first==Boje::Pik) p1=1;
        else if(it->first==Boje::Tref) t1=1;
        else if(it->first==Boje::Herc) h1=1;
        else if(it->first==Boje::Karo) k1=1;

        if(it->second=="2") {
            duzina1=2;
            if(duzina==14 ) duzina=1;
        } else if( it->second=="3") duzina1=3;
        else if(it->second=="4") duzina1=4;
        else if(it->second=="5") duzina1=5;
        else if(it->second=="6") duzina1=6;
        else if(it->second=="7") duzina1=7;
        else if( it->second=="8") duzina1=8;
        else if(it->second=="9") duzina1=9;
        else if( it->second=="10") duzina1=10;
        else if( it->second=="J") duzina1=11;
        else if( it->second=="Q") duzina1=12;
        else if( it->second=="K") duzina1=13;
        else if( it->second=="A") duzina1=14;

        if((p==1 &&p1==1) || (t==1 && t1==1) ||(h==1 && h1==1) || (k==1 && k1==1) || (p==1 && t1==1)||(t==1 && h1==1) || (h==1 && k1==1) || (k==1 && p1==1)) {
            if(duzina==duzina1-1) {
                spil.insert(it,red.front());
                red.pop();
                n--;
            }

        }
        if(it==ot) it=spil.begin();
        else it++;

    }
}



int main ()
{
    try {
        std::cout<<"Unesite korak razbrajanja: ";
        short int broj;
        std::cin>>broj;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int broj1;
        std::cin>>broj1;

        short int r=broj;
        int b=broj1;

        std::list<std::pair<Boje,std::string>> lista;
        lista=KreirajSpila();


        std::queue<std::pair<Boje,std::string>> dek;


        dek=IzbaciKarteRazbrajanjem(lista,r,b);


        std::cout<<"U spilu trenutno ima "<<lista.size()<<" karata, i to:";
        std::cout <<std::endl<<"Pik: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Pik)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Tref: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Tref)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Herc: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Herc)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Karo: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Karo)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >>n;

        VratiPrvihNKarata(lista,dek,n);



        std::cout<<"U spilu trenutno ima "<<lista.size()<<" karata, i to:";
        std::cout <<std::endl<<"Pik: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Pik)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Tref: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Tref)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Herc: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Herc)std::cout <<x.second<<" ";
        }
        std::cout <<std::endl<<"Karo: ";
        for(std::pair<Boje,std::string> x:lista) {
            if(x.first==Boje::Karo)std::cout <<x.second<<" ";
        }

    } catch(std::domain_error izuzetak) {
        std::cout <<"Izuzetak: "<<izuzetak.what();
        return 0;
    } catch(std::logic_error izuzetak) {
        std::cout <<"Izuzetak: "<<izuzetak.what();
        return 0;

    } catch(std::range_error izuzetak) {
        std::cout <<"Izuzetak: "<<izuzetak.what();
        return 0;
    }

    return 0;
}
