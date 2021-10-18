#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<string>
#include<stdexcept>
using std::domain_error;
using std::string;
using std::cin;
using std::cout;
using std::domain_error;
using std::setw;
using std::vector;
using std::endl;


string ObrniFraze(string s, vector<string> v)
{
    for(int i=0; i<v.size(); i++) {
        string pom;
        for(int j=0; j<s.size(); j++) {
            pom=s.substr(j,v[i].size());
            if(pom==v[i]) {
                for(int k=0; k<v[i].size(); k++) {
                    s[k+j]=v[i][v[i].size()-k-1];
                }

            }

        }
    }
    return s;


}
string IzmijeniUPigLatin(string s, vector<string> v)
{
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {

            if(!((v[i][j]>='A' && v[i][j]<='Z') || (v[i][j]>='a' && v[i][j]<='z')))  throw  domain_error("Nekorektan izbor rijeci");

        }


    }
string pom1("ay");
    if(v.size()>0) {
        for(int i=0; i<v.size(); i++) {
            string pom;
            for(int j=0; j<s.size(); j++) {
                pom=s.substr(j,v[i].size());
                if(pom==v[i] && !(((s[j-1]>='A' && s[j-1]<='Z') || (s[j-1]>='a' && s[j-1]<='z'))) && !(((s[j+v[i].size()]>='A' && s[j+v[i].size()]<='Z') || (s[j+v[i].size()]>='a' && s[j+v[i].size()]<='z')))) {
                    s[(v[i].size())-1+j]=s[j];
                    for(int k=0; k<v[i].size()-1; k++) {
                        s[k+j]=v[i][k+1];

                    }
                    s=s.substr(0,(j+v[i].size())) + pom1 + s.substr((j+v[i].size()),s.size());
                }
            }

        }
    } 
    
    else {
        for(int j=0; j<s.size(); j++) {
            if(s[j]>='1' && s[j]<='9') continue;
            int pocetak;
            if((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') ){ pocetak=j;
            while(j<s.size() && ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z'))) j++;
            int kraj=j;
            char b=s[pocetak];
            for(int k=pocetak;k<kraj-1;k++){
                s[k]=s[k+1];
            }
            s[kraj-1]=b;
          
        s=s.substr(0,kraj) + pom1 + s.substr(kraj,s.size()-kraj);
       
        j=j+2;
        
        }
    }

}
    return s;

}
int main ()
{
    vector<string> v;
    string s,a;

    cout<<"Unesite recenicu: ";
    getline(cin,a);
    cout<<"Unesite fraze: ";
    while(getline(cin,s), s.size()>0) {
        v.push_back(s);

    }
    try {
        string s=IzmijeniUPigLatin(a,v);
        cout<<"Recenica nakon PigLatin transformacije: "<<s;
    } catch(domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();

    }
    
    cout<<endl<<"Recenica nakon obrtanja fraza: ";
    cout<<ObrniFraze(a,v);

    return 0;
}