#include <bits/stdc++.h>

using namespace std;

struct cliente
{
    string nome, cpf;
    cliente *next;
    cliente(string _nome, string _cpf){nome = _nome, cpf = _cpf, next = nullptr;}
    cliente(){next = nullptr;}
};

cliente* criar()
{
    cliente *head = new cliente();
    return head;
}

void inserir(cliente *head, string nome, string cpf, int pos)
{
    cliente *aux = head, *c = new cliente(nome, cpf);
    int i = 1;
    while(i < pos and aux->next)
        aux = aux->next, i++;
    if(!aux->next)
        aux->next = c;
    else
        c->next = aux->next, aux->next = c;

}

cliente remover(cliente *head, int pos)
{
    cliente *aux = head, r;
    int i = 1;
    while(i < pos - 1){
        aux = aux->next, i++;
        cout << "wrgwg\n";
    }
    r = *(aux->next)
    if(aux->next->next != nullptr){
    	aux->next = aux->next->next;
    	cout << "as\n";
   	}

    free(aux->next->next), aux->next->next = nullptr;
    return r;
}

int buscar(cliente *head, string cpf)
{
    cliente *aux = head->next;
    int i = 1;
    while(aux){
        if(aux->cpf == cpf) return i;
        aux = aux->next, i++;
    }
    return -1;
}

void imprimir(cliente *head)
{
    cliente *aux = head->next;
    while(aux){
        cout << aux->nome << ' ' << aux->cpf << '\n';
    	aux = aux->next;    
   	}
}

void deletar(cliente *head)
{
    cliente *aux = head;
    while(aux->next)
        aux = aux->next, free(head), head = aux->next;
}

int main()
{
	cliente *head = criar();
	inserir(head, "a", "123", 1);
	inserir(head, "b", "456", 2);
	//inserir(head, "c", "789", 3);
	cout << (remover(head, 1).nome) << '\n';
	cout << (buscar(head, "123")) << '\n';
	//mprimir(head);

    return 0;
}
