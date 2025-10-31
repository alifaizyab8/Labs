#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
struct rectangular {
    double real;
    double imag;
};
struct polar {
    double magnitude;
    double angle;
};
struct polar convert(struct rectangular rect_num)
{
    struct polar pol_num;
    pol_num.magnitude = sqrt(rect_num.real * rect_num.real + rect_num.imag * rect_num.imag);
    pol_num.angle = atan2(rect_num.imag, rect_num.real) * (180.0 / PI);
    return pol_num;

}

//Input for rectangular form without using fuvcntions
int main() {
    struct polar pol_num;
    struct rectangular rect_num;
    printf("Enter the real and imaginary parts of the rectangular form respectively: \n");
    scanf("%lf %lf", &rect_num.real, &rect_num.imag); 
    pol_num = convert(rect_num);
    printf("Polar form: %.2lf /_ %.2lf \n", pol_num.magnitude, pol_num.angle);
    
}

