#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

BOOST_AUTO_TEST_CASE(ReadMatrix3x3)
{
  MatrixXd expectedX(3, 3);
  expectedX << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;

  auto output = matrixIO::openData("../data/m3.csv", 3);

  for (int x = 0; x < 3; ++x) {
    for (int y = 0; y < 3; ++y) {
      BOOST_TEST(expectedX(x, y) == output(x, y));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()