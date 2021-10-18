#include<iostream>
#include<vector>
#include<deque>
#include<type_traits>
#include<stdexcept>
#include<iomanip>

enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename tip>

auto IzdvojiDijagonale3D (tip kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type {
    
    for(int i=0;i<kont.size();i++){
        for(int j=i+1;j<kont.size();j++)
            if(kont.at(i).size()!=kont.at(j).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
    }
    
    for(int i=0;i<kont.size();i++){
        for(int j=0;j<kont.at(i).size();j++){
          for(int k=j+1;k<kont.at(i).size();k++)
            if(kont.at(i).at(j).size()!=kont.at(i).at(k).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
   
   typename std::remove_reference<decltype(kont.at(0))>::type mat;
   
   if(kont.size()==0 || kont.at(0).size()==0) return mat;
   
    if(smjer==SmjerKretanja::NaprijedNazad){
        for(int i=0;i<kont.size();i++){ //spratovi
            mat.push_back({});
            for(int j=0, k=0;  j<kont.at(i).size() && k<kont.at(i).at(j).size() ; j++,  k++){ //sinhrono redovi i kolone
                mat.at(i).push_back(kont.at(i).at(j).at(k));
            }
        }
    }
    
    if(smjer==SmjerKretanja::NazadNaprijed){
        for(int t=0;t<kont.size();t++) mat.push_back({});  //resize
        for(int i=0;i<kont.size();i++){
            for(int j=0, k=kont.at(i).at(j).size()-1; j<kont.at(i).size() && k>=0; j++ , k--){ 
                mat.at(kont.size()-i-1).push_back(kont.at(i).at(j).at(k));     //idem od zadnjeg sprata
            }
        }
    }
    
    if(smjer==SmjerKretanja::GoreDolje){
        for(int j=0;j<kont.at(0).size();j++) {//fiksiram red
            mat.push_back({});
            for(int i=kont.size()-1, k=0; i>=0 && k<kont.at(i).at(j).size(); i--, k++){ //sprat i element
                mat.at(j).push_back(kont.at(i).at(j).at(k)); 
            }
        }
    }
    
    if(smjer==SmjerKretanja::DoljeGore){
        for(int t=0;t<kont.at(0).size();t++) mat.push_back({}); //resize
        for(int j=kont.at(0).size()-1;j>=0;j--){
            for(int i=kont.size()-1 , k=kont.at(i).at(j).size()-1; i>=0 && k>=0; i-- , k--){
                mat.at(kont.at(0).size()-j-1).push_back(kont.at(i).at(j).at(k));
            }
        }
    }
    
    if(smjer==SmjerKretanja::LijevoDesno){
        for(int k=0;k<kont.at(0).at(0).size();k++){
            mat.push_back({}); //resize
            for(int i=kont.size()-1 , j=0; i>=0 &&  j<kont.at(0).size(); i--, j++){
                mat.at(k).push_back(kont.at(i).at(j).at(k));
            }
        }
    }
    
    if(smjer==SmjerKretanja::DesnoLijevo){
        for(int t=0;t<kont.at(0).at(0).size();t++) mat.push_back({}); //resize
        for(int k=kont.at(0).at(0).size()-1;k>=0;k--){
            for(int i=0, j=0; i<kont.size() && j<kont.at(0).size(); i++ , j++){
                mat.at(kont.at(0).at(0).size()-k-1).push_back(kont.at(i).at(j).at(k));
            }
        }
    }
    
    return mat;
}


int main ()
{
    try{
    std::cout<<"Unesite dimenzije (x y z): ";
    int a,b,c;
    std::cin>>a>>b>>c;
    if(a<0 || b<0 || c<0) throw std::domain_error("Neispravne dimenzije kontejnera!");
    std::cout<<"Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> mat (a, std::deque<std::deque<int>>(b, std::deque<int>(c)));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
               std::cin>>mat.at(i).at(j).at(k);
            }
        }
    }

    std::cout<<"\nUnesite smjer kretanja [0 - 5]: ";
    int d;
    std::cin>>d;
    if(d<0 || d>=6) throw std::domain_error ("Smjer kretanja nije ispravan!\n");
    std::deque<std::deque<int>> dvaD=IzdvojiDijagonale3D(mat,SmjerKretanja(d));
    std::string s[]={"NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno","DesnoLijevo"};
    std::cout<<s[d]<<": "<<std::endl;
    for(auto x:dvaD){
        for(auto y:x)
            std::cout<<std::setw(4)<<y;
        std::cout<<std::endl;
      }
    }
    
    catch(std::domain_error b){
        std::cout<<b.what();
    }

	return 0;
}