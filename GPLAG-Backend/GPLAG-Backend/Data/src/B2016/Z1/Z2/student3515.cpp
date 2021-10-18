/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

vector<vector<double>> unesi(vector<vector<double>> mat)
{
    for(int i=0;i<mat.size();i++)
    {for(int j=0;j<mat[i].size();j++)
        cin >> mat[i][j];
        }
        return mat;
}
void ispisi (vector<vector<double>> mat)
{
    for(int i=0;i<mat.size();i++)
    {for(int j=0;j<mat[i].size();j++) 
          cout << setfill(' ') << setw(4)<< mat[i][j];
        cout<<endl; } 
}
vector<vector<double>> HorizontalnoOgledalo(vector<vector<double>> m)
{

	double pom;
	if(m.size()==0 || m[0].size()==0 ) return m;
	for(int i=0;i<m.size();i++)
	{
		if(m[i].size()%2!=0){
		for(int j=m[i].size()-1;j>m[i].size()/2;j--)
		{
			pom=m[i][m[i].size()-1-j];	
			m[i][m[i].size()-1-j]=m[i][j];
			m[i][j]=pom;
		} }
		else {
				for(int j=m[i].size()-1;j>=m[i].size()/2;j--)
		{
			pom=m[i][m[i].size()-1-j];	
			m[i][m[i].size()-1-j]=m[i][j];
			m[i][j]=pom;
		} 
		}
		
	}
	return m;
}
vector<vector<double>> VertikalnoOgledalo(vector<vector<double>> m)
{
	double pom;
	if(m.size()==0 || m[0].size()==0 ) return m;
	else if(m.size()%2!=0) {
	for(int i=m.size()-1;i>m.size()/2;i--)
	{
		for(int j=0;j<m[i].size();j++)
		{
			pom=m[m.size()-1-i][j];
			m[m.size()-1-i][j]=m[i][j];
			m[i][j]=pom;
		}
	} }
	else {
	for(int i=m.size()-1;i>=m.size()/2;i--)
	{
		for(int j=0;j<m[i].size();j++)
		{
			pom=m[m.size()-1-i][j];
			m[m.size()-1-i][j]=m[i][j];
			m[i][j]=pom;
		}
	} }
	return m;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>>m)
{
	for(int i=0;i<m.size();i++) {
	if(m[0].size()!=m[i].size()) throw domain_error("Matrica nije korektna"); }
	if(m.size()==0) return m;
	vector<vector<double>> mat(3*m.size(), vector<double> (3*m[0].size()));
	vector<vector<double>> mhv(m.size(),vector<double>(m[0].size()));
	mhv=HorizontalnoOgledalo(m);
	mhv=VertikalnoOgledalo(mhv);
	vector<vector<double>> mv(m.size(),vector<double>(m[0].size()));
	mv=VertikalnoOgledalo(m);
	vector<vector<double>> mh(m.size(),vector<double>(m[0].size()));
	mh=HorizontalnoOgledalo(m);
	
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(i<m.size() && j<m[i].size()) mat[i][j]=mhv[i][j];
			else if(i<m.size() && j<2*m[i].size()) mat[i][j]=mv[i][j-m[i].size()];
			else if(i<m.size() && j<3*m[i].size()) mat[i][j]=mhv[i][j-2*m[i].size()];
			else if(i<2*m.size() && j<m[i-m.size()].size()) mat[i][j]=mh[i-m.size()][j];
			else if(i<2*m.size() && j<2*m[i-m.size()].size()) mat[i][j]=m[i-m.size()][j-m[i-m.size()].size()];
			else if(i<2*m.size() && j<3*m[i-m.size()].size()) mat[i][j]=mh[i-m.size()][j-2*m[i-m.size()].size()];
			else if(i<3*m.size() && j<m[i-2*m.size()].size()) mat[i][j]=mhv[i-2*m.size()][j];
			else if(i<3*m.size() && j<2*m[i-2*m.size()].size()) mat[i][j]=mv[i-2*m.size()][j-m[i-2*m.size()].size()];
			else if(i<3*m.size() && j<3*m[i-2*m.size()].size()) mat[i][j]=mhv[i-2*m.size()][j-2*m[i-2*m.size()].size()]; 
		}
	}
	return mat;
}

int main ()
{
	try {
	int r,k;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>r>>k;
	if(r<0 || k<0) cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
	vector<vector<double>>m(r, vector<double>(k));
	cout<<"Unesite elemente matrice: "<<endl;
	m=unesi(m);
	m=OgledaloMatrica(m);
	cout<<"Rezultantna matrica: "<<endl;
	ispisi(m);
} }
catch(domain_error izuzetak) {
	cout<<izuzetak.what()<<endl;
}

	
	return 0;
}