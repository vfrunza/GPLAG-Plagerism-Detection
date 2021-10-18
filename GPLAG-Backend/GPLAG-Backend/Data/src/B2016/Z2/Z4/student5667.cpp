#include <iostream>

struct strukt {
  int a;
};

void Ispisi(strukt **niz, int br) {
    for (int i=0; i<br; i++) {
        std::cout<<(*niz[i]).a<<std::endl;
    }
    hi();
}

void hi() {
    std::cout<<"HI"<<std::endl;
}

int main() {
    int br=10;
    strukt **niz=new strukt*[br];
    for (int i=0; i<br; i++) {
        niz[i]=new strukt;
        (*niz[i]).a=i;
    }
    Ispisi(niz, br);
    return 0;
}