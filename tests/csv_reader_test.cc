#include <iostream>
#include <custom_cpp_utilities/CsvReader.h>

using namespace std;
using namespace custom_cpp_utilities;

int main() {

  CsvReader reader("test.csv", "|");
  cout << "File columns: spmode, run, scale, weight" << endl;
  cout << "Values by row: " << endl;
  while (reader.next()) {
    cout << reader.get("spmode") << ", ";
    cout << reader.get("run") << ", ";
    cout << reader.get("scale") << ", ";
    cout << reader.get("weight") << endl;
  }

  return 0;
}
