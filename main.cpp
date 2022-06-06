#include "classes.hpp"

int main () {
    product products[10000];
    item items[10000];
    order orders[10000];
    int option = 0;

    int product_id_count = 0;
    int item_id_count = 0;
    int order_id_count = 0;

    while (option != 4)
    {
        system("cls");
        cout << "======== MENU =======\n";
        cout << "1. Cadastrar produto\n";
        cout << "2. Estoque\n";
        cout << "3. Realizar Pedido\n";
        cout << "4. Sair\n";
        cin >> option;
        system("cls");
        // Cadastrador de products
        if (option == 1)
        {
            char soun;
            cout << "Deseja cadastrar um novo produto? (s/n)\n";
            cin >> soun;
            if (soun == 's')
            {   
                system("cls");
                cout << "== CADASTRO DE PRODUTO ==\n";
                string newname;
                cout << "\nDigite o nome do produto: ";
                getline(cin >> std::ws, newname);
                product_id_count++;
                double newprice;
                cout << "Digite o valor por unidade(use ponto em vez de virgula): ";
                cin >> newprice;
                int newqtd;
                cout << "\nDigite a quantidade em estoque: ";
                cin >> newqtd;
                products[product_id_count].setID(product_id_count);
                products[product_id_count].setName(newname);
                products[product_id_count].setPrice(newprice);
                products[product_id_count].setEstoque(newqtd);
            };
            system("cls");
        };
        if (option == 2)
        {   
            cout << "=====ESTOQUE=====\n";
            cout << "1. Verificar Estoque\n";
            cout << "2. Atualizar quantidade de produto\n";
            cin >> option;
            system("cls");
            if (option == 1) {
                // VERIFICAR ESTOQUE
                cout << "=====ESTOQUE=====\n";
                cout << "ID - NOME - VALOR - QTD\n";
                for (int i = 1; i < product_id_count+1; i++) {
                    cout << products[i].getID() << ". " << products[i].getName() << " - " << products[i].getPrice()<< " - " << products[i].getEstoque() << "\n";
                };
                char soun;
                cout << "\nContinuar? (s/n)\n";
                cin >> soun;
                system("cls");
            }
            else if (option == 2) {
                // ATUALIZAR QTD DE ALGUM PRODUTO CADASTRADO
                int prod_id;
                cout << "=====ESTOQUE=====\n";
                cout << "Digite o ID do produto: ";
                cin >> prod_id;
                cout << "Qual a quantidade de " << products[prod_id].getName() << " em estoque?\n";
                int newqtd;
                cin >> newqtd;
                products[prod_id].setEstoque(newqtd);
                system("cls");
            } else {
                cout << "Opcao incorreta!";
            }
        }

        if (option == 3)
        {
            char soun;
            cout << "Deseja cadastrar um novo produto? (s/n)\n";
            cin >> soun;
            if (soun == 's') {
                order_id_count++;
                orders[order_id_count].setID(order_id_count);
            }
            
            system("cls");
        };

        if (option == 4)
        {
            //4. Sair
            system("cls");
        };
    };
}