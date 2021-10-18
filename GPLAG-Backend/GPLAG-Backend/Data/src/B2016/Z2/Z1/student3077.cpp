#include <iostream>

using std::cout;

int &h(int &p, int &q, int &r){
    cout<<p<<" "<<q<<" "<<r<<std::endl;
    p=q++;
    cout<<"P je "<<p<<std::endl;
    cout<<"Q je "<<q<<std::endl;
    q=r++;
    cout<<"R je "<<p<<std::endl;
    cout<<"Q je "<<q<<std::endl;
    q=p++;
    cout<<"P je "<<p<<std::endl;
    cout<<"Q je "<<q<<std::endl;
    cout<<p<<" "<<q<<" "<<r<<std::endl;
    return p;
    
}


int main(){
    int a[]{4,1,6,7,3,2,9};
    int *p(a+4);
    h(*(a+2),a[4],p[-2])*=3;
    for(auto i=std::begin(a); i<std::end(a); i++)
        cout<<*i<<" ";
    return 0;
}