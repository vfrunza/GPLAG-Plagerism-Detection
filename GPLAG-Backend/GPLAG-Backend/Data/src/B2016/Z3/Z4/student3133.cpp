/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj){
    if(broj<1||broj>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> l;
    for(std::string dijete: djeca) l.push_back(dijete);
    std::vector<std::set<std::string>> grupe(broj);
    int velicina_prvog;
    if(djeca.size()%broj==0) velicina_prvog=djeca.size()/broj;
    else velicina_prvog=djeca.size()/broj+1;
    int pocetna(velicina_prvog);
    std::list<std::string>::iterator it(l.begin());
    int promijeni_index(0);
    int i(0);
    while(l.size()!=0){
        grupe[promijeni_index].insert(*it);
        std::string rijec(*it);
        it=l.erase(it);
        if(l.size()==0) break;
        i++;
        if(i==velicina_prvog){
            promijeni_index++;
            i=0;
        }
        if(velicina_prvog==pocetna&&promijeni_index==djeca.size()%broj&&djeca.size()%broj!=0) velicina_prvog--;
        //pomicanje iteratora
        std::string::iterator it1(rijec.begin());
        it--;
        while(1){
            if(*it1!=' '&&*it1!='-'){
                it++;
                if(it==l.end()) it=l.begin();
            }
            it1++;
            if(it1==rijec.end()) break;
        }
    }
    return grupe;
}

int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::vector<std::string> djeca(n);
    std::cout<<"Unesite imena djece: ";
    std::cin.ignore(100, '\n');
    for(int i=0; i<n; i++) std::getline(std::cin, djeca[i]);
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    int broj;
    std::cin>>broj;
    try{
        std::vector<std::set<std::string>> grupe=Razvrstavanje(djeca, broj);
        for(int i=0; i<broj; i++){
             std::cout<<"Tim "<<i+1<<":";
             int j(0);
             for(std::string x: grupe[i]){
                 std::cout<<" "<<x;
                 if(j<grupe[i].size()-1) std::cout<<",";
                 j++;
             } 
             std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
	return 0;
}