#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8.0);
}

TEST(addTest, simpleAddition) {
  Op* val1 = new Op(1);  
  Op* val2 = new Op(5);
  Add* test = new Add(val1, val2);
  EXPECT_EQ(test->evaluate(), 6);
  EXPECT_EQ(test->stringify(), "1.000000+5.000000");
}

TEST(addTest, OneZero) {
  Op* val1 = new Op(0);
  Op* val2 = new Op(3);
  Add* test = new Add(val1, val2);
  EXPECT_EQ(test->evaluate(), 3);
  EXPECT_EQ(test->stringify(), "0.000000+3.000000");
}

TEST(addTest, LargeNums) {
  Op* val1 = new Op(100);
  Op* val2 = new Op(300);
  Add* test = new Add(val1, val2);
  EXPECT_EQ(test->evaluate(), 400);
  EXPECT_EQ(test->stringify(), "100.000000+300.000000");
}

TEST(subTest, simpleSubtraction) {
  Op* val1 = new Op(5);
  Op* val2 = new Op(1);
  Sub* test = new Sub(val1, val2);
  EXPECT_EQ(test->evaluate(), 4);
  EXPECT_EQ(test->stringify(), "5.000000-1.000000");
}

TEST(subTest, negativeAnswer) {
  Op* val1 = new Op(1);
  Op* val2 = new Op(5);
  Sub* test = new Sub(val1, val2);
  EXPECT_EQ(test->evaluate(), -4);
  EXPECT_EQ(test->stringify(), "1.000000-5.000000");
}

TEST(subTest, largeNums) {
  Op* val1 = new Op(300);
  Op* val2 = new Op(299);
  Sub* test = new Sub(val1, val2);
  EXPECT_EQ(test->evaluate(), 1);
  EXPECT_EQ(test->stringify(), "300.000000-299.000000");
}

TEST(powTest, oneZero) {
  Op* val1 = new Op(5);
  Op* val2 = new Op(0);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 1);
  EXPECT_EQ(test->stringify(), "5.000000**0.000000");
}

TEST(powTest, simpleExponent) {
  Op* val1 = new Op(5);
  Op* val2 = new Op(2);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 25);
  EXPECT_EQ(test->stringify(), "5.000000**2.000000");
}

TEST(powTest, doubleZero) {
  Op* val1 = new Op(0);
  Op* val2 = new Op(1);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 0);
  EXPECT_EQ(test->stringify(), "0.000000**1.000000");
}

TEST(powTest, negativeNums) {
  Op* val1 = new Op(-5);
  Op* val2 = new Op(2);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 25);
  EXPECT_EQ(test->stringify(), "-5.000000**2.000000");
}

TEST(powTest, largeNums) {
  Op* val1 = new Op(10);
  Op* val2 = new Op(5);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 100000);
  EXPECT_EQ(test->stringify(), "10.000000**5.000000");
}

#endif //__OP_TEST_HPP__
