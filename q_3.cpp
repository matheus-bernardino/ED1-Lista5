#include <iostream>

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

void inserir(cliente *head, string nome, string cpf)
{
    cliente *aux = head, *c = new cliente(nome, cpf);
    for(aux; aux->next; aux = aux->next){}
    aux->next = c;
}

cliente remover(cliente *head)
{
    cliente *aux = head, r;
    for(aux; aux->next->next; aux = aux->next){}
    r = *aux->next, delete(aux->next), aux->next = nullptr;
    return r;
}

void deletar(cliente *head)
{
	cliente *aux = head;
    while(aux->next != nullptr)
        aux = aux->next, delete(head), head = aux->next;
}

int main()
{

    return 0;
}