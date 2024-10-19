#include "split.h"
#include <sstream>

using namespace std;
namespace homework {
vector<string> split(const string &str) {
  istringstream ss(str);
  vector<string> result;
  for (string s; ss >> s;) {
    result.push_back(s);
  }
  return result;
}
} // namespace homework
