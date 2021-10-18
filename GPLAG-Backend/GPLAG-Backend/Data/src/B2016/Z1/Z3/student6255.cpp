#include<iostream>
#include<vector>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
typedef vector<vector<double>>Matrica;

int rastuci(vector<double>v,int pozicija){
    int brojac(0);
    for(int i=pozicija;i<v.size()-1;i++){
        if(v[i]<=v[i+1])brojac++;
        else return brojac;
        }
        return brojac;
    }
    
int opadajuci(vector<double>v,int pozicija){
    int brojac(0);
    for(int i=pozicija;i<v.size()-1;i++){
        if(v[i]>=v[i+1])brojac++;
        else return brojac;
        }
        return brojac;
    }
    
Matrica RastuciPodnizovi(vector<double>v){
    Matrica mat;
    int fiksni,brojac;
    for(int i=0;i<v.size();i++){
        if(rastuci(v,i)!=0){
            vector<double>pomocni;
            fiksni=i;
            brojac=rastuci(v,i);
            for(;i<fiksni+brojac+1;i++)pomocni.push_back(v[i]);
            mat.push_back(pomocni);
    }
    }
    return mat;
}

Matrica OpadajuciPodnizovi(vector<double>v){
    Matrica mat;
    int fiksni,brojac;
    for(int i=0;i<v.size();i++){
        if(opadajuci(v,i)!=0){
            vector<double>pomocni;
            fiksni=i;
            brojac=opadajuci(v,i);
            for(;i<fiksni+brojac+1;i++)pomocni.push_back(v[i]);
            mat.push_back(pomocni);
    }
    }
    return mat;
}
int main(){
    int n;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    vector<double>v(n);
    cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++) cin>>v[i];
    Matrica p;
    p=RastuciPodnizovi(v);
    cout<<"Maksimalni rastuci podnizovi: "<<endl;
    for(int i=0;i<p.size();i++){
        for(int j=0;j<p[i].size();j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
   Matrica f;
    f=OpadajuciPodnizovi(v);
    cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    for(int i=0;i<f.size();i++){
        for(int j=0;j<f[i].size();j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
