#include "pato_lucas.h"
#include "font_macro.h"

/**********************
* Global variables
 ******************/

unsigned char pato_lucas[]=
{
________,________,________,______XX,________,________,________,________,
________,________,________,X___XXXX,XX______,________,________,________,
________,________,________,_X_X__X_,X_______,________,________,________,
________,________,________,_XX____X,________,________,________,________,
________,________,________,_X____XX,XX______,________,________,________,
________,________,________,_X______,XXX_____,________,________,________,
________,________,________,XX______,XX______,________,________,________,
________,________,________,X______X,________,________,________,________,
________,________,_______X,X_____XX,X_______,________,________,________,
________,________,______XX,________,XX______,________,________,________,
________,________,_____X__,________,__XX____,________,________,________,
________,________,____XX__,________,X__X____,________,________,________,
________,________,___XX__X,XX_____X,X___X___,________,________,________,
________,________,___X__X_,________,_X__XX__,________,________,________,
________,________,__XX____,________,__X__X__,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,________,________,________,
________,________,________,________,________,X_______,________,________,
________,________,________,________,________,X_______,________,________,
________,________,________,________,________,X_______,________,________,
________,_______X,________,________,________,X_______,________,________,
________,_______X,________,________,________,XX______,________,________,
________,_______X,________,________,________,XX______,________,________,
________,_______X,________,________,________,_X______,________,________,
________,______XX,________,________,________,_XX_____,________,________,
________,___XXXX_,________,________,________,__XX____,________,________,
________,__XXXXXX,________,________,________,XXXXXX__,________,________,
________,_XX____X,________,________,_______X,XX__XXX_,________,________,
________,X_______,________,________,________,______XX,________,________,
_______X,X_______,________,________,________,_______X,X_______,________,
_______X,___XX___,________,________,________,_______X,X_______,________,
______XX,________,________,________,________,___XX__X,X_______,________,
______X_,_____X__,________,________,________,_XX____X,X_______,________,
______XX,_____X__,________,________,________,_X_____X,________,________,
_______X,XXXXXX__,________,________,________,_X___XXX,________,________,
________,_____X__,________,________,________,XXXXXX__,________,________,
________,_____X__,________,________,________,XX______,________,________,
________,____X___,________,_____XXX,XXXXXXXX,XXXX____,________,________,
________,___XX___,________,_XXXXX__,________,__XXXXXX,________,________,
________,__XX____,________,________,________,_______X,XXX_____,________,
________,_XX_____,________,_______X,XXXXXXXX,XXX_____,__XXX___,________,
________,XX______,________,_XXXXXXX,XXX_XXXX,XXXXXXX_,____X___,________,
_______X,X_______,_____XXX,XXX_____,___XXX__,_____XXX,XX_XX___,________,
_______X,X_______,__XXXXX_,________,XXXX____,________,_XXX____,________,
________,XX_____X,XXXX__XX,XXXXXXXX,________,________,________,________,
________,_XXXXXXX,________,_X____X_,________,________,________,________,
________,___XX___,________,_X____X_,________,________,________,________,
________,________,________,_X____X_,________,________,________,________,
________,________,________,_XXXXXX_,________,________,________,________,
________,________,________,_X____X_,________,________,________,________,
________,________,_XXXX___,_X____X_,________,________,________,________,
________,_______X,XXX_XXXX,_X____XX,________,________,________,________,
________,______XX,_______X,XX_____X,________,________,________,________,
________,_____XX_,________,________,XXX_____,________,________,________,
________,________,________,________,__XXXXXX,________,________,________,
________,________,________,________,_______X,XX______,________,________,
________,________,________,________,________,__X_____,________,________,
};

unsigned char ojos_centro[] =
{
__X___XX,________,_____XX_,
__X__XXX,________,__X__XX_,
_XX_XXXX,X_______,XXXX__X_,
_X__XXXX,X_______,XXXXX_X_,
_X_XXXXX,X______X,XXXXX_XX,
_X_XXXXX,XX_____X,XXXXX_XX,
XX_XXXXX,XX____XX,XXXXXX_X,
XX_XXXXX,XX____XX,XXXXXX_X,
XXXXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX___XXX,XXXXXX__,
X_XXXXXX,XX___XXX,XXXXXXX_,
X_XXXXXX,XX___XXX,XXXXXXX_,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXX_,_X___XX_,XXXXXX__,
__XXXXX_,_X___X__,_XXXXX__,
__XXXXX_,_X___X__,_XXXXX__,
__XXXXX_,_X_XXX__,_XXXXX__,
X__XXXX_,XXX__XX_,XXXXX__X,
XX_XXXXX,X_____XX,XXXXXXX_,
_XXXXXXX,_____X_X,XXXXXX__,
__XXXXX_,_X______,_XXX____,
};

unsigned char ojos_izquierda[] =
{
__X___XX,________,_____XX_,
__X__XXX,________,__X__XX_,
_XX_XXXX,X_______,XXXX__X_,
_X__XXXX,X_______,XXXXX_X_,
_X_XXXXX,X______X,XXXXX_XX,
_X_XXXXX,XX_____X,XXXXX_XX,
XX_XXXXX,XX____XX,XXXXXX_X,
XX_XXXXX,XX____XX,XXXXXX_X,
XXXXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX___XXX,XXXXXX__,
X_XXXXXX,XX___XXX,XXXXXXX_,
X_XXXXXX,XX___XXX,XXXXXXX_,
__X__XXX,XX___XX_,XXXXXX__,
__X___XX,XX___X__,XXXXXX__,
__X___XX,XX___X__,_XXXXX__,
__X___XX,XX___X__,_XXXXX__,
__XX_XXX,XX_XXX__,XXXXXX__,
X__XXXXX,XXX__XX_,XXXXX__X,
XX_XXXXX,X_____XX,XXXXXXX_,
_XXXXXXX,_____X_X,XXXXXX__,
__XXXXX_,_X______,_XXX____,
};

unsigned char ojos_derecha[] =
{
__X___XX,________,_____XX_,
__X__XXX,________,__X__XX_,
_XX_XXXX,X_______,XXXX__X_,
_X__XXXX,X_______,XXXXX_X_,
_X_XXXXX,X______X,XXXXX_XX,
_X_XXXXX,XX_____X,XXXXX_XX,
XX_XXXXX,XX____XX,XXXXXX_X,
XX_XXXXX,XX____XX,XXXXXX_X,
XXXXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX___XXX,XXXXXX__,
X_XXXXXX,XX___XXX,XXXXXXX_,
X_XXXXXX,XX___XXX,XXXXXXX_,
__XXXXXX,_X___XXX,XXX_XX__,
__XXXXX_,_X___XXX,XXX__X__,
__XXXXX_,_X___XXX,XX___X__,
__XXXX__,_X___XXX,XX___X__,
__XXXX__,_X_XXXXX,XX___X__,
X__XXXX_,XXX__XXX,XXX_X__X,
XX_XXXXX,X_____XX,XXXXXXX_,
_XXXXXXX,_____X_X,XXXXXX__,
__XXXXX_,_X______,_XXX____,
};

unsigned char ojos_arriba[] =
{
__X___XX,________,_____XX_,
__X__XXX,________,__X__XX_,
_XX_XX_X,X_______,XXXX__X_,
_X__XX__,X_______,X__XX_X_,
_X_XXX__,X______X,X__XX_XX,
_X_XXX__,XX_____X,___XX_XX,
XX_XXXX_,_X____XX,__XXXX_X,
XX_XXXXX,XX____XX,XXXXXX_X,
XXXXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX___XXX,XXXXXX__,
X_XXXXXX,XX___XXX,XXXXXXX_,
X_XXXXXX,XX___XXX,XXXXXXX_,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXXX,XX_XXXXX,XXXXXX__,
X__XXXXX,XXX__XXX,XXXXX__X,
XX_XXXXX,X_____XX,XXXXXXX_,
_XXXXXXX,_____X_X,XXXXXX__,
__XXXXX_,_X______,_XXX____,
};

unsigned char ojos_abajo[] =
{
__X___XX,________,_____XX_,
__X__XXX,________,__X__XX_,
_XX_XXXX,X_______,XXXX__X_,
_X__XXXX,X_______,XXXXX_X_,
_X_XXXXX,X______X,XXXXX_XX,
_X_XXXXX,XX_____X,XXXXX_XX,
XX_XXXXX,XX____XX,XXXXXX_X,
XX_XXXXX,XX____XX,XXXXXX_X,
XXXXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX____XX,XXXXXX_X,
X_XXXXXX,XX___XXX,XXXXXX__,
X_XXXXXX,XX___XXX,XXXXXXX_,
X_XXXXXX,XX___XXX,XXXXXXX_,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXXXX,XX___XXX,XXXXXX__,
__XXXX_X,XX___XXX,XX_XXX__,
__XXX___,XX_XXXXX,X___XX__,
X__XX___,XXX__XXX,X___X__X,
XX_XX__X,X_____XX,X___XXX_,
_XXXX_XX,_____X_X,XX_XXX__,
__XXXXX_,_X______,_XXX____,
};