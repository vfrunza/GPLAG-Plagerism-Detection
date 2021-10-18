// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<vector>
#include<deque>
#include<stdexcept>
#include<type_traits>
#include<iomanip>
using namespace std;

enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

    //GENERICKA FUNKCIJA KOJA IZVLACI RAVAN BROJEVA IZ KONTEJNERA kont 
    //NJOJ PROSLIJEDITI GRANICE PO KOJIM CE VRTITI FOR PETLJE
    //IDEJA JE DA RADI NA OSNOVU TIH GRANICA KOJE OVISE O SMJERU KRETANJA

template <typename Kontejner> auto IzvuciRavan (Kontejner kont, SmjerKretanja smjer)
-> typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type Potkontejner;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type PotPotkontejner;
    //Pocetne skraceno napisane vrijednosti maximuma proslijedjenog kontejnera
    int kPoc(kont.size()), iPoc(kont.at(0).size()), jPoc(kont.at(0).at(0).size());
    Potkontejner ploha;
    //SAD DEFAULT VRIJEDNOSTI NA KOJE CE SE VRACATI kPoc, jPoc i iPoc
   
 
    for (int k{0}; kPoc != k; k++){
        //Formiranje pomocnog potpotkontejnera koji ce zapravo biti nekakav 1D niz neceg
        PotPotkontejner red_plohe;
        for(int i{0} ; iPoc != i; i++ ){
            for( int j{0}; jPoc != j; j++   ){
                //SAD SE PUNJENJE GRANA PO TOME DA LI TRAZIMO GLAVNU ILI SPOR DIJAG
                //TJ DA LI NAS kont KVADAR GLEDAMO SPRIJEDA ILI SAZADA
                //USLOVI ZA ELEMENTE DOBIVENI PREKO JEDNACINA RAVNI U 3D PROSTORU
                if((int)smjer==0 && i==j){
                    red_plohe.push_back(kont.at(k).at(i).at(j));
                } else if ((int)smjer==1 && i+j+1==jPoc){
                    red_plohe.push_back(kont.at(k).at(i).at(j));
                } else if ((int)smjer==2 && k+j+1==kPoc){
                    red_plohe.push_back(kont.at(k).at(i).at(j));
                } else if ((int)smjer==3 && 2*j==jPoc+2*k){
                    red_plohe.push_back(kont.at(k).at(i).at(j));
                } else if ((int)smjer==4 && k+i+1==kPoc){
                    red_plohe.push_back(kont.at(k).at(i).at(j));
                } else if ((int)smjer==5 && k==i){
                    red_plohe.push_back(kont.at(k).at(i).at(j));
                }
                
            }
            
           
        }
        //SAD RED FORMIRAN KRETANJEM KROZ i-j RAVAN PUSH BACKAMO U PLOHU
         ploha.push_back(red_plohe);
        
    }
    return ploha;
}

template <typename Kontejner>
//Vraca reverz po kolonama proslijedjene joj 2d matrice 
auto ReverzMatrica(Kontejner matrica) -> typename remove_reference<decltype(matrica)>::type{
   typedef typename remove_reference<decltype(matrica)>::type Matrica;
    Matrica pomocna{matrica};
    int horizontalna{ pomocna.at(0).size()};

    for(int i{0}; i<matrica.size(); i++) for(int j{0}; j<horizontalna; j++) pomocna.at(i).at(j)=matrica.at(i).at(matrica.at(0).size()-1-j);
    return pomocna;
}

template <typename Kontejner>
auto TransponovanaMatrica(Kontejner matrica)-> typename remove_reference<decltype(matrica)>::type{
    typedef typename remove_reference<decltype(matrica)>::type Matrica;
    typedef typename remove_reference<decltype(matrica.at(0))>::type red;
    Matrica t(matrica.at(0).size(), red(matrica.size()));
    int horizontalna{ t.at(0).size() }, vertikanla { t.size() };
    for(int i{vertikanla-1}; i>=0; i--) for (int j{horizontalna-1}; j>=0; j--) t.at(i).at(j)=matrica.at(j).at(i);
    return ReverzMatrica(t);
}

template <typename Kontejner>
//Vraca reverznu matricu po redovima
auto InverzMatrica(Kontejner matrica)-> typename remove_reference<decltype(matrica)>::type{
    typedef typename remove_reference<decltype(matrica)>::type Matrica;
    Matrica pomocna{matrica};
    int vertiklana{ pomocna.size() };
    for(int i{0}; i<vertiklana; i++){
        for(int j{0}; j<matrica.at(0).size(); j++) pomocna.at(i).at(j)=matrica.at(matrica.size()-1-i).at(j);
    }
    return pomocna;
}

template<typename TriDKontejner> auto IzdvojiDijagonale3D( TriDKontejner kont, SmjerKretanja smjer )
-> typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type Potkontejner;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type PotPotkontejner;
    
    Potkontejner ploha;
    
    //k JE INDEKS ZA PLOHE (NIVO 1)
    //i JE INDEKS ZA REDOVE UNUTAR PLOHA (NIVO 2)
    //j JE INDEKS ZA KOLONE UNUTAR REDOVA UNUTAR PLOHA (NIVO 3)
    //Za brojeve redova unutar ploha
    for(int k{0}; k<kont.size(); k++ ) if (kont.at(k).size()!=kont.at(0).size()) throw domain_error("Plohe nemaju isti broj redova");
    //Za brojeve elemenata u pojedinacnim redovima pojedinacnih ploha
    for( int k{0}; k<kont.size(); k++ ) 
        for ( int i{0}; i<kont.at(0).size(); i++ ) 
            if(kont.at(0).at(0).size() != kont.at(k).at(i).size()) 
                throw domain_error("Redovi nemaju isti broj elemenata");
    
    //FUNKCIJI IzvuciRavan PROSLIJEDJUJEMO KONTEJNER I DONJU I GORNJU GRANICU INDEKSA
    //PO KOJOJ CE DA VRATI PLOHU BROJEVA, NO PAZIMO I NA TO DA LI SE RADI O GLAVNOJ ILI SPOREDNOJ
    ploha=IzvuciRavan(kont,smjer);
    if((int)smjer==2 || (int)smjer==3 || (int)smjer==4 || (int)smjer==5){
        ploha=TransponovanaMatrica(ploha);
        if((int)smjer==3) ploha=InverzMatrica(ReverzMatrica(ploha));
    if((int)smjer==5 ) ploha=InverzMatrica(ploha);
    
    }
    if((int)smjer==1){
        Potkontejner pomocna{ploha};
        int vertikalna { pomocna.size() };
        for(int i{0}; i<vertikalna; i++){
            for(int j{0}; j<pomocna.at(0).size(); j++){
                pomocna.at(i).at(j)=ploha.at( ploha.size()-1-i ).at(j);
            }
        }
        return pomocna;
    } 
    if((int)smjer==3 || (int)smjer == 5){
        Potkontejner pomocna{ploha};
        for(int i{0}; i<pomocna.size(); i++){
            for(int j{0}; j<pomocna.at(0).size(); j++){
                pomocna.at(i).at(j)=ploha.at(i).at( ploha.at(0).size()-1-j );
            } 
        }
        return pomocna;
    }
    
    return ploha;
}


int main (){
    cout <<"Unesite dimenzije (x y z): ";
    int x,y,z;
    cin>>x>>y>>z;
    if(x<0 || y<0 || z<0){
        cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    vector<deque<deque<int>>> kvadar(x,deque<deque<int>>(y, deque<int>(z)));
    
    
    cout<<"Unesite elemente kontejnera: ";
    for(int k{0}; k<x; k++){
        
        for(int i{0}; i<y; i++){
            
            for(int j{0}; j<z; j++){
                int broj;
                cin>>broj;
                kvadar.at(k).at(i).at(j)=broj;
            }
            
        }
        
    }
    cout <<endl<< "Unesite smjer kretanja [0 - 5]: ";
    SmjerKretanja smjer;
    int broj_smjera_u_enum;
    cin>>broj_smjera_u_enum;
    smjer = SmjerKretanja(broj_smjera_u_enum);
    if(broj_smjera_u_enum<0 ||broj_smjera_u_enum>5){
        cout<<"Smjer kretanja nije ispravan!"<<endl;
        return 0;
    }
    //Sad formiramo plohu u mainu pozivom funkcije
    try{
    deque<deque<int>> plohaMain { IzdvojiDijagonale3D(kvadar, smjer) };
    switch((int)smjer){
        case 0:cout<<"NaprijedNazad: "; break;
        case 1:cout<<"NazadNaprijed: "; break;
        case 2:cout<<"GoreDolje: "; break;
        case 3:cout<<"DoljeGore: "; break;
        case 4:cout<<"LijevoDesno: "; break;
        case 5:cout<<"DesnoLijevo: "; break;
    }
        cout<<endl;
        for(auto red : plohaMain){
	    for(auto x : red) {
	         cout<<setw(4)<<x;
	    }
	    cout<<endl;
	    }
    }catch(domain_error e){
        cout<<"Izuzetak: "<<e.what();
        return 0;
    }
	
	return 0;
}