/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/****************************************************************************

   Copyright (C) 2010 William Hart

*****************************************************************************/

#include <mpir.h>
#include <mpfr.h>
#include "flint.h"
#include "mpfr_poly.h"

void mpfr_poly_randtest(mpfr_poly_t f, flint_rand_t state, ulong length)
{
   ulong i;
   mpfr_poly_fit_length(f, length);

   for (i = 0; i < length; i++)
      mpfr_urandomb(f->coeffs + i, state->gmp_state);
   
   _mpfr_poly_set_length(f, length);
}
