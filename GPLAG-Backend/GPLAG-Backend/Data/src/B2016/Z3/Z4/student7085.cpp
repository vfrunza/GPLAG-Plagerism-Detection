/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
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
    for(int i=0;i<broj_timova;i++){
        clanovi_tima[i]=broj_clanova_tima;
        if(velicina%broj_timova!=0){
        clanovi_tima[i]=broj_clanova_tima+1;
        velicina--;
        }
   }
   return clanovi_tima;
}

int KolikoSlovaImaIme(std::string s)
{
    unsigned int brojac(0);
    for(unsigned int i(0);i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9'))
        brojac++;
    }
    return brojac;
}

std::list<std::string>::iterator PomjeriIterator(std::list<std::string>::iterator it, int n){
    for(int i=0;i<n;i++){
        it++;
    }
    return it;
}

void IsprazniSet(std::set<std::string> &skup){
    auto it=skup.begin();
    while(skup.begin()!=skup.end()){
        it=skup.erase(it);
        
    }
}


std::vector<std::set<std::string>>Razvrstavanje(  vekstring v, int broj_timova)
{
    if(broj_timova<=0 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> konacno;
    std::set<std::string> tim;
    std::vector<int> vek=BrojDjece(v, broj_timova); //vektor ciji su elementi broj clanova svakog tima
    //konacno.resize(broj_timova);
 
   std::list<std::string> lista;
   for(int i=0;i<v.size();i++){
       lista.push_back(v[i]);
   }
   int brojac=v.size();//brojac djece
   
    int br_zadnjeg_u_timu(0);
    int br(0);
    auto it=lista.begin();
    for(int i=0; i<broj_timova; i++) {
    
        int trenutni_tim=vek[i];
        
        for(int j=0;j<trenutni_tim;j++) {
            if(brojac==0) break;
           // int br(0);
            if(i==0 && j==0) {
                tim.insert(*it);
                br=KolikoSlovaImaIme(*it);
                j++;
                
                it=lista.erase(it);
                brojac--;
                if(j==vek[i])break;
            }
            if(i==0){
            for(int k=0; k<br-1; k++) {
                if(it==lista.end())it=lista.begin();
                it++;
                if(it==lista.end())it=lista.begin();
            }
            }
            else{
                for(int k=0; k<br_zadnjeg_u_timu-1; k++) {
                if(it==lista.end())it=lista.begin();
                it++;
                if(it==lista.end())it=lista.begin();
            }
                
            }
            
            br=KolikoSlovaImaIme(*it);
            tim.insert(*it);
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

void IspisiSkupSaZarezima(std::set<std::string> skup){
    int mjesto(0);
    for(auto it=skup.begin();it!=skup.end();it++){
        if( mjesto==skup.size()-1) std::cout<<*it;
        else std::cout<<*it<<", ";
        mjesto++;
    }
}


int main ()
{
   
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    
    std::cout<<"Unesite imena djece: ";
    std::cin.ignore(1000, '\n');
    vekstring imena;
    for(int i=0;i<n;i++){
        std::string s;
        std::getline (std::cin, s);
        imena.push_back(s);
    }
    std::cout<<"\nUnesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    try{
    auto v(Razvrstavanje(imena,broj_timova));
    
    for(int i=0;i<v.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        IspisiSkupSaZarezima(v[i]);
        std::cout<<std::endl;
    }
    }catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}