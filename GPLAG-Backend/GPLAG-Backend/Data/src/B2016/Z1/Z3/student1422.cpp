#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> VektorVektora;

void IspisiPodnizove( VektorVektora w){
    for(int i=0;i<int(w.size());i++){
	for(int j=0;j<int(w[i].size());j++)
	std::cout<< std::setprecision(12)<<w[i][j]<<" ";
	std::cout<<std::endl;
	}
}

VektorVektora RastuciPodnizovi(Vektor v){
    VektorVektora w;
    int j(0);
    for(int i=0;i<int(v.size())-1;i++){
        Vektor pom;
        j=i;
     while(v[j]<=v[j+1] && (j+1)<int(v.size())){
         pom.push_back(v[j]);
         pom.push_back(v[j+1]);
         j+=2;
         i=j;
         
         //uslov za posljednji element
         if(j==int(v.size())-1){
             if(v[j]>=v[j-1])
             pom.push_back(v[j]);
             //break;
             w.push_back(pom);
             return w;
         }
         if(j>int(v.size())-1) break;
         
         //dodala
         if(j>0 && v[j]>=v[j-1] && !((v[j]<=v[j+1]))){
             pom.push_back(v[j]);
             break;
         }
         if(j>0 && v[j]>=v[j-1])
         continue;
         else {
             i-=2;
             break;
         }
     }
     if(i==int(v.size())-1) break;
     w.push_back(pom);
    }
    return w;
}

VektorVektora OpadajuciPodnizovi(Vektor v){
    VektorVektora w;
    int j(0);
    for(int i=0;i<int(v.size())-1;i++){
        Vektor pom;
        j=i;
     while(v[j]>=v[j+1] && (j+1)<int(v.size())) {
         pom.push_back(v[j]);
         pom.push_back(v[j+1]);
         j+=2;
         i=j;
         
         if(j==int(v.size())-1){
             if(v[j]<=v[j-1])
             pom.push_back(v[j]);
             //break;
             w.push_back(pom);
             return w;
         }
         if(j>int(v.size())-1) break;
         
         //dodala
          if(j>0 && v[j]<=v[j-1] && !((v[j]>=v[j+1]))){
             pom.push_back(v[j]);
             break;
         }
         if(j>0 && v[j]<=v[j-1])
         continue;
         else {
             i-=2;
             break;
         }
     }
     if(i==int(v.size())-1) break;
     w.push_back(pom);
    }
    return w;
}

int main(){
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    Vektor v;
	double el;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
	    std::cin>>el;
	    v.push_back(el);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	VektorVektora w(RastuciPodnizovi(v));
	IspisiPodnizove(w);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	VektorVektora d(OpadajuciPodnizovi(v));
	IspisiPodnizove(d);
    return 0;
}