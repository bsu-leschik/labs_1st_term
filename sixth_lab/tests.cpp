#include "CorrectFraction.h"
#include "gtest/gtest.h"

CorrectFraction frac(180,10260);
CorrectFraction usable_frac1(54,99);
CorrectFraction usable_frac2(2,198);

TEST(getNumerator, basic){
    ASSERT_EQ(frac.getNumerator(), 180);
}

TEST(getDenumerator, basic){
    ASSERT_EQ(frac.getDenominator(), 10260);
}

TEST(cut, basic){
    frac.cut();
    ASSERT_EQ(frac.getNumerator(), 1);
    ASSERT_EQ(frac.getDenominator(), 57);
}

TEST(sum, basic){
    ASSERT_TRUE(CorrectFraction::sum(usable_frac1, usable_frac2).getNumerator() == 5 &&
                CorrectFraction::sum(usable_frac1, usable_frac2).getDenominator() == 9);
}

TEST(multiply, basic){
    ASSERT_TRUE(CorrectFraction::multiply(usable_frac1, usable_frac2).getNumerator() == 2 &&
                CorrectFraction::multiply(usable_frac1, usable_frac2).getDenominator() == 363);
}

TEST(divide, basic){
    ASSERT_TRUE(CorrectFraction::divide(usable_frac1, usable_frac2).getNumerator() == 54 &&
                CorrectFraction::divide(usable_frac1, usable_frac2).getDenominator() == 1);
}