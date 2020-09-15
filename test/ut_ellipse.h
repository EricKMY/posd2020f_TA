#include "../src/ellipse.h"
#include "../src/utility.h"

TEST(Ellipse, ConstructorNoException){
    ASSERT_NO_THROW(Ellipse("1", 1, 1));
}

TEST(Ellipse, ExceptionForSemiMajorAxesIsZero){
    try {
        Ellipse("1", 0, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsZero){
    try {
        Ellipse("1", 1, 0);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMajorAxesLessThanZero){
    try {
        Ellipse("1", -1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesLessThanZero){
    try {
        Ellipse("1", 1, -1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, AreaInt){
    double abs = 0.0001;
    Shape* ellipse = new Ellipse("1", 3, 4);
    ASSERT_NEAR(37.6991, ellipse->area(), abs);
}

TEST(Ellipse, AreaDouble){
    double abs = 0.0001;
    Shape* ellipse = new Ellipse("1", 3.7, 4.2);
    ASSERT_NEAR(48.8203, ellipse->area(), abs);
}

TEST(Ellipse, PerimeterInt){
    double abs = 0.0001;
    Shape* ellipse = new Ellipse("1", 3, 4);
    ASSERT_NEAR(21.1327, ellipse->perimeter(), abs);
}

TEST(Ellipse, PerimeterDouble){
    double abs = 0.0001;
    Shape* ellipse = new Ellipse("1", 3.7, 4.2);
    ASSERT_NEAR(24.3893, ellipse->perimeter(), abs);
}

TEST(Ellipse, Info){
    Shape* ellipse = new Ellipse("1", 3, 4);
    ASSERT_EQ("Ellipse (3.000, 4.000)", ellipse->info());
}

TEST(Ellipse, ExceptionForAddShape){
    Shape* ellipse = new Ellipse("1", 3, 4);
    try {
        ellipse->addShape(new Ellipse("1", 3, 4));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only complex shape can add shape!", e);
    }
}

TEST(Ellipse, ExceptionForDeleteShape){
    Shape* ellipse = new Ellipse("1", 3, 4);
    try {
        ellipse->deleteShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only complex shape can delete shape!", e);
    }
}

TEST(Ellipse, ExceptionForGetShapeById){
    Shape* ellipse = new Ellipse("1", 3, 4);
    try {
        ellipse->getShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only complex shape can get shape!", e);
    }
}


TEST(Ellipse, ExceptionWhenIteratorFirst){
    Shape* ellipse = new Ellipse("1", 3, 4);
    Iterator *it = ellipse->createIterator();
    try {
        it->first();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("no child member!", e);
    }
}

TEST(Ellipse, ExceptionWhenIteratorCurrentItem){
    Shape* ellipse = new Ellipse("1", 3, 4);
    Iterator *it = ellipse->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("no child member!", e);
    }
}

TEST(Ellipse, ExceptionWhenIteratorNext){
    Shape* ellipse = new Ellipse("1", 3, 4);
    Iterator *it = ellipse->createIterator();
    try {
        it->next();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("no child member!", e);
    }
}

TEST(Ellipse, IteratorIsDone){
    Shape* ellipse = new Ellipse("1", 3, 4);
    Iterator *it = ellipse->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST(Ellipse, ExceptionForCallUtilityGetShapeById){
    Shape* ellipse = new Ellipse("1", 3, 4);
    Utility *utility = new Utility();
    try {
        utility->getShapeById(ellipse, "1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only complex shape can get shape!", e);
    }
}