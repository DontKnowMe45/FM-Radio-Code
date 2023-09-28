#include <kipr/wombat.h>

int main()
{
    while(1)
    {
        if (digital(8) == 1)
        {
            printf("Button down!\n");
        }
        else
        {
            printf("Button up!\n");
        }
    }    
    return 0;
}
