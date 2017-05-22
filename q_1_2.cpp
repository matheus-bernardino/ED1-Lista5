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

void inserir(cliente *head, string nome, string cpf, int p)
{
    cliente *aux = head, *c = new cliente(nome, cpf);

    for(int i = 1; i < p and aux->next; i++){aux = aux->next;}
    
    if(!aux->next)
        aux->next = c;
    else
        c->next = aux->next, aux->next = c;
}


cliente remover(cliente *head, int p)
{
    cliente *aux = head, r;
    for(int i = 1; i < p and aux->next; i++){aux = aux->next;}
    r = *(aux->next);
    if(!aux->next->next)
        aux->next = nullptr, delete(aux->next);
    else
    {
        cliente *k;
        k = aux->next->next, delete(aux->next), aux->next = k;  
    }
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
	inserir(head, "b", "456", 1);
	inserir(head, "c", "789", 2);
	cout << buscar(head, "123") << '\n';
	cout << buscar(head, "456") << '\n';
	cout << buscar(head, "789") << '\n';
	remover(head, 3);
	imprimir(head);
    deletar(head);

    return 0;
}
