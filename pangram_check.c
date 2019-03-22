// checks whether the user-entered-string is pangram or not.
// pangram: a sentence which contains every letter of the alphabets in the language.

#include<stdio.h>
#include<string.h>

int find_str_len(char str[]) {
    int i=0;
    while(str[i++]) {
    }
    return i-1;
}

typedef struct {
    int is_set;
    char name_of_char;
}alphabet;

int main() {
    char name_arr[100], *name, ch, *ch1;
    alphabet alphabet[50];
    int i, j, alphabet_count, len_of_str;
    printf("enter the no of alphabets supported in ur language: ");
    scanf("%d", &alphabet_count);
    for(i=0;i<alphabet_count;i++) {
        printf("\nenter the alphabet %d: ", i+1);
        ch = getch();
        ch1 = strlwr(&ch);
        alphabet[i].name_of_char = *ch1;
        alphabet[i].is_set = 0;
    }
    getchar(); // DEADLY DANGEROUS: to consume the extra newline char by getch() in input buffer
    printf("\n\nthe alphabets in the language are: \n");
    for(i=0;i<alphabet_count;i++) {
        printf("%c\t", alphabet[i].name_of_char, alphabet[i].is_set);
    }
    printf("\nenter your string: ");
    fgets(name_arr, sizeof name_arr, stdin);
    len_of_str = (find_str_len(name_arr)-1);
    printf("len of string: %d", len_of_str);
    name = strlwr(name_arr);
    if(len_of_str >= alphabet_count) {
        for(i=0;i<len_of_str;i++) {
            for(j=0;j<alphabet_count;j++) {
                if(name[i] == alphabet[j].name_of_char) {
                    if(alphabet[j].is_set==0){
                        alphabet[j].is_set++;
                    }
                }
            }
        }
        i=0;
        while(i<alphabet_count && alphabet[i++].is_set) {
        }
        if(i == alphabet_count) {
            printf("\nall alphabets are included in ur string...\n");
        } else {
            printf("\nsome of the alphabets are missing...\n");
        }
    } else {
        printf("\nsome of the alphabets are missing...\n");
    }
    return 0;
}
