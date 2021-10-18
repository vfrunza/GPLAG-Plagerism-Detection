/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
typedef std::vector<std::set<std::string>> Povratni;
struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};
int Slova(std::string s){
    auto a(s.begin());
    int brojac(0);
    while (a!=s.end()){
        if((*a>='a' && *a<='z') || (*a>='A' && *a<='Z') || (*a>='0' && *a<='9')) brojac++;
        a++;
    }
    return brojac;
}
Povratni Razvrstavanje(std::vector<std::string> djeca,int k){
    Dijete *p1(nullptr),*p2(nullptr),*p3(nullptr);
    int n(djeca.size());
    if(k<1 || k>n) throw std::logic_error("Razvrstavanje nemoguce");
    std::string kraj(djeca[n-1]);
    Povratni izlaz;
    for(int i=0;i<n;i++){
        Dijete*novi(new Dijete);
        novi->ime=djeca[i];novi->sljedeci=nullptr;
        if(i==n-1){
            novi->sljedeci=p1;
            p3=novi;
        }
        if(!p1) p1=novi;
        else p2->sljedeci=novi;
        p2=novi;
    }
    auto it(p1);
    int x,i;
    for(i=0;i<n%k;i++){
        std::set<std::string> temp;
        for(int j=0;j<n/k+1;j++){
            x=Slova(it->ime);
            temp.insert(it->ime);
            p3->sljedeci=it->sljedeci;
            delete(it);
            it=p3->sljedeci;
            for(int k=0;k<x-1;k++){
                it=it->sljedeci;
                p3=p3->sljedeci;
            }
        }
        izlaz.push_back(temp);
    }
    for(int a=i;a<k;a++){
        std::set<std::string> temp;
        for(int b=0;b<n/k;b++){
            x=Slova(it->ime);
            temp.insert(it->ime);
            if(p3->sljedeci==it->sljedeci){
                temp.insert(p3->ime);
                delete p3;
                continue;
            }
            p3->sljedeci=it->sljedeci;
            delete(it);
            it=p3->sljedeci;
            for(int c=0;c<x-1;c++){
                it=it->sljedeci;
                p3=p3->sljedeci;
            }
        }
        izlaz.push_back(temp);
    }
    return izlaz;
}
int main (){
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    if(n<0){ std::cout<<"Pogresan parametar";return 0;}
    std::cout<<"Unesite imena djece: \n";
    std::vector<std::string> djeca(n);
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++) std::getline(std::cin,djeca[i]);
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    Povratni ispis;
    try{
        ispis=Razvrstavanje(djeca,k);
    } catch(std::logic_error a){
        std::cout<<"Izuzetak: "<<a.what();
        return 0;
    }
    for(int i=0;i<k;i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto temp(ispis[i].begin());
        for(int j=0;j<ispis[i].size()-1;j++) std::cout<<*temp++<<", ";
        std::cout<<*temp<<std::endl;
    }
	return 0;
}