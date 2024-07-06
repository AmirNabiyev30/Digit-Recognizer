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
        u_int64_t y;
        cout<<sizeof(y)<<endl;
        training_data.read(reinterpret_cast<char*>(&y),sizeof(y));
        cout<<y<<endl;
    }

    return 0;
}
