#include <iostream>
#include <vector>
#include <fstream>
using std::cout, std::endl;


uint32_t convertBEtoLE(uint32_t x){
    //uses bit masking
    uint32_t y =0;
    for(int i = 0;i<=3;i++){
        y= y| (x>>i*8 & 0xFF)<<(3-i)*8;
    }
    return y;

}
int main() {
    //opening a binary file
    std::ifstream training_data;
    training_data.open("t10k-images.idx3-ubyte",std::ios::binary | std::ios::in);
    if(!training_data.is_open()){
        cout<<"File couldn't open"<<endl;
    }
    else{
        cout<<"The file opened"<<endl;
        //reading the magic number
        uint32_t magicNumber;

        training_data.read(reinterpret_cast<char*>(&magicNumber),sizeof(magicNumber));
        cout<<"The magic number before conversion: "<<magicNumber<<endl;
        cout<<"The magic number after conversion: "<<convertBEtoLE(magicNumber)<<endl;





    }

    return 0;
}
