#pragma once

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/register/point.hpp>

#include "tue/vec.hpp"

using vec2 = tue::fvec2;

BOOST_GEOMETRY_REGISTER_POINT_2D_GET_SET(vec2, float, boost::geometry::cs::cartesian, x, y, set_x, set_y);
