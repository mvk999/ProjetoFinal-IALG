ProjetoFinal-IALG


UNIVERSIDADE FEDERAL DE LAVRAS
DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
RELATÓRIO DO PROJETO PRÁTICO
(REGISTRO DE ATLETAS)

Fábio Damas Valim


Guilherme Lirio Miranda


Marcos Vinícius Pereira



Lavras - MG
Agosto de 2024

Sumário
Introdução
Descrição das Estruturas e Lógica do Programa
Estrutura dos Dados no Arquivo registros.bin
Erros e Acertos Durante o Desenvolvimento
Conclusão
1. Introdução
O projeto atual foi elaborado como parte da disciplina de Introdução aos Algoritmos, com o propósito de desenvolver um sistema de cadastro de atletas com capacidade de busca e alteração de dados. Esse sistema viabiliza a organização, classificação e busca de dados dos atletas registrados, abrangendo elementos como seu identificador, nome, data de nascimento, modalidade esportiva e nacionalidade, que estão dispostos em um arquivo binário. A seleção dos métodos de ordenação e busca, bem como a configuração dos registros, foram determinadas com base na necessidade de realizar operações eficazes nos dados, assegurando um desempenho adequado para conjuntos extensos de informações.

2. Descrição das Estruturas e Lógica do Programa
O programa desenvolvido se apoia fortemente em elementos como struct e algoritmos de ordenação. O principal recurso utilizado é o struct atleta, que organiza as informações dos atletas de forma sequencial, permitindo fácil acesso e manipulação dos dados. A lógica do programa está centrada na manipulação de um vetor de registros de atletas "album", onde são aplicadas operações de particionamento e ordenação utilizando o algoritmo "quicksort", bem como operações de busca através do algoritmo de busca binária.

O programa apresenta um menu intuitivo que, após a importação de um arquivo binário contendo as informações dos atletas, permite ao usuário listar de maneira integral ou fracionada os atletas registrados utilizando seu respectivo identificador, excluir ou incluir atletas no registro importado, realizar a busca de um atleta utilizando seu nome ou seu identificador, ordenar os atletas listados por ordem alfabética ou cronológica, gravar as alterações feitas em um novo arquivo binário ou exportar estas alterações através de um arquivo CSV.

As funcionalidades apresentadas no menu são possíveis através da utilização de procedimentos e funções presentes no código. Os procedimentos (void) incluem:

quicksort: Para ordenação do vetor "album".
listar_registros e listar_registros_intervalo: Proporcionam a listagem integral ou fracionada dos atletas.
incluir_registro e excluir_registro: Viabilizam a inclusão e exclusão de atletas do registro.
buscar_nome e buscar_id: Possibilitam a busca dos atletas no registro através de seu nome ou seu identificador.
importarCsv e exportarCsv: Condicionam a importação e exportação de arquivos no formato CSV.
importarBinario e gravarAlteracoes: Proporcionam a importação de arquivos binários e a criação de um novo arquivo binário que recebe e grava as alterações feitas no conteúdo do arquivo binário original.
Já as funções utilizadas são:

particiona_lomuto: Int. Algoritmo de particionamento usado para viabilizar a utilização do algoritmo de ordenação "quicksort".
busca_binaria e busca_binaria_nome: Int. Algoritmos de busca binária que retornam a posição do respectivo elemento procurado.
3. Estrutura dos Dados no Arquivo registros.bin
O arquivo binário registros.bin armazena os dados dos atletas sequencialmente, conforme a estrutura definida em struct atleta. Cada registro de atleta no arquivo é composto pelos seguintes campos:

ID: Int (identificador que enumera os atletas do registro).
Nome: String com espaço (nome dos atletas).
Ano de nascimento: Int (ano de nascimento de cada atleta).
Esporte: String com espaço (esporte praticado por cada atleta).
Nacionalidade: String com espaço (país de origem do atleta).
4. Erros e Acertos Durante o Desenvolvimento
Durante o desenvolvimento do projeto, ocorreram facilidades e percalços, característicos em projetos mais complexos. Desse modo, destacamos como facilidade a comunicação entre o grupo e o trabalho em equipe. A cooperação foi um fator essencial, e a boa convivência e responsabilidade dos participantes foram elementos que auxiliaram no projeto de maneira global, desde a boa indentação para identificação e manutenção do código por todos os participantes até o compromisso com as datas e a preocupação e empenho com o desenvolvimento do projeto. Dentre as dificuldades atestadas pelo grupo, destacamos a implementação de alguns recursos ao código, tal como a realização de operações com arquivos binários, que exigiram estudo e pesquisa adicionais para atribuição correta ao código. Contudo, entre as dificuldades e facilidades encontradas no desenvolvimento do projeto, é consenso do grupo afirmar que, de uma perspectiva geral, foi uma experiência enriquecedora acadêmica e socialmente através da cooperação dos participantes e esforço coletivo.

5. Conclusão
O projeto desenvolvido teve êxito em implementar um programa de cadastro de atletas operante e funcional, sendo capaz de lidar de maneira eficiente com um amplo espectro de dados. As estruturas, funções e procedimentos presentes no código garantem seu bom funcionamento e legibilidade. De modo geral, concluímos ao final do projeto a importância dos algoritmos na construção de soluções para problemas reais, aproximando o grupo da aplicação prática da computação.
