/*
MySecureShell permit to add restriction to modified sftp-server
when using MySecureShell as shell.
Copyright (C) 2004 Sebastien Tardif

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation (version 2)

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef _BUFFER_H_
#define _BUFFER_H_

#include "Sftp.h"

typedef struct		sBuffer
{
	unsigned char	*data;
	u_int32_t	length;
	u_int32_t	read;
	u_int32_t	size;
}			tBuffer;

#define	DEFAULT_GROW	256

tBuffer	*BufferNew();
void	BufferClean(tBuffer *b);
void	BufferDelete(tBuffer *b);
void	BufferGrow(tBuffer *b, u_int32_t toAdd);
void	BufferReadData(tBuffer *b, u_int32_t size);

void	BufferPutInt8(tBuffer *b, u_int8_t nb);
void	BufferPutInt32(tBuffer *b, u_int32_t nb);
void	BufferPutInt64(tBuffer *b, u_int64_t nb);
void	BufferPutString(tBuffer *b, char *data);
void	BufferPutData(tBuffer *b, void *data, int size);
void	BufferPutRawData(tBuffer *b, void *data, int size);

u_int8_t	BufferGetInt8(tBuffer *b);
u_int32_t	BufferGetInt32(tBuffer *b);
u_int64_t	BufferGetInt64(tBuffer *b);
int		BufferGetStringAsInt(tBuffer *b);
char		*BufferGetString(tBuffer *b);
char		*BufferGetData(tBuffer *b, u_int32_t *size);

#define BufferPutInt8FAST(_D, _INT8) (_D)->data[(_D)->length++] = _INT8;
#define BufferPutPacket(_D, _S)	BufferPutData((_D), (_S)->data, (_S)->length)


#define BufferGetInt8FAST(_D) (u_int8_t )(_D)->data[(_D)->read++]

#endif //_BUFFER_H_
