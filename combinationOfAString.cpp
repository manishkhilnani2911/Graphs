/*given a string ABC -> possible combinations are A,B,C,AB,BC,ABC,AC,""*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string val = "ABC";
  vector<string> res;
  res.push_back("");
  cout<<""<<"\n";
  for (unsigned int i=0;i<val.size();i++) {
    unsigned int temp = res.size();
    for (unsigned int j=0;j<temp;j++) {
      string temp1 = res[j];
      temp1 = temp1 + val[i];
      res.push_back(temp1);
      cout<<temp1<<"\n";
    }
  }
  return 0;
}
