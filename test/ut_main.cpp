#include <gtest/gtest.h>
#include "ut_complex_shape.h"
#include "ut_rectangle.h"
#include "ut_ellipse.h"
#include "ut_triangle.h"
#include "ut_sort.h"
#include "ut_terminal.h"

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
