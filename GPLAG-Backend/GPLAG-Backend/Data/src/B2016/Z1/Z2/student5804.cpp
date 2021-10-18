#include<iostream>
#include<vector>
#include <iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;

//Vraća broj redova zadane matrice
/*int BrojRedova(Matrica m) {
 return m.size();
}*/
// Vraća broj kolona zadane matrice
/*int BrojKolona(Matrica m) {
 return m[0].size();
}*/
void IspisiMatricu(Matrica m){
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		std::cout<<std::setw(4)<<m[i][j];
		std::cout<<std::endl;
	}
}
Matrica h_matrica(Matrica m){
	Matrica hm(m.size(),std::vector<double>(m[0].size()));
	int i,j,k;
    for(i=0;i<m.size();i++){
    	k=m[0].size()-1;
    	for(j=0;j<m[i].size();j++){
    		hm[i][j]=m[i][k];
    		k--;
		}}
 return hm;}
 Matrica v_matrica(Matrica m){
 	Matrica vm(m.size(),std::vector<double>(m[0].size()));
 	int i,j,k;
 	k=m.size()-1;
 	for(i=0;i<m.size();i++){
 		
 		for(j=0;j<m[i].size();j++){
 			vm[i][j]=m[k][j];
 		}
 		k--;
 	}
 	return vm;
 }
Matrica kombinovano(Matrica m){
 	Matrica hv(m.size(),std::vector<double>(m[0].size()));
 	int i,j,k,l;
 	k=m.size()-1;
 	for(i=0;i<m.size();i++){
 		l=m[0].size()-1;
 		for(j=0;j<m[i].size();j++){
 			hv[i][j]=m[k][l];
 			l--;
 		}
 		k--;
 	}
 	return hv;
 }
Matrica OgledaloMatrica(Matrica m){
Matrica hm,vm,hv;
hm=h_matrica(m);
vm=v_matrica(m);
hv=kombinovano(m);
int red=m.size();
int kolona=m[0].size();



Matrica Ogledalo(m.size()*3,std::vector<double>(m[0].size()*3));
for(int i=0;i<red;i++)for(int j=0;j<kolona;j++) Ogledalo[i][j]=hv[i][j];
for(int i=0;i<red;i++)for(int j=kolona;j<2*kolona;j++) Ogledalo[i][j]=vm[i][j-kolona];
for(int i=0;i<red;i++)for(int j=2*kolona;j<3*kolona;j++) Ogledalo[i][j]=hv[i][j-2*kolona];
for(int i=red;i<2*red;i++)for(int j=0;j<kolona;j++) Ogledalo[i][j]=hm[i-red][j];
for(int i=red;i<2*red;i++)for(int j=kolona;j<2*kolona;j++) Ogledalo[i][j]=m[i-red][j-kolona];
for(int i=red;i<2*red;i++)for(int j=2*kolona;j<3*kolona;j++) Ogledalo[i][j]=hm[i-red][j-2*kolona];
for(int i=red*2;i<3*red;i++)for(int j=0;j<kolona;j++) Ogledalo[i][j]=hv[i-2*red][j];
for(int i=red*2;i<3*red;i++)for(int j=kolona;j<2*kolona;j++) Ogledalo[i][j]=vm[i-2*red][j-kolona];
for(int i=red*2;i<3*red;i++)for(int j=2*kolona;j<3*kolona;j++) Ogledalo[i][j]=hv[i-2*red][j-2*kolona];

return Ogledalo;	
}
int main ()
{ int m,n;try{
std::cout<<"Unesite dimenzije matrice (m n): ";
std::cin>>m>>n;
if(n<0 || m<0) throw "Dimenzije matrice moraju biti nenegativne!";
if(n==0 && m==0) throw std::domain_error("Unesite elemente matrice:\nRezultantna matrica: ");
std::cout<<"Unesite elemente matrice:";
Matrica mat(m,std::vector<double>(n));
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
	std::cin>>mat[i][j];

}}
Matrica ogledalo;
ogledalo=OgledaloMatrica(mat);
std::cout<<"\nRezultantna matrica:";
std::cout<<std::endl;
IspisiMatricu(ogledalo);
}
catch(const char izuzetak[]){
	std::cout<<izuzetak;
}
catch(std::domain_error poruka){
	std::cout<<poruka.what();
}
	return 0;
}
