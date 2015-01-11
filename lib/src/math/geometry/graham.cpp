#include "math/geometry/graham.hpp"
#include "math/geometry/segment.hpp"
#include "math/matrix33.hpp"
#include "math/misc.hpp"
#include "helper/manipulate.hpp"

#include <algorithm>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

using oh::helper::NextToTop;
using std::min_element;
using std::string;
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

float RelativePositionOfPoints(Segment seg, Point2f r)
{
  return Matrix33f(seg.p1.x, seg.p1.y, 1.0f,
                   seg.p2.x, seg.p2.y, 1.0f,
                   r.x,      r.y,      1.0f).Det();
}

bool SegmentsIntersect(Segment seg1, Segment seg2)
{
  float d1 = RelativePositionOfPoints(seg2.p1, seg2.p2, seg1.p1),
        d2 = RelativePositionOfPoints(seg2.p1, seg2.p2, seg1.p2),
        d3 = RelativePositionOfPoints(seg1.p1, seg1.p2, seg1.p1),
        d4 = RelativePositionOfPoints(seg1.p1, seg1.p2, seg1.p2);

  if (d1*d2 < 0 && d3*d4 < 0) return true;
  if (IsEqual(d1, 0) && PointOnSegment(seg1.p1, seg2)) return true;
  if (IsEqual(d2, 0) && PointOnSegment(seg1.p2, seg2)) return true;
  if (IsEqual(d3, 0) && PointOnSegment(seg2.p1, seg1)) return true;
  if (IsEqual(d4, 0) && PointOnSegment(seg2.p2, seg1)) return true;
  return false;
}

bool PointOnSegment(Point2f point, Segment seg)
{
  return (min(seg.p1.x, seg.p2.x) <= point.x && point.x <= max(seg.p1.x, seg.p2.x)) &&
         (min(seg.p1.y, seg.p2.y) <= point.y && point.y <= max(seg.p1.y, seg.p2.y));
}

struct YComparator {
  bool operator()(const Point2f& p1, const Point2f& p2) {
    return p1.y < p2.y || (IsEqual(p1.y, p2.y) && p1.x < p2.x);
  }
};

struct PolarAngleComparator {
  bool operator()(const Point2f& p1, const Point2f& p2) {
    return p1.PolarAngle() < p2.PolarAngle();
  }
};

bool EqualPolarAngleButFurtherRadius(const Point2f& p1, const Point2f& p2) {
  return IsEqual(p1.PolarAngle(), p2.PolarAngle()) && p1.PolarRadius() > p2.PolarRadius();
}

vector<Point2f> ConvexHullGraham(vector<Point2f> points)
{
  if (points.size() <= 3) return points;
  auto p0 = min_element(points.begin(), points.end(), YComparator());
  std::rotate(points.begin(), p0, points.end());
  std::sort(points.begin() + 1, points.end(), PolarAngleComparator());
  auto unique_iterators = std::unique(points.begin() + 1, points.end(), EqualPolarAngleButFurtherRadius);
  points.resize(std::distance(points.begin(), unique_iterators));

  std::stack<Point2f> S;
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);

  for (int i = 3; i < points.size(); ++i) {
    while (RelativePositionOfPoints(Segment(S.top(), NextToTop(S)), points[i]) >= 0) {
      S.pop();
    }
    S.push(points[i]);
  }
  std::vector<Point2f> result;
  while (!S.empty()) {
    result.push_back(S.top());
    S.pop();
  }
  return result;
}

vector<Point2f> LoadPoints(string file_name)
{
  std::ifstream file_in(file_name);
  std::vector<Point2f> points;
  if (!file_in.is_open()) return points;

  string line;
  float x, y;
  char c;
  while(std::getline(file_in, line)) {
    std::stringstream ss;
    ss << line;
    ss >> x >> c >> y;
    points.push_back(Point2f(x, y));
  }
  return points;
}

}}}
// ~~ oh::math::geometry::
