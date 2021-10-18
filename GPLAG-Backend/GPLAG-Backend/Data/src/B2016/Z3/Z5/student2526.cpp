/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
struct Dijete{
    std::string ime;
    Dijete *sljedeci=nullptr;
};
bool slovo(char c){if(c>='A'&&c<='Z'||c>='a'&&c<='z'||c>='0'&&c<='9') return true;
return false;}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena,int br){
    if(br>imena.size()||br<1) throw std::logic_error("Razvrstavanje nemoguce");
    int vel=imena.size(),brojac=0,z=0;
    std::vector<std::set<std::string>>final(br);
    bool prva=false;
    Dijete *p,*back;
    for(int i=0;i<imena.size();i++){
        try{
            Dijete *tmp=new Dijete;
            (*tmp).ime=imena[i];
            if(!prva){
                p=tmp;prva=true;
            }
            else{
                (*back).sljedeci=tmp;
            }
            back=tmp;
        }
        catch(...){
            Dijete *pok;
            while (p!=nullptr){
                pok=p;
                p=(*p).sljedeci;
                delete pok;
            }
            throw;
        }
    }
    (*back).sljedeci=p;
    Dijete *tmp=p;
    int lol=imena.size();
    while(true){
        int vel1;
        if(br==0) break;
        if(vel%br!=0){
            vel1=vel/br +1;
            vel-=vel1;
        }
        else{
            vel1=vel/br; vel-=vel1;
        }
        br--; 
        tmp=p;
        for(int i=0;i<vel1;i++){
            int brojacitpomjeranja=0;
            while(brojacitpomjeranja!=brojac){
                tmp=(*tmp).sljedeci;
                brojacitpomjeranja++;
            }
            final[z].insert((*tmp).ime);
            brojac=0;
            for(int i=0;i<(*tmp).ime.size();i++) if(slovo((*tmp).ime[i])) brojac++;
            brojac--;
            if(brojac<0) brojac=0;
            Dijete *p2=p;
            while(1){
                if((*p2).sljedeci==tmp){
                    lol--;
                    (*p2).sljedeci=(*tmp).sljedeci;
                    delete tmp;
                    if(lol!=0){
                    tmp=(*p2).sljedeci;
                    p=tmp;}
                    break;
                    
                }
                p2=(*p2).sljedeci;
            }
        }
        z++;
    }
    return final;
} 

int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n; std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> imena(n);
    std::cin.ignore(1000,'\n'); std::cin.clear();
    for(int i=0;i<n;i++)  std::getline(std::cin,imena[i]);
    std::cout<<"Unesite broj timova: ";
    int br; std::cin>>br;
    try{
    auto kek=Razvrstavanje(imena,br);
     for(int i=0;i<kek.size();i++){
        auto it=kek[i].begin(); int brojac=0;
        std::cout<<"Tim "<<i+1<<": ";
        while(brojac!=kek[i].size()-1){std::cout<<*it++<<", "; brojac++;}
        std::cout<<*it<<std::endl;
    }
    }catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::bad_alloc){
        // std::cout<<"Nedovoljno memorije"; 
        return 0;
    }
	return 0;
} 