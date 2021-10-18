//B 2016/2017, Zadaća 1, Zadatak 4

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

typedef std::vector<std::string> strvec;

std::string ObrniFraze (std::string ulaz, strvec fraze);
std::string IzmijeniUPigLatin (std::string ulaz, strvec fraze);
bool Nijeslovo(strvec fraze);

int main ()
{
    std::cout << "Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin, recenica);
    std::cout << "Unesite fraze: ";
    strvec fraze;

    while (true) {
        std::string fraza;
        std::getline(std::cin, fraza);
        if(fraza != "") //da ne ubacuje prazan među fraze i time poveća njihovu veličinu (problemi se javljaju kada se fraze ne unose standardno jer dole moram staviti fraze.size() > 1 uslov)
            fraze.push_back(fraza);
        //ako je u buferu samo znak za novi red prekini petlju
        if (std::cin.peek() == '\n')
            break;
    }
    
    try {
        auto ispis(IzmijeniUPigLatin(recenica, fraze));
        std::cout << "Recenica nakon PigLatin transformacije: " << ispis;
    } catch(std::domain_error izuzetak) {
        std::cout  << "Izuzetak: " << izuzetak.what();   //izuzetak
    }

    std::cout<< std::endl <<"Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);  //obrnuta rečenica

    return 0;
}

bool Nijeslovo(strvec fraze)
{
    for(int i = 0; i < fraze.size(); i++)
        for(int j = 0; j < fraze[i].length(); j++)  //ako naiđeš na nešto što nije slovo, vrati true zbog imena funkcije
            if(!((fraze[i][j] >= 'A' && fraze[i][j] <= 'Z') || (fraze[i][j] >= 'a' && fraze[i][j] <= 'z')))
                return true;

    return false;
}

std::string ObrniFraze (std::string ulaz, strvec fraze)
{
    int i(0);
    while(i < fraze.size()) {
        int p(0);
        while(p < ulaz.length()) {
            if(ulaz[p] != ' ') {                                //↓↓↓↓ Ušteda vremena, nema potrebe za promjenom ako je samo jedno slovo
                if(fraze[i] == ulaz.substr(p,fraze[i].length()) && fraze[i].length() != 1) {   //ako se fraza poklapa sa rijeci onda ju obrni
                    int q(fraze[i].length()-1);

                    //obrćemo riječi
                    while (q >= 0) {
                        ulaz[p] = fraze[i][q];
                        p++;
                        q--;

                        if (q == -1)
                            p-=2;
                    }
                }
            }
            p++;
        }
        i++;
    }
    return ulaz;
}

std::string IzmijeniUPigLatin (std::string ulaz, strvec fraze)
{
    if(Nijeslovo(fraze)) throw std::domain_error("Nekorektan izbor rijeci");

    if (fraze.size() > 0) {
        int p(0);

        while (p < ulaz.length()) {
            if((ulaz[p] >= 'A' && ulaz[p] <= 'Z') || (ulaz[p] >= 'a' && ulaz[p] <= 'z')) {
                int q(p);
                std::string pomoc(ulaz);
                while (q < ulaz.length() && ((ulaz[q] >= 'A' && ulaz[q] <= 'Z') || (ulaz[q] >= 'a' && ulaz[q] <= 'z'))) q++;

                for(int i = 0; i < fraze.size(); i++)
                    if(p < ulaz.length() && fraze[i] ==  pomoc.substr(p, fraze[i].length())  && q-p == fraze[i].length()) {

                        q--; //smanji counter za 1

                        //linija 104/105 uzrokuje opet komplikacije (dok neke riješi) ovo rješava te komplikacije
                        if (!((ulaz[q] >= 'A' && ulaz[q] <= 'Z') || (ulaz[q] >= 'a' && ulaz[q] <= 'z'))) q--;

                        //Nema potrebe da varijable temp živi duže od bloka ispod
                        {
                            std::string temp(1,ulaz[p]);//privremena varijabla sa prvim slovom riječi
                            temp += "ay";       //dodaj ay na nju
                            ulaz.insert(q+1, temp); //ubaci u rečenicu
                        }
                        ulaz.erase(p,1);


                while((ulaz[p] >= 'A' && ulaz[p] <= 'Z') || (ulaz[p] >= 'a' && ulaz[p] <= 'z')) p++; //kada izmjeniš preskoči ostatak
                    }
                    
                while((ulaz[p] >= 'A' && ulaz[p] <= 'Z') || (ulaz[p] >= 'a' && ulaz[p] <= 'z')) p++; //ako nisi odmah našao preskoči riječ, nema potrebe tražit podstring
            }
            p++;
        }

    }

    else {
        int p(0);
        while (p < ulaz.length()) {
            if((ulaz[p] >= 'A' && ulaz[p] <= 'Z') || (ulaz[p] >= 'a' && ulaz[p] <= 'z')) {
                int q(p);
                while (q < ulaz.length() && ((ulaz[q] >= 'A' && ulaz[q] <= 'Z') || (ulaz[q] >= 'a' && ulaz[q] <= 'z'))) q++;

                if(ulaz[q] != ' ')
                    q++;        //ako bude isao q do kraja stringa neće sve radit kako treba
                q--;    //biti će na razmaku pa vrati jedno mjesto

                //radi onog u 139/140 liniji ovo je potrebno za ispravku greške riječi na kraju stringa
                if (!((ulaz[q] >= 'A' && ulaz[q] <= 'Z') || (ulaz[q] >= 'a' && ulaz[q] <= 'z'))) q--;

                //Nema potrebe da varijabla temp živi duže od bloka ispod
                {
                    std::string temp(1,ulaz[p]);    //privremena varijabla sa prvim slovom riječi
                    temp += "ay"; //dodaj ay na nju
                    ulaz.insert(q+1, temp); //ubaci u rečenicu
                }

                ulaz.erase(p,1);//briši prvo slovo riječi

                //nakon izmjene riječi preskoči ostatak riječi
                while (p < ulaz.length() && ((ulaz[p] >= 'A' && ulaz[p] <= 'Z') || (ulaz[p] >= 'a' && ulaz[p] <= 'z')))
                    p++;
            }
            p++;
        }

    }

    return ulaz;
}