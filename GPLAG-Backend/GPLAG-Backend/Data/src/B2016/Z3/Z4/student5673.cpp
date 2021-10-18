/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

vector<set<string>> Razvrstavanje (vector<string> v, int k)
{
    if (k < 1 || k > v.size()) throw logic_error ("Razvrstavanje nemoguce");
    list<string> l(v.size());
    copy(v.begin(), v.end(), l.begin());
    vector<int> br(k);
    vector<set<string>> s;
    
    int n = v.size();
    for (int i = 0; i < k; i++)
    {
        if (i < n % k) br[i] = int(n / k) + 1;
        else br[i] = int(n / k);
    }
    
    auto it = l.begin();
    
    for (int i = 0; i < k; i++)
    {
        set<string> ps;
        for (int j = 0; j < br[i]; j++)
        {
            string pom = *it;
            ps.insert(pom);
            auto pit = it;
            it = l.erase(pit);
            it--;
            //l.remove(*it);
            //remove(l.begin(), l.end(), *it);
            for (int k = 0; k < pom.size() - count(pom.begin(), pom.end(), ' '); k++)
            {
                if (++it == l.end()) it = l.begin();
            }
        }
        s.push_back(ps);
    }
    
    return s;
}

int main ()
{
    try
    {
        cout << "Unesite broj djece: ";
        int n;
        cin >> n;
        
        vector<string> v(n);
        
        cout << "Unesite imena djece: " << endl;
        for (int i = 0; i < n; i++) cin >> v[i];
        
        cout << "Unesite broj timova: ";
        int k;
        cin >> k;
        
        auto print = Razvrstavanje(v, k);
        
        for (int i = 0; i < print.size(); i++)
        {
            auto max = *print[i].begin();
            for (auto j = print[i].begin(); j != print[i].end(); j++)
            {
                if (*j > max) max = *j;
            }
            
            cout << "Tim " << i + 1 << ": ";
            for (auto j = print[i].begin(); j != print[i].end(); j++)
            {
                if (*j == max) cout << *j;
                else cout << *j << ", ";
            }
            cout << endl;
        }
        
    	return 0;
    }
    catch (logic_error x)
    {
        cout << "Izuzetak: " << x.what();
    }
}