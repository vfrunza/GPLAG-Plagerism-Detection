/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::list;
using std::logic_error;
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
    list <string> imena2;
    for(int i(0); i<imena.size(); i++) {
        imena2.push_back(imena[i]);
    }//prebacujemo u listu

    set <string> pomozimi;
    auto it=imena2.begin();
    int slovo(0);
    for(int i(0); i<brojtimova; i++) {
        int brdjeteta=ProvjeriBroj(brojdjece,brojtimova-i);
        brojdjece-=brdjeteta;
        for(int j(0); j<brdjeteta; j++) {
            int broj(0);

            while(broj<slovo) {
                if(it==imena2.end())it=imena2.begin();//ako je iterator na kraju liste mora se postaviti na pocetak jer se radi o kruzenju
                broj++;
                it++;
            }
            it--;
            if(it==imena2.end())it=imena2.begin();

            pomozimi.insert(*it);
            slovo=BrojSlova(*it);
            it=imena2.erase(it);//brisemo dijete nakon sto smo ga ubacili
            if(it==imena2.end())it=imena2.begin();

        }
        povratni.push_back(pomozimi);
        pomozimi.clear();//ocistimo pomocni string
    }

    return povratni;
}
int main ()
{try{
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
    }}catch (logic_error izuzetal){
        cout<<"Izuzetak: "<<izuzetal.what();
    }
    return 0;
}