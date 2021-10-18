#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica;

bool DaLiJePlanina(Matrica mat)
{
	vector<double> pomocni;
	for(int k=0; k<mat.size()/2 + 1; k++)
	{
		double suma(0);
		for(int i=k; i<mat.size()-k; i++)
			for(int j=k; j<mat.size()-k; j++)
				if (i==k || j==k || i==mat.size()-k-1 || j==mat.size()-k-1)
					suma+=mat.at(i).at(j);
		
		pomocni.push_back(suma);
	}
	
	for(int i=0; i<pomocni.size()-1; i++)
		if (pomocni.at(i)>=pomocni.at(i+1))
			return false;
	
	return true;		
}

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
	Matrica m;
	
	if (mat.size()==0 || mat.at(0).size()==0)
		return m;
	
	for(int i=0; i<mat.size()-1; i++)
		if (mat.at(i).size()!=mat.at(i+1).size())
			throw std::domain_error("Matrica nije korektna");
	
	int poc;
	if (mat.size() < mat.at(0).size())
		poc=mat.size();
	else
		poc=mat.at(0).size();
		
	if (poc%2==0)
		poc--;
	
	for(int k=poc; k>0; k-=2)
	{
		for(int i=0; i<=mat.size()-k; i++)
		{
			for(int j=0; j<=mat.at(0).size()-k; j++)
			{
				Matrica prep;
				prep.resize(k);
				for(int p=0; p<k; p++)
					prep.at(p).resize(k);
				
				for(int ip=i; ip<i+k; ip++)
					for(int jp=j; jp<j+k; jp++)
						prep.at(ip-i).at(jp-j)=mat.at(ip).at(jp);
				//	cout<<ip-i<<" "<<jp-j<<" "<<prep.size()<<" "<<ip<<" "<<mat.size()<< " " <<jp<<" " << mat.at(0).size()<<"\n";
						
				if (DaLiJePlanina(prep))
				{
					if (m.size()==0)
						m=prep;
					else
					{
						double vrh_novi, vrh_stari;
						vrh_stari=m.at(k/2).at(k/2);
						vrh_novi=prep.at(k/2).at(k/2);
						if (vrh_novi>vrh_stari)
							m=prep;
					}
				}
			}
		}
		if (m.size()!=0)
			break;
		
	}
	
	
	return m;
}

int main1()
{
	Matrica mat{{0,0,0}, {0,1,0}, {0,5,0}};
	cout<<(DaLiJePlanina(mat) ? "DA" : "NE");
	
}

int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if (m<0 || n<0)
	{
	    cout<<"Dimenzije matrice moraju biti nenegativne!";
	    return 0;
	}
	
	Matrica mat;
	mat.resize(m);
	for(int i=0; i<m; i++)
		mat.at(i).resize(n);
		
	cout<<"Unesite elemente matrice: ";
	double broj;
	for(int i=0; i<m; i++)
	{
	    for(int j=0; j<n; j++)
	    {
	        cin>>broj;
	        mat.at(i).at(j)=broj;
	    }
	}
	
	try
	{
	    Matrica mat_vr;
	    mat_vr=NajvecaPlaninaMatrice(mat);
	    cout<<"\nNajveca planina unesene matrice je: \n";
	    for(int i=0; i<mat_vr.size(); i++)
	    {
	        for(int j=0; j<mat_vr.at(i).size(); j++)
	            cout<<std::setw(6)<<mat_vr.at(i).at(j);
	        cout<<"\n";     
	    }
	}
	catch(std::domain_error izuzetak)
	{
	    cout<<izuzetak.what();
	}
	
	
	return 0;
}