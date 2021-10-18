#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <vector>

// pomocna funkcija provjerava da li je karakter slovo
int JeLiSlovo (char s) {
    if ((s>='A' and s<='Z') or (s>='a' and s<='z')) return 1;
    return 0;
}

// pomocna funkcija pravi palindrom od proslijedjene rijeci
std::string ObrnutiString (std::string string) {
    std::string stringara;
    for (int i=0; i<string.length(); i++){
        stringara.push_back(string.at(string.length()-i-1));
        if (i==string.length()-1) break; // zastita od prekoracenja
    }
    stringara=string+stringara;
    return stringara;
}

// pomocna funkcija pravi polupalindrom od proslijedjene rijeci
std::string LudovicObraniak (std::string string) {
    std::string stringara;
    for (int i=0; i<string.length(); i++) {
        string.at(string.length()-1-i)=string.at(i);
        if (i==string.length()-1) break; // zastita od prekoracenja
    }
    stringara=string;
    return stringara;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> niz) {
    std::string dio;
    if (niz.size()==0) {
        return recenica;
    }
    for (int l=0; l<niz.size(); l++) {
        for (int i=0; i<recenica.length(); i++) {
            int znak(1);
            if (niz.at(l).at(0)==recenica.at(i)) { // nalazimo prvo slovo fraze u recenici
                if (i!=0) { // slucaj kada to nije prvo slovo u recenici
                    if (i+niz.at(l).length()<recenica.length()) {
                        if (JeLiSlovo(recenica.at(i-1))==0 and JeLiSlovo(recenica.at(i+niz.at(l).length()))==0) { // ako je "neslovo" i ispred i iza
                            int k=i, brojac(0);
                            for (int e=0; e<niz.at(l).length(); e++) {
                                if (niz.at(l).at(e)!=recenica.at(k)) {
                                    znak=0;
                                    break;
                                }
                                brojac++;
                                if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                    znak=0;
                                    break;
                                }
                                k++;
                                if (e==niz.at(l).length()-1) break;
                            }
                            if (znak==1 and brojac>=0) {
                                dio=niz.at(l);
                                int fix=i;
                                for (int e=0; e<niz.at(l).length(); e++) {
                                    recenica.erase(recenica.begin()+fix);
                                    if (e==niz.at(l).length()-1) break;
                                }
                                dio=ObrnutiString(dio);
                                int e=i;
                                recenica.insert(e, dio);
                            }
                        }
                    }
                    if (i+niz.at(l).length()==recenica.length() and JeLiSlovo(recenica.at(i-1))==0) { // slucaj kad je zadnje slovo kraj recenice
                        int k=i, brojac(0);
                        for (int e=0; e<niz.at(l).length(); e++) {
                            if (niz.at(l).at(e)!=recenica.at(k)) {
                                znak=0;
                                break;
                            }
                            brojac++;
                            if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                znak=0;
                                break;
                            }
                            k++;
                            if (e==niz.at(l).length()-1) break;
                        }
                        if (znak==1 and brojac>=0) {
                            dio=niz.at(l);
                            int fix=i;
                            for (int e=0; e<niz.at(l).length(); e++) {
                                recenica.erase(recenica.begin()+fix);
                                if (e==niz.at(l).length()-1) break;
                            }
                            dio=ObrnutiString(dio);
                            int e=i;
                            recenica.insert(e, dio);
                        }
                    }
                }
                if (i==0) { // slucaj kada je prvo slovo fraze ujedno i prvo slovo u recenici
                    if (i+niz.at(l).length()>recenica.length()) continue;
                    else if (i+niz.at(l).length()!=recenica.length()) {
                        if (JeLiSlovo(recenica.at(i+niz.at(l).length()))==0) {
                            int k=i, brojac(0);
                            for (int e=0; e<niz.at(l).length(); e++) {
                                if (niz.at(l).at(e)!=recenica.at(k)) {
                                    znak=0;
                                    break;
                                }
                                brojac++;
                                if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                    znak=0;
                                    break;
                                }
                                k++;
                                if (e==niz.at(l).length()-1) break;
                            }
                            if (znak==1 and brojac>=0) {
                                dio=niz.at(l);
                                int fix=i;
                                for (int e=0; e<niz.at(l).length(); e++) {
                                    recenica.erase(recenica.begin()+fix);
                                    if (e==niz.at(l).length()-1) break;
                                }
                                dio=ObrnutiString(dio);
                                int e=i;
                                recenica.insert(e, dio);
                            }
                        }
                    }
                    else if (i+niz.at(l).length()==recenica.length()) { // ako je duzina recenice jednaka duzini fraze
                        int k=i, brojac(0);
                        for (int e=0; e<niz.at(l).length(); e++) {
                            if (niz.at(l).at(e)!=recenica.at(k)) {
                                znak=0;
                                break;
                            }
                            brojac++;
                            if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                znak=0;
                                break;
                            }
                            k++;
                            if (e==niz.at(l).length()-1) break;
                        }
                        if (znak==1 and brojac>=0) {
                            dio=niz.at(l);
                            int fix=i;
                            for (int e=0; e<niz.at(l).length(); e++) {
                                recenica.erase(recenica.begin()+fix);
                                if (e==niz.at(l).length()-1) break;
                            }
                        }
                        dio=ObrnutiString(dio);
                        int e=i;
                        recenica.insert(e, dio);
                    }
                }
            }
            if (i==recenica.length()-1) break;
        }
        if (l==niz.size()-1) break;
    }
    return recenica;
}

// naredbe u funkciji slicne naredbama iz prethodne, sa razlikom sto se poziva druga pomocna funkcija
std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> niz) {
    std::string dio;
    if (niz.size()==0) {
        return recenica;
    }
    for (int l=0; l<niz.size(); l++) {    
        for (int i=0; i<recenica.length(); i++) {
            int znak(1);
            if (niz.at(l).at(0)==recenica.at(i)) {
                if (i!=0) {
                    if (i+niz.at(l).length()<recenica.length()) {
                        if (JeLiSlovo(recenica.at(i-1))==0 and JeLiSlovo(recenica.at(i+niz.at(l).length()))==0) {
                            int brojac(0), k=i;
                            for (int e=0; e<niz.at(l).length(); e++) {
                                if (niz.at(l).at(e)!=recenica.at(k)) {
                                    znak=0;
                                    break;
                                }
                                brojac++;
                                if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                    znak=0;
                                    break;
                                }
                                k++;
                                if (e==niz.at(l).length()-1) break;
                            }
                            if (znak==1 and brojac>=0) {
                                dio=niz.at(l);
                                int fix=i;
                                for (int e=0; e<niz.at(l).length(); e++) {
                                    recenica.erase(recenica.begin()+fix);
                                    if (e==niz.at(l).length()-1) break;
                                }
                                dio=LudovicObraniak(dio);
                                int e=i;
                                recenica.insert(e, dio);
                            }
                        }
                    }
                    if (i+niz.at(l).length()==recenica.length() and JeLiSlovo(recenica.at(i-1))==0) {
                        int brojac(0), k=i;
                        for (int e=0; e<niz.at(l).length(); e++) {
                            if (niz.at(l).at(e)!=recenica.at(k)) {
                                znak=0;
                                break;
                            }
                            brojac++;
                            if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                znak=0;
                                break;
                            }
                            k++;
                            if (e==niz.at(l).length()-1) break;
                        }
                        if (znak==1 and brojac>=0) {
                            dio=niz.at(l);
                            int fix=i;
                            for (int e=0; e<niz.at(l).length(); e++) {
                                recenica.erase(recenica.begin()+fix);
                                if (e==niz.at(l).length()-1) break;
                            }
                            dio=LudovicObraniak(dio);
                            int e=i;
                            recenica.insert(e, dio);
                        }
                    }
                }
                if (i==0) {
                    if (i+niz.at(l).length()>recenica.length()) continue;
                    else if (i+niz.at(l).length()!=recenica.length()) {
                        if (JeLiSlovo(recenica.at(i+niz.at(l).length()))==0) {
                            int brojac(0), k=i;
                            for (int e=0; e<niz.at(l).length(); e++) {
                                if (niz.at(l).at(e)!=recenica.at(k)) {
                                    znak=0;
                                    break;
                                }
                                brojac++;
                                if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                    znak=0;
                                    break;
                                }
                                k++;
                                if (e==niz.at(l).length()-1) break;
                            }
                            if (znak==1 and brojac>=0) {
                                dio=niz.at(l);
                                int fix=i;
                                for (int e=0; e<niz.at(l).length(); e++) {
                                    recenica.erase(recenica.begin()+fix);
                                    if (e==niz.at(l).length()-1) break;
                                }
                                dio=LudovicObraniak(dio);
                                int e=i;
                                recenica.insert(e, dio);
                            }
                        }
                    }
                    else if (i+niz.at(l).length()==recenica.length()) {
                        int brojac(0), k=i;
                        for (int e=0; e<niz.at(l).length(); e++) {
                            if (niz.at(l).at(e)!=recenica.at(k)) {
                                znak=0;
                                break;
                            }
                            brojac++;
                            if (k==(recenica.length()-1) and e!=(niz.at(l).length())-1) {
                                znak=0;
                                break;
                            }
                            k++;
                            if (e==niz.at(l).length()-1) break;
                        }
                        if (znak==1 and brojac>=0) {
                            dio=niz.at(l);
                            int fix=i;
                            for (int e=0; e<niz.at(l).length(); e++) {
                                recenica.erase(recenica.begin()+fix);
                                if (e==niz.at(l).length()-1) break;
                            }
                            dio=LudovicObraniak(dio);
                            int e=i;
                            recenica.insert(e, dio);
                        }
                    }
                }
            }
            if (i==recenica.length()-1) break;
        }  
        if (l==niz.size()-1) break;
    }
    return recenica;
}

int main ()
{
    std::string tekst;
    std::string fraza;
    std::vector<std::string> niz;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, tekst);
    std::cout << "Unesite fraze: ";
    do {
        std::getline(std::cin, fraza);
        if (!fraza.length()) break;
        niz.push_back(fraza);
    } while (1);
    std::cout << "Recenica nakon Palindrom transformacije: ";
    std::string recenica=NapraviPalindrom(tekst, niz);
    std::cout << recenica;
    std::cout << "\nRecenica nakon PoluPalindrom transformacije: ";
    recenica=NapraviPoluPalindrom(tekst, niz);
    std::cout << recenica;
	return 0;
}