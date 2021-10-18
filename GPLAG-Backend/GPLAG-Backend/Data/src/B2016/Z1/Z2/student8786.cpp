#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;
vector<vector<double> > ver(vector<vector<double> > mat)
{
    vector<vector<double> > pom; pom.resize(mat.size());
    for(int i=0; i<mat.size(); i++) pom[i].resize(mat[i].size());
    for(int i=0; i<mat.size(); i++)
    {
        int a=mat[0].size()-1;
        for(int j=0; j<mat[i].size(); j++)
        {
            pom[i][j]=mat[i][a];
            a--;
        }
    }
    return pom;
    
}
vector<vector<double> > hor(vector<vector<double> > mat)
{
    vector<vector<double> > pom; pom.resize(mat.size());
    for(int i=0; i<mat.size(); i++) pom[i].resize(mat[i].size());
    int a=mat.size()-1;
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            pom[i][j]=mat[a][j];
        }
        a--;
    }
    return pom;
    
}
vector<vector<double> > OgledaloMatrica(vector<vector<double> > mat)
{
    for(int i=0; i<mat.size(); i++)
    {
        if(mat[i].size()!=mat[0].size()) throw domain_error("grehka");
    }
    vector<vector<double> > v = ver(mat);
    vector<vector<double> > h = hor(mat);
    vector<vector<double> > hv = hor(ver(mat));
    vector<vector<double> > r; 
    int a=0;
    while(a!=mat.size())
    {
        vector<double> pom;
        for(int j=0; j<mat[a].size(); j++) pom.push_back(hv[a][j]);
        for(int j=0; j<mat[a].size(); j++) pom.push_back(h[a][j]);
        for(int j=0; j<mat[a].size(); j++) pom.push_back(hv[a][j]);
        r.push_back(pom);
        a++;
    }
    a=0;
    while(a!=mat.size())
    {
        vector<double> pom;
        for(int j=0; j<mat[a].size(); j++) pom.push_back(v[a][j]);
        for(int j=0; j<mat[a].size(); j++) pom.push_back(mat[a][j]);
        for(int j=0; j<mat[a].size(); j++) pom.push_back(v[a][j]);
        r.push_back(pom);
        a++;
    }
    a=0;
    while(a!=mat.size())
    {
        vector<double> pom;
        for(int j=0; j<mat[a].size(); j++) pom.push_back(hv[a][j]);
        for(int j=0; j<mat[a].size(); j++) pom.push_back(h[a][j]);
        for(int j=0; j<mat[a].size(); j++) pom.push_back(hv[a][j]);
        r.push_back(pom);
        a++;
    }
    return r;
}
int main ()
{
	try
	{
	    cout<<"Unesite dimenzije matrice (m n): ";
	    int m,n; cin>>m>>n;
	    if(m<0 || n<0) { cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	    cout<<"Unesite elemente matrice: ";
	    vector<vector<double> > mat;
	    mat.resize(m); for(int i=0; i<mat.size();i++) mat[i].resize(n);
	    for(int i=0; i<mat.size(); i++)
	    for(int j=0; j<mat[i].size(); j++) cin>>mat[i][j];
	    cout<<endl<<"Rezultantna matrica: "<<endl;
	    mat=OgledaloMatrica(mat);
	    for(int i=0; i<mat.size(); i++)
	    {
	        for(int j=0; j<mat[i].size(); j++)
	        {
	            cout<<setw(4)<<right<<mat[i][j];
	        } cout<<endl;
	    }
	} catch(domain_error) { cout<<"Matrica nije korektna"; }
	return 0;
}