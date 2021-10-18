/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void pt(int a ) {
    vector<int>b;
 while(a!=0){

    b.push_back(a%3);
    a/=3;
 }
for(int i=b.size()-1;i>=0;i--)cout<<b[i];



}
vector<int>IzdvojiGadne (vector<int>x,bool a){
    int s,d,b1=0,b2=0,b0=0,p1=0;
    vector<int>v;
for(int i=0;i<x.size();i++){
    s=x[i];
    d=s;
    while(d!=0){//djeli i broji 0,1,2

        if(d%3==0)b0=b0+1;
        if(d%3==1||d%3==-1)b1=b1+1;
        if(d%3==2||d%3==-2)b2=b2+1;

        d=d/3;
    }
    //cout<<b0<<b1<<b2;
    if((a==true)&&((b0%2==0)&&(b1%2==0)&&(b2%2==0))){//opaki
        if(v.size()==0)v.push_back(s);
        else {
            for(int j=0;j<v.size();j++){
                if(s==v[j]){p1=1;break;}
                else p1=0;


            }if(p1==0)v.push_back(s);


        }



    }
    if((a==false)&&(((b0%2!=0)&&(b1%2!=0)&&(b2%2!=0))||((b0==0)&&(b1%2!=0)&&(b2%2!=0))||((b0%2!=0)&&(b1==0)&&(b2%2!=0))||((b0%2!=0)&&(b1%2!=0)&&(b2==0))||((b0==0)&&(b1==0)&&(b2%2!=0))||((b0==0)&&(b1%2!=0)&&(b2==0))||((b0%2!=0)&&(b1==0)&&(b2==0))))
      {//pogani
        if(v.size()==0)v.push_back(s);
        else {
            for(int j=0;j<v.size();j++){
                if(s==v[j]){p1=1;break;}
                else p1=0;


            }if(p1==0)v.push_back(s);


        }



    }
   b0=0;
   b1=0;
   b2=0;






}

return v;



}



int main (){



   //pt(67);
   int n;
	vector<int>v;
	std::vector<int>g ;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";// << std::endl;
	std::cin >> n;
	while (n!=0) {v.push_back(n);
		cin>>n;
	}cout<<"Opaki: ";
	g=IzdvojiGadne(v,true);
	for(int i=0;i<g.size();i++){
        cout<<g[i]<<" ";
    }
    std::cout<< std::endl;
    cout<<"Odvratni: ";
	g=IzdvojiGadne(v,false);
	for(int i=0;i<g.size();i++){
        cout<<g[i]<<" ";
    }std::cout  << std::endl;/**/
	return 0;
}