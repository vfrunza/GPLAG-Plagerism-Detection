#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

using namespace std;

int DajBrojSlova(string s)
{
    int brojac=0;
    auto it(s.begin());
    while(it != s.end()) {
        if((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z') || (*it >= '0' && *it <= '9'))
            brojac++;
        it++;
    }
    return brojac;
}
vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    list<string> lista;
    if(n>v.size() || n<1) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> v1(n);
    for(int i = 0 ; i < v.size() ; i++) {
        lista.push_back(v[i]);
    }
    if(v.size()%n > 0)
    {
    auto it = lista.begin();
    for(int i = 0 ; i < v.size()%n ; i++)   //Koliko prvih skupova ce imati za 1 vise elemenat
    {
        for(int j = 0 ; j < (v.size()/n) + 1 ; j++) //Koliko ce imati elemenata ovi prvi skupovi sa vise elemenata
        {
            v1[i].insert(*it);
            int a=DajBrojSlova(*it);
            it = lista.erase(it);
            it--;
            for(int k = 0 ; k < a ; k++)
            {
                it++;
                if(it == lista.end()) it=lista.begin();
            }
        }
    }
    for(int i = v.size()%n ; i < n ; i++)
    {
         for(int j = 0 ; j < (v.size()/n) ; j++)
         {
            v1[i].insert(*it);
            int a=DajBrojSlova(*it);
            it = lista.erase(it);
            it--;
            for(int k = 0 ; k < a ; k++)
            {
                it++;
                if(it == lista.end()) it=lista.begin();
            }
         }
    }
    return v1;
    }
    else
    {
     auto it = lista.begin();
     for(int i = 0 ; i < n ; i++)
     {
         for(int j = 0 ; j < v.size()/n ; j++)
         {
            v1[i].insert(*it);
            int a=DajBrojSlova(*it);
            it = lista.erase(it);
            it--;
            for(int k = 0 ; k < a ; k++)
            {
                it++;
                if(it == lista.end()) it=lista.begin();
            }
         }
    }
    return v1;
    }
}

int main ()
{
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cin.ignore(1000,'\n');
    cout<<"Unesite imena djece: "<<endl;
    vector<string> v;
    for(int i = 0 ; i < n ; i++)
    {
           string s;
        getline(cin, s);
        v.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int k;
    cin>>k;
    try {
    vector<set<string>> v1 = Razvrstavanje(v,k);
    for (int j = 0 ; j < v1.size(); j++) 
    {
            string A = "Tim " + to_string(j+1) + ": ";
            for (auto k : v1[j]) {
                A += k + ", ";
            }
            cout<<A.substr(0, A.length()-2)<<endl;
    }
    }
    catch(logic_error)
    {
        cout<<"Izuzetak: Razvrstavanje nemoguce";
    }
    return 0;
}