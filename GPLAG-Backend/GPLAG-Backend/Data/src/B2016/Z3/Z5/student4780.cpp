/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
    
};

int Broji(std::string ime){
    int br=0;
    for(int i=0; i<ime.size(); i++) 
    if((ime[i]>='0' && ime[i]<='9') || (ime[i]>='a' && ime[i]<='z')|| (ime[i]>='A' && ime[i]<='Z'))
    br++;
    return br;
}

std::vector<int>Djeca(std::vector<std::string>s, int n){
    int m=s.size()/n;
    std::vector<int>ret(n);
    int p=s.size();
    for(int i=0; i<n; i++){
        ret[i]=m;
        if(p%n!=0){
            ret[i]=m+1;
            p--;
        }
    }
    return ret;
}



std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>par1, int par2){
    
    if(par2<=0 || par2>par1.size()) throw std::logic_error("Razvrstavanje nije moguce");
    
    
    std::vector<std::set<std::string>>ret;
    std::set<std::string>umetni_skup;
    std::vector<int>n=Djeca(par1,par2);
    
    Dijete *pocetak(nullptr), *prethodni;
    for(int i=0; i<par1.size(); i++){
        Dijete *novi(new Dijete);
        novi->ime=par1[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else if(i==par1.size()-1){
            prethodni->sljedeci=novi;
            novi->sljedeci=pocetak->sljedeci;
            break;
        }
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    
    
    int granica=par1.size();
    int brojac=0,br=0;
    
    for(Dijete *p=pocetak; p!=nullptr; p=p->sljedeci){
    
    for(int i=0; i<par2; i++){
        for(int j=0; j<n[i]; j++){
            if(granica==0)break;
            if(i==0 && j==0){
                umetni_skup.insert(p->ime);
                j++;
                brojac=Broji(p->ime);
                prethodni->sljedeci=p->sljedeci;
                delete p;
                granica--;
                if(j==n[i])break;
            }
            
            if(i==0){
                for(int k=0; k<brojac-1; k++){
                    p=p->sljedeci;
                }
            }
            
            else{
               for(int k=0; k<br-1; k++){
                   
                   p=p->sljedeci;
               } 
            }
            
            
            brojac=Broji(p->ime);
            umetni_skup.insert(p->ime);
            br=brojac;
            prethodni->sljedeci=p->sljedeci;
            delete p;
           granica--;
                
        }
         ret.push_back(umetni_skup);
         std::set<std::string>::iterator k=umetni_skup.begin();
         while(umetni_skup.begin()!=umetni_skup.end())
         k=umetni_skup.erase(k);
         if(granica==0)break;
    }}
    
    return ret;
    
}
        


int main ()
{
    int broj;
    int n;
    std::vector<std::string> djeca;
    
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    
    
    std::cout<<"Unesite imena djece: ";
    std::cin.ignore(10000, '\n');
    for(int i=0; i<broj; i++){
        std::string ime;
        std::getline(std::cin, ime);
        djeca.push_back(ime);
    }
    
    std::cout<<"\nUnesite broj timova: ";
    std::cin>>n;
    
    
    try{
        std::vector<std::set<std::string>>ret(Razvrstavanje(djeca,n));
        for(int i=0; i<ret.size(); i++){
            std::cout<<"Tim "<<i+1<<"; ";
            int c=0;
            for(std::set<std::string>::iterator k=ret[i].begin(); k!=ret[i].end(); k++){
                if(c==ret[i].size()-1)
                std::cout<<*k;
                else std::cout<<*k<<", ";
                c++;
            }
            std::cout<<std::endl;
        }
    }
    
    catch(std::logic_error l){
        std::cout<<"Izuzetak: "<<l.what();
    }
            
            return 0;
}