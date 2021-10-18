#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
using namespace std;
struct Dijete{
    string ime;
    Dijete *sljedeci;
};
int BrojSlova(std::string s){
    int br=0;
    for(int i=0;i<s.length();i++){
        if((s[i]>='0' && s[i]<='9')|| (s[i]>='A' && s[i]<='z' || (s[i]>='a' && s[i]<='z')))br++;
    }
    return br;
}
vector<set<string>> Razvrstavanje(vector<string>imena,int timovi){
    if(timovi<1 || timovi>imena.size())throw logic_error("Razvrstavanje nemoguce");
    Dijete *prva(0), *prethodna;
    for(int i(1); i<=imena.size(); i++) {
        Dijete *nova(new Dijete);
        nova->ime=imena[i-1];
        if(prva!=0) prethodna->sljedeci=nova;
        else prva=nova;
        if(i!=imena.size()) prethodna=nova;
        else nova->sljedeci=prva;
    }
    Dijete *p(prva);
    vector<set<string>>ii;
    int tim=0;
    int brsl,n=imena.size();
    int nn=n;
    bool istina=true;
    while(nn>0){
        if(n%timovi>tim){
                istina=false;
                set<string>t;
                for(int i=0;i<int(n/timovi)+1;i++){
                    nn--;
                 //brsl=p->ime.length();
                 brsl=BrojSlova(p->ime);
                t.insert(p->ime);
                Dijete*q(p);
                for(int i=0;i<nn;i++){
        p=p->sljedeci;
    }
    p->sljedeci=p->sljedeci->sljedeci;
    delete q;
                for(int i=1;i<brsl+1;i++){
                        p=p->sljedeci;
                }
                }
                ii.push_back(t);
        }
        else {
              set<string>t;
                for(int i=0;i<int(n/timovi);i++){
                    nn--;
                 //brsl=p->ime.length();
                 brsl=BrojSlova(p->ime);
                t.insert(p->ime);
                Dijete*q(p);
                for(int i=0;i<nn;i++){
        p=p->sljedeci;
    }
    p->sljedeci=p->sljedeci->sljedeci;
    delete q;
                for(int i=1;i<brsl+1;i++){
                    if(nn>1)
                        p=p->sljedeci;
                }
                }
                ii.push_back(t);
        }
        tim++;
    }
    return ii;
}
int main()
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
        std::cout <<"Izuzetak: "<<e.what()  << std::endl;
    }
    return 0;
}
