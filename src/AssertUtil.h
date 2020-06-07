#pragma once

#ifndef ASSERT
#include <assert.h>
#ifdef _DEBUG
#define ASSERT assert
#else
#define ASSERT
#endif
#endif

#ifndef RASSERT
#ifdef _DEBUG
#define RASSERT(x,r) { if(!(x)) return r; }
#define RASSERTV(x) { if(!(x)) return; }
#else
#define RASSERT(x,r) { if(!(x)) return r; }
#define RASSERTV(x) { if(!(x)) return; }
#endif
#endif

#ifndef BASSERT
#ifdef _DEBUG
#define BASSERT(x) { if(!(x)) break; }
#else
#define BASSERT(x) { if(!(x)) break; }
#endif
#endif

#ifndef CASSERT
#ifdef _DEBUG
#define CASSERT(x) { if(!(x)) continue; }
#else
#define CASSERT(x) { if(!(x)) continue; }
#endif
#endif

#ifndef EASSERT
#ifdef _DEBUG
#define EASSERT(x,r) { if(!(x)) { __asm { int 3 };return r; } }
#define EASSERTV(x) { if(!(x)) { assert(0);return; } }
#else
#define EASSERT(x,r) { if(!(x)) { __asm { int 3 };return r; } }
#define EASSERTV(x) { if(!(x)) { assert(0);return; } }
#endif
#endif

