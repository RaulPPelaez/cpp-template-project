#include "my_library.h"
#include<iostream>

// This file can contain arbitrary definitions that might be needed by the library.
// However, an user of the library (who includes my_library.h) will not see these definitions.
namespace detail{
  //It is a sensible design choice to hide internal functions and variables in a namespace called detail.

  void some_internal_function(){
    std::cout << "This is an internal function" << std::endl;
  }

}

//Now we define the functions that are declared in my_library.h
namespace my_library{

  void very_cool_function(){
    std::cout << "This is a very cool function" << std::endl;
    std::cout << "It uses an internal function, which prints:" << std::endl;
    detail::some_internal_function();
  }

  double add(double a, double b){
    return a+b;
  }

}
