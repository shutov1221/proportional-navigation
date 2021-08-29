#include "vec2.h"
#include <string>

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

std::ostream& operator<< (std::ostream& out, const vec2& vec)
{	
    //REPLACE '.' TO ',' for Excel

	/*auto x_str = std::to_string(vec.x);
    auto y_str = std::to_string(vec.y);
	replace(x_str, ".", ",");
    replace(y_str, ".", ",");
	out << x_str << " " << y_str;*/

    out << vec.x << " " << vec.y;
	return out;
}
