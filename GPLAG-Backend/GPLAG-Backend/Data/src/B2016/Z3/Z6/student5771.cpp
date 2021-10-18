/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include<vector>
#include<string>
#include<list>
#include<set>
#include<stdexcept>
#include<iterator>
#include<memory>
using namespace std;
struct Dijete{
  string ime;
  shared_ptr<Dijete> sljedeci;
};
int BrojSlovaImena(string rijec){
	int n=0;
	for(int i=0; i<rijec.size(); i++){
		if((rijec[i]>='A' && rijec[i]<='Z') || (rijec[i]>='a' && rijec[i]<='z') || rijec[i]=='1' || rijec[i]=='2' || rijec[i]=='3' 
        || rijec[i]=='4' || rijec[i]=='5' || rijec[i]=='6' || rijec[i]=='7' || rijec[i]=='8' || rijec[i]=='9' || rijec[i]=='0')n++;
	}
	return n;
}
int KolikotrebaClanova(int n, int k, int j){
	int treba;
	treba=n/k;
	int nesto=n%k;
	if(j<=nesto)treba++;
	return treba;
}
shared_ptr<Dijete> KreirajPovezanuListu(vector<string> djeca){
 shared_ptr<Dijete> pocetak=nullptr;
    shared_ptr<Dijete> prethodni;
    for(int i=0; i<djeca.size(); i++){
        shared_ptr<Dijete>novi(make_shared<Dijete>());//pravi//
        novi->ime=djeca[i]; novi->sljedeci=nullptr;//postavi ih//
        if(!pocetak)pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==djeca.size()-1)prethodni->sljedeci=pocetak;}//zadnji cvor//
    return pocetak;
}
vector<set<string>>Razvrstavanje(vector<string> djeca, int n){
    if(n<1 || n>djeca.size()){
	   throw logic_error("Razvrstavanje nemoguce ");
	}
 vector<set<string>> tim;
    //razvrstavanje//
    auto it=KreirajPovezanuListu(djeca);
    int brojslovaproslog=0; int brojubacenih=0;
    int brojackrugova=0;
    for(int i=0; i<n; i++){
    int brojclanovaskupatrenutno=0;
    int kolikoclanovatreba=KolikotrebaClanova(djeca.size(), n, i+1);
    set<string> skup;
    while(brojclanovaskupatrenutno<kolikoclanovatreba){
    if(brojackrugova==brojslovaproslog){
        auto prethodni=it;
        prethodni=it->sljedeci;
        auto treba=it;
        do{
            if(prethodni->sljedeci==it)treba=prethodni;
             prethodni=prethodni->sljedeci;
        }while(prethodni!=it);
        prethodni=treba;
        skup.insert(it->ime);
        brojubacenih++;
        brojslovaproslog=BrojSlovaImena(it->ime)-1;
        prethodni->sljedeci=it->sljedeci;
        if(it!=prethodni)it=prethodni->sljedeci;
    	brojclanovaskupatrenutno++;
    	brojackrugova=0;

    }
    	if(brojubacenih!=djeca.size())it=it->sljedeci;
    	else{ it->sljedeci=nullptr;}	brojackrugova++;
    }
        if(brojclanovaskupatrenutno==kolikoclanovatreba){tim.push_back(skup); }
   
    }
    return tim;
}
void IspisiTimove(vector<set<string>> timovi){
	for(int i=0; i<timovi.size(); i++){
		cout<<"Tim "<<i+1<<": ";
		for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++){
           if((++it)!=timovi[i].end())cout<<*--it<<", ";
           else cout<<*--it;
		}cout<<endl;
	}
}
int main ()
{
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cin.ignore(10000, '\n');
    cout<<"Unesite imena djece: "<<endl;
    vector<string> djeca;
    string dijete;
    int i=0;
    do{
		getline (cin,dijete);
		djeca.push_back(dijete);
	
		i++;
	}while(i<n);
	cout<<"Unesite broj timova: ";
	int m;
	cin>>m;
	cin.ignore(10000, '\n');
	try{
    vector<set<string>> timovi=Razvrstavanje(djeca,m);
    IspisiTimove(timovi);}
    catch(logic_error izuzetak){cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	return 0;
	}
	return 0;
}
  