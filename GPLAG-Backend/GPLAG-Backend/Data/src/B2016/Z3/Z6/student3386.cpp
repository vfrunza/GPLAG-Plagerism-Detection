/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>
#include <stdexcept>

using std::set;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::shared_ptr;
struct Dijete
{
    string ime;
    shared_ptr<Dijete> sljedeci;
};
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
    shared_ptr<Dijete> pocetak(nullptr),prethodni(nullptr);
    auto it=v.begin();
    vector<set<string>> vracam(n);
    if(v.size()==1)
    {
        string pomoc(*it);
        shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=pomoc;
        novi->sljedeci=nullptr;
        vracam[0].insert(pomoc);
        novi=nullptr;
        return vracam;
    }
    for(int i=0;i<v.size()-1;i++)
    {
        string pomoc(*it++);
        shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=pomoc;
        novi->sljedeci=nullptr;
        if(!pocetak)
            pocetak=novi;
        else
            prethodni->sljedeci=novi;
        prethodni=novi;
    }
    shared_ptr<Dijete> zadnji(std::make_shared<Dijete>());
    prethodni->sljedeci=zadnji;
    zadnji->ime=*it;
    zadnji->sljedeci=pocetak;
    string pomoc;
    int j=0;
    int duzina(0);
    shared_ptr<Dijete> pok=pocetak;
    shared_ptr<Dijete> prosli=zadnji;
    while(pok!=nullptr)
    {
        for(int i=0;i<pomoc.size();i++)
            if(SlBr(pomoc[i]))
                duzina++;
        for(int i=0;i<duzina-1;i++)
        {
            if(duzina==0)
                break;
            prosli=pok;
            pok=pok->sljedeci;
        }
        if(pok->sljedeci==pok)
            pok->sljedeci=nullptr;
        pomoc=pok->ime;
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
        if(pok->sljedeci==nullptr)
        {
            pok=nullptr;
            break;
        }
        prosli->sljedeci=pok->sljedeci;
        pok->sljedeci=nullptr;
        pok=nullptr;
        pok=prosli->sljedeci;
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