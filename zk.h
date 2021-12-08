#include <string.h>
#include <stdio.h>
#include <time.h>

void opener();
int check_parameters(int c, char **v);
int start_zk(int c,char **v);
int zk_mode(int num, int mode);
int zk_pow(int base, int e);
void zk();
int get_rand(const int min, const int max);