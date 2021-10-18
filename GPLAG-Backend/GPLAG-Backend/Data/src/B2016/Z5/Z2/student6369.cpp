#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template<typename Skup>
Skup& operator +=(Skup& ulazni1, const Skup &ulazni2){
    for(auto it=ulazni2.begin(); it!=ulazni2.end(); it++){
        if(!ulazni1.count(*it)) ulazni1.insert(*it);
    }
    return ulazni1;
}

template <typename Skup>
Skup operator +(const Skup& ulazni1, const Skup &ulazni2){
    Skup rez(ulazni1);
    rez+=ulazni2;
    return rez;
}

template<typename Skup>
Skup& operator *=(Skup &ulazni1, const Skup &ulazni2){
    Skup rezultat;
    for(auto it=ulazni2.begin(); it!=ulazni2.end(); it++){
        if(ulazni1.count(*it)) rezultat.insert(*it);
    }
    ulazni1=rezultat;
    return ulazni1;
}

template <typename Skup>
Skup operator *(const Skup& ulazni1, const Skup &ulazni2){
    Skup rez(ulazni1);
    rez*=ulazni2;
    return rez;
}

template <typename tip>
std::ostream& operator<<(ostream& tok, const std::set<tip> &rez1){
    tok<<"{";
    for(auto it=rez1.begin(); it!=rez1.end(); it++) {
        tok<<*it;
        if(it!=(--rez1.end())) tok<<",";
    }
    tok<<"}";
    return tok;
}

template <typename tip1, typename tip2>
std::set<std::pair<tip1,tip2>> operator %(const std::set<tip1> &rez1,const std::set<tip2> &rez2){
    std::set<std::pair<tip1,tip2>> parovi;
    int i(0);
    for(auto it=rez1.begin(); it!=rez1.end(); it++){
        std::pair<tip1,tip2> rez;
        for(auto it3=rez2.begin(); it3!=rez2.end(); it3++,i++){
            rez.first=*it;
            rez.second=*it3;
            parovi.insert(rez);
        }
    }
    return parovi;
}

template <typename tip1, typename tip2>
std::ostream& operator <<(std::ostream &tok,const std::set<std::pair<tip1,tip2>> &rez){
    tok<<"{";
    for(auto it=rez.begin(); it!=rez.end(); it++){
        tok<<"("<<it->first<<","<<it->second<<")";
        if(it!=(--rez.end())) tok<<",";
    }
    tok<<"}";
    return tok;
}

// x::y kad god x ovisi od parametra sablona, tipa std::set<tip>::interator, ne moze, moramo dodat typename ispred svega
int main ()
{
    set<string> Imena1{"A1","A2","A3"};
    set<int> Imena2{1,2,3};
    /*auto rez1(Imena2 + Imena1);
    auto rez2(Imena1*Imena2);
    cout<<"Unija: ";
    cout<<rez1<<endl;
    cout<<"Presjek: ";
    cout<<rez2<<endl;
   */ auto rez3(Imena1%Imena2);
    cout<<rez3<<endl;
	return 0;
}