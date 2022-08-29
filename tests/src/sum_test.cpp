#include <gtest/gtest.h>
#include <lib.hpp>

TEST(Foo, Sum)
{
  auto grades = Grades();
  EXPECT_EQ(15, sum(grades));
}