#include <bits/stdc++.h>

using namespace std;

struct cliente
{
    string nome, cpf;
    cliente *next, *prev;
    cliente(string _nome, string _cpf){nome = _nome, cpf = _cpf, next = nullptr, prev = nullptr;}
    cliente(){next = nullptr, prev = nullptr;}
};

cliente* criar()
{
    cliente *head = new cliente();
    return head;
}

void inserir(cliente *head, string nome, string cpf, int pos)
{
    cliente *aux = head, *c = new cliente(nome, cpf);
    for(int i = 1; i < pos and aux->next; i++){aux = aux->next;}

    if(!aux->next)
        aux->next = c, c->prev = aux, c->next = nullptr;
    else
        c->next = aux->next, c->next->prev = c, aux->next = c, c->prev = aux;
}

cliente remover(cliente *head, int pos)
{
    cliente *aux = head->next, r;
    for(int i = 1; i < pos and aux->next; i++){aux = aux->next;}

    r = *aux;
    if(!aux->next)
        aux->prev->next = nullptr;
    else
        aux->prev->next = aux->next, aux->next->prev = aux->prev;
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
    while(aux)
        cout << aux->nome << ' ' << aux->cpf << '\n', aux = aux->next;
}

void deletar(cliente *head)
{
	cliente *aux = head;
    while(aux->next)
        aux = aux->next, delete(head), head = aux->next;
}

int main()
{
	cliente *head = criar();
	inserir(head, "a", "123", 1);
	inserir(head, "b", "456", 2);
	inserir(head, "c", "789", 3);
	cout << buscar(head, "123") << '\n';
	cout << buscar(head, "456") << '\n';
	cout << buscar(head, "789") << '\n' << '\n';
	
	cout << (remover(head, 3).cpf) << '\n' << '\n';
	imprimir(head);
    deletar(head);
	
    return 0;
}
