//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Kemuel dos Santos Rocha//////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////LABIRINTO INTERATIVO////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>


/* 
Especifica��es do labirinto:

- Constitu�dos por obst�culos( quadrados e ret�ngulos ) que formam o trajeto do labirinto
- Possui um personagem
- Os movimentos do personagem acontecem de acordo com as teclas do teclado( seta direita, seta esquerda, seta pra cima, seta pra baixo)
- O bot�o esquerdo do mouse modifica as cores da janela, dos obst�culos, e do personagem
- Caso o personagem colida com algum obst�culo, o mesmo retornar� ao ponto de partida
- O quadrado vermelho pequeno � a ponto de chegada
- O usu�rio possui tr�s vidas
- A cada colis�o o usu�rio perder� uma vida, at� chegar � zero, estado em que perdeu o jogo
- O objetivo do jogo � chegar ao ponto de chegada antes de perder todas as tr�s vidas
*/


int vida=3;
char texto[30],ganhou[30];
bool check=true;
float xr=470.0, yr=0.0, alt=30.0, larg=30.0;
float unidade = 5.0f;
int button, state,mousex,mousey;
float quad=1.0,fund=1.0,ob1=0.0,ob2=0.6,ob3=0.1,ob4=1.0,ob5=1.0,ob6=0.847100,ob7=0.184300,ob8=0.184300,ob9=0.858800,ob10=0.556900;

// Fun��o que recebe a fonte e um texto por par�metro para ser exibido na 
// tela usando caracteres bitmap
void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++); 
}

void DesenhaTextoStroke(void *font, char *string)
{
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
}

// Teclas especiais
void TeclasEspeciais(int key, int x, int y){
    switch (key){
        case GLUT_KEY_RIGHT:
            xr+=unidade;
            break;

        case GLUT_KEY_LEFT:
            xr-=unidade;
        break;

        case GLUT_KEY_UP:
            yr+=unidade;
            break;

        case GLUT_KEY_DOWN:
            yr-=unidade;
        break;

        default:
         break;
    }
    glutPostRedisplay();
    
//limitacao das dimensoes   
    if(xr<0)
    {
    	xr=0;
	}
	if(xr+alt>500)
	{
		xr=470.0;
	}
	if(yr<0)
	{
		yr=0;
	}
	if(yr+larg>500)
	{
		yr=470.0;
	}
//1 quadrado azul com borda rosa COLISAO
	

	
	if((xr>=300.0 && xr<=500.0) && (yr+alt>=40 && yr+alt<=150))
	{
		xr=470.0;
		yr=0.0;	
		vida--;
	}
	if((xr+larg>=300.0 && xr+larg<=500.0) && (yr+alt>=40 && yr+alt<=150))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}

	if((xr>=300.0 && xr<=500.0) && (yr>=40 && yr<=150))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//2	obstaculo roxo com borda ciano   COLISAO

	if((xr>=50.0 && xr<=250.0) && (yr+alt>=105 && yr+alt<=135))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=50.0 && xr+larg<=250.0) && (yr+alt>=105 && yr+alt<=135))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=50.0 && xr+larg<=250.0) && (yr>=105 && yr<=135))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr>=50.0 && xr<=250.0) && (yr>=105 && yr<=135))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//3 obstaculo verde com borda amarela   COLISAO
	
	if((xr>=-50.0 && xr<=250.0) && (yr+alt>=35 && yr+alt<=65))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=-50.0 && xr+larg<=250.0) && (yr>=35 && yr<=65))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr>=-50.0 && xr<=250.0) && (yr>=35 && yr<=65))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//4	obstaculo amarelo com borda rosa   COLISAO
	
	if((xr>=250.0 && xr<=300.0) && (yr+alt>=300 && yr+alt<=500))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>250.0 && xr+larg<=300.0) && (yr+alt>=300 && yr+alt<=500))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=250.0 && xr+larg<=300.0) && (yr>=300 && yr<=500))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//5 obstaculo coral com borda c�qui   COLISAO
	
	if((xr>=40.0 && xr<=150.0) && (yr+alt>=175 && yr+alt<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=40.0 && xr+larg<=150.0) && (yr+alt>=175 && yr+alt<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=40.0 && xr+larg<=150.0) && (yr>=175 && yr<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr>=40.0 && xr<=150.0) && (yr>=175 && yr<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//6 obstaculo cardo com borda vermelha   COLISAO
	
	if((xr>=190.0 && xr<=460.0) && (yr+alt>=190 && yr+alt<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=190.0 && xr+larg<=460.0) && (yr+alt>=190 && yr+alt<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=190.0 && xr+larg<=460.0) && (yr>=190 && yr<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr>=190.0 && xr<=460.0) && (yr>=190 && yr<=260))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
// 7 obstaculo cinza ard�sia escuro com borda magenta    COLISAO
	
	if((xr>=350.0 && xr<=500.0) && (yr+alt>=360 && yr+alt<=390))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=350.0 && xr+larg<=500.0) && (yr+alt>=360 && yr+alt<=390))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=350.0 && xr+larg<=500.0) && (yr>=350 && yr<=390))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr>=350.0 && xr<=500.0) && (yr>=360 && yr<=390))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
// 8 obstaculo cinza ard�sia escuro com borda magenta    COLISAO
	
	if((xr>=350.0 && xr<=460.0) && (yr+alt>=300 && yr+alt<=360))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=350.0 && xr+larg<=460.0) && (yr+alt>=300 && yr+alt<=360))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=350.0 && xr+larg<=460.0) && (yr>=300 && yr<=360))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//9 obstaculo dourado com borda preta com borda maguenta    COLISAO
	
	if((xr>=50.0 && xr<=200.0) && (yr+alt>=300 && yr+alt<=450))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=50.0 && xr+larg<=200.0) && (yr+alt>=300 && yr+alt<=450))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=50.0 && xr+larg<=200.0) && (yr>=300 && yr<=450))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr>=50.0 && xr<=200.0) && (yr>=300 && yr<=450))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	
//10 obstaculo tijolo refratorio com borda amarela   COLISAO
	
	if((xr>=350.0 && xr<=450.0) && (yr+alt>=430 && yr+alt<=500))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=350.0 && xr+larg<=450.0) && (yr+alt>=430 && yr+alt<=500))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}
	if((xr+larg>=350.0 && xr+larg<=450.0) && (yr>=430 && yr<=500))
	{
		xr=470.0;
		yr=0.0;
		vida--;
	}	
}

void Desenha(void)
{
	
	glClearColor(1.0, 1.0, fund, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);


//personagem

	glColor3f(quad, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(xr,yr+alt);
		glVertex2f(xr+larg, yr+alt);       
		glVertex2f(xr+larg, yr);       
		glVertex2f(xr,yr);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xr,yr+alt);
		glVertex2f(xr+larg, yr+alt);       
		glVertex2f(xr+larg, yr);       
		glVertex2f(xr,yr);
	glEnd();

//1 obstaculo azul com borda preta

	glColor3f(ob1, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(500,150);
		glVertex2f(300, 150);       
		glVertex2f(300, 40);       
		glVertex2f(500,40);
	glEnd();
glColor3f(0.0, 0.1, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(500,150);
		glVertex2f(300, 150);       
		glVertex2f(300, 40);       
		glVertex2f(500,40);
	glEnd();
	
//2	obstaculo roxo com borda ciano

	glColor3f(ob2, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(50,135);
		glVertex2f(250, 135);       
		glVertex2f(250, 105);       
		glVertex2f(50,105);
	glEnd();
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(50,135);
		glVertex2f(250, 135);       
		glVertex2f(250, 105);       
		glVertex2f(50,105);
	glEnd();
	
//3 obstaculo verde com borda amarela

	glColor3f(ob3, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(-50,65);
		glVertex2f(250, 65);       
		glVertex2f(250, 35);       
		glVertex2f(-50,35);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-50,65);
		glVertex2f(250, 65);       
		glVertex2f(250, 35);       
		glVertex2f(-50,35);
	glEnd();
	
//4	obstaculo amarelo com borda rosa
	
	glColor3f(ob4, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(300,500);
		glVertex2f(250,  500);       
		glVertex2f(250,  300);       
		glVertex2f(300.,300);
	glEnd();
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(300,500);
		glVertex2f(250,  500);       
		glVertex2f(250,  300);       
		glVertex2f(300,300);
	glEnd();
	
//5 obstaculo coral com borda c�qui

	glColor3f(ob5, 0.5, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(40,260);
		glVertex2f(150,  260);       
		glVertex2f(150,  175);       
		glVertex2f(40,175);
	glEnd();
	glColor3f(0.623500, 0.623500, 0.372600);
	glBegin(GL_LINE_LOOP);
		glVertex2f(40,260);
		glVertex2f(150,  260);       
		glVertex2f(150,  175);       
		glVertex2f(40.,175);
	glEnd();
	
//6 obstaculo cardo com borda vermelha

	glColor3f(ob6, 0.749000, 0.847100);
	glBegin(GL_QUADS);
		glVertex2f(190,190);
		glVertex2f(460,  190);       
		glVertex2f(460,  260);       
		glVertex2f(190,260);
	glEnd();	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(190,190);
		glVertex2f(460,  190);       
		glVertex2f(460,  260);       
		glVertex2f(190,260);
	glEnd();
	
// 7 obstaculo cinza ard�sia escuro com borda magenta
	
	glColor3f(ob7, 0.309800, 0.309800);
	glBegin(GL_QUADS);
		glVertex2f(350,390);
		glVertex2f(500,  390);       
		glVertex2f(500,  360);       
		glVertex2f(350,360);
	glEnd();	
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(350,390);
		glVertex2f(500,  390);       
		glVertex2f(500,  360);       
		glVertex2f(350,360);
	glEnd();
	
//8 obstaculo cinza ard�sia escuro com borda magenta
	
	glColor3f(ob8, 0.309800, 0.309800);
	glBegin(GL_QUADS);
		glVertex2f(350,360);
		glVertex2f(460,  360);       
		glVertex2f(460,  300);       
		glVertex2f(350,300);
	glEnd();
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(350,360);
		glVertex2f(460,  360);       
		glVertex2f(460,  300);       
		glVertex2f(350,300);
	glEnd();
	
//9 obstaculo dourado com borda preta com borda maguenta
	
	glColor3f(ob9, 0.858800, 0.439200);
	glBegin(GL_QUADS);
		glVertex2f(50,450);
		glVertex2f(200,  450);       
		glVertex2f(200,  300);       
		glVertex2f(50,300);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(50,450);
		glVertex2f(200,  450);       
		glVertex2f(200,  300);       
		glVertex2f(50,300);
	glEnd();
	
//10 obstaculo tijolo refratorio com borda amarela

	glColor3f(ob10, 0.137300, 0.137300);
	glBegin(GL_QUADS);
		glVertex2f(450,500);
		glVertex2f(350, 500);       
		glVertex2f(350, 430);       
		glVertex2f(450,430);
	glEnd();
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(450,500);
		glVertex2f(350, 500);       
		glVertex2f(350, 430);       
		glVertex2f(450,430);
	glEnd();
	
// obstaculo ponto de chegada
	glColor3f(1.0,0.0,0.0);
		glBegin(GL_QUADS);
		glVertex2f(500,500);
		glVertex2f(480, 500);       
		glVertex2f(480, 480);       
		glVertex2f(500,480);
	glEnd();

// Define a cor para os textos: preto
	glColor3f(0,0,0);
	
	glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    if(vida > 0){
    	sprintf(texto, "Vidas: %d", vida);
	}else{
		sprintf(texto, "Vidas: %d", 0);
	}
    
    glTranslatef(4.0f, 485.0f,0.0f);
    glRasterPos2f(0,0);
    DesenhaTexto(GLUT_BITMAP_9_BY_15,texto);
    glPopMatrix();



// Texto ponto de chegada 
if(xr==470 && yr==470)
{

	// Limpa a janela de visualiza��o com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Posi��o no universo onde o texto bitmap ser� colocado 
	glColor3f(1,0,0);
    glRasterPos2f(160,250); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"MANDOU MUITO BEM!");
	glColor3f(1,0,0);
    glRasterPos2f(70,230); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"(reinicie o jogo apertando qualquer seta)");
	// Exibe o desenha na janela
	glutSwapBuffers();
	xr=470.0;
	yr=0.0;
	vida=3;	
}
else if( vida==0) // Texto fim de jogo
{
	// Limpa a janela de visualiza��o com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Posi��o no universo onde o texto bitmap ser� colocado 
	glColor3f(1,0,0);
    glRasterPos2f(125,250); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"FIM DE JOGO, TENTE OUTRA VEZ!");
	glColor3f(1,0,0);
    glRasterPos2f(70,230); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"(reinicie o jogo apertando qualquer seta)");
	// Exibe o desenha na janela
	glutSwapBuffers();
	xr=470.0;
	yr=0.0;	
	vida=3;	
}

glFlush();
}
// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}
//funcao que muda de cor ao clicar com o botao esquerdo do mouse
void mouse(int button, int state, int mousex, int mousey)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && check==false) 
	{	ob1=0.0;
		ob2=0.6;
		ob3=0.1;
		ob4=1.0;
		ob5=1.0;
		ob6=0.847100;
		ob7=0.184300;
		ob8=0.184300;
		ob9=0.858800;
		ob10=0.556900;
		fund=1.0;
		quad=1.0;
		check=true;
		
	}	
	else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && check==true)
	{	ob1=0.5;
		ob2=0.2;
		ob3=0.8;
		ob4=0.0;
		ob5=0.0;
		ob6=0.3;
		ob7=0.6;
		ob8=0.6;
		ob9=0.0;
		ob10=0.8;
		fund=0.5;
		quad=0.0;
		check=false;	
	}
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{   
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

int main(int argc,char **argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50); 
	glutInitWindowSize(500,500); 
	glutCreateWindow("Labirinto");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc (Teclado);
	glutSpecialFunc(TeclasEspeciais);
	glutMouseFunc(mouse);
	Inicializa();
	glutMainLoop();
	return 0;
}
