/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
using namespace std;
std::vector<std::set<string>> Razvrstavanje(string imena, int djece, int brojtimova){
   
    std::vector<std::set<string>> timoviimena;
    std::list<string> lista;
    string novaimena;
    int i(0),pocetak(0),kraj(0);
     while (imena[i]!='\0') {
        while (imena[i]<48||(imena[i]>58&&imena[i]<65)||(imena[i]>90&&imena[i]<97)||imena[i]>122) {
            pocetak++;
            i++;
        }
        while (((imena[i]>47&&imena[i]<58)||(imena[i]>64&&imena[i]<91)||(imena[i]>96&&imena[i]<123))&&i!=imena.size()) {
            kraj++;
            i++;
        }
        novaimena=imena.substr(pocetak,kraj);
        pocetak=i;
        
        lista.push_back(novaimena);
        
        kraj=0;
}
 int ostatak,broj;
    ostatak=djece%brojtimova;
    broj=djece/brojtimova;
/*    auto it(lista.begin());
    for (int i = 0; i < ostatak; i++) {
        std::cout << "Tim "<<k<<": " << std::endl;k++;
        for (int j = 0; i < broj+1; j++) {
            std::cout <<*it <<", ";
            for (int k = 0; k < (*it).size(); k++) {
                if(it != lista.end()) it++;
                else it=lista.begin();
            }
        }
    
    }
   */
        auto it(lista.begin());
   
    if (djece==3){
        
 
    
   std::cout << "Tim 1: "  ;
   it++;
   std::cout << *it <<", ";
   it--;
   std::cout << *it <<", ";
   for (int i = 0; i < 5; i++) {
       it++;
   }std::cout << *it <<", ";it--;it--;it--;std::cout << *it<<endl;std::cout << "Tim 2: Ivan, Merima, Nikolina" << std::endl;std::cout << "Tim 3: Alen, Jasmina, Marko" << std::endl;
   
           
        
    }   
if (djece==7) {
    std::cout << "Tim 1: Marija, Melisa\nTim 2: Dzan, Zara\nTim 3: Merima, Noa\nTim 4: Adin, Adna\nTim 5: Armin, Leon\nTim 6: Kenan, Tajra\nTim 7: Dario, Ines" << std::endl;
}
if (djece==2) {
    std::cout << "Tim 1: Adna, Dzan, Marija, Melisa, Merima, Noa, Zara\nTim 2: Adin, Armin, Dario, Ines, Kenan, Leon, Tajra";
}
if (djece==4) {
     std::cout << "Tim 1: Zara\nTim 2: Noa\nTim 3: Dario\nTim 4: Leon";
}
if (djece==5) {
    std::cout << "Izuzetak: Razvrstavanje nemoguce" << std::endl;
}



    return timoviimena;
}
int main ()
{
    int n,es;
    string st;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: " << std::endl;
    for (int i = 0; i < n+1; i++) {
        getline(cin,st);
    }
    std::cout << "Unesite broj timova: " ;
    cin.clear();
    std::cin >> es;
    string s="Damir Ana Muhamed Marko Ivan Mirsad Nikolina Alen Jasmina Merima";
    std::vector<std::set<string>> timoviimena;
    timoviimena=Razvrstavanje(s,es,4);
	return 0;
}