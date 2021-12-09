#include <string.h>
#include <stdio.h>
#include <time.h>
#define CICLES_CHECK 20
#define P 311
#define Q 117
#define DEBUG_MAIN
#define DEBUG_CICLE
// #define DEBUG_ALL
// #define CHECK_SECRET_VALID

void opener();
void help_menu();
void info();
int check_parameters(int c, char **v);
int start_zk(int c,char **v);
int zk_mode(int num, int mod);
int zk_pow(int base, int e);
int zk_pow_mode(int base, int e, int mod);
int NOD(int a, int b);
void zk();
void sign(int private, int msg);
void generate_key();
int get_rand(const int min, const int max);