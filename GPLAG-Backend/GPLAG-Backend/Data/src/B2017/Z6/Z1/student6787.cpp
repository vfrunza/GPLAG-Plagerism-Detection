class Perpleksni {
 double re, hip;
public:
 Perpleksni(double realni = 0, double hiperbolni = 0) : re(realni),
 hip(hiperbolni) {}
 double DajRealni() const { return re; }
 double DajHiperbolni() const { return hip; }
 friend Perpleksni operator +(const Perpleksni &p1, const Perpleksni &p2) {
 return Perpleksni(p1.re + p2.re, p1.hip + p2.hip);
 }
 friend Perpleksni operator -(const Perpleksni &p1, const Perpleksni &p2) {
 return Perpleksni(p1.re - p2.re, p1.hip - p2.hip);
 }
 friend Perpleksni operator *(const Perpleksni &p1, const Perpleksni &p2) {
 return Perpleksni(p1.re * p2.re + p1.hip * p2.hip,
 p1.re * p2.hip + p2.re * p1.hip);
 }
 friend Perpleksni operator /(const Perpleksni &p1, const Perpleksni &p2) {
 double nazivnik(p2.re * p2.re - p2.hip * p2.hip);
 return Perpleksni((p1.re * p2.re + p1.hip * p2.hip) / nazivnik,
 (p2.re * p1.hip - p1.re * p2.hip) / nazivnik);
 }
 Perpleksni &operator +=(const Perpleksni &p) { return *this = *this + p; }
 Perpleksni &operator -=(const Perpleksni &p) { return *this = *this - p; }
 Perpleksni &operator *=(const Perpleksni &p) { return *this = *this * p; }
 Perpleksni &operator /=(const Perpleksni &p) { return *this = *this / p; }
 friend bool operator ==(const Perpleksni &p1, const Perpleksni &p2) {
 return p1.re == p2.re && p1.hip == p2.hip;
 }
 friend bool operator !=(const Perpleksni &p1, const Perpleksni &p2) {
 return !(p1 == p2);
 }
 Perpleksni operator -() { return Perpleksni(-re, -hip); }
 Perpleksni &operator ++() { re++; return *this; }
 Perpleksni operator ++(int) { Perpleksni p(*this); re++; return p; }
 friend ostream &operator <<(ostream &cout, const Perpleksni &p) {
 return cout << "(" << p.re << "|" << p.hip << ")";
 }
 friend istream &operator >>(istream &cin, Perpleksni &p);
 friend double ApsolutnaVrijednost(const Perpleksni &p);
 friend Perpleksni Konjugirani(const Perpleksni &p) {
 return Perpleksni(p.re, -p.hip);
 }
 friend double RealniDio(const Perpleksni &p) { return p.re; }
 friend double HiperbolniDio(const Perpleksni &p) { return p.hip; }
};
double ApsolutnaVrijednost(const Perpleksni &p) {
 double norma(p.re * p.re - p.hip * p.hip);
 if(norma >= 0) return sqrt(norma);
 else return -sqrt(-norma);
}
istream &operator >>(istream &cin, Perpleksni &p) {
 if(cin.peek() != '(') {
 cin >> p.re; p.hip = 0;
 }
 else {
 char znak;
 cin >> znak;
 if(znak != '(') cin.setstate(ios::failbit);
 cin >> p.re >> znak;
 if(znak != '|') cin.setstate(ios::failbit);
 cin >> p.hip >> znak;
 if(znak != ')') cin.setstate(ios::failbit);
 }
 return cin;
} 