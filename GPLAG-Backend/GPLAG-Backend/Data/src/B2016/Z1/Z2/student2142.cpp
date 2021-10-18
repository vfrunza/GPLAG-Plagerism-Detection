/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void IspisiMatricu(vector<vector<double> > M)
{
	for(int i=0; i<M.size(); i++)
	{
		cout<<" ";
		for(int j=0; j<M[0].size(); j++)
			cout<<std::setw(3)<<M[i][j]<<" ";
		cout<<endl;
	}
}

vector<vector<double> >Horizontalno(vector<vector<double> >M)
{
	vector<vector<double> > H(M.size());
	for(int i=0; i<M.size(); i++) H[i].resize(M[0].size());
	for(int i=0; i<M.size(); i++)
		for(int j=0; j<M[0].size(); j++)
			H[i][j]=M[i][M[0].size()-j- 1];
	
	return H;
}

vector<vector<double> >Vertikalno(vector<vector<double> >M)
{
	vector<vector<double> > V(M.size());
	for(int i=0; i<M.size(); i++) V[i].resize(M[0].size());
	for(int i=0; i<M.size(); i++)
		for(int j=0; j<M[0].size(); j++)
			V[i][j]=M[M.size()-i- 1][j];
			
/*	for(int i=0; i<M.size(); i++)
	{
		V[i]=M[M.size()- 1 -i];
	}*/
			
	return V;
}

vector<vector<double> >Kombinovano(vector<vector<double> >M)
{
	vector<vector<double> > HV(M.size());
	for(int i=0; i<M.size(); i++) HV[i].resize(M[0].size());
	for(int i=0; i<M.size(); i++)
		for(int j=0; j<M[0].size(); j++)
			HV[i][j]=M[M.size()-i- 1][M[0].size()-j- 1];
			
	return HV;
}

vector<vector<double> >OgledaloMatrica(vector<vector<double> >M)
{
	for(int i=1; i<M.size(); i++)
		if(M[0].size()!=M[i].size())throw std::domain_error("Matrica nije korektna");
	
	vector<vector<double> >OM(3*M.size());
	//if(OM.size()==0)return OM;
	
	for(int i=0; i<OM.size(); i++) OM[i].resize(3*M[0].size());
	vector<vector<double> >HV(Kombinovano(M));
	vector<vector<double> >H(Horizontalno(M));
	vector<vector<double> >V(Vertikalno(M));
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[0].size(); j++)
			OM[i][j]=HV[i][j];
		for(int j=0; j<M[0].size(); j++)
			OM[i][M[0].size()+j]=V[i][j];
		for(int j=0; j<M[0].size(); j++)
			OM[i][2*M[0].size()+j]=HV[i][j];
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[0].size(); j++)
			OM[M.size()+i][j]=H[i][j];
		for(int j=0; j<M[0].size(); j++)
			OM[M.size()+i][M[0].size()+j]=M[i][j];
		for(int j=0; j<M[0].size(); j++)
			OM[M.size()+i][2*M[0].size()+j]=H[i][j];
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[0].size(); j++)
			OM[2*M.size()+i][j]=HV[i][j];
		for(int j=0; j<M[0].size(); j++)
			OM[2*M.size()+i][M[0].size()+j]=V[i][j];
		for(int j=0; j<M[0].size(); j++)
			OM[2*M.size()+i][2*M[0].size()+j]=HV[i][j];
	}
	
	return OM;
}

int main ()
{
	int m, n;
	
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	
	if(m<0 || n<0)cout<<"Dimenzije matrice moraju biti nenegativne!";
	else
	{
		vector<vector<double> >M(m, vector<double>(n));
		cout<<"Unesite elemente matrice: ";
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				cin>>M[i][j];
			
		cout<<endl<<"Rezultantna matrica:"<<endl;
	
		IspisiMatricu(OgledaloMatrica(M));
	}
	
	
	/*int m, n;
	cout<<"Unesite broj redova: ";
	cin>>m;
	cout<<"Unesite broj kolona: ";
	cin>>n;
	
	vector<vector<double> >M(m, vector<double>(n));
	
	cout<<"Unesite elemente matrice: "<<endl;
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>M[i][j];
			
	vector<vector<double> >OM(OgledaloMatrica(M));
	
	for(int i=0; i<OM.size(); i++)
	{
		for(int j=0; j<OM[0].size(); j++)
			cout<<OM[i][j]<<" ";
		cout<<endl;
	}
	
	*/
	
	/*vector<vector<double> > h(Horizontalno({{1,2,3}, {4,5,6}}));
	vector<vector<double> > v(Vertikalno({{1,2,3}, {4,5,6}}));
	vector<vector<double> > k(Kombinovano({{1,2,3}, {4,5,6}}));
	
	for(int i=0; i<h.size(); i++)
	{
		for(int j=0; j<h[0].size(); j++)
			cout<<h[i][j]<<" ";
		cout<<endl;
	}
	
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[0].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	
	for(int i=0; i<k.size(); i++)
	{
		for(int j=0; j<k[0].size(); j++)
			cout<<k[i][j]<<" ";
		cout<<endl;
	}*/
	
	return 0;
}