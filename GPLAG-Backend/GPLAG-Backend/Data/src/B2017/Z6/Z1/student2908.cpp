#include <iostream>

template <typename Tip>
class Stek {
    int kapacitet;
    Tip ** niz;
    int broj;
public :
    Stek () : kapacitet(100000), broj(0), niz(new Tip*[kapacitet]) {}
    ~Stek () { for ( int i = 0; i < broj; i++ ) delete niz[i]; delete [] niz; }
    Stek (const Stek &stekic) {
        kapacitet = stekic.kapacitet;
        broj = stekic.broj;
        niz = new Tip*[kapacitet];
        for ( int i = 0; i < broj; i++ ) niz[i] = new Tip(*stekic.niz[i]);
    }
    Stek &operator =(const Stek &stekic) {
        if ( &stekic == this) return *this;
        for ( int i = 0; i < broj; i++ ) delete niz[i];
        delete [] niz;
        kapacitet = stekic.kapacitet;
        broj = stekic.broj;
        niz = new Tip*[kapacitet];
        for ( int i = 0; i < broj; i++ ) niz[i] = new Tip(*stekic.niz[i]);
        return *this;
    }
    void stavi(const Tip &el) {
        if ( broj == kapacitet) kapacitet *= 2;
        niz[broj] = new Tip(el);
        broj++;
    }
    void brisi () {
        for ( int i = 0; i < broj; i++ ) delete niz[i];
        broj = 0;
    }
    Tip skini() {
       if ( broj == 0) throw ("Izuzetak");
        Tip ret = *niz[broj-1];
        delete niz[broj-1];
        broj--;
        return ret;
    }
    Tip &vrh () {
        if ( broj == 0) throw ("Izuzetak");
        return *niz[broj-1];
    }
    int brojElemenata () const { return broj;  }
};


template <typename Tip>
void test_brojElemenata(Stek<Tip> stek) {
    std::cout<<stek.brojElemenata()<<std::endl;
}

template <typename Tip>
void test_vrh(Stek<Tip> &stek) {
    std::cout<<stek.vrh()<<std::endl;
    stek.vrh() = 900;
    std::cout<<stek.vrh()<<std::endl;
}
template <typename Tip>
void test_skini(Stek<Tip> &stek) {
    stek.skini();
}
template <typename Tip>
void test_brisi(Stek<Tip> &stek) {
stek.brisi();
}
template <typename Tip>
void test_stavi(Stek<Tip> &stek) {
stek.stavi(5600);
}

int main() {

Stek<int> s;
test_stavi(s);
test_stavi(s);
test_brojElemenata(s);
test_stavi(s);
test_vrh(s);
test_vrh(s);
test_skini(s);
test_brojElemenata(s);
test_brisi(s);

    return 0;
}