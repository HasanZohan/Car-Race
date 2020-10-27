 #include <stdlib.h>
#include<Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/GLAUX.h>

#define PI 3.1416

int i,q;
int score = 0;//for score counting
int screen = 0;
bool collide = false;//check if car collide to make game over
char buffer[10];

int vehicleX = 200, vehicleY = 70;
int ovehicleX[4], ovehicleY[4];
int divx = 250, divy = 4, movd;
int temp_score=0;



void drawText(char ch[],int xpos, int ypos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}


void drawTextNum(char ch[],int numtext,int xpos, int ypos)//counting the score
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }

    }
}




void ovpos()
{
    glClearColor(0.8,0.5,0.3,0);
for(i = 0; i < 4; i++)
{
    if(rand() % 3 == 0)
    {
        ovehicleX[i] = 200;
    }
    else
    {
        ovehicleX[i] = 300;
    }
  //  ovehicleY[i] = 100 - i * 160;
}
}


void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}


void drawTree1()
{
    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(75,400,0);
        circle(13,17);

    glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(62,399,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(88,399,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(68.5,411,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(81.5,411,0);
        circle(12,16);

	glPopMatrix();

	glBegin(GL_QUADS);
        glColor3f(0.7,0.2,0.2);
        glVertex2f(71, 383);
        glVertex2f(71, 360);
        glVertex2f(79, 360);
        glVertex2f(79, 383);
    glEnd();
}

void drawTree2()
{
    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(75,280,0);
        circle(13,17);

    glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(62,279,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(88,279,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(68.5,291,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(81.5,291,0);
        circle(12,16);

	glPopMatrix();

	glBegin(GL_QUADS);
        glColor3f(0.7,0.2,0.2);
        glVertex2f(71, 263);
        glVertex2f(71, 240);
        glVertex2f(79, 240);
        glVertex2f(79, 263);
    glEnd();
}

void drawTree3()
{
    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(75,160,0);
        circle(13,17);

    glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(62,159,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(88,159,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(68.5,171,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(81.5,171,0);
        circle(12,16);

	glPopMatrix();

	glBegin(GL_QUADS);
        glColor3f(0.7,0.2,0.2);
        glVertex2f(71, 143);
        glVertex2f(71, 120);
        glVertex2f(79, 120);
        glVertex2f(79, 143);
    glEnd();
}

void drawTree4()
{
    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(425,400,0);
        circle(13,17);

    glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(412,399,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(438,399,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(418.5,411,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(431.5,411,0);
        circle(12,16);

	glPopMatrix();

	glBegin(GL_QUADS);
        glColor3f(0.7,0.2,0.2);
        glVertex2f(421, 383);
        glVertex2f(421, 360);
        glVertex2f(429, 360);
        glVertex2f(429, 383);
    glEnd();
}

void drawTree5()
{
    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(425,280,0);
        circle(13,17);

    glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(412,279,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(438,279,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(418.5,291,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(431.5,291,0);
        circle(12,16);

	glPopMatrix();

	glBegin(GL_QUADS);
        glColor3f(0.7,0.2,0.2);
        glVertex2f(421, 263);
        glVertex2f(421, 240);
        glVertex2f(429, 240);
        glVertex2f(429, 263);
    glEnd();
}

void drawTree6()
{
    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(425,160,0);
        circle(13,17);

    glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(412,159,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(438,159,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(418.5,171,0);
        circle(12,16);

	glPopMatrix();

	glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(431.5,171,0);
        circle(12,16);

	glPopMatrix();

	glBegin(GL_QUADS);
        glColor3f(0.7,0.2,0.2);
        glVertex2f(421, 143);
        glVertex2f(421, 120);
        glVertex2f(429, 120);
        glVertex2f(429, 143);
    glEnd();
}

void drawRoad()
{
    glBegin(GL_QUADS);
        glColor3f(0.5,0.5,0.5);
        glVertex2f(250 - 100, 500);
        glVertex2f(250 - 100, 0);
        glVertex2f(250 + 100, 0);
        glVertex2f(250 + 100, 500);
    glEnd();
}


void drawDivider()//black patch drawn in middle of road
{
    glPushMatrix();
    glTranslatef(0, movd, 0);
    for(i = 1; i <= 10; i++)
    {
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(divx  - 5, divy * 15 * i + 18);
        glVertex2f(divx  - 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i - 18);
        glVertex2f(divx  + 5, divy * 15 * i + 18);
    glEnd();
    }
    glPopMatrix();
}


void drawVehicle()//car for racing
{
    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(vehicleX - 25, vehicleY + 16);
        glVertex2f(vehicleX + 25, vehicleY + 16);
        glVertex2f(vehicleX - 25, vehicleY - 16);
        glVertex2f(vehicleX + 25, vehicleY - 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1,0,0);//middle body
        glVertex2f(vehicleX - 25, vehicleY + 20);
        glVertex2f(vehicleX - 25, vehicleY - 20);
        glVertex2f(vehicleX + 25, vehicleY - 20);
        glVertex2f(vehicleX + 25, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0,0,1);
        glVertex2f(vehicleX - 23, vehicleY + 20);
        glVertex2f(vehicleX - 19, vehicleY + 40);
        glVertex2f(vehicleX + 19, vehicleY + 40);
        glVertex2f(vehicleX + 23, vehicleY + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0,0,1);
        glVertex2f(vehicleX - 23, vehicleY - 20);
        glVertex2f(vehicleX - 19, vehicleY - 35);
        glVertex2f(vehicleX + 19, vehicleY - 35);
        glVertex2f(vehicleX + 23, vehicleY - 20);
    glEnd();
 }

void drawOVehicle()//other cars
{

    for(i = 0; i < 4; i++)
    {
    glPointSize(10.0);
    glBegin(GL_POINTS);//tire
        glColor3f(0,0,0);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 16);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 16);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 16);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.99609, 0.83984, 0);//middle body
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 25, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] + 25, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//up body
        glColor3f(0,1,0);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] + 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] + 40);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] + 20);
    glEnd();

    glBegin(GL_QUADS);//down body
        glColor3f(0,1,0);
        glVertex2f(ovehicleX[i] - 23, ovehicleY[i] - 20);
        glVertex2f(ovehicleX[i] - 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 19, ovehicleY[i] - 35);
        glVertex2f(ovehicleX[i] + 23, ovehicleY[i] - 20);
    glEnd();

    ovehicleY[i] = ovehicleY[i] - 8;

    if(ovehicleY[i] > vehicleY - 50 && ovehicleY[i] < vehicleY + 50 && ovehicleX[i] == vehicleX)
    {
        collide = true;
    }

    if(ovehicleY[i] < 0){

        temp_score = temp_score + 1;
    }


    if(ovehicleY[i] < -25)
    {


        if(rand() % 2 == 0)
        {
            ovehicleX[i] = 200;
        }
        else
        {
            ovehicleX[i] = 300;

          }
        ovehicleY[i] = 800;
    }
    }
}

void Specialkey(int key, int x, int y)//allow to use navigation key for movement of car
{
switch(key)
{
case GLUT_KEY_UP:
	for(i = 0; i <4; i++)
             {
              ovehicleY[i] = ovehicleY[i] - 10;
             }
             movd = movd - 20;

             vehicleY = vehicleY +5;

             break;
case GLUT_KEY_DOWN:
	for(i = 0; i <4; i++)
             {
              ovehicleY[i] = ovehicleY[i] + 10;
             }
             movd = movd + 20;

             vehicleY = vehicleY -5;

             break;
case GLUT_KEY_LEFT:vehicleX = 200;
             break;
case GLUT_KEY_RIGHT:vehicleX = 300;
             break;

}

glutPostRedisplay();
}

void Normalkey(unsigned char key, int x, int y)
{
    switch(key)
    {
   case 'z':
			vehicleY = 320;
			break;

   case 'x':
			vehicleY = 70;
			break;

    }
}


void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 500, 0, 500);
glMatrixMode(GL_MODELVIEW);
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawTree1();
    drawTree2();
    drawTree3();
    drawTree4();
    drawTree5();
    drawTree6();
    drawRoad();
    drawDivider();
    drawVehicle();
    drawOVehicle();
    movd = movd - 16;
    if(movd < - 60)
    {
        movd = 0;
    }


    glColor3f(1,1,1);
    drawText("Score:", 360,455);
    itoa (temp_score, buffer, 10);
    drawTextNum(buffer, 6, 420,455);
    glutSwapBuffers();
    for(q = 0; q<= 10000000; q++){;}
    if(collide == true)
    {
        glColor3f(0,0,0);
        drawText("Game Over", 200,250);
        glutSwapBuffers();
        getchar();
        //exit(0);
    }
    //}
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,500);
    glutCreateWindow("2D Car Racing game");
    ovpos();
    init();
    glutDisplayFunc(display);
	glutSpecialFunc(Specialkey);
    glutKeyboardFunc(Normalkey);
    glutIdleFunc(display);
    glutMainLoop();
}
