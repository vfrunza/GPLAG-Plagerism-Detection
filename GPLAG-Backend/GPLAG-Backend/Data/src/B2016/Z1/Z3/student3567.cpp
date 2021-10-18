#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;


vector<vector<double>> RastuciPodnizovi (vector<double> v) {
    vector<double> r;
    vector<vector<double>> h;
    for(int i=0;i<v.size()-1;i++){
        if(v.at(i)<=v.at(i+1)){
            int pt=i;
        while( i<v.size()-1 && v.at(i)<=v.at(i+1))i++;
        int kt=i;
        for(unsigned int j=pt;j<=kt;j++){
            r.push_back(v[j]);
        }
          
            h.push_back(r);
            r.clear();
        }
       
    }
    return h;

}
   
vector<vector<double>> OpadajuciPodnizovi (vector<double> v) {
    vector<double> r;
    vector<vector<double>> h;
    for(int i=0;i<v.size()-1;i++){
        if(v.at(i)>=v.at(i+1)){
            int pt=i;
        while( i<v.size()-1 && v.at(i)>=v.at(i+1))i++;
        int kt=i;
        for(unsigned int j=pt;j<=kt;j++){
            r.push_back(v[j]);
        }
            h.push_back(r);
            r.clear();
        }
    }
    return h;

}
    
    

int main ()
{

    int z;
    double broj=1;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>z;
    cout<<"Unesite elemente vektora: ";
    vector<double> v;
    for(int i=0;i<z;i++){
        cin>>broj;
        v.push_back(broj);
    }
    
    cout<<"Maksimalni rastuci podnizovi:"<<endl;
    auto r=RastuciPodnizovi(v);
    for(int i=0;i<r.size();i++){
        for(int u=0;u<r[i].size();u++){
            cout<<r[i][u]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maksimalni opadajuci podnizovi:"<<endl;
    auto o=OpadajuciPodnizovi(v);
    for(int i=0;i<o.size();i++){
        for(int u=0;u<o[i].size();u++){
            cout<<o.at(i).at(u)<<" ";
        }
        cout<<endl;
    }
    
    
	return 0;
}