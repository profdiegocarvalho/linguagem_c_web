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

  printf("Digite o número de funcionários:");
  scanf("%d",&numFuncionarios);

  struct Funcionario funcionario[numFuncionarios];

  for(int i = 0; i < numFuncionarios; i++){
    printf("Funcionário %d:\n", i + 1);
    printf("Nome Completo: ");
    scanf(" %[^\n]s",funcionario[i].nomeCompleto);
    printf("Salário Bruto: ");
    scanf("%f", &funcionario[i].salarioBruto);
    printf("Desconto do INSS (em porcentagem): ");
    scanf("%f", &funcionario[i].descontoINSS);
  }
  printf("\nRelatório de Salários Líquidos:\n");

  for(int i = 0; i < numFuncionarios; i++){
    float salarioLiquido = calcularSalarioLiquido(funcionario[i]);
    printf("Funcionário: %s\n", funcionario[i].nomeCompleto);
    printf("Salário Líquido: R$%.2f\n",salarioLiquido);
    printf("\n");
  }
  
  return 0;
}
