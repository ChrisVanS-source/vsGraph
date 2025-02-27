#pragma once

#include "qgraph_enum.h"
#include <tuple>

Operation map_func1(Operation op, bool xp);
Operation map_func2(Operation op, bool xp, bool yp);
bool is_func2_x_param(Operation op);
bool is_func2_y_param(Operation op);
std::tuple<Operation, bool, bool> unmap_func2(Operation op);
std::pair<Operation, bool> unmap_func2_scalar(Operation op);
std::pair<Operation, bool> unmap_func1(Operation op);
bool is_func2_x_param(Operation op);
bool is_func2_y_param(Operation op);


