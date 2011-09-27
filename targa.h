/******************************************************************************
*                                                                             *
*                                Targa library                                *
*                                                                             *
*                                  targa.h                                    *
*                                                                             *
*                                   Header                                    *
*                                                                             *
*                    Copyright (C) 1994 Ulrik Hørlyk Hjort                    *
*                                                                             *
*   Targa library is free software;  you can  redistribute it                 *
*   and/or modify it under terms of the  GNU General Public License           *
*   as published  by the Free Software  Foundation;  either version 2,        *
*   or (at your option) any later version.                                    *
*   Targa library is distributed in the hope that it will be                  *
*   useful, but WITHOUT ANY WARRANTY;  without even the  implied warranty     *
*   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                   *
*   See the GNU General Public License for  more details.                     *
*   You should have  received  a copy of the GNU General                      *
*   Public License  distributed with Yolk.  If not, write  to  the  Free      *
*   Software Foundation,  51  Franklin  Street,  Fifth  Floor, Boston,        *
*   MA 02110 - 1301, USA.                                                     *
*                                                                             *
******************************************************************************/

#define BYTE unsigned char
#define WORD short int

int save_targa(char *, BYTE *,int,int);

