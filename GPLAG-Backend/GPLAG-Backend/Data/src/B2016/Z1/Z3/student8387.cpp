#include <iostream>
#include <vector>
bool SviIsti(std::vector<double> v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]!=v[i+1])return false;
    }
    return true;
}

typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(std::vector<double> v){
    Matrica mat;
    if(SviIsti(v)){
        mat.push_back(v);
        return mat;
    }
    for(int i=0;i<v.size()-1;i++){
        std::vector<double> a;
        if(v.at(i)<=v.at(i+1)){
            a.push_back(v.at(i));
            while(i<(v.size()-1) && v.at(i)<=v.at(i+1)){
                a.push_back(v.at(i+1));
                i++;
            }
            mat.push_back(a);
        }    
    }
     return mat;   
}
Matrica OpadajuciPodnizovi(std::vector<double> v){
    Matrica mat;
    if(SviIsti(v)){
        mat.push_back(v);
        return mat;
    }
    for(int i=0;i<v.size()-1;i++){
      std::vector<double> a;
      if(v.at(i)>=v.at(i+1)){
            a.push_back(v.at(i));
            while(i<(v.size()-1) && v.at(i)>=v.at(i+1)){
                a.push_back(v.at(i+1));
                i++;
            }
            mat.push_back(a);
        }    
    }
    return mat;
}
int main (){
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::vector<double> v(n);
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    Matrica opada=OpadajuciPodnizovi(v);
    Matrica rasta=RastuciPodnizovi(v);
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i=0;i<rasta.size();i++){
        for(int j=0;j<rasta[i].size();j++){
            std::cout<<rasta[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0;i<opada.size();i++){
        for(int j=0;j<opada[i].size();j++){
            std::cout<<opada[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
	return 0;
}