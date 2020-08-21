#include <gtest/gtest.h>
#include "../test/ut_ellipse.h"
#include "../test/ut_rectangle.h"
#include "../test/ut_triangle.h"
#include "../test/ut_sort.h"
#include "../test/ut_terminal.h"

int main(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
