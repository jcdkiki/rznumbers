#include "natural.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(NATURAL, CMP)
{
    std::stringstream input;
    input << "100 200";

    Natural n1, n2;
    input >> n1 >> n2;

    ASSERT_LT(n1, n2);
    ASSERT_LE(n1, n2);
    ASSERT_NE(n1, n2);

    ASSERT_GT(n2, n1);
    ASSERT_GE(n2, n1);
    ASSERT_NE(n2, n1);
    
    ASSERT_LE(n1, n1);
    ASSERT_GE(n1, n1);
    ASSERT_EQ(n1, n1);

    ASSERT_LE(n2, n2);
    ASSERT_GE(n2, n2);
    ASSERT_EQ(n2, n2);
}
