#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define log10(x) log(x)/log(10); //Definindo os logaritomos, ja que sao valores constantes que nao vao mudar se usa #define ou 'const'. foi assim que eu aprendi, espero nao esta errado :).

    float f(float x){
        return pow(x,3)-9*(x)+5; //Funçao que eu peguei de uma imagem da internet: https://i.ytimg.com/vi/clYhHLC-dfo/maxresdefault.jpg
    }
int main(){ // função principal
    float a, xE, b, Ea, it, calcularAmB; // variaveis a, xE valor estimado, it intercequiçao, calcularAmB é a soma de A e B.
    int bolzano = 0; //Teorema de bolzano


    printf("Digite o valor de 'a' da intercecao de [a;b]: ");           //Solicitando
    scanf("%f", &a);                                                    //as
    printf("Digite o valor de 'b' da intececao de [a;b]: ");            //Variaveis
    scanf("%f", &b);                                                    //E
    printf("Qual o valor aproximado de Erro Absoluto: ");               //Aqui
    scanf("%f", &Ea);                                                   //tbm

    bolzano = (f(a)*f(b) > 0); //Teste do teorema de bolzanos

    while(bolzano == 0){        //Teste do teorema de bolzanos
        printf("Erro nao deu certo tente outros valores\n");
        break;
    }
    
    //Calculo utilizado para saber os valores de cada variavel usando log.
    it = log10(b - a);
    it -= log10(Ea);
    it /= log(2);

    if (f(a) == 0 || f(b) == 0){
        printf("O valor %f e zero da expressao", f(a)==0?a:b);
    }
    while (xE > Ea){ //parte crucial do calculo para acha o resultado, loop para resolver e achar o mais proximo do Ea.
        xE = b-a;
        calcularAmB = (a+b)/2; //aqui a variaveu pe calculo das medias de a e b.
        printf("Valor da tentativa: %f\n", calcularAmB);
        if (f(calcularAmB)==0)
        {
            printf("Resultado exato: %f\n", calcularAmB);
        }
        if (f(a)*f(calcularAmB)<0)
        {
            b = calcularAmB;
        }else{
            a = calcularAmB;
        }
        
    }
    for (int i = 0; i < calcularAmB; i++)
    {
        printf("Valor da tentativa: %f\n", calcularAmB);
    }
    
    
    printf("O Intervalo de %f a %f\nTem sua solucao mais proxima: %f", a, b, (a+b)/2);

    return 0;
}