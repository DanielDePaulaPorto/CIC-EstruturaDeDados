
def moverDiscos(altura, pinoOrigem, pinoDestino, pinoAuxiliar):
    if altura >= 1:
        moverDiscos(altura-1,pinoOrigem, pinoAuxiliar, pinoDestino)
        print("Move disco ", altura, " do pino ",pinoOrigem, "para o pino ", pinoDestino)
        moverDiscos(altura-1, pinoAuxiliar, pinoDestino, pinoOrigem)

moverDiscos(20,"A", "C", "B")


