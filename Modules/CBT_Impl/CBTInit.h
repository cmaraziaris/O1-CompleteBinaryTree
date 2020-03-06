#pragma once

#include "BTInit.h"

typedef BTNode CBTNode;

typedef BTree CBTree;

/*=======================================|| F U N C T I O N S ||=======================================*/

CBTNode CBTGetLast ( CBTree );

void CBTRemove ( CBTree , CBTNode );

void CBTInsertLast ( CBTree , CBTItem );

/*=======================================|| E N D  O F  F I L E ||=======================================*/