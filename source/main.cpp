/*
Functors
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
using namespace std;

// Functors are a kind of object that overloads the () operator.
// This makes it possible to use the object like a function.

// Our basic example will be a class representing a quadratic equation.
struct Quadratic
{
    // The constructor takes in floats a, b, and c used in the equation y = ax^2 + bx + c.
    Quadratic(float a, float b, float c) : a(a), b(b), c(c) {}

    // Override the () operator, to take in a value for x, and return the resulting y value.
    float operator()(float x) const
    {
        return a*x*x + b*x + c; 
    }

private:
    float a, b, c;
};



int main() 
{
    // Using the functor is easy:
    Quadratic curve = Quadratic(.5f, 0, -2.f);  // Create with constructor like any other object.
    
    // Loop from -3 to 3, and calculate the point on the curve at each point:
    for (float x = -3; x <= 3; x++)
    {
        float y = curve(x);
        cout << "(" << x << ", " << y << ")" << endl;   // Print out coordinate pairs.
    }

    cin.get();

    // Functors are nice because they can be initialized with variable information, and they can be passed into functions as parameters.

    return 0;   // End Program.
}