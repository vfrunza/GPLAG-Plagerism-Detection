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
using std::vector;
using std::domain_error;
using std::endl;
using std::setw;
int brojkolonamatrice(vector<vector<double>> m)
{ return((!m.size()) ? 0 : m.at(0).size());


}//funkcija za brojanje kolona matrice da bi skratili kod
vector <vector<double> > HorizontalnoOgledalo(vector<vector<double>> m1)
{
	vector <vector<double> > nekamatrica;
	int velicina=m1.size();

	nekamatrica.resize(velicina);


	
  for(int i=0;i<m1.size();i++){
		for(int j=m1[i].size()-1;j>=0; j--) {
			nekamatrica [i].push_back(m1.at(i).at(j));

		}}
	return nekamatrica;
}//Horizontalno ogledalo - krecem od prvog reda, ali zadnje kolone i premjestam elemente u novu matricu koju nakon premjestenih elemenata vracam iz fje
//Vertikalno ogledalo- zamjena redova pomocu for petlje
vector<vector<double> > VertikalnoOgledalo(vector<vector<double>> m1)
{
	vector<vector<double>> nekamatrica;


	for(int i=m1.size()-1;i>=0;i--){
	
			nekamatrica.push_back(m1.at(i));
		}
	

	return nekamatrica;
}
  //kombinovano ogledalo dobivamo pozivom funkcije horizontalno ogledalo na vec promjenjenu matricu u vertikalno
vector <vector<double> > KombinovanoOgledalo(vector<vector<double> > m1)
{
return HorizontalnoOgledalo(VertikalnoOgledalo(m1));
}

vector <vector<double> > OgledaloMatrica(vector<vector<double> > matrica){
if(matrica.size()==0) return matrica;//ako je matrica prazna samo vrati praznu
for (int i=0;i<matrica.size();i++){
	if(i!=matrica.size()-1 && matrica[i].size()!=matrica[i+1].size()){
		throw domain_error("Matrica nije korektna"); 
	}
}//slucaj grbave matrice baca izuzetak

vector<vector<double> > hv;
	vector<vector<double> > v;
	vector<vector<double> > h;
	vector<vector<double> > ogledalomatrica;
	int duzina=matrica.size();
	ogledalomatrica.resize(3*duzina);
//ova matrica ce biti dimenzija 3*mx3*n
	hv=KombinovanoOgledalo(matrica);
	v=VertikalnoOgledalo(matrica);
	h=HorizontalnoOgledalo(matrica);
   
	for(int i=0; i<hv.size(); i++) {
		for(int j=0; j<hv[i].size(); j++) {
			ogledalomatrica[i].push_back(hv[i][j]);
		}
	}
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v[i].size(); j++) {
			ogledalomatrica[i].push_back(v[i][j]);
		}
	}
	for(int i=0; i<hv.size(); i++) {
		for(int j=0; j<hv[i].size(); j++) {
			ogledalomatrica[i].push_back(hv[i][j]);
		}
	}
	int a=hv.size()+h.size();
	for(int i=h.size(); i<a; i++) {
		for(int j=0; j<h[i-h.size()].size(); j++) {
			ogledalomatrica[i].push_back(h[i-h.size()][j]);
		}
	}
	
	for(int i=matrica.size(); i<a; i++) {
		for(int j=0; j<matrica[i-hv.size()].size(); j++) {
			ogledalomatrica[i].push_back(matrica[i-hv.size()][j]);
		}
	}
	for(int i=hv.size(); i<a; i++) {
		for(int j=0; j<h[i-hv.size()].size(); j++) {
			ogledalomatrica[i].push_back(h[i-hv.size()][j]);
		}
	}
	int b=a+hv.size();
	for(int i=a; i<b; i++) {
	for(int j=0; j<hv[i-a].size(); j++) {
			ogledalomatrica[i].push_back(hv[i-a][j]);
		}}
		for(int i=a; i<b; i++) {
	for(int j=0; j<v[i-a].size(); j++) {
			ogledalomatrica[i].push_back(v[i-a][j]);
		}}
			for(int i=a; i<b; i++) {
	for(int j=0; j<hv[i-a].size(); j++) {
			ogledalomatrica[i].push_back(hv[i-a][j]);
		}}
		return ogledalomatrica;}
		
	



	int main () {
	try{
int n(0),m(0);

cout<<"Unesite dimenzije matrice (m n): ";
cin>>n;
cin>>m;
if(m<0 || n<0){cout<<"Dimenzije matrice moraju biti nenegativne! "<<endl; return 0;}//m i nula ne smiju biti manji od nula
vector<vector<double> > matrica(n, vector <double> (m));
matrica.resize(n);
//ispis elemenata
cout<<"Unesite elemente matrice: "<<endl;
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		cin>>matrica[i][j];

	}
}
vector <vector<double> > matrica2;
matrica2=OgledaloMatrica(matrica);
cout<<"Rezultantna matrica: "<<endl;
for(int i=0;i<3*n;i++){
	for(int j=0;j<3*m;j++){
	cout<<setw(4)<<matrica2[i][j];
}cout<<endl;}}
	catch(domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}


		return 0;
	}