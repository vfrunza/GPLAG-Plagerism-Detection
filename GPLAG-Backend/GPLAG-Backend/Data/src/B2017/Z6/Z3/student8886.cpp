#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
template <typename TipEl>
class Matrica {
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
    void TestIndeksa(int index1, int index2) const {
        if(index1<1 || index2<1 || index1>br_redova || index2>br_kolona)
            throw std::range_error("Neispravan indeks");
    }
    int ReadNumbers( const std::string & s, std::vector <double> & v ) {
    std::istringstream is( s );
    double n;
    while( is >> n ) {
        v.push_back( n );
    }
    return v.size();
}
    void import_matrix_from_txt_file(const std::string& filename_X, std::vector <double>& v, int& rows, int& cols){
    
    std::ifstream file_X;
    std::string line;
    
    file_X.open(filename_X);
    if (file_X.is_open())
    {
        int i=0;
        getline(file_X, line);
        
        
        cols =ReadNumbers( line, v );
        std::cout << "cols:" << cols << std::endl;
        
        
        for ( i=1;i<32767;i++){
            if ( getline(file_X, line) == 0 ) break;
            ReadNumbers( line, v );
            
        }
        
        rows=i;
        std::cout << "rows :" << rows << std::endl;
        if(rows >32766) std::cout<< "N must be smaller than MAX_INT";
        
        file_X.close();
    }
    else{
        std::cout << "file open failed";
    }
    
    std::cout << "v:" << std::endl;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            std::cout << v[i*cols+j] << "\t" ;
        }
        std::cout << std::endl;
    }
}
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(std::string s, bool dane){
        if(dane==false){
            ObnoviIzTekstualneDatoteke(s);
        }
        else if(dane==true){
            ObnoviIzBinarneDatoteke(s);
        }
    }
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica() {
        DealocirajMemoriju(elementi, br_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    void Unesi();
    void Ispisi(int sirina_ispisa) const;

    friend Matrica operator +(const Matrica &m1, const Matrica &m2) {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;
    }

    friend std::ostream &operator << (std::ostream &tok, const Matrica &m) {
        int kojaje(tok.width());
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++)

                std::cout<<std::setw(kojaje)<<m.elementi[i][j];
            std::cout<<std::endl;
        }
        return tok;
    }
    friend std::istream &operator >>(std::istream &tok, const Matrica &m) {
        int duzina(tok.width());
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++) {
                std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                tok>>m.elementi[i][j];
            }
        return tok;
    }
    TipEl* operator [](int indeks) const {
        return elementi[indeks];
    }
    TipEl* &operator [](int indeks) {
        return elementi[indeks];
    }
    friend Matrica operator *(const Matrica &m1, const Matrica &m2) {
        if(m1.br_redova!=m2.br_kolona)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
        for(int i=0; i<m1.br_redova; i++) {
            int k=0;
            for(int j=0; j<m3.br_kolona; j++) {
                double suma(0);
                for(int l(0); l<m2.br_redova;) {
                    suma+=m1.elementi[i][l]*m2.elementi[l][j];
                    l++;
                }
                k++;
                m3.elementi[i][j]=suma;
            }
        }
        return m3;
    }
    TipEl &operator ()(int a, int b) {
        TestIndeksa(a,b);
        return elementi[a-1][b-1];
    }
    TipEl operator ()(int a, int b) const {
        TestIndeksa(a,b);
        return elementi[a-1][b-1];
    }
    friend Matrica operator -(const Matrica &m1, const Matrica &m2) {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
        return m3;
    }
    friend Matrica operator *(double x, const Matrica &m2) {
        Matrica<TipEl> m3(m2.br_redova, m2.br_kolona);
        for(int i=0; i<m2.br_redova; i++)
            for(int j=0; j<m2.br_kolona; j++)
                m3.elementi[i][j]=x*m2.elementi[i][j];
        return m3;
    }

    friend Matrica operator *(const Matrica &m2, double x) {
        Matrica<TipEl> m3(m2.br_redova, m2.br_kolona);
        for(int i=0; i<m2.br_redova; i++)
            for(int j=0; j<m2.br_kolona; j++)
                m3.elementi[i][j]=x*m2.elementi[i][j];
        return m3;
    }

    Matrica operator *=(const Matrica &m2) {
        if(m2.br_redova!=m2.br_kolona)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica<TipEl> m3(br_redova, m2.br_kolona);
        for(int i=0; i<br_redova; i++) {
            int k(0);
            for(int j=0; j<m2.br_kolona; j++) {
                double suma(0);
                for(int l=0; l<m2.br_redova;) {
                    suma+=elementi[i][l]*m2.elementi[l][j];
                    l++;
                }
                k++;
                m3.elementi[i][j]=suma;
            }
        }
        *this=m3;
        return *this;
    }

    Matrica operator +=(const Matrica &m2) {
        if(br_redova!=m2.br_redova || br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                elementi[i][j]=elementi[i][j]+m2.elementi[i][j];
        return *this;
    }

    Matrica operator -=(const Matrica &m2) {
        if(br_redova!=m2.br_redova || br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        for(int i=0; i<m2.br_redova; i++)
            for(int j=0; j<m2.br_kolona; j++)
                elementi[i][j]=elementi[i][j]-m2.elementi[i][j];
        return *this;
    }


    Matrica operator *=(double x) {
        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                elementi[i][j]=x*elementi[i][j];
        return *this;
    }

    operator std::string() const {
        std::string s;
        s.push_back('{');
        for(int i=0; i<br_redova; i++) {
            s.push_back('{');
            for(int j=0; j<br_kolona; j++) {
                if(j==br_kolona-1) {
                    s+=std::to_string(int(elementi[i][j]));
                    s.push_back('}');
                    break;
                }
                s+=std::to_string(int(elementi[i][j]));
                s.push_back(',');
            }
            if(i==br_redova-1) {
                s.push_back('}');
                break;
            }
            s.push_back(',');
        }
        return s;
    }
    void SacuvajUTekstualnuDatoteku(std::string s);
    void SacuvajUBinarnuDatoteku(std::string s);
    void ObnoviIzTekstualneDatoteke(std::string s){
        std::ifstream ulazni_tok(s);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        std::vector<double> v;
        int rows(0), cols(0);
        import_matrix_from_txt_file(s, v, rows, cols);
        /*
        while(1){
            while(ulazni_tok>>broj) std::cout<<broj;
            std::cout<<std::endl;
            br_redova++;
        }
        //std::cout<<br_kolona<<" "<<br_redova;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                ulazni_tok>>elementi[i][j];*/
    }
    void ObnoviIzBinarneDatoteke(std::string s){
        std::ifstream ulazni_tok(s);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        
        ulazni_tok.close();
    }
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
    TipEl **elementi(new TipEl*[br_redova] {});
    try {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
    }
    catch(...) {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
    KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
    m.br_redova = 0;
    m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
    if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
        TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if(br_redova > m.br_redova)
        for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
    br_redova = m.br_redova;
    br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
    std::swap(br_redova, m.br_redova);
    std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}

int main() {
    try
    {
        Matrica<int> m1(0,0);
        m1.SacuvajUTekstualnuDatoteku("datoteka.txt");
        //Matrica<int> m1("datoteka.txt", false);
        //std::cout << std::setw(5) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    
/*
    int m,n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try {
        Matrica<double> a(m, n, 'A'), b(m, n, 'B');
        std::cout << "Unesi matricu A:\n";
        std::cin >> a;
        std::cout << "Unesi matricu B:\n";
        std::cin >> b;
        const Matrica<double>c(a);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                std::cout << c(i+1,j+1) << " ";
            std::cout << std::endl;
        }
        std::cout << "---------------" << std::endl;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                std::cout << c[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::setw(5) << a << std::setw(5) << b;
        //a.SacuvajUTekstualnuDatoteku("TEST.TXT");
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error e) {
        std::cout << e.what();
    }
    catch(std::range_error e) {
        std::cout << e.what();
    }
*/
    return 0;
}
