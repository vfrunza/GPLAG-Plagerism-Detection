#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(Vektor v){
Matrica MAXRAST;
Vektor Rastuci;
Vektor Temp;
int n=v.size();
for(int i=0;i<n-1;i++){
if(v[i]<=v[i+1]){
    Rastuci.push_back(v[i]);
}

if(Rastuci.size()>=1 && v[i]>v[i+1]){

    Rastuci.push_back(v[i]);
    MAXRAST.push_back(Rastuci);
    Rastuci.resize(0);
}
}



if(n>=2 && v[n-2]<=v[n-1]){
    Rastuci.push_back(v[n-1]);
MAXRAST.push_back(Rastuci);
}


return MAXRAST;
}

Matrica OpadajuciPodnizovi(Vektor v){
Matrica MAXOPAD;
Vektor Opadajuci;
Vektor Temp;
int n=v.size();
for(int i=0;i<n-1;i++){
if(v[i]>=v[i+1]){
   Opadajuci.push_back(v[i]);
}

if(Opadajuci.size()>=1 && v[i]<v[i+1]){

    Opadajuci.push_back(v[i]);
    MAXOPAD.push_back(Opadajuci);
    Opadajuci.resize(0);
}
}



if(n>=2 && v[n-2]>=v[n-1]){
    Opadajuci.push_back(v[n-1]);
MAXOPAD.push_back(Opadajuci);
}


return MAXOPAD;
}




int main(){

int n;
double a;
Vektor Unos;


std::cout << "Unesite broj elemenata vektora: ";
std::cin >> n;
std::cout << "Unesite elemente vektora: ";

while(n!=0){
    std::cin >> a;
    Unos.push_back(a);
    n--;

}

 auto Rastuci(RastuciPodnizovi(Unos));
 std::cout << "Maksimalni rastuci podnizovi: \n";

 for(int i=0;i<Rastuci.size();i++){
  for(int j = 0; j < Rastuci[i].size(); j++){
 std::cout << Rastuci[i][j]<<" ";

 }
  std::cout << std::endl;
}

auto Opadajuci(OpadajuciPodnizovi(Unos));
 std::cout << "Maksimalni opadajuci podnizovi: \n";

for(int i=0;i<Opadajuci.size();i++){
  for(int j = 0; j < Opadajuci[i].size(); j++){
 std::cout << Opadajuci[i][j]<<" ";

 }
  std::cout << std::endl;
}


 return 0;
}