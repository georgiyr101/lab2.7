#pragma once

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>


int getIntNumber();

BinaryTree* createBinaryTree(int data);

void showBinaryTree(BinaryTree* tree, int level);

void insertNode(BinaryTree* tree, int data);

int findNode(BinaryTree* tree, int data);

BinaryTree* deleteNode(BinaryTree* tree, int data);

void deleteNodesByUserInput(BinaryTree* tree);

int isMirror(BinaryTree* tree1, BinaryTree* tree2);

int isSymmetric(BinaryTree* tree);
