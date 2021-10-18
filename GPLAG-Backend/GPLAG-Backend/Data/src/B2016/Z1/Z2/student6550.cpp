/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona){
   return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto m(KreirajMatricu(br_redova, br_kolona));
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
 std::cin >> m[i][j];
 }
 return m;
}

void IspisiMatricu (Matrica mat){
   for(int i=0 ; i<mat.size() ; i++){
      for(int j=0 ; j<mat[i].size() ; j++ ){
         std::cout<<std::setw(4)<<mat[i][j];
      }
         std::cout<<std::endl;
   }
}

Matrica HorizontalnoOgledalo (Matrica mat){
	for(int i=0 ; i<mat.size() ; i++){
		for(int j=mat[i].size()-1, k=0 ; j>=(mat[i].size()/2) ; j--, k++){
			int temp = mat[i][j];
			mat[i][j] = mat[i][k];
			mat[i][k] = temp;

		}
	}
		return mat;
}

Matrica VertikalnoOgledalo (Matrica mat){
	for(int i=mat.size()-1,j=0 ; i>=(mat.size()/2) ; i--, j++){
		std::vector<double> temp = mat[i];
		mat[i] = mat[j];
		mat[j] = temp;
	}
		return mat;
}

Matrica HorizontalnoVertikalnoOgledalo (Matrica mat){

		return Matrica(VertikalnoOgledalo(HorizontalnoOgledalo(mat)));
}

Matrica OgledaloMatrica (Matrica mat){

    for(int i(0); i < mat.size(); i++) if(mat[0].size() != mat[i].size())
        throw std::domain_error("Matrica nije korektna");
    if(mat.size() == 0) return mat;
    if(mat[0].size() == 0) return KreirajMatricu(3*mat.size(),0);

    Matrica m = KreirajMatricu(3*mat.size(), 3*mat[0].size());
	Matrica h = HorizontalnoOgledalo(mat);
	Matrica v = VertikalnoOgledalo(mat);
	Matrica hv = HorizontalnoVertikalnoOgledalo(mat);
    int w1(m.size()/3), w2(m[0].size()/3), q1((m.size()*2)/3), q2((m[0].size()*2)/3);
	for(int i=0 ; i<m.size() ; i++){

		for( int j=0 ; j<m[0].size() ; j++){

            if((i >= 0 && i < mat.size()) && (j>=0 && j < mat[0].size()))
                m[i][j] = hv[i][j];
            if((i >= 0 && i < mat.size()) && (j>=2*mat[0].size() && j <= 3*mat[0].size()))
                m[i][j] = hv[i][j-q2];
            if((i >=0 && i < mat.size()) && (j>=mat[0].size() && j < 2*mat[0].size()))
                m[i][j] = v[i][j-w2];

            if((i >= mat.size() && i < 2*mat.size()) && (j>=0 && j <mat[0].size()))
                m[i][j] = h[i-w1][j];
			if((i >= mat.size() && i < 2*mat.size()) && (j>=2*mat[0].size() && j <= 3*mat[0].size()))
                m[i][j] = h[i-w1][j-q2];
			if((i >= mat.size() && i < 2*mat.size()) && (j>=mat[0].size() && j < 2*mat[0].size()))
                m[i][j] = mat[i-w1][j-w2];

            if((i >= 2*mat.size() && i <= 3*mat.size()) && (j>=0 && j < mat[0].size()))
                m[i][j] = hv[i-q1][j];
			if((i >= 2*mat.size() && i <= 3*mat.size()) && (j>=2*mat[0].size() && j <= 3*mat[0].size()))
                m[i][j] = hv[i-q1][j-q2];
            if((i >= 2*mat.size() && i <= 3*mat.size()) && (j>=mat[0].size() && j < 2*mat[0].size()))
                m[i][j] = v[i-q1][j-w2];


			}

		}
		return m;

	}



int main ()
{
 std::cout<<"Unesite dimenzije matrice (m n): ";
 int n,m;
 std::cin>>m;
 std::cin>>n;
 if(m<0 || n<0){
     std::cout<<"Dimenzije matrice moraju biti nenegativne!";
     return 0;
 }
 Matrica M = KreirajMatricu(m, n);
 std::cout<<"Unesite elemente matrice:"<<std::endl;
 M = UnesiMatricu(m, n);
 try{
 Matrica Mat = OgledaloMatrica(M);
 std::cout<<"Rezultantna matrica: "<<std::endl;
 IspisiMatricu(Mat);
}
catch(std::domain_error izuzetak) {
      std::cout<<izuzetak.what()<< std::endl;
}
	return 0;
}
