def quemEhOUltimo(lista,n):
    x=-1
    while len(lista)>1:
        x = (x + n)%len(lista)
        lista.pop(x)
        x = (x-1)%len(lista)
    print(lista[0])

lista = ["Maria","José","Nadia","Pedro","Júlio","César"]

quemEhOUltimo(lista,3)