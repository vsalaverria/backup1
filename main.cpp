#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
int e_x, e_y, v_x, v_y, rx, ry, n_x, n_y, stado;
float mat_ambient[] ={ 0.0f,0.1f,0.06f ,1.0f};
float mat_diffuse[] ={ 0.0f,0.50980392f,0.50980392f,1.0f};
float mat_specular[] ={0.50196078f,0.50196078f,0.50196078f,1.0f };
float shine[] ={32.0f};
          

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
// Ubicamos la fuente de luz en el punto
//GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };


// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
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
	    GLfloat light_position[] = { (int)((0.03076923076923076923076923076923 * (n_x + v_x)) - 10), (int)((0.03076923076923076923076923076923 * (n_y + v_y)) - 10) * -1, 1.0, 0.0 };

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

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
    glutMainLoop();

    return 0;
}
