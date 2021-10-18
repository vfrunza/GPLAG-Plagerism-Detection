/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    //buduci da u postavci nije naglaseno da se primljeni string ne smije mijenjati(iako se ne prima referenca, pa ni ne utice na poslani string)
    //a u mapu treba spremati rijeci tako da su joj sva slova ustvari mala slova, ovom for-petljom vrsimo pretvorbu svih velikih slova u primljenom strinug u mala
    //da bi kasnije lakse manipulisali tim slovima tj. rijecima
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    for(int i=0; i<s.length(); i++){
        std::string rijec;
        int j(0);
        bool rijec_nadjena(false);
        int pozicija(i);
        //while-petlja kojom pronalazimo sve rijeci u primljenom stringu, vodeci racuna o tome sta predstavlja rijec(def. u postavci)
        while( i<s.length() && ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) ){
            rijec.push_back(s[i]);
            j++;
            rijec_nadjena=true;
            i++;
        }
        if(rijec_nadjena){
            //ako se trenutna rijec ne nalazi u mapi potrebno ju je dodati u kljucno polje, a zatim u skup dodati poziciju rijeci
            if(!mapa.count(rijec)){
                mapa[rijec];
                auto it(mapa.find(rijec));
                it->second.insert(pozicija);
            }
            //ako se trenutna rijec vec nalazi u mapi, potrebno je pridruzenoj vrijednosti(skupu) dodijeliti poziciju na kojoj je sada pronadjena 
            else{
                auto it(mapa.find(rijec));
                it->second.insert(pozicija);
            }
        }
        
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std:: string s, std::map<std:: string, std::set<int>> mapa){
    std::set<int> skup;
    //pretrazujemo da li se trazena rijec nalazi u mapi
    auto it(mapa.find(s));
    //ukoliko se ne nalazi, bacanje izuzetka
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    //ukoliko se nalazi, rangovskom for-petljom pristupamo clanovima skupa pozicija i dodjeljujemo skupu koji se vraca iz funkcije
    else{
        for(int x: it->second) skup.insert(x);
    }
    return skup;
}
void IspisiIndeksPojmova(std::map<std:: string, std::set<int>> mapa){
    //for-petlja kojom se odgovarajucim iteratorom krecemo kroz mapu i ispisujemo potrebne podatke
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
        //for-petljom kojom se iteratorom na skup intova krecemo kroz pridruzeno vrijednost mape(tj skup ciji su elemenit tipa int)
        //i ispisujemo elemente skupa, vodeci racuna o tome kada treba ispisati ","
        for(auto it1=it->second.begin(); it1!=it->second.end(); it1++){
            if(it1==--it->second.end()) std::cout<<*it1;
            else std::cout<<*it1<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{   std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    std::set<int> skup;
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        bool izuzetak(false);
        try{
            skup=(PretraziIndeksPojmova(rijec,mapa));
        }
        catch(...){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            izuzetak=true;
        }
        if(!izuzetak){
            for(int x: skup) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
    }
	return 0;
}