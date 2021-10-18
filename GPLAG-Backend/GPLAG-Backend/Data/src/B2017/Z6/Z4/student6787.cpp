class Ugao {
 int d, m, s; // d = stepeni, m = minute, s = sekunde
public:
 Ugao(int d1, int m1, int s1) { Postavi(d1, m1, s1); }
 void Postavi(int d1, int m1, int s1);
 void Ocitaj(int &d1, int &m1, int &s1) const { d1 = d; m1 = m; s1 = s; }
 double Stepeni() const { return d + m / 60. + s / 3600.; }
 friend Ugao operator -(const Ugao &u) {
 return Ugao(359 - u.d, 59 - u.m, 60 - u.s);
 }
 friend Ugao operator +(const Ugao &u1, const Ugao &u2) {
 return Ugao(u1.d + u2.d, u1.m + u2.m, u1.s + u2.s);
 }
 friend Ugao operator -(const Ugao &u1, const Ugao &u2) {
 return u1 + -u2;
 }
 friend Ugao operator *(const Ugao &u, int n) {
 return Ugao(u.d * n, u.m * n, u.s * n);
 }
 friend Ugao operator *(int n, const Ugao &u) { return u * n; }
 Ugao &operator +=(const Ugao &u) { return *this = *this + u; }
 Ugao &operator -=(const Ugao &u) { return *this = *this - u; }
 Ugao &operator *=(int n) { return *this = *this * n; }
 Ugao &operator ++() { return *this = Ugao(d, m, s + 1); }
 Ugao operator ++(int) { Ugao u = *this; ++*this; return u; }
 friend bool operator ==(const Ugao &u1, const Ugao &u2) {
 return u1.d == u2.d && u1.m == u2.m && u1.s == u2.s;
 }
 friend bool operator !=(const Ugao &u1, const Ugao &u2) {
 return !(u1 == u2);
 }
 friend bool operator <(const Ugao &u1, const Ugao &u2) {
 return u1.Stepeni() < u2.Stepeni();
 }
 friend bool operator <=(const Ugao &u1, const Ugao &u2) {
 return u1.Stepeni() <= u2.Stepeni();
 }
 friend bool operator >(const Ugao &u1, const Ugao &u2) {
 return u1.Stepeni() > u2.Stepeni();
 }
 friend bool operator >=(const Ugao &u1, const Ugao &u2) {
 return u1.Stepeni() >= u2.Stepeni();
 }
 friend ostream &operator <<(ostream &cout, const Ugao &u) {
 return cout << u.d << "d " << u.m << "m " << u.s << "s";
 }
 friend istream &operator >>(istream &cin, Ugao &u);
};
void Ugao::Postavi(int d1, int m1, int s1) {
 if(d1 < 0 || m1 < 0 || s1 < 0) throw "Neispravni parametri!\n";
 s = s1 % 60; m1 += s1 / 60; m = m1 % 60; d1 += m1 / 60; d = d1 % 360;
}
istream &operator >>(istream &cin, Ugao &u) {
 cin >> u.d;
 if(cin.get() != 'd') cin.setstate(ios::failbit);
 cin >> u.m;
 if(cin.get() != 'm') cin.setstate(ios::failbit);
 cin >> u.s;
 if(cin.get() != 's') cin.setstate(ios::failbit); 