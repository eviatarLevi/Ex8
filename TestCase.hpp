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
   template <typename T>
   TestCase check_function(int (f)(T),T a, T b)
   {
       return *this;
   } 
    template <typename T1,typename T2>
   TestCase check_function(int (f)(T2),T2 a, T1 b)
   {
       return *this;
   } 
     template <typename T1,typename T2,typename T3>
   TestCase check_function(int (f)(const T2),T3 a, T1 b)
   {
       return *this;
   } 
      template <typename T1,typename T2,typename T3>
   TestCase check_function( T2 f,T3 a, T1 b)
   {
       return *this;
   } 


   void print()
   {

   }


};

