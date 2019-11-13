#pragma once

#include "BTInit.h"

typedef BTNode CBTNode;

typedef BTTree CBTTree;

/*=======================================|| F U N C T I O N S ||=======================================*/

CBTNode CBTGetLast ( CBTTree );

void CBTRemove ( CBTTree , CBTNode );

void CBTInsertLast ( CBTTree , CBTItem );

/*=======================================|| E N D  O F  F I L E ||=======================================*/