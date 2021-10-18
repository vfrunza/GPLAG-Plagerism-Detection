/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;
typedef vector<vector<double>> Matrica ;

Matrica KreirajMatricu(int br_redova,int br_kolona)
{
	return Matrica (br_redova,vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova,int br_kolona)
{
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		{
			cin >>m[i][j];
		}
	}
	return m;
}
void GrbavaMatrica (Matrica m)
{
	for(unsigned int i=0;i<m.size();i++)
	{
		if(m[i].size()!=m[0].size())
		{
			throw domain_error("Matrica nije korektna");
		}
	}
}

Matrica OgledaloMatrica(Matrica m)
{
	if(m.size()==0) return m;
	Matrica nova_mat{KreirajMatricu(3*m.size(),3*m[0].size())};
	for(unsigned int i=0;i<m.size();i++)
		for(unsigned int j=0;j<m[0].size();j++)
		{
			nova_mat[i][j]=m[m.size()-i-1][m[0].size()-j-1]; //hv(M)
			nova_mat[m.size()+i][j]=m[i][m[0].size()-j-1]; //h(M)
			nova_mat[2*m.size()+i][j]=m[m.size()-i-1][m[0].size()-j-1]; //hv(M)
			
			nova_mat[i][m[0].size()+j]=m[m.size()-i-1][j]; //v(M)
			nova_mat[m.size()+i][m[0].size()+j]=m[i][j]; //M
			nova_mat[2*m.size()+i][m[0].size()+j]=m[m.size()-i-1][j]; //v(M)
			
			nova_mat[i][2*m[0].size()+j]=m[m.size()-i-1][m[0].size()-j-1]; //hv(M)
			nova_mat[m.size()+i][2*m[0].size()+j]=m[i][m[0].size()-j-1]; //h(M)
			nova_mat[2*m.size()+i][2*m[0].size()+j]=m[m.size()-i-1][m[0].size()-j-1]; //hv(M)
		}
	return nova_mat;
}

void IspisiMatricu (Matrica m)
{
	for(unsigned int i=0;i<m.size();i++)
	{
		for(unsigned int j=0;j<m[0].size();j++)
			cout <<setw(4)<<m[i][j];
		cout <<endl;
	}
}

int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin >>m>>n;
	if(m<0 || n<0)  
	{
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout <<"Unesite elemente matrice:";
	Matrica mat{UnesiMatricu(m,n)};
	
	try {
		GrbavaMatrica(mat);
	}
	catch(domain_error izuzetak){
		cout <<izuzetak.what()<<endl;
	}
	cout <<endl<<"Rezultantna matrica:";
	cout <<endl;
	IspisiMatricu(OgledaloMatrica(mat));
	return 0;
}