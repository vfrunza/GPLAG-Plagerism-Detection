#include <iostream>
#include <vector>
using namespace std;
vector<vector<double> > RastuciPodnizovi(vector<double>v)
{
    vector< vector<double> > mat;
    for(int i=0; i<v.size()-1; i++)
    {
        int j=i;
        vector<double> pom;
        while(1)
        {
           if(j==v.size()) break;
           if(v[i]>v[j]) break;
           pom.push_back(v[j]);
           if(j==i) {j++; continue;}
           i++; j++;
        }
        if(pom.size()>1) {mat.push_back(pom);}
    }
    return mat;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> v)
{
    vector<vector<double> >mat;
    for(int i=0;i<v.size()-1;i++)
    {
        int j=i;
        vector<double>pom;
        while(1)
        {
            if(j==v.size()) break;
            if(v[i]<v[j]) break;
            pom.push_back(v[j]);
            if(i==j) {j++; continue;}
            i++; j++;
        }
        if(pom.size()>1) mat.push_back(pom);
    }
    return mat;
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n; cin>>n;
	vector<double>v; v.resize(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++) cin>>v[i];
	vector<vector<double>> mat1=RastuciPodnizovi(v);
	vector<vector<double>> mat2=OpadajuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0; i<mat1.size(); i++)
	{
	    for(int j=0; j<mat1[i].size(); j++)
	    {
	        cout<<mat1[i][j]<<" ";
	    } cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0; i<mat2.size(); i++)
	{
	    for(int j=0; j<mat2[i].size(); j++)
	    {
	        cout<<mat2[i][j]<<" ";
	    } cout<<endl;
	}
	return 0;
}