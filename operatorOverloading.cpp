/*Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .

The default constructor of the class should initialize , , and  to .

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's  and  to length, breadth and height.

The copy constructor BoxBox ) should set  and  to 's  and , respectively.

Apart from the above, the class should have  functions:

int getLength() - Return box's length
int getBreadth() - Return box's breadth
int getHeight() - Return box's height
long long CalculateVolume() - Return the volume of the box
Overload the operator  for the class Box. Box   Box  if:

 < 
 <  and ==
 <  and == and ==
Overload operator  for the class Box(). 
If  is an object of class Box:

 should print ,  and  on a single line separated by spaces.

Constraints

 
Two boxes being compared using the  operator will not have all three dimensions equal.*/
#include<bits/stdc++.h>

using namespace std;
class Box {
  int l,b,h;
  public:
  Box() : l(0), b(0), h(0) {}
  Box(int le, int br, int he) :l(le), b(br), h(he) {}
  Box (const Box& B) {
    //cout<<"Assigning::"<<B.l<<" "<<B.h
    l = B.l;
    b = B.b;
    h = B.h;
  }
  bool operator<(const Box& B) {
    if (this->l < B.l) {
      return true;
    } else if (this->l == B.l) {
      if (this->b < B.b) {
        return true;
      }
    } else if (this->l == B.l && this->b == B.b) {
      if (this->h < B.h) {
        return true;
      }
    }
    return false;
  }
    int getLength() {
      return l;
    }
    int getBreadth() {
      return b;
    }
    int getHeight() {
      return h;
    }
    long long CalculateVolume() {
      //cout<<l<<" "<<b<<" "<<h<<"\n";
      //cout<<l*b*h<<"\n";
      //long long res = l*b*h;
      return 1LL*l*b*h;
    }
};
ostream& operator<< (ostream& out, Box& B) {
  out << B.getLength() << " "<<B.getBreadth()<< " "<<B.getHeight();
  //cout<<out.str();
  return out;
}
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


