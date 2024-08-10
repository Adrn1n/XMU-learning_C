#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *DIR[4] = {"Up", "Down", "Left", "Right"};
int __board[4][4];
int __solid[4][4];
int __credit;
uint32_t __seed;
int __rand16() {
    __seed ^= (__seed << 13);
    __seed ^= (__seed >> 17);
    __seed ^= (__seed << 15);
    return __seed & 15;
}
int __up() {
    int succ = 0;
    memset(__solid, 0, sizeof(__solid));
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (__board[i][j] != 0) {
                for (int k = i - 1; k >= 0; --k) {
                    if (__board[k][j] == 0) {
                        succ = 1;
                        __board[k][j] = __board[k + 1][j];
                        __board[k + 1][j] = 0;
                    } else {
                        if (__board[k][j] == __board[k + 1][j] && !__solid[k][j]) {
                            succ = 1;
                            __board[k][j] <<= 1;
                            __board[k + 1][j] = 0;
                            __credit += __board[k][j];
                            __solid[k][j] = 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    return succ;
}
int __down() {
    int succ = 0;
    memset(__solid, 0, sizeof(__solid));
    for (int i = 2; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (__board[i][j] != 0) {
                for (int k = i + 1; k < 4; ++k) {
                    if (__board[k][j] == 0) {
                        succ = 1;
                        __board[k][j] = __board[k - 1][j];
                        __board[k - 1][j] = 0;
                    } else {
                        if (__board[k][j] == __board[k - 1][j] && !__solid[k][j]) {
                            succ = 1;
                            __board[k][j] <<= 1;
                            __board[k - 1][j] = 0;
                            __credit += __board[k][j];
                            __solid[k][j] = 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    return succ;
}
int __left() {
    int succ = 0;
    memset(__solid, 0, sizeof(__solid));
    for (int j = 1; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (__board[i][j] != 0) {
                for (int k = j - 1; k >= 0; --k) {
                    if (__board[i][k] == 0) {
                        succ = 1;
                        __board[i][k] = __board[i][k + 1];
                        __board[i][k + 1] = 0;
                    } else {
                        if (__board[i][k] == __board[i][k + 1] && !__solid[i][k]) {
                            succ = 1;
                            __board[i][k] <<= 1;
                            __board[i][k + 1] = 0;
                            __credit += __board[k][j];
                            __solid[i][k] = 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    return succ;
}
int __right() {
    int succ = 0;
    memset(__solid, 0, sizeof(__solid));
    for (int j = 2; j >= 0; --j) {
        for (int i = 0; i < 4; ++i) {
            if (__board[i][j] != 0) {
                for (int k = j + 1; k < 4; ++k) {
                    if (__board[i][k] == 0) {
                        succ = 1;
                        __board[i][k] = __board[i][k - 1];
                        __board[i][k - 1] = 0;
                    } else {
                        if (__board[i][k] == __board[i][k - 1] && !__solid[i][k]) {
                            succ = 1;
                            __board[i][k] <<= 1;
                            __board[i][k - 1] = 0;
                            __credit += __board[k][j];
                            __solid[i][k] = 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    return succ;
}
int __move(int d) {
    if (d == 0) {
        return __up();
    } else if (d == 1) {
        return __down();
    } else if (d == 2) {
        return __left();
    } else if (d == 3) {
        return __right();
    }
    abort();
}
void __gen() {
    int p, v;
    do {
        p = __rand16();
        v = __rand16();
    } while (__board[p / 4][p % 4] != 0);
    __board[p / 4][p % 4] = v < 2 ? 4 : 2;
}
int checklose() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (__board[i][j] == 0) {
                return 0;
            }
            if (i < 3 && __board[i][j] == __board[i + 1][j]) {
                return 0;
            }
            if (j < 3 && __board[i][j] == __board[i][j + 1]) {
                return 0;
            }
        }
    }
    return 1;
}
void printboard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (__board[i][j] == 0) {
                printf(".\t");
            } else {
                printf("%d\t", __board[i][j]);
            }
        }
        puts("");
    }
}
int decide(int (*board)[4]);
int main() {
    scanf("%d", &__seed);
    getchar();
    __gen();
    for (int i = 0; i < 100 && !checklose(); ++i) {
        int d = decide(__board);
#ifndef ONLINE_JUDGE
        printboard();
        printf("%s\n", DIR[d]);
        getchar();
#else
        printf("%d", d);
#endif
        if (__move(d)) {
            __gen();
        }
    }
#ifndef ONLINE_JUDGE
    printboard();
    printf("Credit: %d\n", __credit);
#else
    printf("\n");
#endif
    return 0;
}