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

    set3.add('q');
    set3.add('r');
    set3.add('s');
    set3.add('z');
    set3.add('y');
    set3.add('x');
    
    set4.add('a');
    set4.add('b');
    set4.add('c');
    set4.add('x');
    set4.add('y');
    set4.add('z');

    setA.add("Chris");
    setA.add("Linda");
    setA.add("Nick");
    setA.add("Matthew");
    setA.add("Vincent");
    
    setB.add("Griffin");
    setB.add("Willy");
    setB.add("Taylor");
    setB.add("Nick");
    setB.add("Vincent");
    setB.add("Matthew");


	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
  Set<int> set1;
  Set<int> set2;
  Set<char> set3;
  Set<char> set4;
  Set<std::string> setA;
  Set<std::string> setB;
  
};

TEST_F(SetOperationsTests, IntUnion)
{
  set1 = set1.setUnion(set2);
  for(int i = 0; i < 15; i++){
    EXPECT_TRUE(set1.contains(i));
  }
}
//put the rest of your test cases here!

TEST_F(SetOperationsTests, IntIntersection){

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

TEST_F(SetOperationsTests, CharUnion){

  Set<char> unionSet = set3.setUnion(set4);
  EXPECT_TRUE(unionSet.contains('a'));
  EXPECT_TRUE(unionSet.contains('b'));
  EXPECT_TRUE(unionSet.contains('c'));
  EXPECT_TRUE(unionSet.contains('q'));
  EXPECT_TRUE(unionSet.contains('r'));
  EXPECT_TRUE(unionSet.contains('s'));
  EXPECT_TRUE(unionSet.contains('x'));
  EXPECT_TRUE(unionSet.contains('y'));
  EXPECT_TRUE(unionSet.contains('z'));
  EXPECT_FALSE(unionSet.contains('j'));
  EXPECT_FALSE(unionSet.contains('k'));
  EXPECT_FALSE(unionSet.contains('l'));

}

TEST_F(SetOperationsTests, CharIntersection){

  Set<char> intersectionSet = set3.setIntersection(set4);
  EXPECT_FALSE(intersectionSet.contains('a'));
  EXPECT_FALSE(intersectionSet.contains('b'));
  EXPECT_FALSE(intersectionSet.contains('c'));
  EXPECT_TRUE(intersectionSet.contains('x'));
  EXPECT_TRUE(intersectionSet.contains('y'));
  EXPECT_TRUE(intersectionSet.contains('z'));
  EXPECT_FALSE(intersectionSet.contains('q'));
  EXPECT_FALSE(intersectionSet.contains('r'));
  EXPECT_FALSE(intersectionSet.contains('s'));
}

TEST_F(SetOperationsTests, StringUnion){
  Set<std::string> unionSet = setA.setUnion(setB);
  EXPECT_TRUE(unionSet.contains("Vincent"));
  EXPECT_TRUE(unionSet.contains("Nick"));
  EXPECT_TRUE(unionSet.contains("Matthew"));
  EXPECT_TRUE(unionSet.contains("Griffin"));
  EXPECT_TRUE(unionSet.contains("Willy"));
  EXPECT_TRUE(unionSet.contains("Taylor"));
  EXPECT_TRUE(unionSet.contains("Chris"));
  EXPECT_TRUE(unionSet.contains("Linda"));
  EXPECT_FALSE(unionSet.contains("Joan"));
  EXPECT_FALSE(unionSet.contains("Larry"));
  EXPECT_FALSE(unionSet.contains("Kyle"));

}


TEST_F(SetOperationsTests, StringIntersection){
  Set<std::string> intersectionSet = setA.setIntersection(setB);
  EXPECT_TRUE(intersectionSet.contains("Vincent"));
  EXPECT_TRUE(intersectionSet.contains("Nick"));
  EXPECT_TRUE(intersectionSet.contains("Matthew"));
  EXPECT_FALSE(intersectionSet.contains("Griffin"));
  EXPECT_FALSE(intersectionSet.contains("Willy"));
  EXPECT_FALSE(intersectionSet.contains("Taylor"));
  EXPECT_FALSE(intersectionSet.contains("Chris"));
  EXPECT_FALSE(intersectionSet.contains("Linda"));


}

