#include "My_Random_Number_Generator.h"
#include "typedefs.h"
#include "small_functions.h"

void get_external_input_current(Number_t en, Number_t in, Number_t nr_time_steps,
                                Number_t time_i, Time_t t_unit,
                                Number_t extI_type,
                                Current_t Imin, Current_t Imax,
                                Number_t nr_steps, Current_t extI_vector[])
{
    Number_t           n = en-in;
    double   step_height = (Imax-Imin)/(nr_steps-1);
    double   which_step  = round(((nr_steps-1)/(nr_time_steps/2.0-1))*time_i);
    Flag_t   display_extI_vector = false;

    // External input current type:
    // 1-Step function from Imin to Imax
    // 2-Step function from Imin to Imax
    //   for only half of exc. Rest is 0
    Number_t loop_stop;
    if ( extI_type == 1 )
    {
        loop_stop = n;
    }
    else if ( extI_type == 2 )
    {
        loop_stop = en/2;
    }

    // Calculate external input
    for (int i=0; i<loop_stop; i++)
    {
        if ( which_step <= nr_steps-1 )
        {
            extI_vector[i] = Imin + which_step*step_height;
        }
        else
        {
            extI_vector[i] = Imin + (2*nr_steps-1-which_step)*step_height;
        }
    }

    // Divide by time conversion factor
    for (int i=0; i<n; i++)
    {
        extI_vector[i] = extI_vector[i]/t_unit;
    }

    // Display
    if ( display_extI_vector )
    {
        for (int i=0; i<n; i++)
        {
            std::cout << extI_vector[i] << " ";
        }
        std::cout << std::endl;
    }
}
