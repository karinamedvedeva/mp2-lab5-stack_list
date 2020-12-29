#include "gtest.h"
#include "../mp2-lab5-list/Stack.h"


TEST(Stack, can_create_stack_with_positive_size)
{
    ASSERT_NO_THROW(Stack <int> bf);
}

TEST(Stack, can_create_copied_stack)
{
	Stack<int> bf;

	ASSERT_NO_THROW(Stack<int> bf1(bf));
}

TEST(Stack, copied_stack_is_equal_to_source_one)
{
	Stack <int> bf1, bf2;
	
	EXPECT_EQ(bf1, bf2);
}

TEST(Stack, can_put_element)
{
	Stack<int> bf;
	ASSERT_NO_THROW(bf.Push(15));
	EXPECT_EQ(15, bf.Top());
}

TEST(Stack, can_assign_stacks)
{
	Stack <int> bf1, bf2;
	bf1.Push(1);
	bf1.Push(2);
	bf2.Push(3);
	ASSERT_NO_THROW(bf2 = bf1);
	EXPECT_EQ(bf1.Pop(), bf2.Pop());
}

TEST(Stack, compare_equal_stacks_return_true)
{
	Stack <int> bf1;
	bf1.Push(1);
	bf1.Push(2);
	bf1.Push(3);
	Stack <int> bf2;
	bf2.Push(1);
	bf2.Push(2);
	bf2.Push(3);
	EXPECT_EQ(1, bf1 == bf2);
}

TEST(Stack, compare_stack_with_itself_return_true)
{
	Stack <int> bf;
	
	EXPECT_EQ(1, bf == bf);
}

TEST(Stack, stacks_with_different_elements_are_not_equal)
{
	Stack <int> bf1, bf2;
	bf1.Push(1);
	bf1.Push(2);
	bf1.Push(3);
	bf2.Push(5);
	bf2.Push(6);
	bf2.Push(7);
	EXPECT_EQ(1, bf1 != bf2);
}

TEST(Stack, can_put_out_of_not_empty_stack)
{
	Stack<int>bf;
	bf.Push(2);
	ASSERT_NO_THROW(bf.Pop());
}

TEST(Stack, cant_put_out_of_empty_stack)
{
	Stack<int>bf;
	ASSERT_ANY_THROW(bf.Pop());
}

TEST(Stack, empty_stack_return_true)
{
	Stack <int> bf;
	EXPECT_EQ(1, bf.Empty());
}

TEST(Stack, can_check_that_stack_is_empty)
{
	Stack <int> bf;
	ASSERT_NO_THROW(bf.Empty());
}

TEST(Stack, can_put_in_not_full_stack)
{
	Stack<int>bf;
	bf.Push(1);
	ASSERT_NO_THROW(bf.Push(2));
}

TEST(Stack, full_stack_return_true)
{
	Stack<int>bf;
	bf.Push(2);
	EXPECT_EQ(1, bf.Full());
}

TEST(Stack, can_check_that_stack_is_full)
{
	Stack<int>bf;
	ASSERT_NO_THROW(bf.Full());
}

TEST(Stack, can_return_the_top)
{
	Stack<int>bf;
	bf.Push(2);
	ASSERT_NO_THROW(bf.Top());
}

TEST(Stack, cant_return_the_top_of_empty_stack)
{
	Stack<int>bf;
	bf.Empty();
	ASSERT_ANY_THROW(bf.Top());
}