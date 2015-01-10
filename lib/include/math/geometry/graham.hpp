#pragma once

#include "math/geometry/point2.hpp"
#include "math/geometry/segment.hpp"

#include <vector>

namespace oh {
  namespace math {
    namespace geometry {

std::vector<Point2f> ConvexHullGraham(std::vector<Point2f> points);

float RelativePositionOfPoints(Point2f p, Point2f q, Point2f r);
bool SegmentsIntersect(Segment seg1, Segment seg2);
bool PointOnSegment(Point2f point, Segment seg);

}}}
// ~~ oh::math::geometry::
