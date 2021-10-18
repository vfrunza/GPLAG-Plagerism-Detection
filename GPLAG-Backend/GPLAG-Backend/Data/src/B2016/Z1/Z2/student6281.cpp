/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <stdexcept>
#include <vector>  
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona) {
return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu (int br_redova, int br_kolona) {
auto m(KreirajMatricu(br_redova, br_kolona));

for (int i(0); i<br_redova; i++) {
    for(int j(0); j<br_kolona; j++ ) {
        std::cin >> m[i][j];
    }
}
return m;
}

int BrojRedova (Matrica m) {
return m.size();
}

int BrojKolona (Matrica m) {
    if(m.size()==0) return 0;
    else return m[0].size();
}

void IspisiMatricu (Matrica m) {
    for (int i(0); i<BrojRedova(m); i++) {
        for (int j(0); j<BrojKolona(m); j++)
        std::cout << std::setw(4) << m[i][j];
        std::cout << std::endl;
    }
    
}

Matrica VertikalnaMatrica (Matrica m) {
for (int i(0); i< BrojRedova(m)/2; i++){
    for (int j(0); j<BrojKolona(m); j++) {
        double pom=m[i][j];
        m[i][j]=m[BrojRedova(m)-1-i][j];
        m[BrojRedova(m)-1-i][j]=pom;
    }
}
return m;
}

Matrica HorizontalnaMatrica (Matrica m) {
for (int i(0); i<BrojRedova(m); i++){
    for (int j(0); j<BrojKolona(m)/2; j++) {
        double pom=m[i][j];
        m[i][j]=m[i][BrojKolona(m)-1-j];
        m[i][BrojKolona(m)-1-j]=pom;
    }
}
return m;
}

Matrica Horiz_Vertik (Matrica m) {
    Matrica M;
    M=HorizontalnaMatrica(VertikalnaMatrica(m));
    return M;
}

Matrica OgledaloMatrica (Matrica m) {
int br_redova(BrojRedova(m)*3), br_kolona(BrojKolona(m)*3);
Matrica m1(br_redova, std::vector<double>(br_kolona)), vertikalna, horizontalna, horz_vert;
vertikalna=VertikalnaMatrica(m);
horizontalna=HorizontalnaMatrica(m);
horz_vert= Horiz_Vertik(m);
if (m.size()==0) {
    return m1;
}

for (int i(0); i<m.size(); i++) {
    for ( int j(0); j<m[i].size(); j++){
    if (m[0].size() != m[i].size()) throw std::domain_error ("Matrica nije korektna");
}
}



for (int i(0); i<m.size(); i++) {
    for (int j(0); j<m[0].size(); j++){
   m1[i][j]=horz_vert[i][j];
   m1[i][BrojKolona(m)+j]=vertikalna[i][j];
   m1[i][2*BrojKolona(m)+j]=horz_vert[i][j];
   m1[BrojRedova(m)+i][j]=horizontalna[i][j];
   m1[BrojRedova(m)+i][BrojKolona(m)+j]=m[i][j];
   m1[BrojRedova(m)+i][2*BrojKolona(m)+j]=horizontalna[i][j];
   m1[2*BrojRedova(m)+i][j]=horz_vert[i][j];
   m1[2*BrojRedova(m)+i][BrojKolona(m)+j]=vertikalna[i][j];
   m1[2*BrojRedova(m)+i][2*BrojKolona(m)+j]=horz_vert[i][j];
   
    }
}
 return m1;   
}
        
int main () {
    try {
int m, n;
Matrica m1;
Matrica m2;
std::cout << "Unesite dimenzije matrice (m n): ";
std::cin >> m >> n;
if (m < 0 || n < 0) {
    std:: cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
    return 0;
}
std::cout << "Unesite elemente matrice: ";
m1=UnesiMatricu(m, n);
m2=OgledaloMatrica(m1);
std::cout<< std::endl;
std::cout << "Rezultantna matrica: "  << std::endl;
IspisiMatricu(m2);
}
catch (std::domain_error izuzetak) {
    std::cout << izuzetak.what() << std::endl;
}
return 0;
}
