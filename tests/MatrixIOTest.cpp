#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    test = MatrixXd(4, 4);
    test << 1, 2, 3, 4,
            5, 6, 7, 8, 9,
            10, 11, 12, 13;
  }

  MatrixXd test;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openDataTest)
{
  matrixIO::saveData("../data/temp.csv", test);

  MatrixXd output = matrixIO::openData("../data/temp.csv", 3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      BOOST_TEST(test(i, j) == output(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()