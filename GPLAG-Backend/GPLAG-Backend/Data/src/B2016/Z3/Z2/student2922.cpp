/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <utility>
#include <map>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;
bool Slovo (char znak ){
    return ((znak>='A' && znak<='Z')||(znak>='a' && znak <='z') || (znak>='0' && znak<='9'));
}

map <string, set<int>> KreirajIndeksPojmova (string rec){
    map <string, set<int>> pomocna;
    int i(0);
    //Sad i tjeramo do prvog slova u recenici aka preskacemo
    //Neslova
    for(; !Slovo(rec[i]) && i<rec.length(); i++);
    for(; i<rec.length(); i++){
        //Sad je pronadjena rijec, nuzno ju je zapamtiti
        //zabiljeziti po svim ponavljanjima
        //i potom ignorisati njena ponavljanja u stringu 
        if(Slovo(rec[i]) && ((i!=0 && !Slovo ( rec[i-1] ) ) || (i==0))){
            //rijec na poziciji "i"
            int duzina{0};
            for(; Slovo(rec[i+duzina]); duzina++);
            string rijec = rec.substr(i, duzina);
            //Transformacija stringa u mala slova putem tolower 
            transform(rijec.begin(), rijec.end(), rijec.begin(), ::tolower);
            
            //Da li smo vec imali ovu rijec? Ako da onda je samo preskoci
            if(pomocna.count(rijec) ) continue;
            //Sad imamo nasu rijec
            
            //Sad je nuzno naci njena sva ponavljanja i pobiljeziti ih
            set<int> pon;
            pon.insert(i);
            for( int k{i+duzina}; k<rec.length(); k++){
                int klizac{k};
                //Da li je to rijec duzine 1?
                if(duzina == 1 && i!=0 && Slovo(rec[i-1]) ) continue;
                //Ako se prvo slovo ne poklapa onda sigurno nece ni ostatak rijeci, pa je preskoci brojanjem k preko te rijeci koja ne zadovoljava
                else if (k!=0 && !Slovo(rec[k-1]) && tolower(rec[k])!=rijec[0]){
                    
                    while(Slovo(rec[klizac])) klizac++;
                    k=klizac;
                }
                if(k==rec.length()) break;
                string pomocna_rijec = rec.substr(k,duzina);
                transform(pomocna_rijec.begin(), pomocna_rijec.end(), pomocna_rijec.begin(), ::tolower);
                
                //Sad poredimo pomocnu rijec (koja nam treba zbog malih slova)
                //I rijec koju sad zelimo ubaciti u mapu
                if(rec[i] == rijec[0] && pomocna_rijec==rijec /*&& (duzina!=1 || k==0 || !Slovo(rec[k-1]))*/){
                    pon.insert(k);
                    //Ako je zadovoljeno onda prebacimo za duzina
                    k+=duzina;
                }
            }
            //Sad su popamcena sva ponavljanja
            pomocna.insert(make_pair(rijec, pon));
            i+=duzina;
        }
        
    }
    
    return pomocna;
}

set<int> PretraziIndeksPojmova (string rijec, map<string, set<int>> mapa){
    //Bacanje izuzetka ako je brojanje ispalo nula tj logicki netacno
    if(!mapa.count(rijec)) throw logic_error("Pojam nije nadjen");
    return mapa[rijec];
}

void IspisiIndeksPojmova( map<string, set<int>> mapa){
    for(auto it = mapa.begin(); it!=mapa.end(); it++){
        cout<<it->first<<": ";
        for( auto it_set  = begin(it->second); it_set!=end(it->second); it_set++){
            if(it_set==prev(end(it->second))) cout<<*it_set;
            else cout <<*it_set<<",";
        }
        cout<<endl;
    }
}

int main (){
    cout << "Unesite tekst: ";
    string tekst;
    getline(cin, tekst);
    auto indeks = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeks);
    string unos;
    for(;;){
        cout<<"Unesite rijec: ";
        string rijec;
        
        getline(cin, rijec);
        
        //Prekid besk petlje je unos tacke
        if(rijec == ".") break;
        transform(rijec.begin(), rijec.end(), rijec.begin(), ::tolower);
        try{
            auto popis = PretraziIndeksPojmova(rijec, indeks);
            for( auto x : popis) cout << x<<" ";
            cout <<endl;
        }catch(...){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
	return 0;
}