/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <vector>
#include <stdexcept>
#include <set>
#include <cmath>
#include <map>
#include <string>
using namespace std;

typedef std::map<std::string, std::vector<std:: string>> Knjiga;


bool validno(char a)
{
    return((a>='0' && a<='9')||(toupper(a)>='A' && toupper(a)<='Z'));
}

vector<tuple<string,int,int>> PretraziIndeksPojmova(string s, map<string,vector<tuple<string,int,int>>> ind)
{
    auto it=ind.find(s);
    if(it==ind.end()) throw logic_error("Unesena rijec nije nadjena!");
    return ind[s];
}

vector<string> sep(string s)
{
    vector<string> v;
    for(int i=0; i<s.size(); i++)
    {
        string s1;
        while(validno(s[i])) {s1.push_back(s[i]); i++;}
        if(s1.size()!=0) v.push_back(s1);
    }
    return v;
}

void cupaj(Knjiga &k, vector<string> &v)
{
    for(auto it=k.begin(); it!=k.end(); it++)
        for(int i=0; i<it->second.size(); i++){
            vector<string> pom=sep(it->second.at(i));
            for(int i=0; i<pom.size(); i++)
            {
                bool a=true;
                for(int j=0; j<v.size(); j++) 
                    if(v[j]==pom[i]) 
                        a=false;
                if(a) v.push_back(pom[i]);
            }
        }
}



void smanji(Knjiga &k)
{
    for(auto it=k.begin(); it!=k.end(); it++)
        for(int i=0; i<it->second.size(); i++)
            for(int j=0; j<it->second.at(i).size(); j++)
                it->second.at(i).at(j)=tolower(it->second.at(i).at(j));
}

map<string,vector<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga k)
{
    smanji(k);
    map<string,vector<tuple<string,int,int>>> indeks;
    vector<string> pom;
    cupaj(k,pom);
    
    for(int ind=0; ind<pom.size(); ind++){
        vector<tuple<string,int,int>>tapl;
        for(auto it=k.begin(); it!=k.end(); it++)
            for(int i=0; i<it->second.size(); i++)
                for(int j=0; j<it->second.at(i).size(); j++)
                    if(pom[ind]==it->second.at(i).substr(j,pom[ind].size()))
                        //if(f1(pom[ind],it->second.at(i))) 
                            tapl.push_back(make_tuple(it->first,i+1,j));
        indeks[pom[ind]]=tapl;
    }
    return indeks;
}

void ispisitapl(tuple<string,int,int> t)
{
    cout<<get<0>(t)<<"/"<<get<1>(t)<<"/"<<get<2>(t);
}

void IspisiIndeksPojmova(map<string,vector<tuple<string,int,int>>> ind)
{
    for(auto it=ind.begin();it!=ind.end(); it++)
    {
        cout<<it->first<<": ";
        for(int i=0; i<it->second.size();i++)
        {
            auto t=it->second.at(i);
            ispisitapl(t);
            if(i!=(it->second.size()-1)) cout<<", ";
            else cout<<endl;
        }
    }
}

int main ()
{
    Knjiga  k;
    string s;
    for(;;)
    {
        cout<<"Unesite naziv poglavlja: ";
        getline(cin,s);
        if(s==".") break;
        vector<string> v;
        int br=1;
        while(1)
        {
            cout<<"Unesite sadrzaj stranice "<<br<<": "; 
            br++;
            string pom;
            getline(cin,pom);
            if(pom==".") break;
            else v.push_back(pom);
        }
        k.insert(make_pair(s,v));
        //k[s]=v;
    }
    cout<<endl;
    map<string,vector<tuple<string,int,int>>> ind=KreirajIndeksPojmova(k);
    cout<<"Kreirani indeks pojmova: "<<endl;
    IspisiIndeksPojmova(ind);
    while(1)
    {
        cout<<"Unesite rijec: ";
        string pom;
        getline(cin,pom);
        if(pom==".") break;
        try{
            vector<tuple<string,int,int>> sk=PretraziIndeksPojmova(pom,ind);
            for(int i=0; i<sk.size(); i++)
            {
                auto t=sk.at(i);
                ispisitapl(t); cout<<" ";
                if(i==sk.size()-1) cout<<endl;
            }
        } catch(logic_error ind) {cout<<ind.what()<<endl;}
    }
	return 0;
}
