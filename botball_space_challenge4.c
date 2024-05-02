#include <kipr/wombat.h>

//Declaring what is.
int lmotor = 0; 
int rmotor = 2; 
int lmotorspeed = 26;
int rmotorspeed = -25;
int fullspeed = 100;
int miniservo = 3;
int cyloarm_servo = 2;
int cyloarm_startpos = 1024;
int cyloarm_upamount = 800;
int astroarm_servo = 1; 
int astroclaw_servo = 0; 
int astroarm_startpos = 676;
int astroarm_downamount = 1156;
int astroarm_upamount = 664;
int astroclaw_startpos = 966;
int astroclaw_closeamount = 597;
int backeye = 0;
int fronteye = 5;
int astroclaw_closed = 643;
int astroclaw_open = 1153;
int miniservo_closed = 1490;
int miniservo_open = 875;
int turntime = 1360;
int lbumper = 2; //analog 2
int rbumper = 3; //analog 3

//Declaring what can be.

void forward();
void go_forward();
void goforward(int forward_wait);
void controlled_turn_right(int c_turn_time);
void controlled_turn_left(int c_turn_time);
void beeg_turn_right();
void crane_down();
void starting_positions();
void claw_close();
void crane_up();
void go_backward();
void arm_up();
void jiggle();
void claw_open();

int main()
{
    printf("Hello World\n"); //To steal your first words is abominable. I will not do it. No matter how useless they seem to others.
    starting_positions();
    //move to astronaut start
    while(analog(backeye) < 4000)
    {
        forward();
    }
    ao();
    
    //pick up astronaut
    crane_down();
    msleep(2000);
    claw_close();
    crane_up(664);
    //move to pool noodle start place
    while(analog(fronteye) < 4000)
    {
        forward();
    }
    ao();
    go_backward(1000);
    ao();
    controlled_turn_right(2100);
    ao();
    //pick up pool noodle
    arm_up();
    controlled_turn_left(500);
    go_backward(200);
    controlled_turn_right(250);
    ao();
    msleep(2000);
    jiggle();
    jiggle();
    jiggle();
    //move to astronaut end place
    go_backward(500);
    controlled_turn_left(500);
    crane_up(296);
    while(analog(lbumper) != 0)
    {
        forward();
    }
    ao();
    msleep(100);
    go_backward(225);
    ao();
    //put pool noodle down
    enable_servos();
    set_servo_position(miniservo, 1655);
    msleep(2750);
    set_servo_position(miniservo, 1024);
    msleep(2750);
    disable_servos();
    //move to astronaut end place
    //put down astronaut
   		//crane_down();
    	//claw_open();
    	//crane_up();
    	//claw_close();
    	//crane_down();
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
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
    msleep(forward_wait);
    ao();
}

void go_backward(int forward_wait)
{
    printf("Full steam behind!");
    motor(lmotor, -fullspeed);
    motor(rmotor, fullspeed);
    msleep(forward_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void controlled_turn_left(int c_turn_time)
{
    printf("Starboard!");
    motor(lmotor, 0);
    motor(rmotor, rmotorspeed);
    msleep(c_turn_time);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void controlled_turn_right(int c_turn_time)
{
    printf("Port!");
    motor(rmotor, 0);
    motor(lmotor, lmotorspeed);
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

void crane_down()
{
    enable_servos();
    while(astroarm_startpos < astroarm_downamount)
    {
        set_servo_position(astroarm_servo, astroarm_startpos);
        msleep(50);
        astroarm_startpos = astroarm_startpos + 25;
    }
    disable_servos();
}

void crane_up(astroarm_upamount)
{
    enable_servos();
    while(astroarm_startpos > astroarm_upamount)
    {
        set_servo_position(astroarm_servo, astroarm_startpos);
        msleep(50);
        astroarm_startpos = astroarm_startpos - 25;
    }
    disable_servos();
}

void claw_close()
{
    enable_servos();
    while(astroclaw_startpos > astroclaw_closeamount)
    {
        set_servo_position(astroclaw_servo, astroclaw_startpos);
        msleep(50);
        astroclaw_startpos = astroclaw_startpos - 25;
    }
    disable_servos();
}

void claw_open()
{
    enable_servos();
    while(966 > astroclaw_closeamount)
    {
        set_servo_position(astroclaw_servo, astroclaw_startpos);
        msleep(50);
        astroclaw_startpos = astroclaw_startpos + 25;
    }
    disable_servos();
}

void starting_positions()
{
    enable_servos();
    set_servo_position(astroarm_servo, astroarm_startpos);
    msleep(1000);
    set_servo_position(astroclaw_servo, astroclaw_startpos);
    msleep(1000);
    set_servo_position(cyloarm_servo, cyloarm_startpos);
    msleep(1000);
    set_servo_position(miniservo, 1024);
    disable_servos();
}

void arm_up()
{
    enable_servos();
    while(cyloarm_startpos > cyloarm_upamount)
    {
        set_servo_position(cyloarm_servo, cyloarm_startpos);
        msleep(50);
        cyloarm_startpos = cyloarm_startpos - 25;
    }
    disable_servos();
}

void jiggle()
{
    enable_servos();
    set_servo_position(cyloarm_servo, cyloarm_startpos);
    msleep(100);
    set_servo_position(cyloarm_servo, cyloarm_startpos + 100);
    msleep(100);
}