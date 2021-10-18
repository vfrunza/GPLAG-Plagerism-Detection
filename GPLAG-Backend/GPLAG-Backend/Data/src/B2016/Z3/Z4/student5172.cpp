#include <iostream>
#include <list>
#include<set>
#include<vector>
#include<stdexcept>
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> imena, int n)
{
    if(n<1 || n>imena.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi;
    std::vector<int> brojclanova;
    for(int i=0; i<imena.size()%n; i++) {
        brojclanova.push_back((imena.size()/n)+1);
    }
    for(int i=0; i<n-imena.size()%n; i++) {
        brojclanova.push_back(imena.size()/n);
    }
    std::list<std::string> im;
    for(int i=0; i<imena.size(); i++) {
        im.push_back(imena[i]);
    }
    int k=0;
    auto it1=im.begin();
    int broj=0;
    for(int p=0; p<(*it1).length(); p++) {
        if(!(((*it1)[p]>='a'&&(*it1)[p]<='z')|| ((*it1)[p]>='A'&&(*it1)[p]<='Z') || ((*it1)[p]>='0'&&(*it1)[p]<='9'))) broj++;
    }
    int brojponavljanja=(*it1).length()-broj;
    auto it=im.begin();
    while(im.size()!=0) {
        std::set<std::string>tim;
        if(k==0) {
            tim.insert(*it);
            it=im.erase(it);
        } 
        while(brojclanova[k]!=tim.size() && im.size()!=0 ) {
            while(brojponavljanja!=1) {
                it++;
                if(it==im.end()) {
                    it=im.begin();
                }
                brojponavljanja--;
            }
            
            broj=0;
            for(int p=0; p<(*it).length(); p++) {
                if(!(((*it)[p]>='a'&&(*it)[p]<='z')|| ((*it)[p]>='A'&&(*it)[p]<='Z') || ((*it)[p]>='0'&&(*it)[p]<='9'))) broj++;
            }
            brojponavljanja=(*it).length()-broj;
            tim.insert(*it);
            it=im.erase(it);
            if(it==im.end()) it=im.begin();
        }
        timovi.push_back(tim);
        k++;
    }
    return timovi;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::vector<std::string> v;
    std::cout<<"Unesite imena djece: "; 
    for(int i=0; i<n; i++) {
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout<<"\nUnesite broj timova: ";
    int m;
    std::cin>>m;
     std::cin.ignore(1000, '\n');
    try {
        std::vector<std::set<std::string>> imena=Razvrstavanje(v, m);
        for(int i=0; i<imena.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            auto it=(imena[i]).begin();
            while(it!=--(imena[i]).end()){
                std::cout << *it << ", ";
                 it++; 

                 if(it==--(imena[i]).end()) break; 
            }
            std::cout<<*it;  
            std::cout<<std::endl;
        }
        
    } catch(std::logic_error iz) {
        std::cout<<"Izuzetak: "<<iz.what();
    }
    return 0;
}