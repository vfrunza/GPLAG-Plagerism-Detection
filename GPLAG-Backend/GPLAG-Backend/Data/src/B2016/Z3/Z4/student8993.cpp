/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int duzina_imena(std::string s){
    int br(0);
    for(int i=0; i<s.length(); i++)
        if((s[i]>47 && s[i]<58) || ( s[i]>64 && s[i]<91) || (s[i]>96 && s[i]<123)) br++;
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje (const std::vector<std::string> &v, int k){
    int n(v.size());
    if(k<1 || k>n) throw std::logic_error ("Izuzetak: Razvrstavanje nemoguce");
    
    std::list<std::string> imena;
    //const std::list<std::string>::iterator imena_begin (imena.begin()); 
    for(int i=0; i<n; i++)
        imena.push_back(v[i]); 
    
    //for(auto i: imena) std::cout << i << std::endl;
    
    auto imena_it(imena.begin());
    std::vector<std::set<std::string>> timovi(k);
    for(int i=0; i<k; i++){
        int tim_i(0);
        if(i<n%k) tim_i=n/k + 1;
        else tim_i=n/k;
        for(int j=0; j<tim_i; j++) {
            //std::cout << *imena_it << std::endl;
            timovi[i].insert(*imena_it);
            int brslova(duzina_imena(*imena_it));
            imena_it=imena.erase(imena_it);
            if(imena_it==imena.end()) imena_it=imena.begin();
            for(int l=1; l<brslova; l++){
                imena_it++;
                if(imena_it==imena.end()) imena_it=imena.begin();
            }
        }
    }
    return timovi;
}


int main ()
{
    try{
        int djece, timova;
        std::cout << "Unesite broj djece: " ;
        std::cin>>djece;
        std::cout << "Unesite imena djece: " << std::endl;
        std::vector<std::string> imena;
        imena.resize(djece);
        //std::cin.ignore(10,' ');
        for(int i=0; i<imena.size(); i++){ std::getline(std::cin>>std::ws, imena[i]);  }
        std::cout << "Unesite broj timova: " ;
        std::cin>>timova;
        auto rez(Razvrstavanje(imena, timova));
        for(int i=0; i<rez.size(); i++) {
            std::cout << "Tim "<<i+1<<": " ;
            auto skup_it(rez[i].begin());
            for(int k=0; k<rez[i].size(); k++){
                std::cout << *skup_it;
                if(k!=rez[i].size()-1) std::cout<<", ";
                skup_it++;
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error i){
        std::cout << i.what() << std::endl;
    }
	return 0;
}