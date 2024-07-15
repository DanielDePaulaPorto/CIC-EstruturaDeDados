
def maximize(x):
    maximo = 0
    maiorY = 0
    for y in range(1,x):
        resultoadoMDC = mdc(y,x)
        soma = resultoadoMDC + y
        if soma > maximo:
            maximo = soma
            maiorY = y
    return maiorY


def mdc(a,b):
    if b == 0:
        return a
    else:
        return mdc(b,a%b)



testes = int(input())

for i in range(testes):
    x = int(input())
    print(maximize(x))