//B 2016/2017, Zadaća 1, Zadatak 4

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
typedef std::vector<string> Vektor;

string ObrniFraze (string s, Vektor v)
{
    for(int j = 0; j < v.size(); j++) {     //prolazim kroz elemente vektora(rijec ili fraza)
        bool nalazise(false);

        for(int i = 0; i < s.length(); i++) {  
            int index(i);

            for(int k = 0; k < v.at(j).length(); k++) {    //prolazim kroz znakove u rijeci ili frazi

                if(i + (v.at(j).length() - 1) > s.length()) break;  //rijec na kraju stringa kraca on rijeci u vekotu npr dan i danas

                if(s.at(index) == v.at(j).at(k)) {
                    nalazise = true;
                    index++;
                    continue;
                } else {
                    nalazise = false;
                    break;
                }
            }

            if(nalazise) {
                //obrtanje redoslijeda rijeci/fraze
                for(int m = i + (v.at(j).length() - 1), n = i; n < m; m--, n++) {
                    char temp = s.at(n);                                        
                    s.at(n) = s.at(m);
                    s.at(m) = temp;
                }
                //pomijerim i za jedno mjesto
                if(i + v.at(j).length() < s.length()) {
                    i += v.at(j).length();
                    nalazise = false;
                }
            }
        }
    }
    return s;
}

string IzmijeniUPigLatin (string s, Vektor v)
{
    //ukoliko je vekotor prazna pronalazim rijeci u stringu i mijenjam ih rediom u pig latin
    if(v.empty()) {
        bool razmak(true);
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == ' ')
                razmak = true;
            else if(razmak) {
                razmak = false;
                int kraj(i);
                while(kraj < s.length() && s.at(kraj) != ' ')
                    kraj++;

                char temp = s.at(i);
                int brojac(i);
                
                //zadnje slovo prebacijem na kraj rijeci
                for(int n = i + 1; n < kraj; n++) {
                    s.at(brojac) = s.at(n);
                    brojac++;
                }
                //dodajem ay na kraj    
                s.at(kraj - 1) = temp;
                s.insert(s.begin() + kraj, 'a');
                s.insert(s.begin() + kraj + 1, 'y');

                i = kraj + 1;
            }
        }
    } else {
        //bacanje izuzetka
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.at(i).length(); j++) {
                if(!((v.at(i).at(j) >= 'A' && v.at(i).at(j) <= 'Z') || (v.at(i).at(j) >= 'a' && v.at(i).at(j) <= 'z')))
                    throw std::domain_error("Nekorektan izbor rijeci");
            }
        }

        for(int j = 0; j < v.size(); j++) {
            bool nalazise(false);

            for(int i = 0; i < s.length(); i++) {
                int index(i);

                for(int k = 0; k < v.at(j).length(); k++) {

                    if(i + (v.at(j).length() - 1) > s.length()) break;
                    if(s.at(index) == v.at(j).at(k)) {
                        nalazise = true;
                        index++;
                        continue;
                    } else {
                        nalazise = false;
                        break;
                    }
                }
                //provjeravam da li je rijec (element vektora) podstring rijeci stringa
                if(i != 0 && s.at(i - 1) != ' ') 
                    nalazise = false;
                else if(index != s.length() && s.at(index) != ' ')
                    nalazise = false;
                    
                if(nalazise) {
        
                    char temp = s.at(i);
                    int brojac(i);

                    for(int n = i + 1; n < i + v.at(j).length(); n++) {
                        s.at(brojac) = s.at(n);
                        brojac++;
                    }

                    s.at(i + (v.at(j).length() - 1)) = temp;
                    s.insert(s.begin() + (i + v.at(j).length()), 'a');
                    s.insert(s.begin() + (i + v.at(j).length() + 1), 'y');

                    if(i + v.at(j).length() < s.length()) {
                        i += v.at(j).length();
                        nalazise = false;
                    }
                }
            }
        }
    }
    return s;
}

int main ()
{
    string s;
    cout << "Unesite recenicu: ";
    std::getline(cin, s);
    cout << "Unesite fraze: ";
    string p;
    Vektor v;

    for(;;) {
        std::getline(cin, p);
        v.push_back(p);
        if(cin.peek() == '\n') break;
    }

    try {
        string q = std::move(IzmijeniUPigLatin(s, v));
        cout << "Recenica nakon PigLatin transformacije: ";
        cout << q;
    } catch (std::domain_error izuzetak) {
        cout << "Izuzetak: " << izuzetak.what() << endl;
    }

    cout << endl << "Recenica nakon obrtanja fraza: ";
    string t = std::move(ObrniFraze(s, v));
    cout << t;

    return 0;
}