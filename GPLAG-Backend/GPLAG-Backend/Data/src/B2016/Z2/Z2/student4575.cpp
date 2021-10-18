// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
typedef std::deque<std::deque<int>> dekovi;
typedef std::vector<dekovi> Vec;


enum class SmjerKretanja
{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};

template <typename Tip,typename SmjerKretanja>
auto IzdvojiDijagonale3D(Tip kont,SmjerKretanja x)-> typename std::remove_reference<decltype(kont[0])>::type{
    typename std::remove_reference<decltype(kont[0])>::type nista{};
    typename std::remove_reference<decltype(kont[0])>::type Vrni;
    if(x==SmjerKretanja::NaprijedNazad){
      //  typename std::remove_reference<decltype(kont[0])>::type Vrni;
        int n=kont.size();
        Vrni.resize(n);
        int m=kont[0].size();
        int r=kont[0][0].size();
        int broj_elemenata_na_dijagonali;
        if(n==m) broj_elemenata_na_dijagonali=r;
        else broj_elemenata_na_dijagonali=m;
     for(int i=0; i<n; i++) {
        Vrni.at(i).resize(broj_elemenata_na_dijagonali);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<broj_elemenata_na_dijagonali; j++) {
            int s=j;
            Vrni.at(i).at(j)=kont.at(i).at(j).at(s);
        }
    }
        return Vrni;
    }
    if(x==SmjerKretanja::NazadNaprijed){
        //typename std::remove_reference<decltype(kont[0])>::type Vrni;
        int n=kont.size();
        Vrni.resize(n);
        int m=kont[0].size();
        int r=kont[0][0].size();
        int broj_elemenata_na_dijagonali;
        if(n==m) broj_elemenata_na_dijagonali=r;
        else broj_elemenata_na_dijagonali=m;
    for(int i=0; i<n; i++) {
        Vrni.at(i).resize(broj_elemenata_na_dijagonali);
    }
        int h=0;
    for(int i=n-1; i>=0; i--) {
         int l=kont[0][0].size()-1;
        for(int j=0; j<broj_elemenata_na_dijagonali; j++) {
            Vrni.at(h).at(j)=kont.at(i).at(j).at(l);
            l--;
        }
        h++;
    }

        return Vrni;
    }
    if(x==SmjerKretanja::GoreDolje){
       // typename std::remove_reference<decltype(kont[0])>::type Vrni;
         int n=kont[0].size();
         Vrni.resize(n);
         int m=kont.size();
    for(int i=0;i<n;i++){
         Vrni.at(i).resize(m);
    }
        int k=kont.size()-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Vrni.at(j).at(i)=kont.at(k).at(j).at(i);
        }
        k--;
    }
        return Vrni;
    }
    if(x==SmjerKretanja::DoljeGore){
        //typename std::remove_reference<decltype(kont[0])>::type Vrni;
        int n=kont[0].size();
        Vrni.resize(n);
        int m=kont.size();
    for(int i=0;i<n;i++){
         Vrni.at(i).resize(m);
    }
       int k=kont.size()-1;
       int s=kont[0][0].size()-1;
    
    for(int i=0;i<m;i++){
        int z=kont[0].size()-1;
        for(int j=0;j<n;j++){
            Vrni.at(j).at(i)=kont.at(k).at(z).at(s);
            z--;
        }
        s--;
        k--;
    }
        return Vrni;
    }
    if(x==SmjerKretanja::LijevoDesno){
        //typename std::remove_reference<decltype(kont[0])>::type Vrni;
         int m=kont[0][0].size();
         Vrni.resize(m);
         int n=kont.size();
    for(int i=0;i<m;i++){
        Vrni.at(i).resize(n);
    }
    int s=0;
    int k=kont.size()-1;
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            Vrni.at(i).at(j)=kont.at(k).at(s).at(i);
        }
        s++;
        k--;
    }
        return Vrni;
    }
    if(x==SmjerKretanja::DesnoLijevo){
        //typename std::remove_reference<decltype(kont[0])>::type Vrni;
        int m=kont[0][0].size();
        Vrni.resize(m);
        int n=kont.size();
    for(int i=0;i<m;i++){
        Vrni.at(i).resize(n);
    }
    int s=0;
    int k=0;
    for(int j=0;j<n;j++){
        int r=m-1;
        for(int i=0;i<m;i++){
            Vrni.at(i).at(j)=kont.at(k).at(s).at(r);
            r--;
        }
        s++;
        k++;
    }
        return Vrni;
    }
    return nista;
}

int main ()
{
    Vec kont;
    cout<<"Unesite dimenzije (x y z): ";
    int broj_elemenata_konta;
    cin>> broj_elemenata_konta;
    kont.resize(broj_elemenata_konta);
    int broj_redova_elemenata_konta;
    cin>> broj_redova_elemenata_konta;
    int broj_kolona_elemenata_konta;
    cin>>broj_kolona_elemenata_konta;
    if(broj_kolona_elemenata_konta<0 or broj_redova_elemenata_konta<0 or broj_kolona_elemenata_konta<0) {
    cout<<"Neispravne dimenzije kontejnera!";
    return 0;
    }
    for(int i=0; i<broj_elemenata_konta; i++) {
       kont.at(i).resize(broj_redova_elemenata_konta);
        for(int j=0; j<broj_redova_elemenata_konta; j++) {
            kont.at(i).at(j).resize(broj_kolona_elemenata_konta);
        }
    }
    int x;
     enum SmjerKretanja smjer;
    
    cout<<"Unesite elemente kontejnera: ";
    cout<< std::endl;
    for(int i=0; i<broj_elemenata_konta; i++) {
        for(int j=0; j<broj_redova_elemenata_konta; j++) {
            for(int k=0; k<broj_kolona_elemenata_konta; k++) {
                cin>>kont.at(i).at(j).at(k);
            }
        }
    }
    cout<<"Unesite smjer kretanja [0 - 5]: ";
    cin>> x;
    if(x<0 or x>5) {
    cout<<"Smjer kretanja nije ispravan!";
    cout<<std::endl;
    return 0;
    }

    if(x==0) {
    smjer=SmjerKretanja::NaprijedNazad;
    cout<<"NaprijedNazad: " << std::endl;
    }
    if(x==1) {
    smjer=SmjerKretanja::NazadNaprijed;
    cout<<"NazadNaprijed: " << std::endl;
    }
    if(x==2) {
    smjer=SmjerKretanja::GoreDolje;
    cout<<"GoreDolje: " << std::endl;
    }
    if(x==3) {
    smjer=SmjerKretanja::DoljeGore;
    cout<<"DoljeGore: " << std::endl;
    }
    if(x==4){
    smjer=SmjerKretanja::LijevoDesno;
    cout<<"LijevoDesno: " << std::endl;
    }
    if(x==5){
    smjer=SmjerKretanja::DesnoLijevo;
    cout<<"DesnoLijevo: " << std::endl;
    }
    dekovi dek;
    dek=IzdvojiDijagonale3D(kont,smjer);
     for(int i=0; i<dek.size(); i++) {
        for(int j=0; j<dek[0].size(); j++) {
            

            cout<<std::setw(4)<<dek.at(i).at(j);
            
        }
        cout<<std::endl;
    }
    
    return 0;
}