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
#include <vector>
#include <stdexcept>
#include <iomanip>


typedef std::vector<std::vector<double>> Matrica;

using std::cout;
using std::cin;
using std::endl;

double Suma_Kvadrata(Matrica mat, int n, int l, int k){ // n je mogući format, (l,k) gornji lijevi "kraj" moguće planine
	
	double suma{0};

	
	for(int i=l;i<n+l;i++){
		for(int j=k;j<n+k;j++){
			if(i==l || j==k || i==n+l-1 || j==n+k-1) suma+=mat.at(i).at(j);
		}
	}
	
	return suma;
}




Matrica NajvecaPlaninaMatrice(Matrica mat){
	
	Matrica Planina;
	
	if(mat.size()==0 || mat.at(0).size()==0) return Planina; 
	
	bool regularna{true};
	

	
	for(int i=0;i<mat.size()-1;i++){
		if((mat.at(i)).size()!=(mat.at(i+1)).size() || !cin){
			regularna=false;
			break;
		}
		
	
	}
	
	
	if(!regularna) throw std::domain_error("Matrica nije korektna");
	
	
	
	std::vector<double> v;			 /* u ovaj vektor cemo smjestiti uredene trojke svih planina najveceg formata
										Trojka ce se sastojati od koordinata vrha (vrh_i,vrh_j) i vrha planine "vrh"
										Kasnije cemo porediti vrhove i koordinate */
	
	
	
	
	int max;
	max=mat.size();
	if(mat.at(0).size()<max) max=mat.at(0).size();
	
	if(max%2==0) max--; // max je teoretski najveca moguca vrijednost formata planine
	
	double suma1,suma2;
	double vrh;
	int vrh_i,vrh_j;
	int i{0},j{0};
	int n{max};
	int cnt{1};
	int format{0};
	bool planina{false};
	
	
	
	// Trazimo format planine, n je trenutni format, (vrh_i,vrh_j) su koordinate vrha planine
	   
	   while(max>=1){
	   	
	   	cnt=1;
	   	n=max;
		while(i+n<=mat.size()){
		
			cnt=1;
			while(j+n<=mat.at(0).size()){
				
				cnt=1;
			suma2=Suma_Kvadrata(mat,n,i,j);
			
			
			while(n>1){
			suma1=suma2; // vanjski kvadrat
			suma2=Suma_Kvadrata(mat,n-2,i+cnt,j+cnt); // unutrasnji kvadrat
			
			if(!(suma1<suma2)) break;	// nije planina, izlazimo iz petlje;
			n-=2; // smanjujemo format;
			cnt++;			
			}
			
			if(n==1) {
				planina=true;	// pronasli smo planinu matrice.
				vrh=suma2;
				vrh_i=max/2+i;
				vrh_j=max/2+j;
				format=max; // format planine
				
				v.push_back(vrh_i); // kooordinate vrha
				v.push_back(vrh_j);
				v.push_back(vrh); // vrh
				
		}
		j++;
		n=max;
	}

	i++;
	j=0;
	n=max;
}
if(planina) break;
max-=2; //smanjujemo format
i=0;    // krecemo ispocetka
j=0;
		
	}
	
	double max_vrh{v.at(2)};
	int max_vrh_ind{2};
	
	for(int i=2;i<v.size();i+=3){
		if (v.at(i)>max_vrh){
			max_vrh=v.at(i); 
			max_vrh_ind=i;
	}
	}
	
	for(int i=2;i<v.size();i+=3){
		if (v.at(i)<=max_vrh && v.at(i)>=max_vrh){
			if(v.at(i-2)<v.at(max_vrh_ind-2))	max_vrh_ind=i;
			else if(v.at(i-2)>=v.at(max_vrh_ind-2) && v.at(i-2)<=v.at(max_vrh_ind-2) && v.at(i-1)<v.at(max_vrh_ind-1))  max_vrh_ind=i;
		} 
	}
	
	
	vrh_i=v.at(max_vrh_ind-2);
	vrh_j=v.at(max_vrh_ind-1);
	
	int gore_lijevo_i{vrh_i-format/2};
	int gore_lijevo_j{vrh_j-format/2};
	int k{0};
	int l{0};
	
	Planina.resize(format);
	for(int i=0;i<format;i++){
	Planina.at(i).resize(format);
	}
	
	
	for(int i=gore_lijevo_i;i<format+gore_lijevo_i;i++){
		l=0;
		for(int j=gore_lijevo_j;j<format+gore_lijevo_j;j++){
		Planina.at(k).at(l)=mat.at(i).at(j);
		l++;
		}
	k++;
	}
	
	
	return Planina;
}

int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0)	{
		cout<<"Dimenzije matrice moraju biti nenegativne!"<<endl; 
		return 0;
	}
	
	Matrica a(m,std::vector<double>(n));
	
	if(m!=0 && n!=0){
	
	cout<<"Unesite elemente matrice: ";
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a.at(i).at(j);
		}
		
	}
	}
	
	try{
	auto Planina(NajvecaPlaninaMatrice(a));
	
	cout<<endl<<"Najveca planina unesene matrice je:"<<endl;
	
	for(int i=0;i<Planina.size();i++){
		for(int j=0;j<=Planina.at(i).size();j++){
			if(j==Planina.size()) cout<<endl;
			else cout<<std::setw(6)<<Planina.at(i).at(j);
		}
	}
	
	}
	
	catch(std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	
	return 0;
}