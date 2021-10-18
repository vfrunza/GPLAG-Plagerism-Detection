/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdexcept>

// rucno napraviti listu i prepisati elemente iz vektora u tu rucno kreiranu listu
// vektor ostaje -> pomocne fcije se mogu iskoristiti

// VRACA BROJ SLOVA U IMENU - korektna i za ovaj zadatak
int BrojSlovaImena (std::string ime_djeteta){
    int broj_slova_imena(0);
    for(int i=0; i<ime_djeteta.size(); i++){
        if( (ime_djeteta[i]>='a' && ime_djeteta[i]<='z') || (ime_djeteta[i]>='A' && ime_djeteta[i]<='Z') || (ime_djeteta[i]>='0' && ime_djeteta[i]<='9') ){
            broj_slova_imena++;
        }
    }
    return broj_slova_imena;
}

// VRACA BROJ TIMOVA I BROJ CLANOVA TIMA - korektna i za ovaj zadatak
std::vector<int> TimoviDjece (std::vector<std::string> imena_djece, int broj_timova){
    int broj_djece = imena_djece.size();
    int visak = broj_djece % broj_timova;
    int djeca_u_timu = broj_djece / broj_timova;
    std::vector<int> broj_djece_tima;
    for(int i=0; i<visak; i++){
        int tmp = djeca_u_timu + 1;
        broj_djece_tima.push_back(tmp);
    }
    for(int i=visak; i<broj_timova; i++){
        broj_djece_tima.push_back(djeca_u_timu);
    }
    return broj_djece_tima;
}

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

void displayNode(Dijete* list){
    if (list != NULL){
        Dijete* first = list->sljedeci;
        Dijete* cur = first;
        do{
            std::cout << "\n Your Data is : ";
            std::cout << cur->ime;
            cur = cur->sljedeci;
        }while(cur != first);
    }
}

// RAZVRSTAVNJE
std::vector<std::set<std::string>> Razvrstaj (std::vector<std::string> imena_djece, int broj_timova){
    if(broj_timova<1 || broj_timova > imena_djece.size() ){
        throw std::logic_error("Razvrstavanje nemoguce");
    } 
    
    // kreiranje vektora, koliko koji tim ima djece
    std::vector<int> broj_djece_tima = TimoviDjece(imena_djece, broj_timova); 
    
    // PREPISIVANJE iz VEKTORA u LISTU
    Dijete *pocetak = nullptr, *prethodni;
    for(int i=0; i<imena_djece.size(); i++){
        Dijete *novi = new Dijete();
        novi->ime = imena_djece[i];
        novi->sljedeci = pocetak;
        if(!pocetak){
            pocetak = novi;
        } else {
            prethodni->sljedeci = novi;
        }
        prethodni = novi;
    }
    
    // Ispis
    /* for(Dijete *p = pocetak; p != nullptr; p=p->sljedeci){
        std::cout << p->ime << std::endl;
    }*/
    
    Dijete *tmp = pocetak;
    
    for(int i=0; i<broj_timova; i++){
        std::set<std::string> tmp_imena;
        for(int j=0; j<broj_djece_tima[i]; j++){
            Dijete *prvi = tmp;
            int br_slova = BrojSlovaImena(*tmp);
            tmp_imena.insert(*tmp);
            
            /* Dijete* first = list->sljedeci;
            Dijete* cur = first;
            do{
                std::cout << "\n Your Data is : ";
                std::cout << cur->ime;
                cur = cur->sljedeci;
            }while(cur != first); */
            
            // brisanje
     

            for(int k=0; k<br_slova-1; k++){
                tmp = tmp->sljedeci;
            }
        }
        TIMOVI_DJECE.push_back(tmp_imena);
    }
    return TIMOVI_DJECE; 
} 


int main (){
    std::vector<std::string> imena_djece = {"Damir", "Ana", "Muhamed", "Marko", "Ivan", "Mirsad", "Nikolina", "Alen", "Jasmina", "Merima"};
    std::vector<std::string> djeca;
    
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.ignore(10000,'\n');
    
    std::cout << "Unesite imena djece: ";
    for(int i=0; i<broj_djece; i++){
        std::string tmp;
        std::getline(std::cin, tmp);
        djeca.push_back(tmp);
    }
    std::cout << std::endl;
    
    int broj_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    
    try {
        std::vector<std::set<std::string>> TIMOVI_DJECE = Razvrstaj(djeca, broj_timova);
        
        int brojac(1);
        for(int i=0; i<TIMOVI_DJECE.size(); i++){
            std::cout << "Tim " << brojac << ": ";
            for(auto itr=TIMOVI_DJECE[i].begin(); itr!=TIMOVI_DJECE[i].end(); ++itr){
                auto it_tmp = TIMOVI_DJECE[i].end();
                it_tmp--;
                if(it_tmp == itr){
                    std:: cout << *itr;
                    break;
                }
                std::cout << *itr << ", ";
            }
            brojac++;
            std::cout << std::endl;
        }
    } catch(std::logic_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    return 0;
}