#include <kipr/wombat.h>

//Declaring what is.
int lmotor = 0; 
int rmotor = 2; 
int lmotorspeed = 26;
int rmotorspeed = -25;
int fullspeed = 100;
int miniservo = 3;
int cyloarm_servo = 2;
int astroarm_servo = 1; 
int astroclaw_servo = 0; 
int backeye = 5;
int fronteye = 0;
int astroclaw_closed = 643;
int astroclaw_open = 1153;
int miniservo_closed = 1490;
int miniservo_open = 875;
int turntime = 1360;

//Declaring what can be.

void forward();
void go_forward();
void goforward(int forward_wait);
void controlled_turn_right(int c_turn_time);
void controlled_turn_left(int c_turn_time);
void beeg_turn_right();

int main()
{
    printf("Hello World\n"); //To steal your first words is abominable. I will not do it. No matter how useless they seem to others.
    //move to astronaut start
    while(analog(backeye) < 40000){
        forward();
    }
    ao();
    
    //pick up astronaut
    //move to pool noodle start place
    //pick up pool noodle
    //move to astronaut end place
    //put down astronaut
    //move to pool noodle end place
    //put pool noodle down
    return 0;
}

void forward() //Without complaint or question do you march. I am both sad and happy.
{
    motor(lmotor, lmotorspeed); //2 parameters. motor number and power, in that order
    motor(rmotor, rmotorspeed);
}

void go_forward(int forward_wait)
{
    printf("Full steam ahead!");
    motor(lmotor, fullspeed);
    motor(rmotor, fullspeed);
    msleep(forward_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void controlled_turn_right(int c_turn_time)
{
    printf("Starboard!");
    motor(lmotor, lmotorspeed);
    motor(rmotor, fullspeed);
    msleep(c_turn_time);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void controlled_turn_left(int c_turn_time)
{
    printf("Port!");
    motor(rmotor, rmotorspeed);
    motor(lmotor, fullspeed);
    msleep(c_turn_time);
    motor(rmotor, rmotorspeed);
    motor(lmotor, lmotorspeed);
}

// And now, that I may teach you how to live, is my greatest honor.
void beeg_turn_right()
{
    printf("Turning...\n");
    // I gave you a voice, so that you may express your actions. That you may have a self.
    // More than a machine following my orders, you are happy, I hope.
    motor(lmotor, 0);
    motor(rmotor, 50);
    msleep(turntime*2);
    ao(); // Rest now, little one. 
}
