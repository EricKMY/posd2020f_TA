#include "../src/terminal.h"

TEST(Terminal, InvalidInputNoShape) {
    try {
        Terminal("perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputShapeLowerCap) {
    try {
        Terminal("ellipse (3, 4) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputShapeNoSpace) {
    try {
        Terminal("Ellipse(3, 4) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputEllipseException) {
    try {
        Terminal("Ellipse (0, 0) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputEllipseArgumentError) {
    try {
        Terminal("Ellipse (1, 2, 3) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputRectangleException) {
    try {
        Terminal("Rectangle (0, 0) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputTriangleArgumentError) {
    try {
        Terminal("Triangle ([0,-3], [-3,0], [0,-4], [0,-4]) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputTriangleException) {
    try {
        Terminal("Triangle ([0,0], [0,0], [0,0]) perimeter dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputNoFeatureToSort) {
    try {
        Terminal("Ellipse (1, 2) dec info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputNoOrder) {
    try {
        Terminal("Ellipse (1, 2) perimeter info");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, InvalidInputNoFeatureToShow) {
    try {
        Terminal("Ellipse (1, 2) perimeter dec");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, PerimeterAscInfo) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter asc info");
    ASSERT_EQ("Triangle ([0.000,0.000], [-3.000,0.000], [0.000,-4.000])\nRectangle (3.700, 4.200)\nEllipse (3.000, 4.000)", test->showResult());
}

TEST(Terminal, PerimeterAscPerimeter) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter asc perimeter");
    ASSERT_EQ("12.000\n15.800\n21.133", test->showResult());
}

TEST(Terminal, PerimeterAscArea) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter asc area");
    ASSERT_EQ("6.000\n15.540\n37.699", test->showResult());
}

TEST(Terminal, PerimeterDecInfo) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter dec info");
    ASSERT_EQ("Ellipse (3.000, 4.000)\nRectangle (3.700, 4.200)\nTriangle ([0.000,0.000], [-3.000,0.000], [0.000,-4.000])", test->showResult());
}

TEST(Terminal, PerimeterDecPerimeter) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter dec perimeter");
    ASSERT_EQ("21.133\n15.800\n12.000", test->showResult());
}

TEST(Terminal, PerimeterDecArea) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter dec area");
    ASSERT_EQ("37.699\n15.540\n6.000", test->showResult());
}

TEST(Terminal, StringHandle) {
    Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4])\nEllipse(3, 4) perimeter dec area");
    ASSERT_EQ("37.699\n15.540\n6.000", test->showResult());

    Terminal* test1 = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nEllipse (three, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter dec area");
    ASSERT_EQ("37.699\n15.540\n6.000", test1->showResult());

    Terminal* test2 = new Terminal("Rectangle (3.7, 4.2)\nEllipse$%^(3, 4)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter dec area");
    ASSERT_EQ("37.699\n15.540\n6.000", test2->showResult());

    Terminal* test3 = new Terminal("\nellipse (3, 4)\nRectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4]) perimeter dec area");
    ASSERT_EQ("37.699\n15.540\n6.000", test3->showResult());

    Terminal* test4 = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,0], [-3,0], [0,-4])\nEllipse (3, 4)@#$%^Ellipse (3, 4) perimeter dec area");
    ASSERT_EQ("37.699\n15.540\n6.000", test4->showResult());
}