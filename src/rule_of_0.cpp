
#include <string>
#include <vector>

class Person {
public:
  std::string name;
  int age;
  std::vector<std::string> hobbies;
};

int main() {
  Person p1{"Alice", 30, {"reading", "hiking"}};
  Person p2 = p1; // Compiler-generated copy constructor
  p2.name = "Bob";
  p2.hobbies.push_back("swimming");
}
