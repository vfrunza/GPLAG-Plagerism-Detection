#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>>Matrica;

Matrica UnesiMatricu(int broj_redova,int broj_kolona){
Matrica m(broj_redova,std::vector<double>(broj_kolona));
for(int i=0;i<broj_redova;i++){
for(int j=0;j<broj_kolona;j++){
std::cin>>m[i][j];
}
}
return m;
}

Matrica OgledaloMatrica(Matrica m){
if(m.size()==0){
    return m;
}

for(int i=0;i<m.size();i++){
if(m[i].size()!=m[0].size()){
throw std::domain_error("Uneli ste grbavu matricu...");
}
}
if(m.size()!=0){
Matrica Ogledalo(3*m.size(),std::vector<double>(3*m[0].size()));

Matrica M;
M=m;
Matrica Hv(M.size(),std::vector<double>(m[0].size()));    

for(int i=0;i<M.size();i++){
for(int j=0;j<M[i].size();j++){
Hv[i][j]=M[M.size()-i-1][M[i].size()-j-1];
}
}
Matrica Vm(M.size(),std::vector<double>(M[0].size()));    

for(int i=0;i<m.size();i++){
for(int j=0;j<m[0].size();j++){
Vm[i][j]=M[m.size()-i-1][j];
}
}
Matrica H(M.size(),std::vector<double>(M[0].size()));
for(int i=0;i<M.size();i++){
for(int j=0;j<M[i].size();j++){
H[i][j]=Vm[M.size()-i-1][M[i].size()-j-1];
}
}

for(int i=0;i<Ogledalo.size();i++){
for(int j=0;j<Ogledalo[0].size();j++){
if(i<m.size() && j<m[0].size())
{
Ogledalo[i][j]=Hv[i][j];
}
else if (i<m.size() && (j>=2*m[0].size() && j<Ogledalo[0].size())){
Ogledalo[i][j]=Hv[i][j-2*m[0].size()];
}
else if((i>=Ogledalo.size()-m.size() && i<Ogledalo.size()) && (j<m[0].size())){
Ogledalo[i][j]=Hv[i-2*m.size()][j];
}
else if((i>=Ogledalo.size()-m.size() && i<Ogledalo.size() && (j>=2*m[0].size() && j<Ogledalo[0].size()))){
Ogledalo[i][j]=Hv[i-2*m.size()][j-2*m[0].size()];
}
else if((i>=m.size() && i<2*m.size()) &&(j<m[0].size())){
Ogledalo[i][j]=H[i-m.size()][j];
}
else if((i>=m.size() && i<2*m.size()) && (j>=2*m[0].size() && j<Ogledalo[0].size())){
Ogledalo[i][j]=H[i-m.size()][j-2*m[0].size()];
}
else if(i<m.size() && (j>=m[0].size()&& j<Ogledalo[0].size()-m[0].size())){
Ogledalo[i][j]=Vm[i][j-m[0].size()];
}
else if((i>=m.size() && i<2*m.size()&& (j>=m[0].size() && j<Ogledalo[0].size()-m[0].size()))){
Ogledalo[i][j]=m[i-m.size()][j-m[0].size()];
}


else if((i>=2*m.size() && i<Ogledalo.size()) && (j>=m[0].size() && j<Ogledalo[0].size()-m[0].size())){
Ogledalo[i][j]=Vm[i-2*m.size()][j-m[0].size()];
}

}
}

return Ogledalo;
}}
	


int main ()
{
int n,m;
Matrica M;
Matrica N;
std::cout<<"Unesite dimenzije matrice (m n): ";
std::cin>>n>>m;
if(n<0 || m<0){
std::cout<<"Dimenzije matrice moraju biti nenegativne!";
return 0;
}
std::cout<<"Unesite elemente matrice: ";
M=UnesiMatricu(n,m);
N=OgledaloMatrica(M);
std::cout<<std::endl;
try{
Matrica rezultat(3*m,std::vector<double>(3*n));

std::cout<<"Rezultantna matrica: "<<std::endl;
if(M.size()==0){
return 0;
}
rezultat=OgledaloMatrica(M);
if(rezultat.size()!=0){
for(int i=0;i<rezultat.size();i++){
for(int j=0;j<rezultat[0].size();j++){
std::cout<<std::setw(4)<<rezultat[i][j];
}
std::cout<<std::endl;
}
}
}
catch(std::domain_error) {
std::cout<<"greska";
}
return 0;
}