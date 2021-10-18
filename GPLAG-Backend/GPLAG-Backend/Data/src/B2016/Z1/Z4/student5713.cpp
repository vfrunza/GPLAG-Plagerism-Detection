


/*B 2016/2017, Zadaca 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

 /*Danas je lijep i suncan dan
danas
lijep
suncan

Ocekivani izlaz programa:
Unesite recenicu: Unesite fraze: Recenica nakon PigLatin transformacije: Danas je ijeplay i uncansay dan
Recenica nakon obrtanja fraza: Danas je pejil i nacnus dan



//Kraj fraze oznacava se prelaskom u novi red.
//Kraj unosa fraza zavrsava se dvostrukim prelaskom u novi red.


*/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>
using std::endl;
using std::cout;
using std::vector;
using std::cin;
using std::string;

int JeLiNeslovo (char znak){
if((znak>='a' && znak<='z')|| (znak>='A' && znak<='Z')) return 0;
return 1;
}

int Maxi_broj_razmaka_u_redu (vector<string> x){
int maxi(0), razmak(0);
for(int i=0; i<x.size(); i++){
        razmak=0;
    for(int j=0; j<x[i].size(); j++){
        if(x[i][j] == ' ') razmak++;
    }
if(razmak>maxi) maxi= razmak;
}

return maxi;
}


string ObrniFraze (string a, vector<string>s ){
int j(0), brojac(0);
    for(int i=0; i<a.size(); i++){
        if(j<s.size()){
                for(int k=0; k<s[j].size(); k++){
                 // cout<<"poredi: "<<a[i]<<" "<<s[j][k]<<endl;
            if(a[i]!=s[j][k]) continue;
            if(a[i]==s[j][k]){
                 // cout<<"jednaka pocetna slova "<<endl;

                int jesu_jednaki(1);
                int u=k;
                //if(i+s[j].size()-1<=a.size()-1)
                for(int l=i+1; l<i+s[j].size(); l++){/* l<..-2,-1, 0 sve radi O.o*/
                    for(int m=u+1; m<u+2; m++){//jednom se izvrsava
                        //cout<<"nastavak provjere:"<<a[l]<<" "<<s[j][m]<<endl;
                            if(a[l]!=s[j][m]) {
                                   // cout<<"nisu jednaki"<<endl;
                            jesu_jednaki=0;  break;}

                   // if(l-i+1==s[j].size()) break;

                    }
                    if(jesu_jednaki==0) break; //za greske mem
                   // if(l==i+s[j].size()-2) break;
                    u++;
                    if(u==s[j].size()) break;//za greske mem
                }

             if(jesu_jednaki==1){
                    //cout<<"jednaki!"<<endl;
                    int t(0);
                    char temp;
            if(i+s[j].size()-t-1<=a.size()-1)//greske memorijske
            for(int n=0; n<s[j].size()/2; n++){
                temp=a[i+t];
                a[i+t]=a[i+s[j].size()-t-1];
                a[i+s[j].size()-t-1]=temp;
                t++;
               // cout<<"prvi,drugi je "<<a[i+t]<<" "<<a[i+s[j].size()-t-1]<<endl;
            }

            }

            }
        }
    }
    if(i==a.size()-1) {i=-1; brojac++; j++;}
    if(brojac==s.size()) break;
    }
    //cout<<"konacno:"<<endl<<a<<endl;
    return a;
}



string IzmijeniUPigLatin (string a, vector<string> s){
//izuzetak
for(int c=0; c<s.size(); c++){
    for(int d=0; d<s[c].size(); d++){
        if(!((s[c][d]>='a' && s[c][d]<='z') || (s[c][d]>='A' && s[c][d]<='Z'))) throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
    }
}



 if(s.size()!=0){
                    string testna="";
for(int i=0; i<a.size(); i++){
    if(a[i]!=' ') testna.push_back(a[i]);
    else if(a[i]==' ' && testna.size()>0) {
            // cout<<"nasao razmak"<<endl;
            int jeste(0);
        for(int j=0; j<s.size(); j++){
           // cout<<"testna je " <<testna<<" a stringoiv zadati su " <<s[j]<<endl;
            if(testna==s[j]) {jeste=1; break;}

        }
        if(jeste==1){
   // cout<<"ubacivanje i izhbacivanj"<<endl;

        a.insert(a.begin()+i, a[i-testna.size()]);
       //cout<<a<<endl;
        a.insert(a.begin()+i+1, 'a');
         // cout<<a<<endl;
        a.insert(a.begin()+i+2, 'y');
          //cout<<a<<endl;
        a.erase(a.begin()+i-testna.size());
  //cout<<a<<endl;
i=i+2;
            testna.resize(0);
        }
        else if(i!=a.size()-1)testna.resize(0);
    }
}

if( testna.size()>0) {
             //cout<<"zadnja provjera"<<endl;
            int jeste(0);
        for(int j=0; j<s.size(); j++){
            //cout<<"testna je " <<testna<<" a stringoiv zadati su " <<s[j]<<endl;
            if(testna==s[j]) {jeste=1; break;}

        }
        if(jeste==1){
    //cout<<"ubacivanje i izhbacivanj"<<endl;
int i=a.size();
        a.insert(a.begin()+i, a[i-testna.size()]);
      // cout<<a<<endl;
        a.insert(a.begin()+i+1, 'a');
        //  cout<<a<<endl;
        a.insert(a.begin()+i+2, 'y');
          //cout<<a<<endl;
        a.erase(a.begin()+i-testna.size());
  //cout<<a<<endl;
i=i+2;
            testna.resize(0);
        }
        else testna.resize(0);
}}



//mijenja sve rijeci
else if(s.size()==0){
//cout<<"br clanova je 0"<<endl;
        string testna="";
for(int i=0; i<a.size(); i++){
        //cout<<"testna je:"<<testna<<endl;
       // cout<<"a[i]:"<<a[i]<<endl;
    if(JeLiNeslovo(a[i])==0) testna.push_back(a[i]);
    else if(JeLiNeslovo(a[i])==1 && testna.size()>0) {
            // cout<<"nasao razmak"<<endl;

  // cout<<"ubacivanje i izhbacivanj"<<endl;

        a.insert(a.begin()+i, a[i-testna.size()]);
       //cout<<a<<endl;
        a.insert(a.begin()+i+1, 'a');
         // cout<<a<<endl;
        a.insert(a.begin()+i+2, 'y');
          //cout<<a<<endl;
        a.erase(a.begin()+i-testna.size());
  //cout<<a<<endl;
i=i+2;
testna.resize(0);
        }

    }


if( testna.size()>0) {
            // cout<<"zadnja provjera"<<endl;

    //cout<<"ubacivanje i izhbacivanj"<<endl;
int i=a.size();
        a.insert(a.begin()+i, a[i-testna.size()]);
      // cout<<a<<endl;
        a.insert(a.begin()+i+1, 'a');
        //  cout<<a<<endl;
        a.insert(a.begin()+i+2, 'y');
          //cout<<a<<endl;
        a.erase(a.begin()+i-testna.size());
  //cout<<a<<endl;
i=i+2;
            testna.resize(0);


}



}

return a;
}




 int main(){

 	cout<<"Unesite recenicu: ";
 	char recenica[40]="";
 	string s=recenica;
 	std::getline(cin, s);

 	vector<string> fraze;
 	cout<<"Unesite fraze: ";
 	char tekst[40]="";
 	string s1=tekst;
// cout<<*(s1.c_str())<<endl;

 	while(1){
            std::getline(cin, s1);
            //if(*(s1.c_str())==char('\n')) break;
            if(s1=="") break;
            else  fraze.push_back(s1);
 	}
 	/*cout<<"fraze su\n";
for(int i=0; i<fraze.size(); i++){
    cout<<fraze[i]<<endl;
}
*/

try{
    string w=IzmijeniUPigLatin(s, fraze);
    cout<<"Recenica nakon PigLatin transformacije: ";
cout<<w;
}
catch(std::domain_error izuzetak){
cout<<izuzetak.what();
}

 	cout<<endl<<"Recenica nakon obrtanja fraza: ";
 	string h= ObrniFraze(s, fraze);
 	cout<<h;


 return 0;
 }




