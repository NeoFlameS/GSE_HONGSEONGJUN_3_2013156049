/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "SceneMgr.h"
#include "Renderer.h"
#include "Tower_object.h"


Renderer *g_Renderer = NULL;
SceneMgr *main_ob=NULL;

//임시로 넣어 두겠습니다.

/*struct tow_list {
	Tower cur_tow;
	tow_list * next_tow;
};
tow_list *towerl;//헤더*/
int mouse_state = 0;
//POINT *tp1;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	g_Renderer->DrawSolidRect(-200, 200, 0, 4, 1, 0, 1, 1);
	// Renderer Test
	//
	main_ob->draw();
	//g_Renderer->DrawSolidRect(tower.Location_search().x, tower.Location_search().y, 0, tower.Tower_Update(), 1, 1, 1, 1);
	/*if (towerl != NULL) {
		tow_list *t = towerl;
		while (t != NULL) {
			g_Renderer->DrawSolidRect(t->cur_tow.Location_search().x, t->cur_tow.Location_search().y, 0,10, 1, 1, 1, 1);// t->cur_tow.Tower_Update()
			t->cur_tow.Tower_Update();
			if (t->next_tow == NULL) {
				break;
			}
			else {
				
				t = t->next_tow;
			}
		}
	}*/


	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	printf("%d %d\n", x, y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		main_ob->create_tower(x-250, 250-y, 1);
		mouse_state = 1;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mouse_state ==1) {
		
		mouse_state = 0;
	}
	
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}


	main_ob = new SceneMgr(g_Renderer);
	//towerl= NULL;

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

