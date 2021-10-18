/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

bool slovo(char a) {
    if( (a>='a' && a<='z') || (a>='A'&&a<='Z'))
    return true;
    return false;
}

bool broj (char a) {
    
    if(a>='0' && a<='9')
    return true;
    return false;
}


bool legalnoime(std::string ime) {
    
    for(int i=0;i<ime.size();i++) {
        if(!slovo(ime[i]) && !broj(ime[i]) && slovo[i]!=' ' &&slovo[i]!='-' && slovo[i]!=39)
        return false;
    }
    return true;
}







class Datum{
    int dan, mjesec, godina;
    
    
Datum(int dan, int mjesec, int godina) {
    
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

void Postavi(int dan, int mjesec, int godina) {
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

int DajDan() const {return dan;}
int DajMjesec() const {return mjesec;}
int DajGodinu() const {return godina;}
void Ispisi() const{
    
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;

}

};



class Kupac {
    
    std::string imeiprezime;
    Datum datumrodjenja;
    
Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    
    if(legalnoime(ime_i_prezime)==false)
    throw std::domain_error("Neispravno ime i prezime");
    
    if(datum_rodjenja.dan<=0 ||datum_rodjenja.dan>31 || datum_rodjenja.mjesec<0 || datum_rodjenja.mjesec>12 || datum_rodjenja.godina<0)
    throw std::domain_error("Neispravan datum");
    
    imeiprezime=ime_i_prezime;
    datumrodjenja=datum_rodjenja;
    

}

void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    
    
    
    if(legalnoime(ime_i_prezime)==false)
    throw std::domain_error("Neispravno ime i prezime");
    
    if(datum_rodjenja.dan<=0 ||datum_rodjenja.dan>31 || datum_rodjenja.mjesec<0 || datum_rodjenja.mjesec>12 || datum_rodjenja.godina<0)
    throw std::domain_error("Neispravan datum");
    
    imeiprezime=ime_i_prezime;
    datumrodjenja=datum_rodjenja;
 
 
}


std::string DajImePrezime() const {return imeiprezime;}
Datum DajDatumRodjenja() const {return datumrodjenja;}

void Ispisi() const {
    std::cout<<imeiprezime<<"("<<datumrodjenja.dan<<"/"<<datumrodjenja.mjesec<<"/"<<datumrodjenja.godina<<")";
}


};










int main ()
{
	return 0;
}