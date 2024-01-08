#include <gtest/gtest.h>
#include <cmath>
#include "quadratic_equation.h"

TEST(EquationTest, b_c_zero)
{
    roots ans = quadr_eq(5,0,0);
    EXPECT_EQ(ans.x1, 0);
    EXPECT_EQ(ans.x2, 0);
}

TEST(EquationTest, c_zero)
{
    roots ans = quadr_eq(0.25,-4.4,0);
    EXPECT_EQ(ans.x1, 17.6);
    EXPECT_EQ(ans.x2, 0);
}

TEST(EquationTest, b_zero)
{
    roots ans = quadr_eq(3,0,-3);
    EXPECT_EQ(ans.x1, 1);
    EXPECT_EQ(ans.x2, -1);
}

TEST(EquationTest, with_nil_and_throw) {

    ASSERT_THROW(quadr_eq(3,0,3), std::overflow_error);
}

TEST(EquationTest, full_eq_roots)
{
    roots ans = quadr_eq(1, -6, 9);
    EXPECT_EQ(ans.x1, 3);
    EXPECT_EQ(ans.x2, 3);
}

TEST(EquationTest, full)
{
    roots ans = quadr_eq(2, -1, -15);
    EXPECT_EQ(ans.x1, 3);
    EXPECT_EQ(ans.x2, -2.5);
}

TEST(EquationTest, full_no_roots) {
    ASSERT_THROW(quadr_eq(3, 1, 2), std::overflow_error);
}