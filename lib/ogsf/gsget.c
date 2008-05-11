/*!
  \file gsd_get.c
 
  \brief OGSF library - 
 
  GRASS OpenGL gsurf OGSF Library 

  (C) 1999-2008 by the GRASS Development Team
 
  This program is free software under the 
  GNU General Public License (>=v2). 
  Read the file COPYING that comes with GRASS
  for details.
  
  \author Bill Brown USACERL (January 1993)
*/

#include <grass/gstypes.h>

int get_mapatt(typbuff * buff, int offset, float *att)
{
    if (buff->nm) {
	if (BM_get
	    (buff->nm, (offset % buff->nm->cols),
	     (offset / buff->nm->cols))) {
	    return (0);
	}
    }

    *att = (buff->ib ? (float) buff->ib[offset] :
	    buff->sb ? (float) buff->sb[offset] :
	    buff->cb ? (float) buff->cb[offset] :
	    buff->fb ? (float) buff->fb[offset] : buff->k);

    if (buff->tfunc) {
	*att = (buff->tfunc) (*att, offset);
    }

    return (1);
}
