#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
    Matrica M;
    std::vector<double> red,prazanvektor;
    for(int i(0);i<v.size()-1;i++){
        if(i<=v.size()-3){
            if(v[i]<=v[i+1])
                red.push_back(v[i]);
            else if(v[i+1]<v[i])
                red.push_back(v[i]);
        }
        else if(i==v.size()-2){
            if(v[i]<=v[i+1]){
                red.push_back(v[i]);
                red.push_back(v[i+1]);
                M.push_back(red);
                
            }
        }
        if(v[i]>v[i+1]){
            if(red.size()>1)
            M.push_back(red);
            red=prazanvektor;
        }
    }
    
return M;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
    Matrica M;
    std::vector<double> red,prazanvektor;
    for(int i(0);i<v.size()-1;i++){
        if(i<=v.size()-3){
            if(v[i]>=v[i+1])
                red.push_back(v[i]);
            else if(v[i+1]>v[i])
                red.push_back(v[i]);
        }
        else if(i==v.size()-2){
            if(v[i]>=v[i+1]){
                red.push_back(v[i]);
                red.push_back(v[i+1]);
                M.push_back(red);
            }
        }
        if(v[i]<v[i+1]){
            if(red.size()>1)
            M.push_back(red);
            red=prazanvektor;
        }
        }
    
return M;
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<double> v;
    int x;
    for(int i(0);i<n;i++){
        std::cin>>x;
        v.push_back(x);
    }
    Matrica M=RastuciPodnizovi(v);
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i(0);i<M.size();i++){
        for(int j(0);j<M[i].size();j++){
            std::cout<<std::setprecision(12)<<M[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    
    Matrica N(OpadajuciPodnizovi(v));
    for(int i(0);i<N.size();i++){
        for(int j(0);j<N[i].size();j++){
            std::cout<<std::setprecision(12)<<N[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
	return 0;
}