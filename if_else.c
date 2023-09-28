#include <kipr/wombat.h>

int main()
{
    while(1)
    {
        if (digital(8) == 1)
        {
            printf("Button being pressed!\n");
        }
        else
        {
            printf("Button not being pressed!\n");
        }
    }    
    return 0;
}
