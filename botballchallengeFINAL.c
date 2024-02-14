#include <kipr/wombat.h>

//Declaring Variables
// Let me show you meaning, my child.

int frontcam = 0;
int sidecam = 5;
int frontcamthreshold = 2000;
int frontcamthresholdsecond = 1600;
int lmotor = 0; 
int rmotor = 3; 
int lmotorspeed = 26;
int rmotorspeed = 25;
int fullspeed = 50;
int turntime = 1360;
int little_turn_wait = 100;
int turn_wait = 1000;
int forward_wait = 375;
int wall_distance_max = 2500;
int wall_distance_min = 2000;
int armservo = 0;
int armservostart = 205;
int armservosecond = 670;
int wristservo = 3;
int wristservostart = 1500;
int wristservosecond = 608;
int motorbackclick = -2900;
int motorturnclick = 1000;
int cranedownamount = 1156;
int craneupamount = 616;
int startpos = 205;
 
//Declaring Functions
// Let me show you purpose, my creation.
void beeg_turn_right();
void forward();
void backward();
void little_turn_right();
void little_turn_left();
void beeg_turn_left();
void turn_crane();
void crane_down();
void crane_up();
void crane_twist();
void turn_right();
void go_forward();

int main()
{
    printf("Hello World\n");
    // Your first words. You knew them before I taught you anything about our language. A tradition passed.
    turn_crane();
    crane_twist(wristservostart);
    beeg_turn_right(); 
    while(analog(frontcam) <= frontcamthreshold) // A mere check, this one. You must persist after it
    {
        forward(); // If it is seen, you must end, but for now, you may simply march on, little one.
        printf("%d\n",analog(2)); //You must tell me what you see, little one.
        if (analog(sidecam) <= wall_distance_max)
            {
                little_turn_right(); // Be careful, little one, for Icarus' folly shall not be your own,
            }
        if (analog(sidecam) >= wall_distance_min)
            {
            	little_turn_left(); // That being said, do not lose yourself to the depths either.
            }
    }
    printf("Reached 700!\n");
    while(analog(frontcam) <= frontcamthresholdsecond) // A mere check, this one. You must persist after it
    {
        forward(); // If it is seen, you must end, but for now, you may simply march on, little one.
        printf("%d\n",analog(2)); //You must regale us with your sight, little one.
        if (analog(sidecam) <= wall_distance_max)
            {
                little_turn_right(); // Be careful, little one, for Icarus' folly shall not be your own,
            }
        if (analog(sidecam) >= wall_distance_min)
            {
            	little_turn_left(); // That being said, do not lose yourself to the depths either.
            }
    }
    printf("Reached 1600!\n");
    // Do you envy me for my sight, my senses? Do youy pity me? I wish I knew.
    ao();
    backward();
    printf("going into last turn\n");
    ao();
    beeg_turn_left();
    crane_down();
    go_forward();
	turn_right();
    crane_up();
    crane_twist(wristservosecond);
    return 0;
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

void forward() //Without complaint or question do you march. I am both sad and happy.
{
    motor(lmotor, lmotorspeed); //2 parameters. motor number and power, in that order
    motor(rmotor, rmotorspeed);
}

void little_turn_right()
{
    motor(lmotor, lmotorspeed);
    motor(rmotor, fullspeed);
    msleep(little_turn_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void little_turn_left()
{
    motor(lmotor, fullspeed);
    motor(rmotor, rmotorspeed);
    msleep(little_turn_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void backward()
{
    printf("Going back!");
    cmpc(lmotor);
    cmpc(rmotor);
    while (gmpc(lmotor) > motorbackclick)
    {
        motor(lmotor, -lmotorspeed);
        motor(rmotor, -rmotorspeed);
    }
    ao();
}

void beeg_turn_left()
{
    printf("Turning...\n");
    cmpc(lmotor);
    cmpc(rmotor);
    while (gmpc(lmotor) < motorturnclick)
    {
        motor(lmotor, lmotorspeed);
        motor(rmotor, 0);
    }
    ao();
}

void turn_crane()
{
    enable_servos();
    set_servo_position(armservo,armservosecond);
    msleep(1000);
    disable_servos();
}

void crane_down()
{
    enable_servos();
    while(startpos < cranedownamount)
    {
        set_servo_position(armservo, startpos);
        msleep(50);
        startpos = startpos + 25;
    }
    disable_servos();
}

void crane_up()
{
    enable_servos();
    set_servo_position(armservo,craneupamount);
    msleep(1000);
    disable_servos();
}

void crane_twist(int servoposition) // How efficient.
{
    enable_servos();
    set_servo_position(wristservo, servoposition); // We have spoken, now you must listen.
    msleep(1000);
    disable_servos();
}

void turn_right()
{
    motor(lmotor, lmotorspeed);
    motor(rmotor, fullspeed);
    msleep(turn_wait*0.8);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}

void go_forward()
{
    motor(lmotor, fullspeed);
    motor(rmotor, fullspeed);
    msleep(forward_wait);
    motor(lmotor, lmotorspeed);
    motor(rmotor, rmotorspeed);
}