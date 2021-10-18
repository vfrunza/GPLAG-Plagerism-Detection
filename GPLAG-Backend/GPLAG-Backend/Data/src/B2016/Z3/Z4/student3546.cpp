#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <stdexcept>

using std::cin;
using std::cout;

int BrojiSlova(std::string s){
    int brojac(0);
    for(int i=0;i<s.length();i++)
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
    brojac++;
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca1,int brtimova){
    if(brtimova<1 || brtimova>djeca1.size())
    throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> djeca;
    for(int i=0;i<djeca1.size();i++)
    djeca.push_back(djeca1[i]);
    std::vector<std::set<std::string>> timovi(brtimova);
    auto it(djeca.begin());
    int n(djeca.size());
    int prvi=n%brtimova;
    int brcl1=n/brtimova+1;
    int brcl2=n/brtimova;
    int brslova(0);
    for(int i=0;i<brtimova;i++){
        if(i<prvi){
            for(int j=0;j<brcl1;j++){
                if(i==0 && j==0){
                    timovi[i].insert(*it);
                    brslova=BrojiSlova(*it);
                    it=djeca.erase(it);
                    if(it==djeca.end())
                    it=djeca.begin();
                    j++;
                }
                for(int k=1;k<brslova;k++)
                if(it==--djeca.end())
                it=djeca.begin();
                else
                it++;
                timovi[i].insert(*it);
                brslova=BrojiSlova(*it);
                it=djeca.erase(it);
                if(it==djeca.end())
                it=djeca.begin();
            }
        }
        else{
            for(int j=0;j<brcl2;j++){
                for(int k=1;k<brslova;k++)
                if(it==--djeca.end())
                it=djeca.begin();
                else
                it++;
                timovi[i].insert(*it);
                brslova=BrojiSlova(*it);
                it=djeca.erase(it);
                if(it==djeca.end())
                it=djeca.begin();
            }
        }
    }
    return timovi;
}

int main ()
{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(1000,'\n');
    std::vector<std::string> djeca(n);
    cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0;i<n;i++){
        std::getline(cin,djeca[i]);
    }
    cout<<"Unesite broj timova: ";
    int brtimova;
    cin>>brtimova;
    std::vector<std::set<std::string>> timovi(brtimova);
    try{
    timovi=Razvrstavanje(djeca,brtimova);
    for(int i=0;i<brtimova;i++){
        cout<<"Tim "<<i+1<<": ";
        for(auto it=timovi[i].begin();it!=timovi[i].end();it++)
        if(it==--timovi[i].end())
        cout<<*it;
        else
        cout<<*it<<", ";
        cout<<std::endl;
    }
    }
    catch(std::logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}