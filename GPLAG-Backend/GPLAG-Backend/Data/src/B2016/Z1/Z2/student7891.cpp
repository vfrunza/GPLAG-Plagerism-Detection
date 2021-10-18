#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
typedef std::vector<std::vector<double>> Matrica;

Matrica VertikalnoOgledalo(Matrica mat)
{
	Matrica matrica;
	
	for(int i=mat.size()-1; i>=0; i--)
	{
		std::vector<double> vrste;
		for(int j=0; j<mat[i].size(); j++)
		{
			vrste.push_back(mat[i][j]);
		}
			matrica.push_back(vrste);
	}
	
	return matrica;
}
Matrica HorizontalnoOgledalo(Matrica mat)
{
	Matrica matrica;
	
	std::vector<double> vrste;
	for(int i=0; i<mat.size(); i++)
	{
		std::vector<double> vrste;
		for(int j=mat[i].size()-1; j>=0; j--)
		{
			
			vrste.push_back(mat[i][j]);

		}
		matrica.push_back(vrste);
		
	}
	
	return matrica;

}
Matrica HorizontalnoVertikalno( Matrica mat)
{
	Matrica matrica;
	matrica=HorizontalnoOgledalo(mat);
	return VertikalnoOgledalo(matrica);
}

std::vector<double> Sastavi( std::vector<double> v1, std::vector<double> v2)
{
	std::vector<double> v3 ;
	for(int i=0; i<v1.size(); i++) v3.push_back(v1[i]);
	for(int i=0; i<v2.size(); i++) v3.push_back(v2[i]);
	for(int i=0; i<v1.size(); i++) v3.push_back(v1[i]);
	return v3;
	
}



Matrica OgledaloMatrica(Matrica mat)
{
	
	
	bool tacno(false);
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=i+1; j<mat.size(); j++)
		{
			if(mat[i].size()!=mat[j].size()){
				tacno=true;
				break;
				
			}
		}
		if(tacno==true) break;
		
	}
	if(tacno==true) throw std::domain_error("Matrica nije korektna");
	
	Matrica matrica, hv(HorizontalnoVertikalno(mat)),  v(VertikalnoOgledalo(mat)), h(HorizontalnoOgledalo(mat));

	for(int i=0; i<mat.size(); i++)
	{
			std::vector<double> vrste=hv[i];
			std::vector<double> vertikalno=v[i];
			std::vector<double> red=Sastavi(vrste,vertikalno);
		
			matrica.push_back(red);
	}
		for(int i=0; i<mat.size(); i++)
	{
			std::vector<double> vrste=h[i];
			std::vector<double> m=mat[i];
			std::vector<double> red=Sastavi(vrste,m);
			matrica.push_back(red);
	}
		for(int i=0; i<mat.size(); i++)
	{
			std::vector<double> vrste=hv[i];
			std::vector<double> vertikalno=v[i];
			std::vector<double> red=Sastavi(vrste,vertikalno);
		
			matrica.push_back(red);
	}

	
	return matrica;


	
}





int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!"<<endl;
		return 0 ;
	}
	cout<<"Unesite elemente matrice: ";
	std::vector<double> vrste ;
	Matrica mat;
	mat.resize(m);
	for(int i=0; i<m; i++)
	{
		mat[i].resize(n);
	}
	for(int i=0; i<m ; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>mat[i][j];
		}
	
	}
	cout<<endl;
	try{
	cout<<"Rezultantna matrica: ";
	cout<<endl;
	Matrica matrica=OgledaloMatrica(mat);
	for(int i=0; i<matrica.size() ; i++)
	{
		for(int j=0; j<matrica[i].size(); j++)
		{
			cout<<std::setw(4)<<matrica[i][j];
		}
		cout<<endl;
	}}
	catch(std::domain_error izuzetak)
   {
      std::cout << izuzetak.what() << std::endl;
   }
	
	

	
	return 0;
}