

typedef struct calc Calc;

Calc * calc_cria (char* f);
void calc_operador (Calc* c, float v);
void calc_operador (Calc* c, char op);
void calc_libera (Calc* c);


