
/*Faz as chamadas das funcoes fazendo a melhor metade da populacao
permanecer e substituindo a metade pior com os filhos dos melhores
O popSize passado como parametro deve ser um numero divisivel por 4*/
void genetico(char* path, int popSize);

/*Altera a ordem do vetor de soluções para que o inicio tenham as soluções com melhor valor de fitness*/
std::vector<Solucao> selecao(std::vector<Solucao> populacao);

/*Reordena o vetor de elementos baseando-se no PMX, porem escolhendo uma quantidade
variavel de segmentos que sao os bins mais de 90% cheios
o resultado é retornado no vetor de filhos passado como parametro*/
void crossover(Solucao pai, Solucao mae, Solucao filhos[2]);

/*Funcao chamada pelo crossover para buscar os elementos equivalentes que estao fora dos melhores bins*/
elemento recursiva(int i, std::vector<int> comecoBin, std::vector<int> fimBin, Solucao pai1, Solucao pai2);

/*Retorna true se s2 é melhor que s1 e false caso contrario*/
bool melhorSolucao(const Solucao &s1, const Solucao &s2);

/*Tem uma chance de 7% de realizar swaps em 10% do tamanho do vetor de elementos*/
Solucao mutacao(Solucao filho);

/*Embaralha a primeira metade do vetor de populacao passado como parametro de forma pseudo-aleatoria*/
std::vector<Solucao> embaralhaPop(std::vector<Solucao> populacao);

void crossover2(Solucao pai, Solucao mae, Solucao filhos[2]);