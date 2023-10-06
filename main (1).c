#include <kipr/wombat.h>

//Declaring Variables
int lmotor = 0;
int rmotor = 3;
int marchtime = 1000;
int rbumper = 8;
int lbumper = 9;
int rbackbumper = 6;
int lbackbumper = 7;
int turntime = 1340;
int counter = 0;

//Declaring Functions
void forward();
void reverse();
void turn_left();
void turn_right();
void turn_back();

int main()
{
    while(1) //while(1) is basically while(true), which makes the while loop go forever
    {
        forward(); // go forward until...
        if(digital(rbumper)==1||digital(rbackbumper) ==1) //the right bumper is pressed down...
        {
            printf("Oops! I bumped into something on the right!\n"); //then say this...
        	reverse(); //and go backwards!
        	turn_left();
            counter = counter + 1;
        }
        if(digital(lbumper)==1||digital(lbackbumper)==1) //if the left bumper is pressed...
        {
            printf("Oops! I bumped into something on the left!\n"); //say this...
            reverse(); //go backwards...
            turn_right(); //and turn right!
            counter = counter + 1;
        }
        if(counter==5)
        {
            printf("MACHINE, TURN BACK NOW.\n");
            reverse();
            turn_back();
            counter = 0;
        }
    }    
    return 0;
}
    
void forward()
{
    motor(lmotor, 52); //2 parameters. motor number and power, in that order
    motor(rmotor, 50);
}
    
void reverse()
{
    motor(lmotor, -52); //2 parameters. motor number and power, in that order
    motor(rmotor, -50);
    msleep(marchtime); // just keep doing what you're doing for a select amount of time
    ao(); // all off (turns off motors, do after each motor command we run
}
    
void turn_left()
{
    printf("Turning...\n");
    motor(lmotor, 50);
    motor(rmotor, -50);
    msleep(turntime);
    ao();
}
    
void turn_right()
{
    printf("Turning...\n");
    motor(lmotor, -50);
    motor(rmotor, 50);
    msleep(turntime);
    ao();
}

void turn_back()
{
    printf("Okay...\n");
    motor(lmotor, -50);
    motor(rmotor, 50);
    msleep(turntime);
    msleep(turntime);
    ao();
}