#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using std::cin;
using std::cout;
using std::vector;


typedef vector<vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica pocetna)
{
	if(pocetna.size()==0)
		return pocetna;
	for(int i=0;i<pocetna.size()-1;i++)
		if(pocetna[i].size()!=pocetna[i+1].size())
			throw std::domain_error ("Matrica nije korektna");
	
	Matrica nova_matrica;
	nova_matrica.resize(3*pocetna.size());
	
	//oboje
	int k(0);
	Matrica mat2;
	mat2.resize(pocetna.size());
	for(int i=pocetna.size()-1;i>=0;i--)
	{
		//vertikala
		for(int j=0;j<pocetna[i].size();j++)
		{
			mat2.at(i).push_back(pocetna.at(k).at(j));
		}
		k++;
	}
	for(int i=0;i<pocetna.size();i++)
	{
		//horizontala
		for(int j=pocetna[i].size()-1;j>=0;j--)
		{
			nova_matrica.at(i).push_back(mat2.at(i).at(j));
		}
	}
	k=0;
	for(int i=pocetna.size()-1;i>=0;i--)
	{
		//vertikala
		for(int j=0;j<pocetna[i].size();j++)
		{
			nova_matrica.at(i).push_back(pocetna.at(k).at(j));
		}
		k++;
	}
	//oboje
	for(int i=0;i<pocetna.size();i++)
	{
		//horizontala
		for(int j=pocetna[i].size()-1;j>=0;j--)
		{
			nova_matrica.at(i).push_back(mat2.at(i).at(j));
		}
	}
	
	//drugi red matrica
	k=0;
	for(int i=pocetna.size();i<2*pocetna.size();i++)
	{
		//horizontala
		for(int j=pocetna[k].size()-1;j>=0;j--)
		{
			nova_matrica.at(i).push_back(pocetna.at(k).at(j));
		}
		k++;
	}
	k=0;
	for(int i=pocetna.size();i<2*pocetna.size();i++)
	{
		//pocetna matrica
		for(int j=0;j<pocetna[k].size();j++)
		{
			nova_matrica.at(i).push_back(pocetna.at(k).at(j));
		}
		k++;
	}
	k=0;
	for(int i=pocetna.size();i<2*pocetna.size();i++)
	{
		//horizontala
		for(int j=pocetna[k].size()-1;j>=0;j--)
		{
			nova_matrica.at(i).push_back(pocetna.at(k).at(j));
		}
		k++;
	}
	//treci red matrica
	//oboje
	k=0;
	for(int i=2*pocetna.size();i<3*pocetna.size();i++)
	{
		//horizontala
		for(int j=pocetna[k].size()-1;j>=0;j--)
		{
			nova_matrica.at(i).push_back(mat2.at(k).at(j));
		}
		k++;
	}
	k=0;
	for(int i=3*pocetna.size()-1;i>=2*pocetna.size();i--)
	{
		//vertikala
		for(int j=0;j<pocetna[k].size();j++)
		{
			nova_matrica.at(i).push_back(pocetna.at(k).at(j));
		}
		k++;
	}
	//oboje
	k=0;
	for(int i=2*pocetna.size();i<3*pocetna.size();i++)
	{
		//horizontala
		for(int j=pocetna[k].size()-1;j>=0;j--)
		{
			nova_matrica.at(i).push_back(mat2.at(k).at(j));
		}
		k++;
	}
	return nova_matrica;
}
int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 or n<0)
	{
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice: ";
	Matrica pocetna;
	pocetna.resize(m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			double x(0);
			cin>>x;
			pocetna.at(i).push_back(x);
		}
	}
	try
	{
		pocetna=OgledaloMatrica(pocetna);
	}
	catch(std::domain_error ne_valja)
	{
		cout<<ne_valja.what();
	}
	cout<<"\nRezultantna matrica: \n";
	for(vector<double> x:pocetna)
	{
		for(double y:x)
			cout<<std::setw(4)<<y;
		cout<<"\n";
	}
	return 0;
}