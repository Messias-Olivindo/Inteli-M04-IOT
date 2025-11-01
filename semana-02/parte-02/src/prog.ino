#include <string>
using namespace std;

class Faca {
    private: 
        string instrumento;
        string acao;
        string vitima;
    public:
        Faca(string instrumento_usado, string acao_praticada, string vitima_atingida) {
            instrumento = instrumento_usado;
            acao = acao_praticada;
            vitima = vitima_atingida;
        }

        string praticar() {
            return acao + "com" + instrumento + "a" + vitima;
        }
};

Faca katana("katana", "assassinei", "tonao");

void setup(){
    katana.praticar();
}