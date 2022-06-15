#include <boost/test/unit_test.hpp>
#include <cucumber-cpp/autodetect.hpp>

#include "Calculator.h"

using cucumber::ScenarioScope;

struct CalcCtx {
    Calculator calc;
    double result;
};

GIVEN("^I have entered (\\d+) into the calculator$") {
    REGEX_PARAM(double, n);
    ScenarioScope<CalcCtx> context;

    context->calc.push(n);
}


WHEN("^I press add") {
    ScenarioScope<CalcCtx> context;

    context->result = context->calc.add();
}

WHEN("^I press divide") {
    ScenarioScope<CalcCtx> context;

    context->result = context->calc.divide();
}

THEN("^the result should be (.*) on the screen$") {
    REGEX_PARAM(double, expected);
    ScenarioScope<CalcCtx> context;

    // https://www.boost.org/doc/libs/1_35_0/libs/test/doc/components/test_tools/reference/
    BOOST_CHECK_EQUAL(expected, context->result);
}
