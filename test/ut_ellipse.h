#include "../src/ellipse.h"

using namespace std;

TEST(Ellipse, ConstructorNoException){
    ASSERT_NO_THROW(Ellipse("1", 1, 1));
}

TEST(Ellipse, ExceptionForSemiMajorAxesIsZero){
    try {
        Ellipse("1", 0, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsZero){
    try {
        Ellipse("1", 1, 0);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMajorAxesLessThanZero){
    try {
        Ellipse("1", -1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesLessThanZero){
    try {
        Ellipse("1", 1, -1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, AreaInt){
    double abs = 0.001;
    Shape* ellipse = new Ellipse("1", 4, 3);
    ASSERT_NEAR(37.6991, ellipse->area(), abs);
}

TEST(Ellipse, AreaDouble){
    double abs = 0.001;
    Shape* ellipse = new Ellipse("1", 4.2, 3.7);
    ASSERT_NEAR(48.820, ellipse->area(), abs);
}

TEST(Ellipse, PerimeterInt){
    double abs = 0.001;
    Shape* ellipse = new Ellipse("1", 4, 3);
    ASSERT_NEAR(22.849, ellipse->perimeter(), abs);
}

TEST(Ellipse, PerimeterDouble){
    double abs = 0.001;
    Shape* ellipse = new Ellipse("1", 4.2, 3.7);
    ASSERT_NEAR(25.247, ellipse->perimeter(), abs);
}

TEST(Ellipse, Info){
    Shape* ellipse = new Ellipse("1", 4, 3);
    ASSERT_EQ("Ellipse (4.000, 3.000)", ellipse->info());
}

TEST(Ellipse, DefaultColor){
    Shape* ellipse = new Ellipse("1", 4, 3);
    ASSERT_EQ("white", ellipse->color());
}

TEST(Ellipse, RedColor){
    Shape* ellipse = new Ellipse("1", 4, 3, "red");
    ASSERT_EQ("red", ellipse->color());
}

TEST(Ellipse, ExceptionForAddShape){
    Shape* ellipse = new Ellipse("1", 4, 3);
    try {
        ellipse->addShape(new Ellipse("1", 4, 3));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST(Ellipse, ExceptionForDeleteShape){
    Shape* ellipse = new Ellipse("1", 4, 3);
    try {
        ellipse->deleteShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST(Ellipse, ExceptionForGetShapeById){
    Shape* ellipse = new Ellipse("1", 4, 3);
    try {
        ellipse->getShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}