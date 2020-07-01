#include "TPolinomConsole\TList.h"

#include "gtest.h"



TEST(TList, can_use_InsFirst_N1)
{
	TList<int> tl;
	ASSERT_NO_THROW(tl.InsFirst(4));
}

TEST(TList, can_use_InsLast)
{
	TList<int> tl;
	ASSERT_NO_THROW(tl.InsLast(4));
}

TEST(TList, can_use_InsCurr_if_pCurr_EQ_NULL_N1)
{
	TList<int> tl;
	ASSERT_ANY_THROW(tl.InsCurr(3));
}

TEST(TList, can_use_InsFirst_N2)
{
	TList<int> tl;
	tl.InsFirst(4);
	tl.Reset();
	EXPECT_EQ(tl.GetCurrVal(), 4 );
}


TEST(TList, can_use_DelFirst)
{
	TList<int> tl;
	tl.InsFirst(4);

	ASSERT_NO_THROW(tl.DelFirst() );
}

TEST(TList, cant_DelCurr_if_size_EQ_0)
{
	TList<int> tl;
	ASSERT_ANY_THROW(tl.DelCurr() );
}

TEST(TList, cant_DelFirst_if_size_EQ_0)
{
	TList<int> tl;
	ASSERT_ANY_THROW(tl.DelFirst());
}


