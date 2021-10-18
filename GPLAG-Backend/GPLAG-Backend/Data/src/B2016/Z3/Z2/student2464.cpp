#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::map;
using std::set;

map<string, set<int>> KreirajIndeksPojmova(string s)
{
    map<string, set<int>> mapa;
    int i=0;
    while(i<s.length())
    {
        if(((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && (i==0 || (i>0 && !((s[i-1]>='A' && s[i-1]<='Z') || (s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='0' && s[i-1]<='9')))))
        {
            int j=i;
            string pom="";
            while(j<s.length() && ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))) 
            {
                char t=s[j];
                if(t>='A' && t<='Z') t+=('a'-'A');
                pom+=t;
                j++;
            }
            mapa[pom].insert(i);
        }
        i++;
    }
    return mapa;
}

set<int> PretraziIndeksPojmova(string s, map<string, set<int>> mapa)
{
    auto u=mapa.find(s);
    if(u==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return mapa[s];
}

void IspisiIndeksPojmova(map<string, set<int>> mapa)
{
    std::for_each(mapa.begin(), mapa.end(), [](std::pair<string, set<int>> pr)
    {
        cout << pr.first << ": ";
        int brojz=0;
        for(int a : pr.second)
        {
            cout << a;
            brojz++;
            if(brojz<pr.second.size()) cout << ",";
        }
        cout << "\n";
    });
}

int main ()
{
    string s;
    cout << "Unesite tekst: ";
    std::getline(cin, s);
    map<string, set<int>> m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    string t;
    do
    {
        cout << "Unesite rijec: ";
        std::getline(cin, t);
        if(t!=".")
        {
            try
            {
                set<int> pj=PretraziIndeksPojmova(t, m);
                for(int x : pj) cout << x << " ";
                cout << "\n";
            }
            catch(...)
            {
                cout << "Unesena rijec nije nadjena!\n";
            }
        }
    } while(t!=".");
	return 0;
}