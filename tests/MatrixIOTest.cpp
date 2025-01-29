// #define BOOST_TEST_DYN_LINK
// #include <boost/test/unit_test.hpp>
// #include "matrixIO.hpp"
// using namespace Eigen;

// BOOST_AUTO_TEST_SUITE(MatrixIoTests)

// BOOST_AUTO_TEST_CASE(ReadTest)
// {
//   MatrixXd expectedX(3, 3);
//   expectedX << 0.680375, 0.59688, -0.329554,
//       -0.211234, 0.823295, 0.536459,
//       0.566198, -0.604897, -0.444451;

//   auto output = matrixIO::openData("../data/m3.csv", 3);

//   for (int x = 0; x < 3; ++x) {
//     for (int y = 0; y < 3; ++y) {
//       BOOST_TEST(expectedX(x, y) == output(x, y));
//     }
//   }
// }

// BOOST_AUTO_TEST_SUITE_END()

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expectedX = MatrixXd(3, 3);
    expectedX << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
  }

  MatrixXd expectedX;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openDataTest)
{
  matrixIO::saveData("../data/temp.csv", expectedX);

  MatrixXd output = matrixIO::openData("../data/temp.csv", 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(expectedX(i, j) == output(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()