#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Datum {
    int dan, mj, god;
public:    
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mj; }
    int DajGodinu() const { return god; }
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
        broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::logic_error("Neispravni podaci");
        
    this->dan = dan; this->mj = mjesec; this->god = godina;
}

bool IstiDatumi(Datum d1, Datum d2) {
    return d1.DajDan() == d2.DajDan() && d1.DajMjesec() == d2.DajMjesec() && d1.DajGodinu() == d2.DajGodinu();
}

class GradjaninBiH {
    string ime_i_prezime;
    int c[13], sifra_regije;
    long long int JMBG;
    Datum datum_rodjenja;
    static GradjaninBiH *zadnji;
    GradjaninBiH *prethodni;

public:
    enum Pol {Musko, Zensko} pol;
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
        int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return JMBG; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    int DajDanRodjenja() const { return datum_rodjenja.DajDan(); }
    int DajMjesecRodjenja() const { return datum_rodjenja.DajMjesec(); }
    int DajGodinuRodjenja() const { return datum_rodjenja.DajGodinu(); }
    int DajSifruRegije() const { return sifra_regije; }
    Pol DajPol() const { return pol; }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) :
    ime_i_prezime(ime_i_prezime), JMBG(jmbg), prethodni(nullptr) {
    // Pretvaranje broja u niz jmbg    
    for (int i = 12; i >= 0; i--) {
        c[i] = jmbg%10;
        jmbg = jmbg/10;
    }                                                                       /*
Standardni ulaz:	3 
Murga Drot
3005017180005
Gile Sampion
2905017170007*/
    // Postavljanje sifre regije
        sifra_regije = c[7]*10 + c[8];
    
    // Postavljanje pola gradjanina
        int POL(0);
            POL += c[9]*100 + c[10]*10 + c[11];
        if(POL < 500)
            pol = Musko;
        else
            pol = Zensko;
            
    // Trazimo ispravan c13
    int c13;
        c13=11-(7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
        
    // Provjera valjanosti c13    
    if (c13 != 11 and c13 != c[12])    
        throw std::logic_error("JMBG nije validan");
    
    // Provjera valjanosti datuma
    int dan(c[0]*10+c[1]),mjesec(c[2]*10+c[3]),godina(0);
    if(c[6]>=17)
        godina+=2000 + c[4]*100 + c[5]*10 + c[6];
    else
        godina+=1000 + c[4]*100 + c[5]*10 + c[6];
    
    try {
        datum_rodjenja.Postavi(dan, mjesec, godina);
    }
    catch (...) {
        throw std::logic_error("JMBG nije validan");
    }
    // Provjera 2 ista JMBG-a u slucaju da prethodno postoji neki GBiH
    if (zadnji) {
        for(auto it = zadnji; it != nullptr; it = it->prethodni) {
            if(it->JMBG == this->JMBG) {
               // cout << it->JMBG << " " << JMBG;
                throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
            }    
        }
    }
    // "Alociranje" novog gradjanjina!
    if(!zadnji)
        zadnji = this;
    else {
        this->prethodni=zadnji;
        zadnji = this;
    }
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime), prethodni(nullptr), pol(pol) {
        
    // Provjera i postavljanje datuma    
    try {
        datum_rodjenja.Postavi(dan_rodjenja, mjesec_rodjenja, godina_rodjenja);
    }
    catch (...) {
        throw std::logic_error("Neispravni podaci");
    }
        
    // Provjera i postavljanje sifre regije    
    if(sifra_regije<0 or sifra_regije>99)
        throw  std::logic_error("Neispravni podaci");
    
    this->sifra_regije = sifra_regije;
    
    // postavljanje c[13]
    c[0] = datum_rodjenja.DajDan()/10;
    c[1] = datum_rodjenja.DajDan()%10;
    c[2] = datum_rodjenja.DajMjesec()/10;
    c[3] = datum_rodjenja.DajMjesec()%10;
    c[4] = (datum_rodjenja.DajGodinu()%1000)/100;
    c[5] = (datum_rodjenja.DajGodinu()%100)/10;
    c[6] = datum_rodjenja.DajGodinu()%10;
    c[7] = sifra_regije/10;
    c[8] = sifra_regije%10;
    
    if(!zadnji) {                     // Sve ovo ako zadnji nije nullptr
        int iniz[500];
        for (int i = 0; i < 500; i++) 
            iniz[i] = i;
        
        if(pol == Zensko)
            for (int i = 0; i < 500; i++) 
                iniz[i] += 500;
        
        bool naso_slobodno = false;
        for(int i = 0; i<500; i++){
            //prvjeravas da li ima i-ti u listi
            
            // prolazis kroz listu
            bool pronasao_i = false;
            for(auto it = zadnji; it != nullptr; it = it->prethodni){
                if(IstiDatumi(this->DajDatumRodjenja(), it->DajDatumRodjenja()) 
                    && this->DajSifruRegije() == it->DajSifruRegije()
                    && this->DajPol() == it->DajPol()){
                        
                        int spec_broj = it->c[9]*100 + it->c[10]*10 + c[11];           
                        if(it->DajPol() == Pol::Zensko){
                            spec_broj -= 500;
                        }
                        
                        if(i == spec_broj){
                            pronasao_i = true;
                            break;
                        }
                        
                    }
            }
            
            if(!pronasao_i){
                naso_slobodno = true;
                c[11] = i%100; c[10] = (i%10)/10; c[9] = i/100;
                if(this->DajPol() == Pol::Zensko){
                    c[9] += 5;
                }
                break;
            }
            
        }
        
        if(!naso_slobodno){
            throw std::logic_error("JMBG nije moguc"); // nema slobodno mjesto
        }
        c[12]=11-(7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
        if(c[12] == 11)
            c[12] = 0;
        JMBG = 0;
        
        for(int i = 0; i < 13; i++){
            JMBG = JMBG*10 + c[i];
        }
        
        
    }
    
}

GradjaninBiH *GradjaninBiH::zadnji=nullptr;

int main ()
{
    int n;
    cout << "Koliko gradjana zelite unijeti po JMBG? " << endl;
    cin >> n;
    cin.ignore(100,'\n');
    
    string ime_i_prezime;
    long long int jmbg;
    
    for (int i = 0; i < n; i++) {
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        getline(cin, ime_i_prezime);
        cout << "Unesite JMBG: " << endl;
        cin >> jmbg;
        cin.ignore(100,'\n');
        
        try {
            GradjaninBiH g(ime_i_prezime,jmbg);
            cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " rodjenog "
            << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "."
            << g.DajGodinuRodjenja() << " u regiji " << g.DajSifruRegije() << 
            ", ";
            if(g.pol == GradjaninBiH::Musko)
                cout << "musko." << endl;
            else 
                cout << "zensko." << endl;
        }
        catch (std::logic_error err) {
            std::cout <<endl <<  err.what() << std::endl;
            i--;
            continue;
        }
    }
    
    char znak1, znak2, MZ;
    int dan, mjesec, godina, sifra_regije;
    
    cout  << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?" << endl;
    cin >> n;
    cin.ignore(100,'\n');
    
    for (int i = 0; i < n; i++) {
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        getline(cin, ime_i_prezime);
        cout << "Unesite datum rodjenja (format dd/mm/gggg):" << endl;
        cin >> dan;
        cin.ignore(100,'\n');
        cin >> znak1 >> mjesec;
        cin.ignore(100,'\n');
        cin >> znak2 >> godina;
        cout << "Unesite sifru regije: " << endl;
        cin >> sifra_regije;
        cin.ignore(100,'\n');
        cout << "Unesite M za musko, Z za zensko: " << endl;
        cin >> MZ;
        
        try {
            if(MZ == 'M') {
            GradjaninBiH g(ime_i_prezime, dan, mjesec ,godina, sifra_regije, GradjaninBiH::Musko);
            cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " JMBG: " << g.DajJMBG();
          } else {
            GradjaninBiH g(ime_i_prezime, dan, mjesec ,godina, sifra_regije, GradjaninBiH::Zensko);
            cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " JMBG: " << g.DajJMBG();
          }    
        }
        catch (const char error[]) {
            std::cout << error << std::endl;
        }
        
        
    }    
    
    
    
	return 0;
}