//ZADATAK 4
#include <iomanip>
#include<iostream>
#include <stdexcept>
using namespace std;
class Sat {
    int S;
    static const int D = 86400; // broj sekundi u jednom danu
    void IspisiHMS() const {
        cout.fill('0'); cout.width(2); cout << S / 3600 << ":";
        cout.fill('0'); cout.width(2); cout << (S % 3600) / 60 << ":";
        cout.fill('0'); cout.width(2); cout << (S % 3600) % 60 << endl;
    }
    void SecsToHMS(int Secs, int &h, int &m, int &s) const {
        h = Secs / 3600;
        m = (Secs % 3600) / 60;
        s = Secs % 60;
    }
    public: // prepisati interfejs
    void Postavi(int sati, int minute, int sekunde);
    void Sljedeci() { PomjeriZa(1); }
    void Prethodni() { PomjeriZa(-1); }
    void PomjeriZa(int pomak); // prototip
    int DajSate() const { return S / 3600; }
    int DajMinute() const { return (S % 3600) / 60; }
    int DajSekunde() const { return S % 60; }
    void Ispisi() const { IspisiHMS(); }
    friend int BrojSekundiIzmedju(const Sat &v1, const Sat &v2);
};
void Sat::Postavi(int sati, int minute, int sekunde) {
    S = 0;
    if(sati < 0 || sati > 23) throw std::domain_error("Sati moraju biti unutar opsega 0h < sati < 23h !");
    else S += sati * 3600;
    if(minute < 0 || minute > 59) throw std::domain_error("Minute moraju biti unutar opsega 0m < minute < 59m !");
    else S += minute * 60;
    if(sekunde < 0 || sekunde > 59) throw std::domain_error("Sekunde moraju biti unutar opsega 0s < sekunde < 59s !");
    else S += sekunde;
}
void Sat::PomjeriZa (int pomak) {
    S += pomak;
    if(S >= D) S = S % D; // ako smo 'prekoracili' dan
    if (S < 0) S = D + S % D; // u slucaju da imamo negativan pomak (vrijeme)
}
int BrojSekundiIzmedju(const Sat &v1, const Sat &v2) {
    return v1.S - v2.S;
}
int main()
{   
    Sat v;
    try {
        v.Postavi(10, 10, 10);
        cout << "Sati: " << v.DajSate();
        cout << endl << "Minute: " << v.DajMinute();
        cout << endl << "Sekunde: " << v.DajSekunde();
    }
    catch(...) {
        cout << "Uneseni su pogresni parametri !" << endl;
    }
    cout << endl << "Uvecano za jednu sekundu: " << endl;
    v.Sljedeci(); v.Ispisi();
    cout << "Umanjeno za jednu sekundu: " << endl;
    v.Prethodni(); v.Ispisi();
    cout << "Pomjereno za 7 sekundi: " << endl;
    v.PomjeriZa(7); v.Ispisi();
    cout << "Broj sekundi izmedju vremena v1 i v2 je: ";
    Sat v1, v2;
    v1.Postavi(10, 10, 15);
    v2.Postavi(10, 10, 10);
    cout << BrojSekundiIzmedju(v1, v2) << "s" << endl;
return 0;
}