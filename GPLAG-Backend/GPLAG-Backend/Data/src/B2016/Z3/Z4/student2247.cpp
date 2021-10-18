#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;

vector<int> BrojDjeceUTimovima(int broj_djece, int broj_timova) {
    vector<int> u_timu(broj_timova, int(broj_djece/broj_timova));
    int ostatak(broj_djece%broj_timova);
    for(int i=0; i<u_timu.size(); i++) {
        if(ostatak!=0) {
            u_timu[i]=u_timu[i]+1;
            ostatak--;
        }
        else break;
    }
    return u_timu;
}

int BrojSlova(string ime) {
    int brojac(0);
    for(auto it=ime.begin(); it!=ime.end(); it++) {
        if((*it>=48 && *it<=57) || (*it>=65 && *it<=90) || (*it>=97 && *it<=122)) brojac++;
    }
    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string> imena_djece, int broj_timova) {
    if(broj_timova<1 || broj_timova>imena_djece.size()) throw logic_error("Razvrstavanje nemoguce");
    auto br_djece_u_timu(BrojDjeceUTimovima(imena_djece.size(), broj_timova));
    vector<set<string>> povratni(broj_timova);
    list<string> lista_imena(imena_djece.begin(), imena_djece.end());
    int koji_tim(0), koje_dijete(0);
    for(auto it=lista_imena.begin(); ;) {
        if (lista_imena.empty()) break;
        if(it==lista_imena.end()) it=lista_imena.begin();
        povratni[koji_tim].insert(*it);
        koje_dijete++;
        if(koje_dijete>=br_djece_u_timu[koji_tim]) {
            koji_tim++;
            koje_dijete=0;
        }
        if(koji_tim>=broj_timova) break;
        int povecanje(BrojSlova(*it));
        it=lista_imena.erase(it);
        if(it==lista_imena.end()) it=lista_imena.begin();
        for(int i=0; i<povecanje-1; i++) {
            it++;
            if(it==lista_imena.end()) it=lista_imena.begin();
        }
        
    }
    return povratni;
}

int main ()
{   
    try {
    cout << "Unesite broj djece: ";
    int br_vojnika;
    cin >> br_vojnika;
    vector<string> vojnici(br_vojnika);
    cin.ignore(100,'\n');
    cout << "Unesite imena djece: \n";
    for(int i=0; i<vojnici.size(); i++) {
        getline(cin, vojnici[i]);
    }
    cout << "Unesite broj timova: ";
    int br_brigada;
    cin >> br_brigada;
    auto brigade(Razvrstavanje(vojnici, br_brigada));
    for(int i=0; i<brigade.size(); i++) {
        cout << "Tim " << i+1 << ": ";
        int brojac(0);
         for(string nejm : brigade[i]) {
             if(brojac==0) cout << nejm;
             else cout << ", " << nejm;
             brojac++;
         }
         cout << endl;
    }
    }
    catch(logic_error nema_logike) {
        cout << "Izuzetak: " << nema_logike.what() << endl;
    }
	return 0;
}