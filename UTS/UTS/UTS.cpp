// UTS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gl/glut.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
int nTitik = 0;
float koordinatX = 0, koordinatY, koordXM, koordYM = 240, koordYM2 = 480;
bool done = false; bool done2 = false;
void write(float x, float y, float z, void* font, const char* string)
{
    glColor3f(1, 1, 1);
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void ally()
{
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.9, 0.9);
    glVertex2f(koordinatX + 30, koordinatY + 30);
    glVertex2f(koordinatX, koordinatY + 30);
    glColor3f(0.7, 0.5, 0.8);
    glVertex2f(koordinatX, koordinatY);
    glVertex2f(koordinatX + 30, koordinatY);
    glEnd();
    
}
void finish()
{
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(480, 640);
    glVertex2f(450, 640);
    glVertex2f(450, 0);
    glVertex2f(480, 0);
    glEnd();
}
void musuh()
{
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(koordXM + 30, koordYM + 30);
    glVertex2f(koordXM + 30, koordYM);
    glColor3f(0.9, 0.9, 0.8);
    glVertex2f(koordXM, koordYM);
    glVertex2f(koordXM, koordYM + 30);
    glEnd();
}
void musuh2()
{
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(koordXM + 30, koordYM2);
    glVertex2f(koordXM + 30, koordYM2 - 30);
    glColor3f(0.7, 0.8, 0.7);
    glVertex2f(koordXM, koordYM2 - 30);
    glVertex2f(koordXM, koordYM2);
    glEnd();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 13: //tombol enter exit(0);
        if(done) exit(0);
        break;
    case 27: //Tombol escape
        exit(0);
        break;
    case 'd':
    case 'D':
        koordinatX += 10;
        koordXM += 15;
        break;  
    case'b':
    case'B':
        koordinatX += 15;
        koordXM += 10;
        break;
    }
    if (koordinatX > 420) done = true;
    if (koordXM > 420 && koordinatX <=420) done2 = true;
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        koordinatY += 10;
        koordYM -= 10;
        koordYM2 -= 25;
    }
}
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    finish();
    ally();
    musuh();
    musuh2();
    if (done)
    {
        if (done2) write(0, 25.0f, 0, GLUT_BITMAP_HELVETICA_18, "You Lose the Race, Press Enter to exit");
        else write(0, 25.0f, 0, GLUT_BITMAP_HELVETICA_18, "You Win the match, Hooray~ , Press Enter to exit");
    }
    glutSwapBuffers();
}
static void update()
{
    // Atur panjang titik
    if (koordinatX < 480) koordinatX += 0.3;
    else
    {
        done = true;
        glutKeyboardFunc(keyboard);
    }
    glutPostRedisplay();
}
int main()
{
    glutInit(&__argc, __argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Racing block(Prototype ver.)");
    glClearColor(0.5, 0.3, 0.5, 0.4);
    gluOrtho2D(0, 480, 0, 480);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
