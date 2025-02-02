#include "app1/basic.hpp"
#include <gtest/gtest.h>

TEST(App1Test, SumAddsTwoInts) {
  EXPECT_EQ(4, app1::Add(2, 2));
}

TEST(App1Test, SubtractsTwoInts) {
  EXPECT_EQ(6, app1::Subtract(8, 2));
}
