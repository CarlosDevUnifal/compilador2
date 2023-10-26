//tabela de simbolos

#define TAM_TAB 100

struct elemTabSimbolos {
    char id[100]; //nome do indentificador
    int end;      //endereço
    int tip;      //tipo
} tabSimb[TAM_TAB], elemTab;

int posTab = 0;   //indica a proxima posicao livre para inserir

int buscaSimbolo(char *s) {
    int i;
    for (i = posTab -1; strcmp(tabSimb[i].id, s) && i >= 0; i-- )
    ;
    if (i == -1) {
        char msg[200];
        sprintf(msg, "Identificador [%s] nao encontrado!", s);
        yyerror(msg);
    }
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem) {
    int i;
    if (posTab == TAM_TAB) {
        yyerror("Tabela de simbolos cheia");
    }
    for (i = posTab -1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i-- )
    ;
    if (i != -1) {
        char msg[200];
        sprintf(msg, "Identificador [%s] duplicado!", elem.id);
        yyerror(msg);
    }
    tabSimb[posTab++] = elem;
}

//pilha semantica

#define TAM_PIL 100

int pilha[TAM_PIL];
int topo = -1;

void empilha (int valor) {
    if (topo == TAM_PIL)
        yyerror("Pilha semantica cheia");
    pilha[++topo] = valor;
}

int desempilha (void) {
    if (topo == -1)
        yyerror("Pilha semantica vazia");
    return pilha[topo--];
}