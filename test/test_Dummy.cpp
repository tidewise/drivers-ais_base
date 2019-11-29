#include <boost/test/unit_test.hpp>
#include <ais_base/Dummy.hpp>

using namespace ais_base;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    ais_base::DummyClass dummy;
    dummy.welcome();
}
