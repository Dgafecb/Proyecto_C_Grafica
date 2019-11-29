#ifndef ROBOT
#define ROBOT
typedef struct Robot{
	float color[3];
  int tam_cabeza;
  int tam_pecho;
  int tam_brazo;
  int tam_pierna;
}Robot;
Robot* crearRobot(float color[3],int tam_cabeza, int tam_pecho, int tam_brazo, int tam_pierna){
    Robot*robotito = calloc(1, sizeof(Robot))
    (*Robotito).color[3]=color[3];
    (*Robotito).tam_cabeza=tam_cabeza;
    (*Robotito).tam_pecho=tam_pecho;
    (*Robotito).tam_brazo=tam_brazo;
    (*Robotito).tam_pierna=tam_pierna;
	   return Robotito;
}
void
void crear_cabeza(robot *robot){
  glPushMatrix();
  glColor3f((GLfloat)robot.color[0],(GLFloat)robot.color[1],(GLfloat)robot.color[2]);
  glSolidSphere(robot.tam_cabeza,100,100);
}


#endif
