/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::set;
using std::string;
using std::logic_error;
struct Dijete {
    string ime;
    Dijete  *sljedeci=nullptr;
};


int ProvjeriBroj(int bd,int bt)
{
    int ostatak=bd%bt;
    int rez=bd/bt;
    if(ostatak!=0)rez++;
    return rez;


}//provjeravamo broj timova
int BrojSlova(string ime)
{
    int brojac(0);
    for(int j(0); j<ime.size(); j++) {
        if((ime[j]>='A' && ime[j]<='Z') || (ime[j]>='a' && ime[j]<='z') || (ime[j]>='0' && ime[j]<='9'))brojac++;
    }
    return brojac;
}///broj slova
vector<set<string>> Razvrstavanje(vector <string> imena,int brojtimova)
{
    if(brojtimova<1 || brojtimova>imena.size())throw logic_error("Razvrstavanje nemoguce");
    int brojdjece=imena.size();

    vector <set<string>> povratni;
     Dijete  *pokazi(nullptr),*prethodni;
    try {
        
           
            for(int i(0); i<imena.size(); i++) {//kreiranje kruzne

                Dijete *novi(new Dijete);
                novi->ime=imena[i];
                novi->sljedeci=nullptr;
                if(!pokazi)pokazi=novi;
                else prethodni->sljedeci=novi;
                prethodni=novi;

            }
            prethodni->sljedeci=pokazi;
        

        }
     catch(...) {
        while(pokazi!=nullptr) {
            Dijete *pok=pokazi;
            pokazi=pokazi->sljedeci;
            delete pok;
        }throw;}

        set <string> pomozimi;
        auto it=pokazi;
        int slovo(0),ubacila(0);
        for(int i(0); i<brojtimova; i++) {
            int brdjeteta=ProvjeriBroj(brojdjece,brojtimova-i);
            brojdjece-=brdjeteta;
            for(int j(0); j<brdjeteta; j++) {
                int broj(0);

                while(broj<slovo) {
                   //ako je iterator na kraju liste mora se postaviti na pocetak jer se radi o kruzenju
                    broj++;
                   // if(broj==slovo)break;
                    it=it->sljedeci;
                }
              
                pomozimi.insert((*it).ime);
                ubacila++;//brojim koliko sam ih ubacila
                
                slovo=(BrojSlova((*it).ime))-1;
                auto help=it;
                while(help->sljedeci!=it)help=help->sljedeci;
                help->sljedeci=it->sljedeci;
                
                delete it;
               if(ubacila!=imena.size()) it=help->sljedeci;//osiguram se od memorijske greske
                
              

            }
            povratni.push_back(pomozimi);
            pomozimi.clear();//ocistimo pomocni string
        }

        return povratni;//povratna vrijednost
    }

    int main () {
        try{
        cout<<"Unesite broj djece: ";
    int brojdjece;
    cin>>brojdjece;
    cin.ignore(10000,'\n');
    cout<<"Unesite imena djece: "<<endl;//unos
    vector <string> imena;
    for(int i(0); i<brojdjece; i++) {
        string s;
        getline(cin,s);
        imena.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int brojtimova;
    cin>>brojtimova;
    vector<set<string>> timovi;
    timovi=Razvrstavanje(imena, brojtimova);
    for(int i(0); i<brojtimova; i++) {
        cout<<"Tim "<<i+1<<": ";
        for(auto j=timovi[i].begin(); j!=timovi[i].end(); j++) {
            auto pomoc=timovi[i].end();
            pomoc--;
            cout<<*j;
            if(pomoc!=j)cout<<", ";

        }
        cout<<endl;
    }}
        catch(logic_error izuzetak){
            cout<<"Izuzetak: "<<izuzetak.what();
        }catch(...){
        return 0;}
        return 0;
    }