#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "op.hpp"
#include "gtest/gtest.h" 
#include "rand.hpp"
#include <stdlib.h>
#include <string> 
#include "mult.hpp" 
#include "div.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ("8.000000", test->stringify());
    EXPECT_EQ(test->evaluate(), 8); 
}

TEST(OpTest, OpEvaluateNeg) {
    Op* test = new Op(-8);
    EXPECT_EQ("-8.000000", test->stringify());
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ("0.000000", test->stringify());
    EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(OpTest, EvalRand){
    Rand* test = new Rand();
    srand(0);  
    int val = rand() % 100;
    std::string str = std::to_string(val);
    str+= ".000000";
    EXPECT_EQ(str, test->stringify()); 
    EXPECT_EQ(test->evaluate(), val); 
}

TEST(OpTest, EvalMult){
    Op* one = new Op(1); 
    Op* two = new Op(2); 
    Mult* test = new Mult(one, two); 
    EXPECT_EQ(test->evaluate(), 2); 
    EXPECT_EQ("1.000000 * 2.000000", test->stringify());
}

TEST(OpTest, EvalMultNeg){
    Op* one = new Op(-5);
    Op* two = new Op(2);
    Mult* test = new Mult(one, two);
    EXPECT_EQ(test->evaluate(), -10);
    EXPECT_EQ("-5.000000 * 2.000000", test->stringify());
}

TEST(OpTest, EvalMultZero){
    Op* one = new Op(0);
    Op* two = new Op(2);
    Mult* test = new Mult(one, two);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ("0.000000 * 2.000000", test->stringify());
}

TEST(OpTest, EvalDivWhole){
    Op* one = new Op(4);
    Op* two = new Op(2);
    Div* test = new Div(one, two);
    EXPECT_EQ(test->evaluate(), 2);
    EXPECT_EQ("4.000000 / 2.000000", test->stringify());
}

TEST(OpTest, EvalDivNeg){
    Op* one = new Op(-4);
    Op* two = new Op(2);
    Div* test = new Div(one, two);
    EXPECT_EQ(test->evaluate(), -2);
    EXPECT_EQ("-4.000000 / 2.000000", test->stringify());
}

TEST(OpTest, EvalDivZero){
    Op* one = new Op(-4);
    Op* two = new Op(0);
    Div* test = new Div(one, two);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ("-4.000000 / 0.000000", test->stringify());
}

TEST(OpTest, EvalDivMult){
    Op* num1 = new Op(2); 
    Op* num2 = new Op(8); 
    Op* num3 = new Op(4); 
    Mult* two = new Mult(num1, num2);
    Div* test = new Div(two, num3);
    EXPECT_EQ(test->evaluate(), 4);
    EXPECT_EQ("2.000000 * 8.000000 / 4.000000", test->stringify());
}

TEST(OpTest, EvalDivMultNeg){
    Op* num1 = new Op(2);
    Op* num2 = new Op(-8);
    Op* num3 = new Op(4);
    Mult* two = new Mult(num1, num2);
    Div* test = new Div(two, num3);
    EXPECT_EQ(test->evaluate(), -4);
    EXPECT_EQ("2.000000 * -8.000000 / 4.000000", test->stringify());
}

#endif //__OP_TEST_HPP__
