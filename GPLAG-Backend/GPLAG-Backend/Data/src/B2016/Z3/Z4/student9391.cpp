/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

int pomocna(string s) {
    int brojac=0;
    for(int i=0; i<s.size(); i++) {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    return brojac;
}


vector<set<string>> Razvrstavanje(vector<string> sve, int br_timova) {
    if(br_timova<1 || br_timova>sve.size()) throw logic_error("Razvrstavanje nemoguce");
    list<string> svi;
    vector<set<string>> povrat;
    for(int i=0; i<sve.size(); i++)
        svi.push_back(sve[i]);
    list<string>::iterator it=svi.begin();
    int do_kada=pomocna(svi.front()), ukupno=sve.size(), pamti=0, when=0;
    while(svi.size()!=0) {
        pamti=ukupno % br_timova;
        if(pamti != 0) when=ukupno/br_timova + 1;
        else when=ukupno/br_timova;
        set<string> temp;
        for(int i=0; i<when; i++) {
            temp.insert(*it);
            do_kada=pomocna(*it)-1;
            it=svi.erase(it);
            if(svi.begin()==svi.end()) break;
            for(int j=0; j<do_kada; j++) {
                if(it==svi.end()) it=svi.begin();
                    advance(it, 1);
                if(it==svi.end()) it=svi.begin();
            }
        }
        povrat.push_back(temp);
        ukupno -=when;
        br_timova--;
    }
    return povrat;
}


int main () {
    int broj_djece;
    string temp;
    cout << "Unesite broj djece: ";
    cin >> broj_djece;
    cout << "Unesite imena djece: ";
    vector<string> s;
    cin.ignore(10000, '\n');
    for(int i=0; i<broj_djece; i++) {
        getline(cin, temp);
        s.push_back(temp);
    }
    int tim;
    cout << "\nUnesite broj timova: ";
	cin >> tim;
	try {
	    vector<set<string>> v=Razvrstavanje(s,tim);
	    int brojac=0;
	    for(int i=0; i<v.size(); i++) {
	        cout << "Tim " << i+1 << ": ";
	        brojac=0;
	        for(auto x: v[i]) {
	            brojac++;
	            if(brojac<v[i].size())
	                cout << x << ", ";
	            else cout << x << endl;
	        }
	    }
	    
	} catch(logic_error greska) {
	    cout << greska.what() << endl;
	}
	return 0;
}