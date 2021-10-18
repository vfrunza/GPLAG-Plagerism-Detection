#include<iostream>
#include<vector>
#include<iomanip>
typedef std::vector<std::vector<double>> Matrica;
void IspisiMatricu(Matrica m){
    for(std::vector<double>red:m){
        for(double x:red)std::cout<<std::setprecision(12)<<x<<" ";
        std::cout<<std::endl;
    }
}
Matrica RastuciPodnizovi(std::vector<double> Niz){
    int PamtiIndeks(0),n(0);
    Matrica Podnizovi;
    if(Niz.size()==0)return Podnizovi;
    for(int i=0;i<Niz.size()-1;i++){
        while(Niz[i]<=Niz[i+1]){
            i++;
            if(i==Niz.size()-1)break;
        }
        if(i-PamtiIndeks>=1){
            n++;
            Podnizovi.resize(n);
            for(int j=PamtiIndeks;j<=i;j++){
                Podnizovi[n-1].push_back(Niz[j]);
            }
        }
        PamtiIndeks=i+1;
    }
    return Podnizovi;
}
Matrica OpadajuciPodnizovi(std::vector<double> Niz){
    int PamtiIndeks(0),n(0);
    Matrica Podnizovi;
    if(Niz.size()==0)return Podnizovi;
    for(int i=0;i<Niz.size()-1;i++){
        while(Niz[i]>=Niz[i+1]){
            i++;
            if(i==Niz.size()-1)break;
        }
        if(i-PamtiIndeks>=1){
            n++;
            Podnizovi.resize(n);
            for(int j=PamtiIndeks;j<=i;j++){
                Podnizovi[n-1].push_back(Niz[j]);
            }
        }
        PamtiIndeks=i+1;
    }
    return Podnizovi;
}
int main ()
{int n;
std::cout<<"Unesite broj elemenata vektora: ";
std::cin>>n;
std::vector<double> v(n);
std::cout<<"Unesite elemente vektora: ";
for(int i=0;i<v.size();i++){
    int a;
    std::cin>>a;
    v[i]=a;
}
std::cout<<"Maksimalni rastuci podnizovi: \n";
    Matrica podnizovi;
    IspisiMatricu(RastuciPodnizovi(v));
    std::cout<<"Maksimalni opadajuci podnizovi: \n";
    IspisiMatricu(OpadajuciPodnizovi(v));
	return 0;
}