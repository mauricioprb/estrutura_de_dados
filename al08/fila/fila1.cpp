// Fila é uma ED Abstrata como lista e pilha 
//     - Possui somente duas operações como pilha:
//         Inserir na fim ou na cauda (tail)
//         Remover da início ou da cabeça (head)

//     - Mecanismos de prioridade FIFO (First In, Firt Out)
//     - Para isso são utilizados dois ponteiros (DEQUE)
//         - ponteiro para inicio -> onde ocorrem as remoções
//         - ponteiro para fim -> onde ocorrem as inserções

#include <iostream>
#include <cstdlib>

#include "source.h"

using namespace std;

int main() {                
    Fila fila;

    inicializar(&fila);

    inserir(100, &fila);
    inserir(101, &fila);
    inserir(102, &fila);

    int valor = remover(&fila);

    cout << valor << endl;
    
    return 1;
}