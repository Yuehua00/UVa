#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (){
    char stence[999] = {0};
    int first = 0;

    while (gets(stence)){
        for (int i = 0; i < strlen(stence); i++){
            if (first == 0 && stence[i] == '"'){
                printf ("``");
                first = 1;
            }else if (first == 1 && stence[i] == '"'){
                printf ("''");
                first = 0;
            }else{
                printf ("%c", stence[i]);
            }

        }
        printf ("\n");
    }
    return 0;
}
