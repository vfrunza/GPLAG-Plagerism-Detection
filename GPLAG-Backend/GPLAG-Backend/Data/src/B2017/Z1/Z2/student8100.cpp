#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>

using namespace std;

int Najvecii(vector<vector<double>> *mat)
{
	int najveci=*mat.at(0).at(0);
	int najvecii=0;
	for(int i=0; i<(int)*mat.size(); i++)
		for(int j=0; j<(int)*mat.at(i).size(); j++)
			if(*mat.at(i).at(j)>najveci)
			{
				najveci=*mat.at(i).at(j);
				najvecii=i;
			}
	return najvecii;
}

int Najvecij(vector<vector<double>> *mat)
{
	int najveci=*mat.at(0).at(0);
	int najvecij=0;
	for(int i=0; i<(int)*mat.size(); i++)
		for(int j=0; j<(int)*mat.at(i).size(); j++)
			if(*mat.at(i).at(j)>najveci)
			{
				najveci=*mat.at(i).at(j);
				najvecij=i;
			}
	return najvecij;
}


int NajveciElement(vector<vector<double>> *mat)
{
	int najveci=*mat.at(0).at(0);
	for(int i=0; i<(int)*mat.size(); i++)
		for(int j=0; j<(int)*mat.at(i).size(); j++)
			if(*mat.at(i).at(j)>najveci)
				najveci=*mat.at(i).at(j);
	return najveci;
}

int SumaOko(int i, int j, int br, vector<vector<double>> *matrica)
{
	int suma(0);
	for(int k=j-br; k<=j+br; k++) {
		if(i+br>=(int)*matrica.size() || i-br<0 || k<0 || k>=(int)*matrica.at(i).size())
			return suma;
		suma+=*matrica.at(i-br).at(k)+*matrica.at(i+br).at(k);
	}
	for(int l=i-br+1; l<=i+br-1; l++) {
		if(l<0 || l>=(int)*matrica.size() || j-br>=(int)*matrica.at(i).size() || j<0)
			return suma;
		suma+=*matrica.at(l).at(j-br)+*matrica.at(l).at(j+br);
	}
	return suma;
}

vector<vector<double>> KatujMatricu(int i, int j, int br, vector<vector<double>> *matrica)
{
	vector<vector<double>> matrica2(2*br+1, vector<double>(2*br+1));

	for(int l=i-br; l<=i+br; l++)
		for(int s=j-br; s<=j+br; s++) {
			if(l-i+br>=0 && l-i+br<2*br+1 && s-j+br>=0 && s-j+br<2*br+1 && l>=0 && l<int(*matrica.size()) && s>=0 && s<int(*matrica.at(0).size()))
				matrica2.at(l-i+br).at(s-j+br)=*matrica.at(l).at(s);
		}
	return matrica2;
}


vector<vector<double>> NajvecaPlaninaMatrice(vector<vector<double>> matrica)
{
	vector<vector<double>> pomocna;
	if(matrica.size()==0)
		return pomocna;
	for(int i=1; i<int(matrica.size()); i++)
		if(matrica.at(i).size()!=matrica.at(0).size())
			throw domain_error("Matrica nije korektna");
	if(matrica.at(0).size()==0)
		return pomocna;


	int br(0), br1(0), cuvari(0), cuvarj(0);
	vector<vector<double>> MaksimalnaMatrica(1, vector<double>(1));
	MaksimalnaMatrica.at(0).at(0)=NajveciElement(&matrica);

	int koi, koj;
	koi=Najvecii(&matrica);
	koj=Najvecij(&matrica);
	
	for(int i=1; i<(int)matrica.size()-1; i++) {
		for(int j=1; j<(int)matrica.at(i).size()-1; j++) {
			if(SumaOko(i, j, 1, &matrica)<matrica.at(i).at(j)) {
				br=2;
				while(br<=i && br<=j && br<=(int)matrica.size()-1-i && br<=(int)matrica.at(i).size()-1-j && SumaOko(i, j, br-1, &matrica)>SumaOko(i, j, br, &matrica))
					br++;
				if(br-1>br1) {
					MaksimalnaMatrica=KatujMatricu(i, j, br-1, &matrica);
					cuvari=KatujMatricu(i, j, br-1, &matrica).size()/2+1;
					cuvarj=KatujMatricu(i, j, br-1, &matrica).size()/2+1;
					br1=br-1;
				} else if(br-1==br1) {
					if(KatujMatricu(i, j, br-1, &matrica).at(br-1).at(br-1)>MaksimalnaMatrica.at(cuvari).at(cuvarj) && ((i<koi) || (i==koi && j<koj))){
						MaksimalnaMatrica=KatujMatricu(i, j, br-1, &matrica);
					koi=i;
					koj=j;
					cuvari=br-1;
					cuvarj=br-1;}
					br1=br-1;
				}
			}
		}
	}
	return MaksimalnaMatrica;
}

int main ()
{
	int red, kol;
	double a;
	vector<vector<double>> matrica(0);
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>red>>kol;
	if(red<0 || kol<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 1;
	}
	matrica.resize(red);
	for(int i=0; i<red; i++)
		matrica.at(i).resize(kol);
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<red; i++)
		for(int j=0; j<kol; j++) {
			cin>>a;
			matrica.at(i).at(j)=a;
		}
	vector<vector<double>> d=NajvecaPlaninaMatrice(matrica);
	cout<<"\nNajveca planina unesene matrice je: "<<endl;
	for(int i=0; i<(int)d.size(); i++) {
		for(int j=0; j<(int)d.at(i).size(); j++)
			cout<<setw(6)<<right<<d.at(i).at(j);
		cout<<endl;
	}
	return 0;
}