#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
float mat_ambient[] ={ 0.0f,0.1f,0.06f ,1.0f};
float mat_diffuse[] ={ 0.0f,0.50980392f,0.50980392f,1.0f};
float mat_specular[] ={0.50196078f,0.50196078f,0.50196078f,1.0f };
float shine[] ={32.0f};
          

void init(void)
{
// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };


// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

//glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();

}
// Aqui ponemos lo que queremos dibujar.
void display(void)
{
// Propiedades del material
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

// Rotacion de 20 grados en torno al eje x
    glRotated(20.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();
//setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glutSolidSphere(90.0,100.0,100.0);
    glFlush();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'B':
    case 'b':
    mat_ambient[0] = 0.329412f;
    mat_ambient[1] =0.223529f;
    mat_ambient[2] =0.027451f,1.0f ;
    mat_diffuse[0] =  0.780392f ;
    mat_diffuse[1] = 0.568627f;
    mat_diffuse[2] = 0.113725f, 1.0f ;
    mat_specular[0] =  0.992157f;
    mat_specular[1] = 0.941176f;
    mat_specular[2] = 0.807843f, 1.0f ;
    shine[0] = 27.8f;
    break;
    case 'G':
    case 'g':
    mat_ambient[0] = 0.24725;
    mat_ambient[1] =0.1995;
    mat_ambient[2] =0.0745,1.0f ;
    mat_diffuse[0] = 0.75164;
    mat_diffuse[1] = 0.60648;
    mat_diffuse[2] = 0.22648, 1.0f ;
    mat_specular[0] =0.628281;
    mat_specular[1] = 0.555802;
    mat_specular[2] = 0.366065, 1.0f ;
    shine[0] = 20.0f;
	break;
    case 'C':
    case 'c':
    mat_ambient[0] = 0.19125;
    mat_ambient[1] =0.0735;
    mat_ambient[2] =0.0225,1.0f ;
    mat_diffuse[0] =0.7038;
    mat_diffuse[1] =0.27048;
    mat_diffuse[2] =0.0828, 1.0f ;
    mat_specular[0] =0.256777;
    mat_specular[1] =0.137622;
    mat_specular[2] =0.086014, 1.0f ;
    shine[0] = 15.0f;
	break;
    case 'R':
    case 'r':
    mat_ambient[0] = 0.0;
    mat_ambient[1] =0.0;
    mat_ambient[2] =0.0,1.0f ;
    mat_diffuse[0] =0.5;
    mat_diffuse[1] =0.0;
    mat_diffuse[2] =0.0, 1.0f ;
    mat_specular[0] =0.7;
    mat_specular[1] =0.6;
    mat_specular[2] =0.6, 1.0f ;
    shine[0] = 10.0f;
	break;
    case 'S':
    case 's':
    mat_ambient[0] = 0.19225;
    mat_ambient[1] =0.19225;
    mat_ambient[2] =0.19225,1.0f ;
    mat_diffuse[0] =0.50754;
    mat_diffuse[1] =0.50754;
    mat_diffuse[2] =0.50754, 1.0f ;
    mat_specular[0] =0.508273;
    mat_specular[1] =0.508273;
    mat_specular[2] =0.508273, 1.0f ;
    shine[0] = 8.0f;
	break;
    }
    glutPostRedisplay();
}

// Main del programa.
int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tarea Materiales");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
