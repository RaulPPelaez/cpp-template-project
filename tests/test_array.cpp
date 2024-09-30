#include <gtest/gtest.h>
#include "dynamic_array.h"
#include <iostream>
#include <random>
using namespace homework::dynarray;
//   #include"DynamicArray.h"
//   #include<iostream>
//   #include<random>
//   using namespace oop; // Lets assume the header is in a namespace called oop
DynamicArray createRandomArray(){
  static std::default_random_engine generator;
  static std::uniform_int_distribution<int> distribution(1,100);
  DynamicArray a(10);
  for(int i = 0; i < 10; i++){
    a[i] = distribution(generator);
  }
  return a;
}
//   int main(){
//     DynamicArray a(10, 1); // 10 elements, all initialized to 1
//     a[0] = 2; a[1] = 3;
//     DynamicArray b = a; // Copy assignment operator
//     DynamicArray c = createRandomArray(); // Move assignment operator
//     DynamicArray d(b); // Copy constructor
//     DynamicArray e(createRandomArray()); // Move constructor
//     std::cout << a << std::endl; // Stream insertion operator
//     DynamicArray f = a + b; // Addition operator, concatenates the arrays
//     if(f.size() != a.size() + b.size()){
//       std::cerr << "Error: size of f is not the sum of sizes of a and b" << std::endl;
//     }
//     return 0; // Destructor is called on all objects: no memory leaks
//   }

TEST(DynamicArray, Constructor) {
	DynamicArray a(10, 1);
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(a[i], 1);
	}
}

TEST(DynamicArray, CopyConstructor) {
	DynamicArray a(10, 1);
	DynamicArray b(a);
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(b[i], 1);
	}
}

TEST(DynamicArray, Move) {
  DynamicArray a(createRandomArray());
  DynamicArray a2 = createRandomArray();
}

TEST(DynamicArray, CopyAssignment) {
  DynamicArray a(10, 1);
  DynamicArray b(10, 2);
  b = a;
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(b[i], 1);
  }
}

TEST(DynamicArray, Concatenate){
  DynamicArray a(10, 1);
  DynamicArray b(10, 2);
  DynamicArray c = a + b;
  EXPECT_EQ(c.getSize(), a.getSize() + b.getSize());
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(c[i], 1);
  }
  for (int i = 10; i < 20; i++) {
    EXPECT_EQ(c[i], 2);
  }

}
