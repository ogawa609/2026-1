#include <stdio.h>
#include "temperature_conversor.h"

int main()
{
    float temp;
    float convert;
    char tsrc,tdst;
    scanf("%f %c %c",&temp,&tsrc,&tdst);

    if(tsrc=='c'&&tdst=='k')
        convert=convert_temperature(temp,convert_celsius_to_kelvin);

    else if(tsrc=='c'&&tdst=='f')
        convert=convert_temperature(temp,convert_celsius_to_fahrenheit);

    else if(tsrc=='k'&&tdst=='c')
        convert=convert_temperature(temp,convert_kelvin_to_celsius);

    else if(tsrc=='k'&&tdst=='f')
        convert=convert_temperature(temp,convert_kelvin_to_fahrenheit);

    else if(tsrc=='f'&&tdst=='c')
        convert=convert_temperature(temp,convert_fahrenheit_to_celsius);

    else if(tsrc=='f'&&tdst=='k')
        convert=convert_temperature(temp,convert_fahrenheit_to_kelvin);

    if(tdst=='c')
         printf("Temperature: %.2fCº",convert);
    else if(tdst=='f')
         printf("Temperature: %.2fFº",convert);
    else
        printf("Temperature: %.2fK",convert);


    return 0;
}