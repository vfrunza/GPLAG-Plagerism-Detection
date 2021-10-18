/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <set>
#include <utility>
#include <iterator>

using std::cout;
using std::endl;
using std::cin;

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string glavni_string) {
    
    std::set<int> start{}; // skup
    std::map<std::string, std::set<int>> indeks_pojmova; // mapa koju vracam
    for (int i=0; i<glavni_string.length(); i++) { // prolazim kroz string
        std::string temp=std::string();
        while (i!=glavni_string.length() && glavni_string[i]==' ')
        i++;
        int ze=i;
        while (i!=glavni_string.length() && glavni_string[i]!=' '  ) 
         {
            temp=temp+glavni_string[i];
            i++;
        }
        if(!indeks_pojmova.count(temp))
        indeks_pojmova.insert(make_pair(temp, start));  //napravi par
        indeks_pojmova[temp].insert(ze);
    }
    return indeks_pojmova;
}


std::set<int> PretraziIndeksPojmova (std::string pojam, std::map<std::string, std::set<int>> broj ) {
     if (!broj.count(pojam)) 
     throw std::logic_error ("Unesena rijec nije nadjena!");
     return broj[pojam];
}


void IspisiIndeksPojmova (std::map<std::string, std::set<int>> indeks_pojma) {
    for (auto l: indeks_pojma) {
        cout << l.first;
        cout << ": ";
        int dim=distance(l.second.begin(), l.second.end()); // logicki kao l.second.end - l.second.begin
        int izbroji(0);
        for (auto n: l.second) {
            izbroji++;
            if (izbroji==dim) 
            cout << n;
            else {
                cout << n;
                cout << ",";
                }
        }
        cout << endl;
    }
    
}
int main ()
{
    cout << "Unesite tekst: ";
    std::string tekst_unos;
    std::string rijec;
    std::getline (std::cin, tekst_unos);
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst_unos));

    do {
        cout << "Unesite rijec: ";
        cin >> rijec;
        if (rijec==".") break;
        try {
            int q=0;
            std::set<int> s =PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(tekst_unos));
            int dim = distance(s.begin(), s.end());
            for (auto var: s) {
                q++;
                if (q == dim) 
                cout << var; 
                else {
                    cout << var;
                    cout <<  " "; 
                    }
            }
            cout << endl;
        }
    catch (std::logic_error m) {
    cout << m.what() << endl;
     } 
     } while (rijec!=".");
    
	return 0;
}