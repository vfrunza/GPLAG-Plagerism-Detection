/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
int BrojSlova(std::string s){
    int br=0;
    for(int i=0;i<s.length();i++){
        if((s[i]>='0' && s[i]<='9')|| (s[i]>='A' && s[i]<='z' || (s[i]>='a' && s[i]<='z')))br++;
    }
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>imena,int timovi){
    if(timovi<1 || timovi>imena.size())throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete>prva(0),prethodna;
    for(int i=1;i<=imena.size();i++){
        std::shared_ptr<Dijete>nova(new Dijete);
        nova->ime=imena[i-1];
        if(prva!=0)prethodna->sljedeci=nova;
        else prva=nova;
        if(i!=imena.size())prethodna=nova;
        else nova->sljedeci=prva;
    }
    std::shared_ptr<Dijete>p(prva),q;
    std::vector<std::set<std::string>>ii;
    int tim=0,brsl,n=imena.size();
    int nn=n;
    while(nn>0){
        if(n%timovi>tim){
            std::set<std::string>t;
            for(int i=0;i<int(n/timovi)+1;i++){
                nn--;
                brsl=BrojSlova(p->ime);
                t.insert(p->ime);
                q=p;
                for(int i=0;i<nn;i++){
                    p=p->sljedeci;
                }
                p->sljedeci=p->sljedeci->sljedeci;
                for(int i=1;i<brsl+1;i++){
                    p=p->sljedeci;
                }
            }
            ii.push_back(t);
        }
        else{
            std::set<std::string>t;
            for(int i=0;i<int(n/timovi);i++){
                nn--;
                brsl=BrojSlova(p->ime);
                t.insert(p->ime);
                q=p;
                for(int i=0;i<nn;i++){
                    p=p->sljedeci;
                }
                p->sljedeci=p->sljedeci->sljedeci;
                for(int i=1;i<brsl+1;i++){
                    p=p->sljedeci;
                }
            }
            ii.push_back(t);
        }
        tim++;
    }
    p->sljedeci=nullptr;
    return ii;
}
int main ()
{
    try{
	std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string>imena;
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    for(int i=0;i<n;i++){
        std::string ime;
        std::getline(std::cin,ime);
        imena.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int brtim;
    std::cin>>brtim;
    auto s=Razvrstavanje(imena,brtim);
    for(int i=0;i<s.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        bool z=true;
        for(std::string d:s[i]){
            if(z){std::cout<<d;z=false;}
            else
            std::cout<<", "<<d;
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    return 0;
}