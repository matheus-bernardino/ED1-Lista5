#include <bits/stdc++.h>

using namespace std;

struct cliente
{
    string nome, cpf;
    cliente *next;
    cliente(string _nome, string _cpf, cliente *head){nome = _nome, cpf = _cpf, next = head;}
    cliente(){}
};

cliente* criar()
{
    cliente *head = new cliente();
    head->next = head;
    return head;
}

void inserir(cliente *head, string nome, string cpf, int pos)
{
    cliente *aux = head, *c = new cliente(nome, cpf, head);
    for(int i = 1; i < pos and aux->next != head; i++){aux = aux->next;}

    if(aux->next == head)
        aux->next = c;
    else
        c->next = aux->next, aux->next = c;
}

cliente remover(cliente *head, int pos)
{
    cliente *aux = head, r, *k;
    for(int i = 1; i < pos; i++){aux = aux->next;}

    r = *(aux->next);
    if(aux->next->next == head)
        delete(aux->next), aux->next = head;
    else
        k = aux->next, aux->next = aux->next->next, delete(k);
    return r;
}

int buscar(cliente *head, string cpf)
{
    cliente *aux = head->next;
    for(int i = 1; aux != head; i++)
    {
        if(aux->cpf == cpf)
            return i;
        aux = aux->next;
    }
    return -1;
}

void imprimir(cliente *head)
{
    cliente *aux = head->next;
    while(aux != head)
        cout << aux->nome << aux->cpf << '\n', aux = aux->next;
}

void deletar(cliente *head)
{	
	cliente *aux = head, *r = head;
    while(aux->next != r)
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
