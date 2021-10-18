#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;


// Kreira matricu sa zadanim brojem redova i kolona

Matrica KreirajMatricu(int br_redova, int br_kolona) {
 return Matrica(br_redova, std::vector<double>(br_kolona));
}

// Vraća broj redova zadane matrice
int BrojRedova(Matrica m) {
 return m.size();
}
// Vraća broj kolona zadane matrice
int BrojKolona(Matrica m) {
 return m[0].size();
}

// Unosi sa tastature matricu sa zadanim brojem redova i kolona i vraća je kao rezultat

Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto mat(KreirajMatricu(br_redova, br_kolona));
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
 std::cin >> mat[i][j];
 }
 return mat;
}


// Ispisuje zadanu matricu
void IspisiMatricu(Matrica m) {
 for(int i = 0; i < BrojRedova(m); i++) {
 for(int j = 0; j < BrojKolona(m); j++)
 std::cout << std::setw(4) << m[i][j];
 std::cout << std::endl;
 }
}


// Funkcija koja obrce redoslijed redova u matrici

Matrica VertikalnaMatrica(Matrica matFunkc){
unsigned int br_redova=matFunkc.size();
unsigned int br_kolona=matFunkc[0].size();
Matrica mat{br_redova, std::vector<double> (br_kolona)};
for(int i = 0; i < br_redova; i++){
for(int j = 0; j < br_kolona; j++){

mat[i][j]=matFunkc[br_redova-i-1][j];
}

}
return mat;

}

// Funkcija koja obrce redoslijed kolona u matrici

Matrica HorizontalnaMatrica(Matrica matFunkc){
unsigned int br_redova=matFunkc.size();
unsigned int br_kolona=matFunkc[0].size();
Matrica mat{br_redova, std::vector<double> (br_kolona)};
for(int i = 0; i < br_redova; i++){
for(int j = 0; j < br_kolona; j++){

mat[i][j]=matFunkc[i][br_kolona-j-1];
}

}
return mat;

}


// Funkcija koja pravi finalnu matricu

Matrica OgledaloMatrica(Matrica M){
if(M.size()==0) return M;
auto H = HorizontalnaMatrica(M);
auto V = VertikalnaMatrica(M);
auto HV = HorizontalnaMatrica(VertikalnaMatrica(M));
unsigned int br_redova = BrojRedova(M);
unsigned int br_kolona = BrojKolona(M);



auto m3(KreirajMatricu(br_redova*3, br_kolona*3));



for(int i=0;i<br_redova;i++){
 for(int j=0;j<br_kolona;j++){
  m3[i][j]=HV[i][j];
 }
}
 

for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i][j+br_kolona]=V[i][j];
    }
}


for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i][j+2*br_kolona]=HV[i][j];
    }
}



for(int i=0;i<br_redova;i++){
    for(int j=0; j<br_kolona;j++){
    m3[i+br_redova][j]=H[i][j];
    }
}


for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i+br_redova][j+br_kolona]=M[i][j];
    }
} 
 
 
for(int i=0;i<br_redova;i++){
    for(int j=0; j<br_kolona;j++){
    m3[i+br_redova][j]=H[i][j];
    }
}


for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i+br_redova][j+2*br_kolona]=H[i][j];
    }
} 
 
 
for(int i=0;i<br_redova;i++){
    for(int j=0; j<br_kolona;j++){
    m3[i+br_redova][j]=H[i][j];
    }
}


for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i+2*br_redova][j]=HV[i][j];
    }
}  
 
for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i+2*br_redova][j+br_kolona]=V[i][j];
    }
}  
  
for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++){
        m3[i+2*br_redova][j+2*br_kolona]=HV[i][j];
    }
}  



return m3;
 
}




int main() {
 int m, n;
 std::cout << "Unesite dimenzije matrice (m n): ";
 std::cin >> m >> n;
 if(m<0 || n<0){
  std::cout <<"Dimenzije matrice moraju biti nenegativne!";
  return 0;
 }
 std::cout << "Unesite elemente matrice: \n";
 
 if(m==0 && n==0){
  std::cout <<"Rezultantna matrica: \n";
  return 0;}
 
 auto Unos(UnesiMatricu(m, n));

 auto Finalna(OgledaloMatrica(Unos));
 
std::cout <<"Rezultantna matrica: \n";
 IspisiMatricu(Finalna);
 
 










 return 0;

}
