#include <iostream>
#include <vector>
int broj_cifara(int x){
        int br(0);
        while(x>0){
                br++;
                x/=10;
        }
        return br;
}
int stepenovanje(int x, int y){
        int povratna(1);
        for(int i=1; i<=y; i++){
                povratna*=x;
        }
        return povratna;
}
bool pripada_intervalu_aongovih(int x){
        if(x<0)return false;
        int pomocna(x),suma(0);
        while(x>0){
             suma+=stepenovanje(x%10,broj_cifara(pomocna));
             x=x/10;
        }
        if(pomocna==suma)return true;
        else return false;
}
std::vector<int>ArmstrongoviBrojevi(int p, int q){
        std::vector<int> ams_br;
        for(int i=p; i<=q; i++){
                if(pripada_intervalu_aongovih(i)){
                        ams_br.push_back(i);
                }
        }
        return ams_br;
}
int main() {
        std::cout << "Unesite dva broja: ";
        int p;
        std::cin >> p;
        int q;
        std::cin >> q;
        std::vector<int> k;
        k=ArmstrongoviBrojevi(p,q);
        if(k.size()==0)std::cout << "Nema Armstronvih brojeva u trazenom opsegu" << std::endl;
        else{
                std::cout << "Armstrongovi brojevi u opsegu ["<<p<<", "<<q<<"]: ";
                for(auto i=0; i<k.size(); i++){
                        if(i<k.size()-1)
                        std::cout << k[i] <<",";
                        else
                        std::cout << k[i] << std::endl;
                }
        }
        return 0;
}

