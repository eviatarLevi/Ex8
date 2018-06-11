#include <iostream>
#include <string>
#include <boost/type_index.hpp>
using namespace std;

class TestCase {
    
   string s;
   ostream &p;
   int testT;
   int testF;
   int count;
   public:
   TestCase(const string s,ostream &p) : s(s),p(p){testT = 0; testF = 0; count = 0;}
   template <typename T>
   TestCase check_equal(T a,T b)
   {
       count++;
       if(!(a==b)){
           testF++;
            p<< s << ": Failure in test #" << count << ": "
            << a << " should equal "<< b << "!" << endl;
       } 
       else testT++;
       return *this;
   }
   template <typename T>
   TestCase check_different(T a,T b)
   {
       count++;
       if(!(a!=b)) {
           testF++;
            p<< s << ": Failure in test #" << count << ": "
            << a << " should different "<< b << "!" << endl;
       } 
       else testT++;
       return *this;
   }
   template <typename T>
   TestCase check_output(T a,string b)
   {
       count++;
       ostringstream t;
       t << a;
       string tests = t.str();
       if(tests != b) 
       {
           testF++;
            p<< s << ": Failure in test #" << count << ": string value should be "
            << b << " but is "<< a << endl;
       } 
       else testT++;
       return *this;
   }
     template <typename T1,typename T2,typename T3>
   TestCase check_function(T1 (f),T2 a, T3 b)
   {
       count++;
       if(!(f(a)==b)){
           testF++;
           p<< s << ": Failure in test #" << count << ": Function should return " <<
            b << " but returned "<< f(a) << "!" << endl;
       }
       else testT++;
       return *this;
   } 



   void print()
   {
    p << s << ": " << testF << " failed, " << 
        testT << " passed, " << count << " total." << endl << "---" << endl;
   }


};

