/**
 Grupo:
 Giulia Barbieri Quagliano - TIA: 42013070
 Gabriela Lopes - TIA: 31744591
 Jenifer Mathias dos Santos - TIA: 32092946
 Lucas Martins de Souza - TIA: 31943187
 **/

#include <stdio.h>
#include <string.h>

#define _Rejeita_ 0
#define _Aceita_ 1


int scanner(char palavra[]) {
    int i = 0;
    int j = 0;
    char c;

    q0:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '/') {
        if (palavra[i] == '*') {
            goto q65;
        } else goto q12;
    } else if (c == '_') {
        goto q1;
    } else if (c == '{') {
        goto q4;
    } else if (c == '}') {
        goto q5;
    } else if (c == '(') {
        goto q7;
    } else if (c == ',') {
        goto q8;
    } else if (c == ';') {
        goto q9;
    } else if (c == '+') {
        goto q10;
    } else if (c == '-') {
        goto q11;
    } else if (c == '/') {
        goto q12;
    } else if (c == '*') {
        goto q13;
    } else if (c == '<') {
        if (palavra[i] == '>') {
            goto q16;
        } else if (palavra[i] == '=') {
            goto q17;
        } else goto q14;
    } else if (c == '>') {
        if (palavra[i] == '=') {
            goto q18;
        } else goto q15;
    } else if (c == '=') {
        if (palavra[i] == '=') {
            goto q19;
        } else goto q20;
    } else if (c == 'b') {
        goto q21;
    } else if (c == 't') {
        goto q25;
    } else if (c == 'f') {
        goto q29;
    } else if (c == 'i') {
        goto q34;
    } else if (c == 'e') {
        goto q38;
    } else if (c == 'p') {
        goto q42;
    } else if (c == 's') {
        goto q49;
    } else if (c == 'd') {
        goto q54;
    } else if (c == 'v') {
        goto q56;
    } else if (c == 'w') {
        goto q60;
    } else goto poco;


    q1:
    c = palavra[i];
    i++;
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' ||
        c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' ||
        c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' ||
        c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' ||
        c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' ||
        c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' ||
        c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' ||
        c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' ||
        c == 'W' || c == 'X' || c == 'Y' || c == 'Z') {
        goto q2;
    } else return (_Rejeita_);


    q2:
    c = palavra[i];
    i++;
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' ||
        c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' ||
        c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' ||
        c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' ||
        c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' ||
        c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' ||
        c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' ||
        c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' ||
        c == 'W' || c == 'X' || c == 'Y' || c == 'Z') {
        goto q2;
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q3:
    c = palavra[i];
    i++;
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
        c == '6' || c == '8' || c == '9') {
        goto q3;
    } else if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q4:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }


    q5:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }


    q6:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }


    q7:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }


    q8:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }


    q9:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Aceita_);
    } else {
        i--;
        goto q0;
    }

    q10:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q10;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q11:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q11;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q12:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q12;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q13:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q13;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q14:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q14;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q15:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q15;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q16:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q16;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q17:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q10;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q18:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q18;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q19:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q19;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q20:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q20;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
               || c == '6' || c == '8' || c == '9') {
        goto q3;
    } else {
        i--;
        goto q0;
    }

    q21:
    c = palavra[i];
    i++;
    if (c == 'o') {
        goto q22;
    } else return (_Rejeita_);

    q22:
    c = palavra[i];
    i++;
    if (c == 'o') {
        goto q23;
    } else return (_Rejeita_);

    q23:
    c = palavra[i];
    i++;
    if (c == 'l') {
        goto q24;
    } else return (_Rejeita_);

    q24:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q25:
    c = palavra[i];
    i++;
    if (c == 'r') {
        goto q26;
    } else return (_Rejeita_);

    q26:
    c = palavra[i];
    i++;
    if (c == 'u') {
        goto q27;
    } else return (_Rejeita_);

    q27:
    c = palavra[i];
    i++;
    if (c == 'e') {
        goto q28;
    } else return (_Rejeita_);

    q28:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q29:
    c = palavra[i];
    i++;
    if (c == 'a') {
        goto q30;
    } else return (_Rejeita_);

    q30:
    c = palavra[i];
    i++;
    if (c == 'l') {
        goto q31;
    } else return (_Rejeita_);

    q31:
    c = palavra[i];
    i++;
    if (c == 's') {
        goto q32;
    } else return (_Rejeita_);

    q32:
    c = palavra[i];
    i++;
    if (c == 'e') {
        goto q33;
    } else return (_Rejeita_);

    q33:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q34:
    c = palavra[i];
    i++;
    if (c == 'f') {
        goto q35;
    } else if (c == 'n') {
        goto q36;
    } else return (_Rejeita_);

    q35:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q36:
    c = palavra[i];
    i++;
    if (c == 't') {
        goto q37;
    } else return (_Rejeita_);

    q37:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q38:
    c = palavra[i];
    i++;
    if (c == 'l') {
        goto q39;
    } else return (_Rejeita_);

    q39:
    c = palavra[i];
    i++;
    if (c == 's') {
        goto q40;
    } else return (_Rejeita_);

    q40:
    c = palavra[i];
    i++;
    if (c == 'e') {
        goto q41;
    } else return (_Rejeita_);

    q41:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q42:
    c = palavra[i];
    i++;
    if (c == 'r') {
        goto q43;
    } else return (_Rejeita_);

    q43:
    c = palavra[i];
    i++;
    if (c == 'o') {
        goto q44;
    } else if (c == 'i') {
        goto q46;
    } else return (_Rejeita_);

    q44:
    c = palavra[i];
    i++;
    if (c == 'c') {
        goto q45;
    } else return (_Rejeita_);

    q45:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q46:
    c = palavra[i];
    i++;
    if (c == 'n') {
        goto q47;
    } else return (_Rejeita_);

    q47:
    c = palavra[i];
    i++;
    if (c == 't') {
        goto q48;
    } else return (_Rejeita_);

    q48:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q49:
    c = palavra[i];
    i++;
    if (c == 'e') {
        goto q50;
    } else return (_Rejeita_);

    q50:
    c = palavra[i];
    i++;
    if (c == 'm') {
        goto q51;
    } else return (_Rejeita_);

    q51:
    c = palavra[i];
    i++;
    if (c == 'i') {
        goto q52;
    } else return (_Rejeita_);

    q52:
    c = palavra[i];
    i++;
    if (c == 'c') {
        goto q48;
    } else return (_Rejeita_);

    q53:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q54:
    c = palavra[i];
    i++;
    if (c == 'o') {
        goto q55;
    } else return (_Rejeita_);

    q55:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q56:
    c = palavra[i];
    i++;
    if (c == 'o') {
        goto q57;
    } else return (_Rejeita_);

    q57:
    c = palavra[i];
    i++;
    if (c == 'i') {
        goto q58;
    } else return (_Rejeita_);

    q58:
    c = palavra[i];
    i++;
    if (c == 'd') {
        goto q59;
    } else return (_Rejeita_);

    q59:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q60:
    c = palavra[i];
    i++;
    if (c == 'h') {
        goto q61;
    } else return (_Rejeita_);

    q61:
    c = palavra[i];
    i++;
    if (c == 'i') {
        goto q62;
    } else return (_Rejeita_);

    q62:
    c = palavra[i];
    i++;
    if (c == 'l') {
        goto q63;
    } else return (_Rejeita_);

    q63:
    c = palavra[i];
    i++;
    if (c == 'e') {
        goto q64;
    } else return (_Rejeita_);

    q64:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    q65:
    c = palavra[i];
    i++;
    if (c == '*') {
        goto q67;
    } else if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f'
               || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' ||
               c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' ||
               c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' ||
               c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' ||
               c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' ||
               c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' ||
               c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' ||
               c == 'W' || c == 'X' || c == 'Y' || c == 'Z' || c == ' ') {
        goto q66;
    } else return (_Rejeita_);

    q66:
    c = palavra[i];
    i++;
    if (c == '*') {
        goto q67;
    } else if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f'
               || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' ||
               c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' ||
               c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' ||
               c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' ||
               c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' ||
               c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' ||
               c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' ||
               c == 'W' || c == 'X' || c == 'Y' || c == 'Z' || c == ' ') {
        goto q66;
    } else return (_Rejeita_);

    q67:
    c = palavra[i];
    i++;
    if (c == '*') {
        goto q67;
    } else if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f'
               || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' ||
               c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' ||
               c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' ||
               c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' ||
               c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' ||
               c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' ||
               c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' ||
               c == 'W' || c == 'X' || c == 'Y' || c == 'Z' || c == ' ') {
        goto q66;
    } else if (c == '/') {
        goto q68;
    } else return (_Rejeita_);

    q68:
    c = palavra[i];
    i++;
    if (c == ' ') {
        goto q0;
    } else if (c == '\0') {
        return (_Rejeita_);
    } else {
        i--;
        goto q0;
    }

    poco:
    return (_Rejeita_);

}

int main() {
    char palavra[20];
    strcpy(palavra, "_id = @2 ;");

    int res = scanner(palavra);

    if (res == 1) {
        printf("Palavra %s Aceita", palavra);
    }

    if (res == 0) {
        printf("Palavra %s Rejeitada", palavra);
    }

}