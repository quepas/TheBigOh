#pragma once

#include "math/geometry/point2.hpp"

namespace oh {
  namespace math {
    namespace geometry {

struct Segment {

Segment()
  : p1(0.0f, 0.0f), p2(0.0f, 0.0f) {}
Segment(float x1, float y1, float x2, float y2)
  : p1(x1, y1), p2(x2, y2) {}
Segment(Point2f _p1, Point2f _p2)
  : p1(_p1), p2(_p2) {}

Point2f p1, p2;
};

}}}
// ~~ oh::math::geometry::Segment
