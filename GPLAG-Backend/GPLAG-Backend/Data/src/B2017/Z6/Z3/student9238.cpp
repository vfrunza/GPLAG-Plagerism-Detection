#include <iostream>
#include <fstream>

int main() {
    std::ofstream izlazni_tok("z.txt");
    int b=9289;
    izlazni_tok<<b;
    return 0;
}