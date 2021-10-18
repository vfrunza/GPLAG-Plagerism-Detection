
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <vector>

using namespace std;

int duzinaStringa(const string &s)
{
    int Duzina{0};
    for(char c : s)
    {
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) Duzina++;
    }
    return Duzina;
}

vector<set<string>> Razvrstavanje(vector<string> imena_djece,int broj_timova)
{
    if(broj_timova<1 || (unsigned int)broj_timova>imena_djece.size()) throw logic_error("Izuzetak: Razvrstavanje nemoguce");
    int brojDjece {int(imena_djece.size())};
    int brojVecihTimova{brojDjece % broj_timova};
    int brojManjihTimova{broj_timova - brojVecihTimova};
    int br_veciTim{ 1+brojDjece/broj_timova };
    int br_manjiTim{ brojDjece/broj_timova };
    
    list<string> lista;
    for(string dijete : imena_djece)
        lista.push_back(dijete);
    vector<set<string>>rez;
    string trenutnoDijete{imena_djece[0]};
    list<string>::iterator it{lista.begin()};
    int brojacVelikih{0};
    int brojacManjih{0};
    
    while(brojacVelikih<brojVecihTimova)
    {
        set<string> a;
        for(int velSkupa=0;velSkupa<br_veciTim;velSkupa++)
        {
            a.insert(trenutnoDijete);
            it=lista.erase(it);
            if(lista.size()==0) break;
            if(it==lista.end()) it=lista.begin();
            int pomaci{ duzinaStringa(trenutnoDijete) };
            for(int i=1;i<pomaci;i++)
            {
                it++;
                if(it==lista.end()) it=lista.begin();
            }
            trenutnoDijete = *it;
        }
        brojacVelikih++;
        rez.push_back(a);
        a.clear();
    }
    while(brojacManjih<brojManjihTimova)
    {
        set<string> a;
        for(int velSkupa=0;velSkupa<br_manjiTim;velSkupa++)
        {
            a.insert(trenutnoDijete);
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            if(lista.size()==0) break;
            int pomaci {duzinaStringa(trenutnoDijete) };
            for(int i=1;i<pomaci;i++)
            {
                it++;
                if(it==lista.end()) it=lista.begin();
            }
            trenutnoDijete=*it;
        }
        brojacManjih++;
        rez.push_back(a);
        a.clear();
    }
    return rez;
}

int main ()
{
    cout<<"Unesite broj djece: ";
    int br_djece;
    cin>>br_djece;
    cin.ignore(10000,'\n');
    cout<<"Unesite imena djece: "<<endl;
    vector<string> imena;
    string s;
    for(int i=0;i<br_djece;i++)
    {
        getline(cin,s);
        imena.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int br_timova;
    cin>>br_timova;
    
    try{
        vector<set<string>> timovi{Razvrstavanje(imena,br_timova)};
    
    for(int i=0;i<br_timova;i++)
    {
        auto tim=timovi[i];
        cout<<"Tim "<<i+1<<": ";
        int j{0};
        for(string s : tim)
        {
            cout<<s;
            j++;
            if(j!=tim.size()) cout<<", ";
        }
        cout<<endl;
    }
    }
    catch(logic_error e){
        cout<<e.what();
    }
	return 0;
}