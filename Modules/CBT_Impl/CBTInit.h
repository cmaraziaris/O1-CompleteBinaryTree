#pragma once
#include "BTInit.h"
typedef BTNode CBTNode;
typedef BTTree CBTTree;

void CBTInsertLast(CBTTree,CBTItem);
CBTNode CBTGetLast(CBTTree);
void CBTRemove (CBTTree,CBTNode);