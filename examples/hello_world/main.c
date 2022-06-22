#include <circular_buffer.h>
#include <stdlib.h>
void main()
{
    // Create an integer circular buffer
    iCircularBuffer icb;
    // Initialize it
    icb_init(&icb, 100);
    //Seed random 
    srand(0);
    // Now let's push some numbers
    for(int i=0;i<125;i++)
    {
        icb_push(&icb, rand()% 101);
    }
    //print the value at a specific position
    printf("value at %d, %d", 5,icb_get_at(&icb, 5));
    //print the minimal value
    printf("min value %d", icb_min(&icb));
    //print the maximal value
    printf("max value %d", icb_max(&icb));
    //print the mean value
    printf("min value %d", icb_mean(&icb));

    // Remove the maximal value
    icb_remove_at_timeindex(&icb, icb_argmax(&icb));
    //print the new maximal value
    printf("max value %d", icb_max(&icb));
}