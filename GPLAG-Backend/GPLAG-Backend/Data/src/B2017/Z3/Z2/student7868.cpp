/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <tuple>
#include <map>
using namespace std;

typedef std::map<std::string, std::vector<std:: string>> Knjiga;

int slovo(char a){
    a=toupper(a);
    if(a>='A' && a<='Z') return 1;
    return 0;
}

int broj(char a)
{
     if(a>='0' && a<='9') return 1;
     return 0;
}

bool slovoilibroj(char a)
{
    int s=slovo(a);
    int b=slovo(b);
    return (s==1 || b==1);
}

vector<string> izdvoji(string s){
    vector<string> rez;
    for(int i=0; i<s.size(); i++)
    {
        string pom;
        while(slovoilibroj(s[i])) { pom.push_back(s[i]); i++;}
        if(pom.size()!=0) rez.push_back(pom);
    }
    return rez;
}

map<string,vector<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga k)
{
    map<string,vector<tuple<string,int,int>>> rez;
    
    for(auto it=k.begin(); it!=k.end(); it++)
        for(int i=0; i<(it->second).size(); i++)
            for(int j=0; j<(it->second).at(i).size(); j++)
                (it->second).at(i).at(j)=tolower((it->second).at(i).at(j));
    
    vector<string> rijeci;
    for(auto it=k.begin(); it!=k.end(); it++){
        for(int i=0; i<(it->second).size(); i++){
            vector<string> pom=izdvoji((it->second).at(i));
            for(int i=0; i<pom.size(); i++) {
                bool ima=false;
                for(int j=0; j<rijeci.size(); j++)
                    if(rijeci[j]==pom[i]) ima=true;
                if(!ima) rijeci.push_back(pom[i]);
            }
        }
    }
    
    for(int l=0; l<rijeci.size(); l++)
    {
        vector<tuple<string,int,int>> skup;
        for(auto it=k.begin(); it!=k.end(); it++)
            for(int i=0; i<(it->second).size(); i++)
                for(int j=0; j<(it->second).at(i).size(); j++)
                    if(rijeci[l]==(it->second).at(i).substr(j,rijeci[l].size()))
                    {
                        //cout<<"ASADADASD"<<endl;
                        tuple<string,int,int> pom(it->first,i+1,j);
                        skup.push_back(pom);
                    }
        //rez.insert(pair<string,vector<tuple<string,int,int>>>(rijeci[l]),skup);
        rez[rijeci[l]]=skup;
        
    }
    
    return rez;
}

vector<tuple<string,int,int>> PretraziIndeksPojmova(string s, map<string,vector<tuple<string,int,int>>> m)
{
    try{
        return m[s];
    }
    catch(...) {
        throw logic_error("Pojam nije nadjen");
    }
}

void IspisiIndeksPojmova(map<string,vector<tuple<string,int,int>>> m)
{
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<": ";
        for(int i=0; i<(it->second).size(); i++)
        {
            tuple<string,int,int> pom=(it->second).at(i);
            cout<<get<0>(pom)<<"/"<<get<1>(pom)<<"/"<<get<2>(pom);
            if(i==(it->second).size()-1)cout<<endl;
            else cout<<", ";
        }
        cout<<endl;
    }
}

int main ()
{
    vector<string> v= {"abc qwe stsda abc abc dhi qwe hrkw dhi"};
   Knjiga knjiga;
   knjiga["I"]=v;
   auto k=KreirajIndeksPojmova(knjiga);
   //cout<<endl<<"weeeee"<<endl;
   IspisiIndeksPojmova(k);
	return 0;
}
