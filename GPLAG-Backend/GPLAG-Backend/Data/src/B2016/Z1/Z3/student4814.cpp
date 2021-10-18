#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

typedef std::vector<std::vector<int>> matrica;

matrica RastuciPodnizovi(std::vector<int> a){

 std::vector<int>pomocni[10];
    int n=a.size();
    int r(0);
    for(int i=0; i<n; i++) {
            while(i!=n && a[i]<=a[i+1]){
            pomocni[r].push_back(a[i]);
                i++;
            }
            if(i!=n &&a[i]>a[i+1]){
                pomocni[r].push_back(a[i]);
            }
            r++;
    }
    matrica m(r);
    int k=0;
    for(int i=0; i<r; i++){


     if(pomocni[i].size()>1){
             m[k]=pomocni[i];
        k++;

        }
}
return m;
}

matrica OpadajuciPodnizovi(std::vector<int> a){

 std::vector<int>pomocni[10];
 int n=a.size();
    int brojac=0;
    int r(0);
    for(int i=0; i<n; i++) {
            while(i!=n && a[i]>=a[i+1]){
            pomocni[r].push_back(a[i]);
                i++;
            }
            if(i!=n && a[i]<a[i+1]){
                pomocni[r].push_back(a[i]);
            }
            r++;
    }
    matrica m(r);
    int k=0;
    for(int i=0; i<r; i++){


     if(pomocni[i].size()>1){
         m[k]=pomocni[i];
        k++;

        }
}
return m;
}
int main ()
{
    int n;
    std::vector<int>a;
    std::cout<<"Unesite broj elemenata vektora: ";
        std::cin>>n;
        int broj;
        std::cout<<"Unesite elemente vektora: ";
        for(int i(0); i<n; i++){
            std::cin>>broj;
            a.push_back(broj);
        }
    matrica k(RastuciPodnizovi(a));

    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;

    for(int i=0; i<k.size(); i++) {

        for(int j=0; j<k[i].size(); j++){
            std::cout<<k[i][j]<<" " ;
        }

         if(i<k.size()) std::cout<<std::endl;
    }
    matrica o(OpadajuciPodnizovi(a));
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0; i<o.size(); i++) {

        for(int j=0; j<o[i].size(); j++){
            std::cout<<o[i][j]<<" " ;
        }

       if(i<o.size())  std::cout<<std::endl;
    }

    return 0;
}
