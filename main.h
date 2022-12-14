#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char * const format, ...);
void print_number(int n);
void print_string(char *str);
void pause_program(void);
int absolute(int n);
void print_base(int b, int n);
void print_hex(int num, char v);
void print_str(char *str);
void print_pointer(int n);
void checks_state(char d, int c);
void check_positivity(int m, char c);
int is_flag(char k);
void print_flag(int n, char c);
int is_conversion_specifier(char c);
int format_specifier_elements_number(const char* const p, int i);
void check_specifier(char c);
void print_char_int(const char * const p, int *i, int n, int x);
void print_strin(const char * const p, int *i, char *s_s, int x);
void print_as_it_is(const char * const p, int *i, int x);
int get_conversion_type(char c);

#endif
