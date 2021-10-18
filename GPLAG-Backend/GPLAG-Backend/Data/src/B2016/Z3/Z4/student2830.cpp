#include <vector>
#include <string>
#include <list>
#include <set>
#include <iostream>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int k){
    if(k<1 || k>djeca.size())  throw std::logic_error("Razvrstavanje nemoguce");
    std::string ime;
    int n(djeca.size());
    int granica(n%k);
    int clanovi_skupa(n/k);
    int brojac(0);
    int drugi(0);
    int oznaka(0);
    int dojava(0);
    
    std::vector<std::set<std::string>> v(k);
    std::list<std::string> krug;
 
    for(int i=0; i<n; i++){
        krug.push_back(djeca[i]);
    }

    for(auto it=krug.begin(); it!=krug.end(); it++){
        v[oznaka].insert(*it);
        dojava++;
        ime=*it;
    if(dojava==clanovi_skupa+1 && oznaka<granica){
        oznaka++;
       dojava=0;
    }
    if(oznaka>=granica &&  dojava==clanovi_skupa){
        oznaka++;
        dojava=0;
    }
        it=krug.erase(it);
        brojac=0;
        for(int i=0; i<ime.length(); i++){
            if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) brojac++;
        }
        while(drugi<brojac){
            if(it==krug.end()) it=krug.begin();
        it++;
        drugi++;
        if(it==krug.end() && drugi<brojac) it=krug.begin();
        if(drugi==brojac-1) {
            it--;
            drugi=0;
            break;
        }
        }
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