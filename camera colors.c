#include <kipr/wombat.h>

//Declaring Variables
int green = 0;
int pink = 1;
int blue = 2;
int lmotor = 0;
int rmotor = 3;
int lmotorspeed = 26;
int rmotorspeed = 25;
int flagservo = 0;
int flagwait = 1000;

//Declaring Functions
void seeingblue();
void seeingpink();
void seeinggreen();

int main()
{
   camera_open_black();
   while(1)
   {
    camera_update();
    if (get_object_count(green) == 0 && get_object_count(pink) == 0 && get_object_count(blue) == 0)
    {
     printf("I'm not seeing any colors...\n");   
    }
   if (get_object_count(green) != 0 || get_object_count(pink) != 0 || get_object_count(blue) != 0)
   {
       if (get_object_count(green) != 0)
       {
           printf("I can see green!\n");
           seeinggreen();
       }
       if (get_object_count(pink) != 0)
       {
           printf("I can see pink!\n");
           seeingpink();
       }
       if (get_object_count(blue) != 0)
       {
           printf("I can see blue!\n");
           seeingblue();
       }
   }
   }
    return 0;
}

void seeingpink()
{
    enable_servos();
    set_servo_position(flagservo,750);
    msleep(flagwait);
    set_servo_position(flagservo,1350);
    msleep(flagwait);
    disable_servos();
}

void seeingblue()
{
    motor(lmotor, 20);
    motor(rmotor, -20);
    msleep(1000);
    ao();
    motor(lmotor, -20);
    motor(rmotor, 20);
    msleep(1000);
    ao();
}

void seeinggreen()
{
    motor(lmotor, lmotorspeed * 0.50);
    motor(rmotor, rmotorspeed * 0.50);
    msleep(750);
    ao();
    motor(lmotor, lmotorspeed * -0.50);
    motor(rmotor, rmotorspeed * -0.50);
    msleep(750);
    ao();
}