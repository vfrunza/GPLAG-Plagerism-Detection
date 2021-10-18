/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <iterator>
typedef std::vector<std::string> VS;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int Prebroj(string s){
    int br(0);
    
    for(int i(0);i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9')) br++;
    }
    return br;
}

vector<std::set<string>>Razvrstavanje(VS vecimena, int k){
    if(k<=0 || k>vecimena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    vector<std::set<string>> vec;
    int brojac(0);
    std::list<string> listaimena;
    for(int i(0);i<vecimena.size();i++)
        listaimena.push_back(vecimena[i]);
        
    auto it(listaimena.begin());
    int n(vecimena.size());
    int me(k);
    int brojslova(0);
    for(int i(0);i<me;i++){
        int tim(n/k);
        if(n%k!=0) tim++;
        std::set<string> settima;
        for(int j(0);j<tim;j++){
            if(brojac==vecimena.size())break;
            if(i==0 && j==0) {settima.insert(*it);brojslova=(Prebroj(*it));j++;it=listaimena.erase(it);brojac++;if(j==tim)break;}
                    for(int lm(0);lm<brojslova-1;lm++){
                        if(it==listaimena.end()) it=listaimena.begin();
                        it++;
                        if(it==listaimena.end()) it=listaimena.begin();
                    }
                brojslova=(Prebroj(*it));
                settima.insert(*it);
                it=listaimena.erase(it);
                if(it==listaimena.end()) it=listaimena.begin();
                brojac++;
                
        }
        vec.push_back(settima);
        if(brojac==vecimena.size())break;
        n=n-tim;
        k--;
    }
    return vec;
}

void IspisiSet(std::set<string> a){
    int br(0);
    for(auto i(a.begin());i!=a.end();i++){
        if(br==(a.size())-1) cout<<*i;
        else
        cout<<*i<<", ";
        br++;
    }
}

int main ()
{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    
    cout<<"Unesite imena djece: ";
    cin.ignore(10000,'\n');
    VS vecimena;
    for(int i(0);i<n;i++){
        string s1;
        std::getline(cin, s1);
        vecimena.push_back(s1);
    }
    cout<<"\nUnesite broj timova: ";
    int k;
    cin>>k;
    try{
    auto vektor(Razvrstavanje(vecimena,k));
    for(int i(0);i<vektor.size();i++){
        cout<<"Tim "<<i+1<<": ";
        IspisiSet(vektor[i]);
        cout<<endl;
    }
    }catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
    }
	return 0;
}