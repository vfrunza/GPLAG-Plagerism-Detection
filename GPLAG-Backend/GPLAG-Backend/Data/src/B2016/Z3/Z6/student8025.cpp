#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <stdexcept>
#include <memory>
struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int k){
    if(k<1 || k>djeca.size())  throw std::logic_error("Razvrstavanje nemoguce");
    std::string ime1;
    int n(djeca.size());
    int granica(n%k);
    int clanovi_skupa(n/k);
    int brojac(0);
    int drugi(0);
    int oznaka(0);
    int dojava(0);
    
    std::vector<std::set<std::string>> v(k);
   std::shared_ptr<Dijete> pocetni; std::shared_ptr<Dijete> prethodni;
    for(int i=0; i<n; i++){
   std::shared_ptr<Dijete> novi=std::make_shared<Dijete>();
    novi->ime=djeca[i]; 
    novi->sljedeci=nullptr;
     if(i==n-1) {
        novi->sljedeci=pocetni;
    }    
    if(!pocetni) pocetni=novi;
    else prethodni->sljedeci=novi;
    prethodni=novi;
    }
 auto p=pocetni;

    for(; ;){
        if(n==0) break;
        v[oznaka].insert(p->ime);
        dojava++;
        ime1=p->ime;
    if(dojava==clanovi_skupa+1 && oznaka<granica){
        oznaka++;
       dojava=0;
    }
    if(oznaka>=granica &&  dojava==clanovi_skupa){
        oznaka++;
        dojava=0;
    }
        if(p==pocetni){
            for(int i=0; i<n; i++){
               if(i==n-1){
                   
                   p->sljedeci=p->sljedeci->sljedeci;
                   n-=1;
                   break;
               }
                p=p->sljedeci;
            }
        }else{
           for(; ;){
               p=p->sljedeci;
               if(p->sljedeci->ime==ime1){
                   if(n==1){
                 p->sljedeci=nullptr;
                 n-=1;
                 break;
                   }
                   p->sljedeci=p->sljedeci->sljedeci;
                  
                   n-=1;
                   break;
               }
               
           }
        }
        brojac=0;
        for(int i=0; i<ime1.length(); i++){
            if((ime1[i]>='a' && ime1[i]<='z') || (ime1[i]>='A' && ime1[i]<='Z') || (ime1[i]>='0' && ime1[i]<='9')) brojac++;
        }
        while(drugi<brojac){
            if(n==0) break;
        p=p->sljedeci;
        drugi++;
        if(drugi==brojac-1) {
            
            drugi=0;
            break;
        }
        }
        if(n==0) {
            break;
        }
        p=p->sljedeci;
    }
    return v;
}
int main ()
{
    int n,m;
    std::vector<std::string> djeca;
	std::vector<std::set<std::string>> v;
	std::cout<<"Unesite broj djece: ";
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::string s;
	std::cout<<"Unesite imena djece: "<<std::endl;
	for(int i=0; i<n; i++){
	    std::getline(std::cin,s);
	    djeca.push_back(s);
	}
	std::cout<<"Unesite broj timova: ";
	std::cin>>m;
	try{
	v=Razvrstavanje(djeca,m);
	}catch(std::logic_error izuzetak){
	    std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	for(int i=0; i<v.size(); i++){
	    std::cout<<"Tim "<<i+1<<": ";
	    for(auto it=v[i].begin(); it!=v[i].end(); it++){
	        if(it!=v[i].begin()){
	            std::cout<<", ";
	    }
	        std::cout<<*it;
	    }
	    std::cout<<std::endl;
	}
	return 0;
}