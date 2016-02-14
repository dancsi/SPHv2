#include "Vec2.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/segment.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/register/segment.hpp>
#include <boost/geometry/algorithms/intersection.hpp>
#include <boost/geometry/algorithms/covered_by.hpp>
#include <boost/geometry/algorithms/within.hpp>

struct Line
{
    vec2 p, q;
};

BOOST_GEOMETRY_REGISTER_SEGMENT(Line, vec2, p, q);

using boost::geometry::intersection;
using boost::geometry::intersects;
using boost::geometry::covered_by;
using boost::geometry::within;

