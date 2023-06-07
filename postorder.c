#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// To create a new Node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//  To insert a new Node
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// To perform Post-order Traversal
void postOrderTraversal(struct Node* node, FILE* outputFile)
{
    if (node == NULL)
        return;

    postOrderTraversal(node->left, outputFile);
    postOrderTraversal(node->right, outputFile);
    fprintf(outputFile, "%d ", node->data);
}


int main() {

    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // To Read binary tree input from file
    struct Node* root = NULL;
    int data;
    while (fscanf(inputFile, "%d", &data) != EOF)
    {
        root = insert(root, data);
    }

    fclose(inputFile);


    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    fprintf(outputFile, "Post-order Traversal: ");
    postOrderTraversal(root, outputFile);
    fprintf(outputFile, "\n");

    fclose(outputFile);

    return 0;
}
