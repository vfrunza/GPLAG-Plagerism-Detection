// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<vector>
#include<deque>
#include<iomanip>
#include<stdexcept>
#include<type_traits>
using namespace std;
enum class SmjerKretanja{NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename tipkont> auto IzdvojiDijagonale3D(tipkont kont,SmjerKretanja s) -> typename remove_reference<decltype(kont.at(0))>::type{
    for(int i=0; i<kont.size(); i++) if(kont.at(0).size()!=kont.at(i).size()){
        throw domain_error("Plohe nemaju isti broj redova");
    } 
    for(int i=0; i<kont.size(); i++)
        for(int j=0; j<kont.at(i).size(); j++){
            
            if(kont.at(0).at(0).size() != kont.at(i).at(j).size() ) {
                throw domain_error("Redovi nemaju isti broj elemenata.");
            }
        }
    
    typename remove_reference<decltype(kont.at(0))>::type mat;
    for(int i=0; i<kont.size();i++ ){
        typename remove_reference<decltype(kont.at(0).at(0))>::type r;
        for(int j=0; j<kont.at(0).size();j++){
            for(int k=0; k<kont.at(0).at(0).size(); k++) {
if ((s==SmjerKretanja::NaprijedNazad && j==k)||(s==SmjerKretanja::NazadNaprijed && j+k+1==kont.at(0).at(0).size())||(s==SmjerKretanja::GoreDolje && i+k+1==kont.size() )||(s==SmjerKretanja::DoljeGore && 2*k-2*i==kont.at(0).at(0).size())||(s==SmjerKretanja::LijevoDesno && i+1+j==kont.size())||(s==SmjerKretanja::DesnoLijevo && i==j)){
    r.push_back(kont.at(i).at(j).at(k));
} 
       
            }
            
        }
        mat.push_back(r); 
        
    }
    if(s==SmjerKretanja::NazadNaprijed){
        typename remove_reference<decltype(kont.at(0))>::type Rmat;
        for(int i=mat.size()-1; i>-1; i--){
            Rmat.push_back(mat.at(i));
        }
        return Rmat;
        
    }
    if(s==SmjerKretanja::GoreDolje){
        typename remove_reference<decltype(kont.at(0))>::type Rmat;
        
        for(int i=0; i<mat.at(0).size(); i++){ typename remove_reference<decltype(kont.at(0).at(0))>::type redov;
            for(int j=0; j<mat.size(); j++){
                redov.push_back(   mat.at(mat.size()-1-j).at(i)  );
            }
            Rmat.push_back(redov);
        }
        return Rmat;
    }
    if(s==SmjerKretanja::DoljeGore){typename remove_reference<decltype(kont.at(0))>::type Rmat;
        for(int i=0; i<mat.at(0).size(); i++){ typename remove_reference<decltype(kont.at(0).at(0))>::type redov;
            for(int j=0; j<mat.size(); j++){
                redov.push_back( mat.at(j).at(mat.at(0).size()-1-i) );
            }
            Rmat.push_back(redov);
        }
       for(int i=0; i<Rmat.size(); i++)
        {
            for(int j=0; j<Rmat.at(0).size()/2; j++) {
                auto pom=Rmat.at(i).at(j);
                Rmat.at(i).at(j)=Rmat.at(i).at(Rmat.at(0).size()-1-j);
                Rmat.at(i).at(Rmat.at(0).size()-1-j)=pom;
            }
        }
        return Rmat;
    }
    if(s==SmjerKretanja::LijevoDesno){typename remove_reference<decltype(kont.at(0))>::type Rmat;
    for(int i=0; i<mat.at(0).size(); i++){ typename remove_reference<decltype(kont.at(0).at(0))>::type Redov;
        for(int j=0; j<mat.size(); j++){
            Redov.push_back(mat.at(mat.size()-1-j).at(i));
        }
        Rmat.push_back(Redov);
    }
        return Rmat;
        
    }
    if(s==SmjerKretanja::DesnoLijevo){typename remove_reference<decltype(kont.at(0))>::type Rmat;
    for(int i=0; i<mat.at(0).size(); i++){ typename remove_reference <decltype(kont.at(0).at(0))>::type Red;
        for(int j=0; j<mat.size(); j++){
            Red.push_back(mat.at(mat.size()-1-j).at(mat.at(0).size()-1-i));
            
        }
        Rmat.push_back(Red);
    }
    for(int i=0; i<Rmat.size(); i++){
        for(int j=0; j<Rmat.at(0).size()/2; j++){
            auto pom=Rmat.at(i).at(j);
            Rmat.at(i).at(j)=Rmat.at(i).at(Rmat.at(0).size()-1-j);
            Rmat.at(i).at(Rmat.at(0).size()-1-j)=pom;
        }
    }
    return Rmat;
        
    }
    
    
    
    
    return mat;
   
}

int main ()
{ int x;
int y;
int z;
SmjerKretanja s;

/*
resize

*/
cout<<"Unesite dimenzije (x y z): ";
cin >> x >> y >>z; 
if(x<0 || y<0 ||z<0){
    cout<<"Neispravne dimenzije kontejnera!";return 0;
}

std::vector< deque<deque<int>> > a ( x, deque<deque<int>>(y, deque<int>(z) ) ) ;
    cout << "Unesite elemente kontejnera: ";
for(int i=0; i<a.size(); i++)
for(int j=0; j<a.at(i).size(); j++)
for(int k=0; k<a.at(i).at(j).size(); k++) {int e; cin>>e; a.at(i).at(j).at(k)=e;}

cout <<endl<<"Unesite smjer kretanja [0 - 5]: ";
int smjerkretanja;

cin>>smjerkretanja; if(smjerkretanja>5 || smjerkretanja<0 ){
    cout<<"Smjer kretanja nije ispravan!"<<endl;   return 0;
} else {
    s=SmjerKretanja(smjerkretanja);
}
try{ deque<deque<int>> b=IzdvojiDijagonale3D(a,s);
    if( s==SmjerKretanja::NaprijedNazad ) cout <<"NaprijedNazad: "; else if (s==SmjerKretanja::NazadNaprijed)
    cout << "NazadNaprijed: "; else if (s==SmjerKretanja::GoreDolje) cout<<"GoreDolje: "; else if (s==SmjerKretanja::DoljeGore) cout << "DoljeGore: "; else if (s==SmjerKretanja::LijevoDesno) cout << "LijevoDesno: ";
    else if (s==SmjerKretanja::DesnoLijevo)cout<<"DesnoLijevo: "; cout<< endl;
    for(int j=0; j<b.size(); j++){
        for(int k=0; k<b.at(j).size(); k++){
            cout<<setw(4)<<b.at(j).at(k);
        }
        cout<<endl;
    }
} catch (domain_error error){
    cout<<error.what();
}
	return 0;
}