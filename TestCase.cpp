#include "TestCase.hpp"

TestCase::TestCase(const string s, ostream &p) : s(s), p(p)
{
    testT = 0;
    testF = 0;
    count = 0;
}
void TestCase::print()
{
    p << s << ": " << testF << " failed, " << testT << " passed, " << count << " total." << endl
      << "---" << endl;
}
