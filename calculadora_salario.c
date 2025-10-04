#include <stdio.h>
#include <stdlib.h> // Recomendado para malloc/free e exit()

struct Funcionario{
  char nomeCompleto[100];
  float salarioBruto;
  float descontoINSS;
};

float calcularSalarioLiquido(struct Funcionario funcionario){
  float desconto = funcionario.salarioBruto * (funcionario.descontoINSS / 100.0f);
  return funcionario.salarioBruto - desconto;
}

int main(void) {
  int numFuncionarios;

  // ... (Resto do seu código C)

  return 0;
}
