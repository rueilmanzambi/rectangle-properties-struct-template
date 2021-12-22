// Programmer: Rueil Manzambi
// MST Username: rnm8cm
// Instructor: Johnathan Dunker
// Section: 301
// Date: 03/02/2021
// File: lab7.cpp
// Description: This program uses structs and a template to get the upper right and lower left coordinates of 
//              a rectangle, outputs the width, the height and the area of the rectangle


#include <iostream>

using namespace std;

/* Constants initializatiion */
const float LOWER_X = 3; 
const float LOWER_Y = 2;
const float UPPER_X = 8;
const float UPPER_Y = 9;
const float FIRSTPOINT_X = 1; // first point to check if it's inside the rectangle
const float FIRSTPOINT_Y = 5;
const float SECONDPOINT_X = 4; // second point to check if it's inside the rectangle
const float SECONDPOINT_Y = 6;

// Struct with x and y coordinates
struct coordinate
{
  float x;
  float y;
};

// for lower left and upper right sides of the rectangle
struct side
{
  coordinate low_left;
  coordinate up_right;
};

// for the points that we need to check whether they are inside the rectangle
struct point
{
  coordinate a;
  coordinate b;
};

// template function print() to compute and output the arguments (value1 * value2) - value3
template <typename T>
void print(T value)
{
  cout <<"(" << value.x << ", " << value.y << ")" <<  endl;
}
  

/* Function prototypes */
bool point_in_rectangle (coordinate first_or_secondpoint, side my_side);
coordinate lower_left_point (coordinate low_left);
coordinate upper_right_point (coordinate up_right);
float width_rect (side my_side);
float height_rect (side my_side);
float area_rect (side my_side);


int main()
{
 /* variable declaration and initialization */
  side my_side;
  my_side.up_right.x = UPPER_X;
  my_side.up_right.y = UPPER_Y;
  my_side.low_left.x = LOWER_X;
  my_side.low_left.y = LOWER_Y;

  point firstpoint;
  point secondpoint;
  firstpoint.a.x = FIRSTPOINT_X;
  firstpoint.a.y = FIRSTPOINT_Y;
  secondpoint.b.x = SECONDPOINT_X;
  secondpoint.b.y = SECONDPOINT_Y; 

  coordinate my_leftpoint = lower_left_point (my_side.low_left);
  coordinate my_rightpoint = upper_right_point (my_side.up_right);
  cout << "rect is {(" << my_leftpoint.x << ", " << my_leftpoint.y << "), (" << my_rightpoint.x << ", " << my_rightpoint.y << ")}" << endl;

  cout << "point a is (" << firstpoint.a.x << ", " << firstpoint.a.y << ")" << endl;
  cout << "point b os (" << secondpoint.b.x << ", " << secondpoint.b.y << ")" << endl;


  cout << "rect has upper right Point: (" <<  my_rightpoint.x << ", " << my_rightpoint.y << ")" << endl;
  cout << "rect has lower left Point: (" << my_leftpoint.x << ", " << my_leftpoint.y << ")" << endl;

  float width = width_rect (my_side);
  cout << "rect has width: " << width << endl;

  float height = height_rect (my_side);
  cout << "rect has height: " << height << endl;

  float area = area_rect (my_side);
  cout << "rect has area: " << area << endl;

  bool is_firstpoint_true =  point_in_rectangle (firstpoint.a, my_side);
  if (is_firstpoint_true)
    cout << "point a is within the rectangle" << endl;
  else
    cout << "point a is not within the rectangle" << endl;

  bool is_secondpoint_true = point_in_rectangle (secondpoint.b, my_side);
  if (is_secondpoint_true)
    cout  << "point b is within the rectangle" << endl;
  else
    cout << "point b is not within the rectangle" << endl;

  cout <<"\nThe following line testifies that I've corrected the error ;)" << endl;
  print(firstpoint.a);

  return 0;
}


// Description: check if the point that is passed is within the passed rectangle
// Pre: Arguments need to be declared using structs structs coordinate, side and point
// Post: Returns true if the point is within the rectangle, otherwise it returns false
bool point_in_rectangle (coordinate first_or_secondpoint, side my_side)
{
  bool in_rectangle;

  if (my_side.low_left.x > first_or_secondpoint.x || my_side.up_right.x < first_or_secondpoint.x) // checks if x coordinate is out of bounds
    in_rectangle = false;
  else if (my_side.low_left.y > first_or_secondpoint.y || my_side.up_right.y < first_or_secondpoint.y) // checks if y coordinate is out of bounds
    in_rectangle = false;
  else
    in_rectangle = true;

  return in_rectangle;
}


// Description: returns lower left coordinates
// Pre: argument has to be defined using struct coordinate and side
// Post: returns lower left coordinates
coordinate lower_left_point (coordinate low_left)
{
  return low_left;
}


// Description: returns upper right coordinates
// Pre: argument has to be defined using struct coordinate and side
// Post: returns upper right coordinates
coordinate upper_right_point (coordinate up_right)
{
  return up_right;
}


// Description: computes and returns rectangle width
// Pre: Argument has to be defined using struct coordinate and side
// Post: returns width
float width_rect (side my_side)
{
  float width = my_side.up_right.x - my_side.low_left.x;
  return width;
}


// Description: computes and returns rectangle height
// Pre: Argument has to be defined using struct coordinate and side
// Post: returns height
float height_rect (side my_side)
{
  float height = my_side.up_right.y - my_side.low_left.y;
  return height;
}


// Description: computes and returns the rectangle area
// Pre: argument has to be defined using struct coordinate and side
// Post: returns area
float area_rect (side my_side)
{
  float area = (my_side.up_right.y - my_side.low_left.y) * (my_side.up_right.x - my_side.low_left.x);
  return area;
}
  
