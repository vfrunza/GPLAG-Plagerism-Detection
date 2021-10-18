#include <iostream>
#include <vector>


typedef std::vector<std::vector<double>> M;

M BrisanjePraznina(M m)

{
    
for(int i=0; i<m.size(); i++){
if(m[i].size()==1){
m.erase(m.begin()+i);
i--;
    
}
}

return m;

}

M RastuciPodnizovi(std::vector<double> v){
M m(1, std::vector<double> ());
int a(0),b(1);
    
v.push_back(1000000000000);
for(int i=0; i<v.size()-1; i++)

{
    
if(v[i]<=v[i+1])

{
    
m[a].push_back(v[i]);


    
}

else

{
            
            m[a].push_back(v[i]);
            a++;
            b++;
            m.resize(b);
        

}
}
        
           m=BrisanjePraznina(m);
           return m;

    
}

M OpadajuciPodnizovi(std::vector<double> v){
M m(1, std::vector<double> ());
int a(0),b(1);
v.push_back(-1000000000000);
for(int i=0; i<v.size()-1; i++){
if(v[i]>=v[i+1]){
m[a].push_back(v[i]);
        

}
        
else
{
    
    m[a].push_back(v[i]);
    a++;
    b++;
    m.resize(b);
    
    
}   
}

    m=BrisanjePraznina(m);
    return m;
}

int main()

{
    

int n;
std::vector<double> v;
M Rastuci,Opadajuci;
std::cout<<"Unesite broj elemenata vektora: ";
std::cin>>n;
std::cout<<"Unesite elemente vektora: ";
for(int i=0; i<n; i++){
double a;
std::cin>>a;
v.push_back(a);

    
    
}

Rastuci=RastuciPodnizovi(v);
Opadajuci=OpadajuciPodnizovi(v);

std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;

for(int i=0; i<Rastuci.size(); i++)

{
    
for(int j=0; j<Rastuci[i].size(); j++)
std::cout<<Rastuci[i][j]<<" ";
std::cout<<std::endl;
    
    
}

std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
     
for(int i=0; i<Opadajuci.size(); i++){
for(int j=0; j<Opadajuci[i].size(); j++)
std::cout<<Opadajuci[i][j]<<" ";
std::cout<<std::endl;
    
    
}
    return 0;
}



