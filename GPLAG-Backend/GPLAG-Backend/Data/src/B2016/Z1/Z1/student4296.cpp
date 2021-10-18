#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
//tacan-opak
//0- ni odvratan ni opak; 1-opak; 2-odvratan
int ProvjeraGadnosti(long long int broj){
    vector<int> br(3,0);
    int x;
    while(broj!=0){
        x=fabs(broj%3);
        if(x==0)
            br[0]++;
        else if(x==1)
            br[1]++;
        else if(x==2)
            br[2]++;
        broj=broj/3;
    }
   
    bool odvratan=true;
    bool opak=true;
    for(int i=0;i<3;i++){
        if(br[i]!=0){
            if(br[i]%2!=0)
                opak=false;
        }
    }
    for(int i=0;i<3;i++){
        if(br[i]!=0){
            if(br[i]%2==0)
                odvratan=false;
        }
    }
    if(!opak && !odvratan)
        return 0;
    if(odvratan)
         return 2;
    else return 1;
}
vector<int> IzdvojiGadne(vector<int> V, bool A){
    int Gadnost;
    std::vector<int> Gadan;
    for(int i=0; i< V.size(); i++){
        Gadnost=ProvjeraGadnosti(V[i]);
        if(A && Gadnost==1){
            Gadan.push_back(V[i]);
        }
        else if(!A && Gadnost==2){
            Gadan.push_back(V[i]);
        }
        if(i==V.size()-1)
            break;
    }
    if(Gadan.size()>1){
        for(int i=0; i<Gadan.size(); i++){
            for(int j=i; j<Gadan.size()-1; j++){
                if(Gadan[i]==Gadan[j+1]){
                    Gadan.erase(Gadan.begin() + j+1);
                    j--;
                }
                if(j==Gadan.size()-2)
                    break;
            }
            if(i==Gadan.size()-1)
                break;
        }
    }
    return Gadan;
}
int main (){   
    int n;
	vector<int> V;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	cin>>n;
	while(n!=0){
	    V.push_back(n);
	    cin>>n;
	}
	vector<int> Opak;
	Opak=IzdvojiGadne(V, true);
	vector<int> Odvratan;
	Odvratan=IzdvojiGadne(V,false);
	cout<<"Opaki: ";
	if(Opak.size()!=0) 
	    for(int x: Opak)
	        cout<<x<<" ";
	cout<<endl<<"Odvratni: ";
	if(Odvratan.size()!=0) 
	    for(int x: Odvratan)
	        cout<<x<<" ";
    return 0;
}