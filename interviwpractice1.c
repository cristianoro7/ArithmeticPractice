#include <stdio.h>
#include <malloc.h>
#include <etip.h>
#include <memory.h>

/**
 * 使用纯c对一段话进行词频统计
 */

typedef struct word_node {
    int word[20];
    int counts;
    struct word_node *next;
} word_node;

word_node *head = NULL;

word_node* find_word(word_node *node) {
    if (node != NULL) {
        word_node p = head;
        while (p) {
            if (strcmp(p.word))
        }
    } else {
        return NULL;
    }
}

void insert_node(word_node *node) {
    if (node != NULL) {
        if (head == NULL) {
            head = node;
        }
        word_node *p = head;
        while (p != NULL) {

        }
    }
}

void count_line(char *s) {
    if (s == NULL) {
        return;
    }

    int c = 0;
    int index = 0;
    int start_index = 0;
    int end_index = 0;

    while (s[index] != '\0') {
        if (s[index] >= 'A' && s[index] <= 'Z') { //大写转小写
            s[index] += 32;
        }

        if (s[index] >= 'a' && s[index] <= 'z') {
            end_index++;
        } else if (s[index] == ' ') {
            word_node *node = malloc(sizeof(word_node));
            if (node == NULL) {
                exit(0);
            }
            strncpy(node->word, s[start_index], end_index - start_index);
            node->next = NULL;
            node->counts = 0;


            start_index = end_index = index + 1;

        }
        index++;
    }
}

int main() {

    char temp[500];
    FILE *fd;
    if ((fd = fopen("123.txt", "r")) == NULL) {
        printf("file path error!");
        return 0;
    }

    while (EOF != (fscanf(fd, "%s", temp))) {
        count_line(temp);
    }
}