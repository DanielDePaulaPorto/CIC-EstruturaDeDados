class No:
    def __init__(self, letra, frequencia):
        self.letra = letra
        self.frequencia = frequencia
        self.esquerda = None
        self.direita = None

    def __lt__(self, outro): # sobrescreve método de comparação entre objetos
        return self.frequencia < outro.frequencia

    def __str__(self):
        return f'{self.letra} {self.frequencia}'


def constroi_tabela_de_frequencia(texto):
    tabela_de_frequencia = {}
    for letra in texto:
        try:
            tabela_de_frequencia[letra] += 1
        except:
            tabela_de_frequencia[letra] = 1
    return tabela_de_frequencia


def huffman_constroi_arvore(tabela_de_frequencia):
    lista_nos = []
    for letra, frequencia in tabela_de_frequencia.items():
        novo_no = No(letra, frequencia)
        adiciona_no_lista(lista_nos, novo_no)

    while len(lista_nos) > 1:
        filho_direita = lista_nos.pop(0)
        filho_esquerda = lista_nos.pop(0)
        pai = No(None, filho_esquerda.frequencia + filho_direita.frequencia)
        pai.esquerda = filho_esquerda
        pai.direita = filho_direita
        adiciona_no_lista(lista_nos,pai)

    return lista_nos[0]

def adiciona_no_lista(lista_nos, novo_no):
    if len(lista_nos) == 0:
        lista_nos.append(novo_no)
    else:
        for posicao in range(len(lista_nos)):
            if lista_nos[posicao].frequencia >= novo_no.frequencia:
                break
        lista_nos.insert(posicao, novo_no)


def huffman_constroi_tabela_de_codificacao(root):
    tabela_de_codificacao = {}
    def cria_codigo(no, prefixo_codigo):
        if no.letra is not None:
            tabela_de_codificacao[no.letra] = prefixo_codigo
        else:
            cria_codigo(no.esquerda, prefixo_codigo + '0')
            cria_codigo(no.direita, prefixo_codigo + '1')

    cria_codigo(root, '')
    return tabela_de_codificacao


def huffman_codifica(texto):
    tabela_de_frequencia = constroi_tabela_de_frequencia(texto)
    arvore_de_huffman = huffman_constroi_arvore(tabela_de_frequencia)
    tabela_de_codificacao = huffman_constroi_tabela_de_codificacao(arvore_de_huffman)

    texto_codificado = ''
    for char in texto:
        texto_codificado += tabela_de_codificacao[char]

    return texto_codificado


def huffman_decodifica(texto_codificado, arvore_de_huffman):
    texto_decodificado = ''
    no_atual = arvore_de_huffman

    for bit in texto_codificado:
        if bit == '0':
            no_atual = no_atual.esquerda
        else:
            no_atual = no_atual.direita

        if no_atual.letra is not None:
            texto_decodificado += no_atual.letra
            no_atual = arvore_de_huffman

    return texto_decodificado

def get_string_binaria(string):
    string_binaria = ""
    for caractere in string:
        valor_decimal = ord(caractere)
        valor_binario = bin(valor_decimal)[2:]  # [2:] para remover o prefixo "0b"
        string_binaria += valor_binario.zfill(8)  # zfill(8) para preencher com zeros à esquerda
    return string_binaria


# Exemplo de uso
texto = "abracadabra!"
# texto = "Estrutura de dados é da hora!"

strinBinaria = get_string_binaria(texto)
print(f"Texto original: {strinBinaria}")

texto_codificado = huffman_codifica(texto)
print("Texto codificado:", texto_codificado)

arvore_de_huffman = huffman_constroi_arvore(constroi_tabela_de_frequencia(texto))

texto_decodificado = huffman_decodifica(texto_codificado, arvore_de_huffman)
print("Texto decodificado:", texto_decodificado)

print("-----------")
print("Tabela de conversao: " + str(huffman_constroi_tabela_de_codificacao(arvore_de_huffman)))
print("-----------")
taxa_compressao = 100 - len(texto_codificado)/(len(texto)*8) * 100
print("Taxa de compressão: "+str(round(taxa_compressao,2)) + "% ")
print("Original: " + str((len(texto)*8)) + " bits ")
print("Comprimido: " + str(len(texto_codificado)) + " bits")
