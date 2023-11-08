#include <kipr/wombat.h>
//Declaring Variables 
int green = 0;
int pink = 1;
int blue = 2; 
int lmotor = 0; 
int rmotor = 3; 
int lmotorspeed = 26;
int rmotorspeed = 25; 

//Declaring Functions
void seeingpink();
void turn_left();
void turn_right();

int main()
{
   camera_open_black();
   while(analog(5) <= 2890)
   {
    camera_update();
   if (get_object_count(pink) != 0)
   {
       printf("I can see pink!\n");
       seeingpink();
       if(get_object_center_x(1,0) < 80)
       {
           turn_right();
       }
       if(get_object_center_x(1,0) > 80)
       {
           turn_left();
       }
   }
   }
    ao();
    return 0;
}

void seeingpink()
{
    motor(lmotor, lmotorspeed * 0.50);
    motor(rmotor, rmotorspeed * 0.50);
}

void turn_left()
{
    motor(lmotor, lmotorspeed * 0.50);
    motor(rmotor, 50);
}

void turn_right()
{
    motor(lmotor, 50);
    motor(rmotor, rmotorspeed * 0.50);
}