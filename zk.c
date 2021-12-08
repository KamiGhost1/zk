#include "zk.h"
#define CICLES_CHECK 20

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
                printf("%d\n",get_rand(0,20));
            }
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

int zk_mode(int num, int mode){
    rand();
    return 0;
}

int zk_pow(int base, int e){
    return 0;
}

void zk(){
    printf("i'm started!\n");
    
}

int get_rand(const int min, const int max) {
    return rand() % (max - min + 1) + min;
}