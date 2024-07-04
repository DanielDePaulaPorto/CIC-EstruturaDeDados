def prioridadeAumentou(operaçãoAntiga,operaçãoNova):
    ordemDasOperações = [['+','-'],['*','/']]
    def search(x):
        for i in range(len(ordemDasOperações)):
            if x in ordemDasOperações[i]:
                return i
    prioridadeAntiga = search(operaçãoAntiga)
    prioridadeNova = search(operaçãoNova)
    if prioridadeNova > prioridadeAntiga:
        return True
    else:
        return False



def notaçãoPolonesaInversa(infixa):
    posfixa = ''
    prioridade = 0
    operações = ['+','-','*','/']
    operationDict = {0:[]}
    for i in range(len(infixa)):
        if infixa[i] == "(":
            prioridade += 1
            operationDict[prioridade] = []
        elif infixa[i] == ")":
            for _ in range(len(operationDict[prioridade])):
                posfixa += operationDict[prioridade].pop()
            operationDict.pop(prioridade)
            prioridade -= 1
        elif infixa[i].isalpha():
            posfixa += infixa[i]
        elif infixa[i] in operações:
            if operationDict[prioridade] == []:
                operationDict[prioridade].append(infixa[i])
            else:
                if prioridadeAumentou(operaçãoAntiga=operationDict[prioridade][-1],operaçãoNova=infixa[i]):
                    operationDict[prioridade].append(infixa[i])
                else:
                    for _ in range(len(operationDict[prioridade])):
                        posfixa += operationDict[prioridade].pop()
                    operationDict[prioridade].append(infixa[i])
    for _ in range(len(operationDict[0])):
        posfixa += operationDict[0].pop()
    return posfixa


infixa1 = 'a+(b-c*g*(e+f))/g'
infixa2 = '((a*b)-(c*d))/(e*f)'
infixa3 = 'A*(B+C)/D-E'
infixa4 = 'A+B*(C-D*(E-F)-G*H)-I*J'
infixa5 = 'A+B*C/D*E-F'
infixa6 = 'A+(B-(C+(D-(E+F))))'
infixa7 = 'A*(B+(C*(D+(E*(F+G)))))'

posfixa = notaçãoPolonesaInversa(infixa = infixa2)

print(posfixa)