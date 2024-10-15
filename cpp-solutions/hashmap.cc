#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main(void)
{
  std::vector<std::string> v = {"misha", "dima", "vanya", "kolya"};
  std::unordered_map<std::string, int> map;

  for (auto name: v) {
    std::unordered_map<std::string, int>::iterator it = map.find("dima");
    if (it != map.end()) {
      map.insert( {"dima", 0} );
    }
  }

  return 0;
}
