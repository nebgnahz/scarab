/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* file: aRobotOSExport.h                                          */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* description: Each platform typically uses different mechanisms  */
/*              to export routines from shared libraries.  This    */
/*              file defines the export mechanism for each OS.     */
/*              These are kept out of the main DLL header to       */
/*              avoid clutter and because the user of the          */
/*              libraries never needs to worry about these.        */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Copyright 1994-2008. Acroname Inc.                              */
/*                                                                 */
/* This software is the property of Acroname Inc.  Any             */
/* distribution, sale, transmission, or re-use of this code is     */
/* strictly forbidden except with permission from Acroname Inc.    */
/*                                                                 */
/* To the full extent allowed by law, Acroname Inc. also excludes  */
/* for itself and its suppliers any liability, wheither based in   */
/* contract or tort (including negligence), for direct,            */
/* incidental, consequential, indirect, special, or punitive       */
/* damages of any kind, or for loss of revenue or profits, loss of */
/* business, loss of information or data, or other financial loss  */
/* arising out of or in connection with this software, even if     */
/* Acroname Inc. has been advised of the possibility of such       */
/* damages.                                                        */
/*                                                                 */
/* Acroname Inc.                                                   */
/* www.acroname.com                                                */
/* 720-564-0373                                                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _aRobotOSExport_H_
#define _aRobotOSExport_H_

#ifdef aWIN
#include "win32_aRobotExport.h"
#define aRobotOSExport
#endif /* aWIN */

#ifdef aWINCE
#include "wince_aRobotExport.h"
#define aRobotOSExport
#endif /* aWINCE */

#ifdef aMAC
#include "macos_aRobotExport.h"
#define aRobotOSExport
#endif /* aMAC */

#ifdef aPALM
#include "palmos_aRobotExport.h"
#define aRobotOSExport
#endif /* aPALM */

#ifdef aUNIX
#ifdef aMACX
#include "macx_aRobotExport.h"
#else /* aMACX */
#include "unix_aRobotExport.h"
#endif /* aMACX */
#define aRobotOSExport
#endif /* aPALM */

#ifndef aRobotOSExport
error!!!! OS Export Not Defined
#else /* aRobotOSExport */
#undef aRobotOSExport
#endif /* aRobotOSExport */

#endif /* _aRobotOSExport_H_ */
