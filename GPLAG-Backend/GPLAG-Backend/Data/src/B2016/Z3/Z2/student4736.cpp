/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <vector>


using namespace std;

bool Razmak(char znak)
{

    return !((znak>='a'&&znak<='z')||(znak>='A'&&znak<='Z')||(znak>='0'&&znak<='9'));
}
vector<string> izdvojiRijeciUMalaSlova(string recenica)
{
    vector<string>rijeci;


    string rijec="";

    for (int i = 0; i < recenica.size(); i++) {
        char znak = recenica[i];
        if((znak>='a'&&znak<='z')||(znak>='A'&&znak<='Z')||(znak>='0'&&znak<='9')) {
            if(znak>='A'&&znak<='Z')znak+=32;

            rijec+=znak;
        } else {
            if(rijec!="")
                rijeci.push_back(rijec);
            rijec="";
        }
    }

    if(rijec!="")rijeci.push_back(rijec);

    return rijeci;
}


set<int> vratiPozicije(string recenica, string rijec)
{


    for (int i = 0; i < recenica.size(); i++) {
        if(recenica[i]>='A'&&recenica[i]<='Z')recenica[i]+=32;

    }
    set<int>pozicije;


    for (int i = 0; i <= recenica.size()-rijec.size(); i++) {
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


map<  string , set<int> > KreirajIndeksPojmova(string recenica)
{
    set<string> jedinstveneRijeci;
    map<string,set<int>> indeksi;
    std::vector<string>rijeci = izdvojiRijeciUMalaSlova(recenica);

    for(auto e:rijeci)jedinstveneRijeci.insert(e);


    for(auto it=jedinstveneRijeci.begin(); it!=jedinstveneRijeci.end(); it++) {
        indeksi[*it] = vratiPozicije(recenica,*it);
    }



    return indeksi;
}

void IspisiIndeksPojmova( map< string, set<int> >indeksi)
{

    for(auto it = indeksi.begin(); it != indeksi.end(); it++) {
        std::cout << it->first << ": ";
        set<int>p = it->second;
        vector<int>poz;

        for(auto itp=p.begin(); itp!=p.end(); itp++) {
            poz.push_back(*itp);
        }

        for (int i = 0; i < poz.size(); i++) {
            cout<<poz[i];
            if(i!=poz.size()-1) cout<<",";
            else cout<<endl;
        }
    }


}



set<int> PretraziIndeksPojmova(string rijec, map<string, set<int> > indeksi)
{

    auto it(indeksi.find(rijec));

    if(it == indeksi.end()) throw logic_error("Pojam nije nadjen");
    else  return it->second;

}
int main ()
{
    cout<<"Unesite tekst: ";
    string tekst;
    getline(cin,tekst);


    auto indeksi = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeksi);


    do {

        cout<<"Unesite rijec: ";
        string rijec;
        getline(cin,rijec);
        if(rijec==".")break;
        try {
            set<int>pozicije = PretraziIndeksPojmova(rijec,indeksi);
            for(auto it=pozicije.begin(); it!=pozicije.end(); it++) {
                cout<<*it<<" ";
            }
            cout<<endl;
        } catch(logic_error e) {
            cout<<"Rijec nije nadjena!"<<endl;
        }
    } while(true);



    return 0;
}