#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector<int>v,bool P){
if(v.size()==0) throw v;
std::vector<int>izdvoji;
int broj,cifra;
int brojac0(0),brojac1(0),brojac2(0);
std::vector<int>opaki;
std::vector<int>odvratni;

for(int i=0;i<v.size();i++){
broj=fabs(v[i]);
while(broj!=0){
cifra=broj%3;
broj/=3;
izdvoji.push_back(cifra);
}
for(int i=0;i<izdvoji.size();i++){
if(izdvoji[i]==0)brojac0++;
if(izdvoji[i]==1)brojac1++;
if(izdvoji[i]==2)brojac2++;
}
if(brojac0==0 && brojac1!=0 && brojac2!=0){
if(brojac1%2==0 && brojac2%2==0)opaki.push_back(v[i]);
else if(brojac1%2==1 && brojac2%2==1)odvratni.push_back(v[i]);
}
else if (brojac1==0 && brojac0!=0 && brojac2!=0){
if (brojac0%2==0 && brojac2%2==0){opaki.push_back(v[i]);}
else if (brojac0%2==1 && brojac2%2==1){odvratni.push_back(v[i]);
}
}
else if(brojac2==0 && brojac1!=0 && brojac0!=0){
if (brojac0%2==0 && brojac1%2==0){opaki.push_back(v[i]);
}
else if (brojac0%2==1 && brojac1%2==1){odvratni.push_back(v[i]);}
}

else if(brojac0==0 && brojac1==0){
if(brojac2%2==0){opaki.push_back(v[i]);}
else if (brojac2%2==1){odvratni.push_back(v[i]);}
}
else if(brojac0==0 && brojac2==0){
if(brojac1%2==0){opaki.push_back(v[i]);}
else if (brojac1%2==1){odvratni.push_back(v[i]);}
}
else if(brojac1==0 && brojac2==0){
if(brojac0%2==0){opaki.push_back(v[i]);}
else if(brojac0%2==1){odvratni.push_back(v[i]);}
}

else if (brojac0!=0 && brojac1!=0 && brojac2!=0){
if (brojac0%2==0 && brojac1%2==0 && brojac2%2==0){opaki.push_back(v[i]);}
else if (brojac0%2==1 && brojac1%2==1 && brojac2%2==1){odvratni.push_back(v[i]);}
}
izdvoji.resize(0);
brojac0=0;
brojac1=0;
brojac2=0;
}



for(int i=1;i<opaki.size();i++){
if(i==opaki.size()-1)break;
if(opaki[i]==opaki[i+1]){
opaki.erase(opaki.begin()+i);
i--;
}}

for(int i=0;i<opaki.size();i++){
for(int j=i+1;j<opaki.size();j++){
if(opaki[i]==opaki[j])
opaki.erase(opaki.begin()+j);}}

for(int i=1;i<odvratni.size();i++){
if(i==odvratni.size()-1)break;
if(odvratni[i]==odvratni[i+1]){

odvratni.erase(odvratni.begin()+i);
i--;
}}

for(int i=0;i<odvratni.size();i++){
for(int j=i+1;j<odvratni.size();j++){
if(odvratni[i]==odvratni[j])
odvratni.erase(odvratni.begin()+j);}}

if(P){
return opaki;
}
else
return odvratni;
}


int main ()
{
bool p(true);
std::vector<int>a;
std::vector<int>b;
int nekibroj;
std::vector<int>v;
std::cout<<"Unesite brojeve (0 za prekid unosa): ";
do{
std::cin>>nekibroj;
if(nekibroj==0)break;
v.push_back(nekibroj);
}while(nekibroj!=0);
try {
v.size()!=0;
}
catch (int e) {
std::cout<<"Niste uneli brojeve: ";
return 0;
}


a=IzdvojiGadne(v,p);
if(a.size()!=0){
std::cout<<"Opaki: ";
for (int i=0;i<a.size();i++){
std::cout<<a[i]<<" ";
}}
std::cout<<std::endl;
p=false;

b=IzdvojiGadne(v,p);
if(b.size()!=0){
std::cout<<"Odvratni: ";
for(int i=0;i<b.size();i++){
std::cout<<b[i]<<" ";
}}
return 0;
}

