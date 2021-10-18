struct Uposlenik {
 char ime[20], adresa[50];
 int telefon;
};
class Imenik {
 Uposlenik *uposlenici;
 int kapacitet, br_uposlenika;
public:
 explicit Imenik(int kapacitet): kapacitet(kapacitet), br_uposlenika(0),
 uposlenici(new Uposlenik[kapacitet]) {}
 ~Imenik() {
 delete[] uposlenici;
 }
 Imenik(const Imenik &);
 Imenik &operator =(const Imenik &);
 void DodajUposlenika(const char*, const char*, int);
 void DodajUposlenika(const Uposlenik &u) {
 if(kapacitet==br_uposlenika) throw "Nema mjesta!";
 uposlenici[br_uposlenika++]=u;
 }
 void DodajUposlenika(Uposlenik *u) {
 if(kapacitet==br_uposlenika) throw "Nema mjesta!";
 uposlenici[br_uposlenika++]=*u;
 }
 void IspisiUposlenika(const char*) const;
 void IspisiSveNaSlovo(char) const;
 void IspisiImenik();
 int &operator [](const char*);
 int operator [](const char*) const;
 bool operator !() const {
 return br_uposlenika==0;
 }
 friend Imenik operator +(const Imenik &, const Imenik &);
 void Sacuvaj(const char*);
 void Obnovi(const char*);
};
void Imenik::Obnovi(const char* ime_datoteke) {
 ifstream ulaz(ime_datoteke, ios::in | ios::binary);
 if(!ulaz) throw "Datoteka ne postoji!";
 delete[] uposlenici;
 ulaz.read((char*)this, sizeof *this);
 uposlenici=new Uposlenik[kapacitet];
 ulaz.read((char*)uposlenici, br_uposlenika*sizeof(Uposlenik));
 if(!ulaz) throw "Problem sa citanjem iz datoteke!";
}
void Imenik::Sacuvaj(const char* ime_datoteke) {
 ofstream izlaz(ime_datoteke, ios::out | ios::binary);
 izlaz.write((char*)this, sizeof *this);
 izlaz.write((char*)uposlenici, br_uposlenika*sizeof(Uposlenik));
 if(!izlaz) throw "Problem sa upisom u datoteku!";
}
Imenik operator +(const Imenik &i1, const Imenik &i2) {
 Imenik i3(i1.kapacitet+i2.kapacitet);
 for(int i(0); i<i1.br_uposlenika; i++) i3.DodajUposlenika(i1.uposlenici[i]);
 for(int i(0); i<i2.br_uposlenika; i++) i3.DodajUposlenika(i2.uposlenici[i]);
 return i3;
}
int Imenik::operator [](const char *ime) const {
 for(int i(0); i<br_uposlenika; i++)
 if(strcmp(uposlenici[i].ime, ime)==0) return uposlenici[i].telefon;
 throw "Nepostojeci korisnik!";
}
int &Imenik::operator [](const char *ime) {
 for(int i(0); i<br_uposlenika; i++)
 if(strcmp(uposlenici[i].ime, ime)==0) return uposlenici[i].telefon;
 throw "Nepostojeci korisnik!";
}
void Imenik::IspisiImenik() {
 sort(uposlenici, uposlenici+br_uposlenika, [](const Uposlenik &u1, const Uposlenik &
u2) {
 return strcmp(u1.ime, u2.ime)<=0;
 });
 for(int i(0); i<br_uposlenika; i++)
 cout << uposlenici[i].ime << endl << uposlenici[i].adresa << endl << uposlenici[i].
telefon << endl;
}
void Imenik::IspisiSveNaSlovo(char s) const {
 for(int i(0); i<br_uposlenika; i++)
 if(uposlenici[i].ime[0]==s)
 cout << uposlenici[i].ime << endl << uposlenici[i].adresa << endl <<
uposlenici[i].telefon << endl;
}
void Imenik::IspisiUposlenika(const char* ime) const {
 for(int i(0); i<br_uposlenika; i++)
 if(strcmp(uposlenici[i].ime, ime)==0) {
 cout << uposlenici[i].ime << endl << uposlenici[i].adresa << endl <<
uposlenici[i].telefon << endl;
 return;
 }
 throw "Uposlenik nije pronadjen!";
}
void Imenik::DodajUposlenika(const char* ime, const char* adresa, int telefon) {
 if(br_uposlenika==kapacitet) throw "Nema mjesta!";
 if(strlen(ime)>20 || strlen(adresa)>50) throw "Predugacko ime ili prezime!";
 strcpy(uposlenici[br_uposlenika].ime,ime);
 strcpy(uposlenici[br_uposlenika].adresa,adresa);
 uposlenici[br_uposlenika++].telefon=telefon;
}
Imenik &Imenik::operator =(const Imenik &im) {
 if(&im==this) return *this;
 delete[] uposlenici;
 kapacitet=im.kapacitet;
 br_uposlenika=im.br_uposlenika;
 uposlenici=new Uposlenik[kapacitet];
 copy(im.uposlenici, im.uposlenici+br_uposlenika, uposlenici);
 return *this;
}
Imenik::Imenik(const Imenik &im) {
 kapacitet=im.kapacitet;
 br_uposlenika=im.br_uposlenika;
 uposlenici=new Uposlenik[kapacitet];
 copy(im.uposlenici, im.uposlenici+br_uposlenika, uposlenici);
//! ZADATAK 2
struct Uposlenik {
 char ime[20], adresa[50];
 int telefon;
};
class Imenik {
 Uposlenik **uposlenici;
 int kapacitet, br_uposlenika;
public:
 explicit Imenik(int kapacitet): kapacitet(kapacitet), br_uposlenika(0),
 uposlenici(new Uposlenik*[kapacitet]) {}
 ~Imenik() {
 for(int i(0); i<br_uposlenika; i++) delete uposlenici[i];
 delete[] uposlenici;
 }
 Imenik(const Imenik &);
 Imenik &operator =(const Imenik &);
 void DodajUposlenika(const char*, const char*, int);
 void DodajUposlenika(const Uposlenik &u) {
 if(kapacitet==br_uposlenika) throw "Nema mjesta!";
 uposlenici[br_uposlenika++]=new Uposlenik(u);
 }
 void DodajUposlenika(Uposlenik *u) {
 if(kapacitet==br_uposlenika) throw "Nema mjesta!";
 uposlenici[br_uposlenika++]=new Uposlenik(*u);
 }
 void IspisiUposlenika(const char*) const;
 void IspisiSveNaSlovo(char) const;
 void IspisiImenik();
 int &operator [](const char*);
 int operator [](const char*) const;
 bool operator !() const {
 return br_uposlenika==0;
 }
 friend Imenik operator +(const Imenik &, const Imenik &);
 void Sacuvaj(const char*);
 void Obnovi(const char*);
};
void Imenik::Obnovi(const char* ime_datoteke) {
 ifstream ulaz(ime_datoteke, ios::in | ios::binary);
 if(!ulaz) throw "Datoteka ne postoji!";
 for(int i(0); i<br_uposlenika; i++) delete uposlenici[i];
 delete[] uposlenici;
 ulaz.read((char*)this, sizeof *this);
 uposlenici=new Uposlenik*[kapacitet];
 for(int i(0); i<br_uposlenika; i++) {
 uposlenici[i]=new Uposlenik;
 ulaz.read((char*)uposlenici, br_uposlenika*sizeof(Uposlenik));
 }
 if(!ulaz) throw "Problem sa citanjem iz datoteke!";
}
void Imenik::Sacuvaj(const char* ime_datoteke) {
 ofstream izlaz(ime_datoteke, ios::out | ios::binary);
 izlaz.write((char*)this, sizeof *this);
 for(int i(0); i<br_uposlenika; i++)
 izlaz.write((char*)uposlenici[i], sizeof(Uposlenik));
 if(!izlaz) throw "Problem sa upisom u datoteku!";
}
Imenik operator +(const Imenik &i1, const Imenik &i2) {
 Imenik i3(i1.kapacitet+i2.kapacitet);
 for(int i(0); i<i1.br_uposlenika; i++) i3.DodajUposlenika(i1.uposlenici[i]);
  for(int i(0); i<i2.br_uposlenika; i++) i3.DodajUposlenika(i2.uposlenici[i]);
 return i3;
}
int Imenik::operator [](const char *ime) const {
 for(int i(0); i<br_uposlenika; i++)
 if(strcmp(uposlenici[i]->ime, ime)==0) return uposlenici[i]->telefon;
 throw "Nepostojeci korisnik!";
}
int &Imenik::operator [](const char *ime) {
 for(int i(0); i<br_uposlenika; i++)
 if(strcmp(uposlenici[i]->ime, ime)==0) return uposlenici[i]->telefon;
 throw "Nepostojeci korisnik!";
}
void Imenik::IspisiImenik() {
 sort(uposlenici, uposlenici+br_uposlenika, [](Uposlenik *u1, Uposlenik *u2) {
 return strcmp(u1->ime, u2->ime)<=0;
 });
 for(int i(0); i<br_uposlenika; i++)
 cout << uposlenici[i]->ime << endl << uposlenici[i]->adresa << endl << uposlenici
[i]->telefon << endl;
}
void Imenik::IspisiSveNaSlovo(char s) const {
 for(int i(0); i<br_uposlenika; i++)
 if(uposlenici[i]->ime[0]==s)
 cout << uposlenici[i]->ime << endl << uposlenici[i]->adresa << endl <<
uposlenici[i]->telefon << endl;
}
void Imenik::IspisiUposlenika(const char* ime) const {
 for(int i(0); i<br_uposlenika; i++)
 if(strcmp(uposlenici[i]->ime, ime)==0) {
 cout << uposlenici[i]->ime << endl << uposlenici[i]->adresa << endl <<
uposlenici[i]->telefon << endl;
 return;
 }
 throw "Uposlenik nije pronadjen!";
}
void Imenik::DodajUposlenika(const char* ime, const char* adresa, int telefon) {
 if(br_uposlenika==kapacitet) throw "Nema mjesta!";
 if(strlen(ime)>20 || strlen(adresa)>50) throw "Predugacko ime ili prezime!";
 uposlenici[br_uposlenika]=new Uposlenik;
 strcpy(uposlenici[br_uposlenika]->ime,ime);
 strcpy(uposlenici[br_uposlenika]->adresa,adresa);
 uposlenici[br_uposlenika++]->telefon=telefon;
}
Imenik &Imenik::operator =(const Imenik &im) {
 if(&im==this) return *this;
 for(int i(0); i<br_uposlenika; i++) delete uposlenici[i];
 delete[] uposlenici;
 kapacitet=im.kapacitet;
 br_uposlenika=im.br_uposlenika;
 uposlenici=new Uposlenik*[kapacitet];
 for(int i(0); i<br_uposlenika; i++) uposlenici[i]=new Uposlenik(*im.uposlenici[i]);
 return *this;
}
Imenik::Imenik(const Imenik &im) {
 kapacitet=im.kapacitet;
 br_uposlenika=im.br_uposlenika;
 uposlenici=new Uposlenik*[kapacitet];
 for(int i(0); i<br_uposlenika; i++) uposlenici[i]=new Uposlenik(*im.uposlenici[i]);
 class Uposlenik {
 string ime, adresa;
 int telefon;
public:
 Uposlenik(string ime, string adresa, int telefon):
 ime(ime), adresa(adresa), telefon(telefon) {}
 string DajIme() const {
 return ime;
 }
 string DajAdresu() const {
 return adresa;
 }
 int DajTelefon() const {
 return telefon;
 }
 int &DajTelefon() { //potrebno za operator [] koji vraca referencu
 return telefon;
 }
};
class Imenik {
 vector<Uposlenik> uposlenici;
public:
 void DodajUposlenika(string, string, int);
 void DodajUposlenika(const Uposlenik &u) {
 uposlenici.push_back(u);
 }
 void DodajUposlenika(Uposlenik *u) {
 uposlenici.push_back(*u);
 }
 void IspisiUposlenika(string) const;
 void IspisiSveNaSlovo(char) const;
 void IspisiImenik();
 int &operator [](string);
 int operator [](string) const;
 bool operator !() const {
 return uposlenici.size();
 }
 friend Imenik operator +(const Imenik &, const Imenik &);
 void Sacuvaj(const char*);
 void Obnovi(const char*);
};
void Imenik::Obnovi(const char* ime_datoteke) {
 ifstream ulaz(ime_datoteke);
 if(!ulaz) throw "Datoteka ne postoji!";
 string ime, adresa;
 int telefon;
 for(;;) {
 getline(ulaz, ime);
 if(!ulaz) break;
 getline(ulaz, adresa);
 ulaz >> telefon;
 ulaz.ignore(10000, '\n');
 DodajUposlenika(ime, adresa, telefon);
 }
}
void Imenik::Sacuvaj(const char* ime_datoteke) {
 ofstream izlaz(ime_datoteke);
 if(!izlaz) throw "Problem sa upisom u datoteku!";
 for(int i(0); i<uposlenici.size(); i++) {
 izlaz << uposlenici[i].DajIme() << endl << uposlenici[i].DajAdresu()
 << endl << uposlenici[i].DajTelefon() << endl;
 }
}
Imenik operator +(const Imenik &i1, const Imenik &i2) {
 Imenik i3;
 for(int i(0); i<i1.uposlenici.size(); i++) i3.uposlenici.push_back(i1.uposlenici[i]);
 for(int i(0); i<i2.uposlenici.size(); i++) i3.uposlenici.push_back(i2.uposlenici[i]);
 return i3;
}
int Imenik::operator [](string ime) const {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i].DajIme()==ime) return uposlenici[i].DajTelefon();
 throw "Nepostojeci korisnik!";
}
int &Imenik::operator [](string ime) {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i].DajIme()==ime) return uposlenici[i].DajTelefon();
 throw "Nepostojeci korisnik!";
}
void Imenik::IspisiImenik() {
 sort(uposlenici.begin(), uposlenici.end(), [](const Uposlenik &u1, const Uposlenik &
u2) {
 return u1.DajIme() < u2.DajIme();
 });
 for(int i(0); i<uposlenici.size(); i++)
 cout << uposlenici[i].DajIme() << endl << uposlenici[i].DajAdresu()
 << endl << uposlenici[i].DajTelefon() << endl;
}
void Imenik::IspisiSveNaSlovo(char s) const {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i].DajIme()[0]==s)
 cout << uposlenici[i].DajIme() << endl << uposlenici[i].DajAdresu()
 << endl << uposlenici[i].DajTelefon() << endl;
}
void Imenik::IspisiUposlenika(string ime) const {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i].DajIme()==ime) {
 cout << uposlenici[i].DajIme() << endl << uposlenici[i].DajAdresu()
 << endl << uposlenici[i].DajTelefon() << endl;
 return;
 }
 throw "Uposlenik nije pronadjen!";
}
void Imenik::DodajUposlenika(string ime, string adresa, int telefon) {
 uposlenici.push_back(Uposlenik(ime, adresa, telefon));
}
//! ZADATAK 4
class Uposlenik {
 string ime, adresa;
 int telefon;
public:
 Uposlenik(string ime, string adresa, int telefon):
 ime(ime), adresa(adresa), telefon(telefon) {}
 string DajIme() const {
 return ime;
 }
 string DajAdresu() const {
 return adresa;
 }
 int DajTelefon() const {
 return telefon;
 }
 int &DajTelefon() { //potrebno za operator [] koji vraca referencu
 return telefon;
 }
};
class Imenik {
 vector<Uposlenik*> uposlenici;
public:
 Imenik() {}
 Imenik(const Imenik &);
 ~Imenik();
 Imenik &operator =(const Imenik &);
 void DodajUposlenika(string, string, int);
 void DodajUposlenika(const Uposlenik &u) {
 uposlenici.push_back(new Uposlenik(u));
 }
 void DodajUposlenika(Uposlenik *u) {
 uposlenici.push_back(new Uposlenik(*u));
 }
 void IspisiUposlenika(string) const;
 void IspisiSveNaSlovo(char) const;
 void IspisiImenik() const;
 int &operator [](string);
 int operator [](string) const;
 bool operator !() const {
 return uposlenici.size();
 }
 friend Imenik operator +(const Imenik &, const Imenik &);
 void Sacuvaj(const char*);
 void Obnovi(const char*);
};
void Imenik::Obnovi(const char* ime_datoteke) {
 ifstream ulaz(ime_datoteke);
 if(!ulaz) throw "Datoteka ne postoji!";
 string ime, adresa;
 int telefon;
 for(;;) {
 getline(ulaz, ime);
 if(!ulaz) break;
 getline(ulaz, adresa);
 ulaz >> telefon;
 ulaz.ignore(10000, '\n');
 DodajUposlenika(ime, adresa, telefon);
 }
}
void Imenik::Sacuvaj(const char* ime_datoteke) {
 ofstream izlaz(ime_datoteke);
 if(!izlaz) throw "Problem sa upisom u datoteku!";
 for(int i(0); i<uposlenici.size(); i++) {
 izlaz << uposlenici[i]->DajIme() << endl << uposlenici[i]->DajAdresu()
 << endl << uposlenici[i]->DajTelefon() << endl;
 }
}
Imenik operator +(const Imenik &i1, const Imenik &i2) {
 Imenik i3;
 for(int i(0); i<i1.uposlenici.size(); i++) i3.DodajUposlenika(*i1.uposlenici[i]);
 for(int i(0); i<i2.uposlenici.size(); i++) i3.DodajUposlenika(*i2.uposlenici[i]);
 return i3;
}
int Imenik::operator [](string ime) const {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i]->DajIme()==ime) return uposlenici[i]->DajTelefon();
 throw "Nepostojeci korisnik!";
}
int &Imenik::operator [](string ime) {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i]->DajIme()==ime) return uposlenici[i]->DajTelefon();
 throw "Nepostojeci korisnik!";
}
void Imenik::IspisiImenik() const {
 sort(uposlenici.begin(), uposlenici.end(), [](Uposlenik *u1, Uposlenik *u2) {
 return u1->DajIme() < u2->DajIme();
 });
 for(int i(0); i<uposlenici.size(); i++)
 cout << uposlenici[i]->DajIme() << endl << uposlenici[i]->DajAdresu()
 << endl << uposlenici[i]->DajTelefon() << endl;
}
void Imenik::IspisiSveNaSlovo(char s) const {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i]->DajIme()[0]==s)
 cout << uposlenici[i]->DajIme() << endl << uposlenici[i]->DajAdresu()
 << endl << uposlenici[i]->DajTelefon() << endl;
}
void Imenik::IspisiUposlenika(string ime) const {
 for(int i(0); i<uposlenici.size(); i++)
 if(uposlenici[i]->DajIme()==ime) {
 cout << uposlenici[i]->DajIme() << endl << uposlenici[i]->DajAdresu()
 << endl << uposlenici[i]->DajTelefon() << endl;
 return;
 }
 throw "Uposlenik nije pronadjen!";
}
void Imenik::DodajUposlenika(string ime, string adresa, int telefon) {
 uposlenici.push_back(new Uposlenik(ime, adresa, telefon));
}
Imenik &Imenik::operator =(const Imenik &im) {
 if(&im==this) return *this;
 for(int i(0); i<uposlenici.size(); i++) delete uposlenici[i];
 uposlenici.resize(0);
 for(int i(0); i<im.uposlenici.size(); i++)
 uposlenici.push_back(new Uposlenik(*im.uposlenici[i]));
}
Imenik::~Imenik() {
 for(int i(0); i<uposlenici.size(); i++) delete uposlenici[i];
}
Imenik::Imenik(const Imenik &im) {
 for(int i(0); i<im.uposlenici.size(); i++)
 uposlenici.push_back(new Uposlenik(*im.uposlenici[i]));