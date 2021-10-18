/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using std::vector;
using std::cout;
using std::cin;
typedef vector<vector<double>> MAT;
const double EP=0.001;

bool DaLiJeGrbava(MAT &mat){
	for(int i(1);i<mat.size();i++){
		if(mat.at(i).size()!=mat.at(0).size()) throw std::domain_error("Matrica nije korektna");
	}
	if(mat.at(0).size()==0) return true;
	return false;
}

vector<double> MaxEl(MAT &mat){
	vector<double> v;
	for(auto &red : mat)
		for(auto &x:red) v.push_back(x);
	for(int i(0);i<v.size();i++){
		for(int j(i+1);j<v.size();j++){
			if((v.at(i)-v.at(j)<EP) && (v.at(i)-v.at(j)>-EP)){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	for(int i(0);i<v.size();i++){
		for(int j(0);j<v.size();j++){
			if(v.at(i)>v.at(j)){
				double pom(v.at(i));
				v.at(i)=v.at(j);
				v.at(j)=pom;
			}
		}
	}
	return v;
}

int DimMaxPodMat(int i,int j,int p,int d){
	int d1(0),d2(0);
	if(p-1<=i-p) d1=p-1;
	else d1=i-p;
	if(d-1<=j-d) d2=d-1;
	else d2=j-d;
	if(d1<=d2) return d1;
	return d2;
}

double SumaKv(MAT &mat,int br,int centar){
	double suma(0);
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat.at(i).size();j++){
			if((i==centar-br || i==centar+br) && (j>=centar-br && j<=centar+br)) suma+=mat.at(i).at(j);
			if((j==centar-br || j==centar+br) && (i>centar-br && i<centar+br)) suma+=mat.at(i).at(j);
		}
	}
	return suma;
}

MAT Oblikovnje(MAT mat){
	if(mat.size()==1) return mat;
	int dim=(mat.size()-1)/2;
	vector<double> v;
	v.push_back(mat.at(dim).at(dim));
	for(int i(0);i<dim;i++){
		double k(0);
		k=SumaKv(mat,i+1,dim);
		v.push_back(k);
	}
	for(int i(1);i<v.size();i++){
		if(v.at(i)>=v.at(i-1)){
			for(int j(0);j<v.size()-i;j++){
				mat.erase(mat.end()-1);
				mat.erase(mat.begin());
			}
			for(int k(0);k<mat.size();k++){
				for(int j(0);j<v.size()-i;j++){
				mat.at(k).erase(mat.at(k).end()-1);
				mat.at(k).erase(mat.at(k).begin());	
				}
			}
			return mat;
		}
	}
	return mat;
}

MAT PronadjiVrhMat(MAT &mat,double br){
	vector<MAT> v;
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat.at(i).size();j++){
			if((mat.at(i).at(j)-br<=EP) && (mat.at(i).at(j)-br>=-EP)){
				int dim=DimMaxPodMat(mat.size(),mat.at(i).size(),i+1,j+1);
				MAT podmat;
				int d(0);
				for(int k(i-dim);k<i+dim+1;k++){
					podmat.resize(podmat.size()+1);
					for(int l(j-dim);l<j+dim+1;l++){
						podmat.at(d).push_back(mat.at(k).at(l));
					}
					d++;
				}
				podmat=Oblikovnje(podmat);
				v.push_back(podmat);
			}
		}
	}
	if(v.size()==1) return v.at(0);
	int max(0);
	for(int i(0);i<v.size();i++){
		if(v.at(i).size()%2==0){
			v.erase(v.begin()+i);
			i--;
			}
		else if(v.at(i).size()>max) max=v.at(i).size();
	}
	for(int i(0);i<v.size();i++){
			if(v.at(i).size()<max){
				v.erase(v.begin()+i);
				i--;
			}
		}
	return v.at(0);
}

vector<vector<double>> NajvecaPlaninaMatrice(MAT mat){
	if(mat.size()==0 || (mat.size()==1 && mat.at(0).size()==0)) return MAT();
	if(mat.size()==1 && mat.at(0).size()==1) return mat;
	if(mat.size()==1 && mat.at(0).size()>1){
		vector<double> d(MaxEl(mat));
		return MAT{{d.at(0)}};
	}
	if(DaLiJeGrbava(mat)){
		return MAT();
	}
	if(mat.size()>1 && mat.at(0).size()==1){
		vector<double> d(MaxEl(mat));
		return MAT{{d.at(0)}};
	}
	vector<MAT> vrhmat;
	vector<double> max(MaxEl(mat));
	for(int i(0);i<max.size();i++){
		vrhmat.push_back(PronadjiVrhMat(mat,max.at(i)));
	}
	if(vrhmat.size()==1) return vrhmat.at(0);
	int maxi(0);
	for(int i(0);i<vrhmat.size();i++){
		if(vrhmat.at(i).size()>maxi) maxi=vrhmat.at(i).size();
	}
	for(int i(0);i<vrhmat.size();i++){
		if(vrhmat.at(i).size()<maxi){
			vrhmat.erase(vrhmat.begin()+i);
			i--;
		}
	}
	return vrhmat.at(0);
}

int main ()
{
	int m(0),n(0);
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice:";
	MAT mat;
	for(int i(0);i<m;i++){
		mat.resize(mat.size()+1);
		for(int j(0);j<n;j++){
			double k(0);
			cin>>k;
			mat.at(i).push_back(k);
		}
	}
	try{
		MAT Planina=NajvecaPlaninaMatrice(mat);
		cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
		for(vector<double> &v : Planina){
					for(double &i : v) cout<<std::right<<std::setw(6)<<i;
					cout<<std::endl;
				}
	}
	catch(std::domain_error izuzetak){
		cout<<izuzetak.what();
	}
	return 0;
}