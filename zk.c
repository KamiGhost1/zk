#include "zk.h"


void opener(){
    printf("\n\t__    __      ______ \n");
    printf("\t| |  / /   / /______\\ \\   | | \\  / | |   | |\n");
    printf("\t| | / /    | |      | |   | |\\ \\/ /| |   | |\n");
    printf("\t| |/ /     | |      | |   | |  --  | |   | |\n");
    printf("\t| |\\ \\     | |      | |   | |      | |   | |\n");
    printf("\t| | \\ \\    | |      | |   | |      | |   | |\n");
    printf("\t| |  \\ \\   | |______| \\   | |      | |   | |\n");
    printf("\t| |   \\ \\  \\ \\______| \\\\  | |      | |   | |\n");
    printf("\n\nK@mi soft\ngithub.com:kamighost1\n\n");
}

int check_parameters(int c, char **v){
    if(c == 1){
        printf("its Zero Knowledge test programm. for more info use flag -h");
        opener();
        return 0;
    }
    if(c == 2){
        if(!strcmp(v[1], "-h")){
            printf("help menu\n");
            return 0;
        }
        if(!strcmp(v[1], "--rand")){
            for(int i = 0; i < 10; i ++){
                printf("%d\n",get_rand(0,1));
            }
            return 0;
        }
        if(!strcmp(v[1], "--nod")){
            printf("nod (36, 17) = %d\n",NOD(36,17));
            printf("nod (12, 6) = %d\n",NOD(12,6));
            printf("nod (1024, 511) = %d\n",NOD(1024,511));
            printf("nod (22751, 36387) = %d\n",NOD(22751, 36387));
            return 0;
        }
        if(!strcmp(v[1], "--start")){
            return 1;
        }
    }

    printf("unknow parameters...\nuse -h for help\n");
}

int start_zk(int c,char **v){
    int mode = check_parameters(c, v);
    if( mode == 0 )
        return 0;
    if( mode == 1 )
        zk();
    return -1;
}

int zk_mode(int num, int mod){
    if(num < 0){
        num = mod - (num*-1)%mod;
    }
    return num % mod;
}

int zk_pow(int base, int e){
    int num = 1;
    while( e != 0 ){
        if( e & 1 ){
            num *= base;
        }
        base *= base;
        e = e>>1;
    }
    return num;
}

int zk_pow_mode(int base, int e,  int mod){
    int num = 1;
    while( e != 0 ){
        if( e & 1 ){
            num = num * base % mod;
        }
        base = base * base % mod;
        e = e>>1;
    }
    return num;
}

void zk(){
    printf("i'm started!\n");
    int N = P * Q;
    int secretA = N;
    while(NOD(secretA,N) != 1){
        secretA = get_rand(1, N-1);
    }
    int r ,publicA, x, e, y , yroot, ysqrt;
    int VALID = 0;
    publicA = zk_pow_mode(secretA,2,N);
    #ifdef DEBUG_MAIN
    printf("secret A: %d\npublic A: %d\nN: %d\n", secretA, publicA, N);
    #endif
    for(int i = 0; i < CICLES_CHECK; i++){
        r = get_rand(1, N-1);
        x = zk_pow_mode(r, 2, N);
        e = get_rand(0,1);
        #ifdef CHECK_SECRET_VALID
        secretA-=1;
        #endif
        y = zk_pow_mode(r*secretA, e, N);
        yroot = zk_pow_mode(x*publicA, e, N);
        ysqrt = zk_pow_mode(y,2,N);

        #ifdef DEBUG_CICLE
        printf("i: %d;\ty==yroot ?  %s\tysqrt: %d\tyroot: %d\n", i+1, ysqrt==yroot ? "true" : "false", ysqrt, yroot);
                #ifdef DEBUG_ALL
                printf("\nr: %d\te: %d\tx: %d\n\n",r, e, x);
                #endif
        #endif
        if(yroot == ysqrt)
            VALID++;
    }
    if(VALID != CICLES_CHECK){
        printf("Not Valid. Access denied!\n");
    }else{
        printf("Valid. Access allowed!\n");
    }
    
}

int get_rand(const int min, const int max) {
    return rand() % (max - min + 1) + min;
}

int NOD(int a, int b){
    while(a > 0 && b > 0)

        if(a > b)
            a %= b;
        else
            b %= a;
 
    return a + b;
}
