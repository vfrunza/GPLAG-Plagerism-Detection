#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> vektor;
bool JesuLiJednaki (double x, double y, double Eps = 1e-10) {
    return std::fabs(x-y) <= Eps* (std::fabs(x)+std::fabs(y)); 
}
Matrica KreirajMatricu (int br_redova, int br_kolona){
    return Matrica(br_redova, vektor(br_kolona));
}
Matrica UnesiMatricu (int br_redova, int br_kolona){
    if (br_redova == 0 || br_kolona ==0) return KreirajMatricu(0,0); 
    Matrica M(KreirajMatricu(br_redova, br_kolona));
    for (int i=0; i<br_redova; i++)
        for (int j=0; j<br_kolona; j++)
            std::cin>>M.at(i).at(j);
    return M;
}

bool opseg (int br_redova, int c, int i ){
if (i-c<0 || i-c>= br_redova || i+c<0 || i+c>= br_redova) return 1;
return 0;
}
double suma0 (int c, int i, int j, Matrica M){
double zbir(0);
for (int a = i-c; a<=i+c; a++) {
    for (int b= j-c; b<=j+c; b++) {
                zbir+=M.at(a).at(b);
        }
    }
return zbir;
}
double suma (int c, int i, int j, Matrica M){
double zbir(0);
for (int a = i-c; a<=i+c; a++) {
    for (int b= j-c; b<=j+c; b++) {
                zbir+=M.at(a).at(b);
        }
    }
    zbir-= suma0 (c-1, i, j, M);
return zbir;
}

Matrica Planina (double x, Matrica M, int i, int j){
int c(1);
Matrica planina;
planina.push_back(vektor(1,M.at(i).at(j)));
int br_redova ( M.size());
int br_kolona (M.at(0).size());
    for (;;) {
    if ( opseg (br_redova, c, i) || opseg (br_kolona, c, j)  ) return planina;
    if (c>1) 
        {if ( suma(c-1, i, j, M)<suma(c, i, j, M) && !JesuLiJednaki(suma(c-1,i,j,M), suma(c, i, j, M)) ) return planina;}
 
    if (M.at(i).at(j)<=suma(c,i,j,M) || JesuLiJednaki(M.at(i).at(j), suma(c,i,j,M)) ) return planina; 
     planina.resize(0);
    int red(0);
        for (int a = i-c; a<=i+c; a++) {
            int kolona (0);
            planina.push_back(vektor(2*c+1));
            for (int b= j-c; b<=j+c; b++) {
                planina.at(red).at(kolona) = M.at(a).at(b);
                kolona++;
                }
            red++;
    }
    c++;
    }
}

void daLiJeGrbava (Matrica M) {
    for (int i=1; i<M.size(); i++)
        if (M.at(0).size()!=M.at(i).size()) throw std::domain_error ("Matrica nije korektna");
}

Matrica NajvecaPlaninaMatrice (Matrica M){
    if (!M.size()) return KreirajMatricu(0, 0);
    for (int i=0; i<M.size(); i++)
        if (M.at(i).size()==0) return KreirajMatricu(0, 0); 
    
      daLiJeGrbava(M); 
std::vector<Matrica> planine;
    for (int i=0; i<M.size(); i++)
        for (int j=0; j<M.at(0).size(); j++)
            planine.push_back(Planina(M.at(i).at(j), M, i,j));
///





std::vector<Matrica> najvece;
int najveca(planine.at(0).size());
    for (int i=0; i<planine.size(); i++) {
        if (planine.at(i).size()>najveca) najveca = planine.at(i).size();
    }

std::vector <int> koordinate1;
std::vector <int> koordinate2;
//std::cout<<"planine size je .."<<planine.size()<<",";
for (int i=0; i<planine.size(); i++) {
    if (planine.at(i).size()==najveca) {
       
        najvece.push_back(planine.at(i));
        if (planine.at(i).size()!=0) {
        koordinate1.push_back(i/M.at(0).size());
        koordinate2.push_back(i%M.at(0).size());
        }
        else {
         koordinate1.push_back(-1);
         koordinate2.push_back(-1);
        }
    }
}



std::vector<double> vrhovi;
double vrh;
std::vector<int> vrhkoordinate1;
std::vector<int> vrhkoordinate2;
for (int i=0; i<najvece.size(); i++){
    if (koordinate1.at(i)!=-1){
           vrh = M.at(koordinate1.at(i)).at(koordinate2.at(i));
           break;
    }
}



for (int i=0; i<najvece.size(); i++){
    if (koordinate1.at(i)!=-1){
           if( M.at(koordinate1.at(i)).at(koordinate2.at(i))> vrh && !JesuLiJednaki(M.at(koordinate1.at(i)).at(koordinate2.at(i)), vrh)) vrh = M.at(koordinate1.at(i)).at(koordinate2.at(i));
    }
}

// OVDJE JE PROBLEM!!!!
//for (int i=0; i<najvece.size(); i++)
  //  std::cout<<koordinate1.at(i)<<","<<koordinate2.at(i); 
    


for (int i=0; i<najvece.size(); i++){
    if (koordinate1.at(i)!=-1 && JesuLiJednaki(M.at(koordinate1.at(i)).at(koordinate2.at(i)), vrh )){
        vrhovi.push_back(vrh);
        vrhkoordinate1.push_back(koordinate1.at(i));
        vrhkoordinate2.push_back(koordinate2.at(i));
    }
}

if (!vrhkoordinate1.size()) return KreirajMatricu(0,0);
std::vector<int> vrhkoordinate1max;
int k1max (vrhkoordinate1.at(0));
for (int i=1; i<vrhovi.size(); i++)
    if (vrhkoordinate1.at(i)>k1max) k1max = vrhkoordinate1.at(i);
int k2max;
for (int i=0; i<vrhovi.size(); i++)
    if (vrhkoordinate1.at(i) == k1max) { k2max = vrhkoordinate2.at(i); break;  }
for (int i=0; i<vrhovi.size(); i++) if (vrhkoordinate1.at(i) == k1max && vrhkoordinate2.at(i)>k2max) k2max=vrhkoordinate2.at(i);




    return Planina(M.at(k1max).at(k2max), M, k1max, k2max);
}
void Ispisi (Matrica m){
    for (int i=0; i<m.size(); i++){
        for (int j=0; j<m.at(0).size(); j++)
            std::cout<<std::setw(6)<<m.at(i).at(j);
     std::cout<<std::endl;       
    }
}


int main () {
int m, n;
std::cout<<"Unesite dimenzije matrice (m i n): ";
std::cin>>m>>n;
if (m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
std::cout<<"Unesite elemente matrice: ";
Matrica M (UnesiMatricu(m,n));
std::cout<<"\nNajveca planina unesene matrice je:\n";
try {
Ispisi (NajvecaPlaninaMatrice(M));
}
catch (std::domain_error e){
    std::cout<<e.what(); 
}



}