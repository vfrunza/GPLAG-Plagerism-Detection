#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
void IspisiIndeksPojmova(map<string,set<int>>index)
{
    for(auto i:index)
    {
        std::cout << i.first <<": ";
        int br(0),vel=distance(i.second.begin(),i.second.end());
        for(auto j:i.second)
        {
            br++;
            if(br==vel) std::cout << j;
            else std::cout << j <<",";
        }
        std::cout <<std::endl;
    }
}
set<int>PretraziIndeksPojmova(string s,map<string,set<int>>m)
{
    if(!m.count(s)) throw logic_error ("Unesena rijec nije nadjena!");
    return m[s];
}
map<string,set<int>> KreirajIndeksPojmova(string s)
{
    map<string,set<int>> m;
    set<int>p{};
    for(int i=0;i<s.length();i++)
    {
        string tmp=string();
        while(i!=s.length()&&s[i]==' ') i++;
        int x=i;
        while(i!=s.length()&&s[i]!=' ') 
        {
            tmp+=s[i];
            i++;
        }
        if(!m.count(tmp)) m.insert(make_pair(tmp,p));
        m[tmp].insert(x);
    }
    return m;
}
int main()
{
    std::cout << "Unesite tekst: " ;
    string s;
    getline(cin,s);
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    
    for(;;)
    {
        cout<<"Unesite rijec: ";
        string r;
        cin>>r;
        if(r==".") break;
        try {
            set<int>d=PretraziIndeksPojmova(r,KreirajIndeksPojmova(s));
            int br=0,vel=distance(d.begin(),d.end());
            for(auto i:d)
            {
                br++;
                if(br==vel) cout<<i;
                else cout<<i<<" ";
            }
            std::cout << std::endl;
        }
        catch (logic_error e) {
            std::cout << e.what() << std::endl;
        }
        
    }
    return 0;
}