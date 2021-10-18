#include<iostream>
#include <vector> 

using namespace std;
vector<vector<double>>RastuciPodnizovi(vector<double>v)
{
    vector<vector<double>>mat;
    
    int i=0;
    while(i<v.size()-1)
    {
        vector<double>v2;
        v2.resize(0);
        if(v[i]<=v[i+1])
        {
            while(i<v.size()-1 && v[i]<=v[i+1] ) {
                if(i>=v.size()-1) break;
                v2.push_back(v[i]);
                i++;
                
            }
            v2.push_back(v[i]);
        }
        else{i++; continue; }
       
        mat.push_back(v2);
    }
    
    return mat;
}
vector<vector<double>>OpadajuciPodnizovi(vector<double>v)
{
    vector<vector<double>>mat;
    int i=0;
    while(i<v.size()-1)
    {
        vector<double>v2;
        v2.resize(0);
        if(v[i]>=v[i+1])
        {
            while(i<v.size()-1 && v[i]>=v[i+1])
            {
                if(i>=v.size()-1) break;
                v2.push_back(v[i]);
                i++;
            }
            v2.push_back(v[i]);
        }
        else{
            i++;
            continue;
        }
        mat.push_back(v2);
    }
    return mat;
}

int main ()
{
    vector<double>v;
    int n;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    v.resize(n);
    cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<vector<double>>mat2=RastuciPodnizovi(v);
    cout<<"Maksimalni rastuci podnizovi:";
    cout<<endl;
    for(int i=0;i<mat2.size();i++)
    {
        for(int j=0;j<mat2[i].size();j++)
        cout<<mat2[i][j]<<" ";
        
        cout<<endl;
    }
    vector<vector<double>>mat3=OpadajuciPodnizovi(v);
    cout<<"Maksimalni opadajuci podnizovi:";
    cout<<endl;
     for(int i=0;i<mat3.size();i++)
    {
        for(int j=0;j<mat3[i].size();j++)
        cout<<mat3[i][j]<<" ";
        
        cout<<endl;
    }
    
	return 0;
}