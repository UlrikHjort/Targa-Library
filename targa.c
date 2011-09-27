/******************************************************************************
*                                                                             *
*                                Targa library                                *
*                                                                             *
*                                  targa.c                                    *
*                                                                             *
*                                   Module                                    *
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "targa.h"


 struct {
     BYTE char_no;
     BYTE color_map;
     BYTE image_type;
 } header1;

struct {
     /* Color map specification */
     WORD map_origin;
     WORD map_length;
 } header2;

struct {
     BYTE map_entry_size;
 } header3;

struct {
     /* Image Specification */
     WORD x_image_origin;     /* Low left corner */
     WORD y_image_origin;     /*     = " =       */
     WORD image_width;
     WORD image_height;
 } header4; 

struct {
     BYTE pixel_size;
     BYTE image_descriptor;
  } header5;


/****************************************************************
 * Save a 24 bit uncompressed RGB Targa image
 * Parameters:
 *  filename : The name of the file
 *  buf      : Pointer to RGB data buffer
 *  width    : Image width
 *  height   : Image height
 ****************************************************************/
int save_targa(char* filename, BYTE *buf,int width,int height) {

    FILE *fp;

    fp=fopen(filename,"wb");

    header1.char_no=0;
    header1.color_map=0;
    header1.image_type=2;

    header2.map_origin=0;
    header2.map_length=0;
    header3.map_entry_size=0;

    header4.x_image_origin=0;
    header4.y_image_origin=0;
    header4.image_width=width;
    header4.image_height=height;
    header5.pixel_size=24;
    header5.image_descriptor=32; 

    fwrite(&header1,1,3,fp);
    fwrite(&header2,2,2,fp);
    fwrite(&header3,1,1,fp);
    fwrite(&header4,2,4,fp);
    fwrite(&header5,1,2,fp);

    fwrite(buf,1,height*width*3,fp);
    fclose(fp);

    return 0;
}

