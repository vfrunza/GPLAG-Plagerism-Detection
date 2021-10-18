#include <iostream>
#include <vector>
using namespace std;
vector<int> IzdvojiGadne(vector<int> a,bool p)
{
    vector<int>	v;
    for(int i=0; i<a.size(); i++) {
        int broj(a[i]);
        int broj1(a[i]);
        int brojac0(0);
        int brojac1(0);
        int brojac2(0);
        while(broj!=0) {
            int ternarnibroj;
            ternarnibroj=broj%3;
            if(ternarnibroj==0) brojac0++;
            if(ternarnibroj==1 || ternarnibroj==-1) brojac1++;
            if(ternarnibroj==2 || ternarnibroj==-2) brojac2++;
            broj/=3;
        }
        if((brojac0%2==0 && brojac1%2==0 && brojac2%2==0)) {
            if(p==true) {
                bool nadjen(false);
                for(int j=0; j<v.size(); j++) {
                    if(broj1==v[j])
                 {       nadjen=true;
                    break;}


    
                }

                if(nadjen==false) v.push_back(broj1);
            }
        }

        if((brojac0%2==1 || brojac0==0) && (brojac1%2==1 || brojac1==0) && (brojac2%2==1 || brojac2==0)) {
            if(p==false) {
                bool nadjen(false);
                for(int j=0; j<v.size(); j++) {
                    if(broj1==v[j])
                      {  nadjen=true;
                    break;}

                }
                if(nadjen==false) v.push_back(broj1);
            }
        }
    }
    return v;

}
int main ()
{
    vector<int> v;
    cout<<"Unesite brojeve (0 za prekid unosa): ";
    int n;
    do {

        cin>>n;
        if(n!=0)
            v.push_back(n);
    } while(n!=0);
    vector<int> v1(IzdvojiGadne(v,true));
    vector<int> v2(IzdvojiGadne(v,false));
    cout<<"Opaki: ";
    for(int x: v1) cout<<x<<" ";
    cout<<endl;
    cout<<"Odvratni: ";
    for(int x: v2) cout<<x<<" ";

    return 0;
}