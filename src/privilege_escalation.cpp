#include <iostream>
#include <string>

void root_privileged_print(std::string message, auto user){
  if (user==0xbada55){
    std::cout<<"Root: "<<message<<std::endl;
  }
  if(user == 0xdeadbeef){
    std::cout<<"Users do not have the rights to print"<<std::endl;
  }
}

void injection(){
  uint dummy = 0;
  for(int distance=0; distance<1000; distance++){
    for (auto i: {distance, -distance}){
      auto& other = *(&dummy+i);
      if(other == 0xdeadbeef){
	other = 0xbada55;
      }
    }
  }
}

int main(){
  auto user = 0xdeadbeef;
  injection();
  root_privileged_print("YOUR BASE ARE BELONG TO US", user);
  return 0;
}
