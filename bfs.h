#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	struct Node *prox;
	struct Node *prev;
	int pf;			//posicion en f
	int pc;			//posicion en c
	int value;
}Node;
typedef struct List{
	struct Node *first;
	struct Node *last;
	char color;
	int d;					//d = distancia del nodo a la raiz del arbol generado
	int pi[2];		//pi  = Padre  -- es un puntero ala posicion de su padre
	int Casilla;   // si casilla = 1 entonces es un muro, si casilla = 0 no es un muro
}List;

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
// FUNCIONES DE LA LISTA
List *List_Create(){
    return calloc(1, sizeof(List));
}
void List_Insertar(List *list, int posicion_f,int posicion_c){

    Node *node = calloc(1, sizeof(Node));
    node->pf = posicion_f;
    node->pc = posicion_c;

    if(list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->prox = node;
        node->prev = list->last;
        list->last = node;
    }

    return;
}
int Lista_Vacia(List *list){
		return (list->first == NULL);
}
// funciones de grafo
void Grafo_Create(List *G[F][C],int A[F][C]){
	int f,c;


	for( f=0;f<F;f++){
		for(c=0;c<C;c++){
			G[f][c] = List_Create();
		}
	}
	//ENLAMOS LOS NODOS DEL GRAFO APARTIR DEL MAPA
	for(f=0;f<F;f++){
		for(c=0;c<C;c++){
			if(A[f][c] == 0){		//Mientras Casilla no sea un MURO entonces es un nodo que se puede enlazar


				//Para mover hacia la DERECHA
				if(c+1 < C){
					if(A[f][c+1] == 0) //
						List_Insertar(G[f][c],f,c+1);
				}
					//Para mover hacia la IZQUIERDA
				if(c-1 >= 0){ //si el nodo que esta a su izquierda, no choca con la pared izquierda entonces existe
					if(A[f][c-1] == 0)//Si el nodo que esta a su izquierdo no es un muro
						List_Insertar(G[f][c],f,c-1);  //insertamos al Grafo[f][c] el nodo[f-1][c]
				}
				//Para mover hacia la ARRIBA
				if(f-1 >= 0){
					if(A[f-1][c] == 0) //
						List_Insertar(G[f][c],f-1,c);
				}
				//Para mover hacia la ABAJO
				if(f+1 < F){
					if(A[f+1][c] == 0) //
						List_Insertar(G[f][c],f+1,c);
				}
			}
		}
	}

}
void BFS(List *G[F][C],int sf,int sc){
	//printf("bfs\n");		//sf posicon_raiz(fila) sc posicion_raiz(columna)
	int f,c;
	List *y;
	//COLOCANDO VALORES INICIALES
	for(f=0;f<F;f++){
		for(c=0;c<C;c++){
			y = G[f][c];
			if(f == sf && c == sc){	//si es la raiz
				y->color = 'G';
				y->d = 0;
				y->pi[0] = -1; ///NILL sera 0
				y->pi[1] = -1;
			}
			else{		//para los demas nodos
				y->color = 'W';
				y->d = 100000;
				y->pi[0] = -1; ///NILL sera 0
				y->pi[1] = -1;
			}
		}
	}
	//TRANSFORMANDO LOS VALORES INCIALES
	Cola *Q;
	Q = crearCola();
	agregarCola(Q,sf,sc);

	while(Q->iq != NULL){
		int uf,uc,fv,cv;
		Node *v;

		retirarCola(Q,&uf,&uc);
		v = G[uf][uc]->first; //v apunta al primer nodo de la lista del vertice G[*u][*(u+1)]

		while(v != NULL){		//Recorremos la lista de G[*u][*(u+1)]

			fv = v->pf;		//fv es la fila del vertice v
			cv = v->pc;		//cv es la columana del vertice v

			if(G[fv][cv]->color == 'W'){
				G[fv][cv]->color = 'G';
				G[fv][cv]->d = (G[uf][uc]->d) +1;
				G[fv][cv]->pi[0] = uf;
				G[fv][cv]->pi[1] = uc;

				agregarCola(Q,fv,cv);		//p->valor = v
				}
			v = v->prox;
		}

		G[uf][uc]->color = 'B';

		}

	}
int main(){
  int A[n][n]= {}
  int posiionenemigo[2]={fr,cr};
  int posicion[2]={fq,cq};
  struct List *G[n][n];
  Grafo_Create(G,A);
  BFS(G,posiionenemigo[0],posiionenemigo[1]);

}
