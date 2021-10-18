#include <iomanip>
#include <iostream>
#include <vector>
#include<string>
using namespace std; 

vector<vector<double>>OpadajuciPodnizovi(vector<double>v) {
    vector<vector<double>>mat2(0);
    vector<double>v2;
    
    for(double i=0; i<v.size()-1; i++) {
        if(v[i]>=v[i+1]) v2.push_back(v[i]); 
        else if(v[i]<=v[i+1] && v2.size()!=0) { v2.push_back(v[i]);
    if(v2.size()>=2 ) { mat2.push_back(v2);
    v2.resize(0);
    }}}
    if(v2.size()!=0) {
        v2.push_back(v[v.size()-1]); 
        mat2.push_back(v2); 
    }
    return mat2;  
}

vector<vector<double>>RastuciPodnizovi(vector<double>v) {
    vector<vector<double>>mat(0);
    vector<double>v1;
    
    for(double i=0; i<v.size()-1; i++) {
        if(v[i]<=v[i+1]) v1.push_back(v[i]);
        else if(v[i]>=v[i+1] && v1.size()!=0){  v1.push_back(v[i]);
    if(v.size()>=2 ){
  mat.push_back(v1);
    v1.resize(0);
    }}}
    
    if(v1.size()!=0) {
        v1.push_back(v[v.size()-1]); 
        mat.push_back(v1); 
    }
    return mat;  
}


int main() 
{
    int n; 
    do{
    cout<<"Unesite broj elemenata vektora: "; 
    cin>>n; 
    } while (n<=0); 
        

    vector<double>vec(n); 
    cout<<"Unesite elemente vektora: ";
    for(double i=0; i<vec.size(); i++) cin>>vec[i];  
    
    vector<vector<double>>a=RastuciPodnizovi(vec);
    vector<vector<double>>b=OpadajuciPodnizovi(vec);
    
    cout<<"Maksimalni rastuci podnizovi: "<<endl; 
		for(double i=0; i<a.size(); i++){
		for(double k=0; k<a[i].size(); k++){
		cout<<setprecision(12) <<a[i][k]<<" "; 
		}
		cout<<endl; 
		}
    cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    
    for(double i=0; i<b.size(); i++){
		for(double kk=0; kk<=b[i].size()-1;  kk++){
		cout<<setprecision(12) <<b[i][kk]<<" "; 
		    
		}
        cout<<endl; 
    }
    
    return 0;
    
}