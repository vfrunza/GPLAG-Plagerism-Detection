#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int brred, int brkol){
    return Matrica(brred, std::vector<double>(brkol));
}

int BrojRedova(Matrica m){
    return m.size();
}

int BrojKolona(Matrica m){
    return m[0].size();
}

Matrica UnesiMatricu(int brred, int brkol){
    
auto m (KreirajMatricu(brred, brkol));
for(int i=0; i<brred; i++)
for(int j=0; j<brkol; j++){
    cin>>m.at(i).at(j);
}
return m;
}

void Ispisi(Matrica m, int a, int b, int c, int d){
    cout<<"Najveca planina unesene matrice je:"<<endl;
    for(int i=a; i<=c; i++){
    for(int j=b; j<=d; j++){
        cout<<std::setw(6)<<m.at(i).at(j);
    } cout<<endl;
}
}


Matrica NajvecaPlaninaMatrice (Matrica m){
    
     for(int i=0; i<BrojRedova(m)-1; i++){
    if(m[i].size()!=m[i+1].size()) throw std::domain_error ("Matrica nije korektna");
    }
    if(m.size()==0) throw m;
    for(int i=0; i<BrojRedova(m)-1; i++){
    if(m[i].size()!=m[i+1].size()) throw ("Matrica nije korektna");
    }
    if(BrojKolona(m)>2 && BrojRedova(m)>2){
        
    for(int i=1; i<=BrojRedova(m)-2; i++)
    for(int j=1; j<=BrojKolona(m)-2; j++){
        
        int k=m.at(i-1).at(j-1)+m.at(i+1).at(j+1)+m.at(i+1).at(j-1)+m.at(i-1).at(j+1)+m.at(i).at(j+1)+m.at(i).at(j-1)+m.at(i+1).at(j)+m.at(i-1).at(j);
   
        if(m.at(i).at(j)>k)
        
        {
        unsigned int indeks1=(i-1);
        unsigned int indeks2=(j-1);
        unsigned int indeks3=(i+1);
        unsigned int indeks4=(j+1);
        Matrica n=KreirajMatricu(3, 3);
        int k(2);
        if(i>1 && j>1){
        while((k+i)!=BrojRedova(m)-1 && (k+j)!=BrojKolona(m)-1){
            int t=m.at(i-k).at(j-k)+m.at(i+k).at(j+k)+m.at(i+k).at(j-k)+m.at(i-k).at(j+k)+m.at(i).at(j+k)+m.at(i).at(j-k)+m.at(i+k).at(j)+m.at(i-k).at(j);
            if(t<k){ m.resize(k+2); indeks1--; indeks2--; indeks3++; indeks4++;}
            else break;
            k++;
        }
        }
   Ispisi(m, indeks1, indeks2, indeks3, indeks4 );
return n;
}


}
} if(BrojKolona(m)<3 || BrojRedova(m)<3){
    double maxi=-99999;
    for(int i=0; i<BrojRedova(m); i++){
    for(int j=0; j<BrojKolona(m); j++){
    if(maxi<m.at(i).at(j)) maxi=m.at(i).at(j);
}
}
cout<<"Najveca planina unesene matrice je:"<<endl;
cout<<std::setw(6)<<maxi;
return m;
}
else {
    Matrica n (KreirajMatricu(0,0));
return n;
}
}

int main() {
    int m,n;
    cout<<"Unesite dimenzije matrice (m i n): ";
   
    cin>>m>>n;
     if(m<1 || n<1) cout<<"Dimenzije matrice moraju biti nenegativne!";
     else {
    cout<<"Unesite elemente matrice:"<<endl;
    try{
    Matrica k (UnesiMatricu(m,n));
    Matrica u=NajvecaPlaninaMatrice(k);
}
catch ( const std::domain_error e){
    std::cout << "Izuzetak: " << e.what() << std::endl;
}
}
    return 0;
}