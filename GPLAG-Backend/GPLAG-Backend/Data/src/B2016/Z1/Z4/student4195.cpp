#include<iostream>
#include<string>
#include <vector>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef std::vector<std::string> Vektor;

string ObrniRijec(string &ulazni, int pocetni, int duzina)  //Obrtanje rijeci - algoritam
{
    int krajnji=duzina+pocetni;
    int brojac(0);
    for(int i=pocetni; i<(krajnji+pocetni)/2; i++) {
        char pomocna=ulazni.at(i);
        ulazni.at(i)=ulazni.at(krajnji-1-brojac);
        ulazni.at(krajnji-1-brojac) = pomocna;
        brojac++;
    }
    return ulazni;
}

string ObrniFraze(string ulazni, Vektor fraze)  //Funkcija koja obrce sve fraze pozivajuci prethodnu
{
    for(int i=0; i<fraze.size(); i++) {
        int duzina=fraze.at(i).length();
        for(int j=0; j<=int(ulazni.length()-duzina); j++) {
            if(fraze.at(i)==ulazni.substr(j,duzina))
                ObrniRijec(ulazni,j,duzina);
        }
    }
    return ulazni;
}

bool JesteSlovo(char karakter)  //Provjera je li karakter slovo ( da ne pisem kroz cijelu funkciju )
{
    if(karakter<'A' or (karakter>'Z' and karakter<'a') or karakter>'z')
        return false;
    return true;
}


bool IspravnaRijec(string rijec)  //Provjera je li rijec sastavljena samo od slova engleskog alfabeta
{
    for(int i=0; i<rijec.length(); i++) {
        if(!JesteSlovo(rijec.at(i)))  return false;
    }
    return true;
}


void PigSifrovanje(string &ulazna,int pocetak, int duzina)
{

    ulazna.insert(ulazna.begin()+pocetak+duzina,ulazna.at(pocetak));
    ulazna.insert(ulazna.begin()+pocetak+duzina+1,'a');
    ulazna.insert(ulazna.begin()+pocetak+duzina+2,'y');
    ulazna.erase(ulazna.begin()+pocetak);
}

void IzmijeniSvePig(string &ulazni)  //U slucaju 0 fraza
{
    int i(0),j;
    while(i<ulazni.length()) {
        for(;i<ulazni.length(); i++) { //Ova petlja trazi prvo slovo, tj. pocetak rijeci
            if(JesteSlovo(ulazni.at(i))){
                break;
            }
        }
        for(j=i; j<ulazni.length(); j++){ //Ova trazi neslovo tj. kraj rijeci
            if(!JesteSlovo(ulazni.at(j))){
                break;
            }
        }
        if(i!=ulazni.length())
            PigSifrovanje(ulazni,i,j-i); //Duzina je kraj rijeci - pocetak, pocetak = i, kraj je j-1
        i=j+2;
    }
}

string IzmijeniUPigLatin(string ulazni, Vektor fraze) //Trazena funkcija PIGLATIN
{
    if(!fraze.size())
        IzmijeniSvePig(ulazni);
    for(int i=0; i<fraze.size(); i++) {
        if(!IspravnaRijec(fraze.at(i))) throw std::domain_error("Nekorektan izbor rijeci");
        int duzina=fraze.at(i).length();
        for(int j=0; j<=int(ulazni.length()-duzina); j++) {
            if(fraze.at(i)==ulazni.substr(j,duzina)) {
                bool poklapa_se_rijec(true);
                if(j+duzina!=ulazni.length()) { //Sigurna provjera karaktera nakon substringa
                    if(JesteSlovo(ulazni.at(j+duzina))) poklapa_se_rijec=false;
                }
                if(j!=0) { //Sigurna provjera karaktera prije pocetka substringa
                    if(JesteSlovo(ulazni.at(j-1))) poklapa_se_rijec=false;
                }
                if(poklapa_se_rijec)
                    PigSifrovanje(ulazni,j,duzina);
            }
        }
    }
    return ulazni;
}

int main ()
{
    string ulazna_recenica;
    cout<<"Unesite recenicu: ";
    getline(cin,ulazna_recenica);
    Vektor fraze;
    int brojac(0);
    cout<<"Unesite fraze: ";
    do {
        string s;
        getline(cin,s);
        if(s.length()==0)
            brojac++;
        if(s.length()>0){
            fraze.push_back(s);
            brojac=0;
        }
    } while(brojac!=1);
    string obrnuta_recenica(ObrniFraze(ulazna_recenica,fraze));
    try {
        string pig_latin(IzmijeniUPigLatin(ulazna_recenica,fraze));
        cout<<"Recenica nakon PigLatin transformacije: "<<pig_latin<<endl;
    } catch(std::domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what()<<endl;
    }
    cout<<"Recenica nakon obrtanja fraza: "<<obrnuta_recenica<<endl;
    return 0;
}
