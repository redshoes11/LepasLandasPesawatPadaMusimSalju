// UTS GRAFIKA KOMPUTER 4
// Tessa Agitha Iwani Br Barus
// NIM : 211401138

#include<stdio.h>
#include<windows.h>
#include<glut.h>

GLfloat a = 0, b = 0, c = 0, d = 0, e = 0;

int snowX[100];
int snowY[100];

void runway();
void update(int value)
{
    a += 15.0;	
    b -= 10.0;	
    c += 15;	   

    if (b <= -80.0)
        b = 0.0;
    glutPostRedisplay();
    glutTimerFunc(200, update, 0);
}

void runway()
{
    glColor3ub(31, 29, 29);
    glBegin(GL_POLYGON);//jalan
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 100.0);
    glVertex2f(500.0, 100.0);
    glVertex2f(500.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON); //garis putih di jalan
    glVertex2f(0.0, 40.0);
    glVertex2f(8.0, 60.0);
    glVertex2f(58.0, 60.0);
    glVertex2f(50.0, 40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(100.0, 40.0);
    glVertex2f(108.0, 60.0);
    glVertex2f(158.0, 60.0);
    glVertex2f(150.0, 40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200.0, 40.0);
    glVertex2f(208.0, 60.0);
    glVertex2f(258.0, 60.0);
    glVertex2f(250.0, 40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(300.0, 40.0);
    glVertex2f(308.0, 60.0);
    glVertex2f(358.0, 60.0);
    glVertex2f(350.0, 40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(400.0, 40.0);
    glVertex2f(408.0, 60.0);
    glVertex2f(458.0, 60.0);
    glVertex2f(450.0, 40.0);
    glEnd();
    glPopMatrix();
}

void myinit()
{
    glClearColor(0.70258f, 0.75338f, 1.04609f, 0.0f);
    glColor3f(1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500, 0.0, 500);

    // Inisialisasi posisi awal salju
    for (int i = 0; i < 100; i++) {
        snowX[i] = rand() % 800;
        snowY[i] = rand() % 600;
    }
}

void write(float x, float y, float z, void* font, const char* string) {
    glColor3f(1, 1, 0);
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    runway();

    ///--------BODY OF THE PLANE----------
    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3ub(255, 91, 54);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 30.0);
    glVertex2f(0.0, 55.0);
    glVertex2f(135.0, 55.0);
    glVertex2f(135.0, 30.0);
    glEnd();
    glPopMatrix();
    ///--------COCKPIT OF THE PLANE----------
    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3ub(203, 228, 254);
    glBegin(GL_POLYGON);
    glVertex2f(135.0, 55.0);
    glVertex2f(150.0, 50.0);
    glVertex2f(155.0, 45.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(135.0, 40.0);
    glEnd();
    glPopMatrix();
    ///--------COCKPIT OUTLINE DIVIDER----------
    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(135.0, 55.0);
    glVertex2f(150.0, 50.0);
    glVertex2f(155.0, 45.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(135.0, 40.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3f(0.35, 0.35, 0.35);
    glBegin(GL_POLYGON);
    glVertex2f(135.0, 40.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(160.0, 37.0);
    glVertex2f(145.0, 30.0);
    glVertex2f(135.0, 30.0);
    glEnd();
    glPopMatrix();

    ///---------TAIL-------------
    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3ub(62, 49, 59);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 55.0);
    glVertex2f(0.0, 80.0);
    glVertex2f(10.0, 80.0);
    glVertex2f(40.0, 55.0);
    glEnd();
    glPopMatrix();

    ///---------LEFT WING-------------
    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3ub(62, 49, 59);
    glBegin(GL_POLYGON);
    glVertex2f(65.0, 55.0);
    glVertex2f(50.0, 70.0);
    glVertex2f(75.0, 70.0);
    glVertex2f(90.0, 55.0);
    glEnd();
    glPopMatrix();
    ///---------RIGHT WING-------------
    glPushMatrix();
    glTranslated(a, c, 0.0);
    glColor3ub(62, 49, 59);
    glBegin(GL_POLYGON);
    glVertex2f(70.0, 40.0);
    glVertex2f(100.0, 40.0);
    glVertex2f(80.0, 15.0);
    glVertex2f(50.0, 15.0);
    glEnd();

    glPopMatrix();
    glFlush();

    glColor3f(1.0, 1.0, 1.0); // Warna salju putih

    // Menggambar salju
    glPointSize(4.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; i++) {
        glVertex2i(snowX[i], snowY[i]);
    }
    glEnd();

    if (a > 500) write(155, 310, 0, GLUT_BITMAP_HELVETICA_18,
        "Pesawat telah berhasil lepas landas.");
    if (a > 500) write(155, 270, 0, GLUT_BITMAP_HELVETICA_18,
        "Tekan ENTER untuk keluar.");
    if (a > 500) write(155, 250, 0, GLUT_BITMAP_TIMES_ROMAN_10,
        "Project by Tessa Agitha (211401138)");

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 13: //tombol enter untuk exit(0);
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void snowAnimation(int value) {
    // Memperbarui posisi salju ke bawah
    for (int i = 0; i < 100; i++) {
        snowY[i] -= 1;

        // Jika salju mencapai bawah jendela, reset ke atas
        if (snowY[i] < 0) {
            snowY[i] = 600;
            snowX[i] = rand() % 800;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, snowAnimation, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(620, 620);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Lepas Landas Pesawat");
    glutDisplayFunc(display);
    myinit();
    glutTimerFunc(20, snowAnimation, 0);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}