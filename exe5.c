#include <stdio.h>  
  
int main()  
{
    char cpf[12];
    int intCpf[12];
    int i, contadorSoma = 0, primeiroDigito, resultado1, resultado2, segundoDigito, valor;

    //Letra a
    printf("Digite o cpf:\n");
    scanf("%s", cpf);

    //array char(cpf) -> array Int(intCpf).
    for(i = 0; i < 11; i++)
    {
        //decoy = cpf[i];// - 48;
        intCpf[i] = cpf[i] - 48;
        //intCpf[i];
        //printf(intCpf[i]);
    }

    //Primeiro digito, pega um por um do array e multiplica

    for(i = 0; i < 9; i++)
    {
        contadorSoma += intCpf[i] * (10 - i);
    }

    resultado1 = contadorSoma % 11;

    if((resultado1 == 0) || (resultado1 == 1))
    {
        primeiroDigito = 0;
    }
    else
    {
        primeiroDigito = 11 - resultado1;
    }

    //Segundo digito

    contadorSoma = 0;

    for(i = 0; i < 10; i++)
    {
        contadorSoma += intCpf[i] * (11 - i);
    }

    valor = (contadorSoma / 11) * 11;
    resultado2 = contadorSoma - valor;

    if((resultado2 == 0) || (resultado2 == 1))
    {
        segundoDigito = 0;
    }
    else
    {
        segundoDigito = 11 - resultado2;
    }

    //Letra b

    if((primeiroDigito == intCpf[9]) && (segundoDigito == intCpf[10]))
    {
        printf("\nCPF OK\n");
    }
    else
    {
        printf("\nCPF INCORRETO\n");
    }

    return 0;
}