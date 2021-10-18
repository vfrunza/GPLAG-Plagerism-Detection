/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <tuple>

using namespace std;


typedef map<string, vector<string>> Knjiga;

bool Razmak(char znak)
{
    return !((znak>='a'&&znak<='z')||(znak>='A'&&znak<='Z')||(znak>='0'&&znak<='9'));
}


void izdvojiRijeciUMalaSlova(string recenica,set<string>&rijeci)
{
    string rijec="";

    for(int i = 0; i < recenica.size(); i++) {
        char znak = recenica[i];
        if((znak>='a'&&znak<='z')||(znak>='A'&&znak<='Z')||(znak>='0'&&znak<='9')) {
            if(znak>='A'&&znak<='Z')znak+=32;

            rijec+=znak;
        } else {
            if(rijec!="")
                rijeci.insert(rijec);
            rijec="";
        }
    }
    if(rijec!="")rijeci.insert(rijec);

}


set<int> vratiPozicije(string recenica, string rijec)
{
    for(int i = 0; i < recenica.size(); i++) {
        if(recenica[i]>='A'&&recenica[i]<='Z')recenica[i]+=32;
    }
    set<int>pozicije;
    for(int i = 0; i <= (int(recenica.size())-int(rijec.size())); i++) {
        int prije=i-1;
        int poslije = i+rijec.size();
        if(recenica.substr(i,rijec.size())==rijec) {
            if((prije==-1 || Razmak(recenica[prije]))&&(poslije==recenica.size()||Razmak(recenica[poslije])) ) {
                pozicije.insert(i);
            }
        }
    }
    return pozicije;
}


map< string, set< tuple<string,int,int> > > KreirajIndeksPojmova(Knjiga k)
{
    map<string, set< tuple<string,int,int> >>indeks_pojmova;


    set<string>pojmovi;

    for(auto it = k.begin(); it!=k.end(); it++) {
        string ime_poglavlja = it->first;
        vector<string>stranice = it->second;

        for(string stranica:stranice) {
            izdvojiRijeciUMalaSlova(stranica, pojmovi);
        }
    }

    for (auto pojam : pojmovi) {
        set< tuple<string,int,int> > skup_pozicija;
        for(auto it = k.begin(); it!=k.end(); it++) {
            string ime_poglavlja = it->first;
            vector<string>stranice = it->second;
            for(int i=0; i<stranice.size(); i++) {
                set<int>indeksi = vratiPozicije(stranice[i],pojam);
                for(int indeks:indeksi) {
                    tuple<string,int,int>t(ime_poglavlja,i+1,indeks);
                    skup_pozicija.insert(t);
                }
            }
        }
        indeks_pojmova[pojam] = skup_pozicija;
    }

    return indeks_pojmova;
}


set<tuple<string,int,int>> PretraziIndeksPojmova(string rijec, map<string, set<tuple<string,int,int>>> indeks_pojmova)
{
    auto it = indeks_pojmova.find(rijec);

    if(it == indeks_pojmova.end()) {
        throw logic_error("Pojam nije nadjen");
    } else {
        return it->second;
    }
}


void IspisiIndeksPojmova(map<string, set<tuple<string,int,int>>> indeksPojmova)
{

    for(auto it = indeksPojmova.begin(); it!=indeksPojmova.end(); it++) {
        string pojam = it->first;
        auto skup_pozicija = it->second;
        cout<<pojam<<": ";
        for(auto it = skup_pozicija.begin(); it!=skup_pozicija.end();) {
            auto t = *(it);
            cout<<get<0>(t)<<"/"<<get<1>(t)<<"/"<<get<2>(t);
            it++;
            if(it!=skup_pozicija.end())cout<<", ";
        }
        cout<<endl;
    }
}
int main ()
{
    Knjiga k;
    string poglavlje="";

    while(true) {
        cout<<"Unesite naziv poglavlja: ";
        cin>>poglavlje;
        cin.ignore(1000,'\n');
        if(poglavlje==".")break;

        vector<string> stranice;
        while(true) {
            cout<<"Unesite sadrzaj stranice "<<stranice.size()+1<<": ";
            string sadrzajStranice;
            getline(cin,sadrzajStranice);
            if(sadrzajStranice==".") break;
            stranice.push_back(sadrzajStranice);
        }
        k[poglavlje] = stranice;
    }


    /*for(auto it=k.begin();it!=k.end();it++){
        string poglavlje = it->first;
        vector<string> stranice = it->second;
        cout<<poglavlje<<": ";
        for(string stranica:stranice)cout<<stranica<<endl;
    }*/
    cout<<endl<<"Kreirani indeks pojmova:"<<endl;


    map< string, set< tuple<string,int,int> > > indeksPojmova = KreirajIndeksPojmova(k);
    IspisiIndeksPojmova(indeksPojmova);


    while(true) {
        try {
            string trazenaRijec;
            cout<<"Unesite rijec: ";
            cin>>trazenaRijec;
            if(trazenaRijec==".")break;
            set<tuple<string,int,int>> skup_pozicija = PretraziIndeksPojmova(trazenaRijec,indeksPojmova);


            for(auto it = skup_pozicija.begin(); it!=skup_pozicija.end();) {
                auto t = *(it);
                cout<<get<0>(t)<<"/"<<get<1>(t)<<"/"<<get<2>(t)<<" ";
                it++;
            }
            cout<<endl;
        } catch(logic_error e) {
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
    return 0;
}
