/*
INTEGRANTES DA DUPLA:
-Guilherme Matheus de Jesus de Araujo
-Felipe Cunegundes Alves Lourenço
*/

#include <stdio.h>
//Variáveis globais, na qual vão ter seus valores modificados em diferentes escopos
double peso = 0, peso_Max = 0, peso_Min = 3000000000, peso_Velho = 0, peso_Novo = 0, peso_Total = 0, preco_arroba = 0;
int id_animal = 0,  meses_animal = 0, mais_velho = 0, mais_novo = 0, id_MaisPesado = 0, id_MaisLeve = 0, meses_MaisPesado = 0, meses_MaisLeve = 0, meses_Total = 0, contador = 0;

//"Assinaturas" para poder iniciar as funções abaixo da main()
void cadastroAnimal();
double MediaPesos();
int MediaMeses();
void MostrarRelatorio(double preco_arroba);
void Limpeza();

int main (void)
{
  int escolha = 0; 
  //Aqui o usuário deve inserir o valor do arroba.
  printf("Digite o preco da arroba do boi: "); 
  scanf("%lf", &preco_arroba);
  //Aqui será o laço que mostrará ao usuário o menu de escolha.
  while(1)
  {
    printf("1. Inserir os dados de um animal\n");
    printf("2. Finalizar o lancamento\n");
    printf("3. Reset\n");
    printf("4. Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    if(escolha == 4) // Esse if servirá para parar o programa.
      break;
    else if(escolha == 3) //Esse if servirá para reiniciar o valores das variáveis por uma função.
      Limpeza();
    else if(escolha == 2) //Esse if sevirá para finalizar o lançamento e mostrar o relatório por uma função.
    {
      MostrarRelatorio(preco_arroba);
      break; 
    }
    else if(escolha == 1) //Esse if servirá para direcionar o usuário para a função cadastroAnimal por uma função.
      cadastroAnimal();
    else
      printf("Escolha invalida!\n");
  }
}

void cadastroAnimal() // Essa função será utilizada para preencher os dados cadastrais do animal.
{
  printf("Digite o n de Identificacao do animal: ");
  scanf("%d", &id_animal);
  printf("Digite o peso(kg): ");
  scanf("%lf", &peso);
  printf("Digite a idade(meses): ");
  scanf("%d", &meses_animal);
  //Nesta condição, serve-se para controlar a entrada de valores negativos
  if (!(peso < 0.0 || meses_animal < 0))
  {
    if(!(contador == 0)) //Condição para que o primeiro animal seja inserido em todas as variáveis da lista, enquanto os seguintes passam para as condições da lista
    {
      if(peso > peso_Max) // Esse if guardará o peso,identificação e a idade do animal mais pesado.
      {   
        id_MaisPesado = id_animal;
        peso_Max = peso;
        meses_MaisPesado = meses_animal;
      } 
      else if (peso < peso_Min)// Esse if guardará o peso, identifição e a idade do animal mais leve.
      {
        id_MaisLeve = id_animal;
        peso_Min = peso;
        meses_MaisLeve = meses_animal;
      }

      if(meses_animal > mais_velho)//Esse if guardará o peso e idade do animal mais velho.
      {
        mais_velho = meses_animal;
        peso_Velho = peso;
      }
      else if (meses_animal < mais_novo) //Esse if guadará o peso e a idade do animal mais novo.
      {
        mais_novo = meses_animal;
        peso_Novo = peso;
      }
      peso_Total = peso_Total + peso;         
      meses_Total += meses_animal;
      contador++; 
    }
    else
    {
      id_MaisPesado = id_animal;
      id_MaisLeve = id_animal;
      peso_Max = peso;
      peso_Min = peso;
      peso_Novo = peso;
      peso_Velho = peso;
      meses_MaisPesado = meses_animal;
      meses_MaisLeve = meses_animal;
      mais_novo = meses_animal;
      mais_velho = meses_animal;
      peso_Total = peso;
      meses_Total = meses_animal;
      contador++;
    }
  }
  else
    printf("Erro! Peso ou idade estao invalidos!\n");
}

double MediaPesos() //Essa função será reponsável pelo cálculo da media dos pesos.
{
  //Condição para previnir um erro de divisão por 0
  if(contador == 0)
    return -1;
  else
    return peso_Total/contador;
}

int MediaMeses() //Essa função será reponsável pelo cálculo da media das idades em meses.
{
  //Condição para previnir um erro de divisão por 0
  if(contador == 0)
    return -1;
  else
    return meses_Total/contador;
}

void MostrarRelatorio(double preco_arroba)//Essa função ficará responsável por mostrar o relátorio para o usuário.
{
  //Essas variáveis servirão para controlar se 
  double media_peso = 0; 
  int media_idade = 0;

  printf("O total de peso dos animais recebidos: %g\n\n", peso_Total);
  printf("Lista do animal mais pesado:\n");
  printf("Identificacao: %d\n", id_MaisPesado);
  printf("Peso: %g\n", peso_Max);
  printf("Idade(meses): %d\n\n", meses_MaisPesado);

  printf("Lista do animal mais leve:\n");
  printf("Identificacao: %d\n", id_MaisLeve);
  
  //Condição para evitar exibir o valor do peso_Min quando não inserir um animal
  if(peso_Min == 3000000000)
    printf("Peso: 0\n");
  else
    printf("Peso: %g\n", peso_Min);
  
  printf("Idade(meses): %d\n\n", meses_MaisLeve);

  printf("Idade e peso do animal mais velho:\n");
  printf("Peso: %g\n", peso_Velho);
  printf("Idade(meses): %d\n\n", meses_MaisPesado);

  printf("Idade e peso do animal mais novo:\n");
  printf("Peso: %g\n", peso_Novo);
  printf("Idade(meses): %d\n\n", meses_MaisLeve);

  media_peso = MediaPesos();
  media_idade = MediaMeses();
    
  if(media_peso == -1 || media_idade == -1)
    printf("Erro! Nenhum animal foi inserido para calcular peso, media ou lote!");
  else
  {
    printf("Media do peso dos animais inseridos: %g\n ", media_peso);
    printf("Media de idade(meses) dos animais inseridos: %d\n", media_idade);
    printf("Preco total do lote: %g\n", (peso_Total/15.0)*preco_arroba);
  }
}

void Limpeza() //Essa será a função responsável pelo reset/limpeza do programa.
{
  //As variáveis são colocadas nos valores iniciais
  peso = 0, peso_Max = 0, peso_Min = 3000000000, peso_Velho = 0, peso_Novo = 0, peso_Total = 0;
  id_animal = 0,  meses_animal = 0, mais_velho = 0, mais_novo = 0, id_MaisPesado = 0, 
  id_MaisLeve = 0, meses_MaisPesado = 0, meses_MaisLeve = 0, meses_Total = 0, contador = 0;

  //Inicio da primeira parte do programa antes de voltar para o menu
  main();
}
