#include <GL/glut.h>
#include <stdio.h>
#include<Windows.h>
#include "math.h"

/*
NAMA KELOMPOK       = GTR
TEMA TR             = CHINA

ANGGOTA KELOMPOK    
1.RICHARD WILIAM KHO    ( 672019167 )
2.GAMA ARSETA           ( 672019177 )
3.TIAN BASKORO          ( 672019191 )

*/

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mousemotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float PI = 3.141592653589793;
int i;
bool mousedown = false;

int is_depth;
void myinit() {
    glClearColor(0, 230, 255, 255);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(4.0);
    glLineWidth(3.0f);
}


void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
    glBegin(GL_POLYGON);
    for (i = 0;i <= 360;i++) {
        GLfloat sudut = i * (2 * PI / jumlah_titik);
        GLfloat x = x_tengah + radius * cos(sudut);
        GLfloat y = y_tengah + radius * sin(sudut);
        glVertex3f(x, y, -70.0f);
    }
    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS); // JALAN DEPAN
    glColor3ub(0, 0, 0);
    glVertex3f(42.0f, -0.1f, 20.5f);
    glVertex3f(42.0f, -0.1f, 5.0f);
    glVertex3f(-58.7f, -0.1f, 5.0f);
    glVertex3f(-58.7f, -0.1f, 20.5f);
    glEnd();

    glBegin(GL_QUADS); // HALAMAN
    glColor3ub(153, 153, 153);
    glVertex3f(42.0f, -0.1f, 5.0f);
    glVertex3f(42.0f, -0.1f, -100.0f);
    glVertex3f(-58.7f, -0.1f, -100.0f);
    glVertex3f(-58.7f, -0.1f, 5.0f);
    glEnd();

    //PAGAR DEPAN 

    glBegin(GL_QUADS);
    glColor3ub(71, 209, 71);
    glVertex3f(0.0f, 0.1f, -9.5f);
    glVertex3f(0.0f, 0.1f, 0.0f);
    glVertex3f(-18.7f, 0.1f, 0.0f);
    glVertex3f(-18.7f, 0.1f, -9.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(0.0f, 0.0f, -9.5f);
    glVertex3f(0.0f, 2.0f, -9.5f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(-18.7f, 0.0f, -9.5f);
    glVertex3f(-18.7f, 2.0f, -9.5f);
    glVertex3f(-18.7f, 2.0f, 0.0f);
    glVertex3f(-18.7f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(0.0f, 0.0f, -9.5f);
    glVertex3f(0.0f, 2.0f, -9.5f);
    glVertex3f(-18.7f, 2.0f, -9.5f);
    glVertex3f(-18.7f, 0.0f, -9.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(-18.7f, 2.0f, 0.0f);
    glVertex3f(-18.7f, 0.0f, 0.0f);
    glEnd();

    // KOTAK DEPAN
    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(-2.0f, 5.0f, 0.0f);
    glVertex3f(-2.0f, 5.0f, 1.0f);
    glVertex3f(-16.7f, 5.0f, 1.0f);
    glVertex3f(-16.7f, 5.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(-2.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, 5.0f, 1.0f);
    glVertex3f(-16.7f, 5.0f, 1.0f);
    glVertex3f(-16.7f, 0.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, 5.0f, 0.0f);
    glVertex3f(-16.7f, 5.0f, 0.0f);
    glVertex3f(-16.7f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(-2.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, 5.0f, 1.0f);
    glVertex3f(-2.0f, 5.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 89, 0);
    glVertex3f(-16.7f, 0.0f, 1.0f);
    glVertex3f(-16.7f, 5.0f, 1.0f);
    glVertex3f(-16.7f, 5.0f, 0.0f);
    glVertex3f(-16.7f, 0.0f, 0.0f);
    glEnd();

    //PENGHUBUNG GEDUNG 1 GEDUNG 2
    glBegin(GL_QUADS);//BAWAH
    glColor3ub(102, 102, 102);
    glVertex3f(-3.0f, 0.0f, -50.0f);
    glVertex3f(-3.0f, 0.0f, -25.0f);
    glVertex3f(-15.7f, 0.0f, -25.0f);
    glVertex3f(-15.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex3f(-3.0f, 1.0f, -50.0f);
    glVertex3f(-3.0f, 1.0f, -25.0f);
    glVertex3f(-15.7f, 1.0f, -25.0f);
    glVertex3f(-15.7f, 1.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 0.0f, -25.0f);
    glVertex3f(-3.0f, 1.0f, -25.0f);
    glVertex3f(-15.7f, 1.0f, -25.0f);
    glVertex3f(-15.7f, 0.0f, -25.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAS
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 10.0f, -50.0f);
    glVertex3f(-3.0f, 10.0f, -25.0f);
    glVertex3f(-15.7f, 10.0f, -25.0f);
    glVertex3f(-15.7f, 10.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 9.0f, -50.0f);
    glVertex3f(-3.0f, 9.0f, -25.0f);
    glVertex3f(-15.7f, 9.0f, -25.0f);
    glVertex3f(-15.7f, 9.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 9.0f, -25.0f);
    glVertex3f(-3.0f, 10.0f, -25.0f);
    glVertex3f(-15.7f, 10.0f, -25.0f);
    glVertex3f(-15.7f, 9.0f, -25.0f);
    glEnd();

    glBegin(GL_QUADS);//KIRI
    glColor3ub(222, 202, 102);
    glVertex3f(-15.0f, 10.0f, -25.0f);
    glVertex3f(-15.0f, 0.0f, -25.0f);
    glVertex3f(-15.7f, 0.0f, -25.0f);
    glVertex3f(-15.7f, 10.0f, -25.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-15.0f, 10.0f, -25.0f);
    glVertex3f(-15.0f, 0.0f, -25.0f);
    glVertex3f(-15.0f, 0.0f, -50.0f);
    glVertex3f(-15.0f, 10.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//KANAN
    glColor3ub(222, 202, 102);
    glVertex3f(-3.7f, 10.0f, -25.0f);
    glVertex3f(-3.7f, 0.0f, -25.0f);
    glVertex3f(-3.7f, 0.0f, -50.0f);
    glVertex3f(-3.7f, 10.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 10.0f, -25.0f);
    glVertex3f(-3.0f, 0.0f, -25.0f);
    glVertex3f(-3.7f, 0.0f, -25.0f);
    glVertex3f(-3.7f, 10.0f, -25.0f);
    glEnd();

    glBegin(GL_QUADS);//TIANG KANAN
    glColor3ub(222, 202, 102);
    glVertex3f(-4.7f, 11.0f, -15.0f);
    glVertex3f(-4.7f, 0.0f, -15.0f);
    glVertex3f(-4.7f, 0.0f, -16.0f);
    glVertex3f(-4.7f, 11.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-4.0f, 11.0f, -15.0f);
    glVertex3f(-4.0f, 0.0f, -15.0f);
    glVertex3f(-4.0f, 0.0f, -16.0f);
    glVertex3f(-4.0f, 11.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-4.0f, 11.0f, -15.0f);
    glVertex3f(-4.0f, 0.0f, -15.0f);
    glVertex3f(-4.7f, 0.0f, -15.0f);
    glVertex3f(-4.7f, 11.0f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-4.0f, 11.0f, -16.0f);
    glVertex3f(-4.0f, 0.0f, -16.0f);
    glVertex3f(-4.7f, 0.0f, -16.0f);
    glVertex3f(-4.7f, 11.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);//TIANG KIRI
    glColor3ub(222, 202, 102);
    glVertex3f(-14.7f, 11.0f, -15.0f);
    glVertex3f(-14.7f, 0.0f, -15.0f);
    glVertex3f(-14.7f, 0.0f, -16.0f);
    glVertex3f(-14.7f, 11.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-14.0f, 11.0f, -15.0f);
    glVertex3f(-14.0f, 0.0f, -15.0f);
    glVertex3f(-14.0f, 0.0f, -16.0f);
    glVertex3f(-14.0f, 11.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-14.0f, 11.0f, -15.0f);
    glVertex3f(-14.0f, 0.0f, -15.0f);
    glVertex3f(-14.7f, 0.0f, -15.0f);
    glVertex3f(-14.7f, 11.0f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-14.0f, 11.0f, -16.0f);
    glVertex3f(-14.0f, 0.0f, -16.0f);
    glVertex3f(-14.7f, 0.0f, -16.0f);
    glVertex3f(-14.7f, 11.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);//BAWAH
    glColor3ub(102, 102, 102);
    glVertex3f(-3.0f, 11.0f, -15.0f);
    glVertex3f(-3.0f, 11.0f, -25.0f);
    glVertex3f(-15.7f, 11.0f, -25.0f);
    glVertex3f(-15.7f, 11.0f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 102, 102);
    glVertex3f(-3.0f, 12.0f, -15.0f);
    glVertex3f(-3.0f, 12.0f, -25.0f);
    glVertex3f(-15.7f, 12.0f, -25.0f);
    glVertex3f(-15.7f, 12.0f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 11.0f, -25.0f);
    glVertex3f(-3.0f, 12.0f, -25.0f);
    glVertex3f(-15.7f, 12.0f, -25.0f);
    glVertex3f(-15.7f, 11.0f, -25.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(222, 202, 102);
    glVertex3f(-3.0f, 11.0f, -15.0f);
    glVertex3f(-3.0f, 12.0f, -15.0f);
    glVertex3f(-15.7f, 12.0f, -15.0f);
    glVertex3f(-15.7f, 11.0f, -15.0f);
    glEnd();

    //GEDUNG 1

    glBegin(GL_QUADS);
    glColor3ub(0, 30, 30);
    glVertex3f(-3.0f, 0.0f, -50.0f);
    glVertex3f(-3.0f, 0.0f, -15.0f);
    glVertex3f(25.7f, 0.0f, -15.0f);
    glVertex3f(25.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(0.4f, 1.0f, -14.0f);
    glVertex3f(0.4f, 19.0f, -14.0f);
    glVertex3f(2.7f, 19.0f, -14.0f);
    glVertex3f(2.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(3.4f, 1.0f, -14.0f);
    glVertex3f(3.4f, 19.0f, -14.0f);
    glVertex3f(5.7f, 19.0f, -14.0f);
    glVertex3f(5.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(6.4f, 1.0f, -14.0f);
    glVertex3f(6.4f, 19.0f, -14.0f);
    glVertex3f(8.7f, 19.0f, -14.0f);
    glVertex3f(8.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(9.4f, 1.0f, -14.0f);
    glVertex3f(9.4f, 19.0f, -14.0f);
    glVertex3f(11.7f, 19.0f, -14.0f);
    glVertex3f(11.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 0.0f, -15.0f);
    glVertex3f(-3.0f, 20.0f, -15.0f);
    glVertex3f(25.7f, 20.0f, -15.0f);
    glVertex3f(25.7f, 0.0f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 0.0f, -16.0f);
    glVertex3f(-3.0f, 20.0f, -16.0f);
    glVertex3f(25.7f, 20.0f, -16.0f);
    glVertex3f(25.7f, 0.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 0.0f, -50.0f);
    glVertex3f(-3.0f, 20.0f, -50.0f);
    glVertex3f(25.7f, 20.0f, -50.0f);
    glVertex3f(25.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 0.0f, -49.0f);
    glVertex3f(-3.0f, 20.0f, -49.0f);
    glVertex3f(25.7f, 20.0f, -49.0f);
    glVertex3f(25.7f, 0.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 0.0f, -15.0f);
    glVertex3f(-3.0f, 20.0f, -15.0f);
    glVertex3f(-3.0f, 20.0f, -50.0f);
    glVertex3f(-3.0f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-2.0f, 0.0f, -15.0f);
    glVertex3f(-2.0f, 20.0, -15.0f);
    glVertex3f(-2.0f, 20.0f, -50.0f);
    glVertex3f(-2.0f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(25.7f, 0.0f, -15.0f);
    glVertex3f(25.7f, 20.0f, -15.0f);
    glVertex3f(25.7f, 20.0, -50.0f);
    glVertex3f(25.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(24.7f, 0.0f, -15.0f);
    glVertex3f(24.7f, 20.0f, -15.0f);
    glVertex3f(24.7f, 20.0f, -50.0f);
    glVertex3f(24.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3ub(102, 51, 0);
    glVertex3f(27.7f, 20.0f, -13.0f);
    glVertex3f(27.7f, 20.0f, -52.0f);
    glVertex3f(-5.0f, 20.0f, -52.0f);
    glVertex3f(-5.0f, 20.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3ub(102, 51, 0);
    glVertex3f(27.7f, 21.0f, -13.0f);
    glVertex3f(27.7f, 21.0f, -52.0f);
    glVertex3f(-5.0f, 21.0f, -52.0f);
    glVertex3f(-5.0f, 21.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(27.7f, 20.0f, -13.0f);
    glVertex3f(27.7f, 21.0f, -13.0f);
    glVertex3f(-5.0f, 21.0f, -13.0f);
    glVertex3f(-5.0f, 20.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(27.7f, 20.0f, -52.0f);
    glVertex3f(27.7f, 21.0f, -52.0f);
    glVertex3f(-5.0f, 21.0f, -52.0f);
    glVertex3f(-5.0f, 20.0f, -52.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(27.7f, 20.0f, -13.0f);
    glVertex3f(27.7f, 21.0f, -13.0f);
    glVertex3f(27.7f, 21.0f, -52.0f);
    glVertex3f(27.7f, 20.0f, -52.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-5.0f, 20.0f, -13.0f);
    glVertex3f(-5.0f, 21.0f, -13.0f);
    glVertex3f(-5.0f, 21.0f, -52.0f);
    glVertex3f(-5.0f, 20.0f, -52.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2
    glColor3ub(102, 51, 0);
    glVertex3f(25.7f, 21.0f, -17.0f);
    glVertex3f(25.7f, 21.0f, -48.0f);
    glVertex3f(-3.0f, 21.0f, -48.0f);
    glVertex3f(-3.0f, 21.0f, -17.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2
    glColor3ub(102, 51, 0);
    glVertex3f(25.7f, 22.0f, -17.0f);
    glVertex3f(25.7f, 22.0f, -48.0f);
    glVertex3f(-3.0f, 22.0f, -48.0f);
    glVertex3f(-3.0f, 22.0f, -17.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(25.7f, 21.0f, -17.0f);
    glVertex3f(25.7f, 22.0f, -17.0f);
    glVertex3f(-3.0f, 22.0f, -17.0f);
    glVertex3f(-3.0f, 21.0f, -17.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(25.7f, 21.0f, -48.0f);
    glVertex3f(25.7f, 22.0f, -48.0f);
    glVertex3f(-3.0f, 22.0f, -48.0f);
    glVertex3f(-3.0f, 21.0f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(25.7f, 21.0f, -17.0f);
    glVertex3f(25.7f, 22.0f, -17.0f);
    glVertex3f(25.7f, 22.0f, -48.0f);
    glVertex3f(25.7f, 21.0f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 21.0f, -17.0f);
    glVertex3f(-3.0f, 22.0f, -17.0f);
    glVertex3f(-3.0f, 22.0f, -48.0f);
    glVertex3f(-3.0f, 21.0f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-3.0f, 1.0f, -14.0f);
    glVertex3f(-3.0f, 3.0f, -14.0f);
    glVertex3f(-3.0f, 3.0f, -14.0f);
    glVertex3f(-3.0f, 1.0f, -14.0f);
    glEnd();

    //GEDUNG 2

    glBegin(GL_QUADS);
    glColor3ub(0, 30, 30);
    glVertex3f(-45.0f, 0.0f, -50.0f);
    glVertex3f(-45.0f, 0.0f, -15.0f);
    glVertex3f(-15.7f, 0.0f, -15.0f);
    glVertex3f(-15.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-18.4f, 1.0f, -14.0f);
    glVertex3f(-18.4f, 19.0f, -14.0f);
    glVertex3f(-20.7f, 19.0f, -14.0f);
    glVertex3f(-20.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-21.4f, 1.0f, -14.0f);
    glVertex3f(-21.4f, 19.0f, -14.0f);
    glVertex3f(-23.7f, 19.0f, -14.0f);
    glVertex3f(-23.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-24.4f, 1.0f, -14.0f);
    glVertex3f(-24.4f, 19.0f, -14.0f);
    glVertex3f(-26.7f, 19.0f, -14.0f);
    glVertex3f(-26.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-27.4f, 1.0f, -14.0f);
    glVertex3f(-27.4f, 19.0f, -14.0f);
    glVertex3f(-29.7f, 19.0f, -14.0f);
    glVertex3f(-29.7f, 1.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-45.0f, 0.0f, -15.0f);
    glVertex3f(-45.0f, 20.0f, -15.0f);
    glVertex3f(-15.7f, 20.0f, -15.0f);
    glVertex3f(-15.7f, 0.0f, -15.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-45.0f, 0.0f, -16.0f);
    glVertex3f(-45.0f, 20.0f, -16.0f);
    glVertex3f(-15.7f, 20.0f, -16.0f);
    glVertex3f(-15.7f, 0.0f, -16.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(-45.0f, 0.0f, -50.0f);
    glVertex3f(-45.0f, 20.0f, -50.0f);
    glVertex3f(-15.7f, 20.0f, -50.0f);
    glVertex3f(-15.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(-45.0f, 0.0f, -49.0f);
    glVertex3f(-45.0f, 20.0f, -49.0f);
    glVertex3f(-15.7f, 20.0f, -49.0f);
    glVertex3f(-15.7f, 0.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-45.0, 0.0f, -15.0f);
    glVertex3f(-45.0, 20.0f, -15.0f);
    glVertex3f(-45.0, 20.0f, -50.0f);
    glVertex3f(-45.0, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-44.0f, 0.0f, -15.0f);
    glVertex3f(-44.0f, 20.0f, -15.0f);
    glVertex3f(-44.0f, 20.0f, -50.0f);
    glVertex3f(-44.0f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(-15.7f, 0.0f, -15.0f);
    glVertex3f(-15.7f, 20.0f, -15.0f);
    glVertex3f(-15.7f, 20.0f, -50.0f);
    glVertex3f(-15.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(-16.7f, 0.0f, -15.0f);
    glVertex3f(-16.7f, 20.0f, -15.0f);
    glVertex3f(-16.7f, 20.0f, -50.0f);
    glVertex3f(-16.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3ub(102, 51, 0);
    glVertex3f(-13.7f, 20.0f, -13.0f);
    glVertex3f(-13.7f, 20.0f, -52.0f);
    glVertex3f(-47.0f, 20.0f, -52.0f);
    glVertex3f(-47.0f, 20.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3ub(102, 51, 0);
    glVertex3f(-13.7f, 21.0f, -13.0f);
    glVertex3f(-13.7f, 21.0f, -52.0f);
    glVertex3f(-47.0f, 21.0f, -52.0f);
    glVertex3f(-47.0f, 21.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-13.7f, 20.0f, -13.0f);
    glVertex3f(-13.7f, 21.0f, -13.0f);
    glVertex3f(-47.0f, 21.0f, -13.0f);
    glVertex3f(-47.0f, 20.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(-13.7f, 20.0f, -52.0f);
    glVertex3f(-13.7f, 21.0f, -52.0f);
    glVertex3f(-47.0f, 21.0f, -52.0f);
    glVertex3f(-47.0f, 20.0f, -52.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(-13.7f, 20.0f, -13.0f);
    glVertex3f(-13.7f, 21.0f, -13.0f);
    glVertex3f(-13.7f, 21.0f, -52.0f);
    glVertex3f(-13.7f, 20.0f, -52.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-47.0f, 20.0f, -13.0f);
    glVertex3f(-47.0f, 21.0f, -13.0f);
    glVertex3f(-47.0f, 21.0f, -52.0f);
    glVertex3f(-47.0f, 20.0f, -52.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2
    glColor3ub(102, 51, 0);
    glVertex3f(-15.7f, 21.0f, -17.0f);
    glVertex3f(-15.7f, 21.0f, -48.0f);
    glVertex3f(-45.0f, 21.0f, -48.0f);
    glVertex3f(-45.0f, 21.0f, -17.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2
    glColor3ub(102, 51, 0);
    glVertex3f(-15.7f, 22.0, -17.0f);
    glVertex3f(-15.7f, 22.0f, -48.0f);
    glVertex3f(-45.0f, 22.0f, -48.0f);
    glVertex3f(-45.0f, 22.0f, -17.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(-15.7f, 21.0f, -17.0f);
    glVertex3f(-15.7f, 22.0f, -17.0f);
    glVertex3f(-45.0f, 22.0f, -17.0f);
    glVertex3f(-45.0f, 21.0f, -17.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(-15.7f, 21.0f, -48.0f);
    glVertex3f(-15.7f, 22.0f, -48.0f);
    glVertex3f(-45.0f, 22.0f, -48.0f);
    glVertex3f(-45.0f, 21.0f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(-15.7f, 21.0f, -17.0f);
    glVertex3f(-15.7f, 22.0f, -17.0f);
    glVertex3f(-15.7f, 22.0f, -48.0f);
    glVertex3f(-15.7f, 21.0f, -48.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-45.0f, 21.0f, -17.0f);
    glVertex3f(-45.0f, 22.0f, -17.0f);
    glVertex3f(-45.0f, 22.0f, -48.0f);
    glVertex3f(-45.0f, 21.0f, -48.0f);
    glEnd();

    //GEDUNG 3

    glBegin(GL_QUADS);
    glColor3ub(0, 30, 30);
    glVertex3f(13.0f, 0.0f, -80.0f);
    glVertex3f(13.0f, 0.0f, -50.0f);
    glVertex3f(-30.7f, 0.0f, -50.0f);
    glVertex3f(-30.7f, 0.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(4.7f, 10.0f, -49.0f);
    glVertex3f(4.7f, 34.0f, -49.0f);
    glVertex3f(2.4f, 34.0f, -49.0f);
    glVertex3f(2.4f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(1.7f, 10.0f, -49.0f);
    glVertex3f(1.7f, 34.0f, -49.0f);
    glVertex3f(-0.7f, 34.0f, -49.0f);
    glVertex3f(-0.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-1.4f, 10.0f, -49.0f);
    glVertex3f(-1.4f, 34.0f, -49.0f);
    glVertex3f(-3.7f, 34.0f, -49.0f);
    glVertex3f(-3.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-4.4f, 10.0f, -49.0f);
    glVertex3f(-4.4f, 34.0f, -49.0f);
    glVertex3f(-6.7f, 34.0f, -49.0f);
    glVertex3f(-6.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-7.4f, 10.0f, -49.0f);
    glVertex3f(-7.4f, 34.0f, -49.0f);
    glVertex3f(-9.7f, 34.0f, -49.0f);
    glVertex3f(-9.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-10.4f, 10.0f, -49.0f);
    glVertex3f(-10.4f, 34.0f, -49.0f);
    glVertex3f(-12.7f, 34.0f, -49.0f);
    glVertex3f(-12.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-13.4f, 10.0f, -49.0f);
    glVertex3f(-13.4f, 34.0f, -49.0f);
    glVertex3f(-15.7f, 34.0f, -49.0f);
    glVertex3f(-15.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-16.4f, 10.0f, -49.0f);
    glVertex3f(-16.4f, 34.0f, -49.0f);
    glVertex3f(-18.7f, 34.0f, -49.0f);
    glVertex3f(-18.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-19.4f, 10.0f, -49.0f);
    glVertex3f(-19.4f, 34.0f, -49.0f);
    glVertex3f(-21.7f, 34.0f, -49.0f);
    glVertex3f(-21.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//JENDELA
    glColor3ub(0, 30, 30);
    glVertex3f(-22.4f, 10.0f, -49.0f);
    glVertex3f(-22.4f, 34.0f, -49.0f);
    glVertex3f(-24.7f, 34.0f, -49.0f);
    glVertex3f(-24.7f, 10.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(13.0f, 0.0f, -50.0f);
    glVertex3f(13.0f, 35.0f, -50.0f);
    glVertex3f(-30.7f, 35.0f, -50.0f);
    glVertex3f(-30.7f, 0.0f, -50.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(13.0f, 0.0f, -51.0f);
    glVertex3f(13.0f, 35.0f, -51.0f);
    glVertex3f(-30.7f, 35.0f, -51.0f);
    glVertex3f(-30.7f, 0.0f, -51.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(13.0f, 0.0f, -80.0f);
    glVertex3f(13.0f, 35.0f, -80.0f);
    glVertex3f(-30.7f, 35.0f, -80.0f);
    glVertex3f(-30.7f, 0.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(13.0f, 0.0f, -79.0f);
    glVertex3f(13.0f, 35.0f, -79.0f);
    glVertex3f(-30.7f, 35.0f, -79.0f);
    glVertex3f(-30.7f, 0.0f, -79.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(13.0f, 0.0f, -50.0f);
    glVertex3f(13.0f, 35.0f, -50.0f);
    glVertex3f(13.0f, 35.0f, -80.0f);
    glVertex3f(13.0f, 0.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(12.0f, 0.0f, -50.0f);
    glVertex3f(12.0f, 35.0f, -50.0f);
    glVertex3f(12.0f, 35.0f, -80.0f);
    glVertex3f(12.0f, 0.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(-30.7f, 0.0f, -50.0f);
    glVertex3f(-30.7f, 35.0f, -50.0f);
    glVertex3f(-30.7f, 35.0f, -80.0f);
    glVertex3f(-30.7f, 0.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//TEMBOK KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(-29.7f, 0.0f, -50.0f);
    glVertex3f(-29.7f, 35.0f, -50.0f);
    glVertex3f(-29.7f, 35.0f, -80.0f);
    glVertex3f(-29.7f, 0.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3ub(102, 51, 0);
    glVertex3f(14.7f, 35.0f, -47.0f);
    glVertex3f(14.7f, 35.0f, -82.0f);
    glVertex3f(-33.0f, 35.0f, -82.0f);
    glVertex3f(-33.0f, 35.0f, -47.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP
    glColor3ub(102, 51, 0);
    glVertex3f(14.7f, 36.0f, -47.0f);
    glVertex3f(14.7f, 36.0f, -82.0f);
    glVertex3f(-33.0f, 36.0f, -82.0f);
    glVertex3f(-33.0f, 36.0f, -47.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(14.7f, 35.0f, -47.0f);
    glVertex3f(14.7f, 36.0f, -47.0f);
    glVertex3f(-33.0f, 36.0f, -47.0f);
    glVertex3f(-33.0f, 35.0f, -47.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(14.7f, 35.0f, -82.0f);
    glVertex3f(14.7f, 36.0f, -82.0f);
    glVertex3f(-33.0f, 36.0f, -82.0f);
    glVertex3f(-33.0f, 35.0f, -82.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(14.7f, 35.0f, -47.0f);
    glVertex3f(14.7f, 36.0f, -47.0f);
    glVertex3f(14.7f, 36.0f, -82.0f);
    glVertex3f(14.7f, 35.0f, -82.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-33.0f, 35.0f, -47.0f);
    glVertex3f(-33.0f, 36.0f, -47.0f);
    glVertex3f(-33.0f, 36.0f, -82.0f);
    glVertex3f(-33.0f, 35.0f, -82.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2
    glColor3ub(102, 51, 0);
    glVertex3f(12.7f, 36.0f, -49.0f);
    glVertex3f(12.7f, 36.0f, -80.0f);
    glVertex3f(-31.0f, 36.0f, -80.0f);
    glVertex3f(-31.0f, 36.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2
    glColor3ub(102, 51, 0);
    glVertex3f(12.7f, 37.0f, -49.0f);
    glVertex3f(12.7f, 37.0f, -80.0f);
    glVertex3f(-31.0f, 37.0f, -80.0f);
    glVertex3f(-31.0f, 37.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 DEPAN
    glColor3ub(255, 217, 179);
    glVertex3f(12.7f, 36.0f, -49.0f);
    glVertex3f(12.7f, 37.0f, -49.0f);
    glVertex3f(-31.0f, 37.0f, -49.0f);
    glVertex3f(-31.0f, 36.0f, -49.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 BELAKANG
    glColor3ub(255, 217, 179);
    glVertex3f(12.7f, 36.0f, -80.0f);
    glVertex3f(12.7f, 37.0f, -80.0f);
    glVertex3f(-31.0f, 37.0f, -80.0f);
    glVertex3f(-31.0f, 36.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 KANAN
    glColor3ub(255, 217, 179);
    glVertex3f(12.7f, 36.0f, -49.0f);
    glVertex3f(12.7f, 37.0f, -49.0f);
    glVertex3f(12.7f, 37.0f, -80.0f);
    glVertex3f(12.7f, 36.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//ATAP2 KIRI
    glColor3ub(255, 217, 179);
    glVertex3f(-31.0f, 36.0f, -49.0f);
    glVertex3f(-31.0f, 37.0f, -49.0f);
    glVertex3f(-31.0f, 37.0f, -80.0f);
    glVertex3f(-31.0f, 36.0f, -80.0f);
    glEnd();

    glBegin(GL_QUADS);//MEJA DEPAN
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 0.00f, -34.03f);
    glVertex3f(16.51f, 0.00f, -34.03f);
    glVertex3f(16.51f, 2.53f, -34.03f);
    glVertex3f(14.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA BELAKANG
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 0.00f, -39.03f);
    glVertex3f(16.51f, 0.00f, -39.03f);
    glVertex3f(16.51f, 2.53f, -39.03f);
    glVertex3f(14.10f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KIRI
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 0.00f, -34.03f);
    glVertex3f(14.10f, 0.00f, -39.03f);
    glVertex3f(14.10f, 2.53f, -39.03f);
    glVertex3f(14.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KANAN
    glColor3ub(102, 51, 0);
    glVertex3f(16.51f, 0.00f, -34.03f);
    glVertex3f(16.51f, 0.00f, -39.03f);
    glVertex3f(16.51f, 2.53f, -39.03f);
    glVertex3f(16.51f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA ATAS
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 2.53f, -34.03f);
    glVertex3f(14.10f, 2.53f, -39.03f);
    glVertex3f(16.51f, 2.53f, -34.03f);
    glVertex3f(16.51f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 0.00f, -34.03f);
    glVertex3f(20.51f, 0.00f, -34.03f);
    glVertex3f(20.51f, 2.53f, -34.03f);
    glVertex3f(18.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN 1
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -34.03f);
    glVertex3f(21.51f, 0.00f, -34.03f);
    glVertex3f(21.51f, 3.53f, -34.03f);
    glVertex3f(20.51f, 3.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 0.00f, -39.03f);
    glVertex3f(20.51f, 0.00f, -39.03f);
    glVertex3f(20.51f, 2.53f, -39.03f);
    glVertex3f(18.10f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG 1
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -39.03f);
    glVertex3f(21.51f, 0.00f, -39.03f);
    glVertex3f(21.51f, 3.53f, -39.03f);
    glVertex3f(20.51f, 3.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 0.00f, -34.03f);
    glVertex3f(18.10f, 0.00f, -39.03f);
    glVertex3f(18.10f, 2.53f, -39.03f);
    glVertex3f(18.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI 1
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -34.03f);
    glVertex3f(20.51f, 0.00f, -39.03f);
    glVertex3f(20.51f, 3.53f, -39.03f);
    glVertex3f(20.51f, 3.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -34.03f);
    glVertex3f(20.51f, 0.00f, -39.03f);
    glVertex3f(20.51f, 2.53f, -39.03f);
    glVertex3f(20.51f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN 1
    glColor3ub(102, 51, 0);
    glVertex3f(21.51f, 0.00f, -34.03f);
    glVertex3f(21.51f, 0.00f, -39.03f);
    glVertex3f(21.51f, 3.53f, -39.03f);
    glVertex3f(21.51f, 3.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 2.53f, -34.03f);
    glVertex3f(18.10f, 2.53f, -39.03f);
    glVertex3f(20.51f, 2.53f, -34.03f);
    glVertex3f(20.51f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS 1
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 3.53f, -34.03f);
    glVertex3f(20.51f, 3.53f, -39.03f);
    glVertex3f(21.51f, 3.53f, -34.03f);
    glVertex3f(21.51f, 3.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA DEPAN A
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 0.00f, -34.03f);
    glVertex3f(6.51f, 0.00f, -34.03f);
    glVertex3f(6.51f, 2.53f, -34.03f);
    glVertex3f(4.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA BELAKANG A
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 0.00f, -39.03f);
    glVertex3f(6.51f, 0.00f, -39.03f);
    glVertex3f(6.51f, 2.53f, -39.03f);
    glVertex3f(4.10f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KIRI A
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 0.00f, -34.03f);
    glVertex3f(4.10f, 0.00f, -39.03f);
    glVertex3f(4.10f, 2.53f, -39.03f);
    glVertex3f(4.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KANAN A
    glColor3ub(102, 51, 0);
    glVertex3f(6.51f, 0.00f, -34.03f);
    glVertex3f(6.51f, 0.00f, -39.03f);
    glVertex3f(6.51f, 2.53f, -39.03f);
    glVertex3f(6.51f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA ATAS A
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 2.53f, -34.03f);
    glVertex3f(4.10f, 2.53f, -39.03f);
    glVertex3f(6.51f, 2.53f, -34.03f);
    glVertex3f(6.51f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN A
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 0.00f, -34.03f);
    glVertex3f(10.51f, 0.00f, -34.03f);
    glVertex3f(10.51f, 2.53f, -34.03f);
    glVertex3f(8.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN 1 A
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -34.03f);
    glVertex3f(11.51f, 0.00f, -34.03f);
    glVertex3f(11.51f, 3.53f, -34.03f);
    glVertex3f(10.51f, 3.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG A
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 0.00f, -39.03f);
    glVertex3f(10.51f, 0.00f, -39.03f);
    glVertex3f(10.51f, 2.53f, -39.03f);
    glVertex3f(8.10f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG 1 A
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -39.03f);
    glVertex3f(11.51f, 0.00f, -39.03f);
    glVertex3f(11.51f, 3.53f, -39.03f);
    glVertex3f(10.51f, 3.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI A
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 0.00f, -34.03f);
    glVertex3f(8.10f, 0.00f, -39.03f);
    glVertex3f(8.10f, 2.53f, -39.03f);
    glVertex3f(8.10f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI 1 A
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -34.03f);
    glVertex3f(10.51f, 0.00f, -39.03f);
    glVertex3f(10.51f, 3.53f, -39.03f);
    glVertex3f(10.51f, 3.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN A
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -34.03f);
    glVertex3f(10.51f, 0.00f, -39.03f);
    glVertex3f(10.51f, 2.53f, -39.03f);
    glVertex3f(10.51f, 2.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN 1 A
    glColor3ub(102, 51, 0);
    glVertex3f(11.51f, 0.00f, -34.03f);
    glVertex3f(11.51f, 0.00f, -39.03f);
    glVertex3f(11.51f, 3.53f, -39.03f);
    glVertex3f(11.51f, 3.53f, -34.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS A
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 2.53f, -34.03f);
    glVertex3f(8.10f, 2.53f, -39.03f);
    glVertex3f(10.51f, 2.53f, -34.03f);
    glVertex3f(10.51f, 2.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS 1 A
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 3.53f, -34.03f);
    glVertex3f(10.51f, 3.53f, -39.03f);
    glVertex3f(11.51f, 3.53f, -34.03f);
    glVertex3f(11.51f, 3.53f, -39.03f);
    glEnd();

    ///

    glBegin(GL_QUADS);//MEJA DEPAN B
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 0.00f, -24.03f);
    glVertex3f(16.51f, 0.00f, -24.03f);
    glVertex3f(16.51f, 2.53f, -24.03f);
    glVertex3f(14.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA BELAKANG B
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 0.00f, -29.03f);
    glVertex3f(16.51f, 0.00f, -29.03f);
    glVertex3f(16.51f, 2.53f, -29.03f);
    glVertex3f(14.10f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KIRI B
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 0.00f, -24.03f);
    glVertex3f(14.10f, 0.00f, -29.03f);
    glVertex3f(14.10f, 2.53f, -29.03f);
    glVertex3f(14.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KANAN B
    glColor3ub(102, 51, 0);
    glVertex3f(16.51f, 0.00f, -24.03f);
    glVertex3f(16.51f, 0.00f, -29.03f);
    glVertex3f(16.51f, 2.53f, -29.03f);
    glVertex3f(16.51f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA ATAS B
    glColor3ub(102, 51, 0);
    glVertex3f(14.10f, 2.53f, -24.03f);
    glVertex3f(14.10f, 2.53f, -29.03f);
    glVertex3f(16.51f, 2.53f, -24.03f);
    glVertex3f(16.51f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN B
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 0.00f, -24.03f);
    glVertex3f(20.51f, 0.00f, -24.03f);
    glVertex3f(20.51f, 2.53f, -24.03f);
    glVertex3f(18.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN 1 B
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -24.03f);
    glVertex3f(21.51f, 0.00f, -24.03f);
    glVertex3f(21.51f, 3.53f, -24.03f);
    glVertex3f(20.51f, 3.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG B
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 0.00f, -29.03f);
    glVertex3f(20.51f, 0.00f, -29.03f);
    glVertex3f(20.51f, 2.53f, -29.03f);
    glVertex3f(18.10f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG 1 B
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -29.03f);
    glVertex3f(21.51f, 0.00f, -29.03f);
    glVertex3f(21.51f, 3.53f, -29.03f);
    glVertex3f(20.51f, 3.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI B
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 0.00f, -24.03f);
    glVertex3f(18.10f, 0.00f, -29.03f);
    glVertex3f(18.10f, 2.53f, -29.03f);
    glVertex3f(18.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI 1 B
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -24.03f);
    glVertex3f(20.51f, 0.00f, -29.03f);
    glVertex3f(20.51f, 3.53f, -29.03f);
    glVertex3f(20.51f, 3.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN B
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 0.00f, -24.03f);
    glVertex3f(20.51f, 0.00f, -29.03f);
    glVertex3f(20.51f, 2.53f, -29.03f);
    glVertex3f(20.51f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN 1 B
    glColor3ub(102, 51, 0);
    glVertex3f(21.51f, 0.00f, -24.03f);
    glVertex3f(21.51f, 0.00f, -29.03f);
    glVertex3f(21.51f, 3.53f, -29.03f);
    glVertex3f(21.51f, 3.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS B
    glColor3ub(102, 51, 0);
    glVertex3f(18.10f, 2.53f, -24.03f);
    glVertex3f(18.10f, 2.53f, -29.03f);
    glVertex3f(20.51f, 2.53f, -24.03f);
    glVertex3f(20.51f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS 1 B
    glColor3ub(102, 51, 0);
    glVertex3f(20.51f, 3.53f, -24.03f);
    glVertex3f(20.51f, 3.53f, -29.03f);
    glVertex3f(21.51f, 3.53f, -24.03f);
    glVertex3f(21.51f, 3.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA DEPAN A B
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 0.00f, -24.03f);
    glVertex3f(6.51f, 0.00f, -24.03f);
    glVertex3f(6.51f, 2.53f, -24.03f);
    glVertex3f(4.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA BELAKANG A B
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 0.00f, -29.03f);
    glVertex3f(6.51f, 0.00f, -29.03f);
    glVertex3f(6.51f, 2.53f, -29.03f);
    glVertex3f(4.10f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KIRI A B
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 0.00f, -24.03f);
    glVertex3f(4.10f, 0.00f, -29.03f);
    glVertex3f(4.10f, 2.53f, -29.03f);
    glVertex3f(4.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA KANAN A B
    glColor3ub(102, 51, 0);
    glVertex3f(6.51f, 0.00f, -24.03f);
    glVertex3f(6.51f, 0.00f, -29.03f);
    glVertex3f(6.51f, 2.53f, -29.03f);
    glVertex3f(6.51f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//MEJA ATAS A B
    glColor3ub(102, 51, 0);
    glVertex3f(4.10f, 2.53f, -24.03f);
    glVertex3f(4.10f, 2.53f, -29.03f);
    glVertex3f(6.51f, 2.53f, -24.03f);
    glVertex3f(6.51f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN A B
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 0.00f, -24.03f);
    glVertex3f(10.51f, 0.00f, -24.03f);
    glVertex3f(10.51f, 2.53f, -24.03f);
    glVertex3f(8.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI DEPAN 1 A B
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -24.03f);
    glVertex3f(11.51f, 0.00f, -24.03f);
    glVertex3f(11.51f, 3.53f, -24.03f);
    glVertex3f(10.51f, 3.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG A B
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 0.00f, -29.03f);
    glVertex3f(10.51f, 0.00f, -29.03f);
    glVertex3f(10.51f, 2.53f, -29.03f);
    glVertex3f(8.10f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI BELAKANG 1 A B
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -29.03f);
    glVertex3f(11.51f, 0.00f, -29.03f);
    glVertex3f(11.51f, 3.53f, -29.03f);
    glVertex3f(10.51f, 3.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI A B
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 0.00f, -24.03f);
    glVertex3f(8.10f, 0.00f, -29.03f);
    glVertex3f(8.10f, 2.53f, -29.03f);
    glVertex3f(8.10f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KIRI 1 A B
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -24.03f);
    glVertex3f(10.51f, 0.00f, -29.03f);
    glVertex3f(10.51f, 3.53f, -29.03f);
    glVertex3f(10.51f, 3.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN A B
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 0.00f, -24.03f);
    glVertex3f(10.51f, 0.00f, -29.03f);
    glVertex3f(10.51f, 2.53f, -29.03f);
    glVertex3f(10.51f, 2.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI KANAN 1 A B
    glColor3ub(102, 51, 0);
    glVertex3f(11.51f, 0.00f, -24.03f);
    glVertex3f(11.51f, 0.00f, -29.03f);
    glVertex3f(11.51f, 3.53f, -29.03f);
    glVertex3f(11.51f, 3.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS A B
    glColor3ub(102, 51, 0);
    glVertex3f(8.10f, 2.53f, -24.03f);
    glVertex3f(8.10f, 2.53f, -29.03f);
    glVertex3f(10.51f, 2.53f, -24.03f);
    glVertex3f(10.51f, 2.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//KURSI ATAS 1 A B
    glColor3ub(102, 51, 0);
    glVertex3f(10.51f, 3.53f, -24.03f);
    glVertex3f(10.51f, 3.53f, -29.03f);
    glVertex3f(11.51f, 3.53f, -24.03f);
    glVertex3f(11.51f, 3.53f, -29.03f);
    glEnd();

    glBegin(GL_QUADS);//PAPAN TULIS
    glColor3ub(77, 77, 77);
    glVertex3f(-2.00f, 4.00f, -24.03f);
    glVertex3f(-2.00f, 4.00f, -39.03f);
    glVertex3f(-2.00f, 10.53f, -39.03f);
    glVertex3f(-2.00f, 10.53f, -24.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI DEPAN
    glColor3ub(77, 51, 25);
    glVertex3f(-20.10f, 0.00f, -36.03f  );
    glVertex3f(-26.51f, 0.00f, -36.03f  );
    glVertex3f(-26.51f, 10.53f, -36.03f  );
    glVertex3f(-20.10f, 10.53f, -36.03f  );
    glEnd();

    glBegin(GL_QUADS);//LEMARI BELAKANG
    glColor3ub(77, 51, 25);
    glVertex3f(-20.10f, 0.00f, -39.03f);
    glVertex3f(-26.51f, 0.00f, -39.03f);
    glVertex3f(-26.51f, 10.53f, -39.03f);
    glVertex3f(-20.10f, 10.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI KIRI
    glColor3ub(77, 51, 25);
    glVertex3f(-20.10f, 0.00f, -36.03f);
    glVertex3f(-20.10f, 0.00f, -39.03f);
    glVertex3f(-20.10f, 10.53f, -39.03f);
    glVertex3f(-20.10f, 10.53f, -36.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI KANAN
    glColor3ub(77, 51, 25);
    glVertex3f(-26.51f, 0.00f, -36.03f);
    glVertex3f(-26.51f, 0.00f, -39.03f);
    glVertex3f(-26.51f, 10.53f, -39.03f);
    glVertex3f(-26.51f, 10.53f, -36.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI ATAS
    glColor3ub(77, 51, 25);
    glVertex3f(-20.10f, 10.53f, -36.03f);
    glVertex3f(-20.10f, 10.53f, -39.03f);
    glVertex3f(-26.51f, 10.53f, -36.03f);
    glVertex3f(-26.51f, 10.53f, -39.03f);
    glEnd();

    glBegin(GL_LINES);//LEMARI GARIS
    glColor3ub(51, 51, 51);
    glVertex3f(-23.00f, 0.00f, -36.04f);
    glVertex3f(-23.00f, 10.53f, -36.04f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI DEPAN 1
    glColor3ub(77, 51, 25);
    glVertex3f(-30.10f, 0.00f, -36.03f);
    glVertex3f(-36.51f, 0.00f, -36.03f);
    glVertex3f(-36.51f, 10.53f, -36.03f);
    glVertex3f(-30.10f, 10.53f, -36.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI BELAKANG 1
    glColor3ub(77, 51, 25);
    glVertex3f(-30.10f, 0.00f, -39.03f);
    glVertex3f(-36.51f, 0.00f, -39.03f);
    glVertex3f(-36.51f, 10.53f, -39.03f);
    glVertex3f(-30.10f, 10.53f, -39.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI KIRI 1
    glColor3ub(77, 51, 25);
    glVertex3f(-30.10f, 0.00f, -36.03f);
    glVertex3f(-30.10f, 0.00f, -39.03f);
    glVertex3f(-30.10f, 10.53f, -39.03f);
    glVertex3f(-30.10f, 10.53f, -36.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI KANAN 1
    glColor3ub(77, 51, 25);
    glVertex3f(-36.51f, 0.00f, -36.03f);
    glVertex3f(-36.51f, 0.00f, -39.03f);
    glVertex3f(-36.51f, 10.53f, -39.03f);
    glVertex3f(-36.51f, 10.53f, -36.03f);
    glEnd();

    glBegin(GL_QUADS);//LEMARI ATAS 1
    glColor3ub(77, 51, 25);
    glVertex3f(-30.10f, 10.53f, -36.03f);
    glVertex3f(-30.10f, 10.53f, -39.03f);
    glVertex3f(-36.51f, 10.53f, -36.03f);
    glVertex3f(-36.51f, 10.53f, -39.03f);
    glEnd();

    glBegin(GL_LINES);//LEMARI GARIS 1
    glColor3ub(51, 51, 51);
    glVertex3f(-33.0f, 0.0f, -36.04f);
    glVertex3f(-33.0f, 10.53f, -36.04f);
    glEnd();

    glBegin(GL_QUADS);//KARPET 
    glColor3ub(255, 133, 102);
    glVertex3f(-20.10f, 0.0f, -35.03f);
    glVertex3f(-20.10f, 0.0f, -18.03f);
    glVertex3f(-36.51f, 0.0f, -18.03f);
    glVertex3f(-36.51f, 0.0f, -35.03f);
    glEnd();

    glColor3ub(128, 255, 128); // JAM DINDING
    lingkaran(5, 50, -8, 20);

    glBegin(GL_LINES);//JAM DINDING 1
    glColor3ub(0,0,0);
    glVertex3f(-8.0f, 20.0f, -70.10f);
    glVertex3f(-8.0f, 17.0f, -70.10f);
    glEnd();

    glBegin(GL_LINES);//JAM DINDING 2
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0f, 20.0f, -70.10f);
    glVertex3f(-4.0f, 20.0f, -70.10f);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();

}

void idle() {
    if (!mousedown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mousedown = false;
}

void mousemotion(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer, 0);
    if (!mousedown)
    {
        yrot += 1;
    } glutPostRedisplay();
}


void keyboard(unsigned char key, int a, int b)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0, 0, 3);
        break;
    case 'd':
    case 'D':
        glTranslatef(3, 0, 0);
        break;
    case 's':
    case 'S':
        glTranslatef(0, 0, -3);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3, 0, 0);
        break;
    case '7':
        glTranslatef(0, 3, 0);
        break;
    case '9':
        glTranslatef(0, -3, 0);
        break;
    case 'p':
        mousedown = true;
        break;
    case 'r':
        mousedown = false;
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);

        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);

        }
    }
    display();

}


void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, lebar / tinggi, 5.0, 600);
    glTranslatef(10, -40, -180);
    glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("672019167-672019177-672019191");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    myinit();
    glutTimerFunc(1, timer, 0);
    glutMainLoop();
    return 0;
}