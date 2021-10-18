#include<iostream>
#include <vector>
#include <iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int brojr, int brojk){
    return Matrica(brojr, std::vector<double> (brojk));
}
Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto m(KreirajMatricu(br_redova, br_kolona));
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
  std::cin >> m[i][j];
 }
 return m;
}

int BrojRedova(Matrica mat){
   return mat.size(); 
}
int BrojKolona(Matrica mat){
    Matrica m=KreirajMatricu(0,0); 
    if(m!=mat) return mat[0].size(); 
    else return 0;
}
bool IspravnaMatrica(Matrica m){
    
    int br=BrojRedova(m); 
   
    for(int i=0; i<br; i++){
       for(int j=0; j<br; j++){ 
            if(m[i].size()!=m[j].size()) return 0; 
       }
    }
    return 1; 
}




Matrica SaberiMatrice(Matrica m1, Matrica m2) {
    int z=IspravnaMatrica(m1); 
    if(z!=1) throw std::domain_error ("Matrica nije korektna"); 
    int g=IspravnaMatrica(m2); 
    if(g!=1) throw std::domain_error ("Matrica nije korektna"); 
 auto m3(KreirajMatricu(BrojRedova(m1), BrojKolona(m1)));
 for(int i = 0; i < BrojRedova(m1); i++)
 for(int j = 0; j < BrojKolona(m1); j++) m3[i][j] = m1[i][j] + m2[i][j];
 return m3;
}

Matrica HorizontalnOgledalo(Matrica m){
    int z=IspravnaMatrica(m); 
    if(z!=1) throw std::domain_error ("Matrica nije korektna"); 
    int brojred=BrojRedova(m); 
    int brojkol=BrojKolona(m); 
    Matrica hor=KreirajMatricu(brojred, brojkol);
    for(int i=0; i<brojred; i++){
        for(int j=0; j<brojkol; j++){
           hor[i][j]=m[i][brojkol-1-j];
        }
    }
    hor.resize(3*brojred); 
    int br=BrojRedova(hor); 
    for(int i=0; i<br; i++) hor[i].resize(3*brojkol); 
    int br1=BrojKolona(hor);
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(j<br1/3 && i>=br/3  && i<2*br/3) hor[i][j]=hor[i-br/3][j];
           else  if(j>=2*br1/3 && i>=br/3  && i<2*br/3) hor[i][j]=hor[i-br/3][j-br1+br1/3]; 
           
        }
    }
    auto h=KreirajMatricu(br, br1); 
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(i>=br/3) h[i][j]=hor[i][j]; 
        }
    }
    return h;
}
Matrica Normalna (Matrica m){
    int z=IspravnaMatrica(m); 
    if(z!=1) throw std::domain_error ("Matrica nije korektna"); 
    int brojred=BrojRedova(m); 
    int brojkol=BrojKolona(m); 
    m.resize(3*brojred); 
    int br=BrojRedova(m); 
    for(int i=0; i<br; i++)m[i].resize(3*brojkol); 
    int br1=BrojKolona(m); 
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(j>=br1/3 && j<2*br1/3  && i>=br/3 && i<2*br/3) m[i][j]=m[i-br/3][j-br1/3]; 
        }
    }
    auto h=KreirajMatricu(br, br1); 
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(i>=br/3) h[i][j]=m[i][j]; 
        }
    }
    return h; 
}
Matrica VertikalnOgledalo (Matrica m){
    int z=IspravnaMatrica(m); 
    if(z!=1) throw std::domain_error ("Matrica nije korektna"); 
    int brojred=BrojRedova(m); 
    int brojkol=BrojKolona(m); 
    Matrica ver=KreirajMatricu(brojred, brojkol); 
    for(int i=0; i<brojred; i++){
        for(int j=0; j<brojkol; j++){
            ver[i][j]=m[brojred-1-i][j]; 
        }
    }
    ver.resize(3*brojred); 
    int br=BrojRedova(ver); 
    for(int i=0; i<br; i++) ver[i].resize(3*brojkol); 
    int br1=BrojKolona(ver); 
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(j>=br1/3 && j<2*br1/3  && i<br/3) ver[i][j]=ver[i][j-br1/3];
           else  if(j>=br1/3 && j<2*br1/3 && i>=2*br/3) ver[i][j]=ver[i-br+br/3][j-br1/3]; 
           
        }
    }
    auto h=KreirajMatricu(br, br1); 
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(j>=br1/3) h[i][j]=ver[i][j]; 
        }
    }
    return h; 
}

Matrica KombinovanOgledalo (Matrica m){
    int z=IspravnaMatrica(m); 
    if(z!=1) throw std::domain_error ("Matrica nije korektna"); 
    int brojred=BrojRedova(m); 
    int brojkol=BrojKolona(m); 
    Matrica kom=KreirajMatricu(brojred, brojkol); 
    for(int i=0; i<brojred; i++){
        for(int j=0; j<brojkol; j++){
            kom[i][j]=m[brojred-1-i][brojkol-1-j]; 
        }
    }
    int br=3*brojred; 
    int br1=3*brojkol; 
    kom.resize(br); 
    for(int i=0; i<br; i++)  kom[i].resize(br1); 
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            if(j>=2*br1/3 && i<br/3) kom[i][j]=kom[i][j-br1+br1/3];
            else if(j>=2*br1/3 && i>=2*br/3) kom[i][j]=kom[i-br+br/3][j-br1+br1/3]; 
            else if(j<br1/3 && i>=2*br/3) kom[i][j]=kom[i-br+br/3][j];
        }
    }
    return kom; 
}

Matrica OgledaloMatrica(Matrica m){
    int z=IspravnaMatrica(m); 
    if(z!=1) throw std::domain_error ("Matrica nije korektna"); 
    int brojkol=3*BrojKolona(m); 
    int brojred=3*BrojRedova(m);
   
    auto ogl=KreirajMatricu(brojred, brojkol);
    auto ver=VertikalnOgledalo(m); 
    auto hor=HorizontalnOgledalo(m); 
    auto kom=KombinovanOgledalo(m); 
    auto nor=Normalna(m); 
    ogl=SaberiMatrice(ogl, kom);
    ogl=SaberiMatrice(ogl, ver);
    ogl=SaberiMatrice(ogl, hor);
    ogl=SaberiMatrice(ogl, nor); 
    return ogl;
}



int main ()
{
   std::cout<<"Unesite dimenzije matrice (m n): "; 
   int m, n; 
   std::cin>>m>>n; 
   if(m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne! "; return 0; }
   std::cout<<"Unesite elemente matrice: "; 
      try{
    auto p= UnesiMatricu(m,n); 
    auto k=OgledaloMatrica(p); 
    int br=BrojRedova(k); 
    int br1=BrojKolona(k); 
    std::cout<<"\nRezultantna matrica: \n";
    for(int i=0; i<br; i++){
        for(int j=0; j<br1; j++){
            std::cout<<std::setw(4)<<k[i][j]; 
        }
        std::cout<<"\n"; 
    }
   }
   	catch(std::domain_error izuzetak) {
		 std::cout << izuzetak.what() << std::endl;
	}
       	return 0;
}