#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace::std;

vector<vector<double>> OgledaloMatrica(vector<vector<double>> m)
{
	if(m.size() == 0)
		return vector<vector<double>>(0);
	vector<vector<double>> h,v(m.size()),hv(m.size());
	for(int i = 0; i < m.size();i++)
	{
		hv[i].resize(m[0].size());
		if(i > 0)
		{
			if(m[i].size() != m[i-1].size())
				throw domain_error("Matrica nije korektna");
		}
	}
	vector<double> hv0(m.size()*m[0].size());
	for(int i = 0;i < m.size(); i++)
	{
		h.push_back(m[m.size()-1-i]);
	}

	for(int i = 0;i < m.size(); i++)
	{
		for(int j = 0; j < m[0].size() ; j++)
		{
			v[i].push_back(m[i][m[i].size()-1-j]);
			hv0[i*m[0].size()+j] = m[i][j];
		}
	}
	for(int i = 0;i < hv0.size()/2; i++)
	{
		double temp = hv0[hv0.size()-i-1];
		hv0[hv0.size()-i-1] = hv0[i];
		hv0[i] = temp;
	}
	for(int i = 0; i < m.size() ;i++)
	{
		for(int j = 0; j < m[0].size(); j++)
		{
			hv[i][j] = hv0[i*m[0].size()+j];
		}
	}
	vector<vector<double>> ogl(3*m.size());
	for(int i = 0;i < ogl.size();i++)
	ogl[i].resize(3*m[0].size());
	for(int i = 0; i < m.size(); i++)
	{
		for(int j = 0; j < m[0].size();j++)
		{
			ogl[i][j] = 1;
			ogl[i][j] = hv[i][j];
			ogl[2*m.size()+i][j] = hv[i][j];
			ogl[i][2*m[0].size()+j] = hv[i][j];
			ogl[2*m.size()+i][2*m[0].size()+j] = hv[i][j];
			ogl[i][m[0].size()+j] = h[i][j];
			ogl[2*m.size()+i][m[0].size()+j] = h[i][j];
			ogl[m.size()+i][j] = v[i][j];
			ogl[m.size()+i][2*m[0].size()+j] = v[i][j];
			ogl[m.size()+i][m[0].size()+j] = m[i][j];
		}
	}

	return ogl;
}
int main ()
{
	int m,n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m;
	cin >> n;
	if(m < 0 || n < 0)
	{
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	vector<vector<double>> mat(m);
	cout << "Unesite elemente matrice: " << endl;
	for(int i = 0; i< m ; i++)
	{
		mat[i].resize(n);
		for(int j = 0;j < n; j++)
		cin >> mat[i][j];
	}
	cout << "Rezultantna matrica: " << endl;
	try
	{
	vector<vector<double>> o = OgledaloMatrica(mat);
	}
	catch(exception& e)
	{
		cout << e.what();
	}
		vector<vector<double>> o = OgledaloMatrica(mat);
	for(int i = 0; i < o.size();i++)
	{
		for(int j = 0; j < o[i].size();j++)
		{
			cout << setw(4);
			cout << o[i][j];
		}
		cout << endl;
	}
	return 0;
}