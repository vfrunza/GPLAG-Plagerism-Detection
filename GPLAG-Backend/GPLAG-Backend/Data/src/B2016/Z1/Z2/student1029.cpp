/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include<iostream>
#include<vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<vector<double>> horizontalna(vector<vector<double>> matrica)
{
	vector<double> vrste;
	vector<vector<double>> nova_matrica;

	for(int i=0; i<matrica.size(); i++) {
		vector<double> vrste;
		for(int j=matrica[i].size()-1; j>=0; j--) {
			vrste.push_back(matrica[i][j]);
		}
		nova_matrica.push_back(vrste);
	}

	return nova_matrica;
}

vector<vector<double>> vertikalna(vector<vector<double>> matrica)
{
	vector<double> kolone;
	vector<vector<double>> nova_matrica;

	for(int i=matrica.size()-1; i>=0; i--) {
		vector<double> kolone;
		for(int j=0; j<matrica[i].size(); j++) {
			kolone.push_back(matrica[i][j]);
		}
		nova_matrica.push_back(kolone);
	}

	return nova_matrica;
}

vector<vector<double>> hv(vector<vector<double>> matrica)
{
	vector<vector<double>> matrica1;
	vector<vector<double>> matrica2;
	matrica1=horizontalna(matrica);
	matrica2=vertikalna(matrica1);

	return matrica2;
}


vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica)
{
	bool grbava=false;
	for(int i=0; i<matrica.size(); i++) {
		for(int j=i+1; j<matrica.size(); j++) {
			if(matrica.at(i).size()!=matrica.at(j).size()) 
				grbava=true;
				break;
		}
		if(grbava==true) break;
	}
	if(grbava==true) throw std::domain_error("Matrica nije korektna");

	vector<vector<double>> hor=horizontalna(matrica);
	vector<vector<double>> ver=vertikalna(matrica);
	vector<vector<double>> mj=hv(matrica);
	double kolone,vrste;
	if(matrica.size()==0) {
		kolone=0;
		vrste=0;
	} else {
		kolone=2*mj[0].size()+ver[0].size();
		vrste=2*mj.size()+hor.size();
	}

	vector<vector<double>> glavna(vrste, vector<double>(kolone));

	for(int i=0; i<mj.size(); i++) { //hv
		for(int j=0; j<mj[i].size(); j++) {
			glavna[i][j]=mj[i][j];
		}
	}

	for(int i=0; i<ver.size(); i++) { //V
		for(int j=0; j<ver[i].size(); j++) {
			glavna[i][j+mj[0].size()]=ver[i][j];
		}
	}

	for(int i=0; i<mj.size(); i++) { //hv
		for(int j=0; j<mj[i].size(); j++) {
			glavna[i][j+2*mj[0].size()]=mj[i][j];
		}
	}

	for(int i=0; i<hor.size(); i++) { //h
		for(int j=0; j<hor[i].size(); j++) {
			glavna[i+mj.size()][j]=hor[i][j];
		}
	}

	for(int i=0; i<matrica.size(); i++) { //M
		for(int j=0; j<matrica[i].size(); j++) {
			glavna[i+ver.size()][j+hor[i].size()]=matrica[i][j];
		}
	}

	for(int i=0; i<hor.size(); i++) { //h
		for(int j=0; j<hor[i].size(); j++) {
			glavna[i+mj.size()][2*hor[i].size()+j]=hor[i][j];
		}
	}

	for(int i=0; i<mj.size(); i++) { //hv
		for(int j=0; j<mj[0].size(); j++) {
			glavna[2*mj.size()+i][j]=mj[i][j];
		}
	}

	for(int i=0; i<ver.size(); i++) { //V
		for(int j=0; j<ver[i].size(); j++) {
			glavna[2*ver.size()+i][mj[i].size()+j]=ver[i][j];
		}
	}

	for(int i=0; i<mj.size(); i++) {
		for(int j=0; j<mj[i].size(); j++) {
			glavna[2*mj.size()+i][2*mj[i].size()+j]=mj[i][j];
		}
	}

	return glavna;
}

int main ()
{
	int m,n;
	vector<vector<double>> matrica;

	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(n<0 || m<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}


	matrica.resize(m);
	for(int i=0; i<m; i++) {
		matrica[i].resize(n);
	}

	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>matrica[i][j];
		}
	}

	cout<<endl;

	try {
		cout<<"Rezultantna matrica: "<<endl;
		vector<vector<double>> matrica_konacna=OgledaloMatrica(matrica);
		for(int i=0; i<matrica_konacna.size(); i++) {
			for(int j=0; j<matrica_konacna[i].size(); j++) {
				cout<<std::setw(4)<<matrica_konacna[i][j];
			}
			cout<<endl;
		}
	} catch(std::domain_error viska)  {
		cout<<viska.what()<<endl;
	}

	return 0;
}