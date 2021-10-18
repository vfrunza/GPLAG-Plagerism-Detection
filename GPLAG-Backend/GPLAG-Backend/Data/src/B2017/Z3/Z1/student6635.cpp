/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>


class Liga{
    int broj_timova;
    const maxbrtimova;
    Tim *timovi;
    
    public:
    
    explicit Liga(int velicina_lige);
    explicit Liga(std::initializer_list<Tim> lista_timova);
    double *begin(){return timovi;}
    double *end(){return timovi+broj_timova;}
    
    ~Liga(){delete[] timovi;}
    
    Liga(const Liga &l);
    Liga(Liga &&l);
    Liga &operator =(const Liga &l);
    Liga &operator =(Liga &&l);
    void DodajNoviTim(const char ime_tima[]);
    void RegistrirajUtakmicu(const char tim1[], const char tim2[],
    int rezultat_1, int rezultat_2);
    void IspisiTabelu();
};

Liga::Liga(int velicina_lige) : velicina_lige(broj_timova),
    timovi(new string[broj_timova]){
        std::fill(timovi,timovi+broj_timova," ");
    }
    
Liga::Liga(std::initializer_list<Tim> lista_timova):
        velicina_lige(lista.size(),timovi(new string[lista.size()]) {
            std::copy(lista.begin(),lista.end(),timovi);
        }
Liga::Liga(const Liga &l) : timovi(l.broj_timova),
    timovi(new Tim[l.broj_timova]){
        std::copy(l.timovi,l.timovi+l.broj_timova,timovi);
    }
Liga::Liga(Liga &&l) : timovi(broj_timova),
    timovi(l.timovi) {l.timovi=nullptr;}
    
Liga &Liga::operator =(const Liga &l){
    Tim *novi_timovi(new Tim[l.broj_timova]);
    std::copy(l.timovi,l.timovi+l.broj_timova,novi_timovi);
    delete[] timovi;
    broj_timova=l.broj_timova; timovi=novi_timovi;
    return *this;
}    
Liga &Liga::operator=(Liga &&l){
    std::swap(broj_timova,l.broj_timova); std::swap(timovi,l.timovi);
    return *this;
}    

Liga::DodajNoviTim(const char ime_tima[]){
    if(broj_timova+1>maxbrtimova) throw std::range_error ("Liga popunjena");
    timovi[broj_timova+1]=ime_tima;
    broj_timova++;
}

Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],
    int rezultat_1, int rezultat_2){
        
    }






int main ()
{
    
    
    
	return 0;
}
