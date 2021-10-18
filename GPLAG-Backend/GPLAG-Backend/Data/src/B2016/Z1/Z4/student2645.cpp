#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>
#include <string>
void IzvrniString(std::string &recenica){
 int i(0),j(recenica.size()-1);
 char pomocni;
 while (i<j) {
    pomocni=recenica[i];
    recenica[i]=recenica[j];
    recenica[j]=pomocni;
    i++;
    j--;
 }
}

std::string ObrniFraze(std::string recenica,std::vector<std::string> vektor){
 
 std::string a,b;
 int poc(-1),kraj(-1);
 for (int i = 0; i < vektor.size(); i++) {
 for(int i=0;i<recenica.size();i++){
  if(recenica[i]==vektor[i][0]){
   if (i==0||(i>0&&recenica[i-1]==' ')) {
   poc=i;
  }}
  if (poc!=-1&&recenica[i]==' ') {
   kraj=i;
   break;
  }
 }
 }
 a=recenica.substr(poc,kraj);
 if(a==vektor[0]){
  IzvrniString(a);
 }
 return recenica;
}
int main (){
 int c(0);
 std::string recenica,rec;
 std::vector<std::string> vektor;
 std::cout<<"Unesite recenicu: ";
 std::getline(std::cin, recenica);
 std::cout << "Unesite fraze: " ;
 
while(c!='\n'){
std::getline(std::cin, rec);
c=std::cin.peek();

vektor.push_back(rec);
 }
ObrniFraze(recenica,vektor);

return 0;
}