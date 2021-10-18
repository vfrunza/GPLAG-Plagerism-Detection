/B2016/2017: Zadaća 3, Zadatak 2
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<cctype>
#include<stdexcept>
using std::string;
using std::map;
using std::set;
using std::make_pair;
using std::endl;
using std::cout;
using std::cin;
map<string, set<int>> KreirajIndeksPojmova(string tekst){
    string temp=tekst;
    string pomocna;
    
    map<string, set<int>> mapa;
   
    for (int i=0; i<temp.size(); i++){
        set<int> skup;
        int brojac=0;
        while ( temp[i]=='.') i++;
        while (i<temp.size() && ((temp[i]>='a'&& temp[i]<='z') ||(temp[i]>='A'&& temp[i]<='Z')|| (temp[i]>='0'&&temp[i]<='9'))){
            brojac++;
            i++;
        }
        pomocna=temp.substr(i-brojac, brojac);
        //if (i==temp.size()) continue;
        skup.insert(i-pomocna.size());
        
        for(char &c:pomocna) c=tolower(c);
        for (int j=i+1; j<temp.size(); j++){
            string pomocna2;
            bool bul=false;
            int brojac1=0;
            while (temp[j]=='.') j++;
            while (j<temp.size() && ((temp[j]>='a'&& temp[j]<='z') ||(temp[j]>='A'&& temp[j]<='Z')|| (temp[j]>='0'&&temp[j]<='9'))){
                brojac1++;
                j++; bul=true;
            }
            if (bul){
            pomocna2=temp.substr(j-brojac1,brojac1);
            }
            for(char &c:pomocna2) c=tolower(c);
            if (pomocna==pomocna2) {
                skup.insert(j-pomocna2.size());
                for (int k=j-brojac1; k<j; k++){
                    temp[k]='.';
                }
            }
        }

        mapa.insert(make_pair(pomocna, skup));
    }
    map<string,set<int>>::iterator it=mapa.begin();
    mapa.erase (it); 
    return mapa;
}
set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> mapa){
    for (char &c:rijec) c=tolower(c);
    if(!mapa.count(rijec)) throw std::logic_error ("Pojam nije nadjen");
    else return mapa[rijec];
}
void IspisiIndeksPojmova(map<string, set<int>> mapa){
    
    for (auto i=mapa.begin(); i!=mapa.end(); i++){
        //if(i->first.empty() ) continue;
        cout<<i->first<<": ";
        for (auto x:i->second){
            cout<<x;
            if(x!=*(--i->second.end())) cout<<",";
        }
        cout<<endl;
    }
    
}

int main (){
        std::string s;
        cout<<"Unesite tekst: ";
        std::getline(cin, s);
        map<string, set<int>> mapa=KreirajIndeksPojmova(s);
        IspisiIndeksPojmova(mapa);
        string rijec;
        for(;;){
            cout<<"Unesite rijec: ";
            std::getline(cin, rijec);
            if(rijec==".")break;
            set<int> skup;
            try{
            skup=PretraziIndeksPojmova(rijec,mapa);
            for (int x:skup) cout<<x<<" ";
            cout<<endl;
            }catch(std::logic_error why){
                cout<<"Unesena rijec nije nadjena!"<<endl;
            }
        }
    
    
    
	return 0;
}