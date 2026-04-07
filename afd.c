/*

 */

#include <stdio.h>

#define ERRO               0
#define INTEIRO            1
#define INTEIRO_SINAL      2
#define P_FLUTUANTE        3
#define P_FLUTUANTE_SINAL  4
#define FIM               -1

//Intengrantes:
//Felipe Hideki Rodrigues Shinozaki RA:10438584
//Gabriel Franco da Rosa Messora    RA:10438405
//João Francisco do Nascimento Paulino Marques  RA:10443666

int scanner(const char *str) {
    static int pos = 0;
    char c;

    //estados modelados conforme as regras apresentadas
    q0:
        c = str[pos]; if (c != '\0') pos++;
        if (c == ' ')                  goto q0;
        else if (c == '\0')            return FIM;
        else if (c=='+' || c=='-')     goto q1;
        else if (c == '0')             goto q2;
        else if (c>='1' && c<='9')     goto q3;
        else                           goto qE;

    q1:
        c = str[pos]; if (c != '\0') pos++;
        if (c == '0')                  goto qE;
        else if (c>='1' && c<='9')     goto q5;
        else if (c==' ' || c=='\0')    return ERRO;
        else                           goto qE;

    q2:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q6;
        else if (c == ',')             goto q7;
        else if (c==' ' || c=='\0')    return INTEIRO;
        else                           goto qE;

    q3:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q3;
        else if (c == ',')             goto q8;
        else if (c==' ' || c=='\0')    return INTEIRO;
        else                           goto qE;

    q4:
        c = str[pos]; if (c != '\0') pos++;
        if (c == ',')                  goto q9;
        else if (c==' ' || c=='\0')    return ERRO;
        else                           goto qE;

    q5:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q5;
        else if (c == ',')             goto q10;
        else if (c==' ' || c=='\0')    return INTEIRO_SINAL;
        else                           goto qE;

    q6:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q6;
        else if (c == ',')             goto qE;
        else if (c==' ' || c=='\0')    return INTEIRO;
        else                           goto qE;

    q7:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q11;
        else if (c==' ' || c=='\0')    return ERRO;
        else                           goto qE;

    q8:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q11;
        else if (c==' ' || c=='\0')    return ERRO;
        else                           goto qE;

    q9:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q12;
        else if (c==' ' || c=='\0')    return ERRO;
        else                           goto qE;

    q10:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q12;
        else if (c==' ' || c=='\0')    return ERRO;
        else                           goto qE;

    q11:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q11;
        else if (c==' ' || c=='\0')    return P_FLUTUANTE;
        else                           goto qE;

    q12:
        c = str[pos]; if (c != '\0') pos++;
        if (c>='0' && c<='9')          goto q12;
        else if (c==' ' || c=='\0')    return P_FLUTUANTE_SINAL;
        else                           goto qE;

    qE:
        c = str[pos]; if (c != '\0') pos++;
        if (c==' ' || c=='\0')         return ERRO;
        else                           goto qE;
}

int main() {

    //main com teste
    const char *str = "21 +4+5,6 00,123 +0,456 -42. xx -123";
    FILE *f;
    int resultado;

    f = fopen("saida.txt", "w");

    //escaneia e registra 
    while ((resultado = scanner(str)) != FIM) {
        switch (resultado) {
            case INTEIRO:           fprintf(f, "<INTEIRO>\n");              break;
            case INTEIRO_SINAL:     fprintf(f, "<INTEIRO COM SINAL>\n");    break;
            case P_FLUTUANTE:       fprintf(f, "<P.FLUTUANTE>\n");          break;
            case P_FLUTUANTE_SINAL: fprintf(f, "<P.FLUTUANTE COM SINAL>\n");break;
            case ERRO:              fprintf(f, "<ERRO>\n");                 break;
        }
    }

    fclose(f);
    return 0;
}
