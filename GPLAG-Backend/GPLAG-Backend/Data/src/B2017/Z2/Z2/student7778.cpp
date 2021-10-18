/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <deque>
typedef  std::vector<std::vector<double>> Matrica;
typedef std::deque<std::vector<std::vector<double>>>Mat;

Matrica KreirajMatricu(int br_redova, int br_kolona) {
 return Matrica(br_redova, std::vector<double>(br_kolona));
}



Mat UnesiMatricu(int br_redova, int br_kolona) {
 auto m(KreirajMatricu(br_redova, br_kolona));
 std::deque<std::vector<std::vector<double>>>dek;

 for(int p = 0; p < br_kolona; p++){
 for(int i = 0; i < br_redova; i++){
 for(int j = 0; j < br_kolona; j++) {
 std::cin >> m.at(i).at(j);


 }
 }
 dek.push_back(m);
 }
 return dek;
}

void PjescaniSat(Mat dek,const int SmjerKretanja ) {
	int br(0);
	
	std::vector<std::vector<double>> mat;
	int a=dek.size();
	
	
	if(a%2==0) throw std::domain_error("3D kontejner ne zadovoljava uvjet neparnosti");
	else {
	for(int p=0; p<a ;p++){
for(int i=0;i<a;i++) {
	for(int j=0; j<a;j++) {

	if(SmjerKretanja==2) {
	if((i>j && j<a-i-1) || (j>i && j>a-i-1)) {br++;std::cout<<std::setw(4)<<"  "; continue;}
	std::cout<<std::setw(4)<<dek[p][i][j];
	if(j<a) std::cout<<"";
	
	
	}
	
	if(SmjerKretanja==3) {
		 std::deque<std::vector<std::vector<double>>>dek1;
		 dek1=dek;
    dek1[p][i][j]=dek[p][dek.size()-i-1][j];
		if((i>j && j<a-i-1) || (j>i && j>a-i-1)) {br++;std::cout<<std::setw(4)<<"  "; continue;}
	std::cout<<std::setw(4)<<dek1[p][i][j];
	if(j<a) std::cout<<"";
		
	}
	if(SmjerKretanja==4) {
	std::deque<std::vector<std::vector<double>>>dek2;
	dek2=dek;
	dek2[p][i][j]=dek[p][j][i];
	if((i>j && j<a-i-1) || (j>i && j>a-i-1)) {br++;std::cout<<std::setw(4)<<"  "; continue;}
	std::cout<<std::setw(4)<<dek2[p][i][j];
	if(j<a) std::cout<<"";
	
	}
	
	if(SmjerKretanja==5){
	std::deque<std::vector<std::vector<double>>>dek2;
	dek2=dek;
	dek2[p][i][j]=dek[p][j][dek.size()-1-i];
	if((i>j && j<a-i-1) || (j>i && j>a-i-1)) {br++;std::cout<<std::setw(4)<<"  "; continue;}
	std::cout<<std::setw(4)<<dek2[p][i][j];
	if(j<a) std::cout<<"";
	
		
	}
	if(SmjerKretanja==0){
		std::deque<std::vector<std::vector<double>>>dek2;
		dek2=dek;
		if(p==0)
		dek2[p][i][j]=dek[p+i][i-i][j];
		else {  dek2[p][i][j]=dek[p-i][i][j];}
		std::cout<<std::setw(4)<<dek2[p][i][j];
		
	}
	
	
		
	}
	std::cout<<std::endl;
}
	std::cout<<std::endl;
	
	}	
	
	
}
}




int main ()
{
	 try 
 {
	int a, b;
typedef std::vector<std::vector<int>> Matrica;
Matrica m(std::vector<int>);

	std::cout<<"Unesite dimenziju (x/y/z): ";
	std::cin>>a;
	if(a<0){
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		std::cin>>a;
	}
	std::cout<<"Unesite elemente kontejnera: ";
	auto A(UnesiMatricu(a, a));
			
	
	
	
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	std::cin>>b;
	if(b>5 || b<0){ std::cout<<"Smjer nije ispravan, unesite opet: ";
	std::cin>>b;
	}
	std::cout<<std::endl;
	if(a%2!=0){
	std::cout<<"Pjescani sat unesene matrice je:\n";
	}
	PjescaniSat(A, b);
	
	
 } catch(std::domain_error IZUZETAK)
   {
    std::cout <<std::endl<<"Izuzetak: "<< IZUZETAK.what() << std::endl;
   }
	return 0;
}



