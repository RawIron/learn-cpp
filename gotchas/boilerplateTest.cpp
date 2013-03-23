#include "exampleClass.cpp"

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class ExampleClassTest : public CppUnit::TestFixture {
    public:
    void setup();
    void teardown();
    static CppUnit::Test* suite();
    void testOne();

    private:
    ExampleClass* d;
};

void ExampleClassTest::setup() {
    d = new ExampleClass(10000);
}
void ExampleClassTest::teardown() {
    delete d;
}
CppUnit::Test* ExampleClassTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("title");
    suite->addTest(new CppUnit::TestCaller<ExampleClassTest>(
                   "example", &ExampleClassTest::testOne));
    return suite;
}

void ExampleClassTest::testOne() {
    setup();
    d->method();
    CPPUNIT_ASSERT(d->read(12) == 12);
    teardown();
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(ExampleClassTest::suite());
    runner.run();
}

