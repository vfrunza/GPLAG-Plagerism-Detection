/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>

using namespace std;

vector<string> IzbaciVisak (vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                for (int k = j; k < v.size() - 1; k++) v[k] = v[k + 1];
                v.resize(v.size() - 1);
                j--;
            }
            
        }
    }
    
    return v;
}

vector<string> KreirajMatricu (string s)
{
    vector<string> v;
    v.push_back("");
    
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            v[v.size() - 1] += s[i];
        }
        else v.push_back("");
    }
    
    v = IzbaciVisak(v);
    
    return v;
}

map<string, set<int>> KreirajIndeksPojmova (string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 'A' && s[i] < 'Z') s[i] += 32;
    }
    
    vector<string> v = KreirajMatricu(s);
    
    map<string, set<int>> m;
    
    for (int i = 0; i < v.size(); i++)
    {
        set<int> Insert;
        
        for (int j = 0; j < s.size(); j++)
        {
            int p = j;
            
            if (isalnum(s[j]))
            {
                while (isalnum(s[j])) j++;
                
                int k = j;
                
                if (s.substr(p, k - p) == v[i]) Insert.insert(p);
            }
        }
        m.insert(make_pair(v[i], Insert));
    }
    
    return m;
}

set<int> PretraziIndeksPojmova (string s, map<string, set<int>> m)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 'A' && s[i] < 'Z') s[i] += 32;
        
    }
    auto it = m.find(s);
    if (it == m.end()) throw logic_error ("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova (map<string, set<int>> m)
{
    for (auto i = m.begin(); i != m.end(); i++)
    {
        for (auto j = i->first.begin(); j != i->first.begin(); j++) tolower(*j);
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        int max = *(i->second.begin());
        
        for (auto j = i->second.begin(); j != i->second.end(); j++)
        {
            if (*j > max) max = *j;
        }
        cout << i->first << ": ";
        for (auto j = i->second.begin(); j != i->second.end(); j++)
        {
            if (*j != max) cout << *j << ",";
            else cout << *j;
        } cout << endl;
    }
}

int main ()
{
    cout << "Unesite tekst: ";
    string s;
    getline(cin, s);
    
    map<string, set<int>> m = KreirajIndeksPojmova(s);
    
    IspisiIndeksPojmova(m);
    
    string r;
    do
    {
        cout << "Unesite rijec: ";
        getline(cin, r);
        
        if (r == ".") return 0;
        
        try {
            set<int> st = PretraziIndeksPojmova(r, m);
        
            for (auto i = st.begin(); i != st.end(); i++) cout << *i << " ";
            cout << endl;
        }
        catch (logic_error x) 
        {
            cout << x.what() << endl;;
        }
    } while (r != ".");
    
	return 0;
}