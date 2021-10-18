/*B 2016/2017, Zadaća 1, Zadatak 2 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;

vector<vector<double>> HorizontalnaMatrica(vector<vector<double>> mat){
	int pocetak(0);
   	unsigned int kraj;
    double temp;
    
    //Ako je prazna, vraca je nazad
    if(mat.size()==0 || mat[0].size()==0) return mat;
    
	for(int i=0; i<mat.size(); i++){
		//Resetovanje pocetka i kraja na vrijednosti za novi vektor
		pocetak=0;
		kraj=mat[i].size()-1;
		
		while(pocetak<kraj){
      		//Izmjena
      		temp=mat[i][pocetak];
      		mat[i][pocetak]=mat[i][kraj];
      		mat[i][kraj]=temp;
      
      		//Inkrementacija/Dekrementacija pocetne i krajnje vrijednosti
      		pocetak++;
      		kraj--;
   		}
	}
	
	return mat;
}

vector<vector<double>> VertikalnaMatrica(vector<vector<double>> mat){
	int pocetak(0);
   	unsigned int kraj;
    double temp;
    
    int duzina(mat[0].size());
	for(int i=0; i<duzina; i++){
		//Resetovanje pocetka i kraja na vrijednosti za novi vektor
		pocetak=0;
		kraj=mat.size()-1;
		
		while(pocetak<kraj){
      		//Izmjena
      		temp=mat[pocetak][i];
      		mat[pocetak][i]=mat[kraj][i];
      		mat[kraj][i]=temp;
      
      		//Inkrementacija/Dekrementacija pocetne i krajnje vrijednosti
      		pocetak++;
      		kraj--;
   		}
	}
	
	return mat;
}


vector<vector<double>> OgledaloMatrica(vector<vector<double>> mat){
	//Provjera da nije unesena prazna matrica
	int duzina(mat.size());
	if(duzina==0) return mat;
	
	//U slucaju da je crnom magijom unesena grbava matrica
	for(int i=0; i<duzina-1; i++){
		if(mat[i].size()!=mat[i+1].size()) throw std::domain_error("Matrica nije korektna.");
		if(i+1==duzina-1) break;
	}
	
	//Sirina matrice za bolju preglednost, nije potrebna ali je korisna
	int sirina(mat[0].size());
	
	//Matrice koje su nam potrebne za konacnu matricu
	vector<vector<double>> hmat(HorizontalnaMatrica(mat));
	vector<vector<double>> vmat(VertikalnaMatrica(mat));
	vector<vector<double>> mijesana(HorizontalnaMatrica(vmat));
	
	//Matrica postaje 3 puta veca jer umjesto jedne MxN matrice imamo 3M x 3N matrica
	unsigned int redovi(duzina*3);
	unsigned int kolone(sirina*3);
	
	//Ovo vracamo na kraju, matrica od matrica
	vector<vector<double>> ogl(redovi);
	
	//Pomocna varijabla koja ce nam govoriti gdje u matrici trenutno ispisujemo
	int red(0);
	//Sastavljanje matrice "OGL" (za ogledalo) koju cemo vratiti
	for(int i=0; i<redovi; i++){
		//Max. vrijednost varijable "RED" je jedna trecina matrice, tako da je koristimo kao brojac pri ubacivanju redova podmatrica
		if(red>=redovi/3) red=0;
		
		//Unosi prvi i treci "red" ogledala matrice, tj. unosi matrice koje trebaju biti u tim "redovima" ako je posmatramo kao matricu matrica
		if(i<redovi/3 || i>=2*redovi/3){
			//Ove petlje unose citav red matrica jedan za drugim tako da ispravno formiraju red glavne matrice
			//Broj reda koji unose ovisi o varijabli "RED" ciji je rad gore naveden
			
			for(int a=0; a<kolone/3; a++){
				ogl[i].push_back(mijesana[red][a]);
			}
			
			for(int b=0; b<kolone/3; b++){
				ogl[i].push_back(vmat[red][b]);
			}
			
			for(int c=0; c<kolone/3; c++){
				ogl[i].push_back(mijesana[red][c]);
			}
		} //Uslov stavljen kao ELSE IF a ne samo IF tako da ne preuzme kontrolu nad pocetnim redovima matrice vec samo nad sredinom
		else if(i<2*redovi/3){
			for(int a=0; a<kolone/3; a++){
				ogl[i].push_back(hmat[red][a]);
			}
			
			for(int b=0; b<kolone/3; b++){
				ogl[i].push_back(mat[red][b]);
			}
			
			for(int c=0; c<kolone/3; c++){
				ogl[i].push_back(hmat[red][c]);
			}
		}
		//Pomjeranje da pomocne matrice gledaju u svoj sljedeci red
		red++;
	}
	
	
	//Stavljati for loopove koji ce push_back-ati clanove tog reda tako da se izvode jedan nakog drugog na nacin da se isprinta red
	//jedne, pa red druge itd. pa se onda mijenja broj reda u drugom for loopu, pa se redovi podmatrica ponovo ubacuju itd.
	
	//temp matrica koja se dobija pozivanjem funkcija, njeni elementi se pushbackaju na nasu matricu tako da budu u istom redu
	//mozda da odredimo raspon za svaku podmatricu i da kad jednu izracunamo da je ubacimo na sva mjesta gdje treba biti
	/* Redom idu:
		HV V HV
		H  M  H
		HV V HV
	
	*/
	
	
	return ogl;
}


int main(){
	int m, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if(m<0 || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	//Resize-amo matricu na unesene dimenzije tako da mozemo fino unijeti elemente
	vector<vector<double>> matrica;
	matrica.resize(m);
	for(int i=0; i<m; i++){
		matrica[i].resize(n);
	}
	
	cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> matrica[i][j];
		}
	}
	
	cout << std::endl;
	
	vector<vector<double>> ogledalo;
	try{
		ogledalo=OgledaloMatrica(matrica);
	} catch(std::domain_error greska) {
        //Ako je doslo do greske, ispisuje je i okoncava program
        cout << greska.what();
        return 0;
	}
	cout << "Rezultantna matrica:" << std::endl;
	for(auto x : ogledalo){
		for(auto y : x){
			cout << std::setw(4) << y;
		}
		cout << std::endl;
	}
	
	return 0;
}