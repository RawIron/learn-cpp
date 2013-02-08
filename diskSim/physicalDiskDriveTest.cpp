#include "physicalDiskDrive.cpp"

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>


class PhysicalDiskDriveTest : public CppUnit::TestFixture {
    public:
    void setup();
    void teardown();
    static CppUnit::Test* suite();
    void readTest();

    private:
    PhysicalDiskDrive* d;
};

void PhysicalDiskDriveTest::setup() {
    d = new PhysicalDiskDrive(10000);
}
void PhysicalDiskDriveTest::teardown() {
    delete d;
}
CppUnit::Test* PhysicalDiskDriveTest::suite() {
    CppUnit::TestSuite* suite = new CppUnit::TestSuite("drive");
    suite->addTest(new CppUnit::TestCaller<PhysicalDiskDriveTest>(
                   "simple", &PhysicalDiskDriveTest::readTest));
    return suite;
}

void PhysicalDiskDriveTest::readTest() {
    setup();
    Platter *p = new Platter();
    p->randomInit();
    d->dd(p);
    CPPUNIT_ASSERT(d->read(12) == p->read(12));
    teardown();
}



int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(PhysicalDiskDriveTest::suite());
    runner.run();
}

