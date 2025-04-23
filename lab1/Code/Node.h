//
// Created by 冯子毅 on 3/21/25.
//

#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char *name;
    struct Node *child, *brother;
    union {
        int lineno;
        int intVal;
        float floatVal;
        char *strVal;
    };
} Node;

#endif //NODE_H
