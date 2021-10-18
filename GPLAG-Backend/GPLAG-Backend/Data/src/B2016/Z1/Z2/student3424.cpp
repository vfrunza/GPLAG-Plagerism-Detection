/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

bool jeLiGrbava(vector<vector<double>> matrica){
	if(matrica.size()==0) return false;
	for(int i=0;i<matrica.size();i++) if(matrica[i].size()!=matrica[0].size()) return true;
	return false;
}

vector<double> obrniVektore(vector<double> x, vector<double> y){
	vector<double> temp;
	temp=x;
	x=y;
	y=temp;
	return x;
}

vector<vector<double>> VertikalnaMatrica(vector<vector<double>> matrica){
	bool grbava;
	grbava=jeLiGrbava(matrica);
	if(grbava==true) throw domain_error("Matrica nije korektna");
	vector<double> temp;
	for(int i(0);i<matrica.size()/2;i++){
		temp=matrica[i];
		matrica[i]=matrica[matrica.size()-1-i];
		matrica[matrica.size()-1-i]=obrniVektore(matrica[i], temp);
	}
	return matrica;
}

double obrni(double x, double y){
	double temp=x;
	x=y;
	y=temp;
	return x;
}

vector<vector<double>> HorizontalnaMatrica(vector<vector<double>> matrica){
	if(jeLiGrbava(matrica)) throw domain_error("Matrica nije korektna");
	for(int i(0);i<matrica.size();i++){
		for(int j(0);j<matrica[i].size()/2;j++){
			double temp=matrica[i][j];
			matrica[i][j]=matrica[i][matrica[i].size()-1-i];
			matrica[i][matrica[i].size()-1-j]=obrni(matrica[i][j],temp);
		}
	}
	return matrica;
}

vector<vector<double>> KombinovanaMatrica(vector<vector<double>> matrica){
	try{
		vector<vector<double>> temp;
		temp=HorizontalnaMatrica(matrica);
		vector<vector<double>> temp2;
		temp2=VertikalnaMatrica(temp);
	
	}
	catch(domain_error e){
		throw e;
	}
	return temp2;
}

vector<double> sabiranjeVektora(vector<double> prvi, vector<double> drugi, vector<double> treci){
	vector<double> povratni(prvi.size()+drugi.size()+treci.size());
	for(int i=0;i<prvi.size();i++) povratni[i]=prvi[i];
	for(int i=0;i<drugi.size();i++) povratni[i+prvi.size()]=drugi[i];
	for(int i=0;i<treci.size();i++) povratni[i+prvi.size()+drugi.size()]=treci[i];
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica){
	vector<vector<double>> povratni(3*matrica.size());
	try{
		vector<vector<double>> hor, ver, komb;
		hor=HorizontalnaMatrica(matrica);
		ver=VertikalnaMatrica(matrica);
		komb=KombinovanaMatrica(matrica);
		for(int i=0;i<hor.size();i++) povratni[i]=(sabiranjeVektora(komb[i],ver[i],komb[i]));
		for(int i=0;i<hor.size();i++) povratni[i]=(sabiranjeVektora(hor[i],matrica[i],hor[i]));
		for(int i=0;i<hor.size();i++) povratni[i]=(sabiranjeVektora(komb[i],ver[i],komb[i]));
	}
	catch(domain_error e){
		throw e;
	}
	return povratni;
}

int main ()
{
	try{
		cout << "Unesite dimenzije matrice (m n): ";
		int m,n;
		cin >> m >>n;
		if(m<n || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	vector<vector<double>> mat(m);
	for(int i=0;i<mat.size();i++) mat[i].resize(n);
	cout << "Unesite elemente matrice: \n";
	for(int j=0;j<m;j++){
		for(int j=0;j<n;j++){
			cin >> matrica[i][j];
		}
	}
	matrica=OgledaloMatrica(matrica);
	cout << "Rezultantna matrica: \n";
	for(int i=0;i<matrica.size();i++){
		for(int j=0;j<matrica[i].size();j++){
			cout << setw(4) << matr  ica[i][j];
		}
		cout << endl;
	}
}
catch(domain_error e){
	cout << e.what();
}
return 0;
}









