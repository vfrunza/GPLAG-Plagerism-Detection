/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>

#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
using std::set;
using std::logic_error;

bool Provjerislovo(char s)
{
    if((s>='a' && s<='z') || (s>='0' && s<='9') || (s>='A' && s<='Z')) {
        return true;

    }//ako jeste slovo vraca true, ako nije false
    return false;
}
map<string,set<int>> KreirajIndeksPojmova(string s)
{
    map<string,set<int>> mapa;
    string pomocnistring;
    int cuvamindeks1(0),cuvamindeks2(0);
    for(int i(0); i<s.length(); i++) {

        if(s[i]>='A' && s[i]<='Z')s[i]=s[i]+('a'-'A');//prebacujem slova da sva budu mala 
    }
    for(int i(0); i<s.length(); i++) {
        if(i!=0 && Provjerislovo(s[i-1])==false &&  Provjerislovo(s[i])==true) {
            cuvamindeks1=i;

            while(cuvamindeks1<s.size() && Provjerislovo(s[cuvamindeks1])) {
                pomocnistring.push_back(s[cuvamindeks1]);
                cuvamindeks1++;
                cuvamindeks2=i;
            }//u pomocni string ubacujem
            if(mapa.find(pomocnistring)!=mapa.end()) {//trazim dali vec postoji takvo ime
                auto it(mapa.find(pomocnistring));
                it->second.insert(cuvamindeks2);

            } else {
                mapa.insert(make_pair(pomocnistring,set<int> {cuvamindeks2}));//ako ne postoji ubacujem ga

            }




        } else if(i==0 && Provjerislovo(s[i])==true) {
            cuvamindeks1=i;
            while(cuvamindeks1<s.size() && Provjerislovo(s[cuvamindeks1])) {
                pomocnistring.push_back(s[cuvamindeks1]);
                cuvamindeks1++;
                cuvamindeks2=i;
            }
            if(mapa.find(pomocnistring)!=mapa.end()) {
                auto it(mapa.find(pomocnistring));
                it->second.insert(cuvamindeks2);

            } else {
                mapa.insert(make_pair(pomocnistring,set<int> {cuvamindeks2}));

            }
        }
        i=cuvamindeks1;
        pomocnistring.resize(0);//vracam ga na nulu da mogu ponovo koristiti
    }

    return mapa;
}
set<int> PretraziIndeksPojmova(string s,map<string,set<int>> mapa)
{
    set <int> indeksi;
    auto it(mapa.find(s));
    if(it==mapa.end())throw logic_error("Unesena rijec nije nadjena!");//nema te rijeci


    return it->second;
}
void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        cout<<it->first<<": ";
        int brojac=0;
        for(auto p=it->second.begin(); p!=it->second.end(); p++) {
            if(brojac<it->second.size()-1) {

                cout<<*p<<",";
                brojac++;//ispis
            } else {
                cout<<*p;
            }


        }
        cout<<endl;
    }

}
int main ()
{
    
        cout<<"Unesite tekst: ";
        string tekst;
        getline(cin,tekst);
        map<string,set<int>> mapa(KreirajIndeksPojmova(tekst));


        IspisiIndeksPojmova(mapa);
        string rijec;
        set <int> skup;
        while(rijec!=".") {
            cout<<"Unesite rijec: ";
            cin>>rijec;
            if(rijec==".")return 0;
           try{ skup =  PretraziIndeksPojmova(rijec,mapa);
                  for(auto x: skup)cout<<x<<" ";
            cout<<endl;
           }
            catch(logic_error izuzetak ) {
        cout<<izuzetak.what()<<endl;}
        }

        

    
    return 0;
}