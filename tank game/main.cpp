#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <Gl/glu.h>
#include <string.h>
#include<math.h>

#define AMMOPlayer1 20
#define AMMOPlayer2 20
#define MOVESPEED 0.02
#define FIRESPEED 0.1
#define Refresh 20


double moveVerticalPlayer1 = 0, moveHorizontalPlayer1 = 0, moveVerticalPlayer2 = 0, moveHorizontalPlayer2 = 0;
float xP1 = -0.3, yP1 = -0.9;
float x = -0.1, y = 0.1;
double xfirePlayer1[AMMOPlayer1], yfirePlayer1[AMMOPlayer1], xfirePlayer2[AMMOPlayer2], yfirePlayer2[AMMOPlayer2];
double powerPlayer1 = 0.4, powerPlayer2 = 0.4;
int i, j;
int fireVisiblePlayer1[AMMOPlayer1], fireVisiblePlayer2[AMMOPlayer2];
int twobatvisible = 1;  // for player 2 visibility
int numoffireplayer1 = 0 ,numoffireplayer2 = 0;
int RefreshP2 = 0;
int RefreshP3 = 0;
char text1[] = "PLAYER 1";
char text2[] = "PLAYER 2";
char text3[] = "PLAYER 1 WIN" ;
char text4[] = "PLAYER 2 WIN";

char xd = 'r', yd = 'u';

// printing string
void stringPrint(float x, float y, char *st)
{
    int l, q;

    l = strlen( st );
    glColor3f(0.0, 1.0, 0.7);
    glRasterPos2f(x, y);
    for(i = 0; i < l; i++ )
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

// player 1 control (green tank)
void controlPlayer1(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        moveHorizontalPlayer1 = moveHorizontalPlayer1 + MOVESPEED;
        break;

    case 'a':
        moveHorizontalPlayer1 = moveHorizontalPlayer1 - MOVESPEED;
        break;

    case 'w':
        moveVerticalPlayer1 = moveVerticalPlayer1 + MOVESPEED;
        break;

    case 's':
        moveVerticalPlayer1 = moveVerticalPlayer1 - MOVESPEED;
        break;

    case 32:

        xfirePlayer1[numoffireplayer1 % 10] = xP1;
        yfirePlayer1[numoffireplayer1 % 10] = yP1;
        fireVisiblePlayer1[numoffireplayer1 % 10] = 1;
        numoffireplayer1++;
        break;

    case 27:
        exit(0);
    }

}

// player 2 control (red tank)

void controlPlayer2(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        moveHorizontalPlayer2 = moveHorizontalPlayer2 + MOVESPEED;
        break;

    case GLUT_KEY_LEFT:
        moveHorizontalPlayer2 = moveHorizontalPlayer2 - MOVESPEED;
        break;

    case GLUT_KEY_UP:
        moveVerticalPlayer2 = moveVerticalPlayer2 + MOVESPEED;
        break;

    case GLUT_KEY_DOWN:
        moveVerticalPlayer2 = moveVerticalPlayer2 - MOVESPEED;
        break;

    case GLUT_KEY_END:

        xfirePlayer2[numoffireplayer2 % 10] = x;
        yfirePlayer2[numoffireplayer2 % 10] = y;
        fireVisiblePlayer2[numoffireplayer2 % 10] = 1;
        numoffireplayer2++;

    }

}

// timer function
void Timer(int value)
{

    // player 1
    for(i = 0; i<AMMOPlayer1; i++)
    {
        yfirePlayer1[i] += FIRESPEED;
    }

    for (i = 0; i<AMMOPlayer2; i++)
    {
        yfirePlayer2[i] -= FIRESPEED;
    }

    if (xP1 < -0.96)
    {
        xP1 = -0.96;
        moveHorizontalPlayer1 = 0;
    }
    if (xP1 > 0.69)
    {
        xP1 = 0.69;
        moveHorizontalPlayer1 = 0;
    }
    if (yP1 > 0.9)
    {
        yP1 = 0.9;
        moveVerticalPlayer1 = 0;
    }
    if (yP1 < -1.0)
    {
        yP1 = -1.0;
        moveVerticalPlayer1 = 0;
    }

    xP1 = xP1 + moveHorizontalPlayer1;
    yP1 = yP1 + moveVerticalPlayer1;

    if (moveHorizontalPlayer1 >= 0.0004)
    {
        moveHorizontalPlayer1 = moveHorizontalPlayer1 - 0.002;
    }
    else if (moveHorizontalPlayer1 <= (-0.0004))
    {
        moveHorizontalPlayer1 = moveHorizontalPlayer1 + 0.002;
    }
    else
    {
        moveHorizontalPlayer1 = 0;
    }

    if (moveVerticalPlayer1 >= 0.0004)
    {
        moveVerticalPlayer1 = moveVerticalPlayer1 - 0.002;
    }
    else if (moveVerticalPlayer1 <= (-0.0004))
    {
        moveVerticalPlayer1 = moveVerticalPlayer1 + 0.002;
    }
    else
    {
        moveVerticalPlayer1 = 0;
    }


    //player 2

    for(i = 0; i<AMMOPlayer1; i++)
    {
        yfirePlayer1[i] += FIRESPEED;
    }

    for (i = 0; i<AMMOPlayer2; i++)
    {
        yfirePlayer2[i] -= FIRESPEED;
    }

    if (x < -0.96)
    {
        x = -0.96;
        moveHorizontalPlayer2 = 0;
    }
    if (x > 0.69)
    {
        x = 0.69;
        moveHorizontalPlayer2 = 0;
    }
    if (y > 0.9)
    {
        y = 0.9;
        moveVerticalPlayer2 = 0;
    }
    if (y < -1.55)
    {
        y = -1.55;
        moveVerticalPlayer2 = 0;
    }

    x = x + moveHorizontalPlayer2;
    y = y + moveVerticalPlayer2;

    if (moveHorizontalPlayer2 >= 0.0004)
    {
        moveHorizontalPlayer2 = moveHorizontalPlayer2 - 0.002;
    }
    else if (moveHorizontalPlayer2 <= (-0.0004))
    {
        moveHorizontalPlayer2 = moveHorizontalPlayer2 + 0.002;
    }
    else
    {
        moveHorizontalPlayer2 = 0;
    }

    if (moveVerticalPlayer2 >= 0.0004)
    {
        moveVerticalPlayer2 = moveVerticalPlayer2 - 0.002;
    }
    else if (moveVerticalPlayer2 <= (-0.0004))
    {
        moveVerticalPlayer2 = moveVerticalPlayer2 + 0.002;
    }
    else
    {
        moveVerticalPlayer2 = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(Refresh, Timer, 0); //call timer again in 20 milliseconds (Refresh = 20)
    RefreshP2 += Refresh;

    RefreshP3 += Refresh;

    //player 2 auto fire
    if (xP1 + 0.2 >= x && xP1 - 0.2 <= x)
    {
        if (RefreshP2 >= 30)
        {
            xfirePlayer2[numoffireplayer2 % 10] = x;
            yfirePlayer2[numoffireplayer2 % 10] = y;
            fireVisiblePlayer2[numoffireplayer2 % 10] = 1;
            numoffireplayer2++;
            RefreshP2 = 0;
        }


    }

    /*//player 1 auto fire
    if (x + 0.2 >= xbat && x - 0.2 <= xbat)
    {
        if (RefreshP3 >= 30)
        {
            xfirePlayer1[numoffireplayer1 % 10] = xbat;
            yfirePlayer1[numoffireplayer1 % 10] = ybat;
            fireVisiblePlayer1[numoffireplayer1 % 10] = 1;
            numoffireplayer1++;
            RefreshP3 = 0;
        }


    }*/


}

/*void printtxt()
{
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);
    stringPrint(0.84, -0.1, text1);
    //stringPrint(0.84, 0.011, text2);
    glEnd();
}*/

void Display()
{
    // player 1 green tank
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(xP1, yP1, 0);
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_POLYGON);            // body of tank
    glVertex2d(-0.05, 0.050);
    glVertex2d(-0.05, -0.050);
    glVertex2d(0.1, -0.05);
    glVertex2d(0.1, 0.05);
    glEnd();

    glLineWidth(15.0);
    glBegin(GL_LINES);              // barrel of tank
    glVertex2f(0.025, 0.15);
    glVertex2f(0.025, 0.00);

    glEnd();

    //player 2 red tank
    if(twobatvisible == 1)
    {
        glLoadIdentity();
        glTranslatef(x, y, 0);
        glBegin(GL_POLYGON);            // body of tank
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.1, 0.85);
        glVertex2f(-0.1, 0.75);
        glVertex2f(0.15, 0.75);
        glVertex2f(0.15, 0.85);
        glEnd();

        glLineWidth(15.0);
        glBegin(GL_LINES);              // barrel of tank
        glVertex2f(0.025, 0.8);
        glVertex2f(0.025, 0.65);
        glEnd();

    }

    glLoadIdentity();
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(0.8, -1.0);
    glVertex2f(0.8, 1.0);
    glEnd();

    // player 1 health bar
    glLoadIdentity();
    glTranslatef(0.9, 0.5, 0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.08, powerPlayer1);
    glVertex2f(-0.08, -0.4);
    glVertex2f(0.08, -0.4);
    glVertex2f(0.08, powerPlayer1);
    glEnd();

    // player 2 health bar
    glLoadIdentity();
    glTranslatef(0.9, -0.5, 0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.08, powerPlayer2);
    glVertex2f(-0.08, -0.4);
    glVertex2f(0.08, -0.4);
    glVertex2f(0.08, powerPlayer2);
    glEnd();

    //text print
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);
    stringPrint(0.84, -0.95, text1);    // player 1 text
    stringPrint(0.84, 0.011, text2);    // player 2 text
    glEnd();

    // player 1 fire ball
    for(i = 0; i<AMMOPlayer1; i++)
    {
        if(fireVisiblePlayer1[i]==1)
        {
            glLoadIdentity();
            glColor3f(0.0f, 1.0f, 0.0f);
            glTranslatef(xfirePlayer1[i] + 0.02, yfirePlayer1[i] + 0.09, 0);
            glutSolidSphere(0.01, 10, 10);
        }
    }

    // player 2 fire ball
    for(i = 0; i<AMMOPlayer2; i++)
    {
        if(fireVisiblePlayer2[i]==1)
        {
            glLoadIdentity();
            glColor3f(1.0f, 0.0f, 0.0f);
            glTranslatef(xfirePlayer2[i] + 0.025, yfirePlayer2[i] + 0.55, 0);
            glutSolidSphere(0.01, 10, 10);
        }
    }

    //for deducting player 2 health
    for(i=0; i<AMMOPlayer1; i++)
    {
        if(fireVisiblePlayer1[i] == 1 && (x < xfirePlayer1[i] + 0.09 && x > xfirePlayer1[i] - 0.09) && y > yfirePlayer1[i])
        {
            if(powerPlayer1 > -0.4)
            {
                powerPlayer1 = powerPlayer1 - 0.003;
            }
        }

    }

    //for deducting player 1 health
    for(i=0; i<AMMOPlayer2; i++)
    {
        if(fireVisiblePlayer2[i] == 1 && (xP1 < xfirePlayer2[i] + 0.09 && xP1 > xfirePlayer2[i] - 0.09) && yP1 < yfirePlayer2[i])
        {
            if(powerPlayer2 > -0.4)
            {
                powerPlayer2 = powerPlayer2 - 0.001;
            }
        }

    }


    glutSwapBuffers();
}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1367, 720);
    glutInitWindowPosition(500, 70);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("tank war");
    glutDisplayFunc(Display);
    glutTimerFunc(Refresh, Timer, 0);       //add a timer
    glutKeyboardFunc(controlPlayer1);
    glutSpecialFunc(controlPlayer2);


    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}


