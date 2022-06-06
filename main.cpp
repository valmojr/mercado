#include <iostream>
#include <string>
#include <vector>

using namespace std;
//-----------------product--------------------
class product {
    private:
        int id=0;
        double price=0;
        string name="";
        int estoque=0;
    public:
        product();
        ~product();
        void setID(int i);
        void setPrice(double p);
        void setName(string n);
        void setEstoque(int e);
        int getID();
        double getPrice();
        string getName();
        int getEstoque();
};

product::~product() {}

product::product() {}

void product::setID(int i) {
    id = i;
};
void product::setPrice(double p) {
    price = p;
};
void product::setName(string n) {
    name = n;
};
void product::setEstoque(int e) {
    estoque = e;
};
int product::getID() {
    return id;
};
double product::getPrice() {
    return price;
};
string product::getName() {
    return name;
};
int product::getEstoque() {
    return estoque;
};

//-------------------------ITEM------------------------

class item {
    private:
        int id;
        int product_id;
        int order_id;
        int quantidade;
    public:
        item();
        ~item();
        void setID(int i);
        void setproduct_id(int p_i);
        void setorder_id(int pd_i);
        void setQuantidade(int qtd);
        int getID();
        int getproduct_id();
        int getorder_id();
        int getQuantidade();
};

item::item() {}
item::~item() {}
void item::setID(int i) {
    id = i;
};
void item::setproduct_id(int p_i) {
    product_id = p_i;
};
void item::setorder_id(int pd_i) {
    order_id = pd_i;
};
void item::setQuantidade(int qtd) {
    quantidade = qtd;
};
int item::getID() {
    return id;
};
int item::getproduct_id() {
    return product_id;
};
int item::getorder_id() {
    return order_id;
};
int item::getQuantidade() {
    return quantidade;
};

//-------------------------order------------------------
class order {
    private:
        int id = 0;
        double valor = 0;
        string pagamento = "nenhum";
        bool pago = false;
    public:
        order();
        ~order();
        void setID(int i);
        void setValor(double v);
        void setPagamento(string p);
        void setPago(bool pg);
        int getID();
        int getValor();
        string getPagamento();
        bool getPago();
        string gerarNotaFiscal();
};

order::order() {};

order::~order() {};

void order::setID(int i) {
    id = i;
};
void order::setValor(double v) {
    valor = v;
};
void order::setPagamento(string p) {
    pagamento = p;
};
void order::setPago(bool pg) {
    pago = pg;
};
int order::getID() {
    return id;
};
int order::getValor() {
    return valor;
};
string order::getPagamento() {
    return pagamento;
};
bool order::getPago() {
    return pago;
};
string order::gerarNotaFiscal() {
    cout << "=== NOTA FISCAL ===";
    return "nota fiscal";
};

int main () {
    product products[10000];
    item items[10000];
    order orders[10000];
    int option = 0;
    int product_id_count = 0;
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
            //3. Fazer pedido
                //Pedir dados do pedido
                //Colocar itens no produto
            system("cls");
        };

        if (option == 4)
        {
            //4. Sair
            system("cls");
        };
    };
}