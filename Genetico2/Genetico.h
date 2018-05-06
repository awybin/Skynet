

/*Altera a ordem do vetor de soluções para que o inicio tenham as soluções com melhor valor de fitness*/
std::vector<Solucao> selecao(std::vector<Solucao> populacao);

void crossover(Solucao pai, Solucao mae, Solucao filhos[2]);

void crossover2(Solucao pai, Solucao mae, Solucao filhos[2]);

bool melhorSolucao(const Solucao &s1, const Solucao &s2);

Solucao mutacao(Solucao filho);

void genetico(char* path, int popSize);

std::vector<Solucao> embaralhaPop(std::vector<Solucao> populacao);