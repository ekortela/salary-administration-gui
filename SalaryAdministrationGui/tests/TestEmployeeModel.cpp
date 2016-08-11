/*
 * TestEmployeeModel.cpp
 *
 *  Created on: 10.8.2016
 *      Author: Aapo Keskimölö
 */


class ExampleTestSuite : public Test::Suite
{

public:
    ExampleTestSuite()
    {
        TEST_ADD(ExampleTestSuite::first_test)
        TEST_ADD(ExampleTestSuite::second_test)
    }

private:
    void first_test();
    void second_test();
};


void ExampleTestSuite::first_test()
{
    // Will succeed since the expression evaluates to true
    //
    TEST_ASSERT(1 + 1 == 2)

    // Will fail since the expression evaluates to false
    //
    TEST_ASSERT(0 == 1);
}

void ExampleTestSuite::second_test()
{
    // Will succeed since the expression evaluates to true
    //
    TEST_ASSERT_DELTA(0.5, 0.7, 0.3);

    // Will fail since the expression evaluates to false
    //
    TEST_ASSERT_DELTA(0.5, 0.7, 0.1);
}


