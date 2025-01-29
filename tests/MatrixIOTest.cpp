#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    m = MatrixXd(4, 4);
    m << 1, 2, 3,
        5, 6, 7,
        10, 11, 12;
  }

  MatrixXd m;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openDataTest)
{
  matrixIO::saveData("../data/temp.csv", m);

  MatrixXd output = matrixIO::openData("../data/temp.csv", 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(m(i, j) == output(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()