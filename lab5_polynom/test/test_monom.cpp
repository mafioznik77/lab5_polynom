#include "gtest.h"
#include "../lab5_polynom/Tmonom.h"

TEST(TMonom, compare_equal_monoms_return_true) {
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMonom, compare_monoms_return_false) {
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = 4;
	m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(false, m1 == m2);
}

TEST(TMonom, no_compare_monoms_return_true) {
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = 4;
	m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(true, m1 != m2);
}

TEST(TMonom, no_compare_equal_monoms_return_false) {
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(false, m1 != m2);
}

TEST(TMonom, first_monom_bigger_then_second_monom_return_true)
{
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = 2;
	m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(true, m1 > m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = 5;
	m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(true, m1 > m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = 6;
	m2.PowZ = 4;
	EXPECT_EQ(true, m1 > m2);
}

TEST(TMonom, first_monom_bigger_then_second_monom_return_false)
{
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = 1;
	m2.PowX = 2;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(false, m1 > m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = 2;
	m2.PowY = 5;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(false, m1 > m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = 2;
	m2.PowZ = 4;
	EXPECT_EQ(false, m1 > m2);
}

TEST(TMonom, first_monom_smaller_then_second_monom_return_true)
{
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = 1;
	m2.PowX = 2;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(true, m1 < m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = 2;
	m2.PowY = 5;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(true, m1 < m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = 2;
	m2.PowZ = 4;
	EXPECT_EQ(true, m1 < m2);
}
TEST(TMonom, first_monom_smaller_then_second_monom_return_false)
{
	TMonom m1, m2;
	m1.coeff = m2.coeff = 3;
	m1.PowX = 2;
	m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(false, m1 < m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = 5;
	m2.PowY = 2;
	m1.PowZ = m2.PowZ = 4;
	EXPECT_EQ(false, m1 < m2);
	m1.PowX = m2.PowX = 1;
	m1.PowY = m2.PowY = 2;
	m1.PowZ = 6;
	m2.PowZ = 4;
	EXPECT_EQ(false, m1 < m2);
}