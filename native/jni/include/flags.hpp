#pragma once

/* Include this header anywhere accessing JOKER_DEBUG, JOKER_VERSION, JOKER_VER_CODE.
 *
 * This file is for precise incremental builds. We can make sure code that uses
 * external flags are re-compiled by updating the timestamp of this file
 * */

#define quote(s) #s
#define str(s) quote(s)

#define JOKER_VERSION  str(__MVSTR)
#define JOKER_VER_CODE __MCODE
#define JOKER_FULL_VER JOKER_VERSION "(" str(JOKER_VER_CODE) ")"

#define NAME_WITH_VER(name) str(name) " " JOKER_FULL_VER

#ifdef __MDBG
#define JOKER_DEBUG
#endif
