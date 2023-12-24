#include "../TQueue/TQueue.h"

#include "gtest.h"


TEST(TQueue, can_create_queue_with_pozitive_length)
{
	ASSERT_NO_THROW(TQueue<int> s(3));
}
TEST(TQueue, can_get_count)
{
	TQueue<int> s(2);
	EXPECT_EQ(0, s.GetCount());
}
TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> s(-8));
}
TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> a(3);
	ASSERT_NO_THROW(TQueue<int> s(a));
}
TEST(TQueue, can_assign_queues)
{
	TQueue<int> a(1);
	TQueue<int> s(2);
	ASSERT_NO_THROW(a = s);
}

TEST(TQueue, assign_operator_change_size)
{
	TQueue<int> a(7);
	TQueue<int> s(9);
	a = s;
	EXPECT_EQ(9, a.Size());
}
TEST(TQueue, can_use_front_and_back)
{
	TQueue<int> q(4);
	q.Push(1);
	int b1, b2;
	ASSERT_NO_THROW(b1 = q.Front());
	ASSERT_NO_THROW(b2 = q.Back());
	EXPECT_EQ(b1, b2);
}
TEST(TQueue, assigned_queues_are_equal)
{
	TQueue<int> a(2);
	TQueue<int> s(3);
	a = s;
	for (int i = 0; i < 3; i++)
	{
		a.Push(i);
		s.Push(i);
	}
	EXPECT_EQ(a.Size(), s.Size());
	EXPECT_EQ(a.GetFinish(), s.GetFinish());
	EXPECT_EQ(a.GetStart(), s.GetStart());
	EXPECT_EQ(a.GetCount(), s.GetCount());
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(a.Pop(), s.Pop());
	}
}
TEST(TQueue, assigned_queues_have_different_memories)
{
	TQueue<int> a(2);
	TQueue<int> s(3);
	a = s;
	a.Push(1);
	s.Push(2);
	EXPECT_NE(a.Pop(), s.Pop());
}
TEST(TQueue, copied_queue_has_own_memory)
{
	TQueue<int> a(4);
	TQueue<int> s(a);
	s.Push(1);
	ASSERT_NO_THROW(a.IsEmpty());
	ASSERT_NO_THROW(s.IsEmpty());
	EXPECT_NE(a.IsEmpty(), s.IsEmpty());
}
TEST(TQueue, can_push_elem_in_empty_queue)
{
	TQueue<int> a(5);
	ASSERT_TRUE(a.IsEmpty());
	ASSERT_NO_THROW(a.Push(1));
}
TEST(TQueue, cant_push_elem_in_full_queue)
{
	TQueue<int> a(1);
	a.Push(1);
	ASSERT_ANY_THROW(a.Push(1));
}
TEST(TQueue, can_pop_elem_from_not_empty_queue)
{
	TQueue<int> a(1);
	a.Push(1);
	ASSERT_NO_THROW(a.Pop());
}
TEST(TQueue, cant_pop_elem_from_empty_queue)
{
	TQueue<int> a(5);
	ASSERT_ANY_THROW(a.Pop());
}
TEST(TQueue, method_Size_is_correct)
{
	TQueue<int> a(10);
	int i = a.Size();
	EXPECT_EQ(i, a.Size());
}
TEST(TQueue, method_GetStart_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	int i = a.GetStart();
	EXPECT_EQ(i, a.GetStart());
}
TEST(TQueue, method_GetFinish_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	int i = a.GetFinish();
	EXPECT_EQ(i, a.GetFinish());
}
TEST(TQueue, method_GetCount_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	int i = a.GetCount();
	EXPECT_EQ(i, a.GetCount());
}
TEST(TQueue, method_Top_is_correct)
{
	TQueue<int> a(10);
	a.Push(1);
	EXPECT_EQ(a.Pop(), a.Front());
}

