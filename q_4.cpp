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
    cliente *aux = head->next, r = *aux;
    
    if(!aux->next)
        head->next = nullptr;
    else
        head->next = aux->next;
    
    delete(aux);
    return r;
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
	inserir(head, "a", "123");
	inserir(head, "b", "456");
	inserir(head, "c", "789");
	cout << head->next->cpf << '\n';
	cout << head->next->next->cpf << '\n';
	cout << head->next->next->next->cpf << '\n' << '\n';
	
	cout << (remover(head).cpf) << '\n';
	cout << (remover(head).cpf) << '\n';
	cout << (remover(head).cpf) << '\n';
    deletar(head);

    return 0;
}
