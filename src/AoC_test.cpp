#include "Password.h"
#include "day01.h"
#include "day02.h"
#include "day03.h"
#include "day04.h"
#include "day05.h"
#include "day06.h"
#include "day07.h"
#include "day08.h"
#include "day09.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"
#include "day15.h"
#include <gtest\gtest.h>

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

TEST(AoC_TEST, day04) {
    ASSERT_EQ(242, day04(false));
    ASSERT_EQ(186, day04(true));
}

TEST(AoC_TEST, day05) {
    ASSERT_EQ(848, day05(false));
    ASSERT_EQ(682, day05(true));
}

TEST(AoC_TEST, day06) {
    ASSERT_EQ(6532, day06(false));
    ASSERT_EQ(3427, day06(true));
}

TEST(AoC_TEST, day07) {
    ASSERT_EQ(274, day07(false));
    ASSERT_EQ(158730, day07(true));
}

TEST(AoC_TEST, day08) {
    ASSERT_EQ(1446, day08(false));
    ASSERT_EQ(1403, day08(true));
}

TEST(AoC_TEST, day09) {
    ASSERT_EQ(25918798, day09(false));
    ASSERT_EQ(3340942, day09(true));
}

TEST(AoC_TEST, day10) {
    ASSERT_EQ(1904, day10(false));
    ASSERT_EQ(10578455953408, day10(true));
}

TEST(AoC_TEST, day11) {
    ASSERT_EQ(2093, day11(false));
    ASSERT_EQ(1862, day11(true));
}

TEST(AoC_TEST, day12) {
    ASSERT_EQ(24769, day12(true));
}

TEST(AoC_TEST, day15) {
    ASSERT_EQ(1373, day15(false));
    ASSERT_EQ(112458, day15(true));
}

#ifdef AoC_RUN_TEST
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif