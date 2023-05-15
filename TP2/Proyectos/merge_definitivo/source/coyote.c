#include "coyote.h"
#include "font_macro.h"

/**********************
* Global variables
 ******************/

unsigned char coyote_cayendo[]=
{
    _______X,X_______,________,________,________,_X____XX,__XXX___,________,
    _______X,X_______,________,________,________,_X____X_,_XXXX___,________,
    ________,XX______,________,________,________,X____XX_,_XXX____,________,
    ________,_X______,________,________,________,X____XXX,XXXXXXXX,XXXXXXXX,
    ________,_XX_____,________,________,________,X___X___,________,_______X,
    _______X,__X_____,________,________,_______X,X___X__X,XX__X___,X_XXX__X,
    _______X,___X____,________,________,_______X,____X__X,__X__X_X,__X____X,
    ______XX,___XX___,________,________,_______X,____X__X,__X__X_X,__X____X,
    ______XX,____X___,________,________,_______X,____X__X,XX____X_,__XXX__X,
    _______X,X____X__,________,________,________,____X__X,__X___X_,__X____X,
    _______X,X____X__,________,________,______X_,____X__X,__X___X_,__X____X,
    _______X,X_____X_,________,________,___X__X_,____X__X,XX____X_,__XXX__X,
    ________,X______X,________,________,___X__X_,____X___,________,_______X,
    ________,________,________,________,__XX__X_,____XXXX,XXXXXXXX,XXXXXXXX,
    ________,________,X_______,________,_XXX_X__,____X___,____X___,_______X,
    _______X,________,________,_______X,XXXX_X__,___X____,____X___,________,
    ____X__X,________,_X_XXXX_,_______X,XXXX_X__,___X____,____X___,________,
    ____X__X,X_______,XXXXXXXX,X_____XX,XXX_____,__X_____,_XXXXX__,________,
    __X____X,XX______,__XXXXXX,XXXXXXXX,X___X___,__X_____,XXXXXXXX,X_______,
    ___X___X,XX______,___X_XXX,XXXXXXX_,____X___,__X_____,XXXXXXXX,________,
    ____X___,XXX_____,________,XXXXXXXX,__XXX___,_X______,_XXXXXX_,________,
    _____XX_,XXX_____,______XX,_XXXXXXX,X__X___X,XXXXXX__,XXXXXXX_,________,
    _______X,XXXX___X,XXXX_XXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXX__,________,
    __XXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXX___,________,________,
    __XXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXXX,XXXXXXX_,________,________,________,
    _XXX_XXX,XXXXXX__,_____XXX,XXXXXXXX,XXX_____,________,________,________,
    ____XXXX,XX___X__,_______X,XXXXXXXX,XXX_____,________,________,________,
    ___XXXXX,X_____X_,________,XXXXXXXX,XXX_____,________,________,________,
    __XXX_XX,______XX,_______X,XXXXXXXX,XXX_____,________,________,________,
    ___X__XX,_______X,X______X,XXXXXXXX,XXX_____,________,________,________,
    ______X_,________,_XX_____,XXXXXXXX,XXX_____,________,________,________,
    ________,________,___XX___,XXXXXXXX,XXX_____,________,________,________,
    ________,________,____XX__,_XXXXXXX,XXX_____,________,________,________,
    ________,________,______X_,_XXXXXXX,XXX_____,________,________,________,
    ________,________,_______X,_XXXXXXX,XX______,________,________,________,
    ________,________,________,XXXXXXXX,XX______,________,________,________,
    ________,________,________,_XXXXXXX,XX______,________,________,________,
    ________,________,________,_XXXXXXX,XX______,________,________,________,
    ________,________,________,_XXXXXXX,XXX_____,________,_____XXX,XX______,
    ________,________,________,XXXXXXXX,XXXX____,________,___XXXXX,X_______,
    ________,________,______XX,XXXXX___,XXXXXXXX,XXXX____,__XXXXXX,XX______,
    ________,________,___XXXXX,XXXX____,_XXXXXXX,XXXX____,__XXXXXX,XX______,
    ________,________,_XXXXXXX,X_______,________,XXXXX___,__XXXX__,________,
    ___XXXXX,________,XXXXXX__,________,________,___XXX__,_XXXX___,________,
    _XXXXXXX,X_______,XXX_____,________,________,____XXXX,XXXX____,________,
    _XXXXXXX,X______X,XX______,________,________,XXX____X,XXXX____,________,
    _XXXXXXX,XX____XX,________,________,________,_XXXX___,XXX_____,________,
    _XXXXXXX,XX___XX_,________,________,________,__XXXXX_,_X______,________,
    ________,XXX__X__,________,________,________,____XXXX,X_______,________,
    ________,_XXXX___,________,X_______,________,______XX,XXX_____,________,
    ________,__XX____,_______X,________,________,________,XXXXX___,________,
    ________,________,_______X,________,__X_____,________,__XXXXXX,________,
    ________,________,______X_,________,___X____,________,____XXXX,XX______,
    ________,________,_____XX_,________,____X___,________,______XX,XXXX____,
    ________,________,_____XX_,________,____X___,________,________,XXXXXXX_,
    ________,________,____XX__,________,_____X__,________,________,__XXXXXX,
    ________,________,____XX__,________,_____XX_,________,________,___XXXXX,
    ________,________,___XX___,________,______X_,________,________,_____XXX,
    ________,________,___XX___,________,_______X,________,________,_______X,
    ________,________,__XXX___,________,_______X,X_______,________,________,
    ________,________,__XX____,________,________,X_______,________,________,
    ________,________,_XXX____,________,________,XX______,________,________,
    ________,________,XXX_____,________,________,_XX_____,________,________,
    ________,________,XXX_____,________,________,__X_____,________,________,
};

unsigned char coyote_golpeado[] =
{
    ________,________,________,____X___,________,________,________,________,
    ________,________,________,____X___,__XX____,________,_X______,________,
    ________,________,________,__XX_XX_,_X__X___,________,_X______,________,
    ________,________,________,___XXX__,_X__X___,______XX,X_XXX___,________,
    ________,________,________,___X_X__,X___X___,_______X,___X____,________,
    ________,________,___X____,________,XX__X___,________,X_X_____,________,
    ________,________,___XX___,________,X__X_X__,_______X,XXXX____,________,
    ________,________,___XX___,________,X____X__,_______X,___X____,________,
    ________,________,XXX__XXX,_______X,__X__X__,________,________,________,
    ________,________,_X____X_,_______X,_____X__,________,________,________,
    ________,________,__X__X__,_______X,____X___,________,________,________,
    ________,________,_X_XX_X_,______X_,X___X___,________,________,________,
    ________,________,_XX__XX_,______X_,__X_X___,________,________,________,
    ________,________,______X_,______X_,X__X____,________,________,________,
    ________,________,________,_____X__,___X____,________,________,________,
    ________,________,________,_____X_X,___X____,________,________,________,
    ________,________,________,_____X__,_X_X____,________,________,________,
    ________,________,________,___XXXXX,X__X____,________,________,________,
    ________,________,________,___XXXXX,XXX_X___,________,________,________,
    ________,______XX,XXXXXX__,__XXXXXX,XXXX_X__,________,________,________,
    ________,____XXXX,XXXXXXXX,XXXXXXXX,XXXXXX__,________,________,________,
    ________,__XXXXXX,XXXXXXXX,XXXXXXXX,XXXXXX__,________,________,________,
    ________,_XXXXXX_,_____XXX,XXXXXXXX,XXXXXXX_,_____XXX,XXX_____,________,
    ________,XXXX____,______XX,XXXX__XX,XXXXXXXX,XXXXXXXX,XXXX____,________,
    _______X,XX______,_______X,XXX_XX_X,__XXXXXX,XXXXXXXX,XXXXX___,________,
    ______XX,X_______,________,XX_XXXXX,XX_XXXXX,XXXXXXXX,__XXXX__,________,
    _____XXX,________,________,XXXXXX_X,XXX_XXXX,XX______,___XXX__,________,
    _____XX_,_____XXX,XX_____X,X_XXXXX_,XXXXXXXX,________,____XXX_,________,
    ____XX__,__XXX___,__XX___X,XXXXXXX_,XXXX_XXX,________,______XX,________,
    ___X____,XX______,____X_XX,_XXXXXXX,XXXXX_XX,X_______,_______X,X_______,
    __X____X,________,_____XX_,XX_____X,XXXXXX_X,X_______,_X______,XX______,
    _X_XXXX_,________,______XX,X______X,___XXXXX,X____XXX,X_XXX___,_XX_____,
    _X______,________,_____XXX,X_______,XX__XX_X,XX__X___,_____X__,_XX_____,
    ________,________,____XXXX,X____XX_,XX___XXX,XXXX____,______X_,_X______,
    ________,________,___XXXXX,X____XX_,_____XXX,XXXXXXXX,XX_____X,_X______,
    ________,________,_XXXXXXX,X______X,_____XX_,________,__XX___X,X_______,
    ________,______XX,X____XXX,XX____XX,XXXXXX_X,X_______,____X__X,________,
    ________,____XX__,___XXXXX,XXXXXXXX,XXXXX___,_XX_____,_____X__,________,
    ________,___X____,__X_____,__XXXX_X,__X_____,________,_____X__,________,
    ________,__X_____,________,_X______,___XX__X,XXX_____,_____X__,________,
    ________,_X______,_______X,X_XXX_XX,XX_____X,__X_____,_____X__,________,
    ________,X_______,______X_,_____X__,__X____X,________,_____X__,________,
    ________,X_______,_____X__,___XX___,____X_X_,________,____X___,________,
    ________,X_______,_____X__,_______X,XXX_____,________,__XX____,________,
    _______X,________,____X__X,_____XX_,___X___X,_______X,XXXX____,________,
    _______X,________,___X____,XXXX____,____X_X_,XXXXXXXX,X_______,________,
    _______X,________,________,X__X____,_____X_X,________,________,________,
    ______XX,X_______,________,_X_X__XX,X____X__,________,________,________,
    ________,XX______,___XXXXX,_XX__XXX,XX___X__,________,________,________,
    ________,_X______,_XX____X,_XX__XX_,XXX__X__,________,________,________,
    ________,_XXXXX_X,X______X,__X__X_X,XXX__X__,________,________,________,
    ________,__XXX_X_,________,X__XXXXX,XXX_X___,________,________,________,
    ________,________,________,_X__XXXX,XXXX____,________,________,________,
    ________,________,________,__XXXXXX,XXX_____,________,________,________,
    ________,________,________,____XXXX,XXX_____,________,________,________,
    ________,________,________,____XXXX,XX______,________,________,________,
    ________,________,________,____X_XX,X_______,________,________,________,
    ________,________,________,____X___,X_______,________,________,________,
    ________,________,________,___X____,X_______,________,________,________,
    ________,________,________,___X___X,________,________,________,________,
    ________,________,________,___X___X,________,________,________,________,
    ________,________,________,__XX___X,________,________,________,________,
    ________,________,________,XXX____X,________,________,________,________,
    ________,________,_______X,XXX___XX,X_______,________,________,________,
};

unsigned char coyote_durmiendo[] =
{
    ___XXX__,________,________,________,________,________,________,________,________,________,________,________,
    _XXXXXX_,________,________,________,________,________,________,________,________,________,________,________,
    _XXXXXX_,________,________,________,________,________,________,________,________,________,________,________,
    _XXXXXXX,________,________,________,________,________,________,________,________,________,________,________,
    _XXXXXX_,________,________,________,________,________,________,________,________,________,________,________,
    __XXXXX_,________,________,________,________,________,________,________,________,________,________,________,
    __XXXXXX,________,___XXX__,________,________,________,________,________,________,________,________,________,
    XXXXXXXX,________,___XXXX_,________,________,________,________,________,________,________,________,________,
    XXXXXX__,________,___XXXX_,________,________,________,________,________,________,________,________,________,
    ___XXX__,________,___XXXX_,________,________,________,________,________,________,________,________,________,
    ___XXX__,________,__XXXX__,________,________,________,________,________,________,________,________,________,
    ___XXXX_,________,__XXXX__,________,________,________,________,________,________,________,________,________,
    ___XXXX_,________,___X____,________,________,________,________,________,________,________,________,________,
    ___XXXX_,________,__XX____,________,________,________,________,________,________,________,________,________,
    ___XXXXX,________,__XX____,________,________,________,________,________,________,________,________,________,
    ___XXXXX,XX______,__XX____,________,________,________,________,________,________,________,________,________,
    ____XXXX,XXXX____,__XX____,________,________,________,________,________,________,________,________,________,
    ____XXX_,_X_XXXX_,__XX____,________,________,________,________,________,________,________,________,________,
    ____XXX_,_X__X_XX,XXXX____,________,________,________,________,________,________,________,________,________,
    ____XXX_,_X__X__X,_XXX____,________,________,________,________,________,________,________,________,________,
    ____XXX_,_X__XX_X,__XX____,________,________,________,________,________,________,________,________,________,
    ____XXX_,_X__X_XX,XXXXXXX_,________,________,________,________,________,________,________,_______X,XX______,
    ____XXX_,_XX_XXXX,XXXXXXXX,XXXXXX__,________,________,________,________,________,______XX,______XX,XXX_____,
    ____XXX_,_XXXX___,__X____X,XXX___XX,________,________,________,________,________,_____XXX,X_____XX,XXX_____,
    ____XXX_,_XX_____,XXXX____,XX___X_X,X_______,________,________,________,________,_____XXX,X_____XX,XXX_____,
    ____XXX_,_XXXXXXX,X__XXXXX,XX_XX___,XX______,____XX__,________,________,________,_____XXX,X______X,XX______,
    ____XXX_,_X_XXXXX,X_XXXXXX,XX_X____,X_______,_XXX__XX,X_______,________,________,_______X,________,X_______,
    ____XXX_,XXXXXXXX,__XXXXXX,X____XXX,X_______,X_______,_XX_____,________,________,______XX,_______X,X_______,
    ____XXXX,XXXXXX_X,_XXXXXX_,____XXXX,XX______,X_______,___X____,________,________,______XX,_______X,X_______,
    ____X___,_____XXX,X_XXXX__,XXX_XXX_,XX_____X,________,___XX___,________,________,______XX,_______X,________,
    _____X__,____XX__,XXXXXX_X,XXX_XXX_,_X_____X,________,____X___,________,________,______X_,______XX,________,
    _____XX_,____X__X,XXXXX__X,XX__XXX_,_X____X_,________,____X___,________,________,______XX,XXXXXXXX,________,
    _____XX_,______XX,XX_XX__X,X__XXXX_,__XXXX__,________,_____X__,________,________,_____XXX,XXXXXXX_,________,
    _____XX_,______XX,__XXXX__,___XXX__,________,____X__X,_____X__,________,________,_____XXX,_X_X_XX_,________,
    _____XXX,______X_,_XXX_XX_,_XXXXX__,_____X__,_____XX_,____X___,________,________,_____X_X,_X_X_XX_,________,
    _____XXX,________,______XX,XXXXXX__,_____X__,___XX___,_____X__,________,________,_____X_X,_X_X_XX_,________,
    ______XX,________,_______X,XXXXXX__,_____X__,___X____,____XXX_,________,________,_____X_X,XX_XXX__,________,
    ______XX,________,________,XXXXXX__,__X__X__,__X_____,____X_X_,________,________,_____X_X,_XX_XX__,________,
    ______XX,________,________,_XXXXX__,__X__X__,_X______,___X__XX,________,________,_____X_X,X_XXXX__,________,
    ______XX,________,________,_XXXXX__,__X__X__,_X______,__X___X_,X_______,________,_____X_X,XX_XX___,________,
    ______XX,XX______,________,___XXX__,_X__X___,X_______,_X____X_,_X______,________,_____X_X,_X_XX___,________,
    ______XX,__X_____,________,____XX__,_X__X__X,_______X,X______X,__XXXX_X,X_XXXXXX,XXXXXX_X,_X_XX___,________,
    ______XX,_X_XXXXX,________,________,_X__X__X,_____XX_,________,___X__X_,_X______,___XXXXX,X__X____,________,
    ______XX,X______X,XXXXXXX_,___XX___,_X____X_,_____X_X,X____X__,____XXXX,________,_____X_X,X_XX____,________,
    ______XX,________,_______X,XXX_____,__X__X__,_______X,_X______,_______X,XXXXXXX_,______XX,__XX____,________,
    ______XX,X_______,________,_X______,__XX_X__,________,__XXX___,________,__X_____,X_____XX,__X_____,________,
    _______X,XX______,________,_X______,__XX____,________,__X__X__,________,____X___,X____XXX,_XX_____,________,
    _______X,_XX_____,________,_X______,__X_____,________,__X__X__,________,_____XX_,X____XXX,_XX_____,________,
    _______X,__XXXX__,________,_X______,__XX____,________,___X_X__,________,______X_,X____XXX,_XX_____,________,
    _______X,XXXXXXXX,XXXXXXXX,XX______,__XX____,________,___X____,________,______X_,X____XXX,_X______,________,
    _______X,XXXXXXXX,XXXXXXXX,XX______,___X____,________,___X____,________,______X_,X____XXX,XX______,________,
    _______X,________,____XXXX,XX______,_X_X____,________,___X____,________,______X_,X____XXX,XX______,________,
    _______X,________,________,__XXXXX_,_X______,________,___X____,________,______X_,X____XXX,X_______,________,
    _______X,________,________,_______X,XXXXXXXX,XXXXX___,________,________,______XX,X____X_X,X_______,________,
    _______X,________,________,________,________,_____XXX,X_XXXX__,________,XXXX__X_,X___X__X,X_______,________,
    _______X,________,________,________,________,________,_X____X_,____XXXX,_____XX_,XXXXX__X,X_______,________,
    _______X,________,________,________,________,________,_______X,XXXX____,________,__X____X,________,________,
    ______XX,________,________,________,________,________,________,________,________,_XXX___X,________,________,
    ______XX,________,________,________,________,________,________,________,________,XXXX___X,________,________,
    _____XXX,X_______,________,________,________,________,________,________,________,_XXX__XX,________,________,
    _____XXX,________,________,________,________,________,________,________,________,_____XXX,X_______,________,
    ________,________,________,________,________,________,________,________,________,_____XXX,X_______,________,
    ________,________,________,________,________,________,________,________,________,______XX,________,________,
    ________,________,________,________,________,________,________,________,________,________,________,________,
};
