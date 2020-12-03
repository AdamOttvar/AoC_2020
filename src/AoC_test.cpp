#include <gtest\gtest.h>
#include "day01.h"
#include "day02.h"
#include "day03.h"
#include "Password.h"

TEST(AoC_TEST, day01) {
    ASSERT_EQ(1019571, day01(false));
    ASSERT_EQ(100655544, day01(true));
}

TEST(AoC_TEST, day02) {
    ASSERT_EQ(582, day02(false));
    ASSERT_EQ(729, day02(true));
}

TEST(AoC_TEST, password) {
    ASSERT_TRUE(Password().validatePassword(false));
    ASSERT_TRUE(Password(1, 3, 'a', "abcde").validatePassword(false));
    ASSERT_FALSE(Password(1, 3, 'b', "cdefg").validatePassword(false));
    ASSERT_TRUE(Password(1, 9, 'c', "ccccccccc").validatePassword(false));
    ASSERT_TRUE(Password().validatePassword(true));
    ASSERT_TRUE(Password(1, 3, 'a', "abcde").validatePassword(true));
    ASSERT_FALSE(Password(1, 3, 'b', "cdefg").validatePassword(true));
    ASSERT_FALSE(Password(1, 9, 'c', "ccccccccc").validatePassword(true));
}

TEST(AoC_TEST, day03) {
    ASSERT_EQ(242, day03(false));
    ASSERT_EQ(2265549792, day03(true));
}

#ifdef AoC_RUN_TEST
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif