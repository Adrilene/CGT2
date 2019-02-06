#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

//globais
int tX = 0, tY = 0;    //translação
float sXY = 1.0;   //Escala
float rAa = 0.0, rAb;    //Ângulo de Rotação antibraço e braço
bool limiteB = false, limiteA = false;   //flag para indicar se haverá rotação para Braço e antibraço

const double eps = 1e-6;

void desenhaCorpo(void){
    //corpo
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(80,80);
        glVertex2i(180,80);
        glVertex2i(180,210);
        glVertex2i(80,210);
    glEnd();

    //cabeça
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(95,215);
        glVertex2i(165,215);
        glVertex2i(165,285);
        glVertex2i(95,285);
    glEnd();
}

void desenhaBraco(){
    glBegin(GL_QUADS);
        glColor3f(0.80, 0.36, 0.36);
        glVertex2i(181,210);
        glVertex2i(206,210);
        glVertex2i(206,155);
        glVertex2i(181,155);
    glEnd();
}

void desenhaAntebraco(){
    
    glBegin(GL_QUADS);
        glColor3f(0.74, 0.56, 0.56);
        glVertex2i(181,156);
        glVertex2i(206,156);
        glVertex2i(206,106);
        glVertex2i(181,106);
    glEnd();
}

void desenhaTexto(void *font, char *string){
    
    while(*string)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *string++);
}

void normalKey(unsigned char key, int x, int y){
    switch(key){
        //'a' para aumentar
        case 'a':
            sXY += 0.2;
            glutPostRedisplay();
            break;

        //'d' para diminuir
        case 'd':
            if(sXY-0.2 > eps){
                sXY -= 0.2;   
            }
            glutPostRedisplay();
            break;

        //'r' para rotacionar o braço e o antebraço
        case 'r':
            //se chegar no limite, braço volta
            if (rAb >= 180){
                limiteB = true;
            }
            else if (rAb == 0){
                limiteB = false;
            }
            if(limiteB){rAb -= 10.0;}
            else{rAb += 10.0;}
            
            glutPostRedisplay();
            
            break;

        //'t' para rotacionar o antibraço
        case 't':
            if (rAa >= 130){
                limiteA = true;
            }
            else if (rAa == 0){
                limiteA = false;
            }
            if(limiteA){rAa -= 10.0;}
            else{rAa += 10.0;}

            glutPostRedisplay();
            break;
        default:
            break;
    }
}

/*Função para gerenciar as setas*/
void specialKey(int key, int x, int y){
    switch (key){
        case GLUT_KEY_UP:
            tY+=2;
            break;
        case GLUT_KEY_DOWN:
            tY-=2;
            break;
        case GLUT_KEY_LEFT:
            tX-=2;
            break;
        case GLUT_KEY_RIGHT:
            tX+=2;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void){
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslated(tX,tY,0);
    glScalef(sXY,sXY,1.0);
    desenhaCorpo();   //desenha cabeça e tronco

    //desenha sorriso
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2);
    glTranslatef(107.0,265.0,0.0);
    glScalef(0.3,0.3,1.0);
    desenhaTexto(GLUT_STROKE_ROMAN, ". .");
    glTranslatef(-117.0,-50.0,0.0);
    glRotatef(270.0, 0.0, 0.0, 1.0);
    desenhaTexto(GLUT_STROKE_ROMAN, ")");
    glPopMatrix();


    glTranslatef(193.5,210, 0.0);
    glRotatef(rAb, 0.0, 0.0, 1.0);
    glTranslatef(-193.5, -210.0, 0.0);
    desenhaBraco(); 
   
    glTranslatef(193.5,156.0, 0.0);
    glRotatef(rAa, 0.0, 0.0, 1.0);
    glTranslatef(-193.5,-156.0,0.0);

    desenhaAntebraco();

    glPopMatrix();
	/* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void){
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(normalKey);
    glutSpecialFunc(specialKey);
    Inicializa();
	glutMainLoop();
}