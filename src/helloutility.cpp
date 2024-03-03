#include <helloutility.h>

using namespace std;

void myPrintHelloMake() {

    vector<string> msg {"Hello", "World", "from", "C++", "VS Code", "and the C++ extension!"};

   for (const string& word : msg)
   {
      cout << word << " ";
   }
   cout << endl;
  return;
}