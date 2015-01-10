#include "math/geometry/graham.hpp"
#include "math/matrix33.hpp"
#include "math/misc.hpp"

using std::vector;

namespace oh {
  namespace math {
    namespace geometry {

float RelativePositionOfPoints(Point2f p, Point2f q, Point2f r)
{
  return Matrix33f(p.x, p.y, 1.0f,
                   q.x, q.y, 1.0f,
                   r.x, r.y, 1.0f).Det();
}

bool SegmentsIntersect(Segment seg1, Segment seg2)
{
  float d1 = RelativePositionOfPoints(seg2.p1, seg2.p2, seg1.p1),
        d2 = RelativePositionOfPoints(seg2.p1, seg2.p2, seg1.p2),
        d3 = RelativePositionOfPoints(seg1.p1, seg1.p2, seg1.p1),
        d4 = RelativePositionOfPoints(seg1.p1, seg1.p2, seg1.p2);

  if (d1*d2 < 0 && d3*d4 < 0) return true;
  if (d1 == 0 && PointOnSegment(seg1.p1, seg2)) return true;
  if (d2 == 0 && PointOnSegment(seg1.p2, seg2)) return true;
  if (d3 == 0 && PointOnSegment(seg2.p1, seg1)) return true;
  if (d4 == 0 && PointOnSegment(seg2.p2, seg1)) return true;
  return false;
}

bool PointOnSegment(Point2f point, Segment seg)
{
  return (min(seg.p1.x, seg.p2.x) <= point.x <= max(seg.p1.x, seg.p2.x)) &&
         (min(seg.p1.y, seg.p2.y) <= point.y <= max(seg.p1.y, seg.p2.y));
}

vector<Point2f> ConvexHullGraham(vector<Point2f> points)
{
  return vector<Point2f>();
}

}}}
// ~~ oh::math::geometry::