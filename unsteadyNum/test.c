#include<stdio.h>
#include<stdarg.h>
double average(int num,...) {
    va_list valist;
    va_start(valist, num);
    double sum= 0.0;
    for(int i=0;i<num;i++){
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return sum / num;
}
int main(){
    printf("%lf", average(5,6,7,7,8,4));
}