/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;

map<string,set<int>> KreirajIndeksPojmova(string text) {
    map<string,set<int>> povrat;
    for(int i=0; i<text.size(); i++)
    if(text[i]>='A' && text[i]<='Z')
        text[i] += 'a'-'A';
    for (int i=0; i<text.size(); i++) {
        string temp;
        if((text[i]>='a' && text[i]<='z') || (text[i]>='0' && text[i]<='9')) {
            while (((text[i]>='a' && text[i]<='z') || (text[i]>='0' && text[i]<='9')) && i!=text.size())
                temp.push_back(text[i++]);
            map<string,set<int>>::iterator it=povrat.find(temp);
            if((povrat.end() != it)) continue;
            else {
                set<int>tmp;
                int lok=0;
                while(lok<text.size()) {
                    lok=text.find(temp,lok);
                    if(lok<text.size()) {
                        tmp.insert(lok);
                        lok++;
                    }
                }
                povrat.insert(std::pair<string,set<int>> (temp, tmp));
            }
        }
    }
    return povrat;
}

set<int> PretraziIndeksPojmova(string trazen, map<string,set<int>> mapa) {
    if(mapa.find(trazen)==mapa.end()) throw logic_error("Pojam nije nadjen");
    else return mapa.find(trazen)->second;
}

void IspisiIndeksPojmova (map<string, set<int>> mapa) {
    for(map<string,set<int>>::iterator it=mapa.begin();it!=mapa.end();it++) {
        cout << it->first << ": ";
        set<int> temp=it -> second;
        int brojac =0;
        for(auto x : temp) {
            brojac++;
            if(brojac!=temp.size())
                cout << x << ",";
            else cout << x << endl;
        }
    }
}

int main () {
    string text, temp;
    cout<< "Unesite tekst: ";
    getline(cin, text);
    map<string, set<int>> mapa(KreirajIndeksPojmova(text));
    IspisiIndeksPojmova(mapa);
    while (1) {
        cout << "Unesite rijec: ";
        getline(cin, temp);
        if(temp == ".") break;
        try {
            set<int> pamti=PretraziIndeksPojmova(temp,mapa);
            int brojac=0;
            for(auto x : pamti) {
                brojac++;
                if(brojac!=pamti.size())
                    cout << x << " ";
                else cout << x << endl;
            }
        }
        catch(logic_error greska) {
            cout << "Unesena rijec nije nadjena!" << endl;
        }
    }
	return 0;
}