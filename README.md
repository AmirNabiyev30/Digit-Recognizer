# Digit-Recognizer
The goal of this project is to implement a neural network using C++ from scratch to recongize digits from 0-9 using the public MNIST dataset. I emabrked on creating this project to learn the fundamentals of machine and deep learning and also improve my skills in C++. 

With this readme I am going to attempt to go into detail with the process of building the neural network. I hope this can serve as a guidleline for other people who try to do this project as I havent see many comphrensive guides online.

READING THE DATA

Using the MNIST dataset seems challenging at first and will require learning extra bits of knowledge about binary and C++ in general.

Things to note is that the file is in little endian which basically means that the binary will be read from least significant bit to most significant bit. However my computer and many other computer operate in big endian which means we will need to convert the endianess. This is not that difficult and there are many videos online on how to do this. 

Once we can covert the endianess with a simple function we can begin to read the data. We need use the ifstream libary to be able to open the binary files and actually read from them. 

Once we craete the file objects we need to open in binary mode and open them with the purpose of reading the file.

Now that we can read the binary files we have to be specific in what to read and how much

