/*
 * vim: ts=4 sw=4 et tw=0 wm=0
 *
 * libvpsc - A solver for the problem of Variable Placement with 
 *           Separation Constraints.
 *
 * Copyright (C) 2005-2008  Monash University
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library in the file LICENSE; if not, 
 * write to the Free Software Foundation, Inc., 59 Temple Place, 
 * Suite 330, Boston, MA  02111-1307  USA
 *
*/

#ifndef __ISNAN_H__
#define __ISNAN_H__

/*
 * Temporary fix for various misdefinitions of isnan().
 * isnan() is becoming undef'd in some .h files. 
 * #include this last in your .cpp file to get it right.
 *
 * The problem is that isnan and isfinite are part of C99 but aren't part of
 * the C++ standard (which predates C99).
 *
 * Authors:
 *   Inkscape groupies and obsessive-compulsives
 *
 * Copyright (C) 2004 authors
 *
 * Released under GNU LGPL, read the file 'LICENSE' for more information
 *
 * 2005 modification hereby placed in public domain.  Probably supercedes 
 * the 2004 copyright for the code itself.
 */

#include <math.h>
/* You might try changing the above to <cmath> if you have problems.
 * Whether you use math.h or cmath, you may need to edit the .cpp file
 * and/or other .h files to use the same header file.
 */

#if defined(__isnan)
# define isNaN(_a) (__isnan(_a))	/* MacOSX/Darwin definition < 10.4 */
#elif defined(WIN32) || defined(_isnan)
# define isNaN(_a) (_isnan(_a)) 	/* Win32 definition */
#elif defined(isnan) || defined(__FreeBSD__)
# define isNaN(_a) (isnan(_a))		/* GNU definition */
#else
# define isNaN(_a) (std::isnan(_a))
#endif
/* If the above doesn't work, then try (a != a).
 * Also, please report a bug as per http://www.inkscape.org/report_bugs.php,
 * giving information about what platform and compiler version you're using.
 */


#if defined(__isfinite)
# define isFinite(_a) (__isfinite(_a))	/* MacOSX/Darwin definition < 10.4 */
#elif defined(isfinite)
# define isFinite(_a) (isfinite(_a))
#else
# define isFinite(_a) (std::isfinite(_a))
#endif
/* If the above doesn't work, then try (finite(_a) && !isNaN(_a)) or (!isNaN((_a) - (_a))).
 * Also, please report a bug as per http://www.inkscape.org/report_bugs.php,
 * giving information about what platform and compiler version you're using.
 */


#endif /* __ISNAN_H__ */
