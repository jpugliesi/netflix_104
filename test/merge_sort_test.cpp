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
		a = NULL;
    sorted = NULL;
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
		a = new vector<int>();
    sorted = new vector<int>();
		for(int i = s; i > 0; ++i){
      a->push(i);
      sorted->push(100-i);
    }

	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
		delete a;
		a = NULL;
	}

	// Objects declared here can be used by all tests in the test case.
	//DoublingArrayList<int> * a;
  vector<int>* a;
  vector<int>* sorted;
	int s;
};

TEST_F(MergeSortTests, Sort)
{
  MergeSort::sort(a);
	for(int i = 0; i < s; ++i) EXPECT_EQ(i, a->get(i));
}
//put the rest of your test cases here!
