#include <kipr/wombat.h>

//Declaring Functions
void forward();
void turn_left();
void little_turn_right();
void little_turn_left();

//Declaring Variables

int fsensor = 5;
int rsensor = 0;
int lmotor = 0;
int rmotor = 3;
int lmotorspeed = 52;
int rmotorspeed = 50;
int turncounter = 0;
int turntime = 1350;
int forward_wall_threshold = 2890;
int wall_distance_min = 2890;
int wall_distance_max = 2910;
int little_turn_wait = 100;

int main()
{
    while(analog(fsensor) <= forward_wall_threshold)
    {
        forward();
    }    
    if(analog(fsensor) >= forward_wall_threshold && turncounter == 0)
    {
        turn_left();
        turncounter = 1;
    }
    while(analog(fsensor) <= forward_wall_threshold)
    {
        forward();
        if (analog(rsensor) <= wall_distance_max)
            {
                little_turn_right();
            }
        if (analog(rsensor) >= wall_distance_min)
            {
            	little_turn_left();
            }
    }
    ao();
    return 0;
}

void forward()
{
    motor(lmotor, lmotorspeed); //2 parameters. motor number and power, in that order
    motor(rmotor, rmotorspeed);
}

void turn_left()
{
    printf("Turning...\n");
    motor(lmotor, 50);
    motor(rmotor, 10);
    msleep(2.45*turntime);
    ao();
}

void little_turn_right()
{
    motor(lmotor, lmotorspeed);
    motor(rmotor, 100);
    msleep(little_turn_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void little_turn_left()
{
    motor(lmotor, 100);
    motor(rmotor, rmotorspeed);
    msleep(little_turn_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}
