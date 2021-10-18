/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#define PI 4.*atan(1)
using namespace std;

int main() {
fstream ulaz("TACKE.DAT",ios::in | ios::out | ios::binary);
pair<double,double>par;
double x,y;
while(ulaz.read(reinterpret_cast<char *>(&par),sizeof par)){
    swap(par.first,par.second);
    ulaz.seekp(ulaz.tellg()-sizeof par);
    ulaz.write(reinterpret_cast<char *>(&par),sizeof par);
    ulaz.seekg(ulaz.tellp());
}
if(!ulaz.eof) throw logic_error("Problem sa datotekom");
fstream tekst("TACKE.TXT",ios::out);
ulaz.clear(); ulaz.tellg(0);
while(ulaz.read(reinterpret_cast<char*>(&par),sizeof par))
    tekst<<par.first<<","<<par.second<<endl;
    if(!ulaz.eof()) throw logic_error("Problemi sa datotekom");
    tekst.close(); ulaz.close();
    tekst.open("TACKE.TXT",ios::in);
    char znak;
    while(tekst>>x>>znak>>y) cout<<x<<znak<<y<<endl;
    if(!tekst.eof()) throw std::logic_error("Problemi sa datotekom TACKE.TXT!");
return 0;
}
