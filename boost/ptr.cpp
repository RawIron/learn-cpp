#include <boost/any.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
using boost::shared_ptr;
using boost::scoped_ptr;

#include <string>
#include <vector>
#include <iostream>
#include <memory>
using std::string;
using std::cout;
using std::endl;
using std::auto_ptr;


void PrintIfString(const boost::any& Any) {
  if (const shared_ptr<string>* s =
    boost::any_cast<shared_ptr<string> >(&Any)) {
      cout << **s << endl;
  }
}

void testShared() {
  std::vector<boost::any> Stuff;

  shared_ptr<string> SharedString1
    (new string("Share me. By the way, Boost.any is another useful Boost library")); 
  shared_ptr<string> SharedString2(SharedString1);
  shared_ptr<int> SharedInt1(new int(42));
  shared_ptr<int> SharedInt2(SharedInt1);

  Stuff.push_back(SharedString1);
  Stuff.push_back(SharedString2);
  Stuff.push_back(SharedInt1);
  Stuff.push_back(SharedInt2);

  // Print the strings
  for_each(Stuff.begin(), Stuff.end(), PrintIfString);
  Stuff.clear();

  // The pointees of the shared_ptr's
  // will be released on leaving scope
}

void testScoped() {
    scoped_ptr<string> MyOwnString
      (new string("This is mine to keep for real!"));
    // Compiler error - there is no copy constructor.
    //scoped_ptr<string> TryingToTakeItAnyway(MyOwnString); 
}

void testAutoptrCrash() {
    auto_ptr<string> MyOwnString
      (new string("This is mine to keep!"));
    auto_ptr<string> NoItsMine(MyOwnString);
    // Boom
    //cout << *MyOwnString << endl;
}


int main() {
    testAutoptrCrash();
    testScoped();
    testShared();
}

