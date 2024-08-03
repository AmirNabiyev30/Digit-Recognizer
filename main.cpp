#include <iostream>
#include <vector>
#include <fstream>
using std::cout, std::endl;


uint32_t convertBEtoLE(uint32_t x){
    //uses bit masking
    uint32_t y = 0;
    for(int i = 0;i<=3;i++){
        y= y| (x>>i*8 & 0xFF)<<((3-i)*8);
    }
    return y;

}

uint32_t read_32int( uint32_t x, std::ifstream& file){
    //assuming file is open

    file.read(reinterpret_cast<char*>(&x), sizeof(x));
    x = convertBEtoLE(x);
    return x;

}

int main() {
    //creating the files variables
    std::ifstream training_images,training_labels, test_labels, test_images;
    //opening the files in binary and for reading NOT WRITING
    training_images.open("train-images.idx3-ubyte",std::ios::binary | std::ios::in);
    training_labels.open("train-labels.idx1-ubyte", std::ios::binary  | std::ios::in);
    test_images.open("t10k-images.idx3-ubyte", std::ios::binary | std::ios::in);
    test_labels.open("t10k-labels-idx1-ubyte", std::ios::binary | std::ios::in);
    if(!training_images.is_open()){
        cout<<"The training images file couldn't open \n";
        return 1;
    }
    if(!training_labels.is_open()){
        cout<<"The training labels file couldn't open \n";
        return 1;
    }
    if(!test_images.is_open()){
        cout<<"The test images couldn't open \n";
    }
    if(!test_labels.is_open()){
        cout<<"The test labels couldn't open \n";
    }
    cout<<"Both files opened without issues\n";

    //Going to read the magic numbers(signatures) of both files
    uint32_t magicImgTrain = 0, magicLabTrain = 0, magicImgTest = 0, magicLabTest = 0;

    magicImgTrain = read_32int(magicImgTrain,training_images);
    magicLabTrain = read_32int(magicLabTrain,training_labels);
    magicImgTest = read_32int(magicImgTest,test_images);
    magicLabTest = read_32int(magicLabTest,test_labels);
    /*training_images.read(reinterpret_cast<char*>(&magicImgTrain),sizeof(magicImgTrain));

    training_labels.read(reinterpret_cast<char*>(&magicLabTrain),sizeof(magicLabTrain));

    test_images.read(reinterpret_cast<char*>(&magicImgTest),sizeof(magicImgTest));

    test_labels.read(reinterpret_cast<char*>(&magicLabTest), sizeof(magicLabTest));


    magicLabTest = convertBEtoLE(magicLabTest);
    magicImgTrain = convertBEtoLE(magicImgTrain);
    magicImgTest = convertBEtoLE(magicImgTest);
    magicLabTrain = convertBEtoLE(magicLabTrain);
*/


    cout<<"The magic number we read is: "<<magicImgTest << endl;

    cout<<"The magic number we read is: "<<magicImgTrain<<endl;

    cout<<"The magic number we read is: "<<magicLabTest<<endl;

    cout<<"The magic number we read is: "<< magicLabTrain<<endl;


    if(magicImgTest == 2051){
        cout<<"We successfully read the magic number from this file\n";
    }




    training_images.close();
    training_labels.close();
    return 0;
}
