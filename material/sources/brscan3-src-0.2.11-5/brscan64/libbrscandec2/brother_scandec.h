/*

 This file is part of the Brother MFC/DCP backend for SANE.

 This program is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2 of the License, or (at your option)
 any later version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 more details.

 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place, Suite 330, Boston, MA  02111-1307  USA

*/


// brscan3 - brother sane backend
// Copyright(c) 2005-2008 Brother Industries, Ltd.  
//          All Rights Reserved.
/*******************************************************************************
 *
 *	Scan Decode �إå����ե�����
 *
 *	Copyright: 2000 brother Industries , Ltd.
 *
 *	ver 1.0.0 : 2000.04.13 : ���� : ��������
 ******************************************************************************/
#ifndef	__BROTHER_SCAN_DECODE_H
#define	__BROTHER_SCAN_DECODE_H

typedef	struct {
	INT		nInResoX ;		/* ���ϲ����� */
	INT		nInResoY ;		/* ���ϲ����� */
	INT		nOutResoX ;		/* ���ϲ����� */
	INT		nOutResoY ;		/* ���ϲ����� */
	INT		nColorType ;	/* ���顼���� */
	DWORD	dwInLinePixCnt ;	/* 1�饤������Pixel�� */
	INT		nOutDataKind ;	/* 24BitColor����RGB���Ϸ��� */
#if 0	/* brother_deccom.h�˵��� */
#define	SCODK_PIXEL		1	/* RGB RGB RGB���ǽ� */
#define	SCODK_PLANE		2	/* RRR GGG BBB���ǽ� */
#endif
	BOOL	bLongBoundary ;	/* Long Boundary���� */

/* ScanDecOpen������ꤵ��� */
	DWORD	dwOutLinePixCnt ;	/* 1�饤�����Pixel�� */
	DWORD	dwOutLineByte ;		/* 1�饤�����Byte�� */
	DWORD	dwOutWriteMaxSize ;	/* ����񤭹��ߥХåե������� */

} SCANDEC_OPEN ;

typedef	struct {
	INT		nInDataComp ;		/* ���ϥǡ������̼��� */
#define	SCIDC_WHITE		1	/* ����饤�� */
#define	SCIDC_NONCOMP	2	/* �󰵽� */
#define	SCIDC_PACK		3	/* �ѥå��ӥåİ��� */

	INT		nInDataKind ;		/* ���ϥǡ�����Ǽ���� */
#if 0	/* brother_deccom.h�˵��� */
#define	SCIDK_MONO		1	/* ��Υ��� */
#define	SCIDK_R			2	/* R�ǡ��� */
#define	SCIDK_G			3	/* G�ǡ��� */
#define	SCIDK_B			4	/* B�ǡ��� */
#define	SCIDK_RGB		5	/* RGB���ǽ� */
#define	SCIDK_BGR		6	/* BGR���ǽ� */
#define	SCIDK_256		7	/* 256�����顼 */
#endif
	BYTE	*pLineData ;	/* ���ϣ��饤��ǡ�����Ǽ�� */
	DWORD	dwLineDataSize ;	/* ���ϣ��饤��ǡ��������� */
	BYTE	*pWriteBuff ;	/* ���ϥǡ�����Ǽ�� */
	DWORD	dwWriteBuffSize ;	/* ���ϥǡ����Хåե������� */
	BOOL	bReverWrite ;	/* ���ϥǡ�����Ǽ��ˡ */

} SCANDEC_WRITE ;

BOOL	ScanDecOpen( SCANDEC_OPEN * );
void	ScanDecSetTblHandle( HANDLE, HANDLE );
BOOL	ScanDecPageStart( void );
DWORD	ScanDecWrite( SCANDEC_WRITE *, INT * );
DWORD	ScanDecPageEnd( SCANDEC_WRITE *, INT * );
BOOL	ScanDecClose( void );

typedef BOOL  (*SCANDECOPEN) (SCANDEC_OPEN * );
typedef void  (*SCANDECSETTBL) ( HANDLE, HANDLE );
typedef BOOL  (*SCANDECPAGESTART) ( void );
typedef DWORD (*SCANDECWRITE) ( SCANDEC_WRITE *, INT * );
typedef DWORD (*SCANDECPAGEEND) ( SCANDEC_WRITE *, INT * );
typedef BOOL  (*SCANDECCLOSE) ( void );


#endif	/* ! __BROTHER_SCAN_DECODE_H */
