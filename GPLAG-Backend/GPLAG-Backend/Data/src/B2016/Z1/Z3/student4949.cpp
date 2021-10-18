#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::domain_error;
using std::setw;
using std::vector;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v)
{
    vector<double> a;
    Matrica m;

    for(int j=0; j<v.size(); j++) {
        
        if(j<v.size()-1 && v[j]<=v[j+1]) a.push_back(v[j]);
        else {
            a.push_back(v[j]);
            if(a.size()>=2) m.push_back(a);
            a.resize(0);
            }
            
    }
    
    return m;
}


Matrica OpadajuciPodnizovi(vector<double> v){
    
    vector<double> a;
    Matrica m;

    for(int j=0; j<v.size(); j++) {
        if(j<v.size()-1 && v[j]>=v[j+1]) a.push_back(v[j]);
        else {
            a.push_back(v[j]);
            if(a.size()>=2) m.push_back(a);
            a.resize(0);
            }
            
    }
    
   
    
    return m;

}

int main ()
{
    int n;
    vector<double> v;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    cout<<"Unesite elemente vektora: ";
    for(int i=0; i<n; i++) {
        int broj;
        cin>>broj;
        v.push_back(broj);

    }
    cout<<"Maksimalni rastuci podnizovi: "<<endl;
Matrica c=RastuciPodnizovi(v);
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c[i].size();j++){
            cout<<c[i][j]<<" ";
            
        }
        cout<<endl;
    }


    cout<<"Maksimalni opadajuci podnizovi: "<<endl;

Matrica b=OpadajuciPodnizovi(v);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            cout<<b[i][j]<<" ";
            
        }
        cout<<endl;
    }


    return 0;
}