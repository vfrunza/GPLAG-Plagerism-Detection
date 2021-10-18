/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova, int br_kolona)
{
    return Matrica(br_redova, vector<double>(br_kolona));
}
Matrica RastuciPodnizovi(vector<double> a)
{
    Matrica mat;
    int t(0);
    for(int i=0; i<a.size()-1; i++) {
        int j(0);
        if(a[i]<=a[i+1]) {
            mat.resize(t+1);
            while(a[i]<=a[i+1]) {
                double pomocni=a[i];
                mat[t].resize(j+1);
                mat[t][j]=pomocni;
                j=j+1;
                if(i+1==a.size()-1) {
                    mat[t].resize(j+1);
                    mat[t][j]=a[i+1];
                    return mat;
                }
                if(i+2<a.size() && a[i+1]>a[i+2]){
                      mat[t].resize(j+1);
                    mat[t][j]=a[i+1];
                }
                i=i+1;
            }
            t=t+1;
        }
    }
    return mat;
}
Matrica OpadajuciPodnizovi(vector<double> a)
{
    Matrica mat;
    int t(0);
    for(int i=0; i<a.size()-1; i++) {
        int j(0);
        if(a[i]>=a[i+1]) {
            mat.resize(t+1);
            while(a[i]>=a[i+1]) {
                double pomocni=a[i];
                mat[t].resize(j+1);
                mat[t][j]=pomocni;
                j=j+1;
                if(i+1==a.size()-1) {
                    mat[t].resize(j+1);
                    mat[t][j]=a[i+1];
                    return mat;
                }
                if(i+2<a.size() && a[i+1]<a[i+2]){
                      mat[t].resize(j+1);
                    mat[t][j]=a[i+1];
                }
                i=i+1;
            }
            t=t+1;
        }
    }
    return mat;
}
int main ()
{
    Matrica opadajuci;
    Matrica rastuci;
    double broj;
    int n;
    vector<double> slijed;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
        cin>>broj;
        if(broj!=0) slijed.push_back(broj);
        if(broj==0) break;
    }
    rastuci=RastuciPodnizovi(slijed);
    opadajuci=OpadajuciPodnizovi(slijed);
    cout<<"Maksimalni rastuci podnizovi: \n";
    for(int i=0; i<rastuci.size(); i++) {
        for(int j=0; j<rastuci[i].size(); j++) {
            cout<<setprecision(12)<<rastuci[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"Maksimalni opadajuci podnizovi: \n";
    for(int i=0; i<opadajuci.size(); i++) {
        for(int j=0; j<opadajuci[i].size(); j++) {
            cout<<setprecision(12)<<opadajuci[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}