#ifndef NINROW_DEFINE_H
    #define NINROW_DEFINE_H
    #define N 4
    #define EMPTY ' '

    void print(const char [N][N]);
    void print_separator();
    void initiate(char [N][N]);
    void erase(char [N][N], char);
    void read_column(int *);
    void read_row(int *);
    int is_token(char [N][N], int, int, char);
    int is_empty(char [N][N], int, int);
    int victory(char [N][N], char);
    void set_token(char [N][N], char);
    void move_token(char [N][N], char);

#endif //NINROW_DEFINE_H
