#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct complex 
{
    double real;
    double img;
} complex;

complex A,B,C,D,E,F;
void read_comp(complex *c1, double real, double img);
void print_comp(complex *c1);
void add_comp(complex *c1, complex *c2);
void sub_comp(complex *c1, complex *c2);
void mult_comp_real(complex *c1, double real);
void mult_comp_img(complex *c1, double img);
void mult_comp_comp(complex *c1, complex *c2);
void abs_comp(complex *c1);


char *commands[9] = { "read_comp" ,"print_comp" , "add_comp" ,  "sub_comp" , 
    "mult_comp_real" , "mult_comp_img" ,  "mult_comp_comp" , "abs_comp", "stop"};

