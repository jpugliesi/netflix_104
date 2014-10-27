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
		a = new std::vector<int>(100);
    sorted = new std::vector<int>(100);
		for(int i = s; i > 0; ++i){
      a->push_back(i);
      sorted->push_back(100-i);
    }

	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
		delete [] a;
    delete [] sorted;
		a = NULL;
	}

	// Objects declared here can be used by all tests in the test case.
	//DoublingArrayList<int> * a;
  std::vector<int>* a;
  std::vector<int>* sorted;
	int s;
};

TEST_F(MergeSortTests, Sort)
{
  std::vector<int> result = MergeSort::sort(*a);
	for(int i = 0; i < 100; ++i) EXPECT_EQ(1, result.at(i));
}
//put the rest of your test cases here!
