#include <vector>
#include "Queue.h"
#include "gtest/gtest.h"

// The fixture for testing class.
class QueueTests: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	QueueTests()
	{
		// You can do set-up work for each test here.
	}

	virtual ~QueueTests()
	{
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
  Queue<int> q;
};

TEST_F(QueueTests, BasicCase)
{
  for(int i = 1; i < 7; i++){
    EXPECT_EQ(i, q.peekFront());
    q.dequeue();
  }
}
//put the rest of your test cases here!
