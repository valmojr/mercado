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
            char soun='n';
            cout << "\nDeseja realizar um pedido? (s/n)\n";
            cin >> soun;
            while (soun == 's')
            {
                order_id_count++;
                orders[order_id_count].setID(order_id_count);
                while (soun != 'n') {
                    cout << "Deseja adicionar algum item ao pedido? (s/n)\n";
                    cin >> soun;
                    if (soun == 's') {
                        system("cls");
                        cout << "=====ESTOQUE=====\n";
                        cout << "ID - NOME - VALOR - QTD\n";
                        for (int i = 1; i < product_id_count+1; i++) {
                            cout << products[i].getID() << ". " << products[i].getName() << " - " << products[i].getPrice()<< " - " << products[i].getEstoque() << "\n";
                        };
                        cout << "Qual produto deseja adicionar ao pedido?\n";
                        int itemselect=0;
                        cin >> itemselect;
                        cout << "Qual a quantidade de " << products[itemselect].getName() << " que deseja? Temos " << products[itemselect].getEstoque() << " em estoque\n";
                        int itemselectqtd=0;
                        cin >> itemselectqtd;
                        if (itemselectqtd <= products[itemselect].getEstoque()) {
                            products[itemselect].setEstoque(products[itemselect].getEstoque()-itemselectqtd);
                            orders[order_id_count].setValor(orders[order_id_count].getValor()+(products[itemselect].getPrice()*itemselectqtd));
                            orders[order_id_count].setItens(orders[order_id_count].getItens()+to_string(products[itemselect].getID())+" - "+products[itemselect].getName()+" - "+to_string(itemselectqtd)+"\n");
                        } else {
                            cout << "Quantidade indisponivel\n";
                        }
                    }
                }
                system("cls");
                cout << orders[order_id_count].getItens();
                cout << "\nTotal a pagar: R$" << orders[order_id_count].getValor() << "\n Qual a forma de pagamento?\n";
                cout << "1. Dinheiro\n";
                cout << "2. Cartao\n";
                cout << "3. Cheque\n";
                int pag;
                cin >> pag;
                switch (pag)
                {
                case 1:
                    orders[order_id_count].setPagamento("dinheiro");
                    orders[order_id_count].setPago(true);
                    break;
                case 2:
                    orders[order_id_count].setPagamento("cartao");
                    orders[order_id_count].setPago(true);
                    break;
                case 3:
                    orders[order_id_count].setPagamento("cheque");
                    orders[order_id_count].setPago(true);
                    break;
                
                default:
                    orders[order_id_count].setPago(false);
                    break;
                }
                if (orders[order_id_count].getPago())
                {
                    system("cls");
                    orders[order_id_count].gerarNotaFiscal();
                }
                char soun;
                cout << "\nContinuar? (s/n)\n";
                cin >> soun;
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