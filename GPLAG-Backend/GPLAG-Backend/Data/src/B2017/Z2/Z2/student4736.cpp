#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;
enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

enum class Smjer
{
    Dole, Desno, Lijevo
};


template <typename M>
M okreni(M mat, Smjer s)
{
	M nova_mat;
	switch(s) {
	case Smjer::Dole:
		for (int i = mat.size()-1; i >=0 ; i--) {
			nova_mat.push_back(mat.at(i));
		}
		break;
	case Smjer::Lijevo:
		nova_mat.resize(mat.size());
		for (int j = mat.size()-1,p=0; j >=0 ; j--,p++) {
			for (int i = 0; i < mat.size(); i++) {
				nova_mat[p].push_back(mat.at(i).at(j));
			}
		}
		break;

	case Smjer::Desno:
		nova_mat.resize(mat.size());
		for (int j = 0,p=0; j <mat.size() ; j++,p++) {
			for (int i = 0; i<mat.size(); i++) {
				nova_mat[p].push_back(mat.at(i).at(j)); // mat.at(i).at(j)
			}
		}
		break;

	}
	return nova_mat;
}
template <typename M>
M pretvori_u_pjescanu_gore_dole(M matrica)
{
	M nova_matrica(matrica.size());
	int k=0;
	for (int i = 0; i < matrica.size(); i++) {

		for (int j = k; j < matrica.at(i).size()-k; j++) {
			nova_matrica[i].push_back(matrica.at(i).at(j));
		}
		if(i<matrica.size()/2)k++;
		else k--;
	}
	return nova_matrica;
}

template <typename M>
void ispisi_mat(M mat)
{
	int k=0;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < k; j++) {
			cout<<"    ";
		}
		for (int j = 0; j < mat.at(i).size(); j++) {
			cout<<setw(4)<<mat.at(i).at(j);
		}
		if(i<mat.size()/2)k++;
		else k--;
		cout<<endl;
	}
}

template <typename T>
T PjescaniSat(T kont, SmjerKretanja smjer )
{
	auto matrica = kont.at(0);

	T novi_kont;
	for(auto mat:kont) {
		if(mat.size()!=kont.size())throw domain_error("3D matrica nema oblik kocke");
		for(auto red:mat) {
			if(red.size()!=mat.size()) throw domain_error("3D matrica nema oblik kocke");
		}
	}
	if(kont.size()%2==0)throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");

	switch(smjer) {
	case SmjerKretanja::GoreDolje:
		for(auto mat:kont) {
			novi_kont.push_back(pretvori_u_pjescanu_gore_dole(mat));
		}
		break;
	case SmjerKretanja::DoljeGore:
		for(auto mat:kont) {
			novi_kont.push_back(pretvori_u_pjescanu_gore_dole( okreni(mat,Smjer::Dole)));
		}
		break;
	case SmjerKretanja::DesnoLijevo:
		for(auto mat:kont) {
			novi_kont.push_back(pretvori_u_pjescanu_gore_dole( okreni(mat,Smjer::Lijevo)));
		}
		break;

	case SmjerKretanja::LijevoDesno:
		for(auto mat:kont) {
			novi_kont.push_back(pretvori_u_pjescanu_gore_dole( okreni(mat,Smjer::Desno)));
		}
		break;

	case SmjerKretanja::NaprijedNazad:
		for(int i=0; i<kont.size();i++){
			matrica.resize(0);
			for (int j = 0; j < kont.size(); j++) {
				matrica.push_back(kont.at(j).at(i));
			}
			novi_kont.push_back(pretvori_u_pjescanu_gore_dole(matrica));
		}
		break;

	case SmjerKretanja::NazadNaprijed:
		for(int i=0; i<kont.size();i++){
			matrica.resize(0);
			for (int j = kont.size()-1;j>=0;j--) {
				matrica.push_back(kont.at(j).at(i));
			}
			
			novi_kont.push_back(pretvori_u_pjescanu_gore_dole(matrica));
		}
		break;
	}

	return novi_kont;
}
int main ()
{

	try {
		int n;

		cout<<"Unesite dimenziju (x/y/z): ";
		while(true) {
			cin>>n;
			if(n<=0) {
				cout<<"Dimenzija nije ispravna, unesite opet: ";
			} else {
				break;
			}
		}
		vector<deque<deque<int>>> kontejner(n,deque<deque<int>>(n,deque<int>(n)));
		cout<<"Unesite elemente kontejnera: ";
		for(int i=0; i<kontejner.size(); i++) {
			for(int j=0; j<kontejner.at(i).size(); j++) {
				for(int k=0; k<kontejner.at(i).at(j).size(); k++) {
					cin>>kontejner.at(i).at(j).at(k);
				}
			}
		}
		cout<<"Unesite smjer kretanja [0 - 5]: ";
		int broj;
		SmjerKretanja smjer;
		while(true) {
			cin>>broj;
			if(broj<0 || broj>5) {
				cout<<"Smjer nije ispravan, unesite opet: ";
			} else {
				break;
			}
		}
		smjer =  SmjerKretanja(broj);

		vector<deque<deque<int>>>novi_kontejner= PjescaniSat(kontejner,smjer);
		cout<<endl<<"Pjescani sat unesene matrice je:"<<endl;
		for (auto mat : novi_kontejner) {
			ispisi_mat(mat);
			cout<<endl;
		}
	} catch(domain_error e) {
		cout<<endl<<"Izuzetak: "<<e.what()<<endl;
	} catch(length_error e) {
		cout<<endl<<"Izuzetak: "<<e.what()<<endl;
	}
	return 0;
}