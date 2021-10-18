/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>

template <typename TipEl>
class Matrica {
    int br_redova,br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova,int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
    public:
    Matrica(int br_redova, int br_kolona, char ime=0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    Matrica(const char ime_datoteke[], bool binarna=true);
    ~Matrica() {
        DealocirajMemoriju(elementi,br_redova);
    }
    Matrica &operator=(const Matrica &m);
    Matrica &operator=(Matrica &&m);
    void SacuvajUTekstualnuDatoteku(const char ime_datoteke[]) const;
    void ObnoviIzTekstualneDatoteke(const char ime_datoteke[]);
    void SacuvajUBinarnuDatoteku(const char ime_datoteke[]) const;
    void ObnoviIzBinarneDatoteke(const char ime_datoteke[]);
    template <typename Tip>
    friend std::ostream &operator<<(std::ostream &p,const Matrica<Tip>&matrica);
    template <typename Tip>
    friend std::istream &operator>>(std::istream &p,Matrica<Tip>&matrica);
    template <typename Tip>
    friend Matrica<Tip>operator -(const Matrica<Tip>&mat1,const Matrica<Tip>&mat2);
    template <typename Tip>
    friend Matrica<Tip>operator +(const Matrica<Tip>&mat1,const Matrica<Tip>&mat2);
    template <typename Tip>
    friend Matrica<Tip> operator -=(Matrica<Tip>&mat1,const Matrica<Tip>&mat2);
    template<typename Tip>
    friend Matrica<Tip> operator +=(Matrica<Tip>&mat1, const Matrica<Tip>&mat2);
    template <typename Tip>
    friend Matrica<Tip>operator *(const Matrica<Tip>&mat1,const Matrica<Tip>&mat2);
    template <typename Tip, typename Tip1>
    friend Matrica<Tip>operator *(const Matrica<Tip>&mat1, Tip1 n);
    template<typename Tip1,typename Tip>
    friend Matrica<Tip>operator *(Tip1 n, const Matrica<Tip>&mat2);
    template <typename Tip,typename Tip1>
    friend Matrica<Tip>operator *=(Matrica<Tip>&mat1, Tip1 n);
    template <typename Tip>
    friend Matrica<Tip>operator *=(Matrica<Tip>&mat1, const Matrica<Tip>&mat2);
    const TipEl* operator[](int index) const {
        return elementi[index];
    }
    const TipEl operator ()(int i, int j) const {
        if(i<1 || i>br_kolona) throw std::range_error("Neispravan indeks");
        if(j<1 || j>br_redova) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    auto operator [](int indeks)->decltype(*elementi) {
        return elementi[indeks];
    }
    auto operator ()(int i, int j)->decltype(**elementi) {
        if(i<1 || i>br_kolona) throw std::range_error("Neispravan indeks");
        if(j<1 || j>br_redova) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    operator std::string() const {
        std::string stringic;
        stringic.push_back('{');
        for(int i=0; i<br_redova; i++) {
            stringic.push_back('{');
            for(int j=0; j<br_kolona; j++) {
                int hehe(elementi[i][j]);
                std::string pomocnistringic;
                do {
                    pomocnistringic.push_back((hehe%10)+'0');
                    hehe/=10;
                }while(hehe!=0);
                for(int n(pomocnistringic.size()-1); n>=0; n--) {
                    stringic.push_back(pomocnistringic[n]);
                }
                if(j!=br_kolona-1) stringic.push_back(',');
                }
                stringic.push_back('}');
                if(i!=br_redova-1) stringic.push_back(',');
            }
            stringic.push_back('}');
            return stringic;
        }
        
    };
    template <typename TipEl>
    TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
        TipEl **elementi(new TipEl*[br_redova] {});
        try {
            for(int i=0; i<br_redova; i++) elementi[i]=new TipEl[br_kolona];
        }
        catch(...) {
            DealocirajMemoriju(elementi, br_redova);
            throw;
        }
        return elementi;
    }
    template<typename TipEl>
    void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
        if(elementi!=0) {
            for(int i=0; i<br_redova; i++) delete[] elementi[i];
            delete[] elementi;
        }
    }
    template <typename TipEl>
    Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime): br_redova(br_redova),br_kolona(br_kolona),ime_matrice(ime),elementi(AlocirajMemoriju(br_redova,br_kolona)) {}
    template <typename TipEl>
    void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
        for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
        Matrica::elementi[i][j]=elementi[i][j];
    }
    template<typename TipEl>
    Matrica<TipEl>::Matrica(const char ime_datoteke[], bool binarna) {
        if(!binarna) {
            ObnoviIzTekstualneDatoteke(ime_datoteke);
        }
        else {
            std::ifstream ulaz(ime_datoteke,std::ios::binary);
            if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
            int m(0),n(0);
            if(!ulaz.read(reinterpret_cast<char*>(&m),sizeof m))
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if(!ulaz.read(reinterpret_cast<char*>(&n),sizeof n))
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
            elementi=AlocirajMemoriju(m,n);
            br_kolona=n;
            br_redova=m;
            for(int i=0; i<br_redova; i++) {
                for(int j=0; j<br_kolona; j++) {
                    TipEl temp;
                    if(!ulaz.read(reinterpret_cast<char*>(&temp),sizeof temp)) {
                        DealocirajMemoriju(elementi,n);
                        throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    }
                    elementi[i][j]=temp;
                }
            }
            ulaz.close();
        }
    }
    template <typename TipEl>
    Matrica<TipEl>::Matrica(const Matrica<TipEl>&m):br_redova(m.br_redova),br_kolona(m.br_kolona),ime_matrice(m.ime_matrice),elementi(AlocirajMemoriju(m.br_redova,m.br_kolona)) {
        KopirajElemente(m.elementi);
    }
    template<typename TipEl>
    Matrica<TipEl>::Matrica(Matrica<TipEl>&&m):br_redova(m.br_redova),br_kolona(m.br_kolona),elementi(m.elementi),ime_matrice(m.ime_matrice) {
        m.br_redova=0;
        m.elementi=nullptr;
    }
    template<typename TipEl>
    Matrica<TipEl>&Matrica<TipEl>::operator =(const Matrica<TipEl>&m) {
        if(br_redova<m.br_redova || br_kolona<m.br_kolona) {
            TipEl **novi_prostor(AlocirajMemoriju(m.br_redova,m.br_kolona));
            DealocirajMemoriju(elementi,br_redova);
            elementi=novi_prostor;
        }
        else if(br_redova>m.br_redova)
        for(int i=m.br_redova; i<br_redova; i++) delete elementi[i];
        br_redova=m.br_redova;
        br_kolona=m.br_kolona;
        ime_matrice=m.ime_matrice;
        KopirajElemente(m.elementi);
        return *this;
    }
    template <typename TipEl>
    Matrica<TipEl>&Matrica<TipEl>::operator=(Matrica<TipEl>&&m) {
        std::swap(br_redova,m.br_redova);
        std::swap(br_kolona,m.br_kolona);
        std::swap(ime_matrice,m.ime_matrice);
        std::swap(elementi,m.elementi);
        return *this;
    }
    template<typename TipEl>
    void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char ime_datoteke[]) const {
        std::ofstream izlaz(ime_datoteke);
        for(int i=0; i<br_redova; i++) {
            for(int j=0; j<br_kolona; j++) {
                izlaz<<elementi[i][j];
                if(j<br_kolona-1)
                izlaz<<",";
            }
            izlaz<<std::endl;
        }
        izlaz.close();
    }
    template<typename TipEl>
    void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char ime_datoteke[]) const {
        std::ofstream izlaz(ime_datoteke,std::ios::binary);
        int m(br_redova),n(br_kolona);
        izlaz.write(reinterpret_cast<char*>(&m),sizeof m);
        izlaz.write(reinterpret_cast<char*>(&n),sizeof n);
        for(int i=0; i<br_redova; i++) {
            for(int j=0; j<br_kolona;j++) {
                TipEl temp(elementi[i][j]);
                izlaz.write(reinterpret_cast<char*>(&temp),sizeof temp);
            }
        }
        izlaz.flush();
        izlaz.close();
    }
    template <typename TipEl>
    void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char ime_datoteke[]) {
        std::ifstream ulaz(ime_datoteke,std::ios::binary);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        int m(0), n(0);
        if(!ulaz.read(reinterpret_cast<char*>(&m),sizeof m))
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if(!ulaz.read(reinterpret_cast<char*>(&n),sizeof n))
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
        DealocirajMemoriju(elementi,br_redova);
        AlocirajMemoriju(m,n);
        for(int i=0; i<br_redova; i++) {
            for(int j=0; j<br_kolona; j++) {
                TipEl temp=TipEl();
                if(!ulaz.read(reinterpret_cast<char*>(&temp),sizeof temp))
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
                elementi[i][j]=temp;
            }
        }
        ulaz.close();
    }
    template<typename TipEl>
    void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char ime_datoteke[])  {
        std::ifstream ulaz(ime_datoteke);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        elementi=AlocirajMemoriju(10,10);
        int i(0),j(0);
        TipEl temp;
        char t(0);
        ulaz>>std::ws;
        while(ulaz>>temp) {
            if(ulaz.peek()!='\n' && !ulaz.eof()) {
                ulaz>>t;
                if(t!=',') {
                    DealocirajMemoriju(elementi,10);
                    ulaz.clear();
                    ulaz.close();
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
                elementi[i][j]=temp;
                j++;
            }
            else {
                elementi[i][j]=temp;
                if(i==0) {
                    br_kolona=j+1;
                }
                else {
                    if(j!=br_kolona-1) {
                        DealocirajMemoriju(elementi,10);
                        ulaz.clear();
                        ulaz.close();
                        throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    }
                }
                i++;
                j=0;
            }
        }
        br_redova=i;
        for(int i=br_redova; i<10; i++)
        delete[] elementi[i];
        if(ulaz.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        ulaz.close();
    }
    template <typename TipEl>
    std::ostream &operator <<(std::ostream &p,const Matrica<TipEl> &matrica) {
        int sirina_ispisa(p.width());
        if(sirina_ispisa<6) sirina_ispisa=6;
        for(int i=0; i<matrica.br_redova; i++) {
            for(int j=0; j<matrica.br_kolona; j++) {
                p<<std::setw(sirina_ispisa)<<matrica.elementi[i][j];
            }
            p<<std::endl;
        }
        return p;
    }
    template <typename TipEl>
    std::istream &operator >>(std::istream &p,Matrica<TipEl>&matrica) {
        for(int i=0; i<matrica.br_redova; i++) 
            for(int j=0; j<matrica.br_kolona; j++) {
                std::cout<<matrica.ime_matrice<<"("<<i+1<<","<<j+1<<")=";
                p>>matrica.elementi[i][j];
            }
            return p;
    }
    template<typename TipEl>
    Matrica<TipEl> operator -(const Matrica<TipEl>&mat1,const Matrica<TipEl>&mat2) {
        if((mat1.br_kolona!=mat2.br_kolona) ||(mat1.br_redova!=mat2.br_redova))
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> mat3(mat1.br_redova,mat1.br_kolona);
        for(int i=0; i<mat1.br_kolona;i++) {
            for(int j=0; j<mat1.br_kolona; j++) {
                mat3.elementi[i][j]=mat1.elementi[i][j]-mat2.elementi[i][j];
            }
        }
        return mat3;
    }
    template<typename TipEl>
    Matrica<TipEl>operator +(const Matrica<TipEl>&mat1,const Matrica<TipEl>&mat2) {
        if((mat1.br_redova!=mat2.br_redova)) throw std::domain_error("Matrice nemaju jednake dimenzije");
        Matrica<TipEl>mat3(mat1.br_redova,mat1.br_kolona);
        for(int i=0; i<mat1.br_redova; i++) {
            for(int j=0; j<mat1.br_kolona; j++) {
                mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
            }
        }
        return mat3;
    }
    template<typename Tip>
    Matrica<Tip>operator-=(Matrica<Tip>&mat1,const Matrica<Tip>&mat2) {
        return mat1=mat1-mat2;
    }
    template<typename Tip>
    Matrica<Tip>operator +=(Matrica<Tip>&mat1, const Matrica<Tip>&mat2) {
        return mat1=mat2+mat1;
    }
    template <typename Tip>
    Matrica<Tip>operator *(const Matrica<Tip>&mat1,const Matrica<Tip>&mat2) {
        if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica<Tip>mat3(mat1.br_redova, mat2.br_kolona);
        for(int i=0; i<mat1.br_redova; i++) 
        for(int j=0;j<mat2.br_kolona; j++)
        mat3.elementi[i][j]={};
        for(int i=0;i<mat1.br_redova; i++) {
            for(int k=0; k<mat2.br_kolona; k++) {
                for(int j=0; j<mat1.br_kolona; j++) {
                    mat3.elementi[i][k]+=(mat1.elementi[i][j]*mat2.elementi[j][k]);
                }
            }
        }
    return mat3;
    }
    template<typename Tip,typename Tip1>
    Matrica<Tip>operator *(const Matrica<Tip>&mat1,Tip1 n){
        Matrica<Tip>mat3(mat1);
        for(int i=0; i<mat3.br_redova; i++) {
            for(int j=0; j<mat3.br_kolona; j++) {
                mat3.elementi[i][j]*=n;
            }
        }
        return mat3;
    }
    template<typename Tip11,typename Tip>
    Matrica<Tip>operator *(Tip11 n, const Matrica<Tip>&mat1) {
        Matrica<Tip>mat3(mat1);
        for(int i=0; i<mat3.br_redova; i++) {
            for(int j=0; i<mat3.br_kolona; j++) {
                mat3.elementi[i][j]*=n;
            }
        }
        return mat3;
    }
    template <typename Tip, typename Tip1>
    Matrica<Tip>operator *=(Matrica<Tip>&mat1, Tip1 n) {
        for(int i=0; i<mat1.br_redova; i++) {
            for(int j=0; j<mat1.br_kolona; j++) {
                mat1.elementi[i][j]*=n;
            }
        }
        return mat1;
    }
    template<typename Tip>
    Matrica<Tip>operator *=(Matrica<Tip>&mat1, const Matrica<Tip>&mat2) {
        return mat1=mat1*mat2;
    }
int main ()
{
    int m,n;
    std::cout<<"Unesi broj redova i kolona za matrice:\n";
    std::cin>>m>>n;
    try {
        Matrica<double>a(m,n,'A'),b(m,n,'B');
        std::cout<<"Unesi matricu A:\n";
        std::cin>>a;
        std::cout<<"Unesi matricu B:\n";
        std::cin>>b;
        std::cout<<"Zbir ove dvije matrice je:\n";
        std::cout<<std::setw(7)<<a+b;
        (a+b).SacuvajUTekstualnuDatoteku("rezulati.txt");
        Matrica<double>ab(2,2,'A');
        ab.ObnoviIzTekstualneDatoteke("rezultati.txt");
        std::cout<<ab;
        ab=ab*2;
        ab.SacuvajUBinarnuDatoteku("rezultati.dat");
        ab.ObnoviIzBinarneDatoteke("rezultati.dat");
        std::cout<<ab;
        Matrica<double>ba("rezultat.txt",true);
        std::cout<<ba;
        Matrica<double>c("rezultati.dat",false);
        std::cout<<c;
    }
    catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
	return 0;
}
