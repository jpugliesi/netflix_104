#include "Set.h"
#include "gtest/gtest.h"

// The fixture for testing class.
class SetOperationsTests: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	SetOperationsTests()
	{
		// You can do set-up work for each test here.
	}

	virtual ~SetOperationsTests()
	{
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
    for(int i = 0; i < 10; i++){
      set1.add(i);
    }
    for(int i = 5; i < 15; i++){  
      set2.add(i);
    }

	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
  Set<int> set1;
  Set<int> set2;
  
};

TEST_F(SetOperationsTests, Union)
{
  set1 = set1.setUnion(set2);
  for(int i = 0; i < 15; i++){
    EXPECT_TRUE(set1.contains(i));
  }
}
//put the rest of your test cases here!

TEST_F(SetOperationsTests, Intersection){

  set1 = set1.setIntersection(set2);
  for(int i = 0; i < 5; i++){
    EXPECT_FALSE(set1.contains(i));
  }
  
  for(int i = 5; i < 10; i++){
    EXPECT_TRUE(set1.contains(i));
  }
  for(int i = 10; i < 15; i++){
    EXPECT_FALSE(set1.contains(i));
  }
}

