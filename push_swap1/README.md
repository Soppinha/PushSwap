# Push Swap

*Este projeto foi criado como parte do currículo da 42 por Sofia Bastos.*

## Descrição

O **push_swap** é um projeto de algoritmo e manipulação de dados que consiste em ordenar uma pilha de números inteiros utilizando um conjunto limitado de operações e o menor número possível de movimentos.

O projeto utiliza duas pilhas (a e b) e um conjunto restrito de operações:
- **sa/sb/ss**: troca os dois primeiros elementos da pilha
- **pa/pb**: move o primeiro elemento de uma pilha para outra
- **ra/rb/rr**: rotaciona a pilha para cima
- **rra/rrb/rrr**: rotaciona a pilha para baixo

O objetivo é desenvolver um algoritmo eficiente que minimize o número de operações necessárias para ordenar a pilha a, utilizando a pilha b como auxiliar.

### Estrutura de Dados

O projeto utiliza uma **lista duplamente encadeada** para representar cada pilha. Cada nó contém:
- `value`: o valor inteiro
- `index`: posição atual na pilha (0 = topo)
- `push_cost`: custo calculado para mover o elemento
- `above_median`: flag indicando se está na metade superior da pilha
- `best_match`: flag indicando se é o elemento mais barato para mover
- `target`: ponteiro para o nó alvo na outra pilha
- `next` e `prev`: ponteiros para navegação bidirecional

Esta estrutura permite operações eficientes de inserção, remoção e navegação em ambas as direções.

### Algoritmo Implementado

Este projeto implementa uma estratégia adaptativa baseada no tamanho da entrada:

**Para 2 elementos:**
- Solução direta: uma única operação `sa` se necessário

**Para 3 elementos:**
- Algoritmo otimizado em `sort_three()`: máximo 3 operações

**Para 4+ elementos:**
- Implementa uma variação do **Turk Algorithm**, um algoritmo de ordenação otimizado que:

1. Move elementos de `a` para `b` (mantém os 3 últimos em `a`)
2. Ordena os 3 elementos restantes em `a`
3. Para cada elemento em `b`:
   - Calcula o **índice** e identifica se está **acima ou abaixo da mediana**
   - Define o **target node** (alvo) em `a` - a posição correta onde deve ser inserido
   - Calcula o **custo** (número de operações) necessário para mover o elemento
   - Identifica o **best match** (elemento com menor custo)
4. Move elementos de volta para `a` na posição correta, priorizando movimentos mais baratos
5. Otimiza usando rotações duplas (`rr` ou `rrr`) quando ambas as pilhas precisam rotacionar na mesma direção
6. Finaliza rotacionando o menor elemento para o topo

O algoritmo utiliza conceitos de:
- **Target nodes**: cada nó em uma pilha tem um "alvo" na outra pilha (próximo menor para a→b, próximo maior para b→a)
- **Cost analysis**: calcula o custo (número de operações) para mover cada elemento considerando sua posição e a posição do alvo
- **Median tracking**: identifica se um elemento está acima ou abaixo da mediana para escolher entre rotação (`ra`) ou rotação reversa (`rra`), minimizando movimentos
- **Best match optimization**: sempre escolhe o elemento mais barato para mover, reduzindo o número total de operações

## Instruções

### Compilação

**Requisitos:**
- Compilador: `gcc` ou `cc`
- Flags: `-Wall -Wextra -Werror`
- Standard: C99 ou superior


```bash
make
```

Isso gerará o executável `push_swap` compilando o `main.c` junto com todos os módulos em `src/`.

### Compilação Adicional

```bash
make clean    # Remove arquivos objeto
make fclean   # Remove arquivos objeto e executável
make re       # Recompila tudo do zero
```

### Uso

```bash
./push_swap [números inteiros]
```

**Exemplos:**

```bash
# Números como argumentos separados
./push_swap 3 2 5 1 4

# Números em uma string
./push_swap "3 2 5 1 4"

# Exemplo com números negativos
./push_swap -5 2 -1 0 10
```

### Saída

O programa imprime na saída padrão a sequência de operações necessárias para ordenar a pilha:

```bash
# Exemplo com 3 números
$ ./push_swap 3 2 1
sa
rra

# Exemplo com 2 números
$ ./push_swap 2 1
sa

# Exemplo com pilha já ordenada (sem output)
$ ./push_swap 1 2 3 4 5
$

# Exemplo com 5 números
$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
ra
ra
```

## Fluxo de Execução

1. **Inicialização** (`main.c`):
   - Verifica se há argumentos (se argc < 2, retorna sem erro)
   - Inicializa as pilhas a e b como NULL

2. **Parsing** (`parse.c`):
   - Valida argumentos da linha de comando
   - Converte strings em números inteiros
   - Verifica duplicatas e limites de INT
   - Constrói a pilha inicial

3. **Verificação de Ordenação** (`stack_utils.c`):
   - Verifica se a pilha já está ordenada com `is_sorted()`
   - Se sim, pula para a liberação de memória (sem operações)

4. **Algoritmo de Ordenação** (seleção baseada no tamanho):
   - **2 elementos**: executa apenas `sa` se necessário
   - **3 elementos**: usa `sort_three()` - algoritmo específico e otimizado
   - **4+ elementos**: implementa o algoritmo Turk completo
     - Move todos elementos exceto 3 para pilha b (`pb`)
     - Ordena os 3 elementos restantes em a
     - Para cada elemento em b:
       - Calcula índices e mediana
       - Define alvos (target nodes) em a
       - Calcula custos de movimentação
       - Identifica o movimento mais barato
       - Otimiza rotações duplas quando possível
       - Move elemento para posição correta em a
     - Posiciona o menor elemento no topo

5. **Finalização**:
   - Libera toda memória alocada (`free_stack()`)
   - Retorna 0 (sucesso)

## Casos Especiais

### 2 Elementos
```c
// Se desordenado, apenas troca
sa(&a, 1);
```

### 3 Elementos
Implementa lógica otimizada em `sort_three()`:
- Identifica o maior elemento
- Posiciona-o no final
- Troca os dois primeiros se necessário
- Máximo de 3 operações

## Gerenciamento de Memória

O projeto implementa gerenciamento cuidadoso de memória:

- **Alocação**: todos os nós da pilha são alocados dinamicamente
- **Liberação**: `free_stack()` e `free_split()` garantem que não há vazamentos
- **Error handling**: em caso de erro durante parsing ou alocação, toda memória já alocada é liberada antes de encerrar
- **Valgrind**: o programa deve executar sem memory leaks quando testado com valgrind

Exemplo de teste com valgrind:
```bash
valgrind --leak-check=full ./push_swap 3 2 1 5 4
```

## Testes Recomendados

### Testes Básicos
```bash
# Sem argumentos (deve retornar sem erro)
./push_swap

# Um número (nenhuma operação)
./push_swap 42

# Pilha já ordenada (nenhuma operação)
./push_swap 1 2 3 4 5

# 2 elementos
./push_swap 2 1

# 3 elementos (todas as permutações)
./push_swap 2 1 3
./push_swap 3 2 1
./push_swap 1 3 2
```

### Testes de Erro
```bash
# Duplicatas
./push_swap 1 2 3 2    # Error

# Não numérico
./push_swap 1 2 abc    # Error

# Overflow
./push_swap 2147483648 # Error

# Argumento vazio
./push_swap ""         # Error
```

### Testes de Performance
```bash
# Gerar números aleatórios e contar operações
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Teste com caso pior (ordem reversa)
./push_swap $(seq 100 -1 1) | wc -l
```
## Tratamento de Erros

O programa verifica e trata os seguintes casos através do módulo `parse.c`:

- ✓ **Números duplicados**: verifica se há valores repetidos antes de adicionar à pilha
- ✓ **Argumentos não numéricos**: valida caracteres (aceita apenas dígitos, '+' e '-')
- ✓ **Números fora do intervalo de INT**: verifica se os valores estão entre INT_MIN e INT_MAX
- ✓ **Argumentos vazios**: detecta strings vazias ou inválidas
- ✓ **Formato inválido**: valida sinais '+' e '-' seguidos de dígitos
- ✓ **Pilha já ordenada**: não executa operações se já estiver ordenada (retorna sem output)

**Comportamento especial:**
- Se o programa for executado sem argumentos (`argc < 2`), retorna 0 sem imprimir erro (comportamento esperado pela 42)

### Validação de Entrada

O parsing suporta duas formas de entrada:

```bash
# Múltiplos argumentos
./push_swap 3 2 1 5 4

# String única com espaços
./push_swap "3 2 1 5 4"

# Combinação de ambos
./push_swap 3 2 "1 5 4"
```

Em caso de erro durante validação, o programa imprime `Error\n` na saída de erro padrão (stderr) e encerra com código de erro.

### Ferramentas de Teste
- **push_swap_visualizer**: visualiza as operações graficamente
- **push_swap_tester**: testa múltiplos casos e verifica número de operações
- **checker**: verifica se a sequência de operações ordena corretamente (se implementado)

## Recursos

### Documentação e Referências

- **Subject da 42**: Documento oficial do projeto push_swap
- **Visualizador de push_swap**: [push-swap-visualizer](https://github.com/o-reo/push_swap_visualizer) - ferramenta para visualizar as operações
- **Algoritmos de ordenação**: estudo sobre complexidade algorítmica e otimização
- **Estruturas de dados**: listas duplamente encadeadas em C

### Artigos e Tutoriais

- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - explicação do algoritmo Turk
- [Sorting algorithms comparison](https://www.bigocheatsheet.com/) - complexidade de algoritmos
- Conceitos de pilhas (stacks) e operações fundamentais

### Uso de IA

A Inteligência Artificial foi utilizada neste projeto para:

- **Geração deste README.md**: estruturação da documentação.
- **Explicação de conceitos**: esclarecimento sobre o funcionamento do algoritmo e suas otimizações.


**Importante**: Todo o código de implementação foi desenvolvido manualmente. A IA foi utilizada apenas como ferramenta de apoio para documentação e compreensão teórica do algoritmo.