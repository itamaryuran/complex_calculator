#include "complex.h"
#include <math.h>


void read_comp(complex *c1, double real, double img)
{
    c1->real = real;
    c1->img = img;
    
}

void print_comp(complex *c1)
{
   
    if (c1->img >= 0)
    {
        printf("%0.2f + (%0.2f)i\n",c1->real,c1->img);
    }
    else 
        printf("%0.2f - (%0.2f)i\n", c1->real,c1->img* -1);
}

void add_comp(complex *c1, complex *c2)
{
complex temp;
temp.real = c1->real + c2->real;
temp.img = c1->img + c2->img;
print_comp(&temp);
}

void sub_comp(complex *c1, complex *c2)
{
complex temp;
temp.real = c1->real - c2->real;
temp.img = c1->img - c2->img;
print_comp(&temp);

}


void mult_comp_real(complex *c1, double real)
{
complex temp;
temp.real = c1->real * real;
temp.img = c1->img * real;
print_comp(&temp);
}


void mult_comp_img( complex *c1, double img)
{
complex temp;
temp.real = c1->img * img * (-1);
temp.img = c1->real * img;
print_comp(&temp);
}

void mult_comp_comp( complex *c1,  complex *c2)
{
complex temp;
temp.real = (c1->real * c2->real) - (c1->img * c2->img);
temp.img = (c1->real * c2->img) + (c1->img * c2->real);
print_comp(&temp);
}

void abs_comp(complex *c1)
{
double abs;
abs = sqrt((c1->real * c1->real) + (c1->img * c1->img));
printf("%0.2f\n", abs);
}
