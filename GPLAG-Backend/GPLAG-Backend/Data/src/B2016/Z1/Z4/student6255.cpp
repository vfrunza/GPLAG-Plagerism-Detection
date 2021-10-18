#include<iostream>
#include<cstring>
#include<vector>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::domain_error;

string IzvrniString(string s){
    for(int i=0;i<s.length()/2;i++){
        char a=s[i];
        s[i]=s[s.size()-1-i];
        s[s.size()-1-i]=a;
        }
    return s;
}
string IzmijeniUPigLatin(string s,vector<string>v){
    int j,pocetak,kraj,a(0);
    string p;
    for(int i=0;i<v.size();i++){
        j=0;
        while(j<s.size()){ 
                if((v[i][0]==s[j])&&(j==0||s[j-1]==' ')){
                pocetak=j; 
                p=v[i];
                a=0;
                while(v[i][a]==s[j] && a<v[i].size()){ 
                    a++;
                    j++;
                }
                if(a==v[i].size()){ 
                    kraj=j;
                    s.erase(s.begin()+pocetak); 
                    s.insert(s.begin()+kraj-1,p[0]); 
                    s.insert(s.begin()+kraj,'a');  
                    s.insert(s.begin()+kraj+1,'y');
                    }
                    }
        else j++;
        }
    }
    return s;
    
}
string ObrniFraze(string s,vector<string>v){
    int j,pocetak,kraj,a(0);
    string p;
    for(int i=0;i<v.size();i++){
        j=0;
        while(j<s.size()){ 
            if(v[i][0]==s[j]){ 
                pocetak=j; 
                p=IzvrniString(v[i]);
                a=0;
                while(v[i][a]==s[j] && a<v[i].size()){ 
                    a++;
                    j++;
                }
                if(a==v[i].size()){ 
                    kraj=j;
                    for(int b=0;b<kraj-pocetak;b++) s.erase(s.begin()+pocetak); 
                    for(int b=0;b<p.size();b++) s.insert(s.begin()+pocetak+b,p[b]); 
                    }
                    }
        else j++;
        }
    }
    return s;
}
int main () {
    try{
    string recenica;
    cout<<"Unesite recenicu: ";
    getline(cin,recenica);
    string fraza;
    vector<string>spisak;
    cout<<"Unesite fraze: ";
    for(;;){
        getline(cin,fraza);
        if(fraza=="") break;
        spisak.push_back(fraza);
    }
    //BACANJE IZUZETKA
    for(int i=0;i<spisak.size();i++){
        if((spisak[i][0]<'a' && spisak[i][0]>'z') || (spisak[i][0]<'A' && spisak[i][0]>'Z'))throw domain_error("Nekorektan izbor riječi");
    }
    string piglatin;
    piglatin=IzmijeniUPigLatin(recenica,spisak);
    cout<<"Recenica nakon PigLatin transformacije: "<<piglatin<<endl;
    string povratni;
    povratni=ObrniFraze(recenica,spisak);
    cout<<"Recenica nakon obrtanja fraza: "<<povratni;
    return 0;
    }
    catch(std::domain_error izuzetak) {
    cout << izuzetak.what()<<endl;
}
}