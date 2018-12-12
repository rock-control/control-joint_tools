#include <boost/test/unit_test.hpp>
#include <joint_tools/Dummy.hpp>

using namespace joint_tools;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    joint_tools::DummyClass dummy;
    dummy.welcome();
}
