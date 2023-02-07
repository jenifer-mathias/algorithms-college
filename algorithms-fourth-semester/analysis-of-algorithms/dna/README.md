**Nome** Jenifer Mathias dos Santos

**TIA:** 32092946

**Nome:** Giulia Barbieri Quagliano

**TIA:** 42013070

**Nome:** Lucas Martins de Souza

**TIA:** 31943187

# Projeto-02

## Descrição

Aplicações biológicas frequentemente precisam comparar o DNA de dois ou mais diferentes organismos.
Um filamento de DNA consiste de uma string de moléculas chamadas bases, onde os possíveis bases são adenina,
guanina, citosina e timina. Representando cada uma destas bases pela letra inicial, podemos expressar
um filamento de DNA como uma string sobre um conjunto finito {A, C, G, T }.
Uma razão para comparar dois filamentos de DNA é determinar quão similares dois filamentos são,
como uma medida do quão proximamente relacionados os dois organismos estão. Nós podemos encontrar um terceiro
filamento S3 no qual as bases dentro de S3 aparecem em ambos S1 e S2. Estas bases devem aparecer na mesma ordem,
mas não necessariamente de forma consecutiva. Quanto maior o filamento S3, mais similares são S1 e S2.
Formalmente, dada uma sequência X = < x1, x2, . . . , xm >, uma outra sequência Z = <z1,z2,...,zk > é uma subsequência
de X se existir uma sequência estritamente crescente < i1,i2,...,ik > de índices de X tal que para todo j = 1,2,...,k,
tivermos xij = zj. Por exemplo, Z = < B,C,D,B > é uma subsequência de X = < A,B,C,B,D,A,B > com a sequência
correspondente de índices < 2, 3, 5, 7 >.

Dada duas sequências X e Y, dizemos que uma sequência Z é uma subsequência comum de X e Y se Z for uma subsequência
para ambos X e Y. Por exemplo, se X = < A,B,C,B,D,A,B > e Y = < B,D,C,A,B,A >, a sequência < B, C, A > não é a mais
longa subsequência comum para ambos X e Y, dado que tem comprimento 3 e a sequência <B,C,B,A>, que também é comum a
ambos X eY, tem tamanho 4. A sequência < B,C,B,A > é uma LCS de X e Y, assim como a sequência < B, D, A, B >,
dado que não há subsequências de tamanho 5 ou maior para X e Y. No problema da mais longa subsequência comum,
são dadas duas sequências X = < x1,x2,...,xm > e Y = < y1,y2,...,yn > e deseja-se encontrar subsequência comum
de tamanho máximo de X e Y.

## Implementação

Escreva um programa em Linguagem C que lê duas strings de tamanho até 1000 e determina a LCS entre elas.
A entrada se dará por meio de dois arquivos texto de nome: string1 e string2 com até 1000 caracteres cada um,
dispostos um em seguida ao outro, sem saltos forçados de linha.
Comente o seu programa.

## Resolução

Para gerar as cadeias de dna utilizadas nos arquivos [string1.txt](https://github.com/jenifer-mathias//algorithms-fourth-semester/analysis-of-algorithms/blob/main/dna/string1.txt) 
e [string2.txt](https://github.com/jenifer-mathias//algorithms-fourth-semester/analysis-of-algorithms/blob/main/dna/string2.txt).
foi usado o [Random DNA Sequence Generator](http://www.faculty.ucr.edu/~mmaduro/random.htm)

### Referências

<https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/>

<https://github.com/lucasrbk/projeto-LCS>

<https://www.techiedelight.com/longest-common-subsequence/>

<https://users.monash.edu/~lloyd/tildeStrings/Alignment/86.IPL.html>
