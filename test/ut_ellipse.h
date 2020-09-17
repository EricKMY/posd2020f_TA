#include "../src/ellipse.h"

using namespace std;
TEST(Ellipse, ConstructorNoException){
    ASSERT_NO_THROW(Ellipse(1, 1));
}

TEST(Ellipse, ExceptionForSemiMajorAxesIsZero){
    try {
        Ellipse(0, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsZero){
    try {
        Ellipse(1, 0);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMajorAxesLessThanZero){
    try {
        Ellipse(-1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesLessThanZero){
    try {
        Ellipse(1, -1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, AreaInt){
    double abs = 0.001;
    Shape* ellipse = new Ellipse(3, 4);
    ASSERT_NEAR(37.699, ellipse->area(), abs);
}

TEST(Ellipse, AreaDouble){
    double abs = 0.001;
    Shape* ellipse = new Ellipse(3.7, 4.2);
    ASSERT_NEAR(48.820, ellipse->area(), abs);
}

TEST(Ellipse, PerimeterInt){
    double abs = 0.001;
    Shape* ellipse = new Ellipse(3, 4);
    ASSERT_NEAR(21.132, ellipse->perimeter(), abs);
}

TEST(Ellipse, PerimeterDouble){
    double abs = 0.001;
    Shape* ellipse = new Ellipse(3.7, 4.2);
    ASSERT_NEAR(24.389, ellipse->perimeter(), abs);
}

TEST(Ellipse, Type){
    Shape* ellipse = new Ellipse(3, 4);
    ASSERT_EQ("Ellipse (3.000, 4.000)", ellipse->info());
}