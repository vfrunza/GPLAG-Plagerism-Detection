/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <list>
int DuzinaImena(std::string ime){
    int duzina(0);
    for(int i=0; i<ime.length(); i++) if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9') || (ime[i]>='a' && ime[i]<='z')) duzina++;
    return duzina;
}
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> djeca, int br_timova){
    if(br_timova<1 || br_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi(br_timova);
    std::list<std::string> l;
    for(int i=0; i<djeca.size(); i++) l.push_back(djeca[i]);
    std::vector<int> velicine(br_timova);
    if(!(djeca.size()%br_timova))
        for(int i=0; i<br_timova; i++) velicine[i]=djeca.size()/br_timova;
    else{
        for(int i=0; i<djeca.size()%br_timova; i++) velicine[i]=(djeca.size()/br_timova)+1;
        for(int i=djeca.size()%br_timova; i<br_timova; i++) velicine[i]=djeca.size()/br_timova;
    }
    int mrzim_ovo(0);
    auto it(velicine.begin());
    auto i(l.begin());
    while(l.size()!=0){
        while(mrzim_ovo<br_timova){
            int j(0);
            while(j<*it){
                timovi[mrzim_ovo].insert(*i);
                int duzina_imena(DuzinaImena(*i)-1);
                if(l.size()==0) break;
                i=l.erase(i);
                if(i==l.end()) i=l.begin();
                while(duzina_imena>0){
                    i++;
                    if(i==l.end()) i=l.begin();
                    duzina_imena--;
                }
                j++;
            }
            if(l.size()==0) break;
            it++;
            mrzim_ovo++;
        }
    }
    return timovi;
}
int main ()
{
    try{
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite imena djece: ";
        std::vector<std::string> djeca;
        for(int i=0; i<n; i++){
            std::string ime;
            std::getline(std::cin, ime);
            djeca.push_back(ime);
        }
        std::cout<<std::endl<<"Unesite broj timova: ";
        int br_tim;
        std::cin>>br_tim;
        auto timovi(Razvrstavanje(djeca, br_tim));
        for(int i=0; i<timovi.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            int br(0);
            for(auto j=timovi[i].begin(); j!=timovi[i].end(); j++){
                br++;
                if(br==timovi[i].size()) std::cout<<*j;
                else std::cout<<*j<<", ";
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error fu){
        std::cout<<"Izuzetak: "<<fu.what();
    }
	return 0;
}