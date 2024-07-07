#include <iostream>
#include <vector>
#include <fstream>


using std::cout, std::endl;
int main() {
    //opening a binary file
    std::ifstream training_data;
    training_data.open("t10k-images.idx3-ubyte",std::ios::binary | std::ios::in);
    if(!training_data.is_open()){
        cout<<"File couldn't open"<<endl;
    }
    else{
        cout<<"The file opened"<<endl;
        uint32_t x =  1769055902;
        uint32_t y = 0;

        for(int i = 0 ;i <= 3;i++) {
            y = y | (x >> (i * 8) & 0xFF) << (3 - i) * 8;
        }

        cout<<y<<endl;





    }

    return 0;
}
