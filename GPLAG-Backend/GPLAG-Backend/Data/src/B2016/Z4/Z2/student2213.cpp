/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

enum Pol{Musko, Zensko};


class GradjaninBiH {
    
    
    
    string naziv;
    long long int maticni;
    int dan;
    int mjesec;
    int godina;
    int sifra;
    Pol spol;
    GradjaninBiH* prethodni = NULL;
    static GradjaninBiH* posljednji;
    
    public:
    
        GradjaninBiH(string ime_i_prezime, long long int jmbg){
            //RJESENJE PROBLEMA PONAVLJAJUCEG JMBG
            GradjaninBiH *posljednji_kop = posljednji;
            long long int lok_jmbg;
            
            while(posljednji_kop != NULL){
                lok_jmbg = posljednji_kop -> DajJMBG();
                if(jmbg == lok_jmbg) throw logic_error("Vec postoji gradjanin sa istim JMBG");
                else posljednji_kop = posljednji_kop -> DajPrethodnog();
            }
            
            azurirajPoveznicu();//DODAJE TRENUTNO KREIRANU INSTANCU U LANAC
            
            string maticni_str = to_string(jmbg);
            
            int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
            
            c1 = stoi(maticni_str.substr(0,1), nullptr);
            c2 = stoi(maticni_str.substr(1,1), nullptr);
            c3 = stoi(maticni_str.substr(2,1), nullptr);
            c4 = stoi(maticni_str.substr(3,1), nullptr);
            c5 = stoi(maticni_str.substr(4,1), nullptr);
            c6 = stoi(maticni_str.substr(5,1), nullptr);
            c7 = stoi(maticni_str.substr(6,1), nullptr);
            c8 = stoi(maticni_str.substr(7,1), nullptr);
            c9 = stoi(maticni_str.substr(8,1), nullptr);
            c10 = stoi(maticni_str.substr(9,1), nullptr);
            c11 = stoi(maticni_str.substr(10,1), nullptr);
            c12 = stoi(maticni_str.substr(11,1), nullptr);
            c13 = stoi(maticni_str.substr(12,1), nullptr);
            
            long long int c13_kont = 11 - (7*(c1+c7) + 6*(c2+c8) + 5*(c3+c9) + 4*(c4+c10) + 3*(c5+c11) + 2*(c6+c12)) % 11;
            
            if(c13_kont == 10) throw logic_error ("JMBG nije validan");
            
            if(c13_kont == c13)
            {
                
                maticni = jmbg;
                dan = c1*10 + c2;
                mjesec = c3*10 + c4;
                godina = 1000 + c5*100 + c6*10 + c7;
                sifra = c8*10 + c9;
                if(c10 >= 0 && c10 < 5) spol = Musko;
                else spol = Zensko;
            }
            
        }
            
        GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
        {
            godina_rodjenja %= 1000;
            int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
            c1 = dan_rodjenja/10;
            c2 = dan_rodjenja%10;
            c3 = mjesec_rodjenja / 10;
            c4 = mjesec_rodjenja % 10;
            c5 = godina_rodjenja / 100;
            c6 = (godina_rodjenja%100) / 10;
            c7 = godina_rodjenja % 10;
            c8 = sifra_regije / 10;
            c9 = sifra_regije % 10;
            
            string c1str = to_string(c1);
            string c2str = to_string(c2);
            string c3str = to_string(c3);
            string c4str = to_string(c4);
            string c5str = to_string(c5);
            string c6str = to_string(c6);
            string c7str = to_string(c7);
            string c8str = to_string(c8);
            string c9str = to_string(c9);
            
            string pocetak = c1str + c2str + c3str + c4str + c5str + c6str + c7str + c8str + c9str;
            int kod = nadji_najmanji_kod(pocetak, pol);
            
            c10 = kod / 100;
            c11 = (kod%100) / 10;
            c12 = kod % 10;
            
            
            c13 = 11 - (7*(c1+c7) + 6*(c2+c8) + 5*(c3+c9) + 4*(c4+c10) + 3*(c5+c11) + 2*(c6+c12)) % 11;
            
            if(c13 == 11) c13 = 0;
            
            long long int jmbg_nap = c1 * 1000000000000;
            jmbg_nap += (c2 * 100000000000);
            jmbg_nap += (c3 * 10000000000);
            jmbg_nap += (c4 * 1000000000);
            jmbg_nap += (c5 * 100000000);
            jmbg_nap += (c6 * 10000000);
            jmbg_nap += (c7 * 1000000);
            jmbg_nap += (c8 * 100000);
            jmbg_nap += (c9 * 10000);
            jmbg_nap += (c10 * 1000);
            jmbg_nap += (c11 * 100);
            jmbg_nap += (c12 * 10);
            jmbg_nap += c13;
            
            naziv = ime_i_prezime;
            maticni = jmbg_nap;
            dan = dan_rodjenja;
            mjesec = mjesec_rodjenja;
            godina = 1000 + godina_rodjenja;
            sifra = sifra_regije;
            spol = pol;
        }
        
        string DajImeIPrezime() const{
            return naziv;
        }
        
        long long int DajJMBG() const{
            return maticni;
        }
        int DajDanRodjenja() const{
            return dan;
        }
        int DajMjesecRodjenja() const{
            return mjesec;
        }
        int DajGodinuRodjenja() const{
            return godina;
        }
        int DajSifruRegije() const{
            return sifra;
        }
        Pol DajPol() const{
            return spol;
        }
        
        void PromijeniImeIPrezime(string novo_ime){
            naziv = novo_ime;
        }
        
    private:
    
        void azurirajPoveznicu(){
            prethodni = posljednji;
            posljednji = this;
        }
        
        GradjaninBiH* DajPrethodnog(){
            return prethodni;
        }
        
        int nadji_najmanji_kod(string prvih_9, Pol _pol){
            
            int rez;
            if(_pol == Musko) rez = 0;
            if(_pol == Zensko) rez = 500;
            
            long long int lok_jmbg;
            
            GradjaninBiH* posljednji_kop = posljednji;
            while(posljednji_kop!= NULL){
                    lok_jmbg = posljednji_kop -> DajJMBG();
                    string lok_jmbg_str = to_string(lok_jmbg);
                    
                    string lok_pocetak = lok_jmbg_str.substr(0,9);
                    
                    int lok_kod = stoi(lok_jmbg_str.substr(9,3), nullptr);
                    if(prvih_9.compare(lok_pocetak) == 0)
                    {
                        if(_pol == Musko && lok_kod == rez)
                        {
                            rez++;
                        }
                        if(_pol == Zensko && lok_kod == rez)
                        {
                            rez++;
                        }
                        
                    }
                    
                    else posljednji_kop = posljednji_kop -> DajPrethodnog();
            }
            
            return rez;
        }
};


GradjaninBiH* GradjaninBiH::posljednji = NULL;

int main ()
{
    cout << "Koliko gradjana zelite unijeti po JMBG? " << endl;
    int  prvi_broj_gradjana;
    cin >> prvi_broj_gradjana;
    cin.clear();
    cin.ignore(1000, '\n');
    
    string ime_prezime;
    long long int lok_jmbg;
    int i = 0;
    while(i < prvi_broj_gradjana)
    {
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        getline(cin, ime_prezime);
        cout << "Unesite JMBG: " << endl;
        cin >> lok_jmbg;
        
        GradjaninBiH gradj(ime_prezime, lok_jmbg);
        cout << "Unijeli ste gradjaniina " << gradj.DajImeIPrezime() << " rodjenog " << gradj.DajDanRodjenja() << "." << gradj.DajMjesecRodjenja() <<
        "." << gradj.DajGodinuRodjenja() << " u regiji " << gradj.DajSifruRegije() << endl;
        
        i++;
    }
    
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << endl;
    
    int drugi_broj_gradjana;
    cin >> drugi_broj_gradjana;
    
    int lok_dan, lok_mjes, lok_god, lok_sifra;
    char spol_char, temp;
    Pol lok_pol;
    
    int j = 0;
    while (j < drugi_broj_gradjana){
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        getline(cin, ime_prezime);
        cout << "Unesite datum rodjenja (format dd/mm/gggg): " << endl;
        cin >> lok_dan >> temp >> lok_mjes >> temp >> lok_god;
        cout << "Unesite sifru regije: " << endl;
        cin >> lok_sifra;
        cout << "Unesite M za musko, Z za zensko: " << endl;
        cin >> spol_char;
        if(spol_char == 'M') lok_pol = Musko;
        if(spol_char == 'Z') lok_pol = Zensko;
        
        GradjaninBiH gradj(ime_prezime, lok_dan, lok_mjes, lok_god, lok_sifra, lok_pol);
        cout << "Unijeli ste gradjanina " <<  gradj.DajImeIPrezime() << " JMBG: " << gradj.DajImeIPrezime() << "." << endl;
        
    }
    
	return 0;
}