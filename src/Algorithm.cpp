#include "tf_manipulator/Algorithm.hpp"

namespace tf_manipulator {

Algorithm::Algorithm()
    : average_(0.0),
      nMeasurements_(0)
{
}

Algorithm::~Algorithm()
{
}
void Algorithm::processData(const int i)
{
  //average_ = (nMeasurements_ * average_ + data) / (nMeasurements_ + 1);
  //nMeasurements_++;
}

double Algorithm::getAverage() const
{
  return average_;
}

} /* namespace */
