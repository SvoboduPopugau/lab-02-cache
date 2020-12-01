// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "cpu_tester.hpp"

TEST(Example, EmptyTest) {
    std::vector<int> e_vec;
    CPU_tester example(e_vec);
    example.completeAllTests();
    EXPECT_TRUE(true);
}
