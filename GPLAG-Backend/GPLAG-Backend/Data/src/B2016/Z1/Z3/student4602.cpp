#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;
vector<vector<double>> RastuciPodnizovi(vector<double>v){
    vector<double>v2;
    vector<vector<double>>mat;
    double prvi;
    prvi=v[0];
    if(v.size()==0) return mat;
    v2.push_back(prvi);
    if(v.size()==1){
        v2.push_back(prvi);
        mat.push_back(v2);
        return mat;
    }
    for(int i=1; i<v.size(); i++){
        if(prvi==v[i]){
            while(prvi==v[i]){
                v2.push_back(v[i]);
                prvi=v[i];
                i++;
            }
            mat.push_back(v2);
            return mat;
        }
        if(prvi<=v[i]){
            v2.push_back(v[i]);
            prvi=v[i];
        }
        else{
            if(v2.size()>1) mat.push_back(v2);
            v2.clear();
            v2.push_back(v[i]);
            prvi=v[i];
        }
    }
    if(v2.size()>1) mat.push_back(v2);
    return mat;
}
/*
vector<vector<double>> RastuciPodnizovi(vector<double>v){
    vector<double>v2;
    vector<vector<double>>mat;
    int prvi;
    prvi=v[0];
    if(v.size()==0) return mat;
    v2.push_back(prvi);
   if(v.size()==1) {
        v2.push_back(prvi); 
        mat.push_back(v2);
        return mat;
    }
    for(int i=1; i<v.size(); i++){
    	
    	if(prvi==v[i]){
    		while(prvi==v[i]){
    			v2.push_back(v[i]);
    			prvi=v[i];
    			i++;
    	}
    	mat.push_back(v2);
    	return mat;
    	}
        if(prvi<=v[i]){
            v2.push_back(v[i]);
            prvi=v[i];
        }
        else{
        if(v2.size()>1) mat.push_back(v2);
        v2.clear();
        v2.push_back(v[i]);
        prvi=v[i];
        }
    }
    if(v2.size()>1) mat.push_back(v2);

    return mat;
} */

vector<vector<double>> OpadajuciPodnizovi(vector<double>v){
    vector<double>v2;
    vector<vector<double>>mat;
    if(v.size()==0) return mat;
    double prvi;
    prvi=v[0];
    if(v.size()==0) return mat;
    v2.push_back(prvi);
    if(v.size()==1){
        v2.push_back(prvi);
        mat.push_back(v2);
        return mat;
    }
    for(int i=1; i<v.size(); i++){
        if(prvi==v[i]){
           while(prvi==v[i]){
                v2.push_back(v[i]);
                prvi=v[i]; 
               i++;
            }
            mat.push_back(v2);
            return mat;
        }
        if(prvi>=v[i]){
            v2.push_back(v[i]);
            prvi=v[i];
        } 
        else{
            if(v2.size()>1) mat.push_back(v2);
            v2.clear();
            v2.push_back(v[i]);
            prvi=v[i];
        }
    }
    if(v2.size()>1) mat.push_back(v2);
    return mat;
}/*
vector<vector<double>> OpadajuciPodnizovi(vector<double>v){
    vector<double>v2;
    vector<vector<double>>mat;
    if(v.size()==0) return mat;
    
    int prvi;
    prvi=v[0];
    if(v.size()==0) return mat;
    v2.push_back(prvi);
   if(v.size()==1) {
        v2.push_back(prvi); 
        mat.push_back(v2);
        return mat;
    }
   
    for(int i=1; i<v.size(); i++){
    	if(prvi==v[i]){
    		while(prvi==v[i]){
    			v2.push_back(v[i]);
    			prvi=v[i];
    			i++;
    	}
    	mat.push_back(v2);
    	return mat;
    	}
        if(prvi>=v[i]){
            v2.push_back(v[i]);
            prvi=v[i];
        }
        else{
        if(v2.size()>1) mat.push_back(v2);
        v2.clear();
        v2.push_back(v[i]);
        prvi=v[i];
        }
    }
    if(v2.size()>1)mat.push_back(v2);

    return mat;
}*/
    
int main(){
    int n;
    
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    vector<double>v;
    v.resize(n);
    cout<<"Unesite elemente vektora: ";
    for(int i=0; i<v.size(); i++){
    	cin>>v[i];
    }
    cout<<"Maksimalni rastuci podnizovi: "<<endl;
    vector<vector<double>>pom=RastuciPodnizovi(v);
    for(int i=0; i<pom.size(); i++){
        for(int j=0; j<pom[i].size(); j++){
            cout<<pom[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    vector<vector<double>>mat=OpadajuciPodnizovi(v);
    for(int i=0; i<mat.size(); i++){
    	for(int j=0; j<mat[i].size(); j++){
    		cout<<mat[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
    
}