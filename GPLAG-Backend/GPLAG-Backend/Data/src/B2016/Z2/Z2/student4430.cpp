// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
using namespace std; 
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo}; 
template <typename Tip>
auto IzdvojiDijagonale3D(Tip kont, SmjerKretanja smjer) -> typename remove_reference <decltype(kont[0])>::type{
    
    for(int i=0; i<kont.size()-1; i++){
        for(int j=0; j<kont[i].size()-1; j++){
            if(kont[i][j].size()!=kont[i+1][j+1].size()) throw domain_error ("Redovi nemaju isti broj elemenata"); 
        }
        if(kont[i].size()!=kont[i+1].size()) throw domain_error ("Plohe nemaju isti broj redova"); 
    }
    int duzina=0; 
    int duzina1=kont[0][0].size();                                  // duzine x, y, i z koje se unose sa tastature
    int duzina2=kont[0].size(); 
    int duzina3=kont.size();
    if(smjer==SmjerKretanja::NaprijedNazad) duzina=duzina3; 
    else if(smjer==SmjerKretanja::NazadNaprijed) duzina=duzina3; 
    else if(smjer==SmjerKretanja::GoreDolje) duzina=duzina2; 
    else if(smjer==SmjerKretanja::DoljeGore) duzina=duzina2; 
    else if(smjer==SmjerKretanja::DesnoLijevo) duzina=duzina1;            //određivanje duzine izlazne matrice u zavisnosti od smjera kretanja
    else if(smjer==SmjerKretanja::LijevoDesno) duzina=duzina1; 
    
    typename remove_reference<decltype(kont[0])>::type izlaz(duzina);   // matrica je tipa kao ono dvodimenzionalno u trodimenzionalnom
     
    
    if(smjer==SmjerKretanja::NaprijedNazad)             // popunjava mattricu u zavisnosti od smjera
        for(int i=0; i<duzina3; i++)
            for(int j=0; j<duzina2; j++)
                izlaz[i].push_back(kont[i][j][j]);
                
    else if(smjer==SmjerKretanja::NazadNaprijed)
        for(int i=0; i<duzina3; i++)
            for(int j=0; j<duzina2; j++)
             izlaz[i].push_back(kont[duzina3-1-i][j][duzina2-j]);
        
    else if(smjer==SmjerKretanja::GoreDolje)
        for(int i=0; i<duzina2; i++)
            for(int j=0; j<duzina3; j++)
                izlaz[i].push_back(kont[duzina3-1-j][i][j]); 

    else if(smjer==SmjerKretanja::DoljeGore)
        for(int i=0; i<duzina2; i++)
            for(int j=0; j<duzina3; j++)
                izlaz[i].push_back(kont[duzina3-1-j][duzina2-1-i][duzina1-1-j]);
    
    else if(smjer==SmjerKretanja::DesnoLijevo)
        for(int i=0; i<duzina1; i++)
            for(int j=0; j<duzina3; j++)
                izlaz[i].push_back(kont[j][j][duzina1-i-1]); 

    else if(smjer==SmjerKretanja::LijevoDesno)
        for(int i=0; i<duzina1; i++)
            for(int j=0; j<duzina3; j++)
                izlaz[i].push_back(kont[duzina3-1-j][j][i]);

    return izlaz; 
}

int main ()
{
    int x, y, z, broj; 
    cout << "Unesite dimenzije (x y z): "; 
    cin >> x >> y >> z; 
    if(x<0 || y<0 || z<0){
        cout << "Neispravne dimenzije kontejnera!"; 
        return 0; 
    }
    cout << "Unesite elemente kontejnera: "; 
    vector<deque<deque<int>>> kontejner(x); 
    for(int i=0; i<x; i++){
        kontejner[i].resize(y); 
        for(int j=0; j<y; j++){
            kontejner[i][j].resize(z); 
        }
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                cin >> broj; 
                kontejner[i][j][k]=broj; 
            }
        }
    }
    cout << endl; 
    cout << "Unesite smjer kretanja [0 - 5]: "; 
    int s; 
    cin >> s; 
    if(s<0 || s>5){
        cout << "Smjer kretanja nije ispravan!" << endl; 
        return 0; 
    }
    SmjerKretanja smjer;           
     if(s==0){
        smjer=SmjerKretanja::NaprijedNazad; 
        cout << "NaprijedNazad: " << endl;  
    }
    else if(s==1){
        smjer=SmjerKretanja::NazadNaprijed; 
        cout << "NazadNaprijed: " << endl; 
    }
    else if(s==2){
        smjer=SmjerKretanja::GoreDolje; 
        cout << "GoreDolje: " << endl; 
    }
    else if(s==3){
        smjer=SmjerKretanja::DoljeGore; 
        cout << "DoljeGore: " << endl; 
    }
    else if(s==4){
        smjer=SmjerKretanja::LijevoDesno; 
        cout << "LijevoDesno: " << endl; 
    }
    else if(s==5){
        smjer=SmjerKretanja::DesnoLijevo; 
        cout << "DesnoLijevo: " << endl; 
    }
    
    auto matrica=IzdvojiDijagonale3D(kontejner, smjer); 
    for(auto red:matrica){
        for(auto x:red){
            cout << setw(4) << x; 
        }
        cout << endl; 
    }
    
    
    
	return 0;
}