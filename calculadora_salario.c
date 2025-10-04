#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten/emscripten.h> // Header obrigatório para exportar funções

// --- Estruturas e Cálculos ---

// Estrutura Funcionario
typedef struct {
  char nomeCompleto[100];
  float salarioBruto;
  float descontoINSS;
} Funcionario;

// Função de cálculo pura
// É a lógica principal que queremos que o Wasm execute
float calcularSalarioLiquido(float salarioBruto, float descontoINSS) {
  float desconto = salarioBruto * (descontoINSS / 100.0f);
  return salarioBruto - desconto;
}

// Função wrapper para ser chamada pelo JavaScript
// Aceita os valores (float e float) e retorna o resultado
// EMSCRIPTEN_KEEPALIVE garante que a função não será removida pelo otimizador
EMSCRIPTEN_KEEPALIVE
float calcularSalarioLiquidoWasm(float salarioBruto, float descontoINSS) {
  // Chamada para a função de cálculo pura
  return calcularSalarioLiquido(salarioBruto, descontoINSS);
}

// --- Funções de Entrada/Saída e Main (Opcional, se o console for necessário) ---

// Se você deseja exportar a função principal para rodar no console Wasm
EMSCRIPTEN_KEEPALIVE
int main() {
  // NO Wasm, é melhor que main() não contenha I/O interativo.
  // O I/O é tratado pelo JavaScript.
  printf("WebAssembly pronto. Chame 'calcularSalarioLiquidoWasm' do JavaScript.\n");
  return 0;
}
