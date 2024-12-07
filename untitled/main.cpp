#include <iostream>
int main() {
    if (std::FILE* f=std::fopen("input.txt","r"); f!=nullptr) {
        char buf[100];
        std::fscanf(f,"%99s", buf);

        std::fclose(f);
    }
    else {
        std::cout<<"File open failure\n";
    }
}
