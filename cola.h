#ifndef COLA
#define COLA
typedef struct Cola{
	struct Node *iq;
	struct Node *fq;
}Cola;

//FUNCIONES DE LA COLA
Cola* crearCola(){
	   return calloc(1, sizeof(Cola));
}
int colaVacia(Cola *Q){
	return (Q->iq == NULL);
}
void agregarCola(Cola *Q,int posicion_f,int posicion_c){
		Node *node = calloc(1,sizeof(Node));
		node->pf = posicion_f;
    	node->pc = posicion_c;
		if(colaVacia(Q)){
			Q->iq = node;
			Q->fq = node;
			}
		else{
			Q->fq->prox = node;
			Q->fq = node;
			}
}
void retirarCola(Cola *Q,int *f,int *c){
	if(colaVacia(Q)){
		*f = -1;
		*c = -1;
	}
	else{
		*f = Q->iq->pf;
		*c = Q->iq->pc;
		Q->iq = Q->iq->prox;
		}
}

#endif
