#include <iostream>
#include <string>
#include <vector>


int wordcounter (std::string fraza)
{
    //Prebroji koliko rijeci ima u frazi
    int brojac(1);
    for (int i(0) ; i<fraza.size(); i++ ) {
        if (fraza.at(i)==' ') brojac++;
    }
    return brojac;
}


bool DuzinaCheck (std::string zaP)
{
    //Provjera duzine rijeci u recenici
    //Ukoliko je fraza korijen jedne rijeci u recenici, ova funkcija vrsi provjeru i sprjecava ispis
    for (int i=0; i<zaP.size(); i++) {
        if (zaP.at(zaP.size()-1)!=' ') {
            return 1;
        }
    }
    return 0;
}


std::vector<std::string> Proveravac ( std::string recenica,std::vector<std::string> fraze)
{
    //Ova funkcija uklanja fraze koje se ne nalaze u recenici
    std::vector<std::string> rijeci;
    std::string r;
    int k(0),max(1);
    //Prebroji broj rijeci u frazi
    for (int f(0) ; f<fraze.size(); f++ ) {
        if (max<wordcounter(fraze.at(f)))
            max=wordcounter(fraze.at(f));
    }
    while (recenica[k]==' ') k++;

    int global(k);
    //Pronalazi rijeci iz recenice
    for ( int i(global); i<recenica.size(); i++) {
        for (int j(i); j<recenica.size(); j++) {
            if (recenica[j]==' ' || j==recenica.size()-1) {
                int sizee(j-i);
                sizee=j-i;
                if (j==recenica.size()-1) sizee++;
                r= recenica.substr(i, sizee);
                rijeci.push_back(r);
                r.clear();
                if (j==recenica.size()-1) {
                    i=j;
                    break;
                }
                while (recenica[j]==' ') j++;
                i=j-1;
                break;
            }

        }

    }
    //Vrsi eliminaciju fraza koje nisu u recenici
    int temp(0);
    std::vector<std::string> zavrsni;
    for (int i(0); i<rijeci.size() ; i++) {
        for (int j(0); j<fraze.size() ; j++) {
            if (rijeci.at(i)== fraze.at(j)) {
                if (zavrsni.size()>=1) {
                    for (int k(0); k<zavrsni.size(); k++)  {
                        if (fraze.at(j)==zavrsni.at(k)) {
                            temp=1;
                        }
                    }
                }
                if (temp==0) {
                    zavrsni.push_back(fraze.at(j));
                }
                temp=0;
                break;
            } else if (wordcounter(fraze.at(j))>1) {
                zavrsni.push_back(fraze.at(j));
            }
        }

    }
    return zavrsni;
}


bool Provjera (char x)
{
    if ((x>='a' && x<='z') || (x>='A' && x<='Z') ) return true;

    return false;
}


std::string PalindromeCreator (std::string a)
{
    //Kreiraj palindrom
    std::string b;
    for (int i(a.size()-1); i>=0 ; i--) {
        b.push_back(a.at(i));
    }
    a=b;
    return a;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze)
{
    std::string checker;
    std::string pS;
    std::vector <std::string> ProcisceneFraze= Proveravac (recenica, fraze);
    int fV= ProcisceneFraze.size(), rV=recenica.size();
    recenica.push_back(' ');
    recenica.resize(recenica.size()+10000);

    for (int i(0); i<fV; i++) {
        int fixed=ProcisceneFraze.at(i).size();
        for (int j(0) ; j<rV; j++) {

            // recenica.resize(recenica.size()+fixed +1);
            pS= recenica.substr (j, fixed );
            checker= recenica.substr (j, ProcisceneFraze.at(i).size()+1 );
            if (pS== ProcisceneFraze.at(i) )  {
                int krajnik=j+fixed;

                if ((wordcounter(ProcisceneFraze.at(i))==1 && DuzinaCheck(checker))) continue;
                if (wordcounter(ProcisceneFraze.at(i))>1 && ( Provjera (recenica.at(j+fixed)) || Provjera (recenica.at(j-1)))  ) continue;
                if (j>0) {
                    if (wordcounter(ProcisceneFraze.at(i))==1 &&  Provjera (recenica.at(j-1))  )  continue;
                }
                if (wordcounter(ProcisceneFraze.at(i))==1 && j==recenica.size()-fixed) continue;
                j= j+ pS.size()-1; //pozicioniranje na kraj rijeci, tako se moze isjeci
                rV+=j; //povecanje velicine recenice zbog petlje
                std::string str1= recenica.substr (0, j+1); //odsjeci prvi dio recenice
                int ost= recenica.size()-j; //velicina ostatka recenice
                std::string str2= recenica.substr (j+1, ost); //odsjeci ostatak recenice
                recenica=str1 + PalindromeCreator(ProcisceneFraze.at(i)) + str2; //umetni palindrom
            }
        }

    }
    //Postavi velicinu stringa, na velicinu recenice
    int brojac(0);
    for (int k(0) ; k<recenica.length() ; k++) {
        if (recenica.at(k)>=' ' && recenica.at(k)<='~' ) brojac++;
    }
    recenica.resize(brojac);
    return recenica;
}
int parNepar (std::string a)
{
    //Provjeri da li je velicina rijeci parna ili neparna
    if (a.size()%2==0) {
        return (a.size()/2);
    } else {
        return ((a.size()/2)+1);
    }
}
std::string PoluPalindrom (std::string a )
{
    //Kreiraj polupalindrom
    std::string b;
    for (int i((a.size()/2)-1); i>=0 ; i--) {
        b.push_back(a.at(i));
    }
    a=b;
    return a;
}
std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze)
{
    std::string checker;
    std::string pS;
    std::vector <std::string> ProcisceneFraze= Proveravac (recenica, fraze);
    int fV= ProcisceneFraze.size(), rV=recenica.size();
    recenica.push_back(' ');
    recenica.resize(recenica.size()+10000);

    for (int i(0); i<fV; i++) {
        int fixed=ProcisceneFraze.at(i).size();
        for (int j(0) ; j<rV; j++) {
            pS= recenica.substr (j, fixed );
            checker= recenica.substr (j, ProcisceneFraze.at(i).size()+1 );
            if (pS== ProcisceneFraze.at(i) )  {
                if ((wordcounter(ProcisceneFraze.at(i))==1 && DuzinaCheck(checker))) continue;
                if (wordcounter(ProcisceneFraze.at(i))>1 && ( Provjera (recenica.at(j+fixed)) || Provjera (recenica.at(j-1)))  ) break;
                if (j>0) {
                    if (wordcounter(ProcisceneFraze.at(i))==1 && (Provjera (recenica.at(j-1)) ||  j==recenica.size()-1) )  continue;
                }
                //Isjecak radi na slicnom principu kao i kod funkcije PraviPalindrom
                j= j+ pS.size()-1-((ProcisceneFraze.at(i).size())/2); 
                rV+=j; 
                std::string str1= recenica.substr (0, j+1); 
                int ost= recenica.size()-j; 
                std::string str2= recenica.substr (j+((ProcisceneFraze.at(i).size())/2)+1, ost); 
                recenica=str1 + PoluPalindrom(ProcisceneFraze.at(i)) + str2; 
            }

        }

    }
    //Postavi velicinu stringa, na velicinu recenice
    int brojac(0);
    for (int k(0) ; k<recenica.length() ; k++) {
        if (recenica.at(k)>=' ' && recenica.at(k)<='~' ) brojac++;
    }
    recenica.resize(brojac);
    return recenica;
}


int main ()
{
    std::string rec;
    std::vector <std::string> fraze;
    std::string pUnos;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,rec);
    std::cout<<"Unesite fraze: ";
     int i(0);

    while (1) {
        std::getline(std::cin,pUnos);
        fraze.push_back(pUnos);
        if (fraze.at(i).size()==0) break;
        i++; 
    }
    std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(rec,fraze)<<std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: " <<NapraviPoluPalindrom(rec,fraze)<<std::endl;
    
    return 0;
}
