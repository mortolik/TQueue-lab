#include "../TStack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, can_get_size)
{
  TStack<int> s(10);

  EXPECT_EQ(s.Size(), 10);
}

TEST(TStack, new_stack_is_empty)
{
  TStack<int> s(5);

  EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, can_assign_stack)
{
	TStack<int> s(10);
	

	s.Push(4);
	s.Push(5);

	TStack<int> s1(s);

	int count = 0;
	while (!s.IsEmpty() && !s1.IsEmpty()) {
		EXPECT_EQ(s.Pop(), s1.Pop());
		count++;
	}
	EXPECT_EQ(2, count);

}


TEST(TStack, cant_push_if_stack_is_stack)
{
  TStack<int> s(10);
  for (int i = 0; i < s.Size(); i++)
	  s.Push(i);
  ASSERT_ANY_THROW(s.Push(1));
}

TEST(TStack, cant_pop_if_stack_is_empty)
{
	TStack<int> s(10);
	
	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> s(5);

	s.Push(1);
	s.Push(2);

	EXPECT_EQ(s.IsEmpty(), false);

	s.Clear();

	EXPECT_EQ(s.IsEmpty(), true);
}


