class ADuzine {
 int inci;
public:
 ADuzine(int jardi, int stope, int inci) {
 ADuzine::inci = 36 * jardi + 12 * stope + inci;
 }
 ADuzine(double metri) { inci = int(metri / 0.0254 + 0.5); }
 void Ocitaj(int &jardi, int &stope, int &inci);
 double DajMetre() const { return inci * 0.0254; }
 friend ADuzine operator +(ADuzine d1, ADuzine d2) {
 return ADuzine(0, 0, d1.inci + d2.inci);
 }
 ADuzine &operator +=(ADuzine d) { inci += d.inci; return *this; }
 ADuzine &operator ++() { inci++; return *this; }
 ADuzine operator ++(int) { ADuzine stara(*this); inci++; return stara; }
 friend ADuzine operator *(ADuzine d, double faktor) {
 return ADuzine(0, 0, int(d.inci * faktor + 0.5));
 }
 friend ADuzine operator *(double faktor, ADuzine d) { return d * faktor; }
 friend double operator /(ADuzine d1, ADuzine d2) {
 return double(d1.inci) / d2.inci;
 }
 friend ostream &operator <<(ostream &tok, ADuzine d);
};
Praktično jedini elementi klase koji zaslužuju da budu implementirani izvan klase su metoda
“Ocitaj” i operator ispisa:
void ADuzine::Ocitaj(int &jardi, int &stope, int &inci) {
 jardi = ADuzine::inci / 36;
 stope = (ADuzine::inci % 36) / 12;
 inci = ADuzine::inci % 12;
}
ostream &operator <<(ostream &tok, ADuzine d) {
 int jardi, stope, inci;
 d.Ocitaj(jardi, stope, inci);
 return tok << jardi << " yd " << stope << " ft " << inci << " in"; 