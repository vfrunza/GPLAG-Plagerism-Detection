/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>


using std::endl;
using std::cout;
using std::vector;
using std::cin;

int maxi_br_el_u_redu ( vector<vector<double>> x){
int maxi=x[0].size();
int c(0);
for(int i=0; i<x.size(); i++){
        if(x[c].size()>maxi) maxi=x[c].size();
        c++;

}

return maxi;
}



void IspisVectora (vector<double>  x){
   for(int i=0; i<x.size(); i++){
   if(i!=x.size()-1) cout<<x[i]<<" ";
   else cout<<x[i];}
   cout<<endl;
}


  vector<vector<double>> RastuciPodnizovi (vector<double> x){

  vector<double> pomocni(0);
  vector<vector<double>> nova;
  if(x.size()==0) return nova;

  double a;
  int d(0);
  int testna(0);
  for(int i=0; i<x.size()-1; i++){
    for(int j=i+1; j<i+2; j++){
        if(x[i]<=x[j]) { testna=1; pomocni.push_back(x[i]); a=x[j];}
        else if(pomocni.size()>0) {
            if(testna==1) testna=0;
            pomocni.push_back(a);

            nova.resize(nova.size()+1);
            nova[d]=pomocni;

            d++;
            pomocni.resize(0);

        }
    } //if(i==x.size()-2) break;
  }

 if(pomocni.size()>0) {
            if(testna==1) testna=0;
            pomocni.push_back(a);

            nova.resize(nova.size()+1);
            nova[d]=pomocni;

            d++;
            pomocni.resize(0);}
  return nova;
  }




  vector<vector<double>> OpadajuciPodnizovi (vector<double> x){

  vector<double> pomocni(0);
  vector<vector<double>> nova;
  if(x.size()==0) return nova;

  double a;
  int  d(0);
  int testna(0);
  for(int i=0; i<x.size()-1; i++){
    for(int j=i+1; j<i+2; j++){
        if(x[i]>=x[j]) { testna=1; pomocni.push_back(x[i]); a=x[j];}
        else if(pomocni.size()>0) {
            if(testna==1) testna=0;
            pomocni.push_back(a);

            nova.resize(nova.size()+1);
            nova[d]=pomocni;

            d++;
            pomocni.resize(0);

        }
    }
  }
  if(pomocni.size()>0) {
            if(testna==1) testna=0;
            pomocni.push_back(a);

            nova.resize(nova.size()+1);
            nova[d]=pomocni;

            d++;
            pomocni.resize(0);

        }

  return nova;
  }

  void IspisMatrice (vector<vector<double>>  x){
   for(int i=0; i<x.size(); i++){
        for(int j=0; j<x[i].size(); j++){
                cout<<x[i][j]<<" ";}
   cout<<endl;}
}





  int main(){
      vector<vector<double>> matrica;
      vector<double> a;
      cout<<"Unesite broj elemenata vektora: ";
      int n;
      cin>>n;
      if(n<=0) return 0;
      double z;
     
      cout<<"Unesite elemente vektora: ";
      for(int i=0; i<n; i++) {
            cin>>z;
            a.push_back(z);}
      cout<<"Maksimalni rastuci podnizovi: "<<endl;
  matrica=RastuciPodnizovi(a);

  //IspisMatrice(matrica);
 if(matrica.size()>0) {int d=maxi_br_el_u_redu(matrica);
  //cout<<"broj clanova u redu sa najvise clanova "<<d<<endl;
  int testna=0;
  for(int i=0; i<matrica.size(); i++){
    if(matrica[testna].size()==d) IspisVectora(matrica[testna]);
    testna++;
  }}
  else cout<<endl; //mere bit da treba mere da ne treba
cout<<"Maksimalni opadajuci podnizovi: "<<endl;
  matrica=OpadajuciPodnizovi(a);
  //IspisMatrice(matrica);
  if(matrica.size()>0) { int d=maxi_br_el_u_redu(matrica);
  //<<"broj clanova u redu sa najvise clanova "<<d<<endl;
   int testna=0;
  for(int i=0; i<matrica.size(); i++){
    if(matrica[testna].size()==d) IspisVectora(matrica[testna]);
    testna++;
  }}
  return 0;}
