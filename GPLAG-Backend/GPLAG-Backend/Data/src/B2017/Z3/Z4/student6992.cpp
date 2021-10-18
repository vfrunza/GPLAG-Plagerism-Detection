/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <stdexcept>
enum class Boje
{
    Pik,Tref,Herc,Karo
};
std::list<std::pair<Boje,std::string>> KreirajSpil()
{
    std::list<std::pair<Boje,std::string>>Spil;
    std::vector<std::string> v {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0; i<v.size(); i++) {
        std::pair<Boje,std::string> temp;
        temp=std::make_pair(Boje::Pik,v.at(i));
        Spil.push_back(temp);
    }
    for(int i=0; i<v.size(); i++) {
        std::pair<Boje,std::string> temp;
        temp=make_pair(Boje::Tref,v.at(i));
        Spil.push_back(temp);
    }
    for(int i=0; i<v.size(); i++) {
        std::pair<Boje,std::string> temp;
        temp=make_pair(Boje::Herc,v.at(i));
        Spil.push_back(temp);
    }
    for(int i=0; i<v.size(); i++) {
        std::pair<Boje,std::string> temp;
        temp=make_pair(Boje::Karo,v.at(i));
        Spil.push_back(temp);
    }
    return Spil;

}
void IzbaciKarte (std::list<std::pair<Boje,std::string>> &Spil, std::multimap<Boje,std::string> &izbaci)
{
    for(auto iT=Spil.begin(); iT!=Spil.end(); iT++) {
        for(auto it=izbaci.begin(); it!=izbaci.end(); it++) {
            if(iT->first==it->first && iT->second==it->second) {
                iT=Spil.erase(iT);
                izbaci.erase(it);
                if(izbaci.size()==0||Spil.size()==0) break;

            } else continue;
        }
        if(izbaci.size()==0||Spil.size()==0) break;
    }
}
std::queue<std::pair<Boje,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &Spil,const short int &r, const int &b)
{
    if(r<1||r>52||b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<Boje,std::string>> red ;
    int brojac2=b;
    if(Spil.size()>52) throw std::logic_error("Neispravna lista!");
    
    for(;;) {
        // for(auto it=Spil.begin();it!=Spil.end();it++){
        auto it=Spil.begin();
        if(brojac2==0) break;
        int x=b ;
        while (x!=0) {
            int br=r;
            while(br!=0) {
                //int bio=0;
                if(--br==0) break;
                br++;
                it++;
                br--;
                if(it==Spil.end()){
                    it=Spil.begin();
                   // bio=1;
                }
                /*if(x<b-4 && bio==1){
                    br++;
                }*/
            }
            red.push(*it);
            it=Spil.erase(it);
            brojac2--;
            x--;

        }

    }

    return red;


}
void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &Spil, std::queue<std::pair<Boje,std::string>> red, int n  )
{
    if(n>52|| (n<0)) {
        throw std::domain_error ("Broj n je besmislen!");
    }
    if(n>red.size()) {
        throw std::range_error ("Nedovoljno karata u redu!");
    }
    
    if(Spil.size()>52) {
        throw std::logic_error ("Neispravna lista!");
    }
    int m(n);
    int l=0;
    int ll=0;
    bool p=0,t=0,h=0,k=0,kk=0,tt=0,pp=0,hh=0;
    /*while(m!=0) {
        std::pair<Boje,std::string> x;
        x=red.front();
        Spil.push_back(x);
        red.pop();
        m--;
    }*/
   auto it=Spil.begin();
   auto kraj=Spil.end();
   --kraj;

    while(m!=0){
        std::pair<Boje,std::string> x;
        x=red.front();
   // for(;;){
        
        //boje karata u redu
        if(x.first==Boje::Pik){
             p=1;
        }
        else if(x.first==Boje::Tref){
             t=1;
        }
        else if(x.first==Boje::Herc){
             h=1;
        }
        else if(x.first==Boje::Karo){
             k=1;
        }
        //boje karata u spilu
        if(it->first==Boje::Pik){
             pp=1;
        }
        else if(it->first==Boje::Tref){
             tt=1;
        }
        else if(it->first==Boje::Herc){
             hh=1;
        }
        else if(it->first==Boje::Karo){
             kk=1;
        }
        //duzine karata u redu
        if(x.second=="2")   l=2;
        else if(x.second=="3")   l=3;
        else if(x.second=="4")   l=4;
        else if(x.second=="5")   l=5;
        else if(x.second=="6")   l=6;
        else if(x.second=="7")   l=7;
        else if(x.second=="8")   l=8;
        else if(x.second=="9")   l=9;
        else if(x.second=="10")  l=10;
        else if(x.second=="J")   l=11;
        else if(x.second=="Q")   l=12;
       else  if(x.second=="K")   l=13;
        else if(x.second=="A")   l=14;
         //duzine karata u spilu 
        if(it->second=="2"){
           ll=2;
           if(l==14) l=1;
        }  
        else if(it->second=="3")  ll= 3;
        else if(it->second=="4")  ll= 4;
        else if(it->second=="5")  ll= 5;
        else if(it->second=="6")  ll= 6;
        else if(it->second=="7")  ll= 7;
        else if(it->second=="8")  ll= 8;
        else if(it->second=="9")  ll= 9;
        else if(it->second=="10")  ll= 10;
        else if(it->second=="J")  ll= 11;
        else if(it->second=="Q")  ll= 12;
        else if(it->second=="K")  ll= 13;
        else if(it->second=="A")  ll= 14;
        if((k==1&&kk==1) || (h==1&&hh==1)||(tt==1&&t==1)||(p==1&&pp==1)||(p==1&&tt==1)||(t==1&&hh==1)||(h==1 && kk==1)||(k==1&&pp==1)){
            if(l==ll-1){
              Spil.insert(it,x); 
              red.pop();
              m--;
              
            } 
            
        }
        if(it==kraj) it=Spil.begin();
        else it++;
    //}
    }
    


}


 int main ()
{
    std::list<std::pair<Boje,std::string>> Spil;
    std::queue<std::pair<Boje,std::string>> red;
    std::multimap<Boje,std::string> izbaci;
    try{
    Spil=KreirajSpil();
    short int r;
    int b;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>b;
    /*int brojac2=b;
    for(;;) {
        if(brojac2==0) break;
        auto it=Spil.begin();
        int x=b ;
        while (x!=0) {
            int br=r;
            while(br!=0) {
                if(--br==0) break;
                br++;
                it++;
                br--;
                if(it==Spil.end()){ 
                    it=Spil.begin();
                }
               
            }
            izbaci.insert(*it);
            x--;
            it++;
            brojac2--;
        }

    }*/
    
    red=IzbaciKarteRazbrajanjem(Spil,r,b);
    std::cout<<"U spilu trenutno ima "<<Spil.size()<<" karata, i to:"<<std::endl;
    // 
    std::cout<<"Pik: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Pik) {
            std::cout<<it->second<<" ";
        }
    }
    std::cout<<std::endl<<"Tref: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Tref) {
            std::cout<<it->second<<" ";
        }
    }
    std::cout<<std::endl<<"Herc: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Herc) {
            std::cout<<it->second<<" ";

        }
    }
    std::cout<<std::endl<<"Karo: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Karo) {
            std::cout<<it->second<<" ";
        }
    }
    int n;
    std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    std::cin>>n;
    VratiPrvihNKarata(Spil,red,n);

    std::cout<<"U spilu trenutno ima "<<Spil.size()<<" karata, i to:";
    std::cout<<std::endl<<"Pik: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Pik) {
            std::cout<<it->second<<" ";
        }
    }
    std::cout<<std::endl<<"Tref: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Tref) {
            std::cout<<it->second<<" ";
        }
    }
    std::cout<<std::endl<<"Herc: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Herc) {
            std::cout<<it->second<<" ";

        }
    }
    std::cout<<std::endl<<"Karo: ";
    for(auto it=Spil.begin(); it!=Spil.end(); it++) {
        if(it->first==Boje::Karo) {
            std::cout<<it->second<<" ";
        }
    }
}
catch (std::domain_error err){
    std::cout<<"Izuzetak: "<<err.what();
    return 0;
}
catch (std::logic_error err){
    std::cout<<"Izuzetak: "<<err.what();
    return 0;
}
catch (std::range_error err){
    std::cout<<"Izuzetak: "<<err.what();
    return 0;
}
IzbaciKarte(Spil,izbaci);
    return 0;
}
