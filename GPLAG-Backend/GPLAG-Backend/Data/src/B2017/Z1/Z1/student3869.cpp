#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> IzdvojiSimetricneTernarne(vector<int>x, bool nesto){
      vector<int>ternarni;
    for (int i=0;i<x.size();i++){
        int d;
    d=x[i];
    int y;
    vector<int>nesto;

    do{
        y=d%3;
        d=d/3;
        nesto.push_back(y);

    } while (d!=0);
    int a;
    a=0;

    for (int k=0;k<nesto.size();k++){
            double stepen;
    stepen=pow(10,k);
        a=a+nesto[k]*stepen;
    }
    ternarni.push_back(a);
    }
    cout<<endl<<endl;
    vector<int>RedniBr;
    for (int i=0;i<ternarni.size();i++){
        int broj;
        broj=ternarni[i];
        vector<int>novo;
        int ostat;
        do{
            ostat=broj%10;
            novo.push_back(ostat);
            broj=broj/10;
        } while(broj!=0);
        int brojac;
        brojac=0;
        int velicina;
        velicina=novo.size()-1;
        for (int j=0;j<(novo.size()/2);j++){

            if (novo[j]==novo[velicina-j]){
                brojac++;

            }

        }
        if (brojac==(novo.size()/2)) RedniBr.push_back(i);
    }
    vector<int>konacan;
    int dosta;
    for (int e=0;e<RedniBr.size();e++){
            int kl;
    kl=RedniBr[e];
        dosta=x[kl];
        konacan.push_back(dosta);
    }
    for (int i=0;i<konacan.size();i++){
        for (int j=(i+1);j<konacan.size();j++){
            if (konacan[i]==konacan[j]){
                konacan[j]=konacan[j+1];
            }
        }
    }
    vector<int> prosti;
    vector<int>slozeni;
            for (int i=0;i<konacan.size();i++){
            int w,t;
            w=konacan[i];
            t=konacan[i];
            int brojac;
            brojac=0;
            for (int j=1;j<=w;j++){
                if ((w%j)==0)brojac++;
            }
            if (brojac==2){
                prosti.push_back(t);
            }
            if (brojac>2) slozeni.push_back(t);

        }
    if (nesto==true) return prosti;
    else return slozeni;
}

int main()
{
    int n;
    vector<int>br;
    cout<<"Unesite elemente vektora (-1 za kraj): ";
    int broji;
    broji=-1;
    do {
        if (n!=broji){
        cin>>n;
        br.push_back(n);
        }
    } while (n!=(-1));
    vector<int> kraj;
    bool tacno;
    cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    cin>>tacno;

    kraj=IzdvojiSimetricneTernarne(br, tacno);

    cout<<"Prosti simetricni brojevi iz vektora su: ";
    for(int i=0;i<(kraj.size()-1);i++){
        cout<<kraj[i]<<", ";
    }
    if (kraj.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
    
    cout<<kraj[kraj.size()]<<".";
    return 0;
}