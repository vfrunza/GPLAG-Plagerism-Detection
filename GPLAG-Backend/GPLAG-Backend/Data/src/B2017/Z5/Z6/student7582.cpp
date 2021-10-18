#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
class Berza{
    int max,min;
    vector<int> v;
    public:
    Berza(int min, int max){if(max<0 || min<0) throw range_error("Ilegalne granicne cijene"); Berza::max=max; Berza::min=min;}
    explicit Berza(int max){if(max<0) throw range_error("Ilegalne granicne cijene"); Berza::max=max; Berza::min=0;}
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const{return v.size();}
    void BrisiSve(){v.resize(0);}
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator!() const {return !v.size();}
    int DajBrojCijenaVecihOd(int) const;
    void Ispisi() const;
    int operator[](int i) const;
    Berza &operator++();
    Berza &operator--();
    Berza operator++(int);
    Berza operator--(int);
    Berza operator-()const;
    bool operator==(const Berza &b) const;
    bool operator!=(const Berza &b) const;
    Berza &operator+=(int y);
    Berza &operator-=(int y);
    Berza operator+(int y) const;
    Berza operator-(int y) const;
    Berza operator+(const Berza &b) const;
    Berza operator-(const Berza &b) const;
    friend Berza operator+(int y,const Berza &b);
    friend Berza operator-(int y,const Berza &b);
};
void Berza::RegistrirajCijenu(int cijena){
    if(cijena>max || cijena<min) throw range_error("Ilegalna cijena");
    v.push_back(cijena);
}
int Berza::DajMinimalnuCijenu() const{
    if(!v.size()) throw range_error("Nema registriranih cijena");
    return *min_element(v.begin(), v.end());
}
int Berza::DajMaksimalnuCijenu() const{
    if(!v.size()) throw range_error("Nema registriranih cijena");
    return *max_element(v.begin(), v.end());
}
int Berza::DajBrojCijenaVecihOd(int x) const{
    return count_if(v.begin(), v.end(), bind(greater<int>(), placeholders::_1, x));
}
void Berza::Ispisi() const{
    auto pomocni(v);
    sort(pomocni.begin(),pomocni.end(),greater<int>());
    for(int i=0;i<pomocni.size();i++){
        cout<<fixed<<setprecision(2)<<pomocni[i]/100.<<endl;
    }
}
int Berza::operator[](int i) const{
    if(i<1 || i>v.size()) throw range_error("Neispravan indeks");
    return v.at(i-1);
}
Berza &Berza::operator++(){
    if(this->DajMaksimalnuCijenu()+100>max) throw range_error("Prekoracen dozvoljeni opseg cijena");
    transform(v.begin(),v.end(),v.begin(), bind(plus<int>(),100, placeholders::_1));
    return *this;
}
Berza &Berza::operator--(){
    if(this->DajMinimalnuCijenu()-100<min) throw range_error("Prekoracen dozvoljeni opseg cijena");
    transform(v.begin(),v.end(),v.begin(), bind(minus<int>(),placeholders::_1, 100));
    return *this;
}
Berza Berza::operator++(int){
    Berza temp(*this);
    ++(*this);
    return temp;
}
Berza Berza::operator--(int){
    Berza temp(*this);
    --(*this);
    return temp;
}
Berza Berza::operator-() const{
    int kapacitet(max+min);
    Berza nova(*this);
    transform(nova.v.begin(),nova.v.end(),nova.v.begin(),bind(minus<int>(),kapacitet,placeholders::_1));
    return nova;
}
bool Berza::operator==(const Berza &b) const{
    if(v.size()!=b.v.size()) return false;
    for(int i=0;i<v.size();i++){
        if(not_equal_to<int>()(v.at(i),b.v.at(i))) return false;
    }
    return true;
}
bool Berza::operator!=(const Berza &b) const{
    return !((*this)==b);
}
Berza &Berza::operator+=(int y){
    if(DajMaksimalnuCijenu()+y>max) throw domain_error("Prekoracen dozvoljeni opseg cijena");
    transform(v.begin(),v.end(),v.begin(), bind(plus<int>(),y, placeholders::_1));
    return *this;
}
Berza &Berza::operator-=(int y){
    if(DajMinimalnuCijenu()-y<min) throw domain_error("Prekoracen dozvoljeni opseg cijena");
    transform(v.begin(),v.end(),v.begin(), bind(minus<int>(),placeholders::_1,y));
    return *this;
}
Berza Berza::operator+(int y) const{
    Berza b(*this);
    b+=y;
    return b;
}
Berza Berza::operator-(int y) const{
    Berza b(*this);
    b-=y;
    return b;
}
Berza Berza::operator+(const Berza &b) const{
    if(max!=b.max || min!=b.min || v.size()!=b.v.size()) throw domain_error("Nesaglasni operandi");
    if(DajMaksimalnuCijenu()+b.DajMaksimalnuCijenu()>max) throw domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza nova(*this);
    transform(nova.v.begin(),nova.v.end(),b.v.begin(),nova.v.begin(),plus<int>());
    return nova;
}
Berza Berza::operator-(const Berza &b) const{
    if(max!=b.max || min!=b.min || v.size()!=b.v.size()) throw domain_error("Nesaglasni operandi");
    if(DajMinimalnuCijenu()-b.DajMaksimalnuCijenu()<min) throw domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza nova(*this);
    transform(nova.v.begin(),nova.v.end(),b.v.begin(),nova.v.begin(),minus<int>());
    return nova;
}
Berza operator+(int y,const Berza &b){
    Berza nova(b);
    nova+=y;
    return nova;
}
Berza operator-(int y,const Berza &b){
    if(y-b.DajMaksimalnuCijenu()<b.min) throw domain_error("Prekoracen dozvoljeni opseg cijena");
    if(y-b.DajMinimalnuCijenu()>b.max) throw domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza nova(b);
    transform(nova.v.begin(),nova.v.end(),nova.v.begin(), bind(minus<int>(),y, placeholders::_1));
    return nova;
}
int main ()
{
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    b1.RegistrirajCijenu(2025);
    Berza b2 = Berza(1000,4000);
    b2.RegistrirajCijenu(3000);
    b2.RegistrirajCijenu(1530);
    b2.RegistrirajCijenu(2025);
    if(b1==b2) cout<<1;
    if(b1!=b2) cout<<0;
    std::cout << "Minimalna cijena: " << b1.DajMinimalnuCijenu() << std::endl;
    std::cout << "Maksimalna cijena: " << b1.DajMaksimalnuCijenu()<<endl;
    cout<<b1.DajBrojCijenaVecihOd(1400)<<endl;
    (++b1).Ispisi();
    (-b1).Ispisi();
    b1.Ispisi();
    cout<<b1[3]<<endl;
    cout<<!b1<<endl;
    b1.BrisiSve();
    cout<<!b1<<endl;
    /*if(b1==b1) cout<<"jesu"<<endl;
    if(b1!=b1) cout<<"nisu"<<endl;*/
    b2+=6;
    b2.Ispisi();
    (b2+4).Ispisi();
    b2.Ispisi();
    (b2-6).Ispisi();
    b2.Ispisi();
    (4500-b2).Ispisi();
    Berza b3 = Berza(0,4000);
    Berza b4 = Berza(0,4000);
    b3.RegistrirajCijenu(100);
    b3.RegistrirajCijenu(200);
    b3.RegistrirajCijenu(300);
    b4.RegistrirajCijenu(1000);
    b4.RegistrirajCijenu(2000);
    b4.RegistrirajCijenu(3000);
    (b3+b4).Ispisi();
    (b4-b3).Ispisi();
    if(b3!=b4) cout<<1;
	return 0;
}
