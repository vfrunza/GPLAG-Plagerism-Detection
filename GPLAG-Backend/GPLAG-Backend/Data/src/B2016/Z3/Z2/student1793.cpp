#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

using namespace::std;

char tlc(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
  return in;
} 

bool JeZnak(char x)
{
    return((x<='z' && x>='a') || (x<='9' && x>='0'));
}
map<string,set<int>> KreirajIndeksPojmova(string recenica)
{
    string temp(recenica);
    transform(temp.begin(),temp.end(),temp.begin(),tlc);
    map<string,set<int>> index;
    for(int i = 0;i < temp.length();i++)
    {
        int j = i;
        bool JeRijec(false);
        while(JeZnak(temp[j]))
        {
            JeRijec = true;
            if(j >= temp.length())
                break;
            j++;
        }
        if(JeRijec)
            index[temp.substr(i,j-i)].insert(i);
        if(j >= temp.length())
            break;
        i = j;
    }
    return index;
}
set<int> PretraziIndeksPojmova(string rijec,map<string,set<int>> index)
{
    map<string,set<int>>::iterator it;
    it = index.find(rijec);
    if(it == index.end())
        throw logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(map<string,set<int>> f)
{
    for(map<string,set<int>>::iterator it = f.begin();it != f.end();it++)
    {
        cout << it->first << ": ";
        set<int> a = it->second;
        set<int>::iterator it1 = a.begin();
        int k(0);
        for(;it1 != a.end();it1++)
        {
            k++;
            if(k == a.size())
                break;
            cout << *it1 << ",";
        }
        cout << *it1;
        cout << endl;
    }
}
int main()
{
    string recenica;
    cout << "Unesite tekst: ";
    getline(cin,recenica);
    auto f = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(f);
    while(true)
    {
        string rijec;
        cout << "Unesite rijec: ";
        getline(cin,rijec);
        if(rijec == ".")
            return 0;
        try
        {
            auto st = PretraziIndeksPojmova(rijec,f);
            set<int>::iterator it1 = st.begin();
            for(;it1 != st.end();it1++)
            {
                cout << *it1 <<  " ";
            }
            cout << endl;
            }
        catch(exception e)
        {
            cout << "Unesena rijec nije nadjena!" << endl;
        }
    }
}