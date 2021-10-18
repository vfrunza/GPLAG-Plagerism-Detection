#include <iostream>
#include<vector>//   ZA IMENA KARATA
#include<stdexcept>
#include<map>
#include<stack>
#include<memory>

std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
enum  Boje {Pik, Tref, Herc, Karo};
struct Karta{
    Boje boja;
    std::string ime;
};
struct Cvor {
 Karta karta;
 std::shared_ptr<Cvor> veza;
};

void Odvezi(std::shared_ptr<Cvor>);

int sizee(std::shared_ptr<Cvor>p){
    int  a=0;
    bool b=true;
    auto pocetak(p);
    if(p==nullptr||p->veza==nullptr)return 0;
    while(p!=pocetak||b!=false){
        p=p->veza;
        b=false;
        a++;
    }
    return a;
}
void  UnistiSpil(std::shared_ptr<Cvor>spil){
    Odvezi(spil);
   //REKT
}
void ispisispil(std::shared_ptr<Cvor>it){
    auto pocetak(it);
    if(it==nullptr){std::cout << "Prazan spil" << std::endl;return;}
    std::cout << "U spilu trenutno ima "<<sizee(it)<<" karata, i to: " << std::endl;
    std::cout << "Pik: " ;
    while(it->karta.boja==Pik){std::cout << it->karta.ime<<" ";it=it->veza;}
     std::cout << "\nTref: " ;
    while(it->karta.boja==Tref){std::cout << it->karta.ime<<" ";it=it->veza;}
    std::cout << "\nHerc: " ;
    while(it->karta.boja==Herc){std::cout << it->karta.ime<<" ";it=it->veza;}
    std::cout << "\nKaro: " ;
    while(it->karta.boja==Karo){std::cout << it->karta.ime<<" ";it=it->veza;if(it==pocetak)break;}
    std::cout << std::endl;
}

std::shared_ptr<Cvor> KreirajSpil(){
std::shared_ptr<Cvor>prvi(nullptr); std::shared_ptr<Cvor>prethodni;
    Boje  bo=Pik;
    for(int i=0;i<52;i++){
        if(i>12)bo=Tref;
        if(i>25)bo=Herc;
        if(i>38)bo=Karo;
        std::string imm=v[i%13];
        auto novi(std::make_shared<Cvor>( Cvor{{bo,imm},nullptr}));
        if(!prvi)prvi=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    prethodni->veza=prvi;
   return prvi;
}
bool dobro(std::string a,std::string b){
      if(a==b)return false;
    int i,j;
    for(i=0;i<v.size();i++){
        if(a==v[i])break;
    }
    for(j=0;j<v.size();j++){
        if(b==v[j])break;
    }
    return i<j;
}
bool je_li_validan(std::shared_ptr<Cvor>p){
    auto prije(p);
    auto temp(p);
    p=p->veza;
    for(int i=1;i<sizee(temp);i++){
        if(prije->karta.boja>p->karta.boja)return false;
        prije=prije->veza;
        p=p->veza;
    }
    p=temp;
    prije=temp;
    p=p->veza;
   while (p->karta.boja==Pik){
       if(!(dobro(prije->karta.ime,p->karta.ime)))return false;
       prije=prije->veza;
       p=p->veza;
   }prije=p;
   p=p->veza;
    while (p->karta.boja==Tref){
       if(!(dobro(prije->karta.ime,p->karta.ime)))return false;
       prije=prije->veza;
       p=p->veza;
   }
   prije=p;
   p=p->veza;
    while (p->karta.boja==Herc){
       if(!(dobro(prije->karta.ime,p->karta.ime)))return false;
       prije=prije->veza;
       p=p->veza;
   }
   prije=p;
   p=p->veza;
    while (p->karta.boja==Karo){
       if(!(dobro(prije->karta.ime,p->karta.ime)))return false;
       prije=prije->veza;
       p=p->veza;
   }
    return true;
}
std::shared_ptr<Cvor> izbrisi(std::shared_ptr<Cvor>&p, std::shared_ptr<Cvor>prije,std::shared_ptr<Cvor>pocetak){
    if(sizee(p)==2){
        pocetak=prije;
        prije->veza=nullptr;
        auto d(p);
        p=pocetak;
    }else if(p->veza==nullptr){
        pocetak=nullptr;
       
    }
    else if(p==pocetak){
        auto d(p);
        p=p->veza;
        pocetak=p;
       
        prije->veza=p;
    }
    else{
         auto d(p);
        p=p->veza;
        
        prije->veza=p;
       
    }
    return pocetak;
}
void IzbaciKarte(std::shared_ptr<Cvor>&temp,std::multimap<Boje, std::string> mapa){
   
    if(sizee(temp)>52){UnistiSpil(temp);throw std::logic_error{"Neispravna lista!"};}
    if(!(je_li_validan(temp))){UnistiSpil(temp);throw std::logic_error{"Neispravna lista!"};}
    auto p(temp);
    int broj=mapa.size();
    auto it(mapa.begin());
    for(int i=0;i<broj;i++){
        p=temp;
        auto prije(p);
        p=p->veza;
        bool a=false;
        for(int j=0;j<sizee(p);j++){
            if(p->karta.boja==it->first&&p->karta.ime==it->second){
               temp=izbrisi(p,prije,temp);it=mapa.erase(it);a=true;break;
            }
            p=p->veza;
            prije=prije->veza;
        }if(a==true)continue;
            it++;
    }
}
bool je_li_validan_stek(std::stack<std::pair<Boje,std::string>> stek){
    auto copy(stek);
    int broj(stek.size());
    for(int i=0;i<broj;i++){
        if(stek.top().first!=Pik&&stek.top().first!=Herc&&stek.top().first!=Karo&&stek.top().first!=Tref)return false;
        stek.pop();
    }stek=copy;
    for(int j=0;j<broj;j++){
        bool a=false;
        for(int i=0;i<v.size();i++){
            if(stek.top().second==v[i])a=true;
        }if(a==false)return false;
        stek.pop();
    }
    return true;
}
std::stack<std::pair<Boje,std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor>&p,const int &r,const int &n){
     if(r<1||r>52||n<1){UnistiSpil(p);throw std::logic_error{"Neispravni elementi za izbacivanje!"};}
    if(sizee(p)>52){UnistiSpil(p);throw std::logic_error{"Neispravna lista!"};}
    if(!(je_li_validan(p))){UnistiSpil(p);throw std::logic_error{"Neispravna lista!"};}
    auto it(p);
    auto prije(p);
    std::stack<std::pair<Boje,std::string>> stek;
    
    for(int i=0;i<52;i++){
        prije=prije->veza;
        if(prije->veza==it)break;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<r;j++){
            it=it->veza;
            prije=prije->veza;
        }stek.push({it->karta.boja,it->karta.ime});
        p=izbrisi(it,prije,p);
        if(p==nullptr)break;
    }
    return stek;
}
void ubaci(std::shared_ptr<Cvor>p,std::shared_ptr<Cvor>prije,std::shared_ptr<Cvor>novi){
    novi->veza=p;
    prije->veza=novi;
}
void zamjeni(std::shared_ptr<Cvor>&p,std::shared_ptr<Cvor>&prije,std::shared_ptr<Cvor>&poslije,std::shared_ptr<Cvor>&p2,std::shared_ptr<Cvor>&prije2,std::shared_ptr<Cvor>&poslije2){
    prije->veza=p2;
    p2->veza=poslije;
    prije2->veza=p;
    p->veza=poslije2;
}
bool prije(std::string a,std::string b){
    int i,j;
    for( i=0;i<v.size();i++){
        if(v[i]==a)break;
    }
     for( j=0;j<v.size();j++){
        if(v[j]==b)break;
    }
    return i<j;
}

std::shared_ptr<Cvor>nadji(std::shared_ptr<Cvor>p){
    auto min(p);
    for(int i=0;i<sizee(p);i++){
        if(p->karta.boja<=min->karta.boja)if(prije(p->karta.ime,min->karta.ime))min=p;
    p=p->veza;
    }
    return min;
}
void VratiPosljednjihNKarata(std::shared_ptr<Cvor>&p,std::stack<std::pair<Boje,std::string>> stek,int n){
        if(n<0){UnistiSpil(p);throw std::domain_error {"Broj n je besmislen!"};}
       if(n>stek.size()){UnistiSpil(p);throw std::range_error{"Nedovoljno karata u redu!"};}
       if(!(je_li_validan(p))){UnistiSpil(p);throw std::logic_error{"Neispravna lista!"};}
       if(!je_li_validan(p)){UnistiSpil(p);throw std::logic_error{"Neispravna lista!"};}
       if(!je_li_validan_stek(stek)){UnistiSpil(p);throw std::logic_error{"Neispravne karte!"};}
       auto it(p);
       

       for(int i=0;i<n;i++){
         
           bool jest=false;
           auto c(p);
           for(int j=0;j<sizee(p);j++){
               if(stek.top().first==c->karta.boja&&stek.top().second==c->karta.ime){jest==true;break;}
               c=c->veza;
           }if(jest==true){stek.pop();continue;}
           auto novi(std::make_shared<Cvor>(Cvor{{stek.top().first,stek.top().second},nullptr}));//auto novi(std::make_shared<Cvor>(new Cvor{stek.top().first,stek.top().second},nullptr})); //auto novi(std::make_shared<Cvor>(new Cvor{stek.top().first,stek.top().second},nullptr));
           it=p;
           auto prije(it);
         for(int i=0;i<52;i++){
         prije=prije->veza;
            if(prije->veza==it)break;
         }Boje rekt=it->karta.boja;
           while(it->karta.boja<stek.top().first){prije=prije->veza;it=it->veza;}
           while(dobro(stek.top().second,it->karta.ime)==false){prije=prije->veza;it=it->veza;}
           ubaci(it,prije,novi);
           stek.pop();
           p=nadji(p);
       }
       
}
void Odvezi(std::shared_ptr <Cvor> p){
    auto sde(sizee(p));
    for(int i=0;i<sde;i++){
        auto d(p);
        p=p->veza;
        d->veza=nullptr;
    }
}
int main(){
     try{int n;
    auto spil(KreirajSpil());
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> n;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int m;
    std::cin >> m;
    //std::multimap<Boje, std::string> mapa{{Pik,std::string("2")},{Pik,std::string("3")},{Pik,std::string("4")},{Pik,std::string("5")}};
   // IzbaciKarte(spil,mapa);
    //ispisi(spil);
    auto red(IzbaciKarteRazbrajanjem(spil,n,m));
    ispisispil(spil);
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    int e;
    std::cin >> e;
    VratiPosljednjihNKarata(spil,red,e);
    ispisispil(spil);
    Odvezi(spil);
    }catch(std::domain_error er){
        std::cout << "Izuzetak: "<<er.what() << std::endl;
       // UnistiSpil(spil);
    }catch(std::logic_error er){
        std::cout << "Izuzetak: "<<er.what() << std::endl;
        //UnistiSpil(spil);
    }catch(std::range_error er){
        std::cout << "Izuzetak: "<<er.what() << std::endl;
        //UnistiSpil(spil);
    }
    
}
















