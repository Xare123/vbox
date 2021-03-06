/*
 * Copyright 2002-2004 Red Hat Inc., Durham, North Carolina.
 *
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation on the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT.  IN NO EVENT SHALL RED HAT AND/OR THEIR SUPPLIERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Authors:
 *   Kevin E. Martin <kem@redhat.com>
 *
 */

/** \file
 * Header file for colormap support.  \see dmxcmap.c. */

#ifndef DMXCMAP_H
#define DMXCMAP_H

#include "colormapst.h"

/** Colormap private area. */
typedef struct _dmxColormapPriv {
    Colormap  cmap;
} dmxColormapPrivRec, *dmxColormapPrivPtr;


extern Bool dmxCreateColormap(ColormapPtr pColormap);
extern void dmxDestroyColormap(ColormapPtr pColormap);
extern void dmxInstallColormap(ColormapPtr pColormap);
extern void dmxStoreColors(ColormapPtr pColormap, int ndef, xColorItem *pdef);

extern Bool dmxCreateDefColormap(ScreenPtr pScreen);

extern Bool dmxBECreateColormap(ColormapPtr pColormap);
extern Bool dmxBEFreeColormap(ColormapPtr pColormap);

/** Private index.  \see dmxcmap.c \see dmxscrinit.c \see dmxwindow.c */
extern DevPrivateKey dmxColormapPrivateKey;

/** Set colormap private structure. */
#define DMX_SET_COLORMAP_PRIV(_pCMap, _pCMapPriv)			\
    dixSetPrivate(&(_pCMap)->devPrivates, dmxColormapPrivateKey, _pCMapPriv)

/** Get colormap private structure. */
#define DMX_GET_COLORMAP_PRIV(_pCMap) (dmxColormapPrivPtr)		\
    dixLookupPrivate(&(_pCMap)->devPrivates, dmxColormapPrivateKey)

#endif /* DMXCMAP_H */
