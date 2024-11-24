#include <iostream>
#include <vector>
#include <string>

class Carro {
private:
    std::string marca;
    std::string modelo;
    double valor;
    int quilometragem;
    std::string combustivel;
    static int totalCarros;  // Atributo estático para armazenar o total de carros

public:
    void inserirDados(const std::string& m, const std::string& mod, double v, int km, const std::string& comb) {
        marca = m;
        modelo = mod;
        valor = v;
        quilometragem = km;
        combustivel = comb;
        totalCarros++;  // Incrementa o total de carros ao inserir um novo carro
    }

    void exibirDados() const {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo
                  << ", Valor: " << valor << ", Quilometragem: " << quilometragem
                  << ", Combustível: " << combustivel << std::endl;
    }

    bool verificarMarcaOuModelo(const std::string& criterio) const {
        return (marca == criterio || modelo == criterio);
    }

    bool verificarValor(double valorBusca) const {
        return (valor <= valorBusca);
    }

    bool verificarQuilometragem(int kmBusca) const {
        return (quilometragem <= kmBusca);
    }

    bool verificarCombustivel(const std::string& combustivelBusca) const {
        return (combustivel == combustivelBusca);
    }

    static int getTotalCarros() {
        return totalCarros;
    }
};

// Inicialização do atributo estático
int Carro::totalCarros = 0;

int main() {
    std::vector<Carro> carros(10);
    int quantidadeCarros = 0;

    while (true) {
        int opcao;
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Cadastrar um novo carro\n";
        std::cout << "2. Consultar total de carros cadastrados\n";
        std::cout << "3. Buscar carros\n";
        std::cout << "4. Sair\n";
        std::cin >> opcao;

        if (opcao == 1) {
            std::string marca, modelo, combustivel;
            double valor;
            int quilometragem;

            std::cout << "Informe a Marca: ";
            std::cin >> marca;
            std::cout << "Informe o Modelo: ";
            std::cin >> modelo;
            std::cout << "Informe o Valor: ";
            std::cin >> valor;
            std::cout << "Informe a Quilometragem: ";
            std::cin >> quilometragem;
            std::cout << "Informe o Tipo de Combustível: ";
            std::cin >> combustivel;

            carros[quantidadeCarros++].inserirDados(marca, modelo, valor, quilometragem, combustivel);
        } else if (opcao == 2) {
            std::cout << "Total de carros cadastrados: " << Carro::getTotalCarros() << std::endl;
        } else if (opcao == 3) {
            std::cout << "Escolha uma opção de busca:\n";
            std::cout << "1. Por Marca ou Modelo\n";
            std::cout << "2. Por Valor máximo\n";
            std::cout << "3. Por Quilometragem máxima\n";
            std::cout << "4. Por Tipo de Combustível\n";
            int buscaOpcao;
            std::cin >> buscaOpcao;

            if (buscaOpcao == 1) {
                std::string criterio;
                std::cout << "Informe a Marca ou Modelo: ";
                std::cin >> criterio;

                for (const auto& carro : carros) {
                    if (carro.verificarMarcaOuModelo(criterio)) {
                        carro.exibirDados();
                    }
                }
            } else if (buscaOpcao == 2) {
                double valorBusca;
                std::cout << "Informe o Valor máximo: ";
                std::cin >> valorBusca;

                for (const auto& carro : carros) {
                    if (carro.verificarValor(valorBusca)) {
                        carro.exibirDados();
                    }
                }
            } else if (buscaOpcao == 3) {
                int kmBusca;
                std::cout << "Informe a Quilometragem máxima: ";
                std::cin >> kmBusca;

                for (const auto& carro : carros) {
                    if (carro.verificarQuilometragem(kmBusca)) {
                        carro.exibirDados();
                    }
                }
            } else if (buscaOpcao == 4) {
                std::string combustivelBusca;
                std::cout << "Informe o Tipo de Combustível: ";
                std::cin >> combustivelBusca;

                for (const auto& carro : carros) {
                    if (carro.verificarCombustivel(combustivelBusca)) {
                        carro.exibirDados();
                    }
                }
            } else {
                std::cout << "Opção inválida!" << std::endl;
            }
        } else if (opcao == 4) {
            break;
        } else {
            std::cout << "Opção inválida!" << std::endl;
        }
    }

    return 0;
}