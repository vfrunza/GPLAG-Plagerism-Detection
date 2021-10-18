/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
using namespace std;
class GradjaninBiH{
  string ime_i_prezime;
  long long int jmbg;
  int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
  GradjaninBiH *veza; 
  mutable int m=0, z=500; 
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
private:
    Pol pol; 
};
GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int jmbg){
    
    GradjaninBiH::ime_i_prezime=ime_i_prezime; 
    GradjaninBiH::jmbg=jmbg;
    long long int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
    c13=jmbg%10; jmbg/=10;
    c12=jmbg%10; jmbg/=10;
    c11=jmbg%10; jmbg/=10;
    c10=jmbg%10; jmbg/=10;
    c9=jmbg%10; jmbg/=10;
    c8=jmbg%10; jmbg/=10;
    c7=jmbg%10; jmbg/=10;
    c6=jmbg%10; jmbg/=10;
    c5=jmbg%10; jmbg/=10;
    c4=jmbg%10; jmbg/=10;
    c3=jmbg%10; jmbg/=10;
    c2=jmbg%10; jmbg/=10;
    c1=jmbg%10; jmbg/=10;
    
    int dan=c2+c1*10; 
    
    int mjesec=c4+c3*10; 
    
    int god=c7+c6*10+c5*100; 
    if(c5>0) god=god+1000; 
    else if(c5==0) god=god+2000;
    
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(god % 4 == 0 && god % 100 != 0 || god % 400 == 0) broj_dana[1]++;
    if(god < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw logic_error ("JMBG nije validan"); 
        
    int sifra=c9+c8*10; 
    int p=c12+c11*10+c10*100; 
    if(p<500) pol=Musko; 
    else pol=Zensko; 
     
    int mojc13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
    if(mojc13 == 11) mojc13=0;
    if(mojc13==10 || mojc13!=c13) throw logic_error ("JMBG nije validan"); 
    
    godina_rodjenja=god; 
    dan_rodjenja=dan; 
    mjesec_rodjenja=mjesec; 
    sifra_regije=sifra; 
    
    
}
GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::dan_rodjenja=dan_rodjenja; 
    GradjaninBiH::godina_rodjenja=mjesec_rodjenja; 
    GradjaninBiH::sifra_regije=sifra_regije; 
    GradjaninBiH::pol=pol; 
     int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0) broj_dana[1]++;
    if(godina_rodjenja < 1 || dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > broj_dana[mjesec_rodjenja - 1])
        throw logic_error ("Neispravni podaci"); 
    long long int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13; 
    c2=dan_rodjenja%10; 
    dan_rodjenja=dan_rodjenja/10; 
    c1=dan_rodjenja%10;
    
    c4=mjesec_rodjenja%10; 
    mjesec_rodjenja=mjesec_rodjenja/10; 
    c3=mjesec_rodjenja%10;  
    
    c7=godina_rodjenja%10;
    godina_rodjenja=godina_rodjenja/10; 
    c6=godina_rodjenja%10; 
    godina_rodjenja=godina_rodjenja/10; 
    c5=godina_rodjenja%10; 
    
    
    
    c9=sifra_regije%10; 
    sifra_regije=sifra_regije/10; 
    c8=sifra_regije%10; 
    
    A:
    if(pol==Musko){
        c12=m%10; 
        m=m/10; 
        c11=m%10; 
        m=m/10; 
        c10=m%10; 
        m++; 
    }
    else if(pol==Zensko){
        c12=z%10; 
        z=z/10; 
        c11=z%10; 
        z=z/10;
        c10=z%10;
        z++; 
    }
    c13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
    if(c13==11) c13=0; 
    if(c13==10)
        goto A;
    jmbg=c13+c12*10+c11*100+c10*1000+c9*10000+c8*100000+c7*1000000+c6*10000000+c5*100000000+c4*1000000000+c3*10000000000+c2*100000000000+c1*1000000000000;
    
}
string GradjaninBiH::DajImeIPrezime() const{
    return ime_i_prezime; 
}
long long int GradjaninBiH::DajJMBG() const{
    return jmbg; 
}
int GradjaninBiH::DajDanRodjenja() const{
    return dan_rodjenja; 
}
int GradjaninBiH::DajMjesecRodjenja() const{
    return mjesec_rodjenja;
}
int GradjaninBiH::DajGodinuRodjenja() const{
    return godina_rodjenja;
}
int GradjaninBiH::DajSifruRegije() const{
    return sifra_regije; 
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    return pol; 
}
void GradjaninBiH::PromijeniImeIPrezime(string novo_ime){
    ime_i_prezime=novo_ime; 
}
int main ()
{   
    GradjaninBiH* gradjani[100]; 
    int po_jmbg; 
    cout << "Koliko gradjana zelite unijeti po JMBG? "; 
    cin >> po_jmbg; 
    string ime_i_prezime; 
    GradjaninBiH *pocetak(nullptr), *prethodni; 
    long long int jmbg; 
    for(int i=0; i<po_jmbg; i++){
        
        cout << endl << "Unesite ime i prezime (u istom redu): ";
        cin.ignore(10000, '\n');
        getline(cin, ime_i_prezime); 
        cout << endl <<"Unesite JMBG: "; 
        cin >> jmbg; 
        try{
        gradjani[i]=new GradjaninBiH(ime_i_prezime,jmbg);
        cout << endl << "Unijeli ste gradjanina " << gradjani[i]->GradjaninBiH::DajImeIPrezime() << " rodjenog "; 
        cout << gradjani[i]->DajDanRodjenja() << "." << gradjani[i]->DajMjesecRodjenja() << "." << gradjani[i]->DajGodinuRodjenja() << " u regiji " << gradjani[i]->DajSifruRegije() << ", "; 
        if(gradjani[i]->DajPol()==0) cout << "musko.";
        else cout << "zensko.";
        
        }
        catch(logic_error poruka){
            cout << endl << poruka.what(); 
            i--; 
        }
    }
    string ime; 
    cout << endl; 
    int po_ostalom;
    char znak, znak1, znak2; 
    int sifra; 
    int dan, mjesec, godina;
    GradjaninBiH::Pol pol;
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "; 
    cin >> po_ostalom;
    
    cin.ignore(10000, '\n');
    for(int i=po_jmbg; i<po_ostalom+po_jmbg; i++){
        
            cout << endl << "Unesite ime i prezime (u istom redu): "; 
            
            getline(cin, ime); 
            cout << endl << "Unesite datum rodjenja (format dd/mm/gggg): "; 
            cin >> dan >> znak1 >> mjesec >> znak2>> godina; 
            cout << endl << "Unesite sifru regije: "; 
            cin >> sifra; 
            cout << endl << "Unesite M za musko, Z za zensko: "; 
            cin >> znak;
            if(znak=='M') pol=GradjaninBiH::Musko; 
            else if(znak=='Z') pol=GradjaninBiH::Zensko;
            
        cin.ignore(10000, '\n');
        try{
            gradjani[i]=new GradjaninBiH(ime,dan,mjesec,godina,sifra,pol);
            cout <<endl << "Unijeli ste gradjanina " << gradjani[i]->GradjaninBiH::DajImeIPrezime() << " JMBG: " << gradjani[i]->GradjaninBiH::DajJMBG() << ".";
        }
        catch(logic_error poruka){
            cout << endl <<  poruka.what(); 
            i--;
        }
    }
    for(int i=0; i<po_jmbg+po_ostalom; i++)
        delete gradjani[i]; 
    
	return 0;
}