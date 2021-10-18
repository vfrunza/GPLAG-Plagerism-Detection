/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

using std::list;
using std::set;
using std::cin;
using std::cout;
using std::string;
using std::vector;

bool SlBr(char a)
{
    return ((a>='A' and a<='Z')or(a>='a' and a<='z')or(a>='0' and a<='9'));
}
vector<set<string>> Razvrstavanje(vector<string> v,int n)
{
    if(n<1 or n>v.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    int broj_vel_timova(v.size()%n);
    int broj_vel_clanova(v.size()/n+1);
    int preostali_clanovi(v.size()/n);
    list<string> lista;
    for(int i=0;i<v.size();i++)
        lista.push_back(v[i]);
    auto it=lista.begin();
    string pomoc;
    vector<set<string>> vracam(n);
    int j=0;
    int duzina(0);
    while(lista.size()!=0)
    {
        for(int i=0;i<pomoc.size();i++)
            if(SlBr(pomoc[i]))
                duzina++;
        for(int i=0;i<duzina-1;i++)
        {
            if(duzina==0)
                break;
            it++;
            if(it==lista.end())
                it=lista.begin();
        }
        pomoc=*it;
        duzina=0;
        if(vracam[j].size()<broj_vel_clanova and j<broj_vel_timova)
            vracam[j].insert(pomoc);
        else if(vracam[j].size()>=broj_vel_clanova and j<broj_vel_timova)
        {
            j++;
        if(vracam[j].size()<broj_vel_clanova and j<broj_vel_timova)
            vracam[j].insert(pomoc);
        }
        if(vracam[j].size()<preostali_clanovi and j>=broj_vel_timova)
            vracam[j].insert(pomoc);
        else if(vracam[j].size()>=preostali_clanovi and j>=broj_vel_timova)
        {
            j++;
            vracam[j].insert(pomoc);
        }
        it=lista.erase(it);
        if(lista.size()==0)
            break;
        else if(lista.size()==1)
        {
            auto it2=lista.begin();
            if(vracam[j].size()<broj_vel_clanova and j<broj_vel_timova)
                vracam[j].insert(*it2);
            else if(vracam[j].size()<preostali_clanovi and j>=broj_vel_timova)
                vracam[j].insert(*it2);
            else
            {
                j++;
                vracam[j].insert(*it2);
            }
            lista.erase(it2);
            break;
                
        }
        else if(it==lista.end())
        {
            it=lista.begin();
        }
    }
    return vracam;
}
int main ()
{
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cout<<"Unesite imena djece: ";
    vector<string> v(n);
    cin.ignore(1000,'\n');
    for(int i=0;i<v.size();i++)
        getline(cin,v[i]);
    cout<<"\nUnesite broj timova: ";
    int x;
    cin>>x;
    try{
    auto a=Razvrstavanje(v,x);
    auto it=a.begin();
    int j=1;
    for(int i=0;i<a.size();i++)
    {
        auto f=*it++;
        auto s=f.begin();
        cout<<"Tim "<<j<<": ";
        for(int i=0;i<f.size()-1;i++)
        {    if(f.size()==1)
                break;
            else
                cout<<*s++<<", ";}
        cout<<*s<<"\n";
        j++;
    }
    }
    catch(std::logic_error e)
    {
        cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}