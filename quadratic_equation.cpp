#include "quadratic_equation.h"
#include <cmath>
#include <stdexcept>

roots quadr_eq(double a, double b, double c)
{
    roots ans{0,0};

    if(b == 0 && c == 0)
    {
        ans.x1 = ans.x2 = 0;
    }

    double D = b*b - 4*a*c;
    if(D < 0)
        throw std::overflow_error("No roots\n");
    double sD = sqrt(D);
    ans.x1 = ((b * -1) + sD)/(2*a);
    ans.x2 = ((b * -1) - sD)/(2*a);
    return ans;
}