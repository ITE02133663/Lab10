#include<stdio.h>
#include<stdlib.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<time.h>

void doprocessing(int sock) {
    int n, read_size, i = 0, j = 0;

    char buffer[256], *a, *answer, num_str[4];


    unsigned seed;
    seed = (unsigned) time(NULL);
    srand(seed);
    int ran_num[4] = {rand() % 10, rand() % 10, rand() % 10, rand() % 10};
    for (i = 0; i < 4; i++) {
        while (j < 4) {
            if (i == j)
                j = j + 1;
            else {
                if (ran_num[i] == ran_num[j]) {
                    ran_num[i] = rand() % 10;
                    j = 0;
                } else
                    j = j + 1;
            }
        }
        j = 0;
    }


    for (i = 0; i < 4; i++) {
        printf("%d", ran_num[i]);
    }
    printf("\n");

    //Reply to the client
    while (1) {

        bzero(buffer, 256);
        n = read(sock, buffer, 255);
        printf("%s", buffer);
        if (n < 0) {
            perror("error reading from socket");
            exit(1);
        }

        int A = 0, B = 0;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (ran_num[i] + 48 == buffer[j]) {
                    if (i == j) {
                        A = A + 1;
                    } else {
                        B = B + 1;
                    }
                }
            }
        }
        if (A == 4) {
            answer = "YOUR ANSWER IS  RIGHT!!!!!!!!!!!!!";
            n = write(sock, answer, strlen(answer));
            exit(1);
        } else {
            char *reply;
            if (A == 0 && B == 0)
                reply = "0A0B";
            else if (A == 0 && B == 1)
                reply = "0A1B";
            else if (A == 0 && B == 2)
                reply = "0A2B";
            else if (A == 0 && B == 3)
                reply = "0A3B";
            else if (A == 0 && B == 4)
                reply = "0A4B";
            else if (A == 1 && B == 0)
                reply = "1A0B";
            else if (A == 1 && B == 1)
                reply = "1A1B";
            else if (A == 1 && B == 2)
                reply = "1A2B";
            else if (A == 1 && B == 3)
                reply = "1A3B";
            else if (A == 2 && B == 0)
                reply = "2A0B";
            else if (A == 2 && B == 1)
                reply = "2A1B";
            else if (A == 2 && B == 2)
                reply = "2A2B";
            else if (A == 3 && B == 0)
                reply = "3A0B";
            n = write(sock, reply, strlen(reply));
            puts(reply);
        }

        if (n < 0) {
            perror("error writingto socket");
        }

    }


}
