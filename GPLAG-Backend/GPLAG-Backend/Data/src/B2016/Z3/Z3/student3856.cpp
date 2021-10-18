/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename Tip>
struct Matrica {
  int broj_redova, broj_kolona;
  Tip **elementi = nullptr;
};

template <typename Tip>
void UnistiMatricu(Matrica<Tip> mat){
    if(!mat.elementi) return;
    for(int i = 0;i < mat.broj_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu(int br_red, int br_kol){
    Matrica<Tip> mat;
    mat.broj_redova = br_red;
    mat.broj_kolona = br_kol;
    mat.elementi = new Tip*[br_red];
    for (int i = 0; i < br_red; i++) mat.elementi[i] = nullptr;
    try {
        
        for(int i = 0; i < br_red; i++) mat.elementi[i] = new Tip[br_kol];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename Tip>
void UnesiMatricu(char ime_matrice, Matrica<Tip> &mat){
    for (int i = 0; i < mat.broj_redova; i++)
        for (int j = 0; j < mat.broj_kolona; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    
    for ( int i = 0; i < mat.broj_redova; i++) {
        for ( int j = 0; j < mat.broj_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout<< std::endl;
    }
    if (treba_brisati == true){
        UnistiMatricu(mat);
    }
}

template <typename Tip>
Matrica<Tip> ZbirMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2){
    if ( m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip>(m1.broj_redova, m1.broj_kolona));
    for(int i = 0; i < m1.broj_redova; i++) {
        for ( int j = 0; j < m1.broj_kolona; j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            
        }
    }
    return m3;
}

template <typename Tip> 
Matrica<Tip> ProduktMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2){
    if( m1.broj_kolona != m2.broj_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    
    Matrica<Tip> mat = StvoriMatricu<Tip>( m1.broj_redova, m2.broj_kolona);
    
    for(int i = 0; i < m1.broj_redova; i++)
        for( int j = 0; j < m2.broj_kolona; j++){
            for( int k =0; k < m1.broj_kolona ; k++) {// mogli smo staviti i m2.broj_redova jer su isti
                mat.elementi[i][j]+= m1.elementi[i][k] * m2.elementi[k][j];
            }
        }

    return mat;
}
template <typename Tip>
void PopuniJedinicnuMatricu(Matrica<Tip> &mat){
    for(int i = 0; i < mat.broj_redova; i++){
        for( int j = 0; j < mat.broj_kolona; j++){
            if(i==j) mat.elementi[i][j] = 1;
            else mat.elementi[i][j] = 0;
        }
    }
}
template <typename Tip>
Matrica<Tip> MatricniPolinom(const Matrica<Tip> mat, std::vector<double> v){
    
    Matrica<Tip> pomocna = StvoriMatricu<Tip>(mat.broj_redova, mat.broj_kolona);
    PopuniJedinicnuMatricu(pomocna);
    Matrica<Tip> zbir = StvoriMatricu<Tip>(mat.broj_redova, mat.broj_kolona);
    //da se osiguramo da su nam u matrici koja ce racunati zbir sve 0
    for( int i = 0; i< mat.broj_redova; i++){
        for (int j = 0; j < mat.broj_kolona; j++){
            zbir.elementi[i][j]=0;
        }
    }
    
    for(int i = 0; i< v.size(); i++){
        
        if( i != 0 ){
            
            Matrica<Tip> k = ProduktMatrica(pomocna, mat);
            UnistiMatricu(pomocna);
            pomocna = k;
            
        }
        Matrica<Tip> h = StvoriMatricu<Tip>(pomocna.broj_redova, pomocna.broj_kolona);
        for (int j = 0; j < pomocna.broj_redova; j++){
            for (int k = 0; k < pomocna.broj_kolona; k++){
                h.elementi[j][k]=v[i]*pomocna.elementi[j][k];
            }
        }
        
        
        Matrica<Tip> s = ZbirMatrica(h,zbir);
        UnistiMatricu(zbir);
        zbir = s; 
        UnistiMatricu(h);
        
    }
    UnistiMatricu(pomocna);
    return zbir;
    
}

int main ()
{
    
    int d,n;
    std::vector<double> v;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>d;
    Matrica<double> a;
    Matrica<double> b;
    try{
        a = StvoriMatricu<double>(d,d);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i =0; i <= n; i++){
            double k;
            std::cin>>k;
            v.push_back(k);
        }
        b = MatricniPolinom(a,v);
        IspisiMatricu(b,10);
        
    }
    catch (std::exception &e){
        std::cout<<e.what();
    }
	return 0;
}