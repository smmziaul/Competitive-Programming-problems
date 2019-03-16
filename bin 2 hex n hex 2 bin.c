#include<stdio.h>
#include<conio.h>
#include<string.h>

int find_str_len(char str[]) {
    int i=0;
    while(str[i]){
        i++;
    }
    return i;
}

void hex_to_bin(char str[]) {
    int len, i, invalid;
    len = find_str_len(str);
    for(i=0;i<len;i++) {
        switch(str[i]) {
            case '0': printf("0000\t"); break;
            case '1': printf("0001\t"); break;
            case '2': printf("0010\t"); break;
            case '3': printf("0011\t"); break;
            case '4': printf("0100\t"); break;
            case '5': printf("0101\t"); break;
            case '6': printf("0110\t"); break;
            case '7': printf("0101\t"); break;
            case '8': printf("1000\t"); break;
            case '9': printf("1001\t"); break;
            case 'A':
            case 'a': printf("1010\t"); break;
            case 'B':
            case 'b': printf("1011\t"); break;
            case 'C':
            case 'c': printf("1100\t"); break;
            case 'D':
            case 'd': printf("1101\t"); break;
            case 'E':
            case 'e': printf("1110\t"); break;
            case 'F':
            case 'f': printf("1111\t"); break;
            case 'g':
            case 'G':
            case 'h':
            case 'H':
            case 'z':
            case 'Z': invalid = 1;
            //default: printf("\nenter valid hex code"); break;
        }
    }
    if(invalid) {
        printf("\nSeems like, you've mistakenly entered invalid Hex Characters. So, we have eliminated all those invalids for you!");
    }
}

char* copy_four_chars(int i, char bin_no[]) {
    int rhl, j = 0;
    static char temp[4];
    rhl = (i*4)+4;
    while(i<rhl) {
        temp[j++] = bin_no[i++];
    }
    return temp;
}

void bin_to_hex(char bin_no[]) {
    int len, i;
    char *temp;
    len=find_str_len(bin_no);
    for(i=0;i<len;i+=4) {
        temp = copy_four_chars(i, bin_no);
        //printf("%s\t", temp);
        if(temp[0] == '0') { // 0xxx
            if(temp[1] == '0') { // 00xx
                if(temp[2] == '0') { // 000x
                    if(temp[3] == '0') { // 0000
                        printf("0\t");
                    } else { // 0001
                        printf("1\t");
                    }
                } else { // 001x
                    if(temp[3] == '0') { // 0010
                        printf("2\t");
                    } else { // 0011
                        printf("3\t");
                    }
                }
            } else { // 01xx
                if(temp[2] == '0' && temp[3] == '0') { // 0100
                    printf("4\t");
                } else if(temp[2] == '0' && temp[3] == '1') { // 0101
                    printf("5\t");
                } else if(temp[2] == '1' && temp[3] == '0') { // 0110
                    printf("6\t");
                } else if(temp[2] == '1' && temp[3] == '1') { // 0111
                    printf("7\t");
                }
            }
        } else { // 1xxx
            if(temp[1] == '0') { // 10xx
                if(temp[2] == '0') { // 100x
                    if(temp[3] == '0') { // 1000
                        printf("8\t");
                    } else { // 1001
                        printf("9\t");
                    }
                } else { // 101x
                    if(temp[3] == '0'){ // 1010
                        printf("A\t");
                    } else { // 1011
                        printf("B\t");
                    }
                }
            } else { // 11xx
                if(temp[2] == '0' && temp[3] == '0') { //1100
                    printf("C\t");
                } else if(temp[2] == '0' && temp[3] == '1') { // 1101
                    printf("D\t");
                } else if(temp[2] == '1' && temp[3] == '0'){ // 1110
                    printf("E\t");
                } else if(temp[2] == '1' && temp[3] == '1') { // 1111
                    printf("F\t");
                }
            }
        }
    }

}


int main() {
    char l, choice, bin_no[40], hex_no[10];
    int i, len, wanna_exit=0;
    printf("BINARY TO HEX AND HEX TO BINARY CONVERTER\n1. Binary to Hex\t2. Hex to Binary\t3. Exit from here\nEnter ur choice: ");
    scanf("%d", &choice);
    do {
        switch(choice) {
            case 1:
                printf("\nenter the binary no: ");
                scanf("%s", &bin_no);
                bin_to_hex(bin_no);
                break;
            case 2:
                printf("\nenter the hexadecimal no: ");
                scanf("%s", &hex_no);
                hex_to_bin(hex_no);
                break;
            case 3:
                wanna_exit = 1;
                break;
            default:
                printf("\nNo such option exists... Sorry..!");
                break;
        }
        if(!wanna_exit) {
            printf("\n\nBINARY TO HEX AND HEX TO BINARY CONVERTER\n1. Binary to Hex\t2. Hex to Binary\t3. Exit from here\nEnter ur choice: ");
            scanf("%d", &choice);
        }
    }while(choice == 2 || choice == 1);
    printf("\nYou have chosen to exit... Hit any key to exit...");
    getch();
    return 0;
}
