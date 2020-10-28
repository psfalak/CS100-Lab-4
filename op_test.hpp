#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "op.hpp"
#include "gtest/gtest.h" 
#include "rand.hpp"
#include <stdlib.h>
#include <string> 

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


#endif //__OP_TEST_HPP__
