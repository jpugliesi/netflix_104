#include "MergeSort.h"
#include <vector>
#include "gtest/gtest.h"

// The fixture for testing class.
class MergeSortTests: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	MergeSortTests()
	{
		// You can do set-up work for each test here.
		s = 100;
	}

	virtual ~MergeSortTests()
	{
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
		a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    a.push_back(4);
    a.push_back(0);

	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	//DoublingArrayList<int> * a;
  std::vector<int> a;
	int s;
};

TEST_F(MergeSortTests, Sort)
{
  std::vector<int> result = MergeSort::sort(a);
	for(int i = 0; i < 6; ++i) EXPECT_EQ(i, result.at(i));
}
//put the rest of your test cases here!
