
def duploFatorial(numero):
    if numero == 0 or numero == 1:
        return 1
    else:
        return numero * duploFatorial(numero-2)

print(duploFatorial(8))


