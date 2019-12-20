#include<stdio.h>
#include<math.h>
#define PI 3.147456
#define square(x) ((x)*(x))
#define circle(x) (PI*(x)*(x))
#define s(x,y,z) ((x)+(y)+(z))/2
#define triangle(x,y,z) sqrt(s(x,y,z)*(s(x,y,z)-x)*(s(x,y,z)-y)*(s(x,y,z)-z))

