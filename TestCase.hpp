#include <iostream>
#include <string>
using namespace std;

class TestCase {
    
   string s;
   ostream &p;
   int testT;
   int testF;
   public:
   TestCase(const string s,ostream &p) : s(s),p(p){testT = 0; testF = 0;}
   template <typename T>
   TestCase check_equal(T a,T b)
   {
       if(!(a==b)) p<<"erorr equal"<<endl;
       return *this;
   }
   template <typename T>
   TestCase check_different(T a,T b)
   {
       if(!(a!=b)) p<<"erorr different"<<endl;
       return *this;
   }
   template <typename T>
   TestCase check_output(T a,string b)
   {
       ostringstream t;
       t << a;
       string tests = t.str();
       if(tests != b) p << "erorr output" <<endl; 
       return *this;
   }


   void print()
   {

   }


};

