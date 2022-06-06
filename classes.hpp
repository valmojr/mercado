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
		string itens = "";
        bool pago = false;
    public:
        order();
        ~order();
        void setID(int i);
        void setValor(double v);
        void setPagamento(string p);
        void setPago(bool pg);
		void setItens(string i);
        int getID();
        int getValor();
        string getPagamento();
        bool getPago();
		string getItens();
        void gerarNotaFiscal();
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
void order::setItens(string i){
	itens = i;
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
string order::getItens() {
	return itens;
}
void order::gerarNotaFiscal() {
    cout << "===== NFE =====\n";
	cout << "Pedido Nr " << id << "\n";
	cout << itens;
	cout << "Valor Total: R$" << valor << "\n";
	cout << "Status: ";
	if (pago) {
		cout << "Pago em " << pagamento << "\n";
	} else {
		cout << "A quitar\n";
	}
};