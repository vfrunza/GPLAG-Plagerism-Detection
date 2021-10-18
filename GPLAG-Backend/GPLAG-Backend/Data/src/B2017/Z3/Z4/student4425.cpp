/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>
#include <string>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje, std::string>> Spil;

Spil KreirajSpil(){
    Spil k;
    int i(0), a(0), p(0);
    Boje b;
    while(p!=4){
    while(i!=13){
        if(p==0)
        b=Boje::Pik;
        if(p==2)
        b=Boje::Herc;
        if(p==1)
        b=Boje::Tref;
        if(p==3)
        b=Boje::Karo;
        int n=a+2;
        std::string s;
        if(n>=2&&n<=10)
        s=std::to_string(n);
        if(n==11) s="J";
        if(n==12) s="Q";
        if(n==13) s="K";
        if(n==14) s="A";
        k.push_back(std::make_pair(b, s));
        a++;
        i++;
    }
    a=0;
    i=0;
    p++;}
    return k;
}

int U_int1(std::string s){
    int a;
    if(s=="2") a=2;
    else if(s=="3") a=3;
    else if(s=="4") a=4;
    else if(s=="5") a=5;
    else if(s=="6") a=6;
    else if(s=="7") a=7;
    else if(s=="8") a=8;
    else if(s=="9") a=9;
    else if(s=="10") a=10;
    else if(s=="J") a=11;
    else if(s=="Q") a=12;
    else if(s=="K") a=13;
    else{
        int i(15);
        while (1) {
            if(s==std::to_string(i)){
                a=i;
                break;
            }
            i++;
        }
    }
    return a;
}

void IzbaciKarte(Spil &n, std::multimap<Boje, std::string> &m){
    if(n.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it=n.begin(); it!=n.end(); it++){
        if(!(it->first==Boje::Pik||it->first==Boje::Tref||it->first==Boje::Herc||it->first==Boje::Karo)) throw std::logic_error("Neispravna lista!");
        if(U_int1(it->second)<2||U_int1(it->second)>14) throw std::logic_error("Neispravna lista!");
    }
    auto it1=n.begin(), it2=it1;
    it2++;
    while(it1!=n.end()){
        while(it2!=n.end()){
            if((it1->first==it2->first)&&(U_int1(it1->second)>U_int1(it2->second))) throw std::logic_error("Neispravna lista!");
            it2++;
        }
        it1++;
        it2=it1;
        if(it2==n.end()) break;
        it2++;
        if(it2==n.end()) break;
    }
    it1=n.begin();
    it2=it1;
    it2++;
    int i(0);
    while(it2!=n.end()){
        if(it1->first!=it2->first){
            i++;
            if(i==4) throw std::logic_error("Neispravna lista!");
            if(it1->first==Boje::Tref&&it2->first==Boje::Pik) throw std::logic_error("Neispravna lista!");
            if(it1->first==Boje::Herc&&(it2->first==Boje::Pik||it2->first==Boje::Tref)) throw std::logic_error("Neispravna lista!");
            if(it1->first==Boje::Karo&&it2->first!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        }
        it1++;
        it2++;
    }
    for(auto it=n.begin(); it!=n.end(); it++){
        for(auto ite=m.begin(); ite!=m.end(); ite++){
            if((it->first==ite->first)&&(it->second==ite->second)){
                it=n.erase(it);
                ite=m.erase(ite);
            }
        }
    }
}

int U_int(std::string s){
    int a;
    if(s=="2") a=2;
    else if(s=="3") a=3;
    else if(s=="4") a=4;
    else if(s=="5") a=5;
    else if(s=="6") a=6;
    else if(s=="7") a=7;
    else if(s=="8") a=8;
    else if(s=="9") a=9;
    else if(s=="10") a=10;
    else if(s=="J") a=11;
    else if(s=="Q") a=12;
    else if(s=="K") a=13;
    else if(s=="A") a=14;
    else{
        int i(15);
        while (1) {
            if(s==std::to_string(i)){
                a=i;
                break;
            }
            i++;
        }
    }
    return a;
}

std::string U_string(int a){
    std::string s;
    int i(0);
     if(a>=2&&a<=10)
        {s=std::to_string(a);i=1;}
        if(a==11) {s="J";i=1;}
        if(a==12) {s="Q";i=1;}
        if(a==13) {s="K";i=1;}
        if(a==14) {s="A";i=1;}
        if(i==0) s=std::to_string(a);
    return s;
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &n, short int &r, const int &b){
    if(r>52||r<1||b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(n.size()>52)  throw std::logic_error("Neispravna lista!");
    auto it1=n.begin(), it2=it1;
    it2++;
    while(it1!=n.end()){
        while(it2!=n.end()){
            if((it1->first==it2->first)&&(U_int(it1->second)>U_int(it2->second))) throw std::logic_error("Neispravna lista!");
            it2++;
        }
        it1++;
        it2=it1;
        if(it2==n.end()) break;
        it2++;
        if(it2==n.end()) break;
    }
    it1=n.begin();
    it2=it1;
    it2++;
    int i(0);
    while(it2!=n.end()){
        if(it1->first!=it2->first){
            i++;
            if(i==4) throw std::logic_error("Neispravna lista!");
            if(it1->first==Boje::Tref&&it2->first==Boje::Pik) throw std::logic_error("Neispravna lista!");
            if(it1->first==Boje::Herc&&(it2->first==Boje::Pik||it2->first==Boje::Tref)) throw std::logic_error("Neispravna lista!");
            if(it1->first==Boje::Karo&&it2->first!=Boje::Karo) throw std::logic_error("Neispravna lista!");
        }
        it1++;
        it2++;
    }
    for(auto it=n.begin(); it!=n.end(); it++){
        if(!(it->first==Boje::Pik||it->first==Boje::Tref||it->first==Boje::Herc||it->first==Boje::Karo)) throw std::logic_error("Neispravna lista!");
        if(U_int(it->second)>14||U_int(it->second)<2) throw std::logic_error("Neispravna lista!");
    }
    std::queue<std::pair<std::string, std::string>> skup_par;
    short int korak(r); // k1(r);
    int br(b), pom(0);
    auto it=n.begin();
    while(br>0&&n.size()>0){
        while(pom!=korak-1){
            pom++;
            it++;
            if(it==n.end())
            it=n.begin();
        }
         std::string s;
                if(it->first==Boje::Pik) s="Pik";
                if(it->first==Boje::Tref) s="Tref";
                if(it->first==Boje::Herc) s="Herc";
                if(it->first==Boje::Karo) s="Karo";
                skup_par.push(std::make_pair(s, it->second));
        it=n.erase(it);
        if(n.size()==0) break;
        if(it==n.end()){
            it=n.begin();}
        pom=0;
        br--;
    }
    return skup_par;
}

void Sortiraj_Spil(Spil &n){
    auto it=n.begin(), ite=it;
    ite++;
    Boje b;
    std::string s;
    while(it!=n.end()){
        while(ite!=n.end()){
            if((ite->first==it->first)&&(U_int(it->second)>U_int(ite->second))){
                b=it->first;
                s=it->second;
                it->first=ite->first;
                it->second=ite->second;
                ite->first=b;
                ite->second=s;
            }
            ite++;
        }
        it++;
        ite=it;
        if(ite==n.end()) break;
        ite++;
        if(ite==n.end()) break;
    }
}
   void Sortiraj_Spil_Po_Boji(Spil &n){
    auto it=n.begin(), ite=it;
    ite++;
    Boje b;
    std::string s;
    while(it!=n.end()){
        while(ite!=n.end()){
            if(ite->first<it->first){
                b=it->first;
                s=it->second;
                it->first=ite->first;
                it->second=ite->second;
                ite->first=b;
                ite->second=s;
            }
            ite++;
        }
        it++;
        ite=it;
        if(ite==n.end()) break;
        ite++;
        if(ite==n.end()) break;
    }
}
    
void VratiPrvihNKarata(Spil &n, std::queue<std::pair<std::string, std::string>> &q, int m){
    if(m<0) throw std::domain_error("Broj n je besmislen!");
    if(m>q.size()) throw std::range_error("Nedovoljno karata u redu!");
     if(n.size()>52)  throw std::logic_error("Neispravna lista!");
     auto it1=n.begin(), it2=it1;
     it2++;
     while(it1!=n.end()){
         while(it2!=n.end()){
             if((it1->first==it2->first)&&(U_int(it1->second)>U_int(it2->second))) throw std::logic_error("Neispravna lista!");
             it2++;
         }
         it1++;
         it2=it1;
         if(it2==n.end()) break;
         it2++;
         if(it2==n.end()) break;
     }
     it1=n.begin();
     it2=it1;
     it2++;
     int i(0);
     while(it2!=n.end()){
         if(it1->first!=it2->first){
             i++;
             if(i==4) throw std::logic_error("Neispravna lista");
             if(it1->first==Boje::Tref&&it2->first==Boje::Pik) throw std::logic_error("Neispravna lista!");
             if(it1->first==Boje::Herc&&(it2->first==Boje::Tref||it2->first==Boje::Pik)) throw std::logic_error("Neispravna lista!");
             if(it1->first==Boje::Karo&&it2->first!=Boje::Karo) throw std::logic_error("Neispravna lista");
         }
         it2++;
         it1++;
     }
        for(auto it=n.begin(); it!=n.end(); it++){
        if(!(it->first==Boje::Pik||it->first==Boje::Tref||it->first==Boje::Herc||it->first==Boje::Karo)) throw std::logic_error("Neispravna lista!");
        if(U_int(it->second)>14||U_int(it->second)<2) throw std::logic_error("Neispravna lista!");
    }
    while(m!=0){
        int brojac(0);
        if(U_int(q.front().second)>14||U_int(q.front().second)<2) throw std::logic_error("Neispravne karate!");
        if(!(q.front().first=="Pik"||q.front().first=="Tref"||q.front().first=="Herc"||q.front().first=="Karo")) throw std::logic_error("Neispravne karate!");
            std::string s1(q.front().second);
            auto it=n.begin();
            if(n.size()==0){
                while(!q.empty()){
                if(U_int(q.front().second)>14||U_int(q.front().second)<2) throw std::logic_error("Neispravne karate!");
                if(!(q.front().first=="Pik"||q.front().first=="Herc"||q.front().first=="Tref"||q.front().first=="Karo")) throw std::logic_error("Neispravne karate!");
                if(q.front().first=="Pik")
                n.push_front(std::make_pair(Boje::Pik, q.front().second));
                if(q.front().first=="Herc")
                n.insert(it, std::make_pair(Boje::Herc, q.front().second));
                if(q.front().first=="Tref")
                n.insert(it, std::make_pair(Boje::Tref, q.front().second));
                if(q.front().first=="Karo")
                n.push_front(std::make_pair(Boje::Karo, q.front().second));
                q.pop();
                m--;
                it++;
                if(m==0)break;}
                if(m==0){Sortiraj_Spil_Po_Boji(n);
                Sortiraj_Spil(n); continue;}
            }else{
            if(q.front().first=="Pik"){
                if(it->first!=Boje::Pik) {n.push_front(std::make_pair(Boje::Pik, q.front().second)); q.pop(); m--; continue;}
        while(it!=n.end()&&U_int(it->second)<U_int(s1)&&it->first!=Boje::Pik){
            if(it->first==Boje::Pik&&U_int(it->second)==U_int(q.front().second)){
                brojac++;
                break;
            }
            it++; 
        }
        if(brojac>0){
            q.pop();
            continue;
        }
            if(q.front().first!="Tref"&&q.front().first!="Herc"&&q.front().first!="Karo")
                n.insert(it, std::make_pair(it->first, q.front().second)); 
            }
            if(q.front().first=="Tref"){
            while(it->first<=Boje::Tref) it++;
            if(it->first==Boje::Herc||it->first==Boje::Karo){
                 n.insert(it, std::make_pair(Boje::Tref, q.front().second));
                 m--;
                 q.pop();
                 continue;
            }
        while(it!=n.end()&&U_int(it->second)<U_int(s1)&&it->first!=Boje::Tref){
             if(it->first==Boje::Tref&&U_int(it->second)==U_int(q.front().second)){
                brojac++;
                break;
            }
            it++; 
        }
        if(brojac>0){
            q.pop();
            continue;
        }
         if(q.front().first!="Pik"&&q.front().first!="Herc"&&q.front().first!="Karo")
                n.insert(it, std::make_pair(it->first, q.front().second));
            }
            if(q.front().first=="Herc"){
            while(it->first<=Boje::Herc) it++;
             if(it->first==Boje::Karo){
                 n.insert(it, std::make_pair(Boje::Herc, q.front().second));
                 m--;
                 q.pop();
                 continue;
            }
        while(it!=n.end()&&U_int(it->second)<U_int(s1)){
             if(it->first==Boje::Herc&&U_int(it->second)==U_int(q.front().second)){
                brojac++;
                break;
            }
            it++; 
        }
        if(brojac>0){
            q.pop();
            continue;
        }
         if(q.front().first!="Tref"&&q.front().first!="Pik"&&q.front().first!="Karo")
                n.insert(it, std::make_pair(it->first, q.front().second));
            }
            if(q.front().first=="Karo"){
                for(auto iter=n.begin(); iter!=n.end(); iter++){
                     if(iter->first==Boje::Karo&&U_int(iter->second)==U_int(q.front().second)){
                brojac++;
                break;
            }
                }
                if(brojac>0){
                    q.pop();
                    continue;
                }
                 n.push_back(std::make_pair(Boje::Karo, q.front().second));
                 m--;
                 q.pop();
                 continue;}
            q.pop();
            if(q.size()==0) break;
        m--; 
    }}
    Sortiraj_Spil(n);
}

int main ()
{
    Spil spil(KreirajSpil());
    try{
        int o(0);
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        std::queue<std::pair<std::string, std::string>> q(IzbaciKarteRazbrajanjem(spil, r, b));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
         for(auto it=spil.begin(); it!=spil.end(); it++){
            std::cout<<"Pik: ";
            while(it->first==Boje::Pik){
                std::cout<<it->second<<" ";
                it++;
                o++;
                if(o==spil.size()) break;
            }
            std::cout<<std::endl<<"Tref: ";
            while(it->first==Boje::Tref){
                std::cout<<it->second<<" ";
                it++;
                o++;
                if(o==spil.size()) break;
            }
            std::cout<<std::endl<<"Herc: ";
            while(it->first==Boje::Herc){
                std::cout<<it->second<<" ";
                it++;
                o++;
                if(o==spil.size()) break;
            }
            std::cout<<std::endl<<"Karo: ";
            while(it->first==Boje::Karo){
                std::cout<<it->second<<" ";
                it++;
                o++;
                if(o==spil.size()) break;
            }
            if(o==spil.size()) break;
        }
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int m;
        std::cin>>m;
      try{  
            VratiPrvihNKarata(spil, q, m);
            std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
            o=0;
            for(auto ite=spil.begin(); ite!=spil.end(); ite++){
                std::cout<<"Pik: ";
                while(ite->first==Boje::Pik){
                std::cout<<ite->second<<" ";
                ite++;
                o++;
                if(o==spil.size()) break;
            }
           std::cout<<std::endl<<"Tref: ";
            while(ite->first==Boje::Tref){
                std::cout<<ite->second<<" ";
                ite++;
                o++;
                if(o==spil.size()) break;
            }
            std::cout<<std::endl<<"Herc: ";
            while(ite->first==Boje::Herc){
                std::cout<<ite->second<<" ";
                ite++;
                o++;
                if(o==spil.size()) break;
            }
            std::cout<<std::endl<<"Karo: ";
            while(ite->first==Boje::Karo){
                std::cout<<ite->second<<" ";
                ite++;
                o++;
                if(o==spil.size()) break;
            }
            if(o==spil.size()) break;
        }}
        catch(std::domain_error iz1){
        std::cout<<"Izuzetak: "<<iz1.what();
    }
    catch(std::logic_error iz){
        std::cout<<"Izuzetak: "<<iz.what();
    }
    catch(std::range_error iz2){
        std::cout<<"Izuzetak: "<<iz2.what();
    }
   }
    catch(std::logic_error iz){
        std::cout<<"Izuzetak: "<<iz.what();
    }
	return 0;
}